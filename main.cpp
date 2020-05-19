#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define CIRCLE_RADIUS 0.15 f
# define PI 3.14159265358979323846
int eggs_caught = 0, missed_eggs = 0, level_count = 1, points = 0, day_mode = 1, stars = 0, egg_xc, egg_yc,duck_animation = 0,basket_x, basket_y,a = 600, b = 650,s = 0,dropped_eggs = 0,speed_1 = 2, speed_2 = 2.2, speed_3 = 2.5, speed_4 = 3,w = 48, h = 48, t = 10, e = 9, g = 12;
float duck_xposition = 40, duck_xposition1 = 180,duck_xposition2 = 320,duck_xposition3 = 460,duck_xposition4 = 600,duck_xposition5 = 740,duck_xposition6 = 880;
GLfloat spin = 0.0;
float cloud_xposition = 100, cloud_xposition2 = 420;
void myinit();
void start_screen(int, int);
void cloud1();
void egg();
void basket(int, int);
void duck(float, float);
void print_score();
void egg_start();
void color();
void score();
void display(void);
void basket_set(int, int);
void myReshape(int, int);
void keys(unsigned char, int, int);
void menu(int);
void tree1(void);
void bushes(void);
void mountain(void);
void hill_big()
{
    glPushMatrix();
    glTranslated(250,78,0);
    glBegin(GL_POLYGON);
    glColor3f(0.627, 0.322, 0.176);
    if(day_mode != 1)
        glColor3f(	0.184, 0.310, 0.310);
    glVertex2i(70, 70);
    glVertex2i(200, 225);
    glVertex2i(330, 70);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);
    if(day_mode != 1)
        glColor3f(	0.184, 0.310, 0.310);
    glVertex2i(200, 225);
    glVertex2i(230, 190);
    glVertex2i(220, 180);
    glVertex2i(200, 190);
    glVertex2i(190, 180);
    glVertex2i(170, 190);
    glEnd();
    glPopMatrix();
}
void myinit()
{
    glViewport(0, 0, a, b);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, (GLdouble) a, 0, (GLdouble) b);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}
void start_screen(int i, int j)
{
                int k;
    char cat[4] = "EGG";
    char orr[9] = "Catching";
    char hatch[5] = "Game";
    char start[19] = "Press S to start";
    glColor3f(0, 1, 0);
    glRasterPos2i(150, 320);
    for (k = 0; k < 4; k++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, cat[k]);
    glColor3f(1, 1, 1);
    glRasterPos2i(200, 320);
    for (k = 0; k < 9; k++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, orr[k]);
    glColor3f(1, 0, 0);
    glRasterPos2i(300, 320);
    for (k = 0; k < 5; k++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, hatch[k]);
    glColor3f(1, 1, 0);
    glRasterPos2i(210, 200);
    for (k = 0; k < 19; k++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, start[k]);
    glRasterPos2i(210, 230);
    glColor3f(1, .5, .5);


}

