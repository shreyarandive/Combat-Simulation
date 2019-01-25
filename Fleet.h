//
//  Fleet.h
//  CombatSimulation
//
//  Copyright © 2019 Shreya Randive. All rights reserved.
//
#include <queue>

using namespace std;

struct Fleet
{
    priority_queue<Ships*> patrolboats, frigates, battleships, temp;
    int total_patrolboats = 0, total_frigates = 0, total_battleships = 0, total_ships = 0;
    int fleet_number = 0, health = 0, fleet_damage = 0;
    
    
    Fleet& addPatrolBoatToFleet(PatrolBoat * ship)
    {
        patrolboats.push(ship);
        total_patrolboats++;
        return *this;
    }
    
    Fleet& addFrigateToFleet(Frigate * ship)
    {
        frigates.push(ship);
        total_frigates++;
        return *this;
    }
    
    Fleet& addBattleShipsToFleet(BattleShip * ship)
    {
        battleships.push(ship);
        total_battleships++;
        return *this;
    }
    
    Fleet& setTotalShipsInFleet()
    {
        total_ships = total_patrolboats + total_frigates + total_battleships;
        return *this;
    }
    
    bool alive()
    {
        return total_ships > 0;
    }
    
    void longRangeShipsAttack()
    {
        fleet_damage += total_battleships * battleships.top()->getDamage();
    }
    
    void mediumRangeShipsAttack()
    {
        fleet_damage += total_frigates * frigates.top()->getDamage();
    }
    
    void shortRangeShipsAttack()
    {
        fleet_damage += total_patrolboats * patrolboats.top()->getDamage();
    }
    
    void applyDamageToOtherFleet(int &damage_by_other_fleet)
    {
        while(damage_by_other_fleet != 0 && !patrolboats.empty())
        {
            health = patrolboats.top()->getHealth();
            
            if(damage_by_other_fleet < health)
            {
                patrolboats.top()->reduceHealth(damage_by_other_fleet);
                damage_by_other_fleet = 0;
            }
            
            else
            {
                damage_by_other_fleet -= patrolboats.top()->getHealth();
                patrolboats.pop();
                total_patrolboats--;
                total_ships--;
            }
        }
        
        while(damage_by_other_fleet != 0 && !frigates.empty())
        {
            health = frigates.top()->getHealth();
            
            if(damage_by_other_fleet < health)
            {
                frigates.top()->reduceHealth(damage_by_other_fleet);
                damage_by_other_fleet = 0;
            }
            
            else
            {
                damage_by_other_fleet -= frigates.top()->getHealth();
                frigates.pop();
                total_frigates--;
                total_ships--;
            }
        }
        
        while(damage_by_other_fleet != 0 && !battleships.empty())
        {
            health = battleships.top()->getHealth();
            
            if(damage_by_other_fleet < health)
            {
                battleships.top()->reduceHealth(damage_by_other_fleet);
                damage_by_other_fleet = 0;
            }
            
            else
            {
                damage_by_other_fleet -= battleships.top()->getHealth();
                battleships.pop();
                total_battleships--;
                total_ships--;
            }
        }
    }
    
    void displayFleetHealthAndShipCount()
    {
        cout<<"Ship Health in Fleet "<<fleet_number<<" --> ";
        
        temp = patrolboats;
        while(!temp.empty())
        {
            cout<<temp.top()->getHealth()<<" ";
            temp.pop();
        }
        
        temp = frigates;
        while(!temp.empty())
        {
            cout<<temp.top()->getHealth()<<" ";
            temp.pop();
        }
        
        temp = battleships;
        while(!temp.empty())
        {
            cout<<temp.top()->getHealth()<<" ";
            temp.pop();
        }
        
        if(total_ships == 0)
            cout<<"All the Ships are destroyed at the end of this Attack!";
        
        cout<<endl;
    }
};
