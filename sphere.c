/*
 * (c) Copyright 1995-1999, Igor Tarasov
 * FidoNet: 2:5020/370.2 620.20 1103.5
 * Inet: itarasov@rtuis.miem.edu.ru
 * Phone: (095)942-50-97
 */


#include <windows.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

AUX_RGBImageRec* photo_image;


double y1=7,y2=5,rr=0,b=0,z=60,x1=0,x2=0,y=2,j=0,i=0,z1=20,z2=10,a=0,x=0,r=0,o=0;
int ind=1;

void CALLBACK resize(int width,int height)
{
  glViewport(0,0,width,height);
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
rr = b * (3.1415 / 180);
  x1 = x;
y1 = y;
z1 = z;
x2 = x - 0.1 * sin(r);
y2 = y - 0.1 * sin(rr);
z2 = z - 0.1 * cos(r);
 o=sqrt(z1*z1+x2*x2);
  gluPerspective(50.0f, 1.0f, 1.0f, 800.0f);

  gluLookAt(x1, y1, z1, x2,y2,z2, 0,1,0 );
  glMatrixMode( GL_MODELVIEW );
}
  
void CALLBACK Key_LEFT(void)
{
//x=x-1;
a=a+2;
r = a * (3.1415 / 180);
resize(600,600);
}
void CALLBACK Key_RIGHT(void)
{
//x=x+1;
a=a-2;
r = a * (3.1415 / 180);
resize(600,600);
}
void CALLBACK Key_DOWN(void)
{
r = a * (3.1415 / 180);
x = x + 1 * sin(r);
z = z + 1 * cos(r);
resize(600,600);
}
void CALLBACK Key_z(void)
{
r = a * (3.1415 / 180);
x = x - 1 * cos(r);;
z = z + 1 * sin(r);;
resize(600,600);
}
void CALLBACK Key_x(void)
{
r = a * (3.1415 / 180);
x = x + 1 * cos(r);
z = z - 1 * sin(r);
resize(600,600);
}
void CALLBACK Key_q(void)
{
b=b-1;

resize(600,600);
}
void CALLBACK Key_c(void)
{
y=y*-1;
resize(600,600);
}
void CALLBACK Key_a(void)
{
b=b+1;

resize(600,600);
}
void CALLBACK Key_UP(void)
{
r = a * (3.1415 / 180);
x = x - 1 * sin(r);
z = z - 1 * cos(r);
resize(600,600);
}

void snowman()
{
 glPushMatrix();
		glTranslated(0,-3,0); 
		glRotated(90,1,0,0); 
		glColor3d(2,2,2);
		auxSolidSphere(1.5 );
glPopMatrix();
glPushMatrix();
		glTranslated(0,-0.9,0); 
		glRotated(90,1,0,0); 
		glColor3d(2,2,2);
		auxSolidSphere(1.1);
glPopMatrix();
glPushMatrix();
		glTranslated(0,0.70,0); 
		glRotated(90,1,0,0); 
		glColor3d(2,2,2);
		auxSolidSphere(0.8);
glPopMatrix();
glPushMatrix();
		glTranslated(0,1.2,0); 
		glRotated(270,1,0,0); 
		glColor3d(0,0,1);
		auxSolidCone(0.6,0.8);
glPopMatrix();
glPushMatrix();
		glTranslated(-0.4,0.9,0.6); 
		glColor3d(0,0,0);
		auxSolidSphere(0.1);
glPopMatrix();
glPushMatrix();
		glTranslated(0.4,0.9,0.6); 
		glColor3d(0,0,0);
		auxSolidSphere(0.1);
glPopMatrix();
glPushMatrix();
		glTranslated(0,0.7,0.6); 
		glColor3d(1.2,0.7,0);
		auxSolidCone(0.17,0.8);
glPopMatrix();
glPushMatrix();
		glTranslated(0.1,0.3,0.65); 
		glColor3d(0,0,0);
		auxSolidSphere(0.05);
glPopMatrix();
glPushMatrix();
		glTranslated(-0.1,0.3,0.65); 
		glColor3d(0,0,0);
		auxSolidSphere(0.05);
glPopMatrix();
glPushMatrix();
		glTranslated(0.3,0.3,0.60); 
		glColor3d(0,0,0);
		auxSolidSphere(0.05);
glPopMatrix();
glPushMatrix();
		glTranslated(-0.3,0.3,0.60); 
		glColor3d(0,0,0);
		auxSolidSphere(0.05);
glPopMatrix();
}

