#include <services/math_handler.h>

int math_handler::countDigits(int number){
    int count = 0;

    while (number != 0){
        number = number / 10;

        ++count;
    };

    return count;
};