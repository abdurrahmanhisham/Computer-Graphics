#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0); // Initial background color
  glMatrixMode(GL_PROJECTION);      // Set the projection matrix
  glLoadIdentity();
  glOrtho(0.0, 100, 0.0, 100.0, -1.0, 1.0); // Orthographic projection
}

void Draw()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0, 0, 255);
  glBegin(GL_POLYGON);
  glVertex2i(48, 23);
  glVertex2i(50, 5);
  glVertex2i(52, 23);
  glVertex2i(70, 25);
  glVertex2i(52, 27);
  glVertex2i(50, 45);
  glVertex2i(48, 27);
  glVertex2i(30, 25);
  glEnd();


  glColor3f(0, 255,0);
  glBegin(GL_POLYGON);
  glVertex2i(68, 43);
  glVertex2i(70, 25);
  glVertex2i(72, 43);
  glVertex2i(90, 45);
  glVertex2i(72, 47);
  glVertex2i(70, 65);
  glVertex2i(68, 47);
  glVertex2i(50, 45);
  glEnd();

glColor3f(255, 0,0);
  glBegin(GL_POLYGON);
  glVertex2i(48, 63);
  glVertex2i(50, 45);
  glVertex2i(52, 63);
  glVertex2i(70, 65);
  glVertex2i(52, 67);
  glVertex2i(50, 85);
  glVertex2i(48, 67);
  glVertex2i(30, 65);
  glEnd();

glColor3f(255, 255,0);
  glBegin(GL_POLYGON);
  glVertex2i(28, 43);
  glVertex2i(30, 25);
  glVertex2i(32, 43);
  glVertex2i(50, 45);
  glVertex2i(32, 47);
  glVertex2i(30, 65);
  glVertex2i(28, 47);
  glVertex2i(10, 45);
  glEnd();

  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Lab Final");
  init();
  glutDisplayFunc(Draw);
  glutMainLoop();
  return 0;
}
