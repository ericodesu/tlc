#ifndef TLC_INCLUDE_PROMPT_HANDLER_H
#define TLC_INCLUDE_PROMPT_HANDLER_H

#include <string>
#include <algorithm>

namespace prompthandler {
    bool ShowTryAgain(std::string tryAgainMessage);
    void ShowMenu();
};

#endif