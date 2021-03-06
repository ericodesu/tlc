#include <services/ui_handler.h>

#include <iostream>
#include <string>
#include <vector>

void ui_handler::showBarsLine(int bars_quantity){
    std::string bars_line,
                bar_caracter = "=";

    for(int current_bart_count = 0; current_bart_count <= bars_quantity; current_bart_count ++){
        bars_line += bar_caracter;
    }

    std::cout << bars_line;
};

void ui_handler::showListing(
    std::string primary_text,
    std::string secondary_text,
    std::vector<std::string> listing
){
    std::cout << "\n\t  " << primary_text << "\n";
    std::cout << "\n     " << secondary_text << "\n\n";

    for(int current_listing = 0; current_listing < listing.size(); current_listing ++){
        std::cout << "\t   " << (current_listing + 1) << " - " << listing[current_listing] << "\n";
    }
};