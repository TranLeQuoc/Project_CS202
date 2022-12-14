#include "Car.h"
#include "Constants.h"
#include "Global.h"
#include "Random.h"

Car::Car(float speed, Direction direction, float y): 
    MovingEntity(&(Global::get().carSound),(direction == DIRECTION_LEFT)? Global::get().vehicleTexture[Random::next(0, 4)][0]: Global::get().vehicleTexture[Random::next(0, 4)][1], speed, 0 , y), direction(direction) {
    
    // assign later because Entity haven't initilized
    x = (direction==DIRECTION_LEFT? SCREEN_WIDTH : -getWidth());
}

void Car::update(float elapsedTime, TrafficLight* trafficLight) {
    MovingEntity::update(elapsedTime, trafficLight);
    if (direction == DIRECTION_LEFT) {
        x -= speed * elapsedTime;
    } else {
        x += speed * elapsedTime;
    }
}
