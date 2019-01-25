//
//  Frigate.h
//  CombatSimulation
//
//  Copyright © 2019 Shreya Randive. All rights reserved.
//

class Frigate : public Ships
{
    int health = 200;
    static const int damage = 45;
    //static const int attack_range = 2;
    
public:
    int getHealth() { return health; }
    
    int getDamage() { return damage; }
    
    //int getAttackRange() { return attack_range;}
    
    void reduceHealth(int damage) { health = health - damage; }
};

