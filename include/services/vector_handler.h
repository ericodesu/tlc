#ifndef TLC_INCLUDE_SERVICES_VECTOR_HANDLER_H
#define TLC_INCLUDE_SERVICES_VECTOR_HANDLER_H

#include <services/math_handler.h>

#include <cassert>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

namespace vectorhandler {
    /**
     *    The multidimensional namespace code is originated from a stackoverflow post,
     *    a few usage directions must be pointed out, given:
     * 
     *    - The operator usage seems a bit out of the ordinary due to design choices
     *      instead of acessing the nested vector by [j][k]...[N], you instead provide
     *      an 1D vector of N size which each index is a nested (if present) vector.
     * 
     *      E.g. Trying to access a 1D vector with 10 length at the 2nd index:
     *              
     *              a_vector_dimensions = [2];
     * 
     *              a_vector[a_vector_dimension]; <-- This is where you are accessing it;
     * 
     *      PS - The stackoverflow answer came from:
     *           https://stackoverflow.com/questions/48456507/c-generate-multidimensional-vector-of-unknown-depth
     * 
     */
    namespace multidimensional{
        template <typename T>
        class Vector {
            private:
                std::vector<uint32_t> _dims;
                std::vector<T> _data;

            public:
                Vector(const std::vector<uint32_t> &dims): _dims(dims){
                    uint32_t size = _dims.empty() ? 0 : 1;

                    for (uint32_t dim : _dims) size *= dim;
                        _data.resize(size);
                }

                Vector(
                    const std::vector<uint32_t> &dims,
                    const std::vector<T> &data
                ): Vector<T>(dims){
                    assert(_data.size() == data.size());

                    std::copy(data.begin(), data.end(), _data.begin());
                }

                T& operator[](const std::vector<uint32_t> &indices){
                    uint32_t i = 0,
                           j = 0;

                    for(uint32_t n = _dims.size(); j < n; ++j){
                        i *= _dims[j];
                        i += indices[j];
                    }

                    return _data[i];
                }

                const T& operator[](const std::vector<uint32_t> &indices) const{
                    uint32_t i = 0,
                           j = 0;

                    for (uint32_t n = _dims.size(); j < n; ++j){
                        i *= _dims[j];
                        i += indices[j];
                    }

                    return _data[i];
                }
        };

        bool inc(std::vector<uint32_t> &indices, const std::vector<uint32_t> &dims){
            for(uint32_t i = indices.size(); i--;){
                if(++indices[i] < dims[i]){
                    return false;
                }

                indices[i] = 0;
            }

            return true;
        };
    };

    template <class TVector>
    multidimensional::Vector<TVector> CreateMultidimensionalVector(std::vector<uint32_t> vector_dimensions){
        return multidimensional::Vector<TVector>(vector_dimensions);
    };

    template <class TVector>
    std::vector<TVector> CreateUnidimensionalVector(uint32_t vector_size){
        return std::vector<TVector>(vector_size, 0);
    };

    template <class TVector>
    void ShowMultidimensionalVector(
        multidimensional::Vector<TVector> matrix,
        std::vector<uint32_t> matrix_dimensions,
        std::string matrix_title = "Matrix",
        int matrix_max_digits = 3
    ){
        std::vector<uint32_t> indices(matrix_dimensions.size(), 0),
                              current_dimensions(matrix_dimensions.size(), 0);

        std::cout << matrix_title;

        do{
            for(
                int current_dimension_index = 1;
                current_dimension_index < matrix_dimensions.size();
                current_dimension_index++
            ){
                uint32_t current_dimension_roof = matrix_dimensions[current_dimension_index],
                       current_dimension = current_dimensions[current_dimension_index];

                if(current_dimension == current_dimension_roof){
                    current_dimensions[current_dimension_index] = 1;

                    if(current_dimension_index == 1){
                        std::cout << "\n";
                    }
                }else{
                    current_dimensions[current_dimension_index] += 1;
                }
            }

            std::cout << std::setw(matrix_max_digits) << matrix[indices];

            bool is_last_element = true;

            for(
                int current_dimension_index = 1;
                current_dimension_index < matrix_dimensions.size();
                current_dimension_index++
            ){
                uint32_t current_dimension_roof = matrix_dimensions[current_dimension_index],
                         current_indice = indices[current_dimension_index];

                if(current_indice != current_dimension_roof - 1){
                    is_last_element = false;
                }
            }

            if(matrix_dimensions.size() > 2 && is_last_element == true){
                std::cout << "\n";
            }
        }while(multidimensional::inc(indices, matrix_dimensions) == false);
    };
};

#endif