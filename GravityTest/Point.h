//
//  Point.h
//  GravityTest
//
//  Created by Sam Bassett on 2/01/13.
//  Copyright (c) 2013 Sam Bassett. All rights reserved.
//

#ifndef __GravityTest__Point__
#define __GravityTest__Point__

#include <iostream>

#endif /* defined(__GravityTest__Point__) */


class Point {
public:
    Point();
    Point(double xval, double yval, double radius);
    
    void move(double dx, double dy);
    double getX();
    double getY();
    
    bool isMassive();
    void switchGrav();
    
    double getXSpeed();
    double getYSpeed();
    double getRadius();
    
    void setXSpeed(double a);
    void setYSpeed(double b);
    
    void setX(double location);
    void setY(double location);
    
    void printStats();
    
private:
    double x;
    double y;
    double xSpeed;
    double ySpeed;
    
    bool hasMass;
    double radius;
};