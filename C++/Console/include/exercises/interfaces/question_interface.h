#ifndef TLC_CPP_INCLUDE_EXERCISES_INTERFACES_QUESTION_INTERFACE_H
#define TLC_CPP_INCLUDE_EXERCISES_INTERFACES_QUESTION_INTERFACE_H

#include <functional>
#include <string>

class IQuestion {
private:
    virtual std::string getQuestionName() = 0;
    virtual std::function<void()> getExecQuestion() = 0;
};

#endif