#include <services/math_handler.h>

int mathhandler::CountDigits(int number){
    int count = 0;

    while (number != 0){
        number = number / 10;

        ++count;
    };

    return count;
};