
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include<windows.h>
#include <glut.h>
#include<dos.h>
#include<math.h>
#define BLACK 0

void *font = GLUT_BITMAP_TIMES_ROMAN_24;
void *fonts[] =
{
  GLUT_BITMAP_9_BY_15,
  GLUT_BITMAP_TIMES_ROMAN_10,
  GLUT_BITMAP_TIMES_ROMAN_24
};

void selectFont(int newfont)
{
  font = fonts[newfont];
  glutPostRedisplay();
}

void output(int x, int y, char *string)
{
  int len, i;

  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) 
  {
    glutBitmapCharacter(font, string[i]);
  }
}

void
tick(void)
{
  glutPostRedisplay();
}

static GLfloat translate[]={0.0,0.0,0.0};
static GLfloat translate1[]={0.0,0.0,0.0};
int wallx=0.0, wally=0.0, boxx=0.0,boxy=0.0;
int flag=0;
int xc=0.0; 
int anglel_l=0.0, anglel_r=0.0;
int _anglel=0.0, _angler=0.0;
GLint sqr[3][20]={{100.0,300.0,300.0,100.0,180.0,220.0,220.0,180.0,100.0,140.0,200.0,100.0,200.0,260.0,300.0,200.0,200.0,180.0,220.0,200.0},{100.0,100.0,300.0,300.0,300.0,300.0,420.0,420.0,440.0,380.0,440.0,440.0,440.0,380.0,440.0,440.0,440.0,420.0,420.0,440.0},{1.0,1.0,1.0,1.0}};
GLint l_arm[3][7]= {{100.0,20.0,20.0,60.0,60.0,100.0,100.0},{260.0,260.0,180.0,180.0,220.0,220.0,260.0},{1.0,1.0,1.0}};
GLint r_arm[3][7]= {{300.0,380.0,380.0,340.0,340.0,300.0,300.0},{260.0,260.0,180.0,180.0,220.0,220.0,260.0},{1.0,1.0,1.0}};
GLint limbs_l[3][7]= {{100.0,60.0,60.0,100.0,60.0,20.0,60.0},{120.0,120.0,20.0,20.0,120.0,20.0,20.0},{1.0,1.0,1.0}};
GLint limbs_r[3][7]= {{300.0,340.0,340.0,300.0,340.0,380.0,340.0},{120.0,120.0,20.0,20.0,120.0,20.0,20.0},{1.0,1.0,1.0}};
GLfloat s_arm[3][8]={{30.0,50.0,50.0,20.0,350.0,370.0,380.0,350.0},{180.0,180.0,140.0,140.0,180.0,180.0,140.0,140.0},{1.0,1.0,1.0}};
GLfloat rect[3][10]={{100.0,100.0,300.0,300.0,100.0,180.0,180.0,220.0,220.0,180.0},{220.0,300.0,300.0,220.0,220.0,100.0,220.0,220.0,100.0,100.0,},{1.0,1.0,1.0}};
GLfloat w_box[3][4]={{380.0,380.0,520.0,520.0},{100.0,240.0,240.0,100.0},{1.0,1.0,1.0}};
GLfloat can[3][4]  ={{380.0,380.0,440.0,440.0},{380.0,480.0,480.0,380.0},{1.0,1.0,1.0}};
GLfloat roadvertex[][2]={{0.0,0.0},{0.0,120.0},{1280.0,120.0},{1280.0,0.0}};

GLint house[][2]={{560,300},{560,450},{620,450},{620,300}};

GLint house1[][2]={{560,120},{560,300},{620,300},{620,120}};

GLint house2[][2]={{0,120},{0,350},{50,350},{50,120}};// 1st building

GLint house3[][2]={{70,120},{70,380},{130,380},{130,120}};// 3rd building

GLint house4[][2]={{25,120},{25,420},{100,420},{100,120}};// 2nd building

GLint house5[][2]={{140,120},{140,280},{190,280},{190,120}};// 5th building

