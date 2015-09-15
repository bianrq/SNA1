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

    Model& initialise(void){
        fishes.initialise();
        return *this;
    }

    Model& start(void){
        now = 1900;
        environ.start();
        fishes.start(environ);
        fleet.start(fishes,environ);
        return *this;
    }

    Model& step(const int& steps=1){
        for(int step=0;step<steps;step++){
            std::cout<<now<<std::endl;

            fishes.track();

            environ.update();
            fishes.update(environ);
            fleet.update(fishes,environ);
            now++;
        }
        return *this;
    }

    Model& stop(void){
        return *this;
    }

    Model& run(int steps=20){
        start();
        step(steps);
        stop();
        return *this;
    }
}; // end class Model
