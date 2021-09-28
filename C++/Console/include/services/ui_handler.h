#ifndef TLC_CPP_INCLUDE_SERVICES_UI_HANDLER_H
#define TLC_CPP_INCLUDE_SERVICES_UI_HANDLER_H

#include <string>
#include <vector>

namespace ui_handler {
    void showBarsLine(int bars_quantity);
    void showListing(
        std::string primary_text,
        std::string secondary_text,
        std::vector<std::string> listing
    );
};

#endif