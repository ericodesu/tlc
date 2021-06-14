#include <exercises/exercise.h>
#include <exercises/question.h>
#include <services/ui_handler.h>

#include <iostream>
#include <vector>

void Exercise::SetQuestionList(std::vector<Question> new_question_list){
    Exercise::question_list = new_question_list;
};

std::vector<Question> Exercise::GetQuestionList(){
    return Exercise::question_list;
};

Question Exercise::ExecQuestionsMenu(std::vector<Question> question_list){
    int question_list_length = question_list.size();

    std::vector<std::string> listing;

    listing.reserve(question_list_length);

    if(question_list_length > 0){
        for(int current_question_index = 0; current_question_index < question_list_length; current_question_index++){
            listing.push_back(question_list[current_question_index].GetQuestionName());
        }
    }else{
        listing.push_back("No questions found");
    }

    uihandler::ShowBarsLine(28);

    uihandler::ShowListing("Exercise", "Available questions", listing);

    uihandler::ShowBarsLine(28);

    int menu_choice = 0;

    while(menu_choice < 1 || menu_choice > question_list_length){
        std::cout << "\n\nInsert an question between [" << 1 << " - " << question_list_length << "]: " ;
        std::cin >> menu_choice;

        if(menu_choice < 1 || menu_choice > question_list_length){
            std::cout << "\nYou inserted " << menu_choice << " please insert values between [" << 1 << " - " << question_list_length << "]";
        }
    }

    return question_list[menu_choice - 1];
};

void Exercise::RunQuestion(std::function<void()> RunnableQuestion){
    system("CLS");
    
    RunnableQuestion();
};