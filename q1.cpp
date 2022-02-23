#include <GL/glut.h>

// Based on professor's code
void init(void)
{
  glClearColor(1.0, 1.0, 1.0, 1.0);

  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  glOrtho (-1, 1, -1, 1, -1, 1);
}

void display() {

  glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_POLYGON); // Roof
      glColor3f(1, 0, 0);
      glVertex2f(-0.4, 0.4);
      glVertex2f(0.4, 0.4);
      glVertex2f(0, 0.8);
    glEnd();
  	
    glBegin(GL_POLYGON); // Building
  	  glColor3f(0, 0, 1);
  	  glVertex2f(-0.4, -0.4);
  	  glVertex2f(0.4, -0.4);
  	  glVertex2f(0.4, 0.4);
  	  glVertex2f(-0.4, 0.4);
  	glEnd();
  	
    glBegin(GL_POLYGON); // Door
  	  glColor3f(1, 1, 1);
  	  glVertex2f(-0.1, -0.39);
  	  glVertex2f(0.1, -0.39);
  	  glVertex2f(0.1, 0.1);
  	  glVertex2f(-0.1, 0.1);
  	glEnd();
    

  glFlush();
}

void keyboard( unsigned char key, int x, int y )
{
  if( key == ' ') {
		glClearColor(0.0, 0.0, 0.0, 1.0);
  } else {
		glClearColor(1.0, 1.0, 1.0, 1.0);
  }
display();
}


int main(int argc, char** argv)
{

  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (800, 800);
  glutInitWindowPosition (200, 200);
  glutCreateWindow ("Question 1");
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMainLoop();

  return 0;

}
