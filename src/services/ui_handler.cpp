#include <services/ui_handler.h>

#include <iostream>
#include <string>
#include <vector>

void uihandler::ShowBarsLine(int bars_quantity_value){
    std::string bars_line,
                bar_caracter = "=";

    for(int current_bart_count = 0; current_bart_count <= bars_quantity_value; current_bart_count ++){
        bars_line += bar_caracter;
    }

    std::cout << bars_line;
}

void uihandler::ShowListing(std::string primary_text,
                            std::string secondary_text,
                            std::vector<std::string> listing
){
    std::cout << "\n\t  " << primary_text << "\n";
    std::cout << "\n     " << secondary_text << "\n\n";

    for(int current_listing = 0; current_listing < listing.size(); current_listing ++){
        std::cout << "\t   " << (current_listing + 1) << " - " << listing[current_listing] << "\n";
    }
}