#include <menu/menu.h>
#include <exercises/exercises.h>
#include <services/ui_handler.h>
#include <services/try_again_handler.h>

#include <iostream>
#include <string>
#include <algorithm>

void showMenuChoices(std::string middleText);
void showBarsLine(int barsQuantityValue);

void menu::showMenu(){
    bool isRunning = true;

    do{
        system("CLS");

        int menuChoice = 0;

        uiHandler::showBarsLine(28);

        uiHandler::showListing("  MENU", "Available Exercises", MENU_AVAILABLE_CHOICES);

        uiHandler::showBarsLine(28);

        while(menuChoice < MIN_MENU_CHOICE_VALUE || menuChoice > MAX_MENU_CHOICE_VALUE){
            std::cout << "\n\nInsert an exercise between [" << MIN_MENU_CHOICE_VALUE << " - " << MAX_MENU_CHOICE_VALUE << "]: " ;
            std::cin >> menuChoice;

            if(menuChoice < MIN_MENU_CHOICE_VALUE || menuChoice > MAX_MENU_CHOICE_VALUE){
                std::cout << "\nYou inserted " << menuChoice << " please insert values between [" << MIN_MENU_CHOICE_VALUE << " - " << MAX_MENU_CHOICE_VALUE << "]";
            }
        }

        system("CLS");

        switch (menuChoice){
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

        isRunning = tryAgainHandler::showTryAgain("Do you want to run another question?");

        system("CLS");
    }while(isRunning == true);
}