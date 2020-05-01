#include <GL/glut.h>
#include <math.h>

#if defined(LINUX) || defined(WIN32)
using namespace std;
#endif
//nombre del grupo
void nombre();
//mario bros:
void mario();
void luigi();
void cuerpo(float r, float g, float b);
//paisaje
void montana();
void edificio();
void drawClouds();
void estrellas();
void arbol();

//menu
static int window;
static int menu_id;
static int submenu_id;
static int value = 0;

//teclado
float pos_x = 0;

//paisaje
float px=2, py=5, radio=25, calx, caly;

void proyeccion(){
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-40,40,-40,40);
}

void menu(int num){

    if (num == 0){
        exit(0);
    }

    else{
        value = num;
    }

    glutPostRedisplay();
}

void createMenu(void){
    //figuras que dibujaremos
    //se escriben primero estas entradas para dárselas como parámetros al menu de dibujar más abajo
    submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Nombre del grupo", 2);
    glutAddMenuEntry("Mario", 3);
    glutAddMenuEntry("Luigi", 4);
    glutAddMenuEntry("Paisaje", 5);

    //elementos que aparecen al hacer click derecho
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Limpiar pantalla", 1);
    glutAddSubMenu("Dibujar", submenu_id);
    glutAddMenuEntry("Salir", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void dibujar(){
    glClear(GL_COLOR_BUFFER_BIT);

    if(value == 1){
        glClear(GL_COLOR_BUFFER_BIT);
    }

    else if(value == 2){
        nombre();
    }

    else if(value == 3){
        mario();
    }

    else if(value == 4){
        luigi();
    }

    else if(value == 5){
        montana(0,0,0,0,0,0);

        //estrellas
        montana(0,0,-35,35,0,0);
        montana(0,0,-35,25,0,0);
        montana(0,0,-35,15,0,0);
        montana(0,0,-35,5,0,0);
        montana(0,0,-25,30,0,0);
        montana(0,0,-25,20,0,0);
        montana(0,0,-25,10,0,0);
        montana(0,0,-25,0,0,0);
        montana(0,0,-15,35,0,0);
        montana(0,0,-15,25,0,0);
        montana(0,0,-15,15,0,0);
        montana(0,0,-15,5,0,0);
        montana(0,0,-5,30,0,0);
        montana(0,0,-5,20,0,0);
        montana(0,0,-5,10,0,0);
        montana(0,0,-5,0,0,0);
        montana(0,0,5,35,0,0);
        montana(0,0,5,25,0,0);
        montana(0,0,5,5,0,0);
        montana(0,0,15,30,0,0);
        montana(0,0,15,20,0,0);
        montana(0,0,15,10,0,0);
        montana(0,0,15,0),0,0;
        montana(0,0,25,35,0,0);
        montana(0,0,25,25,0,0);
        montana(0,0,25,15,0,0);
        montana(0,0,25,5,0,0);
        montana(0,0,35,30,0,0);
        montana(0,0,35,20,0,0);
        montana(0,0,35,10,0,0);
        montana(0,0,35,0,0,0);
        //nubes
        montana(0,20,0,0,0,0);
        montana(-4,20,0,0,0,0);
        montana(-8,20,0,0,0,0);
        montana(4,20,0,0,0,0);
        montana(8,20,0,0,0,0);
        montana(6,18,0,0,0,0);
        montana(10,18,0,0,0,0);
        montana(2,18,0,0,0,0);
        montana(-2,18,0,0,0,0);
        montana(-6,18,0,0,0,0);
        montana(-10,18,0,0,0,0);
        //arboles
        montana(0,0,0,0,-34,-8);
        montana(0,0,0,0,-30,-15);
        montana(0,0,0,0,-28,-22);
        montana(0,0,0,0,-36,-28);
        montana(0,0,0,0,-25,-35);
        montana(0,0,0,0,-25,-3);
        montana(0,0,0,0,-15,-23);
        montana(0,0,0,0,-220,-33);
        montana(0,0,0,0,-19,-9);
        montana(0,0,0,0,-10,-12);
        montana(0,0,0,0,0,-15);
        montana(0,0,0,0,0,-25);
        montana(0,0,0,0,-5,-35);
        montana(0,0,0,0,15,-35);
        montana(0,0,0,0,10,-25);
        montana(0,0,0,0,10,-25);
        montana(0,0,0,0,13,-15);
        montana(0,0,0,0,28,-14);
        montana(0,0,0,0,25,-25);
        montana(0,0,0,0,30,-35);
        montana(0,0,0,0,35,-25);
    }

    glutPostRedisplay();

    glFlush();
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

void mario(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,0.0);
    glEnable(GL_LINE_SMOOTH);
//rojo
    //gorra
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(-4 + pos_x,6);
    glVertex2i(-4 + pos_x,7);
    glVertex2i(6 + pos_x,7);
    glVertex2i(6 + pos_x,6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,7);
    glVertex2i(-3 + pos_x,8);
    glVertex2i(3 + pos_x,8);
    glVertex2i(3 + pos_x,7);
    glEnd();
//negro
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(-4 + pos_x,6);
    glVertex2i(-1 + pos_x,6);
    glVertex2i(-1 + pos_x,5);
    glVertex2i(-4 + pos_x,5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,5);
    glVertex2i(-2 + pos_x,5);
    glVertex2i(-2 + pos_x,4);
    glVertex2i(-3 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,4);
    glVertex2i(-1 + pos_x,4);
    glVertex2i(-1 + pos_x,3);
    glVertex2i(-3 + pos_x,3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,5);
    glVertex2i(-4 + pos_x,5);
    glVertex2i(-4 + pos_x,3);
    glVertex2i(-5 + pos_x,3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,3);
    glVertex2i(-3 + pos_x,3);
    glVertex2i(-3 + pos_x,2);
    glVertex2i(-5 + pos_x,2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,6);
    glVertex2i(1 + pos_x,6);
    glVertex2i(1 + pos_x,4);
    glVertex2i(2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,3);
    glVertex2i(3 + pos_x,3);
    glVertex2i(3 + pos_x,4);
    glVertex2i(2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(1 + pos_x,3);
    glVertex2i(5 + pos_x,3);
    glVertex2i(5 + pos_x,2);
    glVertex2i(1 + pos_x,2);
    glEnd();
//piel
    glColor3f(0.95,0.76,0.50);
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,5);
    glVertex2i(-4 + pos_x,5);
    glVertex2i(-4 + pos_x,3);
    glVertex2i(-3 + pos_x,3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,5);
    glVertex2i(-1 + pos_x,5);
    glVertex2i(-1 + pos_x,4);
    glVertex2i(-2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,3);
    glVertex2i(1 + pos_x,3);
    glVertex2i(1 + pos_x,4);
    glVertex2i(2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,6);
    glVertex2i(3 + pos_x,6);
    glVertex2i(3 + pos_x,4);
    glVertex2i(2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,5);
    glVertex2i(5 + pos_x,5);
    glVertex2i(5 + pos_x,3);
    glVertex2i(3 + pos_x,3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(6 + pos_x,3);
    glVertex2i(6 + pos_x,4);
    glVertex2i(5 + pos_x,4);
    glVertex2i(5 + pos_x,3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,2);
    glVertex2i(1 + pos_x,2);
    glVertex2i(1 + pos_x,1);
    glVertex2i(3 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,6);
    glVertex2i(1 + pos_x,6);
    glVertex2i(1 + pos_x,1);
    glVertex2i(-1 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,1);
    glVertex2i(-3 + pos_x,1);
    glVertex2i(-3 + pos_x,3);
    glVertex2i(-1 + pos_x,3);
    glEnd();



//camisa
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1 + pos_x,1);
    glVertex2i(-1 + pos_x,1);
    glVertex2i(-1 + pos_x,-1);
    glVertex2i(1 + pos_x,-1);
    glEnd();
//mangas
    //izquierda
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,-3);
    glVertex2i(-3 + pos_x,-2);
    glVertex2i(-4 + pos_x,-2);
    glVertex2i(-4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,1);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-4 + pos_x,-2);
    glVertex2i(-4 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,0);
    glVertex2i(-5 + pos_x,-2);
    glVertex2i(-4 + pos_x,-2);
    glVertex2i(-4 + pos_x,0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,-1);
    glVertex2i(-5 + pos_x,-2);
    glVertex2i(-6 + pos_x,-2);
    glVertex2i(-6 + pos_x,-1);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,-3);
    glVertex2i(3 + pos_x,-2);
    glVertex2i(4 + pos_x,-2);
    glVertex2i(4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,1);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(4 + pos_x,-2);
    glVertex2i(4 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,0);
    glVertex2i(5 + pos_x,-2);
    glVertex2i(4 + pos_x,-2);
    glVertex2i(4 + pos_x,0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,-1);
    glVertex2i(5 + pos_x,-2);
    glVertex2i(6 + pos_x,-2);
    glVertex2i(6 + pos_x,-1);
    glEnd();
