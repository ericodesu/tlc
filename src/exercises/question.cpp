#include <exercises/question.h>

#include <functional>
#include <string>

Question::Question(std::string initial_question_name, std::function<void()> InitialQuestionExec){
    Question::question_name = initial_question_name;
    Question::QuestionExec = InitialQuestionExec;
};

std::string Question::GetQuestionName(){
    return Question::question_name;
};

std::function<void()> Question::GetExecQuestion(){
    return Question::QuestionExec;
};