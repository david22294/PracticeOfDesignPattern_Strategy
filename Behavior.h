#include <iostream>
#include <cstdio>
#include<memory>

class FlyBehavior
{
public:
    ~FlyBehavior(){std::cout<<"FlyBehavior object delete.\n";}
    virtual void fly(){}
};

class FlyWithWings: public FlyBehavior
{
public:
    void fly()
    {
        printf("I'm flying.\n");
    }
};

class FlyNoWay: public FlyBehavior
{
public:
    void fly()
    {
        printf("I can't fly.\n");
    }
};

class QuackBehavior
{
public:
    ~QuackBehavior(){std::cout<<"QuackBehavior object delete.\n";}
    virtual void quack(){}
};

class Quack: public QuackBehavior
{
public:
    void quack()
    {
        printf("Quack.\n");
    }
};

class MuteQuackBehavior: public QuackBehavior
{
public:
    void quack()
    {
        printf("<<Silence>>\n");
    }
};

class Squeak: public QuackBehavior
{
public:
    void quack()
    {
        printf("Squeak.\n");
    }
};