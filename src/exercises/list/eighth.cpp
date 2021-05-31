#include <exercises/list/eighth.h>
#include <services/try_again_handler.h>

#include <iostream>
#include <string>

/*
    A few insights on why the result may differ and how to work around it:

    - The execQ1 function heavily depends on the terminal/CMD and how,
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

void EighthExercise::execQ1(){
    const int ASCII_UPPER_CODE_FLOOR_VALUE = int('A'),
              ASCII_LOWER_CODE_FLOOR_VALUE = int('a'),
              ASCII_LOWER_CODE_ROOF_VALUE = int('z'),
              ASCII_CODE_DIFF = (int('a') - int('A'));

    bool isAnotherTry = true;

    int spaceCharCode = int(' ');

    do{
        bool isCurrentChunkModified = false;

        std::wstring userPhrase,
                     modifiedPhrase;

        std::wcout << "\nInsert a phrase: ";
        std::wcin.clear();
        std::wcin.ignore(INT_MAX, '\n');
        std::getline(std::wcin, userPhrase);

        modifiedPhrase = userPhrase;

        for(int currentCharIndex = 0; currentCharIndex < userPhrase.size(); currentCharIndex++){
            int currentCharCode = int(userPhrase[currentCharIndex]);
            
            if(currentCharCode != spaceCharCode){
                if(isCurrentChunkModified == false && (userPhrase[currentCharIndex] >= ASCII_UPPER_CODE_FLOOR_VALUE && userPhrase[currentCharIndex] <= ASCII_LOWER_CODE_ROOF_VALUE)){
                    if(currentCharCode >= ASCII_LOWER_CODE_FLOOR_VALUE){
                        modifiedPhrase[currentCharIndex] = char((currentCharCode - ASCII_CODE_DIFF));
                    }else{
                        modifiedPhrase[currentCharIndex] = char((currentCharCode + ASCII_CODE_DIFF));
                    }
                }
            }else{
                isCurrentChunkModified = !isCurrentChunkModified;
            }
        }

        std::wcout << "\nOriginal: " << userPhrase;
        std::wcout << "\nModified: " << modifiedPhrase;

        isAnotherTry = tryAgainHandler::showTryAgain("\nWant another try?");
    }while(isAnotherTry == true);
};