GLint house6[][2]={{110,120},{110,320},{170,320},{170,120}};// 4th building
void box()
{	
	glPushMatrix();
	glTranslatef(boxx,boxy,0.0);
	glColor3f(0.81,0.71,0.23);
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0,0.0);
	glVertex2f(w_box[0][0], w_box[1][0]); 
		glTexCoord2f(1.0,0.0);
	glVertex2f(w_box[0][1], w_box[1][1]);
		glTexCoord2f(1.0,1.0);
	glVertex2f(w_box[0][2], w_box[1][2]);
		glTexCoord2f(0.0,1.0);
	glVertex2f(w_box[0][3], w_box[1][3]);
	glEnd();
	glPopMatrix();

}
void road()
			{
			glColor3f(0.3,0.3,0.3); 
			glPushMatrix();                    // to draw road
            glBegin(GL_POLYGON);
				glTexCoord2f(1.0,0.0);
			glVertex2f(roadvertex[0][0],roadvertex[0][1]);
				glTexCoord2f(0.0,1.0);
			glVertex2f(roadvertex[1][0],roadvertex[1][1]);
				glTexCoord2f(1.0,0.0);
			glVertex2f(roadvertex[2][0],roadvertex[2][1]);
				glTexCoord2f(0.0,1.0);
			glVertex2f(roadvertex[3][0],roadvertex[3][1]);
			glEnd();
			glPopMatrix();
			}
void drawhouse2()                        // 1st building
   {
	   glColor3f(0.79279,0.88288,1.0);
	   glBegin(GL_POLYGON);
	   glTexCoord2f(1.0,0.0);
	  glVertex2f(house2[0][0],house2[0][1]);
		glTexCoord2f(0.0,1.0);
	  glVertex2f(house2[1][0],house2[1][1]);
		glTexCoord2f(1.0,0.0);
	  glVertex2f(house2[2][0],house2[2][1]);
		glTexCoord2f(0.0,1.0);
	  glVertex2f(house2[3][0],house2[3][1]);
	  glEnd();
	  
  }
void drawhouse3()                                            //3rd building
{
	glColor3f(1.0,0.93725,0.83529);
	  glBegin(GL_POLYGON);
	  glTexCoord2f(1.0,0.0);
	  glVertex2f(house3[0][0],house3[0][1]);
	  glTexCoord2f(0.0,1.0);
	  glVertex2f(house3[1][0],house3[1][1]);
	  glTexCoord2f(1.0,0.0);
	  glVertex2f(house3[2][0],house3[2][1]);
	  glTexCoord2f(0.0,1.0);
	  glVertex2f(house3[3][0],house3[3][1]);
	  glEnd();
}
void drawhouse4()                                    //2nd building
{
	glColor3f(1.0,0.82882,0.60810);
	   glBegin(GL_POLYGON);
	   glTexCoord2f(1.0,0.0);
	  glVertex2f(house4[0][0],house4[0][1]);
	  glTexCoord2f(0.0,1.0);
	  glVertex2f(house4[1][0],house4[1][1]);
	  glTexCoord2f(1.0,0.0);
	  glVertex2f(house4[2][0],house4[2][1]);
	  glTexCoord2f(0.0,1.0);
	  glVertex2f(house4[3][0],house4[3][1]);
	  glEnd();
}
void drawhouse5()                                      //5th building
{
	glColor3f(1.0,0.96,0.92);
	   glBegin(GL_POLYGON);
	   glTexCoord2f(1.0,0.0);
	  glVertex2f(house5[0][0],house5[0][1]);
		glTexCoord2f(0.0,1.0);
	  glVertex2f(house5[1][0],house5[1][1]);
	  glTexCoord2f(1.0,0.0);
	  glVertex2f(house5[2][0],house5[2][1]);
	  glTexCoord2f(0.0,1.0);
	  glVertex2f(house5[3][0],house5[3][1]);
	  glEnd();
}
void drawhouse6()                                          //4th building
{
	glColor3f(1.0,0.67213,0.39344);
	   glBegin(GL_POLYGON);
	   glTexCoord2f(1.0,0.0);
	  glVertex2f(house6[0][0],house6[0][1]);
	  glTexCoord2f(0.0,1.0);
	  glVertex2f(house6[1][0],house6[1][1]);
	  glTexCoord2f(1.0,0.0);
	  glVertex2f(house6[2][0],house6[2][1]);
	  glTexCoord2f(0.0,1.0);
	  glVertex2f(house6[3][0],house6[3][1]);
	  glEnd();
}
void drawhouse()
   {
	   glColor3f(0.329412,0.329412,0.329412);
	   glPushMatrix();
	   glBegin(GL_POLYGON);
	   glTexCoord2f(1.0,0.0);
	  glVertex2f(house[0][0],house[0][1]);
	  glTexCoord2f(0.0,1.0);
	  glVertex2f(house[1][0],house[1][1]);
	  glTexCoord2f(1.0,0.0);
	  glVertex2f(house[2][0],house[2][1]);
	  glTexCoord2f(0.0,1.0);
	  glVertex2f(house[3][0],house[3][1]);
	  glEnd();
      glPopMatrix();
  }

