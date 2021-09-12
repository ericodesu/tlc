#include <exercises/exercises.h>
#include <services/ui_handler.h>
#include <services/prompt_handler.h>

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

bool prompt_handler::showTryAgain(std::string try_again_message){
    std::cout << "\n" << try_again_message << " (Y/N): ";

    std::string user_try_choice;

    std::cin >> user_try_choice;

    std::transform(
        user_try_choice.begin(),
        user_try_choice.end(),
        user_try_choice.begin(),
        ::toupper
    );

    return user_try_choice == "Y" || user_try_choice == "YES";
};

void prompt_handler::showMenu(){
    bool is_running = true;

    std::vector<std::string> MENU_AVAILABLE_CHOICES = {
        "p5",
        "p8",
        "p9",
        "p10",
        "p13"
    };

    int MIN_MENU_CHOICE = 1,
        MAX_MENU_CHOICE = MENU_AVAILABLE_CHOICES.size();

    do{
        clearScreen();

        int menu_choice = 0;

        ui_handler::showBarsLine(28);

        ui_handler::showListing("   TLC\n    (The Learning Channel)", "Available Exercises", MENU_AVAILABLE_CHOICES);

        ui_handler::showBarsLine(28);

        while(menu_choice < MIN_MENU_CHOICE || menu_choice > MAX_MENU_CHOICE){
            std::cout << "\n\nInsert an exercise between [" << MIN_MENU_CHOICE << " - " << MAX_MENU_CHOICE << "]: " ;
            std::cin >> menu_choice;

            if(menu_choice < MIN_MENU_CHOICE || menu_choice > MAX_MENU_CHOICE){
                std::cout << "\nYou inserted " << menu_choice << " please insert values between [" << MIN_MENU_CHOICE << " - " << MAX_MENU_CHOICE << "]";
            }
        }

        clearScreen();

        switch (menu_choice){
            case 1:
                exercises::runFifthExercise();

                break;
            
            case 2:
                exercises::runEighthExercise();

                break;

            case 3:
                exercises::runNinthExercise();

                break;
            
            case 4:
                exercises::runTenthExercise();

                break;

            case 5:
                exercises::runThirteenthExercise();

                break;

            default:
                std::cout << "\nQuestion not found / available, please try another one!\n";

                break;
        }

        is_running = prompt_handler::showTryAgain("Do you want to run another question?");

        clearScreen();
    }while(is_running == true);
};

void prompt_handler::clearScreen(){
    #ifdef _WINDOWS
        std::system("cls");
    #else
        std::system("clear");
    #endif
};