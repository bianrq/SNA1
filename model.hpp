#pragma once

#include "environ.hpp"
#include "fishes.hpp"
#include "fleet.hpp"

/**
 * The model
 *
 * Links together the sub-models `Environ`, 'Fishes` and `Fleet`
 */
class Model {
public:

    Environ environ;
    Fishes fishes;
    Fleet fleet;

    Model& start(void){
        environ.start();
        fishes.start(environ);
        fleet.start(fishes,environ);
        return *this;
    }

    Model& step(const int& steps=1){
        for(int step=0;step<steps;step++){
            //std::cout<<step<<std::endl;
            environ.update();
            fishes.update(environ);
            fleet.update(fishes,environ);
        }
        return *this;
    }

    Model& stop(void){
        return *this;
    }

    Model& run(int steps=1000){
        start();
        step(steps);
        stop();
        return *this;
    }
}; // end class Model