//manos
    //izquierda
    glColor3f(0.95,0.76,0.50);
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,-3);
    glVertex2i(-3 + pos_x,-4);
    glVertex2i(-4 + pos_x,-4);
    glVertex2i(-4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-6 + pos_x,-2);
    glVertex2i(-6 + pos_x,-5);
    glVertex2i(-4 + pos_x,-5);
    glVertex2i(-4 + pos_x,-2);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,-3);
    glVertex2i(3 + pos_x,-4);
    glVertex2i(4 + pos_x,-4);
    glVertex2i(4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(6 + pos_x,-2);
    glVertex2i(6 + pos_x,-5);
    glVertex2i(4 + pos_x,-5);
    glVertex2i(4 + pos_x,-2);
    glEnd();
//overol
    //azul
    //izquierda
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,1);
    glVertex2i(-1 + pos_x,1);
    glVertex2i(-1 + pos_x,-2);
    glVertex2i(-2 + pos_x,-2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,-2);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-2 + pos_x,-4);
    glVertex2i(-3 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-3 + pos_x,-2);
    glVertex2i(-3 + pos_x,-3);
    glVertex2i(-2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,-4);
    glVertex2i(-1 + pos_x,-4);
    glVertex2i(-1 + pos_x,-3);
    glVertex2i(-2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,-6);
    glVertex2i(-4 + pos_x,-6);
    glVertex2i(-4 + pos_x,-4);
    glVertex2i(-1 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,-1);
    glVertex2i(1 + pos_x,-1);
    glVertex2i(1 + pos_x,-5);
    glVertex2i(-1 + pos_x,-5);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,1);
    glVertex2i(1 + pos_x,1);
    glVertex2i(1 + pos_x,-2);
    glVertex2i(2 + pos_x,-2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,-2);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(2 + pos_x,-4);
    glVertex2i(3 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(3 + pos_x,-2);
    glVertex2i(3 + pos_x,-3);
    glVertex2i(2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,-4);
    glVertex2i(1 + pos_x,-4);
    glVertex2i(1 + pos_x,-3);
    glVertex2i(2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(1 + pos_x,-6);
    glVertex2i(4 + pos_x,-6);
    glVertex2i(4 + pos_x,-4);
    glVertex2i(1 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,-1);
    glVertex2i(1 + pos_x,-1);
    glVertex2i(1 + pos_x,-5);
    glVertex2i(-1 + pos_x,-5);
    glEnd();
    //amarillo
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-1 + pos_x,-2);
    glVertex2i(-1 + pos_x,-3);
    glVertex2i(-2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(1 + pos_x,-2);
    glVertex2i(1 + pos_x,-3);
    glVertex2i(2 + pos_x,-3);
    glEnd();
//botas
    //izquierda
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,-6);
    glVertex2i(-5 + pos_x,-8);
    glVertex2i(-2 + pos_x,-8);
    glVertex2i(-2 + pos_x,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,-8);
    glVertex2i(-6 + pos_x,-8);
    glVertex2i(-6 + pos_x,-7);
    glVertex2i(-5 + pos_x,-7);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,-6);
    glVertex2i(5 + pos_x,-8);
    glVertex2i(2 + pos_x,-8);
    glVertex2i(2 + pos_x,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,-8);
    glVertex2i(6 + pos_x,-8);
    glVertex2i(6 + pos_x,-7);
    glVertex2i(5 + pos_x,-7);
    glEnd();

    glFlush();
}

void luigi(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,0.0);
    glEnable(GL_LINE_SMOOTH);
//verde
    //gorra
    glColor3f(0.42,0.68,0.07);
    glBegin(GL_POLYGON);
    glVertex2i(-6 + pos_x,6);
    glVertex2i(-6 + pos_x,7);
    glVertex2i(4 + pos_x,7);
    glVertex2i(4 + pos_x,6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,7);
    glVertex2i(-3 + pos_x,8);
    glVertex2i(3 + pos_x,8);
    glVertex2i(3 + pos_x,7);
    glEnd();
//negro
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(4 + pos_x,6);
    glVertex2i(1 + pos_x,6);
    glVertex2i(1 + pos_x,5);
    glVertex2i(4 + pos_x,5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,5);
    glVertex2i(3 + pos_x,5);
    glVertex2i(3 + pos_x,4);
    glVertex2i(2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,4);
    glVertex2i(1 + pos_x,4);
    glVertex2i(1 + pos_x,3);
    glVertex2i(3 + pos_x,3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(4 + pos_x,5);
    glVertex2i(5 + pos_x,5);
    glVertex2i(5 + pos_x,3);
    glVertex2i(4 + pos_x,3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,3);
    glVertex2i(3 + pos_x,3);
    glVertex2i(3 + pos_x,2);
    glVertex2i(5 + pos_x,2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,6);
    glVertex2i(-1 + pos_x,6);
    glVertex2i(-1 + pos_x,4);
    glVertex2i(-2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,3);
    glVertex2i(-3 + pos_x,3);
    glVertex2i(-3 + pos_x,4);
    glVertex2i(-2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,3);
    glVertex2i(-5 + pos_x,3);
    glVertex2i(-5 + pos_x,2);
    glVertex2i(-1 + pos_x,2);
    glEnd();
//piel
    glColor3f(0.95,0.76,0.50);
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,5);
    glVertex2i(4 + pos_x,5);
    glVertex2i(4 + pos_x,3);
    glVertex2i(3 + pos_x,3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,5);
    glVertex2i(1 + pos_x,5);
    glVertex2i(1 + pos_x,4);
    glVertex2i(2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-6 + pos_x,3);
    glVertex2i(-5 + pos_x,3);
    glVertex2i(-5 + pos_x,4);
    glVertex2i(-6 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,6);
    glVertex2i(-3 + pos_x,6);
    glVertex2i(-3 + pos_x,4);
    glVertex2i(-2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,5);
    glVertex2i(-5 + pos_x,5);
    glVertex2i(-5 + pos_x,3);
    glVertex2i(-3 + pos_x,3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,3);
    glVertex2i(-2 + pos_x,3);
    glVertex2i(-2 + pos_x,4);
    glVertex2i(-1 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,2);
    glVertex2i(-1 + pos_x,2);
    glVertex2i(-1 + pos_x,1);
    glVertex2i(-3 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(1 + pos_x,6);
    glVertex2i(-1 + pos_x,6);
    glVertex2i(-1 + pos_x,1);
    glVertex2i(1 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(1 + pos_x,1);
    glVertex2i(3 + pos_x,1);
    glVertex2i(3 + pos_x,3);
    glVertex2i(1 + pos_x,3);
    glEnd();

//camisa
    glColor3f(0.42,0.68,0.07);
    glBegin(GL_POLYGON);
    glVertex2i(1 + pos_x,1);
    glVertex2i(-1 + pos_x,1);
    glVertex2i(-1 + pos_x,-1);
    glVertex2i(1 + pos_x,-1);
    glEnd();
//mangas
    //izquierda
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,-3);
    glVertex2i(-3 + pos_x,-2);
    glVertex2i(-4 + pos_x,-2);
    glVertex2i(-4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,1);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-4 + pos_x,-2);
    glVertex2i(-4 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,0);
    glVertex2i(-5 + pos_x,-2);
    glVertex2i(-4 + pos_x,-2);
    glVertex2i(-4 + pos_x,0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,-1);
    glVertex2i(-5 + pos_x,-2);
    glVertex2i(-6 + pos_x,-2);
    glVertex2i(-6 + pos_x,-1);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,-3);
    glVertex2i(3 + pos_x,-2);
    glVertex2i(4 + pos_x,-2);
    glVertex2i(4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,1);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(4 + pos_x,-2);
    glVertex2i(4 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,0);
    glVertex2i(5 + pos_x,-2);
    glVertex2i(4 + pos_x,-2);
    glVertex2i(4 + pos_x,0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,-1);
    glVertex2i(5 + pos_x,-2);
    glVertex2i(6 + pos_x,-2);
    glVertex2i(6 + pos_x,-1);
    glEnd();
