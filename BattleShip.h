//
//  BattleShip.h
//  CombatSimulation
//
//  Copyright © 2019 Shreya Randive. All rights reserved.
//

class BattleShip : public Ships
{
    int health = 600;
    static const int damage = 30;
    //const int attack_range = 3;
    
public:
    int getHealth() { return health; }
    
    int getDamage() { return damage; }
    
    //int getAttackRange() { return attack_range; }
    
    void reduceHealth(int damage) { health = health - damage; }
};
