#include <exercises/question.h>

#include <functional>
#include <string>

Question::Question(std::string initialQuestionName, std::function<void()> initialQuestionExec){
    Question::questionName = initialQuestionName;
    Question::questionExec = initialQuestionExec;
};

std::string Question::getQuestionName(){
    return Question::questionName;
};

std::function<void()> Question::getExecQuestion(){
    return Question::questionExec;
};