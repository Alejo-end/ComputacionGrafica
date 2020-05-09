#include <GL/glut.h>
#include <cmath>

#if defined(LINUX) || defined(WIN32)
using namespace std;
#endif

float radio = 0.1, calx = 0, caly = 0;

void proyeccion(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-4.5, 2, -3, 3);
}

void avion(){
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(2.0);
    glEnable(GL_LINE_SMOOTH);

/* ------------- RELLENO DE FONDO ------------- */
    // cuerpo
    glColor3f(0.5,0.5,0.5);
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
        glVertex2f(-0.6,0.6);
    glEnd();    
    //asiento
    glColor3f(0.3,0.3,0.3);
    glBegin(GL_POLYGON);
        glVertex2f(-1.25, 0.1);
        glVertex2f(-1, 0.2);
        glVertex2f(-0.8, 0.4);
        glVertex2f(-0.9, 0.525);
        glVertex2f(-1.4, 0.4);
    glEnd();  
    //ventana
    glColor3f(0.73,0.85,0.92);
    glBegin(GL_POLYGON);
        glVertex2f(-2, 0);
        glVertex2f(-2, 0.4);
        glVertex2f(-1.8, 0.5);
        glVertex2f(-1.4, 0.4);
        glVertex2f(-1.2, 0.2);
        glVertex2f(-1.4,-0.2);
        glVertex2f(-2, 0);
    glEnd();
/* ------------- CONTORNO DE FONDO ------------- */
    glColor3f(0.0,0.0,0.0);
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
        glVertex2f(-0.6,0.6);
        glVertex2f(-1.4, 0.4);
    glEnd();

/* ------------- RELLENO ------------- */
    glColor3f(0.5,0.5,0.5);
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
    glColor3f(0.0,0.0,0.0);
    //ventana
    glBegin(GL_LINE_STRIP);
        glVertex2f(-2, 0);
        glVertex2f(-2, 0.4);
        glVertex2f(-1.8, 0.5);
        glVertex2f(-1.4, 0.4);
        glVertex2f(-1.2, 0.2);
        glVertex2f(-1.4,-0.2);
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

void helice1(){
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
        
    glFlush();
}

void helice2(){
    glColor3f(0.0,0.0,0.0);

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

void helice3(){
    glColor3f(0.0,0.0,0.0);
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

void unionHelices(){
    /* ------------- RELLENO ------------- */
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
        for (double i=0.0; i<6; i+=0.001){
            calx=(radio)*cos(i);
            caly=(radio)*sin(i);
            glVertex2f(calx-2.55,caly-0.7);
        }
    glEnd();   
    /* ------------- CONTORNO ------------- */
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
        for (double i=0.0; i<6; i+=0.001){
            calx=(radio)*cos(i);
            caly=(radio)*sin(i);
            glVertex2f(calx-2.55,caly-0.7);
        }
    glEnd();

    glFlush();
}

void tecladoSalir(unsigned char key, int x, int y){
    switch(key){
        case 'q':
                exit(0);
            break;
    }
}

void tecladoMover(int tecla, int x, int y){
    switch (tecla){
        case GLUT_KEY_UP:
                avion();
                helice1();
                unionHelices();
            break;
        
        case GLUT_KEY_DOWN:
                avion();
                helice4();
                unionHelices();
            break;

        case GLUT_KEY_LEFT:
                avion();
                helice2();
                unionHelices();
            break;

        case GLUT_KEY_RIGHT:
                avion();
                helice3();
                unionHelices();
            break;    
    }

    glutPostRedisplay();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(50,100);
    glutCreateWindow("Avion en OpenGL");

    proyeccion();
    //dibujar();
    //iniciar();
    avion();
    //helice1();
    helice2();
    //helice3();
    //helice4();
    unionHelices();

    glutKeyboardFunc(tecladoSalir);
    glutSpecialFunc(tecladoMover);


    glutMainLoop();

    return EXIT_SUCCESS;
}