void sun()
{
    float theta;
    GLfloat angle;
    glLineWidth(1.5);
    if(day_mode == 1)
    {
        glColor3f(1.000, 0.498, 0.314);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++)
        {
            theta = i * PI * i / 180;
            glVertex2f(500 + 80 * cos(theta) / 2, 600 + 80 * sin(theta) / 2);
        }

        glEnd();
    }
    else if(day_mode == 0)
    {
        glColor3f(0.961, 0.961, 0.961);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++)
        {
            theta = i * PI * i / 180;
            glVertex2f(100 + 80 * cos(theta) / 2, 600 + 80 * sin(theta) / 2);
        }

        glEnd();
    }

    glFlush();
}
void cloud1()
{
    if(day_mode == 1)
    {
        float theta;

        GLfloat angle;
        glLineWidth(1.5);
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++)
        {
            theta = i * PI * i / 180;
            glVertex2f(cloud_xposition + 50 * cos(theta) / 2, 590 + 50 * sin(theta) / 2);
        }

        glEnd();
        glLineWidth(1.5);
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++)
        {
            theta = i * PI * i / 180;
            glVertex2f(cloud_xposition + 30 + 50 * cos(theta) / 2, 580 + 50 * sin(theta) / 2);
        }
        glEnd();
        glLineWidth(1.5);
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++)
        {
            theta = i * PI * i / 180;
            glVertex2f(cloud_xposition + 40 + 50 * cos(theta) / 2, 600 + 50 * sin(theta) / 2);
        }
        glEnd();
        glLineWidth(1.5);
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++)
        {
            theta = i * PI * i / 180;
            glVertex2f(cloud_xposition + 70 + 50 * cos(theta) / 2, 590 + 50 * sin(theta) / 2);
        }
        cloud_xposition += 1;
        if(cloud_xposition > b)
            cloud_xposition = -80;
        glEnd();
        glFlush();
    }
}
void cloud2()
{
    if(day_mode == 1)
    {
        float theta;
        glLineWidth(1.5);
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++)
        {
            theta = i * PI * i / 180;
            glVertex2f(cloud_xposition2 + 45 * cos(theta) / 2, 540 + 45 * sin(theta) / 2);
        }
        glEnd();
        glLineWidth(1.5);
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++)
        {
            theta = i * PI * i / 180;
            glVertex2f(cloud_xposition2 + 35 + 45 * cos(theta) / 2, 550 + 45 * sin(theta) / 2);
        }

        glEnd();
        glLineWidth(1.5);
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++)
        {
            theta = i * PI * i / 180;
            glVertex2f(cloud_xposition2 + 35 + 45 * cos(theta) / 2, 530 + 45 * sin(theta) / 2);
        }
        glEnd();
        glLineWidth(1.5);
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++)
        {
            theta = i * PI * i / 180;
            glVertex2f(cloud_xposition2 + 70 + 45 * cos(theta) / 2, 540 + 45 * sin(theta) / 2);
        }
        cloud_xposition2 += 0.2;
        if(cloud_xposition2 > b)
            cloud_xposition2 = -80;
        glEnd();
        glFlush();
    }
}

void line(int i, int j)
{

    glBegin(GL_QUADS);
    glColor3f(1.0, .5, 0.5);
    glVertex2f(0.0 + i, 10.0 + j);
    glVertex2f(0.0 + i, 15.0 + j);
    glVertex2f(600.0 + i, 15.0 + j);
    glVertex2f(600.0 + i, 10.0 + j);
    glEnd();
    glFlush();
}

