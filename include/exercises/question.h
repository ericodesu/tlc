#ifndef TLC_INCLUDE_EXERCISES_QUESTION_H
#define TLC_INCLUDE_EXERCISES_QUESTION_H

#include <exercises/interfaces/question_interface.h>

#include <functional>
#include <string>

class Question: public IQuestion {
    private:
        std::function<void()> questionExec;
        std::string questionName;

    public:
        Question(std::string initialQuestionName, std::function<void()> initialQuestionExec);
        std::function<void()> getExecQuestion();
        std::string getQuestionName();
};

#endif