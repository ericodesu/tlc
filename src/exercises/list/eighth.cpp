#include <exercises/list/eighth.h>
#include <services/prompt_handler.h>

#include <iostream>
#include <string>

/*
    A few insights on why the result may differ and how to work around it:

    - The ExecQ1 function heavily depends on the terminal/CMD and how,
      is configured, this is given because of the 'chcp' and which
      is his value, this variable controls the Region of the input/output
      accepted by the terminal, they are (Windows based):

        Code Page   Country/ Region/ Language

        437      	United States
        850      	Multilingual (Latin I)
        852      	Slavic (Latin II)
        855      	Cyrillic (Russian)
        857      	Turkish
        860      	Portuguese
        861      	Icelandic
        863      	Canadian-French
        865      	Nordic
        866      	Russian
        869      	Modern Greek
        1252      	West European Latin  <-- This is the value is used in
        65000      	UTF-7 *                  order to run this code snippet.
        65001      	UTF-8 *

        PS - These values were taken from https://ss64.com/nt/chcp.html - 21 may. 2021, 
             it contains way more updated information about this subject.

    - If you encouter any issues (only applicable on Windows based environments),
      consider changing the variable value, in order to do that,
      open your terminal/CMD and type 'chcp ${DESIRED_CODE_PAGE}' in this code
      snippet, the code '1252' was used in order to work propely.
*/

void EighthExercise::ExecQ1(){
    const int ASCII_UPPER_CODE_FLOOR_VALUE = int('A'),
              ASCII_LOWER_CODE_FLOOR_VALUE = int('a'),
              ASCII_LOWER_CODE_ROOF_VALUE = int('z'),
              ASCII_CODE_DIFF = (int('a') - int('A'));

    bool is_another_try = true;

    int space_char_code = int(' ');

    do{
        bool is_current_chunk_modified = false;

        std::wstring user_phrase,
                     modified_phrase;

        std::wcout << "\nInsert a phrase: ";
        std::wcin.clear();
        std::wcin.ignore(INT_MAX, '\n');
        std::getline(std::wcin, user_phrase);

        modified_phrase = user_phrase;

        for(int current_char_index = 0; current_char_index < user_phrase.size(); current_char_index++){
            int current_char_code = int(user_phrase[current_char_index]);
            
            if(current_char_code != space_char_code){
                if(is_current_chunk_modified == false &&
                    (
                        user_phrase[current_char_index] >= ASCII_UPPER_CODE_FLOOR_VALUE &&
                        user_phrase[current_char_index] <= ASCII_LOWER_CODE_ROOF_VALUE
                    )
                ){
                    if(current_char_code >= ASCII_LOWER_CODE_FLOOR_VALUE){
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

        is_another_try = prompthandler::ShowTryAgain("\nWant another try?");
    }while(is_another_try == true);
};