void backk(int i, int j)
{
    if(day_mode == 1)
        glColor3f(0.255, 0.412, 0.882);
    else if(day_mode == 0)
        glColor3f(0.098, 0.098, 0.439);
    glBegin(GL_QUADS);
    glVertex2f(0.0 + i, 0.0 + j);
    glVertex2f(600.0 + i, 0.0 + j);
    glVertex2f(600.0 + i, -500 + j);
    glVertex2f(0.0 + i, -500 + j);
    glEnd();
    if(day_mode == 0)
    {
        glPushMatrix();
        glTranslated(-20,-30,0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(575,653);
        glVertex2f(570,645);
        glVertex2f(580,645);
        glVertex2f(575,642);
        glVertex2f(570,650);
        glVertex2f(580,650);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glTranslated(-100,-140,0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(575,653);
        glVertex2f(570,645);
        glVertex2f(580,645);
        glVertex2f(575,642);
        glVertex2f(570,650);
        glVertex2f(580,650);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glTranslated(-200,-60,0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(575,653);
        glVertex2f(570,645);
        glVertex2f(580,645);
        glVertex2f(575,642);
        glVertex2f(570,650);
        glVertex2f(580,650);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glTranslated(-270,-30,0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(575,653);
        glVertex2f(570,645);
        glVertex2f(580,645);
        glVertex2f(575,642);
        glVertex2f(570,650);
        glVertex2f(580,650);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glTranslated(-200,-300,0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(575,653);
        glVertex2f(570,645);
        glVertex2f(580,645);
        glVertex2f(575,642);
        glVertex2f(570,650);
        glVertex2f(580,650);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glTranslated(-400,-30,0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(575,653);
        glVertex2f(570,645);
        glVertex2f(580,645);
        glVertex2f(575,642);
        glVertex2f(570,650);
        glVertex2f(580,650);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glTranslated(-450,-130,0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(575,653);
        glVertex2f(570,645);
        glVertex2f(580,645);
        glVertex2f(575,642);
        glVertex2f(570,650);
        glVertex2f(580,650);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glTranslated(-350,-70,0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(575,653);
        glVertex2f(570,645);
        glVertex2f(580,645);
        glVertex2f(575,642);
        glVertex2f(570,650);
        glVertex2f(580,650);
        glEnd();
        glPopMatrix();

    }
    glFlush();

}
void ground(int i, int j)
{
    ///Field_Shadow
    glBegin(GL_POLYGON);
    glColor3f(0.000, 1.000, 0.000);
    if(day_mode != 1)
        glColor3f(	0.184, 0.310, 0.310);
    glVertex2i(0, 0);
    glVertex2i(0, 150);
    glVertex2i(600, 150);
    glVertex2i(600, 0);
    glEnd();
    ///Field
    glBegin(GL_POLYGON);
    glColor3f(0.533, 1.293, 0.0);
    if(day_mode != 1)
        glColor3f(	0.184, 0.310, 0.310);
    glVertex2i(0, 130);
    glVertex2i(0, 150);
    glVertex2i(600, 150);
    glVertex2i(600, 120);
    glEnd();
    int grass_xposition = 100,grass_yposition = 50;
    glColor3f(0.180, 0.545, 0.341);
    if(day_mode != 1)
        glColor3f(	0.184, 0.310, 0.310);
    glBegin(GL_TRIANGLES);
    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 10,grass_yposition);
    glVertex2f(grass_xposition + 30,grass_yposition + 50);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition - 20,grass_yposition + 60);
    glVertex2f(grass_xposition + 5,grass_yposition);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 8,grass_yposition);
    glVertex2f(grass_xposition + 2,grass_yposition + 60);
    glEnd();
    grass_xposition = 10,grass_yposition = 10;
    glBegin(GL_TRIANGLES);
    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 10,grass_yposition);
    glVertex2f(grass_xposition + 30,grass_yposition + 50);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition - 20,grass_yposition + 60);
    glVertex2f(grass_xposition + 5,grass_yposition);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 8,grass_yposition);
    glVertex2f(grass_xposition + 2,grass_yposition + 60);
    glEnd();
    grass_xposition = 40,grass_yposition = 70;
    glBegin(GL_TRIANGLES);
    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 10,grass_yposition);
    glVertex2f(grass_xposition + 30,grass_yposition + 50);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition - 20,grass_yposition + 60);
    glVertex2f(grass_xposition + 5,grass_yposition);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 8,grass_yposition);
    glVertex2f(grass_xposition + 2,grass_yposition + 60);
    glEnd();
    grass_xposition = 200,grass_yposition = 70;
    glBegin(GL_TRIANGLES);
    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 10,grass_yposition);
    glVertex2f(grass_xposition + 30,grass_yposition + 50);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition - 20,grass_yposition + 60);
    glVertex2f(grass_xposition + 5,grass_yposition);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 8,grass_yposition);
    glVertex2f(grass_xposition + 2,grass_yposition + 60);
    glEnd();
    grass_xposition = 300,grass_yposition = 40;
    glBegin(GL_TRIANGLES);
    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 10,grass_yposition);
    glVertex2f(grass_xposition + 30,grass_yposition + 50);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition - 20,grass_yposition + 60);
    glVertex2f(grass_xposition + 5,grass_yposition);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 8,grass_yposition);
    glVertex2f(grass_xposition + 2,grass_yposition + 60);
    glEnd();
    grass_xposition = 400,grass_yposition = 20;
    glBegin(GL_TRIANGLES);
    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 10,grass_yposition);
    glVertex2f(grass_xposition + 30,grass_yposition + 50);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition - 20,grass_yposition + 60);
    glVertex2f(grass_xposition + 5,grass_yposition);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 8,grass_yposition);
    glVertex2f(grass_xposition + 2,grass_yposition + 60);
    glEnd();
    grass_xposition = 470,grass_yposition = 100;
    glBegin(GL_TRIANGLES);
    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 10,grass_yposition);
    glVertex2f(grass_xposition + 30,grass_yposition + 50);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition - 20,grass_yposition + 60);
    glVertex2f(grass_xposition + 5,grass_yposition);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 8,grass_yposition);
    glVertex2f(grass_xposition + 2,grass_yposition + 60);
    glEnd();
    grass_xposition = 530,grass_yposition = 80;
    glBegin(GL_TRIANGLES);
    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 10,grass_yposition);
    glVertex2f(grass_xposition + 30,grass_yposition + 50);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition - 20,grass_yposition + 60);
    glVertex2f(grass_xposition + 5,grass_yposition);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 8,grass_yposition);
    glVertex2f(grass_xposition + 2,grass_yposition + 60);
    glEnd();
    glColor3f(0.133, 0.545, 0.133);
    if(day_mode != 1)
        glColor3f(	0.184, 0.310, 0.310);
    grass_xposition = 530,grass_yposition = 30;
    glBegin(GL_TRIANGLES);
    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 25,grass_yposition);
    glVertex2f(grass_xposition + 45,grass_yposition + 30);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition - 35,grass_yposition + 45);
    glVertex2f(grass_xposition + 20,grass_yposition);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 20,grass_yposition);
    glVertex2f(grass_xposition + 18,grass_yposition + 45);
    glEnd();
    grass_xposition = 150,grass_yposition = 150;
    glBegin(GL_TRIANGLES);
    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 25,grass_yposition);
    glVertex2f(grass_xposition + 45,grass_yposition + 30);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition - 35,grass_yposition + 45);
    glVertex2f(grass_xposition + 20,grass_yposition);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 20,grass_yposition);
    glVertex2f(grass_xposition + 18,grass_yposition + 45);
    glEnd();
    grass_xposition = 300,grass_yposition = 90;
    glBegin(GL_TRIANGLES);
    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 25,grass_yposition);
    glVertex2f(grass_xposition + 45,grass_yposition + 30);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition - 35,grass_yposition + 45);
    glVertex2f(grass_xposition + 20,grass_yposition);

    glVertex2f(grass_xposition,grass_yposition);
    glVertex2f(grass_xposition + 20,grass_yposition);
    glVertex2f(grass_xposition + 18,grass_yposition + 45);
    glEnd();
}

