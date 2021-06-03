#ifndef TLC_INCLUDE_SERVICES_VECTOR_HANDLER_H
#define TLC_INCLUDE_SERVICES_VECTOR_HANDLER_H

#include <cassert>
#include <iostream>
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
                std::vector<size_t> _dims;
                std::vector<T> _data;

            public:
                Vector(const std::vector<size_t> &dims): _dims(dims){
                    size_t size = _dims.empty() ? 0 : 1;

                    for (size_t dim : _dims) size *= dim;
                        _data.resize(size);
                }

                Vector(
                    const std::vector<size_t> &dims,
                    const std::vector<T> &data
                ): Vector<T>(dims){
                    assert(_data.size() == data.size());

                    std::copy(data.begin(), data.end(), _data.begin());
                }

                T& operator[](const std::vector<size_t> &indices){
                    size_t i = 0,
                           j = 0;

                    for(size_t n = _dims.size(); j < n; ++j){
                        i *= _dims[j];
                        i += indices[j];
                    }

                    return _data[i];
                }

                const T& operator[](const std::vector<size_t> &indices) const{
                    size_t i = 0,
                           j = 0;

                    for (size_t n = _dims.size(); j < n; ++j){
                        i *= _dims[j];
                        i += indices[j];
                    }

                    return _data[i];
                }
        };

        bool inc(std::vector<size_t> &indices, const std::vector<size_t> &dims){
            for(size_t i = indices.size(); i--;){
                if(++indices[i] < dims[i]){
                    return false;
                }

                indices[i] = 0;
            }

            return true;
        };
    }

    template <class TVector>
    multidimensional::Vector<TVector> CreateMultidimensionalVector(std::vector<size_t> vector_dimensions){
        return multidimensional::Vector<TVector>(vector_dimensions);
    };

    template <class TVector>
    std::vector<TVector> CreateUnidimensionalVector(size_t vector_size){
        return std::vector<TVector>(vector_size, 0);
    };
};

#endif