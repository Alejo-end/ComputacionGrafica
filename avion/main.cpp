#include <GL/glut.h>
#include <windows.h>
#include <cmath>

#if defined(LINUX) || defined(WIN32)
using namespace std;
#endif


void dibujar();
void proyeccion();
void avion();

float radio = 10, calx, caly;

//teclado
float pos_x = 0;

//menu
static int window;


void proyeccion(){
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-40,40,-40,40);
}
void dibujar() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(2.0);

}
void avion(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,1.0,0.5);
    glLineWidth(4.0);

    //Cuerpo
    glBegin(GL_LINE_STRIP);

    glVertex2i(10,0);
    glVertex2i(-1,0);
    glVertex2i(-10,4);
    glVertex2i(2,5);
    glVertex2i(10,5);
    glVertex2i(10,0);

    glEnd();

    //ala baja
    glBegin(GL_LINE_STRIP);

    glVertex2i(9,1);
    glVertex2i(1,1);
    glVertex2i(4,2);
    glVertex2i(9,2);
    glVertex2i(9,1);

    glEnd();

    //ala alta
    glBegin(GL_LINE_STRIP);

    glVertex2i(10,7);
    glVertex2i(2,7);
    glVertex2i(5,8);
    glVertex2i(10,8);
    glVertex2i(10,7);

    glEnd();

    // esqueleto
    glBegin(GL_LINE_STRIP);

    glVertex2i(3,1);
    glVertex2i(5,7);
    glVertex2i(7,2);
    glVertex2i(8,7);

    glEnd();

    //motor
    glBegin(GL_LINE_STRIP);

    glVertex2i(10,-1);
    glVertex2i(10,6);
    glVertex2i(12,6);
    glVertex2i(12,-1);
    glVertex2i(10,-1);


    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    for (float i=0; i<10; i+=0.01)
    {
        calx = radio * cos(i);
        caly = radio * sin(i);
        glVertex2f(calx-50, caly);
    }
    glEnd();
    glFlush();
}


void teclado(int tecla, int x, int y){
    switch(tecla){
        case GLUT_KEY_LEFT:
            pos_x = pos_x - 1;
            glutPostRedisplay();
            break;

        case GLUT_KEY_RIGHT:
            pos_x = pos_x + 1;
            glutPostRedisplay();
            break;
    }
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    window = glutCreateWindow("avion en OpenGL");

    proyeccion();
    dibujar();
    avion();


    glClearColor(1.0,1.0,1.0,0.0);
    glutDisplayFunc(dibujar);
    glutSpecialFunc(teclado);

    glutMainLoop();
    return EXIT_SUCCESS;
}
