#include <string>
#include <vector>

namespace menu{
    const std::vector<std::string> MENU_AVAILABLE_CHOICES = {
        "p5",
        "p8",
        "p9",
        "p10",
        "p13"
    };
    const int MIN_MENU_CHOICE_VALUE = 1;
    const int MAX_MENU_CHOICE_VALUE = MENU_AVAILABLE_CHOICES.size();

    void showMenu();
}