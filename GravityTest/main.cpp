//
//  main.cpp
//  GravityTest
//
//  Created by Sam Bassett on 2/01/13.
//  Copyright (c) 2013 Sam Bassett. All rights reserved.
//

#include <iostream>
#include <SDL/SDL.h>
#include "GravEngine.h"

SDL_Surface *loadImage(std::string filename);
void applySurface(int x, int y, SDL_Surface *source, SDL_Surface *dest,
                  SDL_Rect *clip);


int main (int argc, char *argv[]) {
    
    // can you blit more than one thing to the screen?
    // if so, blit all the balls to the screen at once using the dot.bmp
    // using "applySurface". Store the points in vector,
    // iterate through and apply them one by one to a screen, blit and flip.
    
    GravEngine engine(800,600);
    
    //Start SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_Surface *screen = NULL;
    screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);
    SDL_WM_SetCaption("Newton would [now] be proud", NULL);
    
    SDL_Surface *dotBMP = SDL_LoadBMP("/Users/sam/Documents/Programming/C++/GravityTest/Resources/dot.bmp");
    if (dotBMP == NULL) {
        printf("Problem loading image\n");
        return EXIT_FAILURE;
    }
    
    bool quit = false;
    int ticks = 0;
    SDL_Event event;
    
    while(!quit) {
        ticks = SDL_GetTicks();
        while (SDL_PollEvent(&event)) {
            int mouseX, mouseY;
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                mouseX = event.button.x;
                mouseY = event.button.y;
                Point p(mouseX, mouseY, 10);
                engine.addPoint(p);
            }
            
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
        engine.step();
        
        SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
        
        // now show all points! involves applying the dot
        // to screen for each point.
        // it's okay to work with copies here. 
        std::vector<Point> points = engine.getPoints();
        std::vector<Point>::iterator i;
        for (i = points.begin(); i != points.end(); ++i) {
            // note *i is the point stored at i.
            int x = i->getX();
            int y = i->getY();
            applySurface(x, y, dotBMP, screen, NULL);
        }
        
        SDL_Flip(screen);
        
        if ((SDL_GetTicks() - ticks) < 1000 / 100) {
            SDL_Delay((1000/100) - ticks);
        }
    }
    
    SDL_Quit();
    return EXIT_SUCCESS;
}

SDL_Surface *loadImage(std::string filename) {
    SDL_Surface *loadedImage = NULL;
    SDL_Surface *optImage = NULL;
    loadedImage = SDL_LoadBMP(filename.c_str());
    optImage = SDL_DisplayFormat(loadedImage);
    SDL_FreeSurface(loadedImage);
    if (optImage != NULL) {
        SDL_SetColorKey(optImage, SDL_SRCCOLORKEY, SDL_MapRGB(optImage->format,
                                                              0, 0xFF, 0xFF));
    }
    return optImage;
}

void applySurface(int x, int y, SDL_Surface *source, SDL_Surface *dest, SDL_Rect *clip = NULL) {
    SDL_Rect offsets;
    
    offsets.x = x;
    offsets.y = y;
    
    SDL_BlitSurface(source, clip, dest, &offsets);
}
