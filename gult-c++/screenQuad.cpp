 #include <iostream>
#include <windows.h>
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

 void display(){
 glClearColor(0.0f,0.1f,0.5f,1.0f);
 glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_QUADS) ;
 glColor3f(1.0f, 1.0f , 0.0f);
 glVertex2f(-0.5f , -0.5f );
 glVertex2f(0.5f , -0.5f );
 glVertex2f(0.5f ,  0.5f );
 glVertex2f(-0.5f,  0.5f);
 glEnd();
 glFlush();



 }
 int main( int argc , char** argv ){
   glutInit(&argc , argv);
   glutCreateWindow("Sample Test File");
   glutInitWindowSize(512,512);
   glutInitWindowPosition(50,50);
   glutDisplayFunc(display);
   glutMainLoop();
   return 0 ;

 }

