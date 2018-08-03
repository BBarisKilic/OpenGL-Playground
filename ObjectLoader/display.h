//
// Created by bbk on 03.08.2018.
//

#ifndef DISPLAY_H
#define DISPLAY_H

#include <string.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <fstream>


class draw{
private:
    SDL_Window* m_glwindow;
    SDL_GLContext m_glcontext;
    bool m_isClosed;

    draw(const draw& other){}
    draw& operator=(const draw& other){}
public:
    draw(const std::string& title,int w,int h);
    virtual ~draw();
    void update();
    bool IsClosed();
};

#endif // DISPLAY_H
