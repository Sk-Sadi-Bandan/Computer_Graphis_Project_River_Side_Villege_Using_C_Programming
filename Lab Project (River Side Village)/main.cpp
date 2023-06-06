#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdbool.h>
#include<cmath>
#include<stdlib.h>

int windowWidth = 1000;
int windowHeight = 600;

void circle(float r, int x_center, int y_center)
{
    int deg =0;
    float x,y,theta;

    glBegin(GL_POLYGON);

    while(deg<360)
    {
        theta = (deg*M_PI)/180;
        x = x_center + r* cos(theta);
        y = y_center + r* sin(theta);
        deg++;

        glVertex2d(x,y);
    }
    glEnd();
}

float plain_x= 0.0, sun_y= 0.0, cloud_x= 0.0, boat_x= 0.0, boat_y1= 0.0;
int angle = 0;
int r = 36, g= 173, b= 255;

bool moving = true;
bool moving1 = true;

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 's':
    {
        moving = false;
        break;
        glutPostRedisplay();
    }

    case 'a':
    {
        moving = true;
        break;
        glutPostRedisplay();
    }

    case 'x':
    {
        angle= 180;
        moving = false;
        glutPostRedisplay();
        break;
    }

    case 'c':
    {
        angle= 0;
        moving = true;
        glutPostRedisplay();
        break;
    }

    case 'd':
    {
        r =36;
        g=173;
        b=255;
        moving1= true;
        glutPostRedisplay();
        break;
    }

    case 'n':
    {
        r =9;
        g=16;
        b=54;
        moving1= false;
        glutPostRedisplay();
        break;
    }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

//draw sky
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(r,g, b);
    glVertex2i(0,60);
    glVertex2i(0,100);
    glVertex2i(130,100);
    glVertex2i(130,60);
    glEnd();

//sun
    glPushMatrix();
    glTranslatef(0.0, sun_y, 0.0f);
    glColor3ub(253,185,101);
    circle(7,40,80);
    glPopMatrix();

//cloud1
    glPushMatrix();
    glTranslatef(cloud_x, 0.0, 0.0);
    glColor3ub(255,255,255);
    circle(5,17,88);
    circle(6,22,88);
    circle(5,27,88);

    glPushMatrix();
    glTranslatef(40.0, 5.0, 0.0);
    glColor3ub(255,255,255);
    circle(5,17,88);
    circle(6,22,88);
    circle(5,27,88);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(25.0, -5.0, 0.0);
    glColor3ub(255,255,255);
    circle(5,17,88);
    circle(6,22,88);
    circle(5,27,88);
    glPopMatrix();

    glPopMatrix();

// draw ground
    glBegin(GL_POLYGON);
    glColor3ub(24,229,22);
    glVertex2i(0,15);
    glVertex2i(0,60);
    glVertex2i(130,60);
    glVertex2i(130,44);
    glEnd();

