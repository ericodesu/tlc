#ifndef TLC_INCLUDE_EXERCISES_QUESTION_H
#define TLC_INCLUDE_EXERCISES_QUESTION_H

#include <exercises/interfaces/question_interface.h>

#include <functional>
#include <string>

class Question: public IQuestion {
    private:
        std::function<void()> QuestionExec;
        std::string question_name;

    public:
        Question(std::string initial_question_name, std::function<void()> InitialQuestionExec);
        std::function<void()> GetExecQuestion();
        std::string GetQuestionName();
};

#endif