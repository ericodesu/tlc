#include <exercises/exercises.h>
#include <exercises/question.h>
#include <exercises/list/fifth.h>
#include <exercises/list/eighth.h>
#include <exercises/list/ninth.h>
#include <exercises/list/tenth.h>
#include <exercises/list/thirteenth.h>

#include <iostream>
#include <functional>
#include <vector>

void exercises::RunFifthExercise(){
    FifthExercise *exercise = NULL;

    exercise = new FifthExercise();

    Question *q1 = NULL;
    Question *q2 = NULL;

    q1 = new Question("q1", std::bind(&FifthExercise::ExecQ1, exercise));
    q2 = new Question("q2", std::bind(&FifthExercise::ExecQ2, exercise));
    
    std::vector<Question> question_list = {
        *q1,
        *q2
    };

    exercise->SetQuestionList(question_list);

    Question currentQuestion = exercise->ExecQuestionsMenu(exercise->GetQuestionList());

    exercise->RunQuestion(currentQuestion.GetExecQuestion());
};

void exercises::RunEighthExercise(){
    EighthExercise *exercise = NULL;

    exercise = new EighthExercise();

    Question *q1 = NULL;

    q1 = new Question("q1", std::bind(&EighthExercise::ExecQ1, exercise));
    
    std::vector<Question> question_list = {
        *q1
    };

    exercise->SetQuestionList(question_list);

    Question currentQuestion = exercise->ExecQuestionsMenu(exercise->GetQuestionList());

    exercise->RunQuestion(currentQuestion.GetExecQuestion());
};

void exercises::RunNinthExercise(){
    NinthExercise *exercise = NULL;

    exercise = new NinthExercise();

    Question *q1 = NULL;
    Question *q2 = NULL;

    q1 = new Question("q1", std::bind(&NinthExercise::ExecQ1, exercise));
    q2 = new Question("q2", std::bind(&NinthExercise::ExecQ2, exercise));
    
    std::vector<Question> question_list = {
        *q1,
        *q2
    };

    exercise->SetQuestionList(question_list);

    Question currentQuestion = exercise->ExecQuestionsMenu(exercise->GetQuestionList());

    exercise->RunQuestion(currentQuestion.GetExecQuestion());
};

void exercises::RunTenthExercise(){
    TenthExercise *exercise = NULL;

    exercise = new TenthExercise();

    Question *q1 = NULL;

    q1 = new Question("q1", std::bind(&TenthExercise::ExecQ1, exercise));
    
    std::vector<Question> question_list = {
        *q1
    };

    exercise->SetQuestionList(question_list);

    Question currentQuestion = exercise->ExecQuestionsMenu(exercise->GetQuestionList());

    exercise->RunQuestion(currentQuestion.GetExecQuestion());
};

void exercises::RunThirteenthExercise(){
    ThirteenthExercise *exercise = NULL;

    exercise = new ThirteenthExercise();

    Question *q1 = NULL;

    q1 = new Question("q1", std::bind(&ThirteenthExercise::ExecQ1, exercise));
    
    std::vector<Question> question_list = {
        *q1
    };

    exercise->SetQuestionList(question_list);

    Question currentQuestion = exercise->ExecQuestionsMenu(exercise->GetQuestionList());

    exercise->RunQuestion(currentQuestion.GetExecQuestion());
};