//draw river
    glBegin(GL_POLYGON);
    glColor3ub(196,254,251);
    glVertex2i(0,0);
    glVertex2i(0,15);
    glVertex2i(130,44);
    glVertex2i(130,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2i(65,30);
    glVertex2i(65,11);

    glVertex2i(70,31);
    glVertex2i(70,11);

    glVertex2i(65,25);
    glVertex2i(70,25);

    glVertex2i(65,20);
    glVertex2i(70,20);

    glVertex2i(65,15);
    glVertex2i(70,15);

    glVertex2i(65,11);
    glVertex2i(70,11);

    glEnd();

//boat
    glPushMatrix();
    glTranslatef(boat_x, 0.0, 0.0);
    glTranslatef(40, 5, 0);
    glRotatef(angle, 0, 0, 1);
    glTranslatef(-40, -5, 0);
    glBegin(GL_QUADS);
    glColor3ub(0,0,154);
    glVertex2i(33,5);
    glVertex2i(30,10);
    glVertex2i(50,10);
    glVertex2i(47,5);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2i(34,10);
    glVertex2i(34,15);
    glVertex2i(33,10);
    glVertex2i(33,15);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(200,100,114);
    glVertex2i(32,10);
    glVertex2i(40,15);
    glVertex2i(48,10);
    glEnd();

    glPopMatrix();

//hill
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 174, 91);
    glVertex2i(0,60);
    glVertex2i(9,70);
    glVertex2i(20,60);

    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 174, 91);
    glVertex2i(15,60);
    glVertex2i(26,73);
    glVertex2i(38,60);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 174, 91);
    glVertex2i(30,60);
    glVertex2i(44,75);
    glVertex2i(59,60);

    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 174, 91);
    glVertex2i(51,60);
    glVertex2i(64,78);
    glVertex2i(79,60);

    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 174, 91);
    glVertex2i(65,60);
    glVertex2i(83,73);
    glVertex2i(97,60);

    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 174, 91);
    glVertex2i(85,60);
    glVertex2i(99,75);
    glVertex2i(119,60);

    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 174, 91);
    glVertex2i(102,60);
    glVertex2i(120,72);
    glVertex2i(130,60);

    glEnd();

