#ifndef TLC_INCLUDE_EXERCISES_EXERCISE_H
#define TLC_INCLUDE_EXERCISES_EXERCISE_H

#include <exercises/interfaces/exercise_interface.h>
#include <exercises/question.h>

#include <functional>
#include <vector>

class Exercise: public IExercise {
    private:
       std::vector<Question> question_list;

    public:
        void SetQuestionList(std::vector<Question> newQuestionList);
        std::vector<Question> GetQuestionList();
        Question ExecQuestionsMenu(std::vector<Question> questionList);
        void RunQuestion(std::function<void()> runnableQuestionExec);
};

#endif