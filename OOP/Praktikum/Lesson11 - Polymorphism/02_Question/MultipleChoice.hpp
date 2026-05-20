#pragma once

#include "Question.hpp"

class MultipleChoice : public Question
{
public:
    MultipleChoice();
    MultipleChoice(const char* description, unsigned points, const char** answe);
    ~MultipleChoice();

private:
    bool* choices;
    size_t size;
};
