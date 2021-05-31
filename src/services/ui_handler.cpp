#include <services/ui_handler.h>

#include <iostream>
#include <string>
#include <vector>

void uiHandler::showBarsLine(int barsQuantityValue){
    std::string barsLine, barCaracter = "=";

    for(int currentBartCount = 0; currentBartCount <= barsQuantityValue; currentBartCount ++){
        barsLine += barCaracter;
    }

    std::cout << barsLine;
}

void uiHandler::showListing(std::string primaryText, std::string secondaryText, std::vector<std::string> listing){
    std::cout << "\n\t  " << primaryText << "\n";
    std::cout << "\n     " << secondaryText << "\n\n";

    for(int currentListing = 0; currentListing < listing.size(); currentListing ++){
        std::cout << "\t   " << (currentListing + 1) << " - " << listing[currentListing] << "\n";
    }
}