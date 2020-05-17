#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

float radio = 0.1, calx = 0, caly = 0, pos_x = 0, radio2 = 0.5;

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

void dibujoAutoI(){

/* ----------- RELLENO -----------*/
    //chasis
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-8.5 + pos_x,-6.5);
    glVertex2f(-8.5 + pos_x,-5.5);
    glVertex2f(-7.5 + pos_x,-5.5);
    glVertex2f(-7 + pos_x,-5);
    glVertex2f(-5.5 + pos_x,-5);
    glVertex2f(-4.5 + pos_x,-5.5);
    glVertex2f(-3.5 + pos_x,-5.5);
    glVertex2f(-4.4 + pos_x,-6.5);
    glVertex2f(-8.5 + pos_x,-6.5);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-6.25 + pos_x,-5);
    glVertex2f(-6.25 + pos_x,-4.5);
    glVertex2f(-6.55 + pos_x,-4.5);
    glVertex2f(-6.55 + pos_x,-5);
    glEnd();
    //ventana
    glColor3f(0.73, 0.85, 0.92);
    glBegin(GL_POLYGON);
    glVertex2f(-7.15 + pos_x,-5.55);
    glVertex2f(-6.8 + pos_x,-5.2);
    glVertex2f(-5.6 + pos_x,-5.2);
    glVertex2f(-5 + pos_x,-5.55);
    glVertex2f(-7.15 + pos_x,-5.55);
    glEnd();
    //ruedas
    glColor3f(0.0,0.0,0.0);
    //derecha
    glBegin(GL_POLYGON);
    for (double i = 0.0; i < 6; i += 0.001) {
        calx = (radio2)*cos(i);
        caly = (radio2)*sin(i);
        glVertex2f(calx - 5.425 + pos_x, caly - 6.5);
    }
    glEnd();
    //izquierda
    glBegin(GL_POLYGON);
    for (double i = 0.0; i < 6; i += 0.001) {
        calx = (radio2)*cos(i);
        caly = (radio2)*sin(i);
        glVertex2f(calx - 7.475 + pos_x, caly - 6.5);
    }
    glEnd();

/* ----------- CONTORNO -----------*/
    glLineWidth(3.0);
    glColor3f(0.0,0.0,0.0);
    //chasis
    glBegin(GL_LINE_STRIP);
    glVertex2f(-8.5 + pos_x,-6.5);
    glVertex2f(-8.5 + pos_x,-5.5);
    glVertex2f(-7.5 + pos_x,-5.5);
    glVertex2f(-7 + pos_x,-5);
    glVertex2f(-5.5 + pos_x,-5);
    glVertex2f(-4.5 + pos_x,-5.5);
    glVertex2f(-3.5 + pos_x,-5.5);
    glVertex2f(-4.4 + pos_x,-6.5);
    glVertex2f(-8.5 + pos_x,-6.5);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-4.15 + pos_x,-6.2);
    glVertex2f(-8.5 + pos_x,-6.2);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-6.25 + pos_x,-5);
    glVertex2f(-6.25 + pos_x,-4.5);
    glVertex2f(-6.55 + pos_x,-4.5);
    glVertex2f(-6.55 + pos_x,-5);
    glEnd();
    glPointSize(8.0);
    glBegin(GL_POINTS);
    glVertex2f(-4.65 + pos_x,-5.9);
    glVertex2f(-4.9 + pos_x,-5.7);
    glVertex2f(-5.15 + pos_x,-5.9);
    glVertex2f(-5.4 + pos_x,-5.7);
    glVertex2f(-5.65 + pos_x,-5.9);
    glVertex2f(-5.4 + pos_x,-5.7);
    glVertex2f(-5.65 + pos_x,-5.9);
    glVertex2f(-5.9 + pos_x,-5.7);
    glVertex2f(-6.15 + pos_x,-5.9);
    glVertex2f(-6.4 + pos_x,-5.7);
    glVertex2f(-6.65 + pos_x,-5.9);
    glVertex2f(-6.9 + pos_x,-5.7);
    glVertex2f(-7.15 + pos_x,-5.9);
    glVertex2f(-7.4 + pos_x,-5.7);
    glEnd();
    //ventana
    glBegin(GL_LINE_STRIP);
    glVertex2f(-7.15 + pos_x,-5.55);
    glVertex2f(-6.8 + pos_x,-5.2);
    glVertex2f(-5.6 + pos_x,-5.2);
    glVertex2f(-5 + pos_x,-5.55);
    glVertex2f(-7.15 + pos_x,-5.55);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-6.15 + pos_x,-5.55);
    glVertex2f(-6.15 + pos_x,-5.2);
    glEnd();
    //reflejos
    glLineWidth(2.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-5.65 + pos_x,-5.3);
    glVertex2f(-5.8 + pos_x,-5.45);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-5.55 + pos_x,-5.33);
    glVertex2f(-5.65 + pos_x,-5.45);
    glEnd();
    //rines izquierda
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_QUADS);
    glVertex2f(-7.675 + pos_x,-6.7);
    glVertex2f(-7.675 + pos_x,-6.3);
    glVertex2f(-7.275 + pos_x,-6.3);
    glVertex2f(-7.275 + pos_x,-6.7);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-7.775 + pos_x,-6.6);
    glVertex2f(-7.775 + pos_x,-6.4);
    glVertex2f(-7.175 + pos_x,-6.4);
    glVertex2f(-7.175 + pos_x,-6.6);
    glEnd();
    //rines derecha
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_QUADS);
    glVertex2f(-5.625 + pos_x,-6.7);
    glVertex2f(-5.625 + pos_x,-6.3);
    glVertex2f(-5.225 + pos_x,-6.3);
    glVertex2f(-5.225 + pos_x,-6.7);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-5.725 + pos_x,-6.6);
    glVertex2f(-5.725 + pos_x,-6.4);
    glVertex2f(-5.125 + pos_x,-6.4);
    glVertex2f(-5.125 + pos_x,-6.6);
    glEnd();

    glFlush();
}

