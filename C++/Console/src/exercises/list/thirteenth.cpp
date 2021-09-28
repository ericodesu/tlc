#include <exercises/list/thirteenth.h>
#include <services/prompt_handler.h>

#include <fstream>
#include <istream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <limits>

void showSortedByMonthCodivData(std::vector<std::vector<int>> covid_data){
    int initial_recurrent_deceases = covid_data[0][4],
        initial_recurrent_case = covid_data[0][6];

    std::cout << "This exercise analises the evolution of the number of cases and deceases by Covid-19 in Vicosa-MG";
    std::cout << "\nMonth/Year\tCases\tDeceases";

    for(int covid_data_row = 0; covid_data_row < covid_data.size(); covid_data_row++){
        std::vector<int> covid_data_column = covid_data[covid_data_row];

        int next_covid_data_row = covid_data_row + 1;
        
        int current_day = covid_data_column[0],
            current_month = covid_data_column[1],
            current_year = covid_data_column[2],
            current_deceases = covid_data_column[3],
            current_recurrent_deceases = covid_data_column[4],
            current_cases = covid_data_column[5],
            current_recurrent_cases = covid_data_column[6];

        bool next_row_exists = (next_covid_data_row < covid_data.size() && current_month != covid_data[next_covid_data_row][1]),
             is_last_row = (covid_data_row == (covid_data.size() - 1));

        if(next_row_exists || is_last_row){
            std::cout << "\n"
                      << current_month
                      << "/"
                      << current_year
                      << "\t\t"
                      << (current_recurrent_cases - initial_recurrent_case)
                      << "\t"
                      << (current_recurrent_deceases - initial_recurrent_deceases);

            if(next_row_exists){
                initial_recurrent_deceases = covid_data[next_covid_data_row][4];
                initial_recurrent_case = covid_data[next_covid_data_row][6];
            }

            if(is_last_row){
                std::cout << "\nAt the last month it was considered " << current_day << " days\n";
            }
        }
    }
};

std::vector<std::vector<int>> filterCovidData(
            std::vector<std::vector<int>> covid_data,
            std::vector<int> data_floor_boundary = std::vector<int>(6, 0),
            std::vector<int> data_roof_boundary = std::vector<int>(6, std::numeric_limits<int>::max())
){
    std::vector<std::vector<int>> filtered_covid_data;

    for(int row_index = 0; row_index < covid_data.size(); row_index++){
        std::vector<int> current_row = covid_data[row_index];

        int boundary_index = 0;

        bool is_value_between_boundaries = true;

        while(
            is_value_between_boundaries &&
            (
                boundary_index < data_floor_boundary.size() &&
                boundary_index < data_roof_boundary.size()
            )
        ){
            int column_value = current_row[boundary_index],
                floor_boundary_value = data_floor_boundary[boundary_index],
                roof_boundary_value = data_roof_boundary[boundary_index];

            is_value_between_boundaries = (
                (column_value >= floor_boundary_value || floor_boundary_value == 0) &&
                (column_value <= roof_boundary_value || roof_boundary_value == std::numeric_limits<int>::max())
            );

            if(is_value_between_boundaries){
                bool is_last_entry = (boundary_index + 1 >= data_floor_boundary.size());

                if(is_last_entry){
                    filtered_covid_data.push_back(current_row);
                }
            }

            boundary_index++;
        };
    };

    return filtered_covid_data.size() > 0 ? filtered_covid_data : covid_data;
};

std::vector<int> getCovidDataMinMax(
    std::vector<std::vector<int>> covid_data,
    int target_column = 0
){
    std::vector<int> min_max_list(2, 0);

    min_max_list[0] = std::numeric_limits<int>::max();

    for(int row_index = 0; row_index < covid_data.size(); row_index++){
        std::vector<int> current_row = covid_data[row_index];

        int value = current_row[target_column];

        if(value < min_max_list[0]){
            min_max_list[0] = value;
        }

        if(value > min_max_list[1]){
            min_max_list[1] = value;
        }
    };

    return min_max_list;
};

