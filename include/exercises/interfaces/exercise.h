#ifndef QUESTION_INTERFACE_H
#define QUESTION_INTERFACE_H

#include <exercises/question.h>

#include <functional>
#include <vector>

class IExercise {
    private:
        virtual void setQuestionList(std::vector<Question> newQuestionList) = 0;
        virtual std::vector<Question> getQuestionList() = 0;
        virtual Question execQuestionsMenu(std::vector<Question> questionList) = 0;
        virtual void runQuestion(std::function<void()> runnableQuestionExec) = 0;
};

#endif