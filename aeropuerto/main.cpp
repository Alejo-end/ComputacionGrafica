#include <cmath>
#include <iostream>
#include <cstdlib>

#include <GL/glu.h>
#include <GL/glut.h>
#include <windows.h>


using namespace std;

float radio = 0.1, calx = 0, caly = 0, pos_x = 0, pos_y = 0, radio2 = 0.5;

void proyeccion() {
    glClearColor(0.196078, 0.6, 0.8, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-11, 2, -11, 2);
}

void sol(){
/* ----------- sol -----------*/
    GLfloat color_esfera_ambiente[]={0.5,0.5,0.5,1.0};
    GLfloat color_esfera_difuso[]={0.8,0.8,0.8,1.0};
    GLfloat color_esfera_especular[]={0.5,0.5,0.5,1.0};
    GLfloat brillo_esfera_especular[]={5.0};
    GLfloat luz_ambiente[]={0.9,0.9,0.2,1.0};

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,luz_ambiente);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glColor3f(1.0,1.0,0.0);

    GLfloat luz_amarillo_ambiente[]={1.0,1.0,0.0,0.0};
    //GLfloat luz_naranja_difusa[]={1.0,0.5,0.0,0.0};
    GLfloat luz_amarillo_difusa[]={1.0,1.0,0.0,0.0};
    GLfloat luz_amarillo_especular[]={1.0,1.0,0.0,0.0};
    GLfloat luz_posicion[]={0.0,1.0,-2.0,1.0};
    GLfloat luz_ambiente_fuerte[]={0.6,0.2,0.2,1.0};

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(-9.0,1.0,0.0);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,luz_ambiente_fuerte);
    glLightfv(GL_LIGHT0,GL_AMBIENT,luz_amarillo_ambiente);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,luz_amarillo_difusa);
    glLightfv(GL_LIGHT0,GL_SPECULAR,luz_amarillo_especular);
    glLightfv(GL_LIGHT0,GL_POSITION,luz_posicion);
    glutSolidSphere(0.8,25,25);
    glPopMatrix();
    glDisable(GL_LIGHTING);

    glFlush();


}

void paisaje(){
    //calle
    glColor3f(0.25,0.25,0.25);
    glBegin(GL_POLYGON);
    glVertex2f(-11, -4);
    glVertex2f(-11, -7);
    glVertex2f(2,-7);
    glVertex2f(2,-4);
    glEnd();
    //sidewalks
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-11, -4);
    glVertex2f(-11, -3.5);
    glVertex2f(2,-3.5);
    glVertex2f(2,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-11, -7);
    glVertex2f(-11, -7.5);
    glVertex2f(2,-7.5);
    glVertex2f(2,-7);
    glEnd();
    //lineas
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-10,-5.5);
    glVertex2f(-8,-5.5);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(-7,-5.5);
    glVertex2f(-5,-5.5);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(-4,-5.5);
    glVertex2f(-2,-5.5);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(-1,-5.5);
    glVertex2f(1,-5.5);
    glEnd();
    //cesped
    glColor3f(0.3, 0.8, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(-11, -11);
    glVertex2f(-11, -7.5);
    glVertex2f(2,-7.5);
    glVertex2f(2,-11);
    glEnd();
    //montaña atrás
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-6.15, -3.5);
    glVertex2f(-11.15, -3.5);
    glVertex2f(-8.65, 0);
    glEnd();
    //montaña adelante
    glColor3f(0.75,0.75,0.75);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-7.15, -3.5);
    glVertex2f(-1.15, -3.5);
    glVertex2f(-4.15, 1);
    glEnd();
    //picos atrás
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-8.65, 0);
    glVertex2f(-7.2, -2);
    glVertex2f(-8.5,-1);
    glEnd();
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-8.65, 0);
    glVertex2f(-9.93, -1.8);
    glVertex2f(-8.4,-1.5);
    glEnd();
    //picos adelante
    glColor3f(0.85,0.85,0.85);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-4.15, 1);
    glVertex2f(-2.5, -1.5);
    glVertex2f(-4.5,-1);
    glEnd();
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-4.15, 1);
    glVertex2f(-4, -0.5);
    glVertex2f(-5.8,-1.5);
    glEnd();

    glFlush();
}


