#ifndef TLC_INCLUDE_EXERCISES_INTERFACES_EXERCISE_INTERFACE_H
#define TLC_INCLUDE_EXERCISES_INTERFACES_EXERCISE_INTERFACE_H

#include <exercises/question.h>

#include <functional>
#include <vector>

class IExercise {
    private:
        virtual void SetQuestionList(std::vector<Question> newQuestionList) = 0;
        virtual std::vector<Question> GetQuestionList() = 0;
        virtual Question ExecQuestionsMenu(std::vector<Question> questionList) = 0;
        virtual void RunQuestion(std::function<void()> runnableQuestionExec) = 0;
};

#endif