void building1()
{
		glTranslated(0,-4.8,0); 
		//glRotated(90,1,0,0); 
		glColor3d(4,4,4);
		auxSolidBox(1000,1,1000 );

}

void moon()
{
		glTranslated(4,150,700); 
		glColor3d(10,10,2);
		auxSolidSphere(16);
}





void stars()
{
glEnable(GL_POINT_SMOOTH);
glPointSize(2);
glBegin(GL_POINTS);
glColor3d(10,10,10);
glVertex3d(20,80,600); 
glVertex3d(20,380,600); 
glVertex3d(520,380,60); 
glVertex3d(-520,280,60); 
glVertex3d(-400,30,-600);   
glVertex3d(-300,40,-500);
glVertex3d(100,150,700); 
glVertex3d(400,80,-600);   
glVertex3d(300,60,-400);
glVertex3d(500,280,-700);   
glVertex3d(360,360,-500);
glVertex3d(500,280,700);   
glVertex3d(-360,360,-500);
glVertex3d(400,120,600);   
glVertex3d(600,100,400);
glVertex3d(600,200,200);   
glVertex3d(700,180,100);
glVertex3d(-600,210,120);   
glVertex3d(-700,140,300);
glVertex3d(-600,310,-120);   
glVertex3d(-700,240,-300);
glVertex3d(-600,110,-520);   
glVertex3d(-700,340,-400);
glVertex3d(-200,310,-520);   
glVertex3d(-130,120,-400);
glVertex3d(-20,210,-620);   
glVertex3d(-10,400,-540);
glVertex3d(-680,240,12);   
glVertex3d(-450,210,620);   
glVertex3d(-520,400,540);
glVertex3d(-500,240,612);   
glEnd();
glPointSize(1);
glBegin(GL_POINTS);
glColor3d(10,10,10);
glVertex3d(40,180,560); 
glVertex3d(20,320,630); 
glVertex3d(590,380,160); 
glVertex3d(-520,180,60); 
glVertex3d(-400,30,-620);   
glVertex3d(-300,140,-450);
glVertex3d(100,150,700); 
glVertex3d(340,80,-600);   
glVertex3d(300,60,-430);
glVertex3d(250,180,-710);   
glVertex3d(360,360,-500);
glVertex3d(350,280,340);   
glVertex3d(-260,160,-800);
glVertex3d(600,190,700);   
glVertex3d(200,120,900);
glVertex3d(60,200,600);   
glVertex3d(700,128,10);
glVertex3d(-60,210,420);   
glVertex3d(-700,140,30);
glVertex3d(-600,310,-420);   
glVertex3d(-750,440,-320);
glVertex3d(-560,110,-650);   
glVertex3d(-270,240,-420);
glVertex3d(-320,360,-590);   
glVertex3d(-180,120,-470);
glVertex3d(-320,210,-320);   
glVertex3d(-210,410,-540);
glVertex3d(-680,270,120);   

glEnd();
}

