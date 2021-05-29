#include <services/try_again_handler.h>

#include <iostream>
#include <string>
#include <algorithm>

bool tryAgainHandler::showTryAgain(std::string tryAgainMessage){
    std::cout << "\n" << tryAgainMessage << " (Y/N): ";

    std::string userTryChoice;

    std::cin >> userTryChoice;

    std::transform(userTryChoice.begin(), userTryChoice.end(), userTryChoice.begin(), std::toupper);

    return userTryChoice == "Y" || userTryChoice == "YES";
}