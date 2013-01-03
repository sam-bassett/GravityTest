//
//  GravEngine.h
//  GravityTest
//
//  Created by Sam Bassett on 2/01/13.
//  Copyright (c) 2013 Sam Bassett. All rights reserved.
//

#ifndef __GravityTest__GravEngine__
#define __GravityTest__GravEngine__

#include <iostream>
#include <vector>
#include "Point.h"

#endif /* defined(__GravityTest__GravEngine__) */


class GravEngine {
public:
    GravEngine(int w, int h);
    void step();
    
    void addPoint(Point p);
    
    std::vector<Point> getPoints();
    long getTicks();
    
private:
    const double g = 9.8; // acceleration due to gravity, in m/s/s
                          // note that SDL is strange, so gravity positive
    const double time = 0.5; // time per step, 10ms.
    
    int width;
    int height;
    
    std::vector<Point> points;
    long ticks;
    
    void calculateStep(Point *p);
    void collide(Point *p);
};