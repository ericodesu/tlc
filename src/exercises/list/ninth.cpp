#include <exercises/list/ninth.h>
#include <services/vector_handler.h>
#include <services/random_generator.h>
#include <services/prompt_handler.h>

#include <iostream>
#include <vector>
#include <functional>

#define MATRIX_MIN_DIMENSIONS_VALUE 2
#define MATRIX_MAX_DIMENSIONS_VALUE 10

void NinthExercise::ExecQ1(){
    std::string matrix_dimension_constraints = "(" + std::to_string(MATRIX_MIN_DIMENSIONS_VALUE) + "-" + std::to_string(MATRIX_MAX_DIMENSIONS_VALUE) + ")";

    std::function<bool (size_t)> conditional;

    conditional = [](size_t user_input) {
        if(user_input < MATRIX_MIN_DIMENSIONS_VALUE || user_input > MATRIX_MAX_DIMENSIONS_VALUE){
            return false;
        }else{
            return true;
        }
    };

    size_t matrix_A_row_value = prompthandler::ShowQuestion<size_t>(
        "Insert the amount of rows regarding A matrix " + matrix_dimension_constraints,
        "Invalid Value!!!",
        conditional
    );
    size_t matrix_A_column_value = prompthandler::ShowQuestion<size_t>(
        "Insert the amount of columns regarding A matrix " + matrix_dimension_constraints,
        "Invalid Value!!!",
        conditional
    );

    size_t matrix_B_row_value = prompthandler::ShowQuestion<size_t>(
        "Insert the amount of rows regarding B matrix " + matrix_dimension_constraints,
        "Invalid Value!!!",
        conditional
    );
    size_t matrix_B_column_value = prompthandler::ShowQuestion<size_t>(
        "Insert the amount of columns regarding B matrix " + matrix_dimension_constraints,
        "Invalid Value!!!",
        conditional
    );

    std::vector<size_t> matrix_A_dimensions = { matrix_A_row_value,
                                                matrix_A_column_value },
                        matrix_B_dimensions = { matrix_B_row_value,
                                                matrix_B_column_value };


    vectorhandler::multidimensional::Vector<int> matrix_A = randomgenerator::MultidimensionalVector<int>(
        matrix_A_dimensions,
        2,
        16
    );
    vectorhandler::multidimensional::Vector<int> matrix_B = randomgenerator::MultidimensionalVector<int>(
        matrix_B_dimensions,
        2,
        16
    );

    vectorhandler::ShowMultidimensionalVector(
        matrix_A,
        matrix_A_dimensions,
        "Matrix A:\n",
        16
    );
    vectorhandler::ShowMultidimensionalVector(
        matrix_B,
        matrix_B_dimensions,
        "\n\nMatrix B:\n",
        16
    );
};

void NinthExercise::ExecQ2(){
    std::cout << "huh";
};