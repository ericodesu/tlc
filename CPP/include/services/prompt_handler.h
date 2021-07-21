#ifndef TLC_INCLUDE_PROMPT_HANDLER_H
#define TLC_INCLUDE_PROMPT_HANDLER_H

#include <functional>
#include <string>
#include <iostream>

namespace prompthandler {
    bool ShowTryAgain(std::string try_again_message);
    void ShowMenu();
    void ClearScreen();
    template<class T>
    T ShowQuestion(
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