//manos
    //izquierda
    glColor3f(0.95,0.76,0.50);
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,-3);
    glVertex2i(-3 + pos_x,-4);
    glVertex2i(-4 + pos_x,-4);
    glVertex2i(-4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-6 + pos_x,-2);
    glVertex2i(-6 + pos_x,-5);
    glVertex2i(-4 + pos_x,-5);
    glVertex2i(-4 + pos_x,-2);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,-3);
    glVertex2i(3 + pos_x,-4);
    glVertex2i(4 + pos_x,-4);
    glVertex2i(4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(6 + pos_x,-2);
    glVertex2i(6 + pos_x,-5);
    glVertex2i(4 + pos_x,-5);
    glVertex2i(4 + pos_x,-2);
    glEnd();
//overol
    //azul
    //izquierda
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,1);
    glVertex2i(-1 + pos_x,1);
    glVertex2i(-1 + pos_x,-2);
    glVertex2i(-2 + pos_x,-2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,-2);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-2 + pos_x,-4);
    glVertex2i(-3 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-3 + pos_x,-2);
    glVertex2i(-3 + pos_x,-3);
    glVertex2i(-2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,-4);
    glVertex2i(-1 + pos_x,-4);
    glVertex2i(-1 + pos_x,-3);
    glVertex2i(-2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,-6);
    glVertex2i(-4 + pos_x,-6);
    glVertex2i(-4 + pos_x,-4);
    glVertex2i(-1 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,-1);
    glVertex2i(1 + pos_x,-1);
    glVertex2i(1 + pos_x,-5);
    glVertex2i(-1 + pos_x,-5);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,1);
    glVertex2i(1 + pos_x,1);
    glVertex2i(1 + pos_x,-2);
    glVertex2i(2 + pos_x,-2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,-2);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(2 + pos_x,-4);
    glVertex2i(3 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(3 + pos_x,-2);
    glVertex2i(3 + pos_x,-3);
    glVertex2i(2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,-4);
    glVertex2i(1 + pos_x,-4);
    glVertex2i(1 + pos_x,-3);
    glVertex2i(2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(1 + pos_x,-6);
    glVertex2i(4 + pos_x,-6);
    glVertex2i(4 + pos_x,-4);
    glVertex2i(1 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,-1);
    glVertex2i(1 + pos_x,-1);
    glVertex2i(1 + pos_x,-5);
    glVertex2i(-1 + pos_x,-5);
    glEnd();
    //amarillo
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-1 + pos_x,-2);
    glVertex2i(-1 + pos_x,-3);
    glVertex2i(-2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(1 + pos_x,-2);
    glVertex2i(1 + pos_x,-3);
    glVertex2i(2 + pos_x,-3);
    glEnd();
//botas
    //izquierda
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,-6);
    glVertex2i(-5 + pos_x,-8);
    glVertex2i(-2 + pos_x,-8);
    glVertex2i(-2 + pos_x,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,-8);
    glVertex2i(-6 + pos_x,-8);
    glVertex2i(-6 + pos_x,-7);
    glVertex2i(-5 + pos_x,-7);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,-6);
    glVertex2i(5 + pos_x,-8);
    glVertex2i(2 + pos_x,-8);
    glVertex2i(2 + pos_x,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,-8);
    glVertex2i(6 + pos_x,-8);
    glVertex2i(6 + pos_x,-7);
    glVertex2i(5 + pos_x,-7);
    glEnd();

    glFlush();
}

// se glitchea si están separadas
void cuerpo(float r, float g, float b){
    //glClear(GL_COLOR_BUFFER_BIT);
//camisa
    glColor3f(0.42,0.68,0.07);
    glBegin(GL_POLYGON);
    glVertex2i(1 + pos_x,1);
    glVertex2i(-1 + pos_x,1);
    glVertex2i(-1 + pos_x,-1);
    glVertex2i(1 + pos_x,-1);
    glEnd();
//mangas
    //izquierda
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,-3);
    glVertex2i(-3 + pos_x,-2);
    glVertex2i(-4 + pos_x,-2);
    glVertex2i(-4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,1);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-4 + pos_x,-2);
    glVertex2i(-4 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,0);
    glVertex2i(-5 + pos_x,-2);
    glVertex2i(-4 + pos_x,-2);
    glVertex2i(-4 + pos_x,0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,-1);
    glVertex2i(-5 + pos_x,-2);
    glVertex2i(-6 + pos_x,-2);
    glVertex2i(-6 + pos_x,-1);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,-3);
    glVertex2i(3 + pos_x,-2);
    glVertex2i(4 + pos_x,-2);
    glVertex2i(4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,1);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(4 + pos_x,-2);
    glVertex2i(4 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,0);
    glVertex2i(5 + pos_x,-2);
    glVertex2i(4 + pos_x,-2);
    glVertex2i(4 + pos_x,0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,-1);
    glVertex2i(5 + pos_x,-2);
    glVertex2i(6 + pos_x,-2);
    glVertex2i(6 + pos_x,-1);
    glEnd();
