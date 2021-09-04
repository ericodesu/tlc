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

void exercises::runFifthExercise(){
    FifthExercise *exercise = NULL;

    exercise = new FifthExercise();

    Question *q1 = NULL;
    Question *q2 = NULL;

    q1 = new Question("q1", std::bind(&FifthExercise::execQ1, exercise));
    q2 = new Question("q2", std::bind(&FifthExercise::execQ2, exercise));
    
    std::vector<Question> question_list = {
        *q1,
        *q2
    };

    exercise->setQuestionList(question_list);

    Question current_question = exercise->execQuestionsMenu(exercise->getQuestionList());

    exercise->runQuestion(current_question.getExecQuestion());
};

void exercises::runEighthExercise(){
    EighthExercise *exercise = NULL;

    exercise = new EighthExercise();

    Question *q1 = NULL;

    q1 = new Question("q1", std::bind(&EighthExercise::execQ1, exercise));
    
    std::vector<Question> question_list = {
        *q1
    };

    exercise->setQuestionList(question_list);

    Question current_question = exercise->execQuestionsMenu(exercise->getQuestionList());

    exercise->runQuestion(current_question.getExecQuestion());
};

void exercises::runNinthExercise(){
    NinthExercise *exercise = NULL;

    exercise = new NinthExercise();

    Question *q1 = NULL;
    Question *q2 = NULL;

    q1 = new Question("q1", std::bind(&NinthExercise::execQ1, exercise));
    q2 = new Question("q2", std::bind(&NinthExercise::execQ2, exercise));
    
    std::vector<Question> question_list = {
        *q1,
        *q2
    };

    exercise->setQuestionList(question_list);

    Question current_question = exercise->execQuestionsMenu(exercise->getQuestionList());

    exercise->runQuestion(current_question.getExecQuestion());
};

void exercises::runTenthExercise(){
    TenthExercise *exercise = NULL;

    exercise = new TenthExercise();

    Question *q1 = NULL;

    q1 = new Question("q1", std::bind(&TenthExercise::execQ1, exercise));
    
    std::vector<Question> question_list = {
        *q1
    };

    exercise->setQuestionList(question_list);

    Question current_question = exercise->execQuestionsMenu(exercise->getQuestionList());

    exercise->runQuestion(current_question.getExecQuestion());
};

void exercises::runThirteenthExercise(){
    ThirteenthExercise *exercise = NULL;

    exercise = new ThirteenthExercise();

    Question *q1 = NULL;

    q1 = new Question("q1", std::bind(&ThirteenthExercise::execQ1, exercise));
    
    std::vector<Question> question_list = {
        *q1
    };

    exercise->setQuestionList(question_list);

    Question current_question = exercise->execQuestionsMenu(exercise->getQuestionList());

    exercise->runQuestion(current_question.getExecQuestion());
};