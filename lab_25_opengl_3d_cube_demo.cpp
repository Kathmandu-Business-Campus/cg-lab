#include <GL/glut.h>
#include <GL/glu.h>

static float rotX = 0.0f;
static float rotY = 0.0f;

void drawCube(void) {
    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
    glColor3f(0.0f, 0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);

    glColor3f(1.0f, 0.5f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
    glColor3f(0.5f, 0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
    glColor3f(1.0f, 1.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);

    glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
    glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
    glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-1.0f,  1.0f, -1.0f);

    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);

    glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
    glColor3f(0.0f, 0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
    glColor3f(0.0f, 0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);

    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);

    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(rotX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotY, 0.0f, 1.0f, 0.0f);
    drawCube();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'x' || key == 'X') rotX += 10.0f;
    if (key == 'y' || key == 'Y') rotY += 10.0f;
    if (key == 27) exit(0);
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL 3D Cube Demo");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
