#include <iostream>

#include <cstdlib>
#include <ctime>

#include <GL/glut.h>

#include "defines.h"

using namespace std;

float spaceColorRed;
float spaceColorGreen;
float spaceColorBlue;
float cubeColorRed;
float cubeColorGreen;
float cubeColorBlue;
GLfloat X = 0.0f; // Translate screen to x direction (left or right)
GLfloat Y = 0.0f; // Translate screen to y direction (up or down)
GLfloat Z = 0.0f; // Translate screen to z direction (zoom in or out)
GLfloat rotX = 0.0f; // Rotate screen on x axis
GLfloat rotY = 0.0f; // Rotate screen on y axis
GLfloat rotZ = 0.0f; // Rotate screen on z axis
GLfloat rotLx = 0.0f; // Translate screen by using the glulookAt function (left or right)
GLfloat rotLy = 0.0f; // Translate screen by using the glulookAt function (up or down)
GLfloat rotLz = 0.0f; // Translate screen by using the glulookAt function (zoom in or out)
bool gridFlag = false; // If True the grid is drawn
bool lightFlag[8] = {false, false, false, false, false, false, false, false}; // If True the lights i is ON
int lightCounter = 1;
bool sphereFFlag = true;
bool sphereSFlag = false;
bool snakeFlag = false;

void createAxis()
{
    glBegin ( GL_LINES );

    glColor3f ( 0.0, 1.0, 0.0 );

    glVertex3f ( 0, 0, 0 );
    glVertex3f ( 10, 0, 0 );

    glColor3f ( 1.0, 0.0, 0.0 );

    glVertex3f ( 0, 0, 0 );
    glVertex3f ( 0, 10, 0 );

    glColor3f ( 0.0, 0.0, 1.0 );

    glVertex3f ( 0, 0, 0 );
    glVertex3f ( 0, 0, 10 );

    glEnd();

    glEnable ( GL_LINE_STIPPLE );

    glLineStipple ( 1, 0x0101 );

    glBegin ( GL_LINES );

    glColor3f ( 0.0, 1.0, 0.0 );

    glVertex3f ( -10, 0, 0 );
    glVertex3f ( 0, 0, 0 );

    glColor3f ( 1.0, 0.0, 0.0 );

    glVertex3f ( 0, 0, 0 );
    glVertex3f ( 0, -10, 0 );

    glColor3f ( 0.0, 0.0, 1.0 );

    glVertex3f ( 0, 0, 0 );
    glVertex3f ( 0, 0, -10 );

    glEnd();

    glDisable ( GL_LINE_STIPPLE );
}