void windtow()
{
    glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(570,440);
	glVertex2i(610,440);
	glVertex2i(610,430);
	glVertex2i(570,430);
	glEnd();
}

void windtow2()
{
    glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(570,290);
	glVertex2i(610,290);
	glVertex2i(610,280);
	glVertex2i(570,280);
	glEnd();
}

void window()                           //window 1st buliding
{

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(5,340);
	glVertex2i(40,340);
	glVertex2i(40,330);
	glVertex2i(5,330);
	glEnd();
}
void window1()                          //window 2nd building
{

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(30,410);
	glVertex2i(95,410);
	glVertex2i(95,400);
	glVertex2i(30,400);
	glEnd();
}

void window2()                          //window 3rd building
{

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(75,370);
	glVertex2i(125,370);
	glVertex2i(125,360);
	glVertex2i(75,360);
	glEnd();
}

void window3()                          //window 4th building
{

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(115,310);
	glVertex2i(165,310);
	glVertex2i(165,300);
	glVertex2i(115,300);
	glEnd();
}

void window4()                          //window 5th building
{

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(145,270);
	glVertex2i(185,270);
	glVertex2i(185,260);
	glVertex2i(145,260);
	glEnd();
}

void backg1()
{
		glColor3f(0.52,0.39,0.39);
	glBegin(GL_POLYGON);
		glTexCoord2f(1.0,0.0);
	glVertex2f(w_box[0][0], w_box[1][0]); 
		glTexCoord2f(0.0,1.0);
	glVertex2f(w_box[0][1], w_box[1][1]);
		glTexCoord2f(1.0,0.0);
	glVertex2f(w_box[0][2], w_box[1][2]);
		glTexCoord2f(0.0,1.0);
	glVertex2f(w_box[0][3], w_box[1][3]);
		
	glEnd();
}



void drawpixel(GLint ex, GLint ey)
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POINTS);
	glVertex2i(ex,ey);
	glEnd();
}

void plotpixel(GLint h, GLint k, GLint x, GLint y)
{
	drawpixel(x+h,y+k);
	drawpixel(-x+h,y+k);
	drawpixel(x+h,-y+k);
	drawpixel(-x+h,-y+k);
	drawpixel(y+h,x+k);
	drawpixel(-y+h,x+k);
	drawpixel(y+h,-x+k);
	drawpixel(-y+h,-x+k);
}
void circle_draw(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixel(h,k,x,y);
		if(d<0)
			d+=(2*x+3);
		else
		{
			d+=(2*(x-y)+5);
			--y;
		}
		++x;
	}
	plotpixel(h,k,x,y);
}

