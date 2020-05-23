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
int dino_rot = 0;
void drawCircle(int r, int  xc, int yc) {
	int x = 0, y = r;
	int d;
	d = 1 - r;

	while (x < y)
	{
		glBegin(GL_POLYGON);
		glVertex2i(y + xc, x + yc);
		glVertex2i(x + xc, y + yc);
		glVertex2i(x + xc, -y + yc);
		glVertex2i(y + xc, -x + yc);
		glVertex2i(-y + xc, -x + yc);
		glVertex2i(-x + xc, -y + yc);
		glVertex2i(-x + xc, y + yc);
		glVertex2i(-y + xc, x + yc);
		glEnd();

		if (d < 0)
		{
			x = x + 1;
			d = d + 2 * x + 1;
		}
		else
		{
			x = x + 1;
			y = y - 1;
			d = d + ((2 * x) + 1) - (2 * y);
		}
	}//end while
}//end drawCircle

void drawEllipse(int rx, int ry, int xc, int yc) {
	float a = rx;
	float b = ry;
	float x = 0;
	float y = ry;
	float d2;
	float d1 = b - (a*a*ry) + (a*a*0.25);

	while (2 * b*b*x < 2 * a*a*y)
	{
		glBegin(GL_POLYGON);
		glVertex2f(x + xc, y + yc);
		glVertex2f(x + xc, -y + yc);
		glVertex2f(-x + xc, -y + yc);
		glVertex2f(-x + xc, y + yc);
		glEnd();

		if (d1 < 0)
		{
			x = x + 1;
			d1 = d1 + (2 * b*b*x) + (b*b);
		}
		else
		{
			x = x + 1;
			y = y - 1;
			d1 = d1 + (2 * b*b*x) - (2 * a*a*y) + (b*b);
		}
	}//end while

	d2 = b*b*((x + 0.5)*(x + 0.5)) + (a*a*((y - 1)*(y - 1))) - (a*a*b*b);
	while (y > 0 || y < 0)
	{
		glBegin(GL_POLYGON);
		glVertex2f(x + xc, y + yc);
		glVertex2f(x + xc, -y + yc);
		glVertex2f(-x + xc, -y + yc);
		glVertex2f(-x + xc, y + yc);
		glEnd();

		if (d2 > 0)
		{
			y = y - 1;
			d2 = d2 - (2 * a*a*y) + (a*a);
		}
		else
		{
			x = x + 1; y = y - 1;
			d2 = d2 + (2 * b*b*x) - (2 * a*a*y) + (a*a);
		}
	}
}

void dinoLeft_LeftArm() {
	glColor3f(0.666, 0.266, 0);
	drawEllipse(10, 10, 260, 250);
	glBegin(GL_POLYGON);
	glVertex2f(260, 250);
	glVertex2f(270, 250);
	glVertex2f(280, 240);
	glVertex2f(290, 240);
	glVertex2f(290, 230);
	glVertex2f(270, 230);
	glVertex2f(260, 240);
	glVertex2f(260, 250);
	glEnd();

	drawEllipse(10, 10, 290, 235);

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0);
	glVertex2f(295, 230);
	glVertex2f(300, 225);
	glVertex2f(295, 220);
	glVertex2f(295, 225);
	glVertex2f(290, 225);
	glVertex2f(290, 230);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0);
	glVertex2f(300, 235);
	glVertex2f(305, 230);
	glVertex2f(300, 225);
	glVertex2f(300, 230);
	glVertex2f(295, 230);
	glVertex2f(295, 235);
	glEnd();
}

void dinoLeft_RightArm() {
	glColor3f(0.0, 0.0, 0);
	drawEllipse(10, 10, 270, 250);
	glBegin(GL_POLYGON);
	glVertex2f(270, 250);
	glVertex2f(280, 250);
	glVertex2f(290, 240);
	glVertex2f(300, 240);
	glVertex2f(300, 230);
	glVertex2f(280, 230);
	glVertex2f(270, 240);
	glVertex2f(270, 250);
	glEnd();

	drawEllipse(10, 10, 300, 235);

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0);
	glVertex2f(305, 230);
	glVertex2f(310, 225);
	glVertex2f(305, 220);
	glVertex2f(305, 225);
	glVertex2f(300, 225);
	glVertex2f(300, 230);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0);
	glVertex2f(310, 235);
	glVertex2f(315, 230);
	glVertex2f(310, 225);
	glVertex2f(310, 230);
	glVertex2f(305, 230);
	glVertex2f(305, 235);
	glEnd();
}

void dinoLeft_HeadAndNeck() {

	glBegin(GL_POLYGON);
	glColor3f(0.666, 0.266, 0);
	glVertex2f(300, 350);
	glVertex2f(350, 340);
	glVertex2f(360, 330);
	glVertex2f(360, 320);
	glVertex2f(350, 320);
	glVertex2f(320, 310);
	glVertex2f(340, 310);
	glVertex2f(360, 310);
	glVertex2f(350, 300);
	glVertex2f(360, 310);
	glVertex2f(310, 290);
	glVertex2f(300, 300);
	glVertex2f(300, 290);
	glVertex2f(270, 245);
	glVertex2f(270, 300);
	glVertex2f(300, 350);
	glEnd();

	drawEllipse(10, 30, 270, 270);

	glColor3f(255.0, 255.0, 255.0);
	drawCircle(5, 310, 340);

	glPointSize(5.0);
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(310, 340);
	glEnd();
}