void createLight ( int i )
{
    switch ( i )
    {
        case TOP_BACK_LEFT:
        {
            GLfloat light_color1[] = {1.0f, 1.0f, 1.0f, 1.0f};
            GLfloat light_pos1[] = { -grid_size / 2.0 + 1.0, grid_size / 2.0 - 1.0, grid_size / 2.0 - 1.0, 0.0f};
            glLightfv ( GL_LIGHT1, GL_DIFFUSE, light_color1 );
            glLightfv ( GL_LIGHT1, GL_POSITION, light_pos1 );

            glPushMatrix();
            glTranslatef ( -grid_size / 2.0 + 1.0, grid_size / 2.0 - 1.0, grid_size / 2.0 - 1.0 );
            glColor3f ( 1.0, 1.0, 1.0 );
            glutSolidSphere ( 0.3, 20, 20 );
            glPopMatrix();

            glEnable ( GL_LIGHT1 );
            break;
        }

        case TOP_BACK_RIGHT:
        {
            GLfloat light_color2[] = {1.0f, 1.0f, 1.0f, 1.0f};
            GLfloat light_pos2[] = {grid_size / 2.0 - 1.0, grid_size / 2.0 - 1.0, grid_size / 2.0 - 1.0, 0.0f};
            glLightfv ( GL_LIGHT2, GL_DIFFUSE, light_color2 );
            glLightfv ( GL_LIGHT2, GL_POSITION, light_pos2 );

            glPushMatrix();
            glTranslatef ( grid_size / 2.0 - 1.0, grid_size / 2.0 - 1.0, grid_size / 2.0 - 1.0 );
            glColor3f ( 1.0, 1.0, 1.0 );
            glutSolidSphere ( 0.3, 20, 20 );
            glPopMatrix();

            glEnable ( GL_LIGHT2 );
            break;
        }

        case TOP_FRONT_LEFT:
        {
            GLfloat light_color3[] = {1.0f, 1.0f, 1.0f, 1.0f};
            GLfloat light_pos3[] = { -grid_size / 2.0 + 1.0, grid_size / 2.0 - 1.0, -grid_size / 2.0 + 1.0, 0.0f};
            glLightfv ( GL_LIGHT3, GL_DIFFUSE, light_color3 );
            glLightfv ( GL_LIGHT3, GL_POSITION, light_pos3 );

            glPushMatrix();
            glTranslatef ( -grid_size / 2.0 + 1.0, grid_size / 2.0 - 1.0, -grid_size / 2.0 + 1.0 );
            glColor3f ( 1.0, 1.0, 1.0 );
            glutSolidSphere ( 0.3, 20, 20 );
            glPopMatrix();

            glEnable ( GL_LIGHT3 );
            break;
        }

        case TOP_FRONT_RIGHT:
        {
            GLfloat light_color4[] = {1.0f, 1.0f, 1.0f, 1.0f};
            GLfloat light_pos4[] = {grid_size / 2.0 - 1.0, grid_size / 2.0 - 1.0, -grid_size / 2.0 + 1.0, 0.0f};
            glLightfv ( GL_LIGHT4, GL_DIFFUSE, light_color4 );
            glLightfv ( GL_LIGHT4, GL_POSITION, light_pos4 );

            glPushMatrix();
            glTranslatef ( grid_size / 2.0 - 1.0, grid_size / 2.0 - 1.0, -grid_size / 2.0 + 1.0 );
            glColor3f ( 1.0, 1.0, 1.0 );
            glutSolidSphere ( 0.3, 20, 20 );
            glPopMatrix();

            glEnable ( GL_LIGHT4 );
            break;
        }

        case DOWN_BACK_LEFT:
        {
            GLfloat light_color5[] = {1.0f, 1.0f, 1.0f, 1.0f};
            GLfloat light_pos5[] = { -grid_size / 2.0 + 1.0, -grid_size / 2.0 + 1.0, grid_size / 2.0 - 1.0, 0.0f};
            glLightfv ( GL_LIGHT5, GL_DIFFUSE, light_color5 );
            glLightfv ( GL_LIGHT5, GL_POSITION, light_pos5 );

            glPushMatrix();
            glTranslatef ( -grid_size / 2.0 + 1.0, -grid_size / 2.0 + 1.0, grid_size / 2.0 - 1.0 );
            glColor3f ( 1.0, 1.0, 1.0 );
            glutSolidSphere ( 0.3, 20, 20 );
            glPopMatrix();

            glEnable ( GL_LIGHT5 );
            break;
        }

        case DOWN_BACK_RIGHT:
        {
            GLfloat light_color6[] = {1.0f, 1.0f, 1.0f, 1.0f};
            GLfloat light_pos6[] = {grid_size / 2.0 - 1.0, -grid_size / 2.0 + 1.0, grid_size / 2.0 - 1.0, 0.0f};
            glLightfv ( GL_LIGHT6, GL_DIFFUSE, light_color6 );
            glLightfv ( GL_LIGHT6, GL_POSITION, light_pos6 );

            glPushMatrix();
            glTranslatef ( grid_size / 2.0 - 1.0, -grid_size / 2.0 + 1.0, grid_size / 2.0 - 1.0 );
            glColor3f ( 1.0, 1.0, 1.0 );
            glutSolidSphere ( 0.3, 20, 20 );
            glPopMatrix();

            glEnable ( GL_LIGHT6 );
            break;
        }

        case DOWN_FRONT_LEFT:
        {
            GLfloat light_color7[] = {1.0f, 1.0f, 1.0f, 1.0f};
            GLfloat light_pos7[] = { -grid_size / 2.0 + 1.0, -grid_size / 2.0 + 1.0, -grid_size / 2.0 + 1.0, 0.0f};
            glLightfv ( GL_LIGHT7, GL_DIFFUSE, light_color7 );
            glLightfv ( GL_LIGHT7, GL_POSITION, light_pos7 );

            glPushMatrix();
            glTranslatef ( -grid_size / 2.0 + 1.0, -grid_size / 2.0 + 1.0, -grid_size / 2.0 + 1.0 );
            glColor3f ( 1.0, 1.0, 1.0 );
            glutSolidSphere ( 0.3, 20, 20 );
            glPopMatrix();

            glEnable ( GL_LIGHT7 );
            break;
        }

        case DOWN_FRONT_RIGHT:
        {
            GLfloat light_color8[] = {1.0f, 1.0f, 1.0f, 1.0f};
            GLfloat light_pos8[] = {grid_size / 2.0 - 1.0, -grid_size / 2.0 + 1.0, -grid_size / 2.0 + 1.0, 0.0f};

            glPushMatrix();
            glTranslatef ( grid_size / 2.0 - 1.0, -grid_size / 2.0 + 1.0, -grid_size / 2.0 + 1.0 );
            glColor3f ( 1.0, 1.0, 1.0 );
            //glutSolidSphere(0.1, 20, 20);
            glPopMatrix();

            //glEnable(GL_LIGHT8);
            break;
        }

        default:
        {
            for ( int i = TOP_BACK_LEFT; i <= DOWN_FRONT_RIGHT; i++ )
                glDisable ( GL_LIGHT1 + i );

            break;
        }
    }
}



