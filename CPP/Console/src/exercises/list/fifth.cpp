#include <exercises/question.h>
#include <exercises/list/fifth.h>
#include <services/prompt_handler.h>

#include <stdio.h>
#include <iostream>
#include <functional>
#include <string>
#include <cmath>
#include <algorithm>

#define DRAWN_FLOOR 1
#define DRAWN_ROOF 100

#define PI21 3.141592653589793238462
#define ERROR_FLOOR 2
#define ERROR_ROOF 20

void FifthExercise::execQ1(){
    //Setting random number seed
    srand(0);

    int drawn_number = 0,
        current_drawn_floor = DRAWN_FLOOR,
        current_drawn_roof = DRAWN_ROOF,
        user_guess,
        user_total_tries = 1;
        
    bool is_another_try = true;

    std::cout << "This App simulates a guessing game!\n";

    do{
        user_guess = DRAWN_FLOOR - 1;

        std::cout << "\nA number between " << DRAWN_FLOOR << " and " << DRAWN_ROOF << " will be drawn, your job is to guess it out...!";

        drawn_number = rand() % (DRAWN_ROOF + DRAWN_FLOOR);
        
        do{
            do{
                std::cout << "\nWhich is your guessing?: ";

                std::cin >> user_guess;

                if(user_guess < current_drawn_floor || user_guess > current_drawn_roof){
                    std::cout << "Invalid guess! Range:[" << current_drawn_floor << "," << current_drawn_roof << "]";
                }
            }while(user_guess < current_drawn_floor || user_guess > current_drawn_roof);

            if(user_guess != drawn_number){
                std::string tip_number_order = "less";

                if(user_guess < drawn_number){
                    tip_number_order = "greater";
                    current_drawn_floor = user_guess + 1;
                }else{
                    current_drawn_roof = user_guess - 1;
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

        is_another_try = prompthandler::showTryAgain("Want another run?");
    }while(is_another_try == true);
};

void FifthExercise::execQ2(){
    bool is_another_try = true;

    std::cout << "Find the value of PI using the series of Nilakantha\nwith the minimal amount of error going between (10^-2 until 10^-20)\n";\

    do{
        bool has_partial_results = false;

        int user_choice = 0;

        double error = 0;

        do{
            std::cout << "\nInsert a value between (" << ERROR_FLOOR << "-" << ERROR_ROOF << "):  ";
            std::cin >> user_choice;

            if(user_choice < ERROR_FLOOR || user_choice > ERROR_ROOF){
                std::cout << "You inserted a invalid value, please insert a value between (" << ERROR_FLOOR << "-" << ERROR_ROOF << ")";
            }
        }while(user_choice < ERROR_FLOOR || user_choice > ERROR_ROOF);

        error = std::pow(10, - user_choice);

        std::printf("You've choosen the error < %g", error);

        has_partial_results = prompthandler::showTryAgain("Want to watch the parcial results?");

        int current_iteration = 1;

        double current_PI = 3,
               current_error = PI21 - current_PI,
               current_summation = 0;

        std::string current_iteration_display = "\n%5d",
                    current_pi_display = "",
                    current_error_display = "",
                    current_status_display = "",
                    middle_title_spacing = std::string((ERROR_ROOF / 2) - 1, ' '),
                    last_title_spacing = std::string((ERROR_ROOF) - 3, ' ');
    
        std::cout << "\n    N" << middle_title_spacing << "Calculated PI" << last_title_spacing << "Error";

        while(std::fabs(current_error) >= error){
            current_pi_display = "%" + std::to_string(ERROR_ROOF) + "." + std::to_string(user_choice + 1) + "f";
            current_error_display = "%" + std::to_string(ERROR_ROOF) + "." + std::to_string(user_choice + 1) + "f";

            current_status_display = current_iteration_display + current_pi_display + current_error_display;

            if(has_partial_results == true){
                std::printf(current_status_display.c_str(), current_iteration, current_PI, current_error);
            }

            current_summation = ((std::pow(-1, (current_iteration + 1))) * 4) / ((2 * current_iteration) * ((2 * current_iteration) + 1) * ((2 * current_iteration) + 2));

            current_PI = current_PI + current_summation;
            
            current_error = current_PI - PI21;

            current_iteration ++;
        }

        std::printf(current_status_display.c_str(), current_iteration, current_PI, current_error);

        is_another_try = prompthandler::showTryAgain("Want another run?");
    }while(is_another_try == true);
};