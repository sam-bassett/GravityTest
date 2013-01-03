//
//  Point.cpp
//  GravityTest
//
//  Created by Sam Bassett on 2/01/13.
//  Copyright (c) 2013 Sam Bassett. All rights reserved.
//

#include "Point.h"

Point::Point() {
    x = 0;
    y = 0;
    hasMass = true;
    xSpeed = 0;
    ySpeed = 0;
    radius = 0;
}

Point::Point(double xval, double yval, double radius) {
    x = xval;
    y = yval;
    hasMass = true;
    xSpeed = 0;
    ySpeed = 0;
    this->radius = radius;
}

void Point::move(double dx, double dy) {
    x = x + dx;
    y = y + dy;
}

double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}

double Point::getXSpeed() {
    return xSpeed;
}

double Point::getYSpeed() {
    return ySpeed;
}

void Point::setXSpeed(double a) {
    xSpeed = a;
}

void Point::setYSpeed(double b) {
    ySpeed = b;
}

void Point::setX(double location) {
    x = location;
}

void Point::setY(double location) {
    y = location;
}

bool Point::isMassive() {
    return hasMass;
}

void Point::switchGrav() {
    if (hasMass) {
        hasMass = false;
    } else {
        hasMass = true;
    }
}

void Point::printStats() {
    printf("X:%f Y:%f\nxVel:%f yVel:%f\n", x, y, xSpeed, ySpeed);
}