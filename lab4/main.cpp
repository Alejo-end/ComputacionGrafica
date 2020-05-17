#include <cmath>
#include <iostream>
#include <cstdlib>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <windows.h>
#include <cmath>


#if defined(LINUX) || defined(WIN32)
using namespace std;
#endif

void iniciarProyeccion() {
    glClearColor(0.206078, 0.6, 0.7, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-6, 2, -5, 4);
}

void pista() {
    glColor3f(0.3, 0.3, 0.3);

    //pista de aterrizaje
    glBegin(GL_POLYGON);
    glVertex2f(2, 0);
    glVertex2f(2, -2);
    glVertex2f(-7, -6);
    glVertex2f(-7, -3);
    glVertex2f(2, 0);
    glEnd();
    //lineas montaña1
    glColor4f(0, 0, 0,1);
    glBegin(GL_LINES);
    glLineWidth(0.1);
    glVertex2f(-4.70, 1);
    glVertex2f(-4, 2);
    glVertex2f(-4, 2);
    glVertex2f(-3.3, 1);
    glEnd();
    //lineas montaña1
    glColor4f(0, 0, 0,1);
    glBegin(GL_LINES);
    glLineWidth(0.1);
    glVertex2f(-3.6, 1.45);
    glVertex2f(-2, 3.03);
    glVertex2f(-2, 3.03);
    glVertex2f(-.5, 1);

    glEnd();
    //lineas montaña2
    glColor4f(0, 0, 0,1);
    glBegin(GL_LINES);
    glLineWidth(0.1);
    glVertex2f(-1.1, 1.85);
    glVertex2f(-0.5, 3);
    glVertex2f(-0.5, 3);
    glVertex2f(.8, 1);

    glEnd();

    //lineas
    glColor3f(1.0,1.0,1.0);
    glLineWidth(5.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-6.9, -4.0);
    glVertex2f(-5.8, -5.01);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-4.5, -3.6);
    glVertex2f(-3.5, -3.2);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-2, -2.6);
    glVertex2f(-0.8, -2.1);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.8, -1.5);
    glVertex2f(1.8, -1.1);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(2, 0);
    glVertex2f(-7, -3);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-7, -6);
    glVertex2f(2, -2);
    glEnd();
    glFlush();
    //cesped
    glColor3f(0.3, 0.8, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(2, -2);
    glVertex2f(2, -8);
    glVertex2f(-8, -8);
    glVertex2f(2, 1);
    glVertex2f(-8,1);
    glVertex2f(-8,-8);
    glEnd();

    //montana1
    glBegin(GL_POLYGON);
    glVertex2f(-6, -1);
    glVertex2f(-4, 2);
    glVertex2f(-2, -1);
    glEnd();

    //montana2
    glBegin(GL_POLYGON);
    glVertex2f(-6, -1);
    glVertex2f(-2, 3);
    glVertex2f(1, -1);
    glEnd();
    //montana3
    glBegin(GL_POLYGON);
    glVertex2f(-2.5, -1);
    glVertex2f(-0.5, 3);
    glVertex2f(2, -1);
    glEnd();


}



//Metodo Main por donde el programa comienza a ejecutarse.
int main (int argc, char* argv []){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(300,100);
    glutCreateWindow ("Paisaje y edificio en OpenGL");
    iniciarProyeccion();
    glutDisplayFunc(pista);
    glutMainLoop();

}