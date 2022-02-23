#include <GL/glut.h>
#include <iostream>

using namespace std;

void init(void);
void display(void);
bool clicked = true;
int xp,yp;

void init(void) {

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 800.0, 0.0, 800.0);
  glClear(GL_COLOR_BUFFER_BIT);

}

void mouse(int button, int action, int x, int y) {
  switch(button)  {
    case GLUT_LEFT_BUTTON:
    {

      cout << "(x,y): " << x << ", " << y << endl;
    	clicked = true;
      xp = x;
      yp = 800 - y;
      break;

    }
    case GLUT_MIDDLE_BUTTON:
    {

      break;
    }
    case GLUT_RIGHT_BUTTON:
    {

      glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
      clicked = false;
      break;

    }
    default: break;
  }

  glutPostRedisplay();
}

void display() {
  
  glPointSize(50);
  glColor3f(0, 0, 0);
  if(clicked) {
    glBegin(GL_POINTS);
      glVertex2i(xp, yp);
    glEnd();
  }
  glFlush();
}

int main(int argc, char** argv) {

  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (800, 800);
  glutInitWindowPosition (200, 200);
  glutCreateWindow ("Question 2");
  init();
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutMainLoop();

  return 0;

}

