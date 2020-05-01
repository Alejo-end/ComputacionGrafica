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
        // cuerpo(1.0,0.0,0.0);
    }

    else if(value == 4){
        luigi();
        cuerpo(0.42,0.68,0.07);
    }

    else if(value == 5){
        montana();

        edificio();

        estrellas(-35,35);
        estrellas(-35,25);
        estrellas(-35,15);
        estrellas(-35,5);
        estrellas(-25,30);
        estrellas(-25,20);
        estrellas(-25,10);
        estrellas(-25,0);
        estrellas(-15,35);
        estrellas(-15,25);
        estrellas(-15,15);
        estrellas(-15,5);
        estrellas(-5,30);
        estrellas(-5,20);
        estrellas(-5,10);
        estrellas(-5,0);
        estrellas(5,35);
        estrellas(5,25);
        estrellas(5,15);
        estrellas(5,5);
        estrellas(15,30);
        estrellas(15,20);
        estrellas(15,10);
        estrellas(15,0);
        estrellas(25,35);
        estrellas(25,25);
        estrellas(25,15);
        estrellas(25,5);
        estrellas(35,30);
        estrellas(35,20);
        estrellas(35,10);
        estrellas(35,0);

        drawClouds(0,20);
        drawClouds(-4,20);
        drawClouds(-8,20);
        drawClouds(4,20);
        drawClouds(8,20);
        drawClouds(6,18);
        drawClouds(10,18);
        drawClouds(2,18);
        drawClouds(-2,18);
        drawClouds(-6,18);
        drawClouds(-10,18);

        arbol(-34,-8);
        arbol(-30,-15);
        arbol(-28,-22);
        arbol(-36,-28);
        arbol(-25,-35);
        arbol(-25,-3);
        arbol(-15,-23);
        arbol(-220,-33);
        arbol(-19,-9);
        arbol(-10,-12);
        arbol(0,-15);
        arbol(0,-25);
        arbol(-5,-35);
        arbol(15,-35);
        arbol(10,-25);
        arbol(10,-25);
        arbol(13,-15);
        arbol(28,-14);
        arbol(25,-25);
        arbol(30,-35);
        arbol(35,-25);
    }

    glutPostRedisplay();

    glFlush();
}

void nombre(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,0.0);
    glEnable(GL_LINE_SMOOTH);
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

    glFlush();
}

void cuerpo(float r, float g, float b){
    //glClear(GL_COLOR_BUFFER_BIT);
//camisa
    glColor3f(r,g,b);
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

void montana(void){
    glClear(GL_COLOR_BUFFER_BIT);
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
    glFlush();
}
//edificio
void edificio(void){
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

void arbol(double x1, double y1) {

    glPushMatrix();
    glTranslated(x1,y1,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x1-1,y1,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x1+1,y1,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x1-2,y1,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x1+2,y1,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x1-1,y1+1,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x1+1,y1+1,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x1,y1+2,0);
    glColor3f(0,1,0);
    glutSolidSphere(1,10,10);
    glPopMatrix();
//tronco
    glBegin(GL_QUADS);
    glColor3f(0.647059,0.164706,0.164706);
    glVertex2d(x1-1,y1-1);
    glVertex2d(x1-1,y1-3);
    glVertex2d(x1+1,y1-3);
    glVertex2d(x1+1,y1-1);
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