//manos
    //izquierda
    glColor3f(0.95,0.76,0.50);
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,-3);
    glVertex2i(-3 + pos_x,-4);
    glVertex2i(-4 + pos_x,-4);
    glVertex2i(-4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-6 + pos_x,-2);
    glVertex2i(-6 + pos_x,-5);
    glVertex2i(-4 + pos_x,-5);
    glVertex2i(-4 + pos_x,-2);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,-3);
    glVertex2i(3 + pos_x,-4);
    glVertex2i(4 + pos_x,-4);
    glVertex2i(4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(6 + pos_x,-2);
    glVertex2i(6 + pos_x,-5);
    glVertex2i(4 + pos_x,-5);
    glVertex2i(4 + pos_x,-2);
    glEnd();
//overol
    //azul
    //izquierda
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,1);
    glVertex2i(-1 + pos_x,1);
    glVertex2i(-1 + pos_x,-2);
    glVertex2i(-2 + pos_x,-2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,-2);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-2 + pos_x,-4);
    glVertex2i(-3 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-3 + pos_x,-2);
    glVertex2i(-3 + pos_x,-3);
    glVertex2i(-2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,-4);
    glVertex2i(-1 + pos_x,-4);
    glVertex2i(-1 + pos_x,-3);
    glVertex2i(-2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,-6);
    glVertex2i(-4 + pos_x,-6);
    glVertex2i(-4 + pos_x,-4);
    glVertex2i(-1 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,-1);
    glVertex2i(1 + pos_x,-1);
    glVertex2i(1 + pos_x,-5);
    glVertex2i(-1 + pos_x,-5);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,1);
    glVertex2i(1 + pos_x,1);
    glVertex2i(1 + pos_x,-2);
    glVertex2i(2 + pos_x,-2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,-2);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(2 + pos_x,-4);
    glVertex2i(3 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(3 + pos_x,-2);
    glVertex2i(3 + pos_x,-3);
    glVertex2i(2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,-4);
    glVertex2i(1 + pos_x,-4);
    glVertex2i(1 + pos_x,-3);
    glVertex2i(2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(1 + pos_x,-6);
    glVertex2i(4 + pos_x,-6);
    glVertex2i(4 + pos_x,-4);
    glVertex2i(1 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,-1);
    glVertex2i(1 + pos_x,-1);
    glVertex2i(1 + pos_x,-5);
    glVertex2i(-1 + pos_x,-5);
    glEnd();
    //amarillo
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-1 + pos_x,-2);
    glVertex2i(-1 + pos_x,-3);
    glVertex2i(-2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(1 + pos_x,-2);
    glVertex2i(1 + pos_x,-3);
    glVertex2i(2 + pos_x,-3);
    glEnd();
//botas
    //izquierda
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,-6);
    glVertex2i(-5 + pos_x,-8);
    glVertex2i(-2 + pos_x,-8);
    glVertex2i(-2 + pos_x,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,-8);
    glVertex2i(-6 + pos_x,-8);
    glVertex2i(-6 + pos_x,-7);
    glVertex2i(-5 + pos_x,-7);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,-6);
    glVertex2i(5 + pos_x,-8);
    glVertex2i(2 + pos_x,-8);
    glVertex2i(2 + pos_x,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,-8);
    glVertex2i(6 + pos_x,-8);
    glVertex2i(6 + pos_x,-7);
    glVertex2i(5 + pos_x,-7);
    glEnd();

    glFlush();
}

void montana(double x1, double y1, double x2,double y2,double x3, double y3){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f( 0.137255, 0.556863,0.137255);
    glPointSize(1.0);
    glBegin(GL_POLYGON);
    for (double i=0.0; i<10; i+=0.001)
    {
        calx=(radio+10)*cos(i);
        caly=(radio+10)*sin(i-500);
        glVertex2f(calx-40,caly-40);
    }
    glEnd();
//
    glPointSize(1.0);
    glBegin(GL_POLYGON);
    for (double i=0.0; i<10; i+=0.001)
    {
        calx=radio*cos(i);
        caly=radio*sin(i+50);
        glVertex2f(calx+40,caly-40);
    }
    glEnd();
//
    glPointSize(1.0);
    glBegin(GL_POLYGON);
    for (double i=0.0; i<10; i+=0.001)
    {
        calx=radio*cos(i);
        caly=radio*sin(i+50);
        glVertex2f(calx+10,caly-30);
    }
    glEnd();
//luna
    glColor3f(0.85,0.85,0.85);
    glPointSize(1.0);
    glBegin(GL_POLYGON);
    for (double i=0.0; i<3; i+=0.001)
    {
        calx=(radio-18)*cos(i);
        caly=(radio-18)*sin(i);
        glVertex2f(calx,caly+20);
    }
    glEnd();


//edificio
    glColor3f(0.76,0.45,0.20);
    glBegin(GL_QUADS);
    glVertex2i(-4,8);
    glVertex2i(4,8);
    glVertex2i(4,-8);
    glVertex2i(-4,-8);
    glEnd();

//arriba
    glColor3f(1.23,0.63,0.0);
    glBegin(GL_QUADS);
    glVertex2i(-3,6);
    glVertex2i(-1,6);
    glVertex2i(-1,4);
    glVertex2i(-3,4);
    glEnd();

    glColor3f(1.23,0.63,0.0);
    glBegin(GL_QUADS);
    glVertex2i(3,6);
    glVertex2i(1,6);
    glVertex2i(1,4);
    glVertex2i(3,4);
    glEnd();

// centros
    glColor3f(1.23,0.63,0.0);
    glBegin(GL_QUADS);
    glVertex2i(-3,3);
    glVertex2i(-1,3);
    glVertex2i(-1,1);
    glVertex2i(-3,1);
    glEnd();

    glColor3f(1.23,0.63,0.0);
    glBegin(GL_QUADS);
    glVertex2i(3,3);
    glVertex2i(1,3);
    glVertex2i(1,1);
    glVertex2i(3,1);
    glEnd();

//abajo
    glColor3f(1.23,0.63,0.0);
    glBegin(GL_QUADS);
    glVertex2i(-3,0);
    glVertex2i(-1,0);
    glVertex2i(-1,-2);
    glVertex2i(-3,-2);
    glEnd();

    glColor3f(1.23,0.63,0.0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(1,0);
    glVertex2i(1,-2);
    glVertex2i(3,-2);
    glEnd();

//puerta
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2i(-1,-4);
    glVertex2i(1,-4);
    glVertex2i(1,-8);
    glVertex2i(-1,-8);
    glEnd();


//nubes
    glPushMatrix();
    glTranslated(x1,y1,0);
    glColor3f(1,1,1);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x1,y1+1,0);
    glColor3f(1,1,1);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    //Cloud 2
    glPushMatrix();
    glTranslated(x1-1,y1,0);
    glColor3f(1,1,1);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    //Cloud 3
    glPushMatrix();
    glTranslated(x1+1,y1,0);
    glColor3f(1,1,1);
    glutSolidSphere(1,10,10);
    glPopMatrix();


//estrellas
    glPointSize(3);
    glBegin(GL_POINTS);
    glColor3f(1,1,1);
    glVertex2i(x2,y2);
    glEnd();


//arboles
    glPushMatrix();
    glTranslated(x3,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3-1,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3+1,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3-2,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3+2,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x3-1,y3+1,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3+1,y3+1,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x3,y3+2,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
//tronco
    glBegin(GL_QUADS);
    glColor3f(0.647059,0.164706,0.164706);
    glVertex2d(x3-1,y3-1);
    glVertex2d(x3-1,y3-3);
    glVertex2d(x3+1,y3-3);
    glVertex2d(x3+1,y3-1);
    glEnd();

    glFlush();
}

//edificio
void edificio(void){

    glFlush();
}

//Metodo para dibujar las Nubes
void drawClouds (double x1, double y1) {

    glPushMatrix();
    glTranslated(x1,y1,0);
    glColor3f(1,1,1);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x1,y1+1,0);
    glColor3f(1,1,1);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    //Cloud 2
    glPushMatrix();
    glTranslated(x1-1,y1,0);
    glColor3f(1,1,1);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    //Cloud 3
    glPushMatrix();
    glTranslated(x1+1,y1,0);
    glColor3f(1,1,1);
    glutSolidSphere(1,10,10);
    glPopMatrix();
}

void estrellas(double x2,double y2){
    glPointSize(3);
    glBegin(GL_POINTS);
    glColor3f(1,1,1);
    glVertex2i(x2,y2);
    glEnd();
}

void arbol(double x3, double y3) {

    glPushMatrix();
    glTranslated(x3,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3-1,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3+1,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3-2,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3+2,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x3-1,y3+1,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3+1,y3+1,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x3,y3+2,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
//tronco
    glBegin(GL_QUADS);
    glColor3f(0.647059,0.164706,0.164706);
    glVertex2d(x3-1,y3-1);
    glVertex2d(x3-1,y3-3);
    glVertex2d(x3+1,y3-3);
    glVertex2d(x3+1,y3-1);
    glEnd();
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
    window = glutCreateWindow("Menu de imagenes en OpenGL");

    proyeccion();
    createMenu();

    glClearColor(1.0,1.0,1.0,0.0);
    glutDisplayFunc(dibujar);
    glutSpecialFunc(teclado);

    glutMainLoop();
    return EXIT_SUCCESS;
}
#include <GL/glut.h>
#include <math.h>

#if defined(LINUX) || defined(WIN32)
using namespace std;
#endif
//nombre del grupo
void nombre();
//mario bros:
void mario();
void luigi();
void cuerpo(float r, float g, float b);
//paisaje
void montana();
void edificio();
void drawClouds();
void estrellas();
void arbol();

//menu
static int window;
static int menu_id;
static int submenu_id;
static int value = 0;

//teclado
float pos_x = 0;

//paisaje
float px=2, py=5, radio=25, calx, caly;

void proyeccion(){
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-40,40,-40,40);
}

