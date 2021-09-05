#ifndef TLC_CPP_INCLUDE_EXERCISES_EXERCISE_H
#define TLC_CPP_INCLUDE_EXERCISES_EXERCISE_H

#include <exercises/interfaces/exercise_interface.h>
#include <exercises/question.h>

#include <functional>
#include <vector>

class Exercise: public IExercise {
    private:
       std::vector<Question> question_list;

    public:
        void setQuestionList(std::vector<Question> new_question_list);
        std::vector<Question> getQuestionList();
        Question execQuestionsMenu(std::vector<Question> question_list);
        void runQuestion(std::function<void()> runnableQuestion);
};

#endif