void spade()
{
	GLUquadricObj *quadObj;
 quadObj = gluNewQuadric();

glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // см. выше
glTranslated(12,6,-10);
glRotated(90,1,0,0);
glTranslated(0,0,10);
glBegin(GL_TRIANGLES);

 glColor3d(1.1,0,0);      // рисуем треугольник
  glVertex3d(-0.8,2,0.2);
  glVertex3d(-1,1.5,0.2);
  glVertex3d(-0.8,1.5,0);

  glVertex3d(-0.8,2,0.2);
  glVertex3d(-0.8,1.5,0);
  glVertex3d(0.3,1.5,0);

  glVertex3d(-0.8,2,0.2);
  glVertex3d(0.3,1.5,0);
  glVertex3d(0.3,2,0.2);
 
  glVertex3d(0.3,1.5,0);
  glVertex3d(0.3,2,0.2);
  glVertex3d(0.5,1.5,0.2);
 glEnd();
 glColor3d(1,0,0); 
 glBegin(GL_QUADS);
  glVertex3d(-1,1.5,0.2);
  glVertex3d(-1,0.5,0.2);
  glVertex3d(-0.8,0.5,0);
  glVertex3d(-0.8,1.5,0);
  
  glVertex3d(-0.8,0.5,0);
  glVertex3d(-0.8,1.5,0);
  glVertex3d(0.3,1.5,0);
  glVertex3d(0.3,0.5,0);

  
  glVertex3d(0.3,1.5,0);
  glVertex3d(0.3,0.5,0);
  glVertex3d(0.5,0.5,0.2);
  glVertex3d(0.5,1.5,0.2);
 
  glVertex3d(-0.8,0.3,0);
  glVertex3d(-0.8,0.5,0);
  glVertex3d(0.3,0.5,0);
  glVertex3d(0.3,0.3,0);
  glEnd();
 glBegin(GL_TRIANGLES);
  glVertex3d(-1,0.5,0.2);
  glVertex3d(-0.8,0.3,0);
  glVertex3d(-0.8,0.5,0);
  glVertex3d(0.5,0.5,0.2);
  glVertex3d(0.3,0.3,0);
  glVertex3d(0.3,0.5,0);
 glEnd();
  glColor3d(1,0,0);
glTranslated(-0.2,0.55,0);
glRotated(90,1,0,0);
  gluQuadricDrawStyle(quadObj, GLU_FILL);
 gluCylinder(quadObj, 0.15, 0.15, 0.5, 5, 3);
 glColor3d(0.6,0.5,0);
 gluCylinder(quadObj, 0.13, 0.13, 4, 4, 3);
 
//auxSolidCylinder(0.15,0.5);

gluDeleteQuadric(quadObj);

}

void snowballs()
{
GLUquadricObj *quadObj;
quadObj = gluNewQuadric();

 glColor3d(2,2,2);
  gluQuadricDrawStyle(quadObj, GLU_FILL);
glPushMatrix();
  glTranslated(-12,-3.5,-10);
  gluSphere(quadObj,1, 10,6);
glPopMatrix();
glPushMatrix();
  glTranslated(-15,-3.5,-12);
  gluSphere(quadObj,0.6, 10,6);
glPopMatrix();
glPushMatrix();
  glTranslated(15,-3.5,-12);
  gluSphere(quadObj,0.6, 10,6);
glPopMatrix();
gluDeleteQuadric(quadObj);
}

