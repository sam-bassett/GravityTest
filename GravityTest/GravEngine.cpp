//
//  GravEngine.cpp
//  GravityTest
//
//  Created by Sam Bassett on 2/01/13.
//  Copyright (c) 2013 Sam Bassett. All rights reserved.
//

#include "GravEngine.h"


// moves points around and stops them at the borders of the space.
// later incorporate imperfect elastic collisions with borders.

GravEngine::GravEngine(int w, int h) {
    width = w;
    height = h;
    ticks = 0;
}

void GravEngine::step() {
    // iterate through all points, updating them as necessary. X and Y speeds
    // are affected, as are locations.
    
    std::vector<Point>::iterator i;
    for (i = points.begin(); i != points.end(); ++i) {
        // apply individual vector calculations to each point.
        // this is ugly.
        
        calculateStep(&(*i));
    }
    ticks++;
}

void GravEngine::addPoint(Point p) {
    points.push_back(p);
}

std::vector<Point> GravEngine::getPoints() {
    return points;
}

long GravEngine::getTicks() {
    return ticks;
}

void GravEngine::collide(Point *p) {
    // figure out where it's colliding, so the correct speed
    // can be changed.
    bool isX;
    double xVal, yVal;
    xVal = p->getX();
    yVal = p->getY();
    if (xVal >= width || xVal <= 0) {
        isX = true;
    } else if (yVal >= height || yVal <= 0) {
        isX = false;
    } else {
        std::cerr << "GravEngine reporting collision where there doesn't seem"
         << " to be one. Debug follows: ";
        std::cerr << "(width, height) = " << width << height;
        std::cerr << "(x, y) = " << p->getX() << p->getY();
    }
    
    if (isX) {
        double xSpeed = p->getXSpeed();
        p->setXSpeed(-xSpeed);
    } else {
        double ySpeed = p->getYSpeed();
        if (ySpeed >= 6) {
            ySpeed -= ySpeed/6;
        } else {
            ySpeed = 0;
        }
        p->setYSpeed(-ySpeed);
        // move slightly "in bounds" so it doesn't keep reversing velocity
        // FIX THIS SO IT IS ACTUALLY PHYSICS
        if (yVal >= height) {
            p->setY(height-5);
        } else {
            p->setY(5);
        }
    }
}

void GravEngine::calculateStep(Point *p) {
    // only do y for now.
    // in y,
    /*
     v = u + at
     s = ut + (at^2)/2
     s = ([u+v]/2)t
     v^2 = u^2 + 2as
     s = vt - (at^2)/2
     */
    
    // what is t here? we're looking at ∆ values, so having
    // a time to simulate is handy. maybe a constant value?
    // try 100ms to start with.
    
    // actually, this relies on a somewhat constant refresh rate.
    // ideally, maybe 100fps? so each step would move 10ms.
    // can you tell I'm new to this? 
    
    double yPos = p->getY();
    double yVel = p->getYSpeed();
    
    // populate both y speed and y position.
    // first check for collision.
    if (yPos >= height || yPos <= 0) {
        collide(p);
    } else {
        double yFinal = yVel + g*time;
        double s = yVel*time + (g*time*time)/2;
        p->setYSpeed(yFinal);
        p->move(0, s);
    }
}