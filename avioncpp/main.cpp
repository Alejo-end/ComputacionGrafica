#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <windows.h>

using namespace std;

float radio = 0.1, calx = 0, caly = 0;

void proyeccion() {
    GLfloat luz_ambiente[] = { 0.1,1.0,1.0,0.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luz_ambiente);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-4.5, 2, -3, 3);
}

void avion() {
    GLfloat color_difuso_y_ambiente[] = { 0.5,0.4,0.1,1.0 };
    GLfloat color_especular_ninguno[] = { 0.560784, 0.560784, 0.737255,0.0 };
    GLfloat color_especular_blanco[] = { 2.0,2.0,2.0,2.0 };
    GLfloat brillo_especular_suave[] = { 1.0 };
    GLfloat brillo_especular_fuerte[] = { 8.0 };
    GLfloat luz_posicion[] = { -3, -1, 0, -1};

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(-0.7, 0.0, 0.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_difuso_y_ambiente);
    glMaterialfv(GL_FRONT, GL_SPECULAR, color_especular_blanco);
    glMaterialfv(GL_FRONT, GL_SHININESS, brillo_especular_suave);
    glLightfv(GL_LIGHT0, GL_POSITION, luz_posicion);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_difuso_y_ambiente);
    glMaterialfv(GL_FRONT, GL_SPECULAR, color_especular_blanco);
    glMaterialfv(GL_FRONT, GL_SHININESS, brillo_especular_suave);
    glLightfv(GL_LIGHT0, GL_POSITION, luz_posicion);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7, 0.0, 0.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_difuso_y_ambiente);
    glMaterialfv(GL_FRONT, GL_SPECULAR, color_especular_blanco);
    glMaterialfv(GL_FRONT, GL_SHININESS, brillo_especular_fuerte);
    glLightfv(GL_LIGHT0, GL_POSITION, luz_posicion);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-12.0, -3, -2.8);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_difuso_y_ambiente);
    glMaterialfv(GL_FRONT, GL_SPECULAR, color_especular_blanco);
    glMaterialfv(GL_FRONT, GL_SHININESS, brillo_especular_suave);
    glLightfv(GL_LIGHT0, GL_POSITION, luz_posicion);
    glutSolidSphere(0.3, 90, 90);
    glPopMatrix(); 

    glLineWidth(2.0);
    glEnable(GL_LINE_SMOOTH);

    /* ------------- RELLENO DE FONDO ------------- */
        // cuerpo
    /*glColor3f(0.5, 0.5, 0.5);*/
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
   /* glColor3f(0.3, 0.3, 0.3);*/
    glBegin(GL_POLYGON);
    glVertex2f(-1.25, 0.1);
    glVertex2f(-1, 0.2);
    glVertex2f(-0.8, 0.4);
    glVertex2f(-0.9, 0.525);
    glVertex2f(-1.4, 0.4);
    glEnd();
    //ventana
    /*glColor3f(0.73, 0.85, 0.92);*/
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
   /* glColor3f(0.0, 0.0, 0.0);*/
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
  /*  glColor3f(0.5, 0.5, 0.5);*/
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
   /* glColor3f(0.0, 0.0, 0.0);*/
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

    glFlush();
}

void unionHelices() {
    GLfloat color_difuso_y_ambiente[] = { 0.5,0.4,0.1,1.0 };
    GLfloat color_especular_blanco[] = { 2.0,2.0,2.0,2.0 };
    GLfloat brillo_especular_suave[] = { 1.0 };
    GLfloat luz_posicion[] = { -3, -1, 0, -1};

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_difuso_y_ambiente);
    glMaterialfv(GL_FRONT, GL_SPECULAR, color_especular_blanco);
    glMaterialfv(GL_FRONT, GL_SHININESS, brillo_especular_suave);
    glLightfv(GL_LIGHT0, GL_POSITION, luz_posicion);

    /* ------------- RELLENO ------------- */
   /* glColor3f(0.5, 0.5, 0.5);*/
    glBegin(GL_POLYGON);
    for (double i = 0.0; i < 6; i += 0.001) {
        calx = (radio)*cos(i);
        caly = (radio)*sin(i);
        glVertex2f(calx - 2.55, caly - 0.7);
    }
    glEnd();
    /* ------------- CONTORNO ------------- */
   /* glColor3f(0.0, 0.0, 0.0);*/
    glBegin(GL_LINE_STRIP);
    for (double i = 0.0; i < 6; i += 0.001) {
        calx = (radio)*cos(i);
        caly = (radio)*sin(i);
        glVertex2f(calx - 2.55, caly - 0.7);
    }
    glEnd();

    glFlush();
}

void helice1() {
    glColor3f(0.0,0.0,0.0);

    GLfloat color_difuso_y_ambiente[]={0.5,0.5,0.4,0.0};
    GLfloat color_especular_blanco[]={2.0,2.0,2.0,2.0};
    GLfloat brillo_especular_suave[]={5.0};
    GLfloat luz_posicion[]={0.0,0.3,-0.8,1.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_difuso_y_ambiente);
    glMaterialfv(GL_FRONT,GL_SPECULAR,color_especular_blanco);
    glMaterialfv(GL_FRONT,GL_SHININESS,brillo_especular_suave);
    glLightfv(GL_LIGHT0,GL_POSITION,luz_posicion);

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

    glFlush();
}

