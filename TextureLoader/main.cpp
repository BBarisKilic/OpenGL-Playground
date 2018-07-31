#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

float derece = 0.0;

unsigned int loadTexture(const char* filename)
{
    SDL_Surface* img = SDL_LoadBMP(filename);

    unsigned int id;
    glGenTextures(1,&id);
    glBindTexture(GL_TEXTURE_2D,id);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,img->w,img->h,0,GL_RGB,GL_UNSIGNED_SHORT_5_6_5,img->pixels);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    SDL_FreeSurface(img);
    return id;
}

GLuint tex;

void init( void )
{
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,640.0/480.0,1.0,500.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    tex=loadTexture("wall.bmp");
}

void display( void )
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-5.0);
    glRotatef(derece,1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D,tex);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0,2.0);
    glVertex3f(-2.0,2.0,0.0);
    glTexCoord2f(0.0,0.0);
    glVertex3f(-2.0,-2.0,0.0);
    glTexCoord2f(2.0,0.0);
    glVertex3f(2.0,-2.0,0.0);
    glTexCoord2f(2.0,2.0);
    glVertex3f(2.0,2.0,0.0);
    glEnd();

}


int main(int argc,char* argv[])
{

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* m_glwindow;
    SDL_GLContext m_glcontext;


    m_glwindow = SDL_CreateWindow("OpenGL Texture Loader", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
    m_glcontext = SDL_GL_CreateContext(m_glwindow);

    if(!m_glwindow)
        return 1;

    bool isRunning = true;
    Uint32 start;
    SDL_Event event;
    init();

    while(isRunning)
    {
        start=SDL_GetTicks();

        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT){
                isRunning=false;
                break;
            }
            if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE){
                isRunning=false;
                break;
            }
        }

        display();
        SDL_GL_SwapWindow(m_glwindow);
        derece+=0.5;
        if(1000/30>(SDL_GetTicks()-start))
            SDL_Delay(1000/30-(SDL_GetTicks()-start));
    }

    glDisable(GL_TEXTURE_2D);
    SDL_GL_DeleteContext(m_glcontext);
    SDL_DestroyWindow(m_glwindow);
    SDL_Quit();
    return 0;
}

