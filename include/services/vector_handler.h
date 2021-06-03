#ifndef TLC_INCLUDE_SERVICES_VECTOR_HANDLER_H
#define TLC_INCLUDE_SERVICES_VECTOR_HANDLER_H

#include <cassert>
#include <iostream>
#include <vector>

namespace vectorhandler {
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

        std::ostream& operator<<(std::ostream &out, const std::vector<size_t> &values){
            const char *sep = "";

            for(size_t value : values){
                out << sep << value; sep = ", ";
            }

            return out;
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