void home()
{
GLUquadricObj *quadObj;
quadObj = gluNewQuadric();
 glEnable(GL_ALPHA_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glTranslated(-35,-3.5,0);
    glColor4d(3,3,2.8,1);
  glBegin(GL_TRIANGLES);
  glVertex3d(15,15,-15);
  glVertex3d(15,15,15);
  glVertex3d(15,25,0);

  glVertex3d(-15,15,-15);
  glVertex3d(-15,15,15);
  glVertex3d(-15,25,0);
  glEnd();
  glPushMatrix();
  glColor4d(0.5,0,0,1);
  glTranslated(0,20,7);
  glRotated(33,1,0,0);
  auxSolidBox(32,1,20);
  glPopMatrix();
  glPushMatrix();
  glColor4d(0.5,0,0,1);
  glTranslated(0,20,-7);
  glRotated(-33,1,0,0);
  auxSolidBox(32,1,20);
  glPopMatrix();
 glColor4d(3,3,2.8,1);
  
  glPushMatrix();
  glBegin(GL_QUADS);

  glVertex3d(-15,-3.5,-15);
  glVertex3d(-15,15,-15);
  glVertex3d(-15,15,15);
  glVertex3d(-15,-3.5,15);

  glVertex3d(-15,-3.5,-15);
  glVertex3d(-15,15,-15);
  glVertex3d(15,15,-15);
  glVertex3d(15,-3.5,-15);

  glVertex3d(-15,15,15);
  glVertex3d(-15,-3.5,15);
  glVertex3d(15,-3.5,15);
  glVertex3d(15,15,15);

  glVertex3d(15,15,15);
  glVertex3d(15,-3.5,15);
  glVertex3d(15,-3.5,9.5);
  glVertex3d(15,15,9.5);

  glVertex3d(15,15,9.5);
  glVertex3d(15,9.5,9.5);
  glVertex3d(15,9.5,4.5);
  glVertex3d(15,15,4.5);
  
  glVertex3d(15,-3.5,9.5);
  glVertex3d(15,4.5,9.5);
  glVertex3d(15,4.5,4.5);
  glVertex3d(15,-3.5,4.5);

  glVertex3d(15,-3.5,0);
  glVertex3d(15,15,0);
  glVertex3d(15,15,4.5);
  glVertex3d(15,-3.5,4.5);

  glVertex3d(15,-3.5,-15);
  glVertex3d(15,15,-15);
  glVertex3d(15,15,-7);
  glVertex3d(15,-3.5,-7);

  glVertex3d(15,9.5,0);
  glVertex3d(15,15,0);
  glVertex3d(15,15,-7);
  glVertex3d(15,9.5,-7);
glEnd();
  //auxSolidBox(30,30,30);
    glColor4d(0.2,0.2,0.2,1);
glPushMatrix();
  glTranslated(15,15,0);
  auxSolidBox(0.7,0.7,30);
glPopMatrix();
glPushMatrix();
  glTranslated(15,0,15);
  auxSolidBox(0.7,30,0.7);
glPopMatrix();
glPushMatrix();
  glTranslated(15,0,9.5);
  auxSolidBox(0.4,30,0.4);
glPopMatrix();
glPushMatrix();
  glTranslated(15,0,4.5);
  auxSolidBox(0.4,30,0.4);
glPopMatrix();

glPushMatrix();
  glTranslated(15,9.5,7);
  auxSolidBox(0.4,0.4,5);
glPopMatrix();
glPushMatrix();
  glTranslated(15,4.5,7);
  auxSolidBox(0.4,0.4,5);
glPopMatrix();

glPushMatrix();
  glTranslated(-15,0,15);
  auxSolidBox(0.7,30,0.7);
glPopMatrix();
glPushMatrix();
  glTranslated(-15,0,-15);
  auxSolidBox(0.7,30,0.7);
glPopMatrix();
glPushMatrix();
  glTranslated(15,0,-15);
  auxSolidBox(0.7,30,0.7);
glPopMatrix();
glPushMatrix();
    glColor4d(0.7,0.7,0.7,0.6);
  glTranslated(15,7,7);
  auxSolidBox(0.2,5,5);
glPopMatrix();

glPushMatrix();
    glColor4d(0.5,0.35,0.2,1);
  glTranslated(15,4.5,-0.2);
  auxSolidBox(0.2,10,0.4);
  glTranslated(0,0,-0.41);
  auxSolidBox(0.2,10,0.4);
  glTranslated(0,0,-0.41);
  auxSolidBox(0.2,10,0.4);
  glTranslated(0,0,-0.41);
  auxSolidBox(0.2,10,0.4);
  glTranslated(0,0,-0.41);
  auxSolidBox(0.2,10,0.4);
  glTranslated(0,0,-0.41);
  auxSolidBox(0.2,10,0.4);
  glTranslated(0,0,-0.41);
  auxSolidBox(0.2,10,0.4);
  glTranslated(0,0,-0.41);
  auxSolidBox(0.2,10,0.4);
  glTranslated(0,0,-0.41);
  auxSolidBox(0.2,10,0.4);
  glTranslated(0,0,-0.41);
  auxSolidBox(0.2,10,0.4);
  glTranslated(0,0,-0.41);
  auxSolidBox(0.2,10,0.4);
  glTranslated(0,0,-0.41);
  auxSolidBox(0.2,10,0.4);
  glTranslated(0,0,-0.41);
  auxSolidBox(0.2,10,0.4);
  glTranslated(0,0,-0.41);
  auxSolidBox(0.2,10,0.4);
  glTranslated(0,0,-0.41);
  auxSolidBox(0.2,10,0.4);
  glTranslated(0,0,-0.41);
  auxSolidBox(0.2,10,0.4);
  glTranslated(0,0,-0.41);
  auxSolidBox(0.2,10,0.4);
  glTranslated(0.2,3,3.25);
  auxSolidBox(0.2,0.4,7);
  glTranslated(0,-6,0);
  auxSolidBox(0.2,0.4,7);
  glPushMatrix();
  glColor4d(0.6,0.6,0.6,1);
  glTranslated(0,-2.2,0);
  auxSolidBox(2.2,0.4,7);
  glPopMatrix();
  glTranslated(-0.15,-0.5,3.5);
  glPushMatrix();
  glRotated(90,1,0,0);
  glColor4d(0.7,0.7,0.7,1);
  gluQuadricDrawStyle(quadObj, GLU_FILL);
  gluCylinder(quadObj, 0.12, 0.12, 0.5, 4, 1);
  glPopMatrix();
  glTranslated(0,7.3,0);
 glRotated(90,1,0,0); 
  gluCylinder(quadObj, 0.12, 0.12, 0.5, 4, 1);
  glPopMatrix();
  glPopMatrix();

glDisable(GL_BLEND);
  glDisable(GL_ALPHA_TEST);

}
void lumber()
{
  glColor4d(0.5,0.35,0.2,1);
  glTranslated(-55,-4,0);
  glPushMatrix();  
  glRotated(90,1,0,0);
  auxSolidCylinder(0.6,5);
  glPopMatrix();
  glColor4d(0.7,0.7,0.3,1);
  glPushMatrix();  
  glTranslated(0,0,-4);
  auxSolidCone(0.6,0.01);
  glTranslated(0,0,5);
  auxSolidCone(0.6,0.01);
  glPopMatrix();
  glColor4d(0.5,0.35,0.2,1);
  glTranslated(1,-0.2,0);
  glPushMatrix();  
  glRotated(90,1,0,0);
  auxSolidCylinder(0.4,5);
  glPopMatrix();
  glColor4d(0.7,0.7,0.3,1);
  glPushMatrix();  
  glTranslated(0,0,-4);
  auxSolidCone(0.4,0.01);
  glTranslated(0,0,5);
  auxSolidCone(0.4,0.01);
  glPopMatrix();
  
  glColor4d(0.5,0.35,0.2,1);
  glTranslated(1,0.05,0);
  glPushMatrix();  
  glRotated(90,1,0,0);
  auxSolidCylinder(0.45,5);
  glPopMatrix();
  glColor4d(0.7,0.7,0.3,1);
  glPushMatrix();  
  glTranslated(0,0,-4);
  auxSolidCone(0.45,0.01);
  glTranslated(0,0,5);
  auxSolidCone(0.45,0.01);
  glPopMatrix();

  glColor4d(0.5,0.35,0.2,1);
  glTranslated(-0.5,0.6,0);
  glPushMatrix();  
  glRotated(90,1,0,0);
  auxSolidCylinder(0.45,5);
  glPopMatrix();
  glColor4d(0.7,0.7,0.3,1);
  glPushMatrix();  
  glTranslated(0,0,-4);
  auxSolidCone(0.45,0.01);
  glTranslated(0,0,5);
  auxSolidCone(0.45,0.01);
  glPopMatrix();
  
  glColor4d(0.5,0.35,0.2,1);
  glTranslated(-2,0.6,5);
  auxSolidCylinder(2,5);
  glTranslated(0,1,0);
  glPushMatrix();
  glRotated(90,1,0,0);
  glColor4d(0.9,0.9,0.6,1);
  auxSolidCone(2,0.01);
  glPopMatrix();
  glColor4d(0.5,0.35,0.2,1);
  glTranslated(0,-0.8,1.7);
  glRotated(40,1,0,0);
  auxSolidCylinder(0.1,1);
}

void table()
{
glColor4d(0.5,0.4,0.1,1);
glTranslated(-43.5,0,0);
auxSolidBox(6.5,0.5,10);
glTranslated(-2.0,-1.3,-4.5);
auxSolidCylinder(0.2,4);
glTranslated(4,0,0);
auxSolidCylinder(0.2,4);
glTranslated(-4,0,9);
auxSolidCylinder(0.2,4);
glTranslated(4,0,0);
auxSolidCylinder(0.2,4);
}

void lpoint()
{
glEnable(GL_POINT_SMOOTH);
glPointSize(20);
glBegin(GL_POINTS);
glColor3d(10,0,0);
glVertex3d(-18,9,16); 
glVertex3d(-18,0,16); 
glEnd();
}

void teapot()
{
	 glEnable(GL_ALPHA_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  glTranslated(-42,1,4);
  glRotated(40,0,1,0);
  glColor4d(1,1,1,1);  
auxSolidTeapot(1); 
glPushMatrix();  
  glColor4d(0.5,0.2,0,0.8);
  glTranslated(-0.1,-1.1,-3);
  auxSolidCylinder(0.25,0.65);
glPopMatrix();

glColor4d(0.9,0.9,0.9,0.6);
  glTranslated(-0.1,-1,-3);
  auxSolidCylinder(0.27,0.85);
  
glDisable(GL_BLEND);
  glDisable(GL_ALPHA_TEST);
   }
void CALLBACK display (void)
{
glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

glPushMatrix();
lumber();
glPopMatrix();
glPushMatrix();
table();
glPopMatrix();
glPushMatrix();
teapot();
glPopMatrix();
glPushMatrix();
snowman();
glPopMatrix();
glPushMatrix();
building1();
glPopMatrix();
glPushMatrix();
moon();
glPopMatrix();
glPushMatrix();
stars();
glPopMatrix();
glPushMatrix();
spade();
glPopMatrix();
glPushMatrix();
snowballs();
glPopMatrix();
glPushMatrix();
home();
glPopMatrix();
auxSwapBuffers();
}

void main()
{
float pos[4] = {4,15,40,1};
float dir[3] = {-10,0,0};
float color[4] = {0.4,0.3,0.1,1};
float pos2[4] = {-20,9,15,1};
float dir2[4] = {-20,2,15,1};
float sp[4] = {0.1,0.1,0.1,1};
float ambient[4] = {0.1, 0.1, 0.1, 1};
float fogcolor[4] = {0.25,0.25,0.25,1};
GLfloat density=0.0;
GLfloat front_color[] = {1,1,1,1};
GLfloat mat_specular[] = {1,1,1,1};
    auxInitPosition( 0, 0, 600, 600);
    auxInitDisplayMode( AUX_RGB | AUX_DEPTH | AUX_DOUBLE );
    auxInitWindow( "Controls" );
    auxIdleFunc(display);
    auxReshapeFunc(resize);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
    glEnable(GL_LIGHT0);
	glEnable(GL_AUTO_NORMAL);

   // glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
  glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);
  glLightfv(GL_LIGHT1, GL_SPECULAR, sp);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, color);
  glLightfv(GL_LIGHT1, GL_POSITION, pos2);
  glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dir2);
      //glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
//устанавливаем функции-обработчик клавиатуры и мыши
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
 auxKeyFunc(AUX_c,Key_c);
 auxKeyFunc(AUX_q,Key_q);
    auxKeyFunc(AUX_a,Key_a);
	auxKeyFunc(AUX_z,Key_z);
	auxKeyFunc(AUX_x,Key_x);
	auxKeyFunc(AUX_LEFT, Key_LEFT);
    auxKeyFunc(AUX_RIGHT, Key_RIGHT);
    auxKeyFunc(AUX_UP, Key_UP);
    auxKeyFunc(AUX_DOWN, Key_DOWN);
	    auxMainLoop(display);
}

