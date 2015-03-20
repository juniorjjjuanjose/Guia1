//------------------------------------------
//          INTEGRANTES
//Juan José Valdez Jiménez VJ11002
//Mauricio Edgardo Montano Vásquez MV12025
//------------------------------------------

//Declaracion de librerias
#include <GL/gl.h>
#include <GL/glut.h>


void display(void)//Inicio de la funcion Display
{
	glClear (GL_COLOR_BUFFER_BIT);//Reseteo del buffer para establecer colores

	  glBegin(GL_QUADS);
      glColor3f (0.0, 0.0, 1.0);
	  glVertex2f( -0.3f, 0.15f);
      glVertex2f( -0.3f, -0.15f);
      glVertex2f( 0.50f, -0.15f);
      glVertex2f( 0.50f, 0.15f);
	  glEnd();

	  glBegin(GL_QUADS);
	  glColor3f (1.0, 0.0, 0.0);
	  glVertex2f( -0.35f, 0.11f);
      glVertex2f( -0.35f, 0.04f);
	  glVertex2f( -0.3f, 0.04f);
      glVertex2f( -0.3f, 0.11f);
      glEnd();

	  glBegin(GL_QUADS);
	  glColor3f (1.0, 0.0, 0.0);
	  glVertex2f( -0.35f, -0.11f);
      glVertex2f( -0.35f, -0.04f);
	  glVertex2f( -0.3f, -0.04f);
      glVertex2f( -0.3f, -0.11f);
      glEnd();


	  glBegin(GL_TRIANGLES);
	  glColor3f (0.0, 1.0, 0.0); //triangulo verde
	  glVertex3f(0.75f, 0.0f, 0.0f);
	  glVertex3f(0.50f, -0.20f, 0.0f);
	  glVertex3f(0.50f, 0.20f, 0.0f);
	  glEnd();

	  glBegin(GL_TRIANGLES);
	  glColor3f (1.0, 0.0, 0.0); //rojo
	  glVertex3f(0.3f, 0.15f, 0.0f);
	  glVertex3f(0.1f, 0.35f, 0.0f);
	  glVertex3f(-0.1f, 0.15f, 0.0f);
	  glEnd();

	  glBegin(GL_TRIANGLES);
	  glColor3f (0.0, 1.0, 0.0); //verde
	  glVertex3f(-0.29f, 0.35f, 0.0f);
	  glVertex3f(0.1, 0.35f, 0.0f);
	  glVertex3f(-0.1f, 0.15f, 0.0f);
	  glEnd();

	  glBegin(GL_TRIANGLES);
	  glColor3f (1.0, 0.0, 0.0); //triangulo rojo2
	  glVertex3f(0.3f, -0.15f, 0.0f);
	  glVertex3f(0.1f, -0.35f, 0.0f);
	  glVertex3f(-0.1f, -0.15f, 0.0f);
	  glEnd();

	  glBegin(GL_TRIANGLES);
	  glColor3f (0.0, 1.0, 0.0); //verde2
	  glVertex3f(-0.29f, -0.35f, 0.0f);
	  glVertex3f(0.1f, -0.35f, 0.0f);
	  glVertex3f(-0.1f, -0.15f, 0.0f);
	  glEnd();
	  glFlush ();
}

void init (void)//Inicio de la funcion INIT
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);//Configuracion de la camara
}
int main(int argc, char** argv)//Inicio de la funcion principal
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (800, 600);//Tamaño
	glutInitWindowPosition (100,100);//Posicion
	glutCreateWindow ("Ejercicio_3");//Titulo de la ventana
	init();
	glutDisplayFunc(display);//Llamado a la funcion Display
	glutMainLoop();
	return 0;//Retorno
}