void update ( int value )
{
    glutPostRedisplay();

    glutTimerFunc ( timer, update, 0 );
}

int randomNumber ( int low, int high )
{
    return ( rand() % ( high - low + 1 ) ) + low;
}

float randomFNumber()
{
    return ( ( float ) rand() / RAND_MAX );
}

void init ( void )
{
    srand ( ( unsigned ) time ( 0 ) );
    glClearColor ( 0.0, 0.0, 0.0, 0.0 );
    glShadeModel ( GL_SMOOTH );

    GLfloat ambient_color[] = {0.1f, 0.1f, 0.1f, 1.0f};
    glLightModelfv ( GL_LIGHT_MODEL_AMBIENT, ambient_color );

    GLfloat light_color0[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light_pos0[] = {rotLx, rotLy, 15.0f + rotLz, 0.0f};

    glLightfv ( GL_LIGHT0, GL_DIFFUSE, light_color0 );
    glLightfv ( GL_LIGHT0, GL_POSITION, light_pos0 );

    glEnable ( GL_LIGHT0 );

    spaceColorRed = 0.1;
    spaceColorGreen = 0.5;
    spaceColorBlue = 0.1;

    cubeColorRed = randomFNumber();
    cubeColorGreen = randomFNumber();
    cubeColorBlue = randomFNumber();

    glEnable ( GL_LINE_SMOOTH );
    glEnable ( GL_DEPTH_TEST );
    glEnable ( GL_COLOR_MATERIAL );
    glEnable ( GL_LIGHTING );
    glEnable ( GL_NORMALIZE );
    glHint ( GL_LINE_SMOOTH_HINT, GL_NICEST );


}

void createSphere ( sphere* s )
{
    if ( sphereFFlag )
    {
        glColor3f ( randomFNumber(), randomFNumber(), randomFNumber() );
        s->setRandomCoord();
        sphereFFlag = false;
    }

    glPushMatrix();
    glTranslatef ( s->getPosition().x, s->getPosition().y, s->getPosition().z );
    glColor3f ( 1.0, 0.0, 0.0 );
    glutSolidSphere ( 1.0, 20, 20 );
    glPopMatrix();
    s->move();
}

void createGrid ( int size )
{
    glColor3f ( 1.0, 1.0, 1.0 );

    for ( float i = -grid_size / 2.0; i < grid_size / 2.0; i++ )
    {
        for ( float j = -grid_size / 2.0; j < grid_size / 2.0; j++ )
        {
            for ( float k = -grid_size / 2.0; k < grid_size / 2.0; k++ )
            {
                glPushMatrix();
                glTranslatef ( i, j, k );
                glutWireCube ( size );
                glPopMatrix();
            }
        }
    }
}


void createSpace()
{

    glBegin ( GL_QUADS );

    glColor3f ( spaceColorRed, spaceColorGreen, spaceColorBlue );

    //Top

    glNormal3f ( 1.0f, -1.0f, 1.0f );
    glVertex3f ( -grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5 );
    glNormal3f ( -1.0f, -1.0f, 1.0f );
    glVertex3f ( grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5 );
    glNormal3f ( -1.0f, -1.0f, -1.0f );
    glVertex3f ( grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5 );
    glNormal3f ( 1.0f, -1.0f, -1.0f );
    glVertex3f ( -grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5 );

    //Back

    glNormal3f ( 1.0, -1.0, 1.0 );
    glVertex3f ( -grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5 );
    glNormal3f ( -1.0, -1.0, 1.0 );
    glVertex3f ( grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5 );
    glNormal3f ( -1.0, 1.0, 1.0 );
    glVertex3f ( grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5 );
    glNormal3f ( 1.0, 1.0, 1.0 );
    glVertex3f ( -grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5 );

    //Left

    glNormal3f ( 1.0, -1.0, 1.0 );
    glVertex3f ( -grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5 );
    glNormal3f ( 1.0, 1.0, 1.0 );
    glVertex3f ( -grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5 );
    glNormal3f ( 1.0, 1.0, -1.0 );
    glVertex3f ( -grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5 );
    glNormal3f ( 1.0, -1.0, -1.0 );
    glVertex3f ( -grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5 );

    //Right

    glNormal3f ( -1.0, -1.0, 1.0 );
    glVertex3f ( grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5 );
    glNormal3f ( -1.0, 1.0, 1.0 );
    glVertex3f ( grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5 );
    glNormal3f ( -1.0, 1.0, -1.0 );
    glVertex3f ( grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5 );
    glNormal3f ( -1.0, -1.0, -1.0 );
    glVertex3f ( grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5 );

    //Front

    glNormal3f ( 1.0, -1.0, -1.0 );
    glVertex3f ( -grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5 );
    glNormal3f ( -1.0, -1.0, -1.0 );
    glVertex3f ( grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5 );
    glNormal3f ( -1.0, 1.0, -1.0 );
    glVertex3f ( grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5 );
    glNormal3f ( 1.0, 1.0, -1.0 );
    glVertex3f ( -grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5 );


    //Bottom

    glNormal3f ( 1.0, 1.0, 1.0 );
    glVertex3f ( -grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5 );
    glNormal3f ( -1.0, 1.0, 1.0 );
    glVertex3f ( grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5 );
    glNormal3f ( -1.0, 1.0, -1.0 );
    glVertex3f ( grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5 );
    glNormal3f ( 1.0, 1.0, -1.0 );
    glVertex3f ( -grid_size / 2.0 - 0.5, -grid_size / 2.0 - 0.5, grid_size / 2.0 - 0.5 );

    glEnd();
}


void drawSnake()
{
    int x, y, z;

    for ( int i = 0; i < snake_num; i++ )
    {
        for ( int j = 0; j < 2 * snake_array[i].getSize() - 1; j++ )
        {
            x = snake_array[i].getCoord() [j].x;
            y = snake_array[i].getCoord() [j].y;
            z = snake_array[i].getCoord() [j].z;

            if ( j == 0 )
            {
                glRasterPos3f ( x, y + 1, z );
                glutBitmapCharacter ( GLUT_BITMAP_HELVETICA_18, 48 + i + 1 );
            }

            glPushMatrix();
            glTranslatef ( x, y, z );

            if ( j % 2 != 1 )
            {
                glColor3f ( randomFNumber(), randomFNumber(), randomFNumber() );
                //glutSolidCube(1);
                glBegin ( GL_QUADS );
                //Top
                glNormal3f ( -1.0f, 1.0f, -1.0f );
                glVertex3f ( -0.5, 0.5, -0.5 );
                glNormal3f ( 1.0f, 1.0f, -1.0f );
                glVertex3f ( 0.5, 0.5, -0.5 );
                glNormal3f ( 1.0f, 1.0f, 1.0f );
                glVertex3f ( 0.5, 0.5, 0.5 );
                glNormal3f ( -1.0f, 1.0f, 1.0f );
                glVertex3f ( -0.5, 0.5, 0.5 );

                //Back

                glNormal3f ( -1.0, 1.0, -1.0 );
                glVertex3f ( -0.5, 0.5, -0.5 );
                glNormal3f ( 1.0, 1.0, -1.0 );
                glVertex3f ( 0.5, 0.5, -0.5 );
                glNormal3f ( 1.0, -1.0, -1.0 );
                glVertex3f ( 0.5, -0.5, -0.5 );
                glNormal3f ( -1.0, -1.0, -1.0 );
                glVertex3f ( -0.5, -0.5, -0.5 );

                //Left

                glNormal3f ( -1.0, 1.0, -1.0 );
                glVertex3f ( -0.5, 0.5, -0.5 );
                glNormal3f ( -1.0, -1.0, -1.0 );
                glVertex3f ( -0.5, -0.5, -0.5 );
                glNormal3f ( -1.0, -1.0, 1.0 );
                glVertex3f ( -0.5, -0.5, 0.5 );
                glNormal3f ( -1.0, 1.0, 1.0 );
                glVertex3f ( -0.5, 0.5, 0.5 );

                //Right

                glNormal3f ( 1.0, 1.0, -1.0 );
                glVertex3f ( 0.5, 0.5, -0.5 );
                glNormal3f ( 1.0, -1.0, -1.0 );
                glVertex3f ( 0.5, -0.5, -0.5 );
                glNormal3f ( 1.0, -1.0, 1.0 );
                glVertex3f ( 0.5, -0.5, 0.5 );
                glNormal3f ( 1.0, 1.0, 1.0 );
                glVertex3f ( 0.5, 0.5, 0.5 );

                //Front

                glNormal3f ( -1.0, 1.0, 1.0 );
                glVertex3f ( -0.5, 0.5, 0.5 );
                glNormal3f ( 1.0, 1.0, 1.0 );
                glVertex3f ( 0.5, 0.5, 0.5 );
                glNormal3f ( 1.0, -1.0, 1.0 );
                glVertex3f ( 0.5, -0.5, 0.5 );
                glNormal3f ( -1.0, -1.0, 1.0 );
                glVertex3f ( -0.5, -0.5, 0.5 );

                //Bottom

                glNormal3f ( -1.0, -1.0, -1.0 );
                glVertex3f ( -0.5, -0.5, -0.5 );
                glNormal3f ( 1.0, -1.0, -1.0 );
                glVertex3f ( 0.5, -0.5, -0.5 );
                glNormal3f ( 1.0, -1.0, 1.0 );
                glVertex3f ( 0.5, -0.5, 0.5 );
                glNormal3f ( 1.0, 1.0, -1.0 );
                glVertex3f ( -0.5, -0.5, 0.5 );
                glEnd();
            }
            else
            {
                glColor3f ( 0.75, 0.5, 1.0 );
                glutSolidSphere ( 0.5, 20, 20 );
            }

            glPopMatrix();
        }

        if ( snakeFlag )
            snake_array[i].random_move();
    }
}


void display ( void )
{

    glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glPushMatrix();
    glRotatef ( rotX, 1.0, 0.0, 0.0 );
    glRotatef ( rotY, 0.0, 1.0, 0.0 );
    glRotatef ( rotZ, 0.0, 0.0, 1.0 );
    glTranslatef ( X, Y, Z );

    createSpace();
    createAxis();

    for ( int i = TOP_BACK_LEFT; i <= DOWN_FRONT_RIGHT; i++ )
    {
        if ( lightFlag[i] == true )
        {
            createLight ( i );
        }
        else if ( lightCounter == 1 )
        {
            createLight ( -1 );

            break;
        }
    }

    if ( gridFlag )
        createGrid ( 1 );

    if ( sphereSFlag )
        createSphere ( &hugeSphere );

    drawSnake();

    glPopMatrix();

    glutSwapBuffers();
}


void reshape ( int w, int h )
{
    glViewport ( 0, 0, ( GLsizei ) w, ( GLsizei ) h );
    glMatrixMode ( GL_PROJECTION );
    glLoadIdentity ();
    gluPerspective ( 75, ( GLfloat ) w / ( GLfloat ) h , 0.10, 100.0 );
    glMatrixMode ( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt ( rotLx, rotLy, 15.0 + rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 );
}


void keyboard ( unsigned char key, int x, int y )
{
    switch ( key )
    {
        case 'x':
            rotX -= 0.5f;
            break;

        case 'X':
            rotX += 0.5f;
            break;

        case 'y':
            rotY -= 0.5f;
            break;

        case 'Y':
            rotY += 0.5f;
            break;

        case 'z':
            rotZ -= 0.5f;
            break;

        case 'Z':
            rotZ += 0.5f;
            break;

        case 'j':
            rotLx -= 0.2f;
            glMatrixMode ( GL_MODELVIEW );
            glLoadIdentity();
            gluLookAt ( rotLx, rotLy, 15.0 + rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 );
            break;

        case 'J':
            rotLx += 0.2f;
            glMatrixMode ( GL_MODELVIEW );
            glLoadIdentity();
            gluLookAt ( rotLx, rotLy, 15.0 + rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 );
            break;

        case 'k':
            rotLy -= 0.2f;
            glMatrixMode ( GL_MODELVIEW );
            glLoadIdentity();
            gluLookAt ( rotLx, rotLy, 15.0 + rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 );
            break;

        case 'K':
            rotLy += 0.2f;
            glMatrixMode ( GL_MODELVIEW );
            glLoadIdentity();
            gluLookAt ( rotLx, rotLy, 15.0 + rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 );
            break;

        case 'l':
            if ( rotLz + 14 >= 0 )
                rotLz -= 0.2f;

            glMatrixMode ( GL_MODELVIEW );
            glLoadIdentity();
            gluLookAt ( rotLx, rotLy, 15.0 + rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 );
            break;

        case 'L':
            rotLz += 0.2f;
            glMatrixMode ( GL_MODELVIEW );
            glLoadIdentity();
            gluLookAt ( rotLx, rotLy, 15.0 + rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 );
            break;

        case 'e':
        case 'E':
            X = Y = 0.0f;
            Z = 0.0f;
            rotX = 0.0f;
            rotY = 0.0f;
            rotZ = 0.0f;
            rotLx = 0.0f;
            rotLy = 0.0f;
            rotLz = 0.0f;
            glMatrixMode ( GL_MODELVIEW );
            glLoadIdentity();
            gluLookAt ( rotLx, rotLy, 15.0f + rotLz, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f );
            break;

        case 'g':
            gridFlag = !gridFlag;
            break;

        case '+':
            timer -= 100;
            break;

        case '-':
            timer += 100;
            break;

        case 'q':
        {
            if ( lightCounter == 8 )
                break;

            int random = randomNumber ( 0, 7 );

            while ( lightFlag[random] == true )
                random = randomNumber ( TOP_BACK_LEFT, DOWN_FRONT_RIGHT );

            lightCounter++;
            lightFlag[random] = true;
            break;
        }

        case 'Q':
        {
            for ( int i = TOP_BACK_LEFT; i <= DOWN_FRONT_RIGHT; i++ )
                lightFlag[i] = false;

            lightCounter = 1;
            break;
        }

        case 'o':
        case 'O':
        {
            sphereSFlag = true;
            break;
        }

        case ' ':
        {
            snakeFlag = !snakeFlag;
            break;
        }
    }

    glutPostRedisplay();
}


void specialKey ( int key, int x, int y )
{
    switch ( key )
    {
        case GLUT_KEY_LEFT:
        {
            X -= 0.1f;
            break;
        }

        case GLUT_KEY_RIGHT:
        {
            X += 0.1f;
            break;
        }

        case GLUT_KEY_UP:
        {
            Y += 0.1f;
            break;
        }

        case GLUT_KEY_DOWN:
        {
            Y -= 0.1f;
            break;
        }

        case GLUT_KEY_PAGE_UP:
        {
            Z -= 0.1f;
            break;
        }

        case GLUT_KEY_PAGE_DOWN:
        {
            Z += 0.1f;
            break;
        }
    }

    glutPostRedisplay();
}


