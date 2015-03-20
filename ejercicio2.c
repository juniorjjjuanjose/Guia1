//------------------------------------------
//          INTEGRANTES
//Juan José Valdez Jiménez VJ11002
//Mauricio Edgardo Montano Vásquez MV12025
//------------------------------------------

//Declaracion de las librerias principales
#include <GL/gl.h>
#include <GL/glut.h>
void display(void)//Inicio de la funcion Display
{
    glClear (GL_COLOR_BUFFER_BIT);//Reseteo del buffer para establecimiento de color
    glColor3f (0.0, 0.0, 1.0);//Definiendo color Azul para el cuadrado
    glBegin(GL_POLYGON);//Tipo de primitiva
    glVertex3f(-0.3f, -0.3f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.0f);
    glVertex3f(0.3f, 0.3f, 0.0f);
    glVertex3f(-0.3f, 0.3f, 0.0f);
    glEnd();
    glBegin(GL_TRIANGLES); //Triangulo izquierdo color verde
    glColor3f (0.0, 1.0, 0.0);//Definiendo color verde
    glVertex3f(-0.7f, 0.0f, 0.0f);
    glVertex3f(-0.3f, -0.3f, 0.0f);
    glVertex3f(-0.3f, 0.3f, 0.0f);
    glEnd();
    glBegin(GL_TRIANGLES); // Triangulo derecho color verde
    glColor3f (0.0, 1.0, 0.0);//Definiendo color verde
    glVertex3f(0.3f, 0.3f, 0.0f);
    glVertex3f(0.7f, 0.0f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.0f);
    glEnd();
    glBegin(GL_TRIANGLES); // Triangulo superior amarillo
    glColor3f (1.0, 1.0, 0.0);//Definiendo color Amarillo
    glVertex3f(-0.3f, 0.3f, 0.0f);
    glVertex3f(0.0f, 0.7f, 0.0f);
    glVertex3f(0.3f, 0.3f, 0.0f);
    glEnd();
    glBegin(GL_TRIANGLES); // Triangulo inferior rojo
    glColor3f (1.0, 0.0, 0.0);//Definiendo color Rojo
    glVertex3f(-0.3f, -0.3f, 0.0f);
    glVertex3f(0.0f, -0.7f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.0f);
    glEnd();
    glFlush ();
}//Fin de funcion Display
void init (void)//Inicio de la funcion INIT
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);//Coordenadas de la camara
}
int main(int argc, char** argv)//Inicio de la funcion principal
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 600);//Tamaño de la ventana
    glutInitWindowPosition (100,100);//Posicion de la ventana
    glutCreateWindow ("Ejercicio_2");//Titulo de la ventana
    init();
    glutDisplayFunc(display);//Llamado a la funcion Display
    glutMainLoop();
    return 0;//Retorno
}
