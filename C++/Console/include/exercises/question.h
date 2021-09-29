#ifndef TLC_CPP_INCLUDE_EXERCISES_QUESTION_H
#define TLC_CPP_INCLUDE_EXERCISES_QUESTION_H

#include <exercises/interfaces/question_interface.h>

#include <functional>
#include <string>

class Question: public IQuestion {
public:
    Question(std::string initial_question_name, std::function<void()> initialQuestionExec);
    std::function<void()> getExecQuestion();
    std::string getQuestionName();

private:
    std::function<void()> questionExec;
    std::string question_name;
};

#endif