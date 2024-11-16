#pragma once

#include <iostream>

class Talent
{
public:
    virtual void showTalent() const = 0;
    virtual ~Talent() = default;
};

class Swimming : virtual public Talent
{
public:
    virtual void showTalent() const override;
};

class Dancing : virtual public Talent
{
public:
    virtual void showTalent() const override;
};

class Counting : virtual public Talent
{
public:
    virtual void showTalent() const override;
};
