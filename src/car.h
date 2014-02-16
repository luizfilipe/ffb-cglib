#ifndef CAR_H
#define CAR_H

#define ACCEL 0.01
#define DECCEL 0.005
#define TOP_SPEED 1.5
#define REVERSE_SPEED 0.5
#define BREAK_DECCEL 0.04

typedef struct
{
    Camera* camera;
    GLfloat currentSpeed;
} Car;

Car* newCar(Camera* camera)
{

    Car* car = (Car*) malloc( sizeof(Car) );
    car->camera = camera;
    car->currentSpeed = 0;
    
    return car;
}

void accelerateCar(Car* car)
{
    if(car->currentSpeed < TOP_SPEED)
    {
        car->currentSpeed += ACCEL;
    }
    else if(car->currentSpeed > TOP_SPEED)
    {
        car->currentSpeed = TOP_SPEED;
    } 
}

void deccelerateCar(Car* car)
{
    if(car->currentSpeed > 0)
    {
        car->currentSpeed -= DECCEL;
    }
    
    clamp(&car->currentSpeed, 0, TOP_SPEED);
}

void breakCar(Car* car)
{
    if(car->currentSpeed)
    {
       car->currentSpeed -= BREAK_DECCEL;
    }
    
    clamp(&car->currentSpeed, 0, TOP_SPEED);
}

void steerRightCar(Car* car)
{
    if(car->currentSpeed > 0)
        car->camera->rotation.Y -= 1;
}

void steerLeftCar(Car* car)
{
    if(car->currentSpeed > 0)
        car->camera->rotation.Y += 1;    
}

void updateCar(Car* car)
{
    moveFoward(car->camera, car->currentSpeed);
}

#endif
