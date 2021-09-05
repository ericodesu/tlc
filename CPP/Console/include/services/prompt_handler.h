#ifndef TLC_CPP_INCLUDE_PROMPT_HANDLER_H
#define TLC_CPP_INCLUDE_PROMPT_HANDLER_H

#include <functional>
#include <string>
#include <iostream>

namespace prompthandler {
    bool showTryAgain(std::string try_again_message);
    void showMenu();
    void clearScreen();
    template<class T>
    T showQuestion(
        std::string question_message,
        std::string error_message,
        std::function<bool (T)> conditional
    ){
        T user_input;

        do{
            std::cout << question_message << ": ";
            std::cin >> user_input;

            if(conditional(user_input) == false){
                std::cout << error_message << "\n";
            }
        }while(conditional(user_input) == false);

        return user_input;
    };
};

#endif