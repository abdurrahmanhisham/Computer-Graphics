#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
float y=30;
void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-50, 50, -50, 50, -1.0, 1.0);
}
void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    if (y <= 30) { 
        y = y + 0.01;
    } else {
        y = -30;  
    }
    glutPostRedisplay();
    glBegin(GL_QUADS);
    glVertex2f(-10, y);
    glVertex2f(0, y);
    glVertex2f(0, y - 20);
    glVertex2f(-10, y - 20);
    glEnd();
    glutSwapBuffers();
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lab 5");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}