void menu(int num){

    if (num == 0){
        exit(0);
    }

    else{
        value = num;
    }

    glutPostRedisplay();
}

void createMenu(void){
    //figuras que dibujaremos
    //se escriben primero estas entradas para dárselas como parámetros al menu de dibujar más abajo
    submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Nombre del grupo", 2);
    glutAddMenuEntry("Mario", 3);
    glutAddMenuEntry("Luigi", 4);
    glutAddMenuEntry("Paisaje", 5);

    //elementos que aparecen al hacer click derecho
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Limpiar pantalla", 1);
    glutAddSubMenu("Dibujar", submenu_id);
    glutAddMenuEntry("Salir", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void dibujar(){
    glClear(GL_COLOR_BUFFER_BIT);

    if(value == 1){
        glClear(GL_COLOR_BUFFER_BIT);
    }

    else if(value == 2){
        nombre();
    }

    else if(value == 3){
        mario();
    }

    else if(value == 4){
        luigi();
    }

    else if(value == 5){
        montana(0,0,0,0,0,0);

        //estrellas
        montana(0,0,-35,35,0,0);
        montana(0,0,-35,25,0,0);
        montana(0,0,-35,15,0,0);
        montana(0,0,-35,5,0,0);
        montana(0,0,-25,30,0,0);
        montana(0,0,-25,20,0,0);
        montana(0,0,-25,10,0,0);
        montana(0,0,-25,0,0,0);
        montana(0,0,-15,35,0,0);
        montana(0,0,-15,25,0,0);
        montana(0,0,-15,15,0,0);
        montana(0,0,-15,5,0,0);
        montana(0,0,-5,30,0,0);
        montana(0,0,-5,20,0,0);
        montana(0,0,-5,10,0,0);
        montana(0,0,-5,0,0,0);
        montana(0,0,5,35,0,0);
        montana(0,0,5,25,0,0);
        montana(0,0,5,5,0,0);
        montana(0,0,15,30,0,0);
        montana(0,0,15,20,0,0);
        montana(0,0,15,10,0,0);
        montana(0,0,15,0),0,0;
        montana(0,0,25,35,0,0);
        montana(0,0,25,25,0,0);
        montana(0,0,25,15,0,0);
        montana(0,0,25,5,0,0);
        montana(0,0,35,30,0,0);
        montana(0,0,35,20,0,0);
        montana(0,0,35,10,0,0);
        montana(0,0,35,0,0,0);
        //nubes
        montana(0,20,0,0,0,0);
        montana(-4,20,0,0,0,0);
        montana(-8,20,0,0,0,0);
        montana(4,20,0,0,0,0);
        montana(8,20,0,0,0,0);
        montana(6,18,0,0,0,0);
        montana(10,18,0,0,0,0);
        montana(2,18,0,0,0,0);
        montana(-2,18,0,0,0,0);
        montana(-6,18,0,0,0,0);
        montana(-10,18,0,0,0,0);
        //arboles
        montana(0,0,0,0,-34,-8);
        montana(0,0,0,0,-30,-15);
        montana(0,0,0,0,-28,-22);
        montana(0,0,0,0,-36,-28);
        montana(0,0,0,0,-25,-35);
        montana(0,0,0,0,-25,-3);
        montana(0,0,0,0,-15,-23);
        montana(0,0,0,0,-220,-33);
        montana(0,0,0,0,-19,-9);
        montana(0,0,0,0,-10,-12);
        montana(0,0,0,0,0,-15);
        montana(0,0,0,0,0,-25);
        montana(0,0,0,0,-5,-35);
        montana(0,0,0,0,15,-35);
        montana(0,0,0,0,10,-25);
        montana(0,0,0,0,10,-25);
        montana(0,0,0,0,13,-15);
        montana(0,0,0,0,28,-14);
        montana(0,0,0,0,25,-25);
        montana(0,0,0,0,30,-35);
        montana(0,0,0,0,35,-25);
    }

    glutPostRedisplay();

    glFlush();
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

void mario(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,0.0);
    glEnable(GL_LINE_SMOOTH);
//rojo
    //gorra
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(-4 + pos_x,6);
    glVertex2i(-4 + pos_x,7);
    glVertex2i(6 + pos_x,7);
    glVertex2i(6 + pos_x,6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,7);
    glVertex2i(-3 + pos_x,8);
    glVertex2i(3 + pos_x,8);
    glVertex2i(3 + pos_x,7);
    glEnd();
//negro
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(-4 + pos_x,6);
    glVertex2i(-1 + pos_x,6);
    glVertex2i(-1 + pos_x,5);
    glVertex2i(-4 + pos_x,5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,5);
    glVertex2i(-2 + pos_x,5);
    glVertex2i(-2 + pos_x,4);
    glVertex2i(-3 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,4);
    glVertex2i(-1 + pos_x,4);
    glVertex2i(-1 + pos_x,3);
    glVertex2i(-3 + pos_x,3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,5);
    glVertex2i(-4 + pos_x,5);
    glVertex2i(-4 + pos_x,3);
    glVertex2i(-5 + pos_x,3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,3);
    glVertex2i(-3 + pos_x,3);
    glVertex2i(-3 + pos_x,2);
    glVertex2i(-5 + pos_x,2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,6);
    glVertex2i(1 + pos_x,6);
    glVertex2i(1 + pos_x,4);
    glVertex2i(2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,3);
    glVertex2i(3 + pos_x,3);
    glVertex2i(3 + pos_x,4);
    glVertex2i(2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(1 + pos_x,3);
    glVertex2i(5 + pos_x,3);
    glVertex2i(5 + pos_x,2);
    glVertex2i(1 + pos_x,2);
    glEnd();
//piel
    glColor3f(0.95,0.76,0.50);
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,5);
    glVertex2i(-4 + pos_x,5);
    glVertex2i(-4 + pos_x,3);
    glVertex2i(-3 + pos_x,3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,5);
    glVertex2i(-1 + pos_x,5);
    glVertex2i(-1 + pos_x,4);
    glVertex2i(-2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,3);
    glVertex2i(1 + pos_x,3);
    glVertex2i(1 + pos_x,4);
    glVertex2i(2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,6);
    glVertex2i(3 + pos_x,6);
    glVertex2i(3 + pos_x,4);
    glVertex2i(2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,5);
    glVertex2i(5 + pos_x,5);
    glVertex2i(5 + pos_x,3);
    glVertex2i(3 + pos_x,3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(6 + pos_x,3);
    glVertex2i(6 + pos_x,4);
    glVertex2i(5 + pos_x,4);
    glVertex2i(5 + pos_x,3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,2);
    glVertex2i(1 + pos_x,2);
    glVertex2i(1 + pos_x,1);
    glVertex2i(3 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,6);
    glVertex2i(1 + pos_x,6);
    glVertex2i(1 + pos_x,1);
    glVertex2i(-1 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,1);
    glVertex2i(-3 + pos_x,1);
    glVertex2i(-3 + pos_x,3);
    glVertex2i(-1 + pos_x,3);
    glEnd();



//camisa
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1 + pos_x,1);
    glVertex2i(-1 + pos_x,1);
    glVertex2i(-1 + pos_x,-1);
    glVertex2i(1 + pos_x,-1);
    glEnd();
//mangas
    //izquierda
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,-3);
    glVertex2i(-3 + pos_x,-2);
    glVertex2i(-4 + pos_x,-2);
    glVertex2i(-4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,1);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-4 + pos_x,-2);
    glVertex2i(-4 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,0);
    glVertex2i(-5 + pos_x,-2);
    glVertex2i(-4 + pos_x,-2);
    glVertex2i(-4 + pos_x,0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,-1);
    glVertex2i(-5 + pos_x,-2);
    glVertex2i(-6 + pos_x,-2);
    glVertex2i(-6 + pos_x,-1);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,-3);
    glVertex2i(3 + pos_x,-2);
    glVertex2i(4 + pos_x,-2);
    glVertex2i(4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,1);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(4 + pos_x,-2);
    glVertex2i(4 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,0);
    glVertex2i(5 + pos_x,-2);
    glVertex2i(4 + pos_x,-2);
    glVertex2i(4 + pos_x,0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,-1);
    glVertex2i(5 + pos_x,-2);
    glVertex2i(6 + pos_x,-2);
    glVertex2i(6 + pos_x,-1);
    glEnd();