void showCovidDataMovingAVG(std::vector<std::vector<int>> covid_data){
    std::string try_again_message = "Do you want to verify the moving average of a given date";

    bool will_be_another_run = prompt_handler::showTryAgain(try_again_message);

    std::vector<int> first_entry = covid_data[0],
                     last_entry = covid_data[(covid_data.size() - 1)],
                     year_min_max = getCovidDataMinMax(covid_data, 2);

    std::string year_constraints = " (" + std::to_string(year_min_max[0]) + "-" + std::to_string(year_min_max[1]) + ")";

    std::function<bool (int)> year_conditional = [year_min_max](int user_input) {
        if(user_input < year_min_max[0] || user_input > year_min_max[1]){
            return false;
        }else{
            return true;
        }
    };

    while(will_be_another_run){
        int target_year = prompt_handler::showQuestion<int>(
            "Insert the target year" + year_constraints,
            "Invalid Value!!!",
            year_conditional
        );

        std::vector<int> month_floor_boundaries(6, 0);

        month_floor_boundaries[2] = target_year;

        std::vector<int> month_min_max = getCovidDataMinMax(filterCovidData(covid_data, month_floor_boundaries), 1);

        std::string month_constraints = " (" + std::to_string(month_min_max[0]) + "-" + std::to_string(month_min_max[1]) + ")";

        std::function<bool (int)> month_conditional = [month_min_max](int user_input) {
            if(user_input < month_min_max[0] || user_input > month_min_max[1]){
                return false;
            }else{
                return true;
            }
        };

        int target_month = prompt_handler::showQuestion<int>(
            "Insert the target month" + month_constraints,
            "Invalid Value!!!", 
            month_conditional
        );

        std::vector<int> day_floor_boundaries(6, 0);

        day_floor_boundaries[1] = target_month;
        day_floor_boundaries[2] = target_year;

        std::vector<int> day_min_max = getCovidDataMinMax(filterCovidData(covid_data, day_floor_boundaries), 0);

        std::string day_constraints = " (" + std::to_string(day_min_max[0]) + "-" + std::to_string(day_min_max[1]) + ")";

        std::function<bool (int)> day_conditional = [day_min_max](int user_input) {
            if(user_input < day_min_max[0] || user_input > day_min_max[1]){
                return false;
            }else{
                return true;
            }
        };

        int target_day = prompt_handler::showQuestion<int>(
            "Insert the target day" + day_constraints,
            "Invalid Value!!!", 
            day_conditional
        );

        std::vector<int> date_floor_boundaries(6, 0),
                         date_roof_boundaries(6, 0);

        date_floor_boundaries[0] = target_day - 6;
        date_floor_boundaries[1] = target_month;
        date_floor_boundaries[2] = target_year;

        date_roof_boundaries[0] = target_day;
        date_roof_boundaries[1] = target_month;
        date_roof_boundaries[2] = target_year;

        std::vector<std::vector<int>> user_selected_data = filterCovidData(covid_data, date_floor_boundaries);

        std::string current_date = std::to_string(target_day) + "/"  + std::to_string(target_month) + "/" + std::to_string(target_year);

        std::cout << "\nIn "
                  << current_date
                  << " the moving average of the cases was: "
                  << 0
                  << "\n      and the moving average of the diceases was: "
                  << 0;

        will_be_another_run = prompt_handler::showTryAgain(try_again_message);
    };
};

void ThirteenthExercise::execQ1(){
    std::string resource_path = RESOURCE_FILE_DIR,
                cvs_file_path = resource_path + "/csv/Covid19VicosaMG.csv",
                line;

    char covid_data_divisor = ';';

    std::ifstream covid_data(cvs_file_path);

    std::vector<std::vector<int>> sorted_covid_data;

    while(std::getline(covid_data, line)){
        std::stringstream line_stream(line);

        std::string cell;

        std::vector<int> column;

        while(std::getline(line_stream, cell, covid_data_divisor)){
            column.push_back(std::stoi(cell));
        }

        sorted_covid_data.push_back(column);
    }

    showSortedByMonthCodivData(sorted_covid_data);

    showCovidDataMovingAVG(sorted_covid_data);
};