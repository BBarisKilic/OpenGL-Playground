//
// Created by bbk on 03.08.2018.
//

#include "display.h"

draw::draw(const std::string& title, int w, int h){
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    m_glwindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_OPENGL);
    m_glcontext = SDL_GL_CreateContext(m_glwindow);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0);
    glColor3f(0.0f, 1.0f, 0.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 640.0/480.0, 1.0f, 500.0f);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    float color[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, color);

    m_isClosed = false;
}

draw::~draw(){
    SDL_GL_DeleteContext(m_glcontext);
    SDL_DestroyWindow(m_glwindow);
    SDL_Quit();
}

bool draw::IsClosed(){
    return m_isClosed;
}

void draw::update(){
    SDL_GL_SwapWindow(m_glwindow);

    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
            m_isClosed = true;
    }
}