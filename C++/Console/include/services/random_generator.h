#ifndef TLC_CPP_INCLUDE_SERVICES_RANDOM_GENERATOR_H
#define TLC_CPP_INCLUDE_SERVICES_RANDOM_GENERATOR_H

#include <services/vector_handler.h>

#include <type_traits>
#include <vector>
#include <random>

namespace random_generator {
    template<class T>
    using UniformDistribution =  typename std::conditional<
        std::is_floating_point<T>::value,
        std::uniform_real_distribution<T>,
        typename std::conditional<
            std::is_integral<T>::value,
            std::uniform_int_distribution<T>,
            void
        >::type
    >::type;

    template <class TDraw>
    TDraw Number(TDraw draw_floor, TDraw draw_roof){
        static thread_local std::mt19937_64 mt(std::random_device{}());

        UniformDistribution<TDraw> dist6(draw_floor, draw_roof);

        return dist6(mt);
    };

    template <class TDraw>
    std::vector<TDraw> unidimensionalVector(
        uint32_t draw_size,
        TDraw draw_floor = 1,
        TDraw draw_roof = 100
    ){
        std::vector<TDraw> drawn_vector = vector_handler::createunidimensionalVector<TDraw>(draw_size);
        
        for(int currentDrawnVectorIndex = 0; currentDrawnVectorIndex < draw_size; currentDrawnVectorIndex++){
            drawn_vector[currentDrawnVectorIndex] = Number(draw_floor, draw_roof);
        }

        return drawn_vector;
    };

    template <class TDraw>
    vector_handler::multidimensional::Vector<TDraw> multidimensionalVector(
        std::vector<uint32_t> draw_dimensions,
        TDraw draw_floor = 1,
        TDraw draw_roof = 100
    ){
        vector_handler::multidimensional::Vector<TDraw> drawn_vector = vector_handler::createMultidimensionalVector<TDraw>(draw_dimensions);
        
        std::vector<uint32_t> indices(draw_dimensions.size(), 0);

        do{
            drawn_vector[indices] = Number(draw_floor, draw_roof);
        }while(vector_handler::multidimensional::inc(indices, draw_dimensions) == false);

        return drawn_vector;
    };
};

#endif