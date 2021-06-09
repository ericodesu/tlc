#include <exercises/question.h>
#include <exercises/list/fifth.h>
#include <services/prompt_handler.h>

#include <stdio.h>
#include <iostream>
#include <functional>
#include <string>
#include <cmath>
#include <algorithm>

#define DRAWN_FLOOR_VALUE 1
#define DRAWN_ROOF_VALUE 100

#define PI21 3.141592653589793238462
#define ERROR_FLOOR_VALUE 2
#define ERROR_ROOF_VALUE 20

void FifthExercise::ExecQ1(){
    //Setting random number seed
    srand(0);

    int drawn_number = 0,
        current_drawn_floor_value = DRAWN_FLOOR_VALUE,
        current_drawn_roof_value = DRAWN_ROOF_VALUE,
        user_guess,
        user_total_tries = 1;
        
    bool is_another_try = true;

    std::cout << "This App simulates a guessing game!\n";

    do{
        user_guess = DRAWN_FLOOR_VALUE - 1;

        std::cout << "\nA number between " << DRAWN_FLOOR_VALUE << " and " << DRAWN_ROOF_VALUE << " will be drawn, your job is to guess it out...!";

        drawn_number = rand() % (DRAWN_ROOF_VALUE + DRAWN_FLOOR_VALUE);
        
        do{
            do{
                std::cout << "\nWhich is your guessing?: ";

                std::cin >> user_guess;

                if(user_guess < current_drawn_floor_value || user_guess > current_drawn_roof_value){
                    std::cout << "Invalid guess! Range:[" << current_drawn_floor_value << "," << current_drawn_roof_value << "]";
                }
            }while(user_guess < current_drawn_floor_value || user_guess > current_drawn_roof_value);

            if(user_guess != drawn_number){
                std::string tip_number_order = "less";

                if(user_guess < drawn_number){
                    tip_number_order = "greater";
                    current_drawn_floor_value = user_guess + 1;
                }else{
                    current_drawn_roof_value = user_guess - 1;
                }

                std::cout << "Tip number " << user_total_tries << ": the drawn number is " << tip_number_order << " than " << user_guess;
                
                user_total_tries ++;
            }else{
                std::string try_noun = "try";

                if(user_total_tries > 1){
                    try_noun = "tries";
                }

                std::cout << "\n\nDrawn number: " << user_guess;
                std::cout << "\nIt took you " << user_total_tries << " " << try_noun;
            }
        }while(user_guess != drawn_number);

        is_another_try = prompthandler::ShowTryAgain("Want another run?");
    }while(is_another_try == true);
};

void FifthExercise::ExecQ2(){
    bool is_another_try = true;

    std::cout << "Find the value of PI using the series of Nilakantha\nwith the minimal amount of error going between (10^-2 until 10^-20)\n";\

    do{
        bool has_partial_results = false;

        int user_choice = 0;

        double error_value = 0;

        do{
            std::cout << "\nInsert a value between (" << ERROR_FLOOR_VALUE << "-" << ERROR_ROOF_VALUE << "):  ";
            std::cin >> user_choice;

            if(user_choice < ERROR_FLOOR_VALUE || user_choice > ERROR_ROOF_VALUE){
                std::cout << "You inserted a invalid value, please insert a value between (" << ERROR_FLOOR_VALUE << "-" << ERROR_ROOF_VALUE << ")";
            }
        }while(user_choice < ERROR_FLOOR_VALUE || user_choice > ERROR_ROOF_VALUE);

        error_value = std::pow(10, - user_choice);

        std::printf("You've choosen the error < %g", error_value);

        has_partial_results = prompthandler::ShowTryAgain("Want to watch the parcial results?");

        int current_iteration_value = 1;

        double current_PI_value = 3,
               current_error = PI21 - current_PI_value,
               current_summation = 0;

        std::string current_error_value_string = "",
                    middle_title_spacing = std::string((ERROR_ROOF_VALUE / 2) - 1, ' '),
                    last_title_spacing = std::string((ERROR_ROOF_VALUE) - 3, ' ');
    
        std::cout << "\n    N" << middle_title_spacing << "Calculated PI" << last_title_spacing << "Error";

        while(std::fabs(current_error) >= error_value){
            current_error_value_string = "\n%5d %" + std::to_string(ERROR_ROOF_VALUE) + "." + std::to_string(user_choice + 1) + "f %" + std::to_string(ERROR_ROOF_VALUE) + "." + std::to_string(user_choice + 1) + "f";

            if(has_partial_results == true){
                std::printf(current_error_value_string.c_str(), current_iteration_value, current_PI_value, current_error);
            }

            current_summation = ((std::pow(-1, (current_iteration_value + 1))) * 4) / ((2 * current_iteration_value) * ((2 * current_iteration_value) + 1) * ((2 * current_iteration_value) + 2));

            current_PI_value = current_PI_value + current_summation;
            
            current_error = current_PI_value - PI21;

            current_iteration_value ++;
        }

        std::printf(current_error_value_string.c_str(), current_iteration_value, current_PI_value, current_error);

        is_another_try = prompthandler::ShowTryAgain("Want another run?");
    }while(is_another_try == true);
};