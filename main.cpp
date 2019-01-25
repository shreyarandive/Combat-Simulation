//
//  main.cpp
//  CombatSimulation
//
//  Copyright © 2019 Shreya Randive. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include "Ships.h"
#include "BattleShip.h"
#include "Frigate.h"
#include "PatrolBoat.h"
#include "Fleet.h"
#include "Combat.h"

using namespace std;

int main()
{
    Fleet fleetOne;
    fleetOne.fleet_number = 1;
    fleetOne.addPatrolBoatToFleet(new PatrolBoat())
            .addPatrolBoatToFleet(new PatrolBoat())
            .addPatrolBoatToFleet(new PatrolBoat())
            .addFrigateToFleet(new Frigate())
            .addFrigateToFleet(new Frigate())
            .addBattleShipsToFleet(new BattleShip())
            .setTotalShipsInFleet();
    
    Fleet fleetTwo;
    fleetTwo.fleet_number = 2;
    fleetTwo.addPatrolBoatToFleet(new PatrolBoat())
            .addFrigateToFleet(new Frigate())
            .addFrigateToFleet(new Frigate())
            .addBattleShipsToFleet(new BattleShip())
            .addBattleShipsToFleet(new BattleShip())
            .addBattleShipsToFleet(new BattleShip())
            .setTotalShipsInFleet();
    
    Combat combat;
    combat.begin(fleetOne, fleetTwo);
    
    while(fleetOne.alive() && fleetTwo.alive())
    {
        combat.continueAttack(fleetOne, fleetTwo);
    }
    
    combat.finish(fleetOne, fleetTwo);
    
    return 0;
}
