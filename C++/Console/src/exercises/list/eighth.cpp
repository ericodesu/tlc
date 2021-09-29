#include <exercises/list/eighth.h>
#include <services/prompt_handler.h>

#include <limits>
#include <cstdint>
#include <iostream>
#include <string>

void EighthExercise::execQ1(){
    constexpr int ASCII_UPPER_CODE_FLOOR = int('A'),
                  ASCII_LOWER_CODE_FLOOR = int('a'),
                  ASCII_LOWER_CODE_ROOF = int('z'),
                  ASCII_CODE_DIFF = (int('a') - int('A'));

    bool is_another_try = true;

    int space_char_code = int(' ');

    do{
        bool is_current_chunk_modified = false;

        std::wstring user_phrase,
                     modified_phrase;

        std::wcout << "\nInsert a phrase: ";
        std::wcin.clear();
        std::wcin.ignore(std::numeric_limits<std::int32_t>::max(), '\n');
        std::getline(std::wcin, user_phrase);

        modified_phrase = user_phrase;

        for(int current_char_index = 0; current_char_index < user_phrase.size(); current_char_index++){
            int current_char_code = int(user_phrase[current_char_index]);
            
            if(current_char_code != space_char_code){
                if(is_current_chunk_modified == false &&
                    (
                        user_phrase[current_char_index] >= ASCII_UPPER_CODE_FLOOR &&
                        user_phrase[current_char_index] <= ASCII_LOWER_CODE_ROOF
                    )
                ){
                    if(current_char_code >= ASCII_LOWER_CODE_FLOOR){
                        modified_phrase[current_char_index] = char((current_char_code - ASCII_CODE_DIFF));
                    }else{
                        modified_phrase[current_char_index] = char((current_char_code + ASCII_CODE_DIFF));
                    }
                }
            }else{
                is_current_chunk_modified = !is_current_chunk_modified;
            }
        }

        std::wcout << "\nOriginal: " << user_phrase;
        std::wcout << "\nModified: " << modified_phrase;

        is_another_try = prompt_handler::showTryAgain("\nWant another try?");
    }while(is_another_try == true);
};