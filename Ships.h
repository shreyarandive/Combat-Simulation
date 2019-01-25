//
//  Ships.h
//  CombatSimulation
//
//  Copyright © 2019 Shreya Randive. All rights reserved.
//

class Ships
{
public:
    virtual int getHealth() = 0;
    virtual int getDamage() = 0;
    virtual void reduceHealth(int damage) = 0;
    //virtual int getAttackRange() = 0;
};