void dibujoAutoD(){
/* ----------- RELLENO -----------*/
    //chasis
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-7.4 + pos_x,-6.5);
    glVertex2f(-8.5 + pos_x,-5.5);
    glVertex2f(-7.5 + pos_x,-5.5);
    glVertex2f(-6.5 + pos_x,-5);
    glVertex2f(-5 + pos_x,-5);
    glVertex2f(-4.5 + pos_x,-5.5);
    glVertex2f(-3.5 + pos_x,-5.5);
    glVertex2f(-3.5 + pos_x,-6.5);
    glVertex2f(-8.5 + pos_x,-6.5);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-5.7 + pos_x,-5);
    glVertex2f(-5.7 + pos_x,-4.5);
    glVertex2f(-5.45 + pos_x,-4.5);
    glVertex2f(-5.45 + pos_x,-5);
    glEnd();
    //ventana
    glColor3f(0.73, 0.85, 0.92);
    glBegin(GL_POLYGON);
    glVertex2f(-4.85 + pos_x,-5.55);
    glVertex2f(-5.2 + pos_x,-5.2);
    glVertex2f(-6.4 + pos_x,-5.2);
    glVertex2f(-7 + pos_x,-5.55);
    glVertex2f(-4.85 + pos_x,-5.55);
    glEnd();
    //ruedas
    glColor3f(0.0,0.0,0.0);
    //derecha
    glBegin(GL_POLYGON);
    for (double i = 0.0; i < 6; i += 0.001) {
        calx = (radio2)*cos(i);
        caly = (radio2)*sin(i);
        glVertex2f(calx - 4.525 + pos_x, caly - 6.5);
    }
    glEnd();
    //izquierda
    glBegin(GL_POLYGON);
    for (double i = 0.0; i < 6; i += 0.001) {
        calx = (radio2)*cos(i);
        caly = (radio2)*sin(i);
        glVertex2f(calx - 6.375 + pos_x, caly - 6.5);
    }
    glEnd();