void helice2() {
    glColor3f(0.0,0.0,0.0);

    GLfloat color_difuso_y_ambiente[]={0.5,0.5,0.4,0.0};
    GLfloat color_especular_blanco[]={2.0,2.0,2.0,2.0};
    GLfloat brillo_especular_suave[]={5.0};
    GLfloat luz_posicion[]={0.0,0.3,-0.8,1.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_difuso_y_ambiente);
    glMaterialfv(GL_FRONT,GL_SPECULAR,color_especular_blanco);
    glMaterialfv(GL_FRONT,GL_SHININESS,brillo_especular_suave);
    glLightfv(GL_LIGHT0,GL_POSITION,luz_posicion);

    //izquierda
    glBegin(GL_POLYGON);
    glVertex2f(-2.55, -0.7);
    glVertex2f(-3.1, -0.55);
    glVertex2f(-3.3, -0.7);
    glVertex2f(-3.1, -0.85);
    glVertex2f(-2.55, -0.7);
    glEnd();

    //derecha
    glBegin(GL_POLYGON);
    glVertex2f(-2.55, -0.7);
    glVertex2f(-2, -0.85);
    glVertex2f(-1.8, -0.7);
    glVertex2f(-2, -0.55);
    glVertex2f(-2.55, -0.7);
    glEnd();

    glFlush();
}

void helice3() {
    glColor3f(0.0,0.0,0.0);
    
    GLfloat color_difuso_y_ambiente[]={0.5,0.5,0.4,0.0};
    GLfloat color_especular_blanco[]={2.0,2.0,2.0,2.0};
    GLfloat brillo_especular_suave[]={5.0};
    GLfloat luz_posicion[]={0.0,0.3,-0.8,1.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_difuso_y_ambiente);
    glMaterialfv(GL_FRONT,GL_SPECULAR,color_especular_blanco);
    glMaterialfv(GL_FRONT,GL_SHININESS,brillo_especular_suave);
    glLightfv(GL_LIGHT0,GL_POSITION,luz_posicion);

    //arriba
    glBegin(GL_POLYGON);
    glVertex2f(-2.55, -0.7);
    glVertex2f(-2.7, -0.2);
    glVertex2f(-2.55, 0);
    glVertex2f(-2.4, -0.2);
    glVertex2f(-2.55, -0.7);
    glEnd();

    //abajo
    glBegin(GL_POLYGON);
    glVertex2f(-2.55, -0.7);
    glVertex2f(-2.7, -1.2);
    glVertex2f(-2.55, -1.4);
    glVertex2f(-2.4, -1.2);
    glVertex2f(-2.55, -0.7);
    glEnd();

    glFlush();
}

void helice4(){
    glColor3f(0.0,0.0,0.0);
    
    GLfloat color_difuso_y_ambiente[]={0.5,0.5,0.4,0.0};
    GLfloat color_especular_blanco[]={2.0,2.0,2.0,2.0};
    GLfloat brillo_especular_suave[]={5.0};
    GLfloat luz_posicion[]={0.0,0.3,-0.8,1.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_difuso_y_ambiente);
    glMaterialfv(GL_FRONT,GL_SPECULAR,color_especular_blanco);
    glMaterialfv(GL_FRONT,GL_SHININESS,brillo_especular_suave);
    glLightfv(GL_LIGHT0,GL_POSITION,luz_posicion);

    //derecha
    glBegin(GL_POLYGON);
        glVertex2f(-2.55, -0.7);
        glVertex2f(-2.25, -0.15);
        glVertex2f(-1.9, 0);
        glVertex2f(-2, -0.3);
        glVertex2f(-2.55, -0.7);
    glEnd();
    //izquierda
    glBegin(GL_POLYGON);
        glVertex2f(-2.55, -0.7);
        glVertex2f(-2.75, -1.2);
        glVertex2f(-3.1, -1.4);
        glVertex2f(-3.05, -1.1);
        glVertex2f(-2.55, -0.7);
    glEnd();

    glFlush();
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
            avion();
            helice1();
        break;

    case GLUT_KEY_DOWN:
            avion();
            helice4();
        break;

    case GLUT_KEY_RIGHT:
            avion();
            helice3();
        break;

    case GLUT_KEY_LEFT:
            avion();
            helice2();
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    cerr << "Presionar las teclas especiales de movimiento: ARRIBA, DERECHA, ABAJO, IZQUIERDA, en ese orden" << endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 100);
    glutCreateWindow("Avion en OpenGL");

    proyeccion();

    glutDisplayFunc(unionHelices);

    avion();
    helice2();

    glutKeyboardFunc(tecladoSalir);
    glutSpecialFunc(tecladoMover);


    glutMainLoop();

    return EXIT_SUCCESS;
}