#include <exercises/list/ninth.h>
#include <services/vector_handler.h>
#include <services/random_generator.h>
#include <services/prompt_handler.h>

#include <iostream>
#include <vector>
#include <functional>

#define Q1_MATRIX_FLOOR_DIMENSIONS 2
#define Q1_MATRIX_ROOF_DIMENSIONS 10
#define Q1_MATRIX_DRAW_FLOOR 2
#define Q1_MATRIX_DRAW_ROOF 16

#define Q2_MATRIX_FLOOR_DIMENSIONS 2
#define Q2_MATRIX_ROOF_DIMENSIONS 8
#define Q2_MATRIX_DRAW_FLOOR -10
#define Q2_MATRIX_DRAW_ROOF 10
#define Q2_MATRIX_A_PRINT_SPACING 4
#define Q2_MATRIX_B_PRINT_SPACING 4
#define Q2_MATRIX_C_PRINT_SPACING 6

void NinthExercise::ExecQ1(){
    std::string matrix_dimension_constraints = "(" + std::to_string(Q1_MATRIX_FLOOR_DIMENSIONS) + "-" + std::to_string(Q1_MATRIX_ROOF_DIMENSIONS) + ")";

    std::function<bool (uint32_t)> conditional = [](uint32_t user_input) {
        if(user_input < Q1_MATRIX_FLOOR_DIMENSIONS || user_input > Q1_MATRIX_ROOF_DIMENSIONS){
            return false;
        }else{
            return true;
        }
    };

    uint32_t matrix_A_row = prompthandler::ShowQuestion<uint32_t>(
        "Insert the amount of rows regarding A matrix " + matrix_dimension_constraints,
        "Invalid Value!!!",
        conditional
    );
    uint32_t matrix_A_column = prompthandler::ShowQuestion<uint32_t>(
        "Insert the amount of columns regarding A matrix " + matrix_dimension_constraints,
        "Invalid Value!!!",
        conditional
    );

    uint32_t matrix_B_row = prompthandler::ShowQuestion<uint32_t>(
        "Insert the amount of rows regarding B matrix " + matrix_dimension_constraints,
        "Invalid Value!!!",
        conditional
    );
    uint32_t matrix_B_column = prompthandler::ShowQuestion<uint32_t>(
        "Insert the amount of columns regarding B matrix " + matrix_dimension_constraints,
        "Invalid Value!!!",
        conditional
    );

    std::vector<uint32_t> matrix_A_dimensions = { matrix_A_row,
                                                  matrix_A_column },
                          matrix_B_dimensions = { matrix_B_row,
                                                  matrix_B_column };


    vectorhandler::multidimensional::Vector<int> matrix_A = randomgenerator::MultidimensionalVector<int>(
        matrix_A_dimensions,
        Q1_MATRIX_DRAW_FLOOR,
        Q1_MATRIX_DRAW_ROOF
    );
    vectorhandler::multidimensional::Vector<int> matrix_B = randomgenerator::MultidimensionalVector<int>(
        matrix_B_dimensions,
        Q1_MATRIX_DRAW_FLOOR,
        Q1_MATRIX_DRAW_ROOF
    );

    vectorhandler::ShowMultidimensionalVector(
        matrix_A,
        matrix_A_dimensions,
        "Matrix A:\n"
    );
    vectorhandler::ShowMultidimensionalVector(
        matrix_B,
        matrix_B_dimensions,
        "\n\nMatrix B:\n"
    );

    uint32_t matrix_row_floor = matrix_A_row < matrix_B_row ?
                matrix_A_row : matrix_B_row,
             matrix_row_roof = matrix_A_row > matrix_B_row ?
                matrix_A_row : matrix_B_row,
             matrix_column_floor = matrix_A_column < matrix_B_column ?
                matrix_A_column : matrix_B_column,
             matrix_column_roof = matrix_A_column > matrix_B_column ?
                matrix_A_column : matrix_B_column;

    std::vector<uint32_t> matrix_add_and_cut_dimensions = { matrix_row_floor,
                                                          matrix_column_floor },
                          matrix_add_and_keep_dimensions = { matrix_row_roof,
                                                             matrix_column_roof },
                          indice_matrix_add_and_cut(matrix_add_and_cut_dimensions.size(), 0),
                          indice_matrix_add_and_keep(matrix_add_and_keep_dimensions.size(), 0);

    vectorhandler::multidimensional::Vector<int> matrix_add_and_cut(matrix_add_and_cut_dimensions),
                                                 matrix_add_and_keep(matrix_add_and_keep_dimensions);

    do{
        matrix_add_and_cut[indice_matrix_add_and_cut] = matrix_A[indice_matrix_add_and_cut] + matrix_B[indice_matrix_add_and_cut];
    }while(vectorhandler::multidimensional::inc(indice_matrix_add_and_cut, matrix_add_and_cut_dimensions) == false);

    for(
        int current_matrix_index_1 = 0;
        current_matrix_index_1 < matrix_add_and_keep_dimensions[0];
        current_matrix_index_1++
    ){
        indice_matrix_add_and_keep[0] = current_matrix_index_1;

        for(int current_matrix_index_2 = 0; current_matrix_index_2 < matrix_add_and_keep_dimensions[1]; current_matrix_index_2++){
            indice_matrix_add_and_keep[1] = current_matrix_index_2;

            if(indice_matrix_add_and_keep[0] < matrix_row_floor){
                if(indice_matrix_add_and_keep[1] < matrix_column_floor){
                    matrix_add_and_keep[indice_matrix_add_and_keep] = matrix_A[indice_matrix_add_and_keep] + matrix_B[indice_matrix_add_and_keep];
                }else{
                    if(matrix_A_dimensions[1] > matrix_column_floor){
                        matrix_add_and_keep[indice_matrix_add_and_keep] = matrix_A[indice_matrix_add_and_keep];
                    }else{
                        matrix_add_and_keep[indice_matrix_add_and_keep] = matrix_B[indice_matrix_add_and_keep];
                    }
                }
            }else{
                if(matrix_A_dimensions[0] > indice_matrix_add_and_keep[0] && matrix_A_dimensions[1] > indice_matrix_add_and_keep[1]){
                    matrix_add_and_keep[indice_matrix_add_and_keep] = matrix_A[indice_matrix_add_and_keep];
                }else if(matrix_B_dimensions[0] > indice_matrix_add_and_keep[0] && matrix_B_dimensions[1] > indice_matrix_add_and_keep[1]){
                    matrix_add_and_keep[indice_matrix_add_and_keep] = matrix_B[indice_matrix_add_and_keep];
                }
            }
        }
    }

    vectorhandler::ShowMultidimensionalVector(
        matrix_add_and_cut,
        matrix_add_and_cut_dimensions,
        "\n\nA add and cut B:\n"
    );
    vectorhandler::ShowMultidimensionalVector(
        matrix_add_and_keep,
        matrix_add_and_keep_dimensions,
        "\n\nA add and keep B:\n"
    );

    std::cout << "\n";
};

