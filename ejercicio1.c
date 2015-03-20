//------------------------------------------
//          INTEGRANTES
//Juan José Valdez Jiménez VJ11002
//Mauricio Edgardo Montano Vásquez MV12025
//------------------------------------------

//Declaracion de las variables
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>//Libreria que servira para trabajar con las funciones trigonometricas

void display(void)//Aqui comienza la funcion Display
{
    glClear (GL_COLOR_BUFFER_BIT);//Limpia el buffer para establecer el color
    glColor3f (1.0, 1.0, 1.0); //En esta linea estamos asignando el color a los puntos
    glPointSize(4);//Tamaño de los puntos
    GLfloat angulo; //Variable constante angulo
    float i; //Declarando una variable flotante
    glBegin(GL_POINTS); //Tipo de primitiva
    for (i=0; i<360; i+=7.2)//Aqui comienza el FOR que dibujara los 50 puntos automaticamente
    {
        angulo = (GLfloat)i*3.14159f/180.0f; // de grados a radianes
        //glVertex3f(0.0f, 0.0f, 0.0f); //Esta linea esta comentada para que no imprima un punto en el centro
        glVertex3f(cos(angulo), sin(angulo), 0.0f);//Coordenadas para los diferentes vertices
    }
    glEnd();//Fin de la primitiva
    glFlush ();
}//Aqui termina la funcion Display
void init (void)//Aqui inicia la funcion INIT
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);//Coordenadas de la orientacion de la camara
}//Fin de la funcion INIT
int main(int argc, char** argv)//Aqui empieza la funcion principal
{
    glutInit(&argc, argv); //Inicializa GLUT y procesa los argumentos de la línea de comandos (para X, esto sería opciones como -display y -geometry).
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 400);//Define el tamaño de la ventana
    glutInitWindowPosition (100,100);//Define la posicion de la ventana
    glutCreateWindow ("Ejercicio_1");//Titulo de la ventana
    init();
    glutDisplayFunc(display);//Llamado a la funcion Diaplay
    glutMainLoop();
    return 0;//Devuelve un valor de retorno
}
