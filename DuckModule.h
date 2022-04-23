#include <iostream>
#include <cstdio>
#include<memory>
#include "Behavior.h"

using namespace std;

class Duck
{
public:
    FlyBehavior* flyBehavior;
    QuackBehavior* quackBehavior;

    virtual void display(){}

    virtual void setFlyBehavior(FlyBehavior* fb){}
    virtual void setQuackBehavior(QuackBehavior* qb){}

    virtual void performFly(){}
    virtual void performQuack(){}
};

class ModelDuck: public Duck
{
public:
    ModelDuck()
    {
        flyBehavior = new FlyNoWay();
        quackBehavior = new MuteQuackBehavior();
    }

    ~ModelDuck()
    {
        if(flyBehavior){
            delete flyBehavior;
            flyBehavior = NULL;
        }

        if(quackBehavior){
            delete quackBehavior;
            quackBehavior = NULL;
        }
    }

    void display()
    {
        printf("Hi, I'm Model Duck.");
    }

    void setFlyBehavior(FlyBehavior* fb)
    {
        if(flyBehavior){
            delete flyBehavior;
            flyBehavior = NULL;
        }
        flyBehavior = fb;
    }
    void setQuackBehavior(QuackBehavior* qb)
    {
        if(quackBehavior){
            delete quackBehavior;
            quackBehavior = NULL;
        }
        quackBehavior = qb;
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