#include <iostream>
#include <cstdio>
#include<memory>
#include "Behavior.h"

using namespace std;

class Duck
{
public:
    unique_ptr<FlyBehavior> flyBehavior;
    unique_ptr<QuackBehavior> quackBehavior;

    virtual void display(){}

    virtual void setFlyBehavior(unique_ptr<FlyBehavior> fb){}
    virtual void setQuackBehavior(unique_ptr<QuackBehavior> qb){}

    virtual void performFly(){}
    virtual void performQuack(){}
};

class ModelDuck: public Duck
{
public:
    ModelDuck()
    {
        flyBehavior = unique_ptr<FlyBehavior>(new FlyNoWay());
        quackBehavior = unique_ptr<QuackBehavior>(new MuteQuackBehavior());
    }

    ~ModelDuck()
    {

    }

    void display()
    {
        printf("Hi, I'm Model Duck.");
    }

    void setFlyBehavior(unique_ptr<FlyBehavior> fb)
    {
        flyBehavior = move(fb);
    }
    void setQuackBehavior(unique_ptr<QuackBehavior> qb)
    {
        quackBehavior = move(qb);
    }


    void performFly()
    {
        flyBehavior->fly();
    }

    void performQuack()
    {
        quackBehavior->quack();
    }
};