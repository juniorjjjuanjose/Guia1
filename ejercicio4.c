//------------------------------------------
//          INTEGRANTES
//Juan José Valdez Jiménez VJ11002
//Mauricio Edgardo Montano Vásquez MV12025
//------------------------------------------

//Declaracion de librerias
#include <stdio.h>
#include <stdarg.h>//Permite que las funciones acepten un número indefinido de argumentos.
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

//Definiendo los protoripos de la funcion
void display();
void specialKeys();

//Definicion de variables globales
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;

//Definicion de constantes
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;

void display()//Inicio de funcion Display
{

  //Borrar pantalla y Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  //Resetear transformaciones
  glLoadIdentity();

  // Otras transformaciones
  //glTranslatef( 0.1, 0.0, 0.0 );      // No incluido
  //glRotatef( 180, 0.0, 1.0, 0.0 );    // No incluido

  //Rotar cuando el usuario cambie “rotate_x” , “rotate_y” y "rotate_z"
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  glRotatef( rotate_z, 0.0, 0.0, 1.0 );
  glTranslatef(X, Y, Z);

  //Otras transformaciones
  glScalef( scale, scale, scale );

  //LADO FRONTAL: lado multicolor
  glBegin(GL_POLYGON);//Definicion de primitiva

  glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  0.5, -0.5, -0.5 );      // P1 es rojo
  glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  0.5,  0.5, -0.5 );      // P2 es verde
  glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -0.5,  0.5, -0.5 );      // P3 es azul
  glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -0.5, -0.5, -0.5 );      // P4 es morado

  glEnd();

  // LADO TRASERO: lado blanco
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f(  0.5, -0.5, 0.5 );
  glVertex3f(  0.5,  0.5, 0.5 );
  glVertex3f( -0.5,  0.5, 0.5 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glEnd();

  // LADO DERECHO: lado Verde
  glBegin(GL_POLYGON);
  glColor3f(  0.0,  1.0,  0.0 );
  glVertex3f( 0.5, -0.5, -0.5 );
  glVertex3f( 0.5,  0.5, -0.5 );
  glVertex3f( 0.5,  0.5,  0.5 );
  glVertex3f( 0.5, -0.5,  0.5 );
  glEnd();

  // LADO IZQUIERDO: lado amarillo
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0,  0.0 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  // LADO SUPERIOR: lado azul
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f(  0.5,  0.5,  0.5 );
  glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glEnd();

  // LADO INFERIOR: lado rojo
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  glFlush();
  glutSwapBuffers();

}


void specialKeys( int key, int x, int y ) //Funcion para hacer uso de las teclas de direccion (Flechas) y las teclas especiales F! y F2
{

  //Flecha derecha: aumentar rotación 5 grados
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;

  //Flecha izquierda: disminuir rotación 5 grados
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;

  //Flecha arriba: aumentar rotación 5 grados
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;

  //Flecha abajo: disminuir rotación 5 grados
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;

  //Tecla especial F1: aumenta rotacion 5 grados
  else if (key == GLUT_KEY_F1)
    rotate_z += 5;

  //Tecla especial F2: disminuye rotacion 5 grados
  else if (key == GLUT_KEY_F2)
    rotate_z -= 5;


  glutPostRedisplay();//Solicitar actualización de visualización

}

void keyboard(unsigned char key, int x, int y)//Funcion que sirve para el uso de las teclas S,D,X,Y,Z y Q
{
    switch (key)
    {
    case 's':
        scale=0.5;
        break;
    case 'd':
        scale=1.5;
        break;
    case 'x' :
        X += 0.1f;
        break;
    case 'X' :
        X -= 0.1f;
        break;
    case 'y' :
        Y += 0.1f;
        break;
    case 'Y' :
        Y -= 0.1f;
        break;
    case 'z':
        Z += 0.1f;
        break;
    case 'Z':
        Z -= 0.1f;
        break;
    case 27://Numero que corresponde a la tecla ESCAPE
        exit(0);//Salir precionando ESC
    }

    glutPostRedisplay();//Actualización de visualización
}


int main(int argc, char* argv[])//Inicio de la Funcion principal
{


  glutInit(&argc,argv);//Inicializar los parámetros GLUT y de usuario proceso


  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//Solicitar ventana con color real y doble buffer con Z-buffer

  //Crear ventana
  glutInitWindowSize (600, 600);
  glutInitWindowPosition (0,0);
  glutCreateWindow("Ejercicio_4");

  //Habilitar la prueba de profundidad de Z-buffer
  glEnable(GL_DEPTH_TEST);

  //Funciones de retrollamada
    glutDisplayFunc(display);//Invoca la funcion display
    glutKeyboardFunc(keyboard); //invoca funcion de teclado
    glutSpecialFunc(specialKeys);//invoca teclas de función especial
    glutMainLoop();

  //Regresar al sistema operativo
  return 0;

}
