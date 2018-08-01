//
// Created by bbk on 02.08.2018.
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


struct coordinate{
    float x, y, z;
    coordinate(float a, float b, float c) : x(a), y(b), z(c) {};
};
struct face{
    int facenum;
    bool four;
    int faces[4];
    face(int a, int b, int c, int d, int e) : facenum(a) {
        faces[0] = b;
        faces[1] = c;
        faces[2] = d;
        faces[3] = e;
        four = true;
    };
    face(int a, int b, int c, int d) : facenum(a) {
        faces[0] = b;
        faces[1] = c;
        faces[2] = d;
        four = false;
    };
};

class draw{
private:
    SDL_Window* m_glwindow;
    SDL_GLContext m_glcontext;
    bool m_isClosed;

    draw(const draw& other){}
    draw& operator=(const draw& other){}
public:
    draw(const std::string& title, int w, int h);
    virtual ~draw();
    void update();
    bool IsClosed();
};

#endif // DISPLAY_H