void NinthExercise::ExecQ2(){
    std::string matrix_dimension_constraints = "(" + std::to_string(Q2_MATRIX_FLOOR_DIMENSIONS) + "-" + std::to_string(Q2_MATRIX_ROOF_DIMENSIONS) + ")";

    std::function<bool (uint32_t)> conditional = [](uint32_t user_input) {
        if(user_input < Q2_MATRIX_FLOOR_DIMENSIONS || user_input > Q2_MATRIX_ROOF_DIMENSIONS){
            return false;
        }else{
            return true;
        }
    };

    uint32_t matrix_A_row = prompthandler::ShowQuestion<uint32_t>(
        "Insert the amount of rows regarding A matrix " + matrix_dimension_constraints,
        "Invalid Value!!!",
        conditional
    );
    uint32_t matrix_A_column = prompthandler::ShowQuestion<uint32_t>(
        "Insert the amount of columns regarding A matrix " + matrix_dimension_constraints,
        "Invalid Value!!!",
        conditional
    );

    std::cout << "The amount of rows regarding matrix B will be " << matrix_A_column << "\n";

    uint32_t matrix_B_row = matrix_A_column,
             matrix_B_column = prompthandler::ShowQuestion<uint32_t>(
                "Insert the amount of columns regarding B matrix " + matrix_dimension_constraints,
                "Invalid Value!!!",
                conditional
             );

    std::vector<uint32_t> matrix_A_dimensions = { matrix_A_row,
                                                  matrix_A_column },
                          matrix_B_dimensions = { matrix_B_row,
                                                  matrix_B_column },
                          matrix_C_dimensions = { matrix_A_row,
                                                  matrix_A_column > matrix_B_column ?
                                                      matrix_A_column : matrix_B_column };

    vectorhandler::multidimensional::Vector<int> matrix_A = randomgenerator::MultidimensionalVector(
        matrix_A_dimensions,
        Q2_MATRIX_DRAW_FLOOR,
        Q2_MATRIX_DRAW_ROOF
    );
    vectorhandler::multidimensional::Vector<int> matrix_B = randomgenerator::MultidimensionalVector(
        matrix_B_dimensions,
        Q2_MATRIX_DRAW_FLOOR,
        Q2_MATRIX_DRAW_ROOF
    );
    vectorhandler::multidimensional::Vector<int> matrix_C(matrix_C_dimensions);

    std::vector<uint32_t> indices_matrix_C(matrix_C_dimensions.size(), 0),
                          indices_matrix_A(matrix_C_dimensions.size(), 0),
                          indices_matrix_B(matrix_C_dimensions.size(), 0);

    for(
        int current_matrix_A_row_index = 0;
        current_matrix_A_row_index < matrix_A_row;
        current_matrix_A_row_index++
    ){
        indices_matrix_A[0] = current_matrix_A_row_index;
        indices_matrix_C[0] = current_matrix_A_row_index;

        for(int current_matrix_B_column_index = 0; current_matrix_B_column_index < matrix_B_column; current_matrix_B_column_index++){
            indices_matrix_B[1] = current_matrix_B_column_index;
            indices_matrix_C[1] = current_matrix_B_column_index;

            for(int current_matrix_C_row_index = 0; current_matrix_C_row_index < matrix_C_dimensions[0]; current_matrix_C_row_index++){
                indices_matrix_A[1] = current_matrix_C_row_index;
                indices_matrix_B[0] = current_matrix_C_row_index;

                matrix_C[indices_matrix_C] += (matrix_A[indices_matrix_A] * matrix_B[indices_matrix_B]);
            }
        }
    }

    vectorhandler::ShowMultidimensionalVector(
        matrix_A,
        matrix_A_dimensions,
        "\nMatrix A:\n",
        Q2_MATRIX_A_PRINT_SPACING
    );
    vectorhandler::ShowMultidimensionalVector(
        matrix_B,
        matrix_B_dimensions,
        "\n\nMatrix B:\n",
        Q2_MATRIX_B_PRINT_SPACING
    );
    vectorhandler::ShowMultidimensionalVector(
        matrix_C,
        matrix_C_dimensions,
        "\n\nMatrix C:\n",
        Q2_MATRIX_C_PRINT_SPACING
    );

    std::cout << "\n";
};