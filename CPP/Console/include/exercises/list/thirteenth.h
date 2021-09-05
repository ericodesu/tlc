#ifndef TLC_CPP_INCLUDE_EXERCISES_LIST_THIRTEENTH_H
#define TLC_CPP_INCLUDE_EXERCISES_LIST_THIRTEENTH_H

#include <exercises/exercise.h>
#include <exercises/question.h>

#include <string>
#include <vector>

void showSortedByMonthCodivData(std::vector<std::vector<int>> covid_data);
std::vector<std::vector<int>> filterCovidData(
    std::vector<std::vector<int>> covid_data,
    std::vector<int> data_floor_boundary,
    std::vector<int> data_roof_boundary
);
std::vector<int> getCovidDataMinMax(
    std::vector<std::vector<int>> covid_data,
    int target_column
);
void showCovidDataMovingAVG(std::vector<std::vector<int>> covid_data);

class ThirteenthExercise: public Exercise {
    public:
        void execQ1();
};

#endif