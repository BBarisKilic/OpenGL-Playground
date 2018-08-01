//
// Created by bbk on 02.08.2018.
//


#include "display.h"

float angle = 0.0;
int cube;

int loadObject(const char* xxx)
{
    std::vector<std::string*> coord;
    std::vector<coordinate*> vertex;
    std::vector<face*> faces;
    std::vector<coordinate*> normals;

    std::ifstream in(xxx);
    if (!in.is_open()){
        std::cout << "read error." << std::endl;
        return -1;
    }

    char buf[256];
    while (!in.eof()){
        in.getline(buf, 256);
        coord.push_back(new std::string(buf));
    }

    for (unsigned int i = 0; i < coord.size(); i++)
    {
        if ((*coord[i])[0] == 'v' && (*coord[i])[1] == ' '){
            float tmpx, tmpy, tmpz;
            sscanf(coord[i]->c_str(), "v %f %f %f", &tmpx, &tmpy, &tmpz);
            vertex.push_back(new coordinate(tmpx, tmpy, tmpz));
        }
        else if ((*coord[i])[0] == 'v' && (*coord[i])[1] == 'n'){
            float tmpx, tmpy, tmpz;
            sscanf(coord[i]->c_str(), "vn %f %f %f", &tmpx, &tmpy, &tmpz);
            normals.push_back(new coordinate(tmpx, tmpy, tmpz));
        }
        else if ((*coord[i])[0] == 'f' && (*coord[i])[1] == ' '){
            int bosluk = 0;
            for (unsigned int a = 0; a < (*coord[i]).size(); a++){
                if ((*coord[i])[a] == ' ')
                    bosluk++;
            }
            if (bosluk == 4){
                int a, b, c, d, e;
                sscanf(coord[i]->c_str(), "f %d//%d %d//%d %d//%d %d//%d", &a, &b, &c, &b, &d, &b, &e, &b);
                faces.push_back(new face(b, a, c, d, e));
            }
            else{
                int a, b, c, d;
                sscanf(coord[i]->c_str(), "f %d//%d %d//%d %d//%d", &a, &b, &c, &b, &d, &b);
                faces.push_back(new face(b, a, c, d));
            }
        }
        else{
            continue;
        }
    }

    //çizim
    int num;
    num = glGenLists(1);
    glNewList(num, GL_COMPILE);
    for (unsigned int i = 0; i < faces.size(); i++){
        if (faces[i]->four){
            glBegin(GL_QUADS);
            glNormal3f(normals[faces[i]->facenum - 1]->x, normals[faces[i]->facenum - 1]->y, normals[faces[i]->facenum - 1]->z);
            glVertex3f(vertex[faces[i]->faces[0] - 1]->x, vertex[faces[i]->faces[0] - 1]->y, vertex[faces[i]->faces[0] - 1]->z);
            glVertex3f(vertex[faces[i]->faces[1] - 1]->x, vertex[faces[i]->faces[1] - 1]->y, vertex[faces[i]->faces[1] - 1]->z);
            glVertex3f(vertex[faces[i]->faces[2] - 1]->x, vertex[faces[i]->faces[2] - 1]->y, vertex[faces[i]->faces[2] - 1]->z);
            glVertex3f(vertex[faces[i]->faces[3] - 1]->x, vertex[faces[i]->faces[3] - 1]->y, vertex[faces[i]->faces[3] - 1]->z);
            glEnd();
        }
        else{
            glBegin(GL_TRIANGLES);
            glNormal3f(normals[faces[i]->facenum - 1]->x, normals[faces[i]->facenum - 1]->y, normals[faces[i]->facenum - 1]->z);
            glVertex3f(vertex[faces[i]->faces[0] - 1]->x, vertex[faces[i]->faces[0] - 1]->y, vertex[faces[i]->faces[0] - 1]->z);
            glVertex3f(vertex[faces[i]->faces[1] - 1]->x, vertex[faces[i]->faces[1] - 1]->y, vertex[faces[i]->faces[1] - 1]->z);
            glVertex3f(vertex[faces[i]->faces[2] - 1]->x, vertex[faces[i]->faces[2] - 1]->y, vertex[faces[i]->faces[2] - 1]->z);
            glEnd();
        }
    }
    glEndList();


    for (unsigned int i = 0; i < coord.size(); i++)
        delete coord[i];
    for (unsigned int i = 0; i < vertex.size(); i++)
        delete vertex[i];
    for (unsigned int i = 0; i < faces.size(); i++)
        delete faces[i];
    for (unsigned int i = 0; i < normals.size(); i++)
        delete normals[i];

    return num;
}



int main(int argc, char *argv[])
{

    draw draw("GLPush-Popmatrix", 640, 480);
    cube = loadObject("test.obj");


    while (!draw.IsClosed()){

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        float pos[] = { -1.0, 1.0, -2.0, 1.0 };
        glLightfv(GL_LIGHT0, GL_POSITION, pos);
        glPushMatrix();
        glTranslatef(-4.0f, 0.0f, -15.0f);
        glRotatef(angle, 0.0f, 1.0f, 0.0f);
        glCallList(cube);
        glPopMatrix();
        glTranslatef(3.0f, 0.0f, -10.0f);
        glCallList(cube);

        angle += 0.5f;
        if (angle >= 360.f)
            angle = 0.0f;

        draw.update();
    }

    return 0;
}