//manos
    //izquierda
    glColor3f(0.95,0.76,0.50);
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,-3);
    glVertex2i(-3 + pos_x,-4);
    glVertex2i(-4 + pos_x,-4);
    glVertex2i(-4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-6 + pos_x,-2);
    glVertex2i(-6 + pos_x,-5);
    glVertex2i(-4 + pos_x,-5);
    glVertex2i(-4 + pos_x,-2);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,-3);
    glVertex2i(3 + pos_x,-4);
    glVertex2i(4 + pos_x,-4);
    glVertex2i(4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(6 + pos_x,-2);
    glVertex2i(6 + pos_x,-5);
    glVertex2i(4 + pos_x,-5);
    glVertex2i(4 + pos_x,-2);
    glEnd();
//overol
    //azul
    //izquierda
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,1);
    glVertex2i(-1 + pos_x,1);
    glVertex2i(-1 + pos_x,-2);
    glVertex2i(-2 + pos_x,-2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,-2);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-2 + pos_x,-4);
    glVertex2i(-3 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-3 + pos_x,-2);
    glVertex2i(-3 + pos_x,-3);
    glVertex2i(-2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,-4);
    glVertex2i(-1 + pos_x,-4);
    glVertex2i(-1 + pos_x,-3);
    glVertex2i(-2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,-6);
    glVertex2i(-4 + pos_x,-6);
    glVertex2i(-4 + pos_x,-4);
    glVertex2i(-1 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,-1);
    glVertex2i(1 + pos_x,-1);
    glVertex2i(1 + pos_x,-5);
    glVertex2i(-1 + pos_x,-5);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,1);
    glVertex2i(1 + pos_x,1);
    glVertex2i(1 + pos_x,-2);
    glVertex2i(2 + pos_x,-2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,-2);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(2 + pos_x,-4);
    glVertex2i(3 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(3 + pos_x,-2);
    glVertex2i(3 + pos_x,-3);
    glVertex2i(2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,-4);
    glVertex2i(1 + pos_x,-4);
    glVertex2i(1 + pos_x,-3);
    glVertex2i(2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(1 + pos_x,-6);
    glVertex2i(4 + pos_x,-6);
    glVertex2i(4 + pos_x,-4);
    glVertex2i(1 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,-1);
    glVertex2i(1 + pos_x,-1);
    glVertex2i(1 + pos_x,-5);
    glVertex2i(-1 + pos_x,-5);
    glEnd();
    //amarillo
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-1 + pos_x,-2);
    glVertex2i(-1 + pos_x,-3);
    glVertex2i(-2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(1 + pos_x,-2);
    glVertex2i(1 + pos_x,-3);
    glVertex2i(2 + pos_x,-3);
    glEnd();
//botas
    //izquierda
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,-6);
    glVertex2i(-5 + pos_x,-8);
    glVertex2i(-2 + pos_x,-8);
    glVertex2i(-2 + pos_x,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,-8);
    glVertex2i(-6 + pos_x,-8);
    glVertex2i(-6 + pos_x,-7);
    glVertex2i(-5 + pos_x,-7);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,-6);
    glVertex2i(5 + pos_x,-8);
    glVertex2i(2 + pos_x,-8);
    glVertex2i(2 + pos_x,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,-8);
    glVertex2i(6 + pos_x,-8);
    glVertex2i(6 + pos_x,-7);
    glVertex2i(5 + pos_x,-7);
    glEnd();

    glFlush();
}

void luigi(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,0.0);
    glEnable(GL_LINE_SMOOTH);
//verde
    //gorra
    glColor3f(0.42,0.68,0.07);
    glBegin(GL_POLYGON);
    glVertex2i(-6 + pos_x,6);
    glVertex2i(-6 + pos_x,7);
    glVertex2i(4 + pos_x,7);
    glVertex2i(4 + pos_x,6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,7);
    glVertex2i(-3 + pos_x,8);
    glVertex2i(3 + pos_x,8);
    glVertex2i(3 + pos_x,7);
    glEnd();
//negro
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(4 + pos_x,6);
    glVertex2i(1 + pos_x,6);
    glVertex2i(1 + pos_x,5);
    glVertex2i(4 + pos_x,5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,5);
    glVertex2i(3 + pos_x,5);
    glVertex2i(3 + pos_x,4);
    glVertex2i(2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,4);
    glVertex2i(1 + pos_x,4);
    glVertex2i(1 + pos_x,3);
    glVertex2i(3 + pos_x,3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(4 + pos_x,5);
    glVertex2i(5 + pos_x,5);
    glVertex2i(5 + pos_x,3);
    glVertex2i(4 + pos_x,3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,3);
    glVertex2i(3 + pos_x,3);
    glVertex2i(3 + pos_x,2);
    glVertex2i(5 + pos_x,2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,6);
    glVertex2i(-1 + pos_x,6);
    glVertex2i(-1 + pos_x,4);
    glVertex2i(-2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,3);
    glVertex2i(-3 + pos_x,3);
    glVertex2i(-3 + pos_x,4);
    glVertex2i(-2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,3);
    glVertex2i(-5 + pos_x,3);
    glVertex2i(-5 + pos_x,2);
    glVertex2i(-1 + pos_x,2);
    glEnd();
//piel
    glColor3f(0.95,0.76,0.50);
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,5);
    glVertex2i(4 + pos_x,5);
    glVertex2i(4 + pos_x,3);
    glVertex2i(3 + pos_x,3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,5);
    glVertex2i(1 + pos_x,5);
    glVertex2i(1 + pos_x,4);
    glVertex2i(2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-6 + pos_x,3);
    glVertex2i(-5 + pos_x,3);
    glVertex2i(-5 + pos_x,4);
    glVertex2i(-6 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,6);
    glVertex2i(-3 + pos_x,6);
    glVertex2i(-3 + pos_x,4);
    glVertex2i(-2 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,5);
    glVertex2i(-5 + pos_x,5);
    glVertex2i(-5 + pos_x,3);
    glVertex2i(-3 + pos_x,3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,3);
    glVertex2i(-2 + pos_x,3);
    glVertex2i(-2 + pos_x,4);
    glVertex2i(-1 + pos_x,4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,2);
    glVertex2i(-1 + pos_x,2);
    glVertex2i(-1 + pos_x,1);
    glVertex2i(-3 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(1 + pos_x,6);
    glVertex2i(-1 + pos_x,6);
    glVertex2i(-1 + pos_x,1);
    glVertex2i(1 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(1 + pos_x,1);
    glVertex2i(3 + pos_x,1);
    glVertex2i(3 + pos_x,3);
    glVertex2i(1 + pos_x,3);
    glEnd();

//camisa
    glColor3f(0.42,0.68,0.07);
    glBegin(GL_POLYGON);
    glVertex2i(1 + pos_x,1);
    glVertex2i(-1 + pos_x,1);
    glVertex2i(-1 + pos_x,-1);
    glVertex2i(1 + pos_x,-1);
    glEnd();
//mangas
    //izquierda
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,-3);
    glVertex2i(-3 + pos_x,-2);
    glVertex2i(-4 + pos_x,-2);
    glVertex2i(-4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,1);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-4 + pos_x,-2);
    glVertex2i(-4 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,0);
    glVertex2i(-5 + pos_x,-2);
    glVertex2i(-4 + pos_x,-2);
    glVertex2i(-4 + pos_x,0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,-1);
    glVertex2i(-5 + pos_x,-2);
    glVertex2i(-6 + pos_x,-2);
    glVertex2i(-6 + pos_x,-1);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,-3);
    glVertex2i(3 + pos_x,-2);
    glVertex2i(4 + pos_x,-2);
    glVertex2i(4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,1);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(4 + pos_x,-2);
    glVertex2i(4 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,0);
    glVertex2i(5 + pos_x,-2);
    glVertex2i(4 + pos_x,-2);
    glVertex2i(4 + pos_x,0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,-1);
    glVertex2i(5 + pos_x,-2);
    glVertex2i(6 + pos_x,-2);
    glVertex2i(6 + pos_x,-1);
    glEnd();
