#include <iostream>
#include "DuckModule.h"

int main()
{
    Duck* modelDuck = new ModelDuck();
    
    modelDuck->performFly();
    modelDuck->performQuack();

    modelDuck->setFlyBehavior(unique_ptr<FlyBehavior>(new FlyWithWings()));
    modelDuck->setQuackBehavior(unique_ptr<QuackBehavior>(new Quack()));

    modelDuck->performFly();
    modelDuck->performQuack();

    return 0;
}