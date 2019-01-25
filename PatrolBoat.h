//
//  PatrolBoat.h
//  CombatSimulation
//
//  Copyright © 2019 Shreya Randive. All rights reserved.
//

class PatrolBoat : public Ships
{
    int health = 100;
    static const int damage = 50;
    //const int attack_range = 1;
    
public:
    int getHealth() { return health;}
    
    int getDamage() { return damage; }
    
    //int getAttackRange() { return attack_range; }
    
    void reduceHealth(int damage) { health = health - damage; }
};

