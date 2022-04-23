#include <iostream>
#include "DuckModule.h"

int main()
{
    Duck* modelDuck = new ModelDuck();
    
    modelDuck->performFly();
    modelDuck->performQuack();

    modelDuck->setFlyBehavior(new FlyWithWings());
    modelDuck->setQuackBehavior(new Quack());

    modelDuck->performFly();
    modelDuck->performQuack();

    return 0;
}