void egg()
{
    float x, y, z;
    int t;
    glColor3f(1.0, 10, 1.0);
    glBegin(GL_POLYGON);
    for (t = 0; t <= 360; t += 1)
    {
        x = egg_xc + 8 * (cos(t));
        y = egg_yc + 16 * (sin(t));
        z = 0;
        glVertex3f(x, y, z);
    }
    glEnd();
}
void basket(int i, int j)
{
    j = 10;
    if (i >= a - 60)
        i = a - 60;
    glColor3f(0.627, 0.322, 0.176);
    glBegin(GL_QUADS);
    glVertex2f(0.0 + i, 30.0 + j);
    glVertex2f(10.0 + i, 10.0 + j);
    glVertex2f(50.0 + i, 10.0 + j);
    glVertex2f(60.0 + i, 30.0 + j);
    glEnd();
}
void duck(float i, float j)
{
    float h;
    glColor3f(1.000, 0.871, 0.678);
    glBlendFunc(GL_ONE, GL_SRC_ALPHA);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glBegin(GL_POLYGON);
    glVertex2f(45 + i, 45 + j);
    glVertex2f(70 + i, 20 + j);
    glVertex2f(95 + i, 20 + j);
    glVertex2f(120 + i, 45 + j);
    glVertex2f(95 + i, 70 + j);
    glVertex2f(70 + i, 70 + j);
    glVertex2f(95 + i, 95 + j);
    glVertex2f(82.5 + i, 107.5 + j);
    glVertex2f(32.5 + i, 57.5 + j);
    glEnd();
    glFlush();
    for (h = 0; h < 13; h += 4)
    {
        glBegin(GL_LINES);
        glColor3f(0.7, 0.4, 0);
        glVertex2f(57.5 + h + i, 52.5 + h + j);
        glVertex2f(100 + h + i, 30 + h + j);
        glEnd();
        glFlush();
    }
    glColor3f(0.827, 0.827, 0.827);
    glBegin(GL_POLYGON);
    glVertex2f(82.5 + i, 107.5 + j);
    glVertex2f(65 + i, 107.5 + j);
    glVertex2f(50 + i, 95 + j);
    glVertex2f(70 + i, 95 + j);
    glEnd();
    glFlush();
    glColor3f(0.184, 0.310, 0.310);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(76 + i, 101 + j);
    glEnd();
    glColor3f(0.827, 0.827, 0.827);
    glBegin(GL_LINE_LOOP);
    glVertex2f(72.5 + i, 107.5 + j);
    glVertex2f(67.5 + i, 112.5 + j);
    glVertex2f(72.5 + i, 110 + j);
    glVertex2f(77.5 + i, 112.5 + j);
    glEnd();
    if(duck_animation == 1)
    {
        duck_xposition -= 0.3;
        duck_xposition1 -= 0.3;
        duck_xposition2 -= 0.3;
        duck_xposition3 -= 0.3;
        duck_xposition4 -= 0.3;
        duck_xposition5 -= 0.3;
        duck_xposition6 -= 0.3;
        if( duck_xposition <= -110)
            duck_xposition = 600;
        if( duck_xposition1 <= -110)
            duck_xposition1 = 600;
        if( duck_xposition2 <= -110)
            duck_xposition2 = 600;
        if( duck_xposition3 <= -110)
            duck_xposition3 = 600;
        if( duck_xposition4 <= -110)
            duck_xposition4 = 600;
        if( duck_xposition5 <= -110)
            duck_xposition5 = 600;
        if( duck_xposition6 <= -110)
            duck_xposition6 = 600;
    }
    glFlush();
}