void wall_e()
{
	glPushMatrix();
	glTranslatef(wallx,wally,0.0);
	glColor3f(0.85,0.53,0.10);
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0,0.0);
	glVertex2f(sqr[0][0], sqr[1][0]); 
		glTexCoord2f(1.0,0.0);
	glVertex2f(sqr[0][1], sqr[1][1]);
		glTexCoord2f(1.0,1.0);
	glVertex2f(sqr[0][2], sqr[1][2]);
		glTexCoord2f(0.0,1.0);
	glVertex2f(sqr[0][3], sqr[1][3]);
	glEnd();
	glColor3f(0.85,0.53,0.10);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0,0.0);
	glVertex2f(sqr[0][4], sqr[1][4]);
	glTexCoord2f(1.0,0.0);
	glVertex2f(sqr[0][5], sqr[1][5]);
	glTexCoord2f(1.0,1.0);
	glVertex2f(sqr[0][6], sqr[1][6]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(sqr[0][7], sqr[1][7]);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.81,0.71,0.23);
	glTexCoord2f(1.0,0.0);
	glVertex2f(sqr[0][8], sqr[1][8]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(sqr[0][9], sqr[1][9]);
	glTexCoord2f(1.0,0.0);
	glVertex2f(sqr[0][10], sqr[1][10]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(sqr[0][11], sqr[1][11]);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.81,0.71,0.23);
	glTexCoord2f(1.0,0.0);
	glVertex2f(sqr[0][12], sqr[1][12]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(sqr[0][13], sqr[1][13]);
	glTexCoord2f(1.0,0.0);
	glVertex2f(sqr[0][14], sqr[1][14]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(sqr[0][15], sqr[1][15]);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.25,0.0);
	glTexCoord2f(1.0,0.0);
	glVertex2f(sqr[0][16], sqr[1][16]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(sqr[0][17], sqr[1][17]);
	glTexCoord2f(1.0,0.0);
	glVertex2f(sqr[0][18], sqr[1][18]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(sqr[0][19], sqr[1][19]);
	glEnd();									//Square and triangle!!!

		glColor3f(0.65,0.49,0.24);
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0,0.0);
	glVertex2f(rect[0][0], rect[1][0]);
		glTexCoord2f(1.0,0.0);
	glVertex2f(rect[0][1], rect[1][1]);
		glTexCoord2f(1.0,1.0);
	glVertex2f(rect[0][2], rect[1][2]);
		glTexCoord2f(0.0,1.0);
	glVertex2f(rect[0][3], rect[1][3]);
		glTexCoord2f(0.0,0.0);
	glVertex2f(rect[0][4], rect[1][4]);
	glEnd();
	glColor3f(0.65,0.49,0.24);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0,0.0);
	glVertex2f(rect[0][5], rect[1][5]);
	glTexCoord2f(1.0,0.0);
	glVertex2f(rect[0][6], rect[1][6]);
	glTexCoord2f(1.0,1.0);
	glVertex2f(rect[0][7], rect[1][7]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(rect[0][8], rect[1][8]);
	glTexCoord2f(0.0,0.0);
	glVertex2f(rect[0][9], rect[1][9]);
	glEnd();									//The Rectangles inside the square

	
	glPushMatrix();
	glTranslatef(100.0,260.0,0.0);
	glRotatef(_anglel,0.0,0.0,1.0);
	glTranslatef(-100.0,-260.0,0.0);
		glColor3f(0.68,0.49,0.24);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0,0.0);
	glVertex2f(l_arm[0][0], l_arm[1][0]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(l_arm[0][1], l_arm[1][1]);
	glTexCoord2f(1.0,0.0);
	glVertex2f(l_arm[0][2], l_arm[1][2]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(l_arm[0][3], l_arm[1][3]);
	glTexCoord2f(1.0,0.0);
	glVertex2f(l_arm[0][4], l_arm[1][4]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(l_arm[0][5], l_arm[1][5]);
	glEnd();									//The left Big arm

			glBegin(GL_POLYGON);
	glColor3f(0.85,0.53,0.10);
	glTexCoord2f(1.0,0.0);
	glVertex2f(s_arm[0][0], s_arm[1][0]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(s_arm[0][1], s_arm[1][1]);
	glTexCoord2f(1.0,0.0);
	glVertex2f(s_arm[0][2], s_arm[1][2]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(s_arm[0][3], s_arm[1][3]);
	glEnd();									//The Left Small Arm
	glPointSize(8.0);
	circle_draw(40,180,15);
	glPopMatrix();
	

	glPushMatrix();
	glTranslatef(300.0,260.0,0.0);
	glRotatef(_angler,0.0,0.0,1.0);
	glTranslatef(-300.0,-260.0,0.0);
		glColor3f(0.68,0.49,0.24);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0,0.0);
	glVertex2f(r_arm[0][0], r_arm[1][0]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(r_arm[0][1], r_arm[1][1]);
	glTexCoord2f(1.0,0.0);
	glVertex2f(r_arm[0][2], r_arm[1][2]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(r_arm[0][3], r_arm[1][3]);
	glTexCoord2f(1.0,0.0);
	glVertex2f(r_arm[0][4], r_arm[1][4]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(r_arm[0][5], r_arm[1][5]);
	glEnd();									//The right Big arm

	glBegin(GL_POLYGON);
	glColor3f(0.85,0.53,0.10);
	glTexCoord2f(1.0,0.0);
	glVertex2f(s_arm[0][4], s_arm[1][4]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(s_arm[0][5], s_arm[1][5]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(s_arm[0][6], s_arm[1][6]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(s_arm[0][7], s_arm[1][7]);
	glEnd();									//The Right Small Arm
	glPointSize(8.0);
	circle_draw(360,180,15);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(100.0,120.0,0.0);
	glRotatef(anglel_l,0.0,0.0,1.0);
	glTranslatef(-100.0,-120.0,0.0);
	glBegin(GL_POLYGON);
	glColor3f(0.68,0.49,0.24);
	glTexCoord2f(1.0,0.0);
	glVertex2f(limbs_l[0][0], limbs_l[1][0]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(limbs_l[0][1], limbs_l[1][1]);
	glTexCoord2f(1.0,0.0);
	glVertex2f(limbs_l[0][2], limbs_l[1][2]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(limbs_l[0][3], limbs_l[1][3]);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.68,0.49,0.24);
	glTexCoord2f(1.0,0.0);
	glVertex2f(limbs_l[0][4], limbs_l[1][4]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(limbs_l[0][5], limbs_l[1][5]);
	glTexCoord2f(1.0,0.0);
	glVertex2f(limbs_l[0][6], limbs_l[1][6]);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(300.0,120.0,0.0);
	glRotatef(anglel_r,0.0,0.0,1.0);
	glTranslatef(-300.0,-120.0,0.0);
	glBegin(GL_POLYGON);
	glColor3f(0.68,0.49,0.24);
	glTexCoord2f(1.0,0.0);
	glVertex2f(limbs_r[0][0], limbs_r[1][0]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(limbs_r[0][1], limbs_r[1][1]);
	glTexCoord2f(1.0,0.0);
	glVertex2f(limbs_r[0][2], limbs_r[1][2]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(limbs_r[0][3], limbs_r[1][3]);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.68,0.49,0.24);
	glTexCoord2f(1.0,0.0);
	glVertex2f(limbs_r[0][4], limbs_r[1][4]);
	glTexCoord2f(0.0,1.0);
	glVertex2f(limbs_r[0][5], limbs_r[1][5]);
	glTexCoord2f(1.0,0.0);
	glVertex2f(limbs_r[0][6], limbs_r[1][6]);
	glEnd();									//The Limbs
	glPopMatrix();
	    circle_draw(80,240,30);
		circle_draw(320,240,30);
		glPushMatrix();
		glTranslatef(0.0,xc,0.0);
		glPointSize(5.0);
		circle_draw(260,440,20);
		circle_draw(140,440,20);
		glPopMatrix();
		glPointSize(8.0);
		circle_draw(80,120,25);
		circle_draw(320,120,25);				//The other circles...

	glPopMatrix();

}



void mouse(int btn, int state, int x, int y)
{
	
	if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN)
	{
		
	wallx+=5;
	boxx+=5;
	if(flag==0)
		{
		anglel_l-=10;
		anglel_r+=10;
		xc=5.0;
		}
		else if(flag==1)
		{
			anglel_l+=10;
			anglel_r-=10;
			xc=0.0;
		}
		if(anglel_l<=-30)
			flag=1;
		if(anglel_l>=0)
			flag=0;
	glutPostRedisplay();
		
	}						//Moves Wall-E right with the waste-box

	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
	{
		
	wallx-=5;
	boxx-=5;
	if(flag==0)
		{
		anglel_l-=10;
		anglel_r+=10;
		xc=5.0;
		}
		else if(flag==1)
		{
			anglel_l+=10;
			anglel_r-=10;
			xc=0.0;
		}
		if(anglel_l<=-30)
			flag=1;
		if(anglel_l>=0)
			flag=0;
	glutPostRedisplay();	//Moves Wall-E left with the waste-box
		
	}
}

int i;

   
void keys(unsigned char key, int x, int y)
{
	if(key=='x')			//Moves Wall-e to right
	{
		wallx+=5;
		if(flag==0)
		{
		anglel_l-=10;
		anglel_r+=10;
		xc=5.0;
		}
		else if(flag==1)
		{
			anglel_l+=10;
			anglel_r-=10;
			xc=0.0;
		}
		if(anglel_l<=-30)
			flag=1;
		if(anglel_l>=0)
			flag=0;
	}
		if(key=='z')			//Moves Wall-e to left
	{
		wallx-=5;
		if(flag==0)
		{
		anglel_l-=10;
		anglel_r+=10;
		xc=5.0;
		}
		else if(flag==1)
		{
			anglel_l+=10;
			anglel_r-=10;
			xc=0.0;
		}
		if(anglel_l<=-30)
			flag=1;
		if(anglel_l>=0)
			flag=0;
	}
	if(key=='y')			//Moves Wall-e to up
	{	
		wally+=5;
		if(flag==0)
		{
		anglel_l-=10;
		anglel_r+=10;
		xc=5.0;
		}
		else if(flag==1)
		{
			anglel_l+=10;
			anglel_r-=10;
			xc=0.0;
		}
		if(anglel_l<=-30)
			flag=1;
		if(anglel_l>=0)
			flag=0;
	}
	if(key=='h')			//Moves Wall-E down
	{
		wally-=5;
				if(flag==0)
		{
		anglel_l-=10;
		anglel_r+=10;
		xc=5.0;
		}
		else if(flag==1)
		{
			anglel_l+=10;
			anglel_r-=10;
			xc=0.0;
		}
		if(anglel_l<=-30)
			flag=1;
		if(anglel_l>=0)
			flag=0;
	}
	if(key=='q')			//Moves left hand to left
	{
		_anglel-=1;
	}
	if(key=='w')			//Moves left hand to right
	{
		_anglel+=1;				
	}
	if(key=='o')			//Moves right hand to left
	{
		_angler-=1;
	}	
	if(key=='p')			//Moves right hand to right
	{
		_angler+=1;
	}
	if(key=='a')
	{
		
			wally+=5;
			boxy+=5;
	
	}
	

}
 

void display() {
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	    glColor3f(0.85,0.85,0.10);
		drawhouse4();                                 // 2nd building

glPushMatrix();
window1();                                    //window for 2nd building
for( i=0;i<=11;i++)
{
glTranslated(0.0,-20.0,0.0);
window1();
}
glPopMatrix();

drawhouse2();                                    // 1st building

glPushMatrix();                                 
window();                                       //window for 1st building
for( i=0;i<=8;i++)
{
glTranslated(0.0,-20.0,0.0);
window();
}
glPopMatrix();
glPushMatrix();
glTranslatef(0.0,-translate1[0],0.0);

drawhouse();
glPushMatrix();

windtow();
for( i=0;i<=5;i++)
{
glTranslated(0.0,-20.0,0.0);
windtow();
}
glPopMatrix();
glPopMatrix();
                                

drawhouse6();                                 // 4th building

glPushMatrix();
window3();                                    //window for 4th building
for( i=0;i<=7;i++)
{
glTranslated(0.0,-20.0,0.0);
window3();
}
glPopMatrix();



drawhouse3();                                 // 3rd building 

glPushMatrix();
window2();                                    // window for  3rd building
for( i=0;i<=10;i++)
{
glTranslated(0.0,-20.0,0.0);
window2();
}
glPopMatrix();
road();
                                     
drawhouse5();                                 //5th building

glPushMatrix();
window4();                                    // window for 5th building   
for( i=0;i<=5;i++)
{
glTranslated(0.0,-20.0,0.0);
window4();
}
glPopMatrix();
glPushMatrix();
	glTranslatef(50.0,50.0,0.0);
	glScalef(0.45,0.35,0.0);
	wall_e();
	box();
glPopMatrix();
output(100, 440, "Wall-E");
glutSwapBuffers();
glFlush();
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,500.0,0.0,500.0);
	glClearColor(0.59,0.41,0.31,1.0);
	glColor3f(0.0,0.0,0.0);
}


int main(int argc, char **argv)
{


	GLubyte image[64][64][3];
	int i,j,c;
	for(i=0;i<64;i++)
	{
		for(j=0;j<64;j++)
		{
			c=((((i&0x8)==0)^((j&0x8))==0))*255;
			image[i][j][0]=(GLubyte) c;
			image[i][j][1]=(GLubyte) c;
			image[i][j][2]=(GLubyte) c;
		}
	}
	glutInit(&argc, argv);
	for (i = 1; i < argc; i++) {
    if (!strcmp(argv[i], "-mono")) {
      font = GLUT_BITMAP_9_BY_15;
    }
  }
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Wall-E");
    glutDisplayFunc(display);
    glutIdleFunc(tick);
    glutKeyboardFunc(keys);
    glutMouseFunc(mouse);
	glEnable(GL_TEXTURE_2D);
	glTexImage2D(GL_TEXTURE_2D,0,3,64,64,0,GL_RGB,GL_UNSIGNED_BYTE,image);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);

    init();
	glutMainLoop();
	return 0;
}
