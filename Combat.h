//
//  Combat.h
//  CombatSimulation
//
//  Copyright © 2019 Shreya Randive. All rights reserved.
//
using namespace std;

class Combat : public Fleet
{
    int attack = 1;
    string attack_message;
    
    public:
    
    Combat(){}
    
    void begin(Fleet fleet_one, Fleet fleet_two)
    {
        string attack_message;
        cout<<"COMBAT BEGINS...\nAll Ships are at Full Health...\n"<<endl;
        
        fleet_one.displayFleetHealthAndShipCount();
        fleet_two.displayFleetHealthAndShipCount();
    }
    
    void continueAttack(Fleet &fleet_one, Fleet &fleet_two)
    {
        attack_message = (attack > 2 ) ? "All Ships ATTACK!!!\n" : (attack == 1) ? "Ships at Long Range ATTACK!!!\n" : "Ships at Long & Medium Range ATTACK!!!\n";
        
        cout<<endl<<attack_message<<endl;
        
        //long range will attack first
        if(attack > 0)
        {
            fleet_one.longRangeShipsAttack();
            fleet_two.longRangeShipsAttack();
        }
        
        //medium range attacks
        if(attack > 1)
        {
            fleet_one.mediumRangeShipsAttack();
            fleet_two.mediumRangeShipsAttack();
        }
        
        //all ranges attack
        if(attack > 2)
        {
            fleet_one.shortRangeShipsAttack();
            fleet_two.shortRangeShipsAttack();
        }
        
        fleet_one.applyDamageToOtherFleet(fleet_two.fleet_damage);
        fleet_two.applyDamageToOtherFleet(fleet_one.fleet_damage);
        
        attack++;
        
        fleet_one.displayFleetHealthAndShipCount();
        fleet_two.displayFleetHealthAndShipCount();
    }
    
    void finish(Fleet fleet_one, Fleet fleet_two)
    {
        if(fleet_one.total_ships > 0)
            cout<<"\nFleet 1 Wins the COMBAT!!"<<endl;
        else
            cout<<"\nFleet 2 Wins the COMBAT!!"<<endl;
        
        cout<<endl<<"FIN.\n"<<endl;
    }
};