/* ----------- CONTORNO -----------*/
    glLineWidth(3.0);
    glColor3f(0.0,0.0,0.0);
    //chasis
    glBegin(GL_LINE_STRIP);
    glVertex2f(-7.4 + pos_x,-6.5);
    glVertex2f(-8.5 + pos_x,-5.5);
    glVertex2f(-7.5 + pos_x,-5.5);
    glVertex2f(-6.5 + pos_x,-5);
    glVertex2f(-5 + pos_x,-5);
    glVertex2f(-4.5 + pos_x,-5.5);
    glVertex2f(-3.5 + pos_x,-5.5);
    glVertex2f(-3.5 + pos_x,-6.5);
    glVertex2f(-7.4 + pos_x,-6.5);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-3.5 + pos_x,-6.2);
    glVertex2f(-7.7 + pos_x,-6.2);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-5.7 + pos_x,-5);
    glVertex2f(-5.7 + pos_x,-4.5);
    glVertex2f(-5.45 + pos_x,-4.5);
    glVertex2f(-5.45 + pos_x,-5);
    glEnd();
    glPointSize(8.0);
    glBegin(GL_POINTS);
    glVertex2f(-4.65 + pos_x,-5.7);
    glVertex2f(-4.9 + pos_x,-5.9);
    glVertex2f(-5.15 + pos_x,-5.7);
    glVertex2f(-5.4 + pos_x,-5.9);
    glVertex2f(-5.65 + pos_x,-5.7);
    glVertex2f(-5.9 + pos_x,-5.9);
    glVertex2f(-6.15 + pos_x,-5.7);
    glVertex2f(-6.4 + pos_x,-5.9);
    glVertex2f(-6.65 + pos_x,-5.7);
    glVertex2f(-6.9 + pos_x,-5.9);
    glVertex2f(-7.15 + pos_x,-5.7);
    glVertex2f(-7.4 + pos_x,-5.9);
    glEnd();
    //ventana
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-4.85 + pos_x,-5.55);
    glVertex2f(-5.2 + pos_x,-5.2);
    glVertex2f(-6.4 + pos_x,-5.2);
    glVertex2f(-7 + pos_x,-5.55);
    glVertex2f(-4.85 + pos_x,-5.55);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-5.8 + pos_x,-5.55);
    glVertex2f(-5.8 + pos_x,-5.2);
    glEnd();
    //reflejos
    glLineWidth(2.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-6.23 + pos_x,-5.3);
    glVertex2f(-6.35 + pos_x,-5.45);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-6.35 + pos_x,-5.3);
    glVertex2f(-6.5 + pos_x,-5.45);
    glEnd();
    //rines izquierda
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_QUADS);
    glVertex2f(-6.575 + pos_x,-6.7);
    glVertex2f(-6.575 + pos_x,-6.3);
    glVertex2f(-6.175 + pos_x,-6.3);
    glVertex2f(-6.175 + pos_x,-6.7);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-6.675 + pos_x,-6.6);
    glVertex2f(-6.675 + pos_x,-6.4);
    glVertex2f(-6.075 + pos_x,-6.4);
    glVertex2f(-6.075 + pos_x,-6.6);
    glEnd();
    //rines derecha
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_QUADS);
    glVertex2f(-4.725 + pos_x,-6.7);
    glVertex2f(-4.725 + pos_x,-6.3);
    glVertex2f(-4.325 + pos_x,-6.3);
    glVertex2f(-4.325 + pos_x,-6.7);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-4.825 + pos_x,-6.6);
    glVertex2f(-4.825 + pos_x,-6.4);
    glVertex2f(-4.225 + pos_x,-6.4);
    glVertex2f(-4.225 + pos_x,-6.6);
    glEnd();

    glFlush();
}

