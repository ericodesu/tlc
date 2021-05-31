#ifndef TLC_INCLUDE_SERVICES_UI_HANDLER_H
#define TLC_INCLUDE_SERVICES_UI_HANDLER_H

#include <string>
#include <vector>

namespace uiHandler {
    void showBarsLine(int barsQuantityValue);
    void showListing(std::string primaryText, std::string secondaryText, std::vector<std::string> listing);
};

#endif