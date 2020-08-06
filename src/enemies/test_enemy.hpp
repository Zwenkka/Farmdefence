#pragma once

#include <vector>
#include <iostream>

#include "enemy.hpp"
#include "../bullet.hpp"

class TestEnemy : public Enemy {
    public:
        //Constructor
        TestEnemy() 
            : Enemy() 
            {
                std::cout << "New enemy created!" << std::endl;
            }

        //Destructor, implement when class is abstract
        //~TestEnemy() = default;


        //Take damage
        /* Damage depends on bullet, certain bullets can have stronger or weaker effects on certain enemies.
        * 1. check if bullet is certain type 
        *   => if true take damage more or less than normally
        * 2. otherwise take damage or slow down for number of ticks
        */



};