void avion() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLineWidth(2.0);
    glEnable(GL_LINE_SMOOTH);

    /* ------------- RELLENO DE FONDO ------------- */
    // cuerpo
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-2, 0);
    glVertex2f(-2.6, -0.4);
    glVertex2f(-2.6, -0.7);
    glVertex2f(-2.4, -0.8);
    glVertex2f(-2, -0.8);
    glVertex2f(-1, -0.4);
    glVertex2f(0.1, 0.5);
    glVertex2f(-0.9, 0.525);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.5);
    glVertex2f(-0.9, 0.525);
    glVertex2f(-0.6, 0.6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.5);
    glVertex2f(0.2, 1);
    glVertex2f(0.2, 1.4);
    glVertex2f(-0.2, 1.4);
    glVertex2f(-0.6, 0.6);
    glEnd();
    //asiento
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(-1.25, 0.1);
    glVertex2f(-1, 0.2);
    glVertex2f(-0.8, 0.4);
    glVertex2f(-0.9, 0.525);
    glVertex2f(-1.4, 0.4);
    glEnd();
    //ventana
    glColor3f(0.73, 0.85, 0.92);
    glBegin(GL_POLYGON);
    glVertex2f(-2, 0);
    glVertex2f(-2, 0.4);
    glVertex2f(-1.8, 0.5);
    glVertex2f(-1.4, 0.4);
    glVertex2f(-1.2, 0.2);
    glVertex2f(-1.4, -0.2);
    glVertex2f(-2, 0);
    glEnd();
    /* ------------- CONTORNO DE FONDO ------------- */
    glColor3f(0.0, 0.0, 0.0);
    // cuerpo
    glBegin(GL_LINE_STRIP);
    glVertex2f(-2, 0);
    glVertex2f(-2.6, -0.4);
    glVertex2f(-2.6, -0.7);
    glVertex2f(-2.4, -0.8);
    glVertex2f(-2, -0.8);
    glVertex2f(-1, -0.4);
    glVertex2f(0.1, 0.5);
    glVertex2f(0.2, 1);
    glVertex2f(0.2, 1.4);
    glVertex2f(-0.2, 1.4);
    glVertex2f(-0.6, 0.6);
    glVertex2f(-1.4, 0.4);
    glEnd();

    /* ------------- RELLENO ------------- */
    glColor3f(0.5, 0.5, 0.5);
    //aleta
    glBegin(GL_POLYGON);
    glVertex2f(0, 0.3);
    glVertex2f(0.6, 0.2);
    glVertex2f(0.9, 0.4);
    glVertex2f(-0.2, 0.7);
    glVertex2f(-0.3, 0.4);
    glVertex2f(0, 0.3);
    glEnd();
    //ala
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, 0);
    glVertex2f(-1.3, -0.5);
    glVertex2f(0, -0.7);
    glVertex2f(0.3, -0.5);
    glVertex2f(-0.7, 0);
    glEnd();

    /* ------------- CONTORNO ------------- */
    glColor3f(0.0, 0.0, 0.0);
    //ventana
    glBegin(GL_LINE_STRIP);
    glVertex2f(-2, 0);
    glVertex2f(-2, 0.4);
    glVertex2f(-1.8, 0.5);
    glVertex2f(-1.4, 0.4);
    glVertex2f(-1.2, 0.2);
    glVertex2f(-1.4, -0.2);
    glVertex2f(-2, 0);
    glEnd();
    //aleta

    glBegin(GL_LINE_STRIP);
    glVertex2f(0, 0.3);
    glVertex2f(0.6, 0.2);
    glVertex2f(0.9, 0.4);
    glVertex2f(-0.2, 0.7);
    glVertex2f(-0.3, 0.4);
    glVertex2f(0, 0.3);
    glEnd();
    //ala

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.7, 0);
    glVertex2f(-1.3, -0.5);
    glVertex2f(0, -0.7);
    glVertex2f(0.3, -0.5);
    glVertex2f(-0.7, 0);
    glEnd();
    //asiento

    glBegin(GL_LINE_STRIP);
    glVertex2f(-1.25, 0.1);
    glVertex2f(-1, 0.2);
    glVertex2f(-0.8, 0.4);
    glVertex2f(-0.9, 0.525);
    glEnd();

/* ------------- Hélice 1 ------------- */
    glColor3f(0.0,0.0,0.0);

    //izquierda
    glBegin(GL_POLYGON);
    glVertex2f(-2.55, -0.7);
    glVertex2f(-2.7, -0.15);
    glVertex2f(-3, 0);
    glVertex2f(-3, -0.3);
    glVertex2f(-2.55, -0.7);
    glEnd();

    //derecha
    glBegin(GL_POLYGON);
    glVertex2f(-2.55, -0.7);
    glVertex2f(-2.35, -1.3);
    glVertex2f(-2.1, -1.4);
    glVertex2f(-2.05, -1.15);
    glVertex2f(-2.55, -0.7);
    glEnd();

/* ------------- Unión de hélices ------------- */
    /* ------------- RELLENO ------------- */
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    for (double i = 0.0; i < 6; i += 0.001) {
        calx = (radio)*cos(i);
        caly = (radio)*sin(i);
        glVertex2f(calx - 2.55, caly - 0.7);
    }
    glEnd();

    /* ------------- CONTORNO ------------- */
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for (double i = 0.0; i < 6; i += 0.001) {
        calx = (radio)*cos(i);
        caly = (radio)*sin(i);
        glVertex2f(calx - 2.55, caly - 0.7);
    }
    glEnd();

    glFlush();
}

void dibujar1(){
    avion();
    paisaje();
    dibujoAutoI();
    sol();
}

void dibujar2(){
    avion();
    paisaje();
    dibujoAutoD();
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
            glutDisplayFunc(dibujar1);
            break;

        case GLUT_KEY_DOWN:
            glutDisplayFunc(dibujar2);
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

    glutDisplayFunc(dibujar1);

    glutKeyboardFunc(tecladoSalir);
    glutSpecialFunc(tecladoMover);

    glutMainLoop();

    return EXIT_SUCCESS;
}