void dibujoAvion() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLineWidth(2.0);
    glEnable(GL_LINE_SMOOTH);

    /* ------------- RELLENO DE FONDO ------------- */
    // cuerpo
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-2+ pos_x, 0 + pos_y);
    glVertex2f(-2.6+ pos_x, -0.4 + pos_y);
    glVertex2f(-2.6+ pos_x, -0.7 + pos_y);
    glVertex2f(-2.4+ pos_x, -0.8 + pos_y);
    glVertex2f(-2+ pos_x, -0.8 + pos_y);
    glVertex2f(-1+ pos_x, -0.4 + pos_y);
    glVertex2f(0.1+ pos_x, 0.5 + pos_y);
    glVertex2f(-0.9+ pos_x, 0.525 + pos_y);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.1+ pos_x, 0.5 + pos_y);
    glVertex2f(-0.9+ pos_x, 0.525 + pos_y);
    glVertex2f(-0.6+ pos_x, 0.6 + pos_y);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.1+ pos_x, 0.5 + pos_y);
    glVertex2f(0.2+ pos_x, 1 + pos_y);
    glVertex2f(0.2+ pos_x, 1.4 + pos_y);
    glVertex2f(-0.2+ pos_x, 1.4 + pos_y);
    glVertex2f(-0.6+ pos_x, 0.6 + pos_y);
    glEnd();
    //asiento
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(-1.25+ pos_x, 0.1 + pos_y);
    glVertex2f(-1+ pos_x, 0.2 + pos_y);
    glVertex2f(-0.8+ pos_x, 0.4 + pos_y);
    glVertex2f(-0.9+ pos_x, 0.525 + pos_y);
    glVertex2f(-1.4+ pos_x, 0.4 + pos_y);
    glEnd();
    //ventana
    glColor3f(0.73, 0.85, 0.92);
    glBegin(GL_POLYGON);
    glVertex2f(-2+ pos_x, 0 + pos_y);
    glVertex2f(-2+ pos_x, 0.4 + pos_y);
    glVertex2f(-1.8+ pos_x, 0.5 + pos_y);
    glVertex2f(-1.4+ pos_x, 0.4 + pos_y);
    glVertex2f(-1.2+ pos_x, 0.2 + pos_y);
    glVertex2f(-1.4+ pos_x, -0.2 + pos_y);
    glVertex2f(-2+ pos_x, 0 + pos_y);
    glEnd();
    /* ------------- CONTORNO DE FONDO ------------- */
    glColor3f(0.0, 0.0, 0.0);
    // cuerpo
    glBegin(GL_LINE_STRIP);
    glVertex2f(-2+ pos_x, 0 + pos_y);
    glVertex2f(-2.6+ pos_x, -0.4 + pos_y);
    glVertex2f(-2.6+ pos_x, -0.7 + pos_y);
    glVertex2f(-2.4+ pos_x, -0.8 + pos_y);
    glVertex2f(-2+ pos_x, -0.8 + pos_y);
    glVertex2f(-1+ pos_x, -0.4 + pos_y);
    glVertex2f(0.1+ pos_x, 0.5 + pos_y);
    glVertex2f(0.2+ pos_x, 1 + pos_y);
    glVertex2f(0.2+ pos_x, 1.4 + pos_y);
    glVertex2f(-0.2+ pos_x, 1.4 + pos_y);
    glVertex2f(-0.6+ pos_x, 0.6 + pos_y);
    glVertex2f(-1.4+ pos_x, 0.4 + pos_y);
    glEnd();

    /* ------------- RELLENO ------------- */
    glColor3f(0.5, 0.5, 0.5);
    //aleta
    glBegin(GL_POLYGON);
    glVertex2f(0+ pos_x, 0.3 + pos_y);
    glVertex2f(0.6+ pos_x, 0.2 + pos_y);
    glVertex2f(0.9+ pos_x, 0.4 + pos_y);
    glVertex2f(-0.2+ pos_x, 0.7 + pos_y);
    glVertex2f(-0.3+ pos_x, 0.4 + pos_y);
    glVertex2f(0+ pos_x, 0.3 + pos_y);
    glEnd();
    //ala
    glBegin(GL_POLYGON);
    glVertex2f(-0.7+ pos_x, 0 + pos_y);
    glVertex2f(-1.3+ pos_x, -0.5 + pos_y);
    glVertex2f(0+ pos_x, -0.7 + pos_y);
    glVertex2f(0.3+ pos_x, -0.5 + pos_y);
    glVertex2f(-0.7+ pos_x, 0 + pos_y);
    glEnd();

    /* ------------- CONTORNO ------------- */
    glColor3f(0.0, 0.0, 0.0);
    //ventana
    glBegin(GL_LINE_STRIP);
    glVertex2f(-2+ pos_x, 0 + pos_y);
    glVertex2f(-2+ pos_x, 0.4 + pos_y);
    glVertex2f(-1.8+ pos_x, 0.5 + pos_y);
    glVertex2f(-1.4+ pos_x, 0.4 + pos_y);
    glVertex2f(-1.2+ pos_x, 0.2 + pos_y);
    glVertex2f(-1.4+ pos_x, -0.2 + pos_y);
    glVertex2f(-2+ pos_x, 0 + pos_y);
    glEnd();
    //aleta

    glBegin(GL_LINE_STRIP);
    glVertex2f(0+ pos_x, 0.3 + pos_y);
    glVertex2f(0.6+ pos_x, 0.2 + pos_y);
    glVertex2f(0.9+ pos_x, 0.4 + pos_y);
    glVertex2f(-0.2+ pos_x, 0.7 + pos_y);
    glVertex2f(-0.3+ pos_x, 0.4 + pos_y);
    glVertex2f(0+ pos_x, 0.3 + pos_y);
    glEnd();
    //ala

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.7+ pos_x, 0 + pos_y);
    glVertex2f(-1.3+ pos_x, -0.5 + pos_y);
    glVertex2f(0+ pos_x, -0.7 + pos_y);
    glVertex2f(0.3+ pos_x, -0.5 + pos_y);
    glVertex2f(-0.7+ pos_x, 0 + pos_y);
    glEnd();
    //asiento

    glBegin(GL_LINE_STRIP);
    glVertex2f(-1.25+ pos_x, 0.1 + pos_y);
    glVertex2f(-1+ pos_x, 0.2 + pos_y);
    glVertex2f(-0.8+ pos_x, 0.4 + pos_y);
    glVertex2f(-0.9+ pos_x, 0.525 + pos_y);
    glEnd();

