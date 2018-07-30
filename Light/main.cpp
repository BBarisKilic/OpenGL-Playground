#include <iostream>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

float angle = 0.0;


void displayCube(float size)
{
    float difamb[]={0.3,0.3,0.30,1.0};
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,difamb);

    glBegin(GL_QUADS);
    //ön kısım
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(size/2,size/2,size/2);
    glVertex3f(-size/2,size/2,size/2);
    glVertex3f(-size/2,-size/2,size/2);
    glVertex3f(size/2,-size/2,size/2);
    //sol kısım
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(-size/2,size/2,size/2);
    glVertex3f(-size/2,size/2,-size/2);
    glVertex3f(-size/2,-size/2,-size/2);
    glVertex3f(-size/2,-size/2,size/2);
    //üst kısım
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(size/2,size/2,size/2);
    glVertex3f(size/2,size/2,-size/2);
    glVertex3f(-size/2,size/2,-size/2);
    glVertex3f(-size/2,size/2,size/2);
    //sağ kısım
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(size/2,size/2,size/2);
    glVertex3f(size/2,size/2,-size/2);
    glVertex3f(size/2,-size/2,-size/2);
    glVertex3f(size/2,-size/2,size/2);
    //arka kısım
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(size/2,size/2,-size/2);
    glVertex3f(size/2,-size/2,-size/2);
    glVertex3f(-size/2,-size/2,-size/2);
    glVertex3f(-size/2,size/2,-size/2);
    //alt kısım
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(size/2,-size/2,size/2);
    glVertex3f(size/2,-size/2,-size/2);
    glVertex3f(-size/2,-size/2,-size/2);
    glVertex3f(-size/2,-size/2,size/2);
    glEnd();
}
void init(){
    glClearColor(0.0,0.0,0.0,1.0);//arkaplan rengi...
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,640.0/480.0,1.0,500.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //glEnable(GL_COLOR_MATERIAL);//renkleri aktif etmek için ama suan materialfv kullandıgımız için buna gerek duymuyoruz...

    float dif[]={1.0,1.0,1.0,1.0};
    glLightfv(GL_LIGHT0,GL_DIFFUSE,dif);
    float amb[]={0.3,0.3,0.3,1.0};
    glLightfv(GL_LIGHT0,GL_AMBIENT,amb);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    float pos[]={-2.0,2.0,-3.0,1.0};
    glLightfv(GL_LIGHT0,GL_POSITION,pos);

    glTranslatef(0.0,0.0,-6.0);
    glRotatef(angle,1.0,1.0,1.0);
    displayCube(2.0);
}

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* m_glwindow;
    SDL_GLContext m_glcontext;
    m_glwindow = SDL_CreateWindow("OpenGL Light", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
    m_glcontext = SDL_GL_CreateContext(m_glwindow);


    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    Uint32 start;
    SDL_Event event;
    init();
    bool isRunning = true;

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
        angle+=0.5;
        if(angle>360)
            angle-=360;
        SDL_GL_SwapWindow(m_glwindow);
        if(1000/30>(SDL_GetTicks()-start))
            SDL_Delay(1000/30-(SDL_GetTicks()-start));

    }

    SDL_GL_DeleteContext(m_glcontext);
    SDL_DestroyWindow(m_glwindow);
    SDL_Quit();
    return 0;
}