//manos
    //izquierda
    glColor3f(0.95,0.76,0.50);
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,-3);
    glVertex2i(-3 + pos_x,-4);
    glVertex2i(-4 + pos_x,-4);
    glVertex2i(-4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-6 + pos_x,-2);
    glVertex2i(-6 + pos_x,-5);
    glVertex2i(-4 + pos_x,-5);
    glVertex2i(-4 + pos_x,-2);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,-3);
    glVertex2i(3 + pos_x,-4);
    glVertex2i(4 + pos_x,-4);
    glVertex2i(4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(6 + pos_x,-2);
    glVertex2i(6 + pos_x,-5);
    glVertex2i(4 + pos_x,-5);
    glVertex2i(4 + pos_x,-2);
    glEnd();
//overol
    //azul
    //izquierda
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,1);
    glVertex2i(-1 + pos_x,1);
    glVertex2i(-1 + pos_x,-2);
    glVertex2i(-2 + pos_x,-2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,-2);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-2 + pos_x,-4);
    glVertex2i(-3 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-3 + pos_x,-2);
    glVertex2i(-3 + pos_x,-3);
    glVertex2i(-2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,-4);
    glVertex2i(-1 + pos_x,-4);
    glVertex2i(-1 + pos_x,-3);
    glVertex2i(-2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,-6);
    glVertex2i(-4 + pos_x,-6);
    glVertex2i(-4 + pos_x,-4);
    glVertex2i(-1 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,-1);
    glVertex2i(1 + pos_x,-1);
    glVertex2i(1 + pos_x,-5);
    glVertex2i(-1 + pos_x,-5);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,1);
    glVertex2i(1 + pos_x,1);
    glVertex2i(1 + pos_x,-2);
    glVertex2i(2 + pos_x,-2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,-2);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(2 + pos_x,-4);
    glVertex2i(3 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(3 + pos_x,-2);
    glVertex2i(3 + pos_x,-3);
    glVertex2i(2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,-4);
    glVertex2i(1 + pos_x,-4);
    glVertex2i(1 + pos_x,-3);
    glVertex2i(2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(1 + pos_x,-6);
    glVertex2i(4 + pos_x,-6);
    glVertex2i(4 + pos_x,-4);
    glVertex2i(1 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,-1);
    glVertex2i(1 + pos_x,-1);
    glVertex2i(1 + pos_x,-5);
    glVertex2i(-1 + pos_x,-5);
    glEnd();
    //amarillo
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-1 + pos_x,-2);
    glVertex2i(-1 + pos_x,-3);
    glVertex2i(-2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(1 + pos_x,-2);
    glVertex2i(1 + pos_x,-3);
    glVertex2i(2 + pos_x,-3);
    glEnd();
//botas
    //izquierda
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,-6);
    glVertex2i(-5 + pos_x,-8);
    glVertex2i(-2 + pos_x,-8);
    glVertex2i(-2 + pos_x,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,-8);
    glVertex2i(-6 + pos_x,-8);
    glVertex2i(-6 + pos_x,-7);
    glVertex2i(-5 + pos_x,-7);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,-6);
    glVertex2i(5 + pos_x,-8);
    glVertex2i(2 + pos_x,-8);
    glVertex2i(2 + pos_x,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,-8);
    glVertex2i(6 + pos_x,-8);
    glVertex2i(6 + pos_x,-7);
    glVertex2i(5 + pos_x,-7);
    glEnd();

    glFlush();
}

// se glitchea si están separadas
void cuerpo(float r, float g, float b){
    //glClear(GL_COLOR_BUFFER_BIT);
//camisa
    glColor3f(0.42,0.68,0.07);
    glBegin(GL_POLYGON);
    glVertex2i(1 + pos_x,1);
    glVertex2i(-1 + pos_x,1);
    glVertex2i(-1 + pos_x,-1);
    glVertex2i(1 + pos_x,-1);
    glEnd();
//mangas
    //izquierda
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,-3);
    glVertex2i(-3 + pos_x,-2);
    glVertex2i(-4 + pos_x,-2);
    glVertex2i(-4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,1);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-4 + pos_x,-2);
    glVertex2i(-4 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,0);
    glVertex2i(-5 + pos_x,-2);
    glVertex2i(-4 + pos_x,-2);
    glVertex2i(-4 + pos_x,0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,-1);
    glVertex2i(-5 + pos_x,-2);
    glVertex2i(-6 + pos_x,-2);
    glVertex2i(-6 + pos_x,-1);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,-3);
    glVertex2i(3 + pos_x,-2);
    glVertex2i(4 + pos_x,-2);
    glVertex2i(4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,1);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(4 + pos_x,-2);
    glVertex2i(4 + pos_x,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,0);
    glVertex2i(5 + pos_x,-2);
    glVertex2i(4 + pos_x,-2);
    glVertex2i(4 + pos_x,0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,-1);
    glVertex2i(5 + pos_x,-2);
    glVertex2i(6 + pos_x,-2);
    glVertex2i(6 + pos_x,-1);
    glEnd();