/* ------------- Hélice 1 ------------- */
    glColor3f(0.0,0.0,0.0);

    //izquierda
    glBegin(GL_POLYGON);
    glVertex2f(-2.55+ pos_x, -0.7 + pos_y);
    glVertex2f(-2.7+ pos_x, -0.15 + pos_y);
    glVertex2f(-3+ pos_x, 0 + pos_y);
    glVertex2f(-3+ pos_x, -0.3 + pos_y);
    glVertex2f(-2.55+ pos_x, -0.7 + pos_y);
    glEnd();

    //derecha
    glBegin(GL_POLYGON);
    glVertex2f(-2.55+ pos_x, -0.7 + pos_y);
    glVertex2f(-2.35+ pos_x, -1.3 + pos_y);
    glVertex2f(-2.1+ pos_x, -1.4 + pos_y);
    glVertex2f(-2.05+ pos_x, -1.15 + pos_y);
    glVertex2f(-2.55+ pos_x, -0.7 + pos_y);
    glEnd();

/* ------------- Unión de hélices ------------- */
    /* ------------- RELLENO ------------- */
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    for (double i = 0.0; i < 6; i += 0.001) {
        calx = (radio)*cos(i);
        caly = (radio)*sin(i);
        glVertex2f(calx - 2.55 + pos_x, caly - 0.7 + pos_y);
    }
    glEnd();

    /* ------------- CONTORNO ------------- */
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for (double i = 0.0; i < 6; i += 0.001) {
        calx = (radio)*cos(i);
        caly = (radio)*sin(i);
        glVertex2f(calx - 2.55 + pos_x, caly - 0.7 + pos_y);
    }
    glEnd();


}

void dibujar(){

    dibujoAvion();
    paisaje();
    sol();
}


void tecladoSalir(unsigned char key, int x, int y) {
    switch (key) {
        case 'q':
            exit(0);
            break;
    }
}

void tecladoMover(int tecla, int x, int y) {
    switch (tecla) {
        case GLUT_KEY_UP:
            pos_y = pos_y + 0.25;
            if(pos_y > 11){
                pos_y = 0;
            }
            break;

        case GLUT_KEY_DOWN:
            pos_y = pos_y - 0.25;
            if(pos_y < -8){
                pos_y = 0;
            }
            break;

        case GLUT_KEY_RIGHT:
            pos_x = pos_x + 0.25;
            if(pos_x > 11){
                pos_x = 0;
            }
            break;

        case GLUT_KEY_LEFT:
            pos_x = pos_x - 0.25;
            if(pos_x < -8){
                pos_x = 0;
            }
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    cerr << "Para cambiar el sentido del auto, presione ARRIBA o ABAJO; para moverlo, presione IZQUIERDA O DERECHA." <<endl;
    cerr << "Presione la letra 'q' para salir." << endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(50, 100);
    glutCreateWindow("Avion en OpenGL");

    proyeccion();

    glutDisplayFunc(dibujar);

    glutKeyboardFunc(tecladoSalir);
    glutSpecialFunc(tecladoMover);

    glutMainLoop();

    return EXIT_SUCCESS;
}
