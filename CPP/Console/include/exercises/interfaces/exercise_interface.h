#ifndef TLC_CPP_INCLUDE_EXERCISES_INTERFACES_EXERCISE_INTERFACE_H
#define TLC_CPP_INCLUDE_EXERCISES_INTERFACES_EXERCISE_INTERFACE_H

#include <exercises/question.h>

#include <functional>
#include <vector>

class IExercise {
    private:
        virtual void setQuestionList(std::vector<Question> new_question_list) = 0;
        virtual std::vector<Question> getQuestionList() = 0;
        virtual Question execQuestionsMenu(std::vector<Question> question_list) = 0;
        virtual void runQuestion(std::function<void()> runnableQuestion) = 0;
};

#endif