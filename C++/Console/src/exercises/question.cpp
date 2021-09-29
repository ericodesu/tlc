#include <exercises/question.h>

#include <functional>
#include <string>

Question::Question(std::string initial_question_name, std::function<void()> initialQuestionExec){
    Question::question_name = initial_question_name;
    Question::questionExec = initialQuestionExec;
};

std::string Question::getQuestionName(){
    return Question::question_name;
};

std::function<void()> Question::getExecQuestion(){
    return Question::questionExec;
};