//draw 2nd house
    glPushMatrix();
    glTranslatef(15.0f, 5.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(116,58,0);
    glVertex2i(7,50);
    glVertex2i(10,57);
    glVertex2i(30,57);
    glVertex2i(33,50);
    glEnd();

    glColor3ub(255,43,0);
    glRecti(10,35,30,50);

    glColor3ub(0,95,95);
    glRecti(12,40,15,44);

    glColor3ub(0,95,95);
    glRecti(25,40,28,44);

    glColor3ub(0,95,95);
    glRecti(17,35,23,46);

    glPopMatrix();

//draw 1st house
    glBegin(GL_QUADS);
    glColor3ub(116,58,0);
    glVertex2i(7,50);
    glVertex2i(10,57);
    glVertex2i(30,57);
    glVertex2i(33,50);
    glEnd();

    glColor3ub(250, 102, 7);
    glRecti(10,35,30,50);

    glColor3ub(0,95,95);
    glRecti(12,40,15,44);

    glColor3ub(0,95,95);
    glRecti(25,40,28,44);

    glColor3ub(0,95,95);
    glRecti(17,35,23,46);

//draw 3rd house
    glPushMatrix();
    glTranslatef(60.0f, 5.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(116,58,0);
    glVertex2i(7,50);
    glVertex2i(10,57);
    glVertex2i(30,57);
    glVertex2i(33,50);
    glEnd();

    glColor3ub(0,199,129);
    glRecti(10,35,30,50);

    glColor3ub(0,95,95);
    glRecti(12,40,15,44);

    glColor3ub(0,95,95);
    glRecti(25,40,28,44);

    glColor3ub(0,95,95);
    glRecti(17,35,23,46);

    glPopMatrix();

//Tree 1st
    glColor3ub(82, 54, 36);
    glRecti(53, 41, 55, 50);

    glBegin(GL_POLYGON);
    glColor3ub(0,132,0);
    glVertex2i(53,50);
    glVertex2i(50,50);
    glVertex2i(52,53);
    glVertex2i(50,53);
    glVertex2i(52,55);
    glVertex2i(50,55);
    glVertex2i(54,63);

    glVertex2i(58,55);
    glVertex2i(56,55);
    glVertex2i(58,53);
    glVertex2i(56,53);
    glVertex2i(58,50);
    glVertex2i(55,50);
    glEnd();

//Tree 2nd
    glPushMatrix();
    glTranslatef(8.0f, 5.0f, 0.0f);

    glColor3ub(82, 54, 36);
    glRecti(53, 41, 55, 50);

    glBegin(GL_POLYGON);
    glColor3ub(0,132,0);
    glVertex2i(53,50);
    glVertex2i(50,50);
    glVertex2i(52,53);
    glVertex2i(50,53);
    glVertex2i(52,55);
    glVertex2i(50,55);
    glVertex2i(54,63);

    glVertex2i(58,55);
    glVertex2i(56,55);
    glVertex2i(58,53);
    glVertex2i(56,53);
    glVertex2i(58,50);
    glVertex2i(55,50);
    glEnd();

    glPopMatrix();

//Tree 3rd
    glPushMatrix();
    glTranslatef(50.0f, 3.0f, 0.0f);

    glColor3ub(82, 54, 36);
    glRecti(53, 41, 55, 50);

    glBegin(GL_POLYGON);
    glColor3ub(0,132,0);
    glVertex2i(53,50);
    glVertex2i(50,50);
    glVertex2i(52,53);
    glVertex2i(50,53);
    glVertex2i(52,55);
    glVertex2i(50,55);
    glVertex2i(54,63);

    glVertex2i(58,55);
    glVertex2i(56,55);
    glVertex2i(58,53);
    glVertex2i(56,53);
    glVertex2i(58,50);
    glVertex2i(55,50);
    glEnd();
    glPopMatrix();

//Tree 4th
    glPushMatrix();
    glTranslatef(60.0f, 3.0f, 0.0f);

    glColor3ub(82, 54, 36);
    glRecti(53, 41, 55, 50);

    glBegin(GL_POLYGON);
    glColor3ub(0,132,0);
    glVertex2i(53,50);
    glVertex2i(50,50);
    glVertex2i(52,53);
    glVertex2i(50,53);
    glVertex2i(52,55);
    glVertex2i(50,55);
    glVertex2i(54,63);

    glVertex2i(58,55);
    glVertex2i(56,55);
    glVertex2i(58,53);
    glVertex2i(56,53);
    glVertex2i(58,50);
    glVertex2i(55,50);
    glEnd();
    glPopMatrix();

    //Tree 5th
    glPushMatrix();
    glTranslatef(70.0f, 3.0f, 0.0f);

    glColor3ub(82, 54, 36);
    glRecti(53, 41, 55, 50);

    glBegin(GL_POLYGON);
    glColor3ub(0,132,0);
    glVertex2i(53,50);
    glVertex2i(50,50);
    glVertex2i(52,53);
    glVertex2i(50,53);
    glVertex2i(52,55);
    glVertex2i(50,55);
    glVertex2i(54,63);

    glVertex2i(58,55);
    glVertex2i(56,55);
    glVertex2i(58,53);
    glVertex2i(56,53);
    glVertex2i(58,50);
    glVertex2i(55,50);
    glEnd();
    glPopMatrix();

    glFlush();
}

void sun(int value)
{
    if(moving1)
    {
        sun_y += .05;
        {
            if (sun_y > 30)
            {
                sun_y = -20;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, sun, 0);
}

void cloud(int value)
{
    cloud_x += .05;
    {
        if (cloud_x > 120.0)
        {
            cloud_x  = -65.0;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(5, cloud, 0);
}

void boat(int value)
{
    if(moving)
    {
        boat_x += .1;
        {
            if (boat_x > 100)
            {
                boat_x = -50;
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(25, boat, 0);
}


void init()
{
    glClearColor(36, 173, 255, 0);
    gluOrtho2D(0.0f, 130.0f, 0.0f, 100.0f);

}

void reshape(int width, int height) {
    windowWidth = width;
    windowHeight = height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    if(width != 1200 || height != 600) {
        glutPositionWindow(100, 100);
        glutReshapeWindow(1200, 600);
        glutPostRedisplay();
    }
    glMatrixMode(GL_MODELVIEW);

}

//coand line argument and pointer argument
int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(300, 100);
    glutInitWindowSize(1200, 600);
    glutCreateWindow("PROJECT");
    glutReshapeFunc(reshape);
    //display callback Function
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, sun, 0);
    glutTimerFunc(0, cloud, 0);
    glutTimerFunc(0, boat, 0);
    //init();
    //Add a timer
    glutMainLoop();

    return 0;
}