void dinoLeft_Body() {
	glBegin(GL_POLYGON);
	glColor3f(0.501, 0.2, 0);
	glVertex2f(270, 300);
	glVertex2f(270, 240);
	glVertex2f(250, 230);
	glVertex2f(160, 250);
	glVertex2f(180, 310);
	glVertex2f(260, 310);
	glVertex2f(270, 300);
	glEnd();
}

void dinoLeft_Tail() {
	glBegin(GL_POLYGON);
	glColor3f(0.501, 0.2, 0);
	glVertex2f(70, 300);
	glVertex2f(150, 300);
	glVertex2f(180, 310);
	glVertex2f(160, 250);
	glVertex2f(150, 250);
	glVertex2f(150, 270);
	glVertex2f(70, 300);
	glEnd();
}

void dinoLeft_LegLeft() {
	glColor3f(0.666, 0.266, 0);
	drawEllipse(30, 30, 195, 250);

	glBegin(GL_POLYGON);
	//glColor3f(0.0, 0.0, 0);
	glVertex2f(225, 245);
	glVertex2f(200, 200);
	glVertex2f(170, 200);
	glVertex2f(190, 245);
	glVertex2f(180, 180);
	glVertex2f(170, 180);
	glVertex2f(170, 160);
	glVertex2f(170, 200);
	glEnd();

	drawEllipse(15, 10, 185, 165);

	//Feet Claws
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0);
	glVertex2f(200, 160);
	glVertex2f(195, 165);
	glVertex2f(190, 165);
	glVertex2f(190, 160);
	glVertex2f(200, 160);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0);
	glVertex2f(205, 165);
	glVertex2f(200, 170);
	glVertex2f(195, 170);
	glVertex2f(195, 165);
	glVertex2f(205, 165);
	glEnd();
}

void dinoLeft_LegRight() {
	glColor3f(0.0, 0.0, 0.0);
	drawEllipse(30, 30, 205, 250);

	glBegin(GL_POLYGON);
	//glColor3f(0.0, 0.0, 0);
	glVertex2f(235, 245);
	glVertex2f(210, 200);
	glVertex2f(180, 200);
	glVertex2f(200, 245);
	glVertex2f(190, 180);
	glVertex2f(180, 180);
	glVertex2f(180, 160);
	glVertex2f(180, 200);
	glVertex2f(235, 245);
	glEnd();

	drawEllipse(15, 10, 195, 165);

	//Feet Claws
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0);
	glVertex2f(210, 160);
	glVertex2f(205, 165);
	glVertex2f(200, 165);
	glVertex2f(200, 160);
	glVertex2f(210, 160);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0);
	glVertex2f(215, 165);
	glVertex2f(210, 170);
	glVertex2f(200, 170);
	glVertex2f(200, 165);
	glVertex2f(210, 165);
	glEnd();
}

void dinoLeft() {
 	dinoLeft_Tail();
	dinoLeft_LegRight();
	dinoLeft_RightArm();
	dinoLeft_Body();
	dinoLeft_HeadAndNeck();
	dinoLeft_LegLeft();
	dinoLeft_LeftArm();
}
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
        glColor3f(0.098, 0.098, 0.439);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++)
        {
            theta = i * PI * i / 180;
            glVertex2f(115 + 80 * cos(theta) / 2, 620 + 80 * sin(theta) / 2);
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
        egg_xc = 275;
        break;
    case 2:
        egg_xc = 450;
        break;
    case 5:
        egg_xc = 115;
        break;
    case 3:
        egg_xc = 275;
        break;
    case 4:
        egg_xc = 450;
        break;
    case 7:
        egg_xc = 115;
        break;
    case 6:
        egg_xc = 275;
        break;
    case 8:
        egg_xc = 450;
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

    if(dino_rot == 0){
        glPushMatrix();
        glScalef(0.5,0.5,0.5);
        glTranslatef(50,620,0);
        dinoLeft();
        glPopMatrix();
        glPushMatrix();
        glScalef(0.5,0.5,0.5);
        glTranslatef(390,620,0);
        dinoLeft();
        glPopMatrix();
        glPushMatrix();
        glScalef(0.5,0.5,0.5);
        glTranslatef(720,620,0);
        dinoLeft();
        glPopMatrix();
    }
    else{
        glPushMatrix();
        glScalef(0.5,0.5,0.5);
        glTranslatef(430,620,0);
        glRotated(180,0,1,0);
        dinoLeft();
        glPopMatrix();
        glPushMatrix();
        glScalef(0.5,0.5,0.5);
        glTranslatef(770,620,0);
        glRotated(180,0,1,0);
        dinoLeft();
        glPopMatrix();
        glPushMatrix();
        glScalef(0.5,0.5,0.5);
        glTranslatef(1100,620,0);
        glRotated(180,0,1,0);
        dinoLeft();
        glPopMatrix();
    }
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
    gluOrtho2D(0.0, 600, 0.0, 650);
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
    if (key == 'y' || key == 'Y')
    {
        if(dino_rot == 1)
            dino_rot = 0;
        else
            dino_rot = 1;
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
