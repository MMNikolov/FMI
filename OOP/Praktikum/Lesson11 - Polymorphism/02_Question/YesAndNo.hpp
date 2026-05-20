#pragma once

#include "Question.hpp"

class YesAndNo : public Question
{
public:
    YesAndNo();
    YesAndNo(const char* description, unsigned points, bool isRight);

    //methods
    void ask() const override;
    unsigned grade() const override;

    //getters
    bool getIsRight() const { return this->isRight; };

private:
    bool isRight;
};