//manos
    //izquierda
    glColor3f(0.95,0.76,0.50);
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,-3);
    glVertex2i(-3 + pos_x,-4);
    glVertex2i(-4 + pos_x,-4);
    glVertex2i(-4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-6 + pos_x,-2);
    glVertex2i(-6 + pos_x,-5);
    glVertex2i(-4 + pos_x,-5);
    glVertex2i(-4 + pos_x,-2);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,-3);
    glVertex2i(3 + pos_x,-4);
    glVertex2i(4 + pos_x,-4);
    glVertex2i(4 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(6 + pos_x,-2);
    glVertex2i(6 + pos_x,-5);
    glVertex2i(4 + pos_x,-5);
    glVertex2i(4 + pos_x,-2);
    glEnd();
//overol
    //azul
    //izquierda
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,1);
    glVertex2i(-1 + pos_x,1);
    glVertex2i(-1 + pos_x,-2);
    glVertex2i(-2 + pos_x,-2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-3 + pos_x,-2);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-2 + pos_x,-4);
    glVertex2i(-3 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-3 + pos_x,-2);
    glVertex2i(-3 + pos_x,-3);
    glVertex2i(-2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,-4);
    glVertex2i(-1 + pos_x,-4);
    glVertex2i(-1 + pos_x,-3);
    glVertex2i(-2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,-6);
    glVertex2i(-4 + pos_x,-6);
    glVertex2i(-4 + pos_x,-4);
    glVertex2i(-1 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,-1);
    glVertex2i(1 + pos_x,-1);
    glVertex2i(1 + pos_x,-5);
    glVertex2i(-1 + pos_x,-5);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,1);
    glVertex2i(1 + pos_x,1);
    glVertex2i(1 + pos_x,-2);
    glVertex2i(2 + pos_x,-2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(3 + pos_x,-2);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(2 + pos_x,-4);
    glVertex2i(3 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(3 + pos_x,-2);
    glVertex2i(3 + pos_x,-3);
    glVertex2i(2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,-4);
    glVertex2i(1 + pos_x,-4);
    glVertex2i(1 + pos_x,-3);
    glVertex2i(2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(1 + pos_x,-6);
    glVertex2i(4 + pos_x,-6);
    glVertex2i(4 + pos_x,-4);
    glVertex2i(1 + pos_x,-4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-1 + pos_x,-1);
    glVertex2i(1 + pos_x,-1);
    glVertex2i(1 + pos_x,-5);
    glVertex2i(-1 + pos_x,-5);
    glEnd();
    //amarillo
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(-2 + pos_x,-2);
    glVertex2i(-1 + pos_x,-2);
    glVertex2i(-1 + pos_x,-3);
    glVertex2i(-2 + pos_x,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(2 + pos_x,-2);
    glVertex2i(1 + pos_x,-2);
    glVertex2i(1 + pos_x,-3);
    glVertex2i(2 + pos_x,-3);
    glEnd();
//botas
    //izquierda
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,-6);
    glVertex2i(-5 + pos_x,-8);
    glVertex2i(-2 + pos_x,-8);
    glVertex2i(-2 + pos_x,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(-5 + pos_x,-8);
    glVertex2i(-6 + pos_x,-8);
    glVertex2i(-6 + pos_x,-7);
    glVertex2i(-5 + pos_x,-7);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,-6);
    glVertex2i(5 + pos_x,-8);
    glVertex2i(2 + pos_x,-8);
    glVertex2i(2 + pos_x,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(5 + pos_x,-8);
    glVertex2i(6 + pos_x,-8);
    glVertex2i(6 + pos_x,-7);
    glVertex2i(5 + pos_x,-7);
    glEnd();

    glFlush();
}

void montana(double x1, double y1, double x2,double y2,double x3, double y3){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f( 0.137255, 0.556863,0.137255);
    glPointSize(1.0);
    glBegin(GL_POLYGON);
    for (double i=0.0; i<10; i+=0.001)
    {
        calx=(radio+10)*cos(i);
        caly=(radio+10)*sin(i-500);
        glVertex2f(calx-40,caly-40);
    }
    glEnd();
//
    glPointSize(1.0);
    glBegin(GL_POLYGON);
    for (double i=0.0; i<10; i+=0.001)
    {
        calx=radio*cos(i);
        caly=radio*sin(i+50);
        glVertex2f(calx+40,caly-40);
    }
    glEnd();
//
    glPointSize(1.0);
    glBegin(GL_POLYGON);
    for (double i=0.0; i<10; i+=0.001)
    {
        calx=radio*cos(i);
        caly=radio*sin(i+50);
        glVertex2f(calx+10,caly-30);
    }
    glEnd();
//luna
    glColor3f(0.85,0.85,0.85);
    glPointSize(1.0);
    glBegin(GL_POLYGON);
    for (double i=0.0; i<3; i+=0.001)
    {
        calx=(radio-18)*cos(i);
        caly=(radio-18)*sin(i);
        glVertex2f(calx,caly+20);
    }
    glEnd();


//edificio
    glColor3f(0.76,0.45,0.20);
    glBegin(GL_QUADS);
    glVertex2i(-4,8);
    glVertex2i(4,8);
    glVertex2i(4,-8);
    glVertex2i(-4,-8);
    glEnd();

//arriba
    glColor3f(1.23,0.63,0.0);
    glBegin(GL_QUADS);
    glVertex2i(-3,6);
    glVertex2i(-1,6);
    glVertex2i(-1,4);
    glVertex2i(-3,4);
    glEnd();

    glColor3f(1.23,0.63,0.0);
    glBegin(GL_QUADS);
    glVertex2i(3,6);
    glVertex2i(1,6);
    glVertex2i(1,4);
    glVertex2i(3,4);
    glEnd();

// centros
    glColor3f(1.23,0.63,0.0);
    glBegin(GL_QUADS);
    glVertex2i(-3,3);
    glVertex2i(-1,3);
    glVertex2i(-1,1);
    glVertex2i(-3,1);
    glEnd();

    glColor3f(1.23,0.63,0.0);
    glBegin(GL_QUADS);
    glVertex2i(3,3);
    glVertex2i(1,3);
    glVertex2i(1,1);
    glVertex2i(3,1);
    glEnd();

//abajo
    glColor3f(1.23,0.63,0.0);
    glBegin(GL_QUADS);
    glVertex2i(-3,0);
    glVertex2i(-1,0);
    glVertex2i(-1,-2);
    glVertex2i(-3,-2);
    glEnd();

    glColor3f(1.23,0.63,0.0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(1,0);
    glVertex2i(1,-2);
    glVertex2i(3,-2);
    glEnd();

//puerta
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2i(-1,-4);
    glVertex2i(1,-4);
    glVertex2i(1,-8);
    glVertex2i(-1,-8);
    glEnd();


//nubes
    glPushMatrix();
    glTranslated(x1,y1,0);
    glColor3f(1,1,1);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x1,y1+1,0);
    glColor3f(1,1,1);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    //Cloud 2
    glPushMatrix();
    glTranslated(x1-1,y1,0);
    glColor3f(1,1,1);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    //Cloud 3
    glPushMatrix();
    glTranslated(x1+1,y1,0);
    glColor3f(1,1,1);
    glutSolidSphere(1,10,10);
    glPopMatrix();


//estrellas
    glPointSize(3);
    glBegin(GL_POINTS);
    glColor3f(1,1,1);
    glVertex2i(x2,y2);
    glEnd();


//arboles
    glPushMatrix();
    glTranslated(x3,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3-1,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3+1,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3-2,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3+2,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x3-1,y3+1,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3+1,y3+1,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x3,y3+2,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
//tronco
    glBegin(GL_QUADS);
    glColor3f(0.647059,0.164706,0.164706);
    glVertex2d(x3-1,y3-1);
    glVertex2d(x3-1,y3-3);
    glVertex2d(x3+1,y3-3);
    glVertex2d(x3+1,y3-1);
    glEnd();

    glFlush();
}

//edificio
void edificio(void){

    glFlush();
}

//Metodo para dibujar las Nubes
void drawClouds (double x1, double y1) {

    glPushMatrix();
    glTranslated(x1,y1,0);
    glColor3f(1,1,1);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x1,y1+1,0);
    glColor3f(1,1,1);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    //Cloud 2
    glPushMatrix();
    glTranslated(x1-1,y1,0);
    glColor3f(1,1,1);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    //Cloud 3
    glPushMatrix();
    glTranslated(x1+1,y1,0);
    glColor3f(1,1,1);
    glutSolidSphere(1,10,10);
    glPopMatrix();
}

void estrellas(double x2,double y2){
    glPointSize(3);
    glBegin(GL_POINTS);
    glColor3f(1,1,1);
    glVertex2i(x2,y2);
    glEnd();
}

void arbol(double x3, double y3) {

    glPushMatrix();
    glTranslated(x3,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3-1,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3+1,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3-2,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3+2,y3,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x3-1,y3+1,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x3+1,y3+1,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x3,y3+2,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
//tronco
    glBegin(GL_QUADS);
    glColor3f(0.647059,0.164706,0.164706);
    glVertex2d(x3-1,y3-1);
    glVertex2d(x3-1,y3-3);
    glVertex2d(x3+1,y3-3);
    glVertex2d(x3+1,y3-1);
    glEnd();
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
    window = glutCreateWindow("Menu de imagenes en OpenGL");

    proyeccion();
    createMenu();

    glClearColor(1.0,1.0,1.0,0.0);
    glutDisplayFunc(dibujar);
    glutSpecialFunc(teclado);

    glutMainLoop();
    return EXIT_SUCCESS;
}
