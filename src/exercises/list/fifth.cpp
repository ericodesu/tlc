#include <exercises/question.h>
#include <exercises/list/fifth.h>
#include <services/try_again_handler.h>

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

void FifthExercise::execQ1(){
    //Setting random number seed
    srand(0);

    int drawnNumber = 0,
        currentDrawnFloorValue = DRAWN_FLOOR_VALUE,
        currentDrawnRoofValue = DRAWN_ROOF_VALUE,
        userGuess,
        userTries = 1;
        
    bool isAnotherTry = true;

    std::cout << "This App simulates a guessing game!\n";

    do{
        userGuess = DRAWN_FLOOR_VALUE - 1;

        std::cout << "\nA number between " << DRAWN_FLOOR_VALUE << " and " << DRAWN_ROOF_VALUE << " will be drawn, your job is to guess it out...!";

        drawnNumber = rand() % (DRAWN_ROOF_VALUE + DRAWN_FLOOR_VALUE);
        
        do{
            do{
                std::cout << "\nWhich is your guessing?: ";

                std::cin >> userGuess;

                if(userGuess < currentDrawnFloorValue || userGuess > currentDrawnRoofValue){
                    std::cout << "Invalid guess! Range:[" << currentDrawnFloorValue << "," << currentDrawnRoofValue << "]";
                }
            }while(userGuess < currentDrawnFloorValue || userGuess > currentDrawnRoofValue);

            if(userGuess != drawnNumber){
                std::string tipNumberOrder = "less";

                if(userGuess < drawnNumber){
                    tipNumberOrder = "greater";
                    currentDrawnFloorValue = userGuess + 1;
                }else{
                    currentDrawnRoofValue = userGuess - 1;
                }

                std::cout << "Tip number " << userTries << ": the drawn number is " << tipNumberOrder << " than " << userGuess;
                
                userTries ++;
            }else{
                std::string tryNoun = "try";

                if(userTries > 1){
                    tryNoun = "tries";
                }

                std::cout << "\n\nDrawn number: " << userGuess;
                std::cout << "\nIt took you " << userTries << " " << tryNoun;
            }
        }while(userGuess != drawnNumber);

        isAnotherTry = tryAgainHandler::showTryAgain("Want another run?");
    }while(isAnotherTry == true);
};

void FifthExercise::execQ2(){
    bool isAnotherTry = true;

    std::cout << "Find the value of PI using the series of Nilakantha\nwith the minimal amount of error going between (10^-2 until 10^-20)\n";\

    do{
        int userChoice = 0;
        double errorValue = 0;

        do{
            std::cout << "\nInsert a value between (" << ERROR_FLOOR_VALUE << "-" << ERROR_ROOF_VALUE << "):  ";
            std::cin >> userChoice;

            if(userChoice < ERROR_FLOOR_VALUE || userChoice > ERROR_ROOF_VALUE){
                std::cout << "You inserted a invalid value, please insert a value between (" << ERROR_FLOOR_VALUE << "-" << ERROR_ROOF_VALUE << ")";
            }
        }while(userChoice < ERROR_FLOOR_VALUE || userChoice > ERROR_ROOF_VALUE);

        errorValue = std::pow(10, - userChoice);

        std::cout << "You've choosen the error < ";

        if(userChoice > 3){
            std::cout.precision(0);

            std::cout << std::scientific;
        }

        std::cout << errorValue;

        isAnotherTry = tryAgainHandler::showTryAgain("Want another run?");
    }while(isAnotherTry == true);
};