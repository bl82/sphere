#include <windows.h>
#include <GL/glu.h>
#include <GL/glaux.h>

//Указатель на память, куда функция 
//auxDIBImageLoad загрузит исходное изображение
//в формате RGB
AUX_RGBImageRec *srcImage;

//Наши собственные данные в формате RGBA,
//(добавили еще и альфа-компонент)
unsigned char *resImage;
int resImageWidth,resImageHeight;

//Имя текстуры (номер)
GLuint texName;

//Список отображения прямоугольника
GLuint listNum;

//Угол поворота
GLfloat rot_angle=0;

//Функция загрузки и обработки изображения
//(добавление альфы)
void loadImage()
{
	int i,j;

	//Загружаем картинку, части которой будем исключать
	//а точнее черные пиксели
	srcImage=auxDIBImageLoad("billboard.bmp");

	//Сохраняем размеры изображения
	resImageWidth=srcImage->sizeX;
	resImageHeight=srcImage->sizeY;

	//Выделяем память под наше изображение
	resImage=new unsigned char[srcImage->sizeX * srcImage->sizeY * 4];

	//Процессим изображение (циклы по линиям и по столбцам)
	for (i=0;i<srcImage->sizeY;i++)
	{
		for(j=0;j<srcImage->sizeX;j++)
		{
			//Переприсваиваем в нашем изображении цветовые значения исходного
			resImage[i*srcImage->sizeX*4+j*4]=srcImage->data[i*srcImage->sizeX*3+j*3];
			resImage[i*srcImage->sizeX*4+j*4+1]=srcImage->data[i*srcImage->sizeX*3+j*3+1];
			resImage[i*srcImage->sizeX*4+j*4+2]=srcImage->data[i*srcImage->sizeX*3+j*3+2];
			
			//Если исходный пиксель белый (или серый) -- альфе присваиваем 0,
			//если нет -- 255 (позже при отображении OpenGL
			//предварительно интерполирует альфу в дробный диапазон от 0 до 1)
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
	
	//Создаем текстуру (расмеры должны быть степенями 2)
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,resImageWidth,resImageHeight,0,GL_RGBA,GL_UNSIGNED_BYTE,resImage);

	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	
	glEnable(GL_TEXTURE_2D);

	//Создаем список отображения для 
	//текстурированного прямоугольника
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

	//Поворачиваем всю сцену, чтобы было видно
	//трехмерность
	glRotatef(-40,1.0,0.0,0.0);
	
	//Поворачиваем сцену во времени
	glRotatef(rot_angle,0.0,1.0,0.0);

	//Позиционируем первый квад и рисуем его
	glRotatef(45,0.0,1.0,0.0);

	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glCallList(listNum);
	
	//Позиционируем второй квад и рисуем его
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