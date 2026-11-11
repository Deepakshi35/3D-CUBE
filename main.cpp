#include <GL/freeglut.h>

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;

// Draw 3D Cube
void drawCube()
{
    glBegin(GL_QUADS);

    // Front face - Red
    glColor3f(1, 0, 0);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(-1, 1, 1);

    // Back face - Green
    glColor3f(0, 1, 0);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, -1);

    // Top face - Blue
    glColor3f(0, 0, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);

    // Bottom face - Yellow
    glColor3f(1, 1, 0);
    glVertex3f(-1, -1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);

    // Right face - Orange
    glColor3f(1, 0.5, 0);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, 1);

    // Left face - Cyan
    glColor3f(0, 1, 1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);

    glEnd();
}

// Display function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0, 0, -6);

    // Apply 3D rotations
    glRotatef(angleX, 1, 0, 0);
    glRotatef(angleY, 0, 1, 0);
    glRotatef(angleZ, 0, 0, 1);

    drawCube();

    glutSwapBuffers();
}

// Animation function
void update(int value)
{
    angleX += 0.5f;
    angleY += 0.7f;
    angleZ += 0.3f;

    if (angleX >= 360) angleX -= 360;
    if (angleY >= 360) angleY -= 360;
    if (angleZ >= 360) angleZ -= 360;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// Window resizing
void reshape(int w, int h)
{
    if (h == 0) h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45, (float)w / h, 1, 100);

    glMatrixMode(GL_MODELVIEW);
}

// Main function
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(900, 650);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("3D Rotating Cube with Transformations");

    glClearColor(0.08f, 0.08f, 0.12f, 1);

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(16, update, 0);

    glutMainLoop();

    return 0;
}