void print_score()
{
    printf("\nLevel reached: %d\n\n", level_count);
    printf("\nNo. of eggs dropped= %d \n", dropped_eggs);
    printf("\nNo. of eggs caught = %d\n", eggs_caught);
    printf("\nNo. of eggs missed = %d\n", missed_eggs);

    getchar();
    exit(0);
}
void egg_start()
{
    egg_yc = 375;
    if (missed_eggs >= 10)
    {
        printf("\n\n\t\t\t\tGAME OVER\n\n");
        print_score();
    }
    dropped_eggs++;

    switch (rand() % 9)
    {
    case 0:
        egg_xc = 115;
        break;
    case 1:
        egg_xc = 255;
        break;
    case 2:
        egg_xc = 390;
        break;
    case 5:
        egg_xc = 115;
        break;
    case 3:
        egg_xc = 255;
        break;
    case 4:
        egg_xc = 390;
        break;
    case 7:
        egg_xc = 115;
        break;
    case 6:
        egg_xc = 255;
        break;
    case 8:
        egg_xc = 390;
        break;
    }
}

void score()
{
    if (egg_yc <= 50 && (egg_xc >= basket_x && egg_xc <= basket_x + 60))
    {
        printf("\a");
        eggs_caught++;
        egg_yc = -10;
    }
    missed_eggs = dropped_eggs - eggs_caught;
}
void draw_pixel(GLint cx, GLint cy)
{

    glBegin(GL_POINTS);
    glVertex2i(cx,cy);
    glEnd();
}
void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
    draw_pixel(x+h,y+k);
    draw_pixel(-x+h,y+k);
    draw_pixel(x+h,-y+k);
    draw_pixel(-x+h,-y+k);
    draw_pixel(y+h,x+k);
    draw_pixel(-y+h,x+k);
    draw_pixel(y+h,-x+k);
    draw_pixel(-y+h,-x+k);
}
void draw_circle(GLint h, GLint k, GLint r)
{
    GLint d=1-r, x=0, y=r;
    while(y>x)
    {
        plotpixels(h,k,x,y);
        if(d<0)
            d+=2*x+3;
        else
        {
            d+=2*(x-y)+5;
            --y;
        }
        ++x;
    }
    plotpixels(h,k,x,y);
}
void tree1()
{
    if(day_mode == 1)
        glColor3f(0.627, 0.322, 0.176);
    else
        glColor3f(0.184, 0.310, 0.310);
    glBegin(GL_POLYGON);
    glVertex2f(100,135);
    glVertex2f(100,285);
    glVertex2f(140,285);
    glVertex2f(140,135);
    glEnd();
    if(day_mode == 1)
        glColor3f(0.0,0.5,0.0);
    else
        glColor3f(0.184, 0.310, 0.310);
    for(int l=0; l<=40; l++)
    {
        draw_circle(40,280,l);
        draw_circle(90,280,l);
        draw_circle(150,280,l);
        draw_circle(210,280,l);
        draw_circle(65,340,l);
        draw_circle(115,340,l);
        draw_circle(175,340,l);
    }
    for(int l=0; l<=55; l++)
    {
        draw_circle(115,360,l);
    }
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    ground(0, 650);
    backk(0, 650);
        tree1();
        hill_big();
        bushes();
        duck(duck_xposition, 375);
        duck(duck_xposition1, 375);
        duck(duck_xposition2, 375);
        duck(duck_xposition3, 375);
        duck(duck_xposition4, 375);
    sun();
    cloud1();
    cloud2();
    line(0, 375);
    int i;
    char z[12] = "";
    char level1[12] = "LEVEL 1";
    char level2[12] = "LEVEL 2";
    char level3[12] = "LEVEL 3";
    char level4[12] = "LEVEL 4";
    if (s >= 1)
    {
        glColor3f(0, 0, 1);

        glRasterPos2i(10, 10);
        for (i = 0; i < 12; i++)
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, z[i]);

        if (level_count == 1)
        {
            glColor3f(1, 1, 1);
            glRasterPos2i(500, 300);
            for (i = 0; i < 12; i++)
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level1[i]);
        }
        else if (level_count == 2)
        {
            glColor3f(1, 0, 0);
            glRasterPos2i(500, 300);
            for (i = 0; i < 12; i++)
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level2[i]);
        }
        else if (level_count == 3)
        {
            glColor3f(0, 1, 1);
            glRasterPos2i(500, 300);
            for (i = 0; i < 12; i++)
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level3[i]);
        }
        if (level_count == 4)
        {
            glColor3f(1, 0, 1);
            glRasterPos2i(500, 300);
            for (i = 0; i < 12; i++)
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level4[i]);
        }

        if (egg_yc <= 10)
            egg_start();

        egg();
        basket(basket_x, basket_y);
        if (eggs_caught >= 10)
        {
            egg_yc -= speed_2;
            level_count = 2;
        }
        if (eggs_caught >= 20)
        {
            egg_yc -= speed_3;
            level_count = 3;
        }
        if (eggs_caught >= 30)
        {
            egg_yc -= speed_4;
            level_count = 4;
        }
        else
            egg_yc -= speed_1;
        score();
    }
    else
        start_screen(40, 300);
    glFlush();
    glutSwapBuffers();
}
void basket_set(int a, int b)
{
    basket_x = a;
    basket_y = b;
    glutPostRedisplay();
}
void myReshape(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, w, 0.0, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    a = w;
    b = h;
}
void keys(unsigned char key, int x, int y)
{
    if (key == 'q' || key == 'Q')
    {
        printf("\n\n\n\t\tQUIT BY PLAYER\n\n");
        print_score();
    }
    if (key == 's' || key == 'S')
        s += 1;

    if (key == 'a' || key == 'A')
    {
        egg_xc -= 10;
        if (egg_xc <= 0)
            egg_xc = 10;
    }
    if (key == 'd' || key == 'D')
    {
        egg_xc += 10;
        if (egg_xc >= 500)
            egg_xc = 490;
    }

}
void menu(int id)
{
    switch (id)
    {
    case 1:
        s += 1;
        break;
    case 2:
        print_score();
        break;
    case 3:
        printf("\n\n\n\t\tQUIT BY PLAYER\n");
        exit(0);
        break;
    case 4:
        day_mode = 1;
        stars = 0;
        break;
    case 5:
        day_mode = 0;
        stars = 0;
        break;
    case 6:
        duck_animation = 1;
        break;
    case 7:
        duck_animation = 0;
        break;
    default:
        exit(0);
    }
    glutPostRedisplay();
}
int main(int argc, char ** argv)
{
    printf("**********************");
    printf("\n\t\t\t\t EGG GAME\n\n");
    printf("**********************");
    printf("\n\tHow to Play..?\n\n <1>The objective of the game is to catch the eggs in the basket.\n\t To move Basket use mouse.\n");
    printf("\n <2> To Start, press key 's' or 'S' or \n\tClick Right mouse button then click 'Start Game'.\n");
    printf("\n <3> To Quit manually, press key 'q' or 'Q' or\n\t Click Right mouse button then click 'Quit'.\n");
    printf("\n\n RULES : If the player misses 10 eggs,then 'Game Over'.\n");
    printf("\nFor each level, speed is Increased\n\n");
    printf("\n\nBEST OF LUCK\n");

    glutInit( & argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(a, b);
    glutCreateWindow("EGG GAME");
    glutInitWindowPosition(100, 100);
    glutCreateMenu(menu);
    glutAddMenuEntry("Start game", 1);
    glutAddMenuEntry("score", 2);
    glutAddMenuEntry("Quit", 3);
    glutAddMenuEntry("Day mode", 4);
    glutAddMenuEntry("night mode", 5);
    glutAddMenuEntry("move ducks", 6);
    glutAddMenuEntry("stop ducks", 7);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutKeyboardFunc(keys);
    glutPassiveMotionFunc(basket_set);
    glutIdleFunc(display);
    glutReshapeFunc(myReshape);
    myinit();
    glutMainLoop();
}
void bushes()
{
    GLint bush_xposition = 517, bush_yposition = 160;
    if(day_mode == 1)
        glColor3f(0.420, 0.557, 0.137);
    else
        glColor3f(0.184, 0.310, 0.310);
    for(int l=0; l<=20; l++)
    {
        draw_circle(bush_xposition,bush_yposition,l);
        draw_circle(bush_xposition + 20,bush_yposition,l);
        draw_circle(bush_xposition + 40,bush_yposition,l);
        draw_circle(bush_xposition + 60,bush_yposition,l);
        draw_circle(bush_xposition + 10,bush_yposition + 30,l);
        draw_circle(bush_xposition + 30,bush_yposition + 30,l);
        draw_circle(bush_xposition + 50,bush_yposition + 30,l);
    }
    for(int l=0; l<=20; l++)
    {
        draw_circle(bush_xposition + 30,bush_yposition + 50,l);
    }
    bush_xposition -= 150, bush_yposition = 100;
    for(int l=0; l<=20; l++)
    {
        draw_circle(bush_xposition,bush_yposition,l);
        draw_circle(bush_xposition + 20,bush_yposition,l);
        draw_circle(bush_xposition + 40,bush_yposition,l);
        draw_circle(bush_xposition + 60,bush_yposition,l);
        draw_circle(bush_xposition + 10,bush_yposition + 30,l);
        draw_circle(bush_xposition + 30,bush_yposition + 30,l);
        draw_circle(bush_xposition + 50,bush_yposition + 30,l);
    }
    for(int l=0; l<=20; l++)
    {
        draw_circle(bush_xposition + 30,bush_yposition + 50,l);
    }
    bush_xposition = 30, bush_yposition = 130;
    for(int l=0; l<=20; l++)
    {
        draw_circle(bush_xposition,bush_yposition,l);
        draw_circle(bush_xposition + 20,bush_yposition,l);
        draw_circle(bush_xposition + 40,bush_yposition,l);
        draw_circle(bush_xposition + 60,bush_yposition,l);
        draw_circle(bush_xposition + 10,bush_yposition + 30,l);
        draw_circle(bush_xposition + 30,bush_yposition + 30,l);
        draw_circle(bush_xposition + 50,bush_yposition + 30,l);
    }
    for(int l=0; l<=20; l++)
    {
        draw_circle(bush_xposition + 30,bush_yposition + 50,l);
    }
    bush_xposition = 140, bush_yposition = 150;
    for(int l=0; l<=20; l++)
    {
        draw_circle(bush_xposition,bush_yposition,l);
        draw_circle(bush_xposition + 20,bush_yposition,l);
        draw_circle(bush_xposition + 40,bush_yposition,l);
        draw_circle(bush_xposition + 60,bush_yposition,l);
        draw_circle(bush_xposition + 10,bush_yposition + 30,l);
        draw_circle(bush_xposition + 30,bush_yposition + 30,l);
        draw_circle(bush_xposition + 50,bush_yposition + 30,l);
    }
    for(int l=0; l<=20; l++)
    {
        draw_circle(bush_xposition + 30,bush_yposition + 50,l);
    }
}
