#include <exercises/exercise.h>
#include <exercises/question.h>
#include <services/ui_handler.h>

#include <iostream>
#include <vector>

void Exercise::setQuestionList(std::vector<Question> newQuestionList){
    Exercise::questionList = newQuestionList;
}
;
std::vector<Question> Exercise::getQuestionList(){
    return Exercise::questionList;
};

Question Exercise::execQuestionsMenu(std::vector<Question> questionList){
    int questionListLength = questionList.size();

    std::vector<std::string> listing;

    listing.reserve(questionListLength);

    if(questionListLength > 0){
        for(int currentQuestionIndex = 0; currentQuestionIndex < questionListLength; currentQuestionIndex++){
            listing.push_back(questionList[currentQuestionIndex].getQuestionName());
        }
    }else{
        listing.push_back("No questions found");
    }

    uiHandler::showBarsLine(28);

    uiHandler::showListing("Exercise", "Available questions", listing);

    uiHandler::showBarsLine(28);

    int menuChoice = 0;

    while(menuChoice < 1 || menuChoice > questionListLength){
        std::cout << "\n\nInsert an question between [" << 1 << " - " << questionListLength << "]: " ;
        std::cin >> menuChoice;

        if(menuChoice < 1 || menuChoice > questionListLength){
            std::cout << "\nYou inserted " << menuChoice << " please insert values between [" << 1 << " - " << questionListLength << "]";
        }
    }

    return questionList[menuChoice - 1];
};

void Exercise::runQuestion(std::function<void()> runnableQuestionExec){
    system("CLS");
    
    runnableQuestionExec();
};