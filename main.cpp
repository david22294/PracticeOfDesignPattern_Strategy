#include <iostream>
#include "DuckModule.h"

int main()
{
    Duck* modelDuck = new ModelDuck();
    
    modelDuck->display();
    modelDuck->performFly();
    modelDuck->performQuack();

    // modelDuck->setFlyBehavior(unique_ptr<FlyBehavior>(new FlyWithWings()));
    // modelDuck->setQuackBehavior(unique_ptr<QuackBehavior>(new Quack()));

    modelDuck->setFlyBehavior(make_unique<FlyWithWings>());
    modelDuck->setQuackBehavior(make_unique<Quack>());

    modelDuck->performFly();
    modelDuck->performQuack();

    return 0;
}