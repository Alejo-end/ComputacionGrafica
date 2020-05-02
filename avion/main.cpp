#include <GL/glut.h>
#include <cmath>

#if defined(LINUX) || defined(WIN32)
using namespace std;
#endif


void dibujar();
void proyeccion();
void nombre();


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
void nombre(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(1.0,0.0,0.0);
    glLineWidth(2.0);

    //F
    glBegin(GL_LINE_STRIP);

    glVertex2i(-20,20);
    glVertex2i(-15,20);
    glVertex2i(-15,18);
    glVertex2i(-18,18);
    glVertex2i(-18,16);
    glVertex2i(-15,16);
    glVertex2i(-15,14);
    glVertex2i(-18,14);
    glVertex2i(-18,0);
    glVertex2i(-20,0);
    glVertex2i(-20,20);

    glEnd();


    // E
    glBegin(GL_LINE_STRIP);

    glVertex2i(-13,20);
    glVertex2i(-8,20);
    glVertex2i(-8,18);
    glVertex2i(-11,18);
    glVertex2i(-11,16);
    glVertex2i(-8,16);
    glVertex2i(-8,14);
    glVertex2i(-11,14);
    glVertex2i(-11,2);
    glVertex2i(-8,2);
    glVertex2i(-8,0);
    glVertex2i(-13,0);
    glVertex2i(-13,20);

    glEnd();

    // L
    glBegin(GL_LINE_STRIP);

    glVertex2i(-6,20);
    glVertex2i(-4,20);
    glVertex2i(-4,2);
    glVertex2i(-1,2);
    glVertex2i(-1,0);
    glVertex2i(-6,0);
    glVertex2i(-6,20);
    glEnd();

    // L
    glBegin(GL_LINE_STRIP);

    glVertex2i(1,20);
    glVertex2i(3,20);
    glVertex2i(3,2);
    glVertex2i(6,2);
    glVertex2i(6,0);
    glVertex2i(1,0);
    glVertex2i(1,20);
    glEnd();

    // A
    glBegin(GL_LINE_STRIP);

    glVertex2i(8,20);
    glVertex2i(13,20);
    glVertex2i(13,0);
    glVertex2i(11,0);
    glVertex2i(11,14);
    glVertex2i(10,14);
    glVertex2i(10,0);
    glVertex2i(8,0);
    glVertex2i(8,20);

    glEnd();

    // centro de la A
    glBegin(GL_LINE_STRIP);

    glVertex2i(10,18);
    glVertex2i(11,18);
    glVertex2i(11,16);
    glVertex2i(10,16);
    glVertex2i(10,18);

    glEnd();

    // S
    glBegin(GL_LINE_STRIP);

    glVertex2i(15,20);
    glVertex2d(20,20);
    glVertex2d(20,18);
    glVertex2i(17,18);
    glVertex2i(17,16);
    glVertex2i(20,16);
    glVertex2i(20,0);
    glVertex2i(15,0);
    glVertex2i(15,2);
    glVertex2i(18,2);
    glVertex2i(18,14);
    glVertex2i(15,14);
    glVertex2i(15,20);

    glEnd();

    // lineas
    glLineWidth(10.0);
    glBegin(GL_LINE_STRIP);

    glVertex2i(-24,-2);
    glVertex2d(24,-2);

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
    nombre();

    glClearColor(1.0,1.0,1.0,0.0);
    glutDisplayFunc(dibujar);
    glutSpecialFunc(teclado);

    glutMainLoop();
    return EXIT_SUCCESS;
}
