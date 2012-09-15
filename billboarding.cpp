#include <windows.h>
#include <GL/glu.h>
#include <GL/glaux.h>

//��������� �� ������, ���� ������� 
//auxDIBImageLoad �������� �������� �����������
//� ������� RGB
AUX_RGBImageRec *srcImage;

//���� ����������� ������ � ������� RGBA,
//(�������� ��� � �����-���������)
unsigned char *resImage;
int resImageWidth,resImageHeight;

//��� �������� (�����)
GLuint texName;

//������ ����������� ��������������
GLuint listNum;

//���� ��������
GLfloat rot_angle=0;

//������� �������� � ��������� �����������
//(���������� �����)
void loadImage()
{
	int i,j;

	//��������� ��������, ����� ������� ����� ���������
	//� ������ ������ �������
	srcImage=auxDIBImageLoad("billboard.bmp");

	//��������� ������� �����������
	resImageWidth=srcImage->sizeX;
	resImageHeight=srcImage->sizeY;

	//�������� ������ ��� ���� �����������
	resImage=new unsigned char[srcImage->sizeX * srcImage->sizeY * 4];

	//��������� ����������� (����� �� ������ � �� ��������)
	for (i=0;i<srcImage->sizeY;i++)
	{
		for(j=0;j<srcImage->sizeX;j++)
		{
			//��������������� � ����� ����������� �������� �������� ���������
			resImage[i*srcImage->sizeX*4+j*4]=srcImage->data[i*srcImage->sizeX*3+j*3];
			resImage[i*srcImage->sizeX*4+j*4+1]=srcImage->data[i*srcImage->sizeX*3+j*3+1];
			resImage[i*srcImage->sizeX*4+j*4+2]=srcImage->data[i*srcImage->sizeX*3+j*3+2];
			
			//���� �������� ������� ����� (��� �����) -- ����� ����������� 0,
			//���� ��� -- 255 (����� ��� ����������� OpenGL
			//�������������� ������������� ����� � ������� �������� �� 0 �� 1)
			if ((srcImage->data[i*srcImage->sizeX*3+j*3]==srcImage->data[i*srcImage->sizeX*3+j*3+1]) &&
				(srcImage->data[i*srcImage->sizeX*3+j*3+1]==srcImage->data[i*srcImage->sizeX*3+j*3+2]))
				resImage[i*srcImage->sizeX*4+j*4+3]=0;
			else
				resImage[i*srcImage->sizeX*4+j*4+3]=255;
		}
	}
	delete srcImage;
}

void init()
{
	glShadeModel(GL_FLAT);
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	glEnable(GL_BLEND);

	loadImage();
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);

	glGenTextures(1,&texName);
	glBindTexture(GL_TEXTURE_2D,texName);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	
	//������� �������� (������� ������ ���� ��������� 2)
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,resImageWidth,resImageHeight,0,GL_RGBA,GL_UNSIGNED_BYTE,resImage);

	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	
	glEnable(GL_TEXTURE_2D);

	//������� ������ ����������� ��� 
	//����������������� ��������������
	listNum=glGenLists(1);
	glNewList(listNum,GL_COMPILE);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0,0.0);glVertex3f(-1.0,-1.0,0);
			glTexCoord2f(1.0,0.0);glVertex3f(1.0,-1.0,0);
			glTexCoord2f(1.0,1.0);glVertex3f(1.0,1.0,0);
			glTexCoord2f(0.0,1.0);glVertex3f(-1.0,1.0,0);
		glEnd();
	glEndList();
}

void deinit()
{
	glDeleteLists(listNum,1);
	delete resImage;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPushMatrix();

	//������������ ��� �����, ����� ���� �����
	//������������
	glRotatef(-40,1.0,0.0,0.0);
	
	//������������ ����� �� �������
	glRotatef(rot_angle,0.0,1.0,0.0);

	//������������� ������ ���� � ������ ���
	glRotatef(45,0.0,1.0,0.0);

	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glCallList(listNum);
	
	//������������� ������ ���� � ������ ���
	glRotatef(-90,0.0,1.0,0.0);

	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glCallList(listNum);

	glPopMatrix();
	gluSwapBuffers();
}

void reshape(int w, int h)
{	
	glViewport(0,0,(GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-10,10,-10,10,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void rotate_scene()
{
	rot_angle+=0.5;
	if(rot_angle>360.0)
		rot_angle=0.5;
	gluPostRedisplay();
}

int main(int argc, char** argv)
{
	gluInit(&argc,argv);
	gluInitDisplayMode(GLU_DOUBLE|GLU_RGB);
	gluInitWindowSize(600,600);
	gluCreateWindow("Billboarding technique");
	init();
	gluDisplayFunc(display);
	gluReshapeFunc(reshape);
	gluIdleFunc(rotate_scene);
	gluMainLoop();
	deinit();
	return 0;
}