#ifndef CAR_H
#define CAR_H

#include "Entity.h"

class Car: public MovingEntity {
private:
    Direction direction;
public:
    Car(float speed, Direction Direction, float y);
    void update(float elapsedTime);
};

#endif