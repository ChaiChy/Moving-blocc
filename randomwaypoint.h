#ifndef RANDOMWAYPOINT_H
#define RANDOMWAYPOINT_H


class RandomWaypoint
{
public:
    RandomWaypoint(float x, float y);

    float getX();
    float getY();
    void setX(float x);
    void setY(float y);
    void proceed();
    void newMovement();
private:
    float x;
    float y;
    float x_end;
    float y_end;
    float x_speed;
    float y_speed;
    float steps;
};

#endif // RANDOMWAYPOINT_H
