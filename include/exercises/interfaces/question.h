#ifndef EXERCISE_INTERFACE_H
#define EXERCISE_INTERFACE_H

#include <functional>
#include <string>

class IQuestion {
    private:
        virtual std::string getQuestionName() = 0;
        virtual std::function<void()> getExecQuestion() = 0;
};

#endif