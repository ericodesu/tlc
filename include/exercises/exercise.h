#ifndef EXERCISE_H
#define EXERCISE_H

#include <exercises/interfaces/exercise.h>
#include <exercises/question.h>

#include <functional>
#include <vector>

class Exercise: public IExercise {
    private:
       std::vector<Question> questionList;

    public:
        void setQuestionList(std::vector<Question> newQuestionList);
        std::vector<Question> getQuestionList();
        Question execQuestionsMenu(std::vector<Question> questionList);
        void runQuestion(std::function<void()> runnableQuestionExec);
};

#endif