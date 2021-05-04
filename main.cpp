#include <GL/glut.h>

GLfloat T = 0;

void Spin()
{
    T = T + 1;
    if (T > 360)
        T = 0;
    glutPostRedisplay();
}

void MyInit()
{
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
}

// Fourth create faces
void Face(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[])
{
    glBegin(GL_POLYGON);
        glVertex3fv(A);
        glVertex3fv(B);
        glVertex3fv(C);
        glVertex3fv(D);
    glEnd();
}


// Second to make cube we need faces
void Cube(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[], GLfloat V5[], GLfloat V6[], GLfloat V7[])
{
    // Third call face function
    glColor3f(1,0,0);
    Face(V0,V1,V2,V3);  // Front

    glColor3f(0,1,0);
    Face(V4,V5,V6,V7);  // Back

    glColor3f(1,1,0);
    Face(V0,V3,V7,V4);  // Left

    glColor3f(0,1,1);
    Face(V1,V2,V6,V5);  // Right

    glColor3f(0,0,1);
    Face(V0,V1,V5,V4);  // Top

    glColor3f(1,1,1);
    Face(V3,V2,V6,V7);  // Bottom
}

void display(void)
{
    // Initialize all coordinates
    GLfloat V[8][3] = {
                        {-0.5,  0.5,  0.5},
                        { 0.5,  0.5,  0.5},
                        { 0.5, -0.5,  0.5},
                        {-0.5, -0.5,  0.5},

                        {-0.5,  0.5,  -0.5},
                        { 0.5,  0.5,  -0.5},
                        { 0.5, -0.5,  -0.5},
                        {-0.5, -0.5,  -0.5},
                      };

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glRotatef(T,1,1,0);

    // First call cube function
    Cube(V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);

    // when we model 3d object we use this instead of "glFlush()"
    glutSwapBuffers();
}


/* Program entry point */
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(250,50);
    glutInitWindowSize(600,600);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    MyInit();
    glutDisplayFunc(display);
    glutIdleFunc(Spin);
    glutMainLoop();
    return 0;
}
