#include "randomwaypoint.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

RandomWaypoint::RandomWaypoint(float x, float y)
    :x(0), y(0), x_end(0), y_end(0), x_speed(0), y_speed(0), steps(0)
{
    this->x = x;
    this->y = y;
}

float RandomWaypoint::getX()
{
    return x;
}

float RandomWaypoint::getY()
{
    return y;
}

void RandomWaypoint::setX(float x)
{
    this->x = x;
}

void RandomWaypoint::setY(float y)
{
    this->y = y;
}

void RandomWaypoint::proceed()
{
     x += x_speed;
     y += y_speed;
     if ((abs(x - x_end) < 1.0) && (abs(y - y_end) < 1.0))
     {
         x = x_end;
         y = y_end;
     }
     newMovement();
}

void RandomWaypoint::newMovement()
{
   srand(time(NULL));
   x_end = (float)(rand() % 401);
   y_end = (float)(rand() % 401);
   steps = (float)(rand() % 991) + 10;
   x_speed = ((x_end - x) / steps);
   y_speed = ((y_end - y) / steps);
}
