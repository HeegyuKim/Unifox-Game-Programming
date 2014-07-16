

#include <GL/GLUT.h>
#include <stdio.h>
#include "SOIL/SOIL.h"

GLuint texture;

bool OnSetup()
{
	glEnable(GL_TEXTURE_2D);

	texture = SOIL_load_OGL_texture (
				"�����°�����.png",
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y );
	
	return texture != 0;
}

void OnClear()
{
	if(texture)
		glDeleteTextures(1, &texture);
}

void OnDisplay()
{
	// ����� ������ �Ͼ��
	glClearColor(1, 1, 1, 1);

	// ���� ���۸� �����.
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLE_STRIP);

	// ���� ��
	glTexCoord2f(0, 1);
	glVertex2f(-1, 1);

	// ������ ��
	glTexCoord2f(1, 1);
	glVertex2f( 1, 1);
	
	// ���� �Ʒ�
	glTexCoord2f(0, 0);
	glVertex2f(-1,-1);

	// ������ �Ʒ�
	glTexCoord2f(1, 0);
	glVertex2f( 1,-1);

	glEnd();

	glFlush();
}

void OnKeyboard(unsigned char key, int, int)
{
	switch(key) 
	{
	case 'q':
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		break;
	case 'w':
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		break;
	default:
		return;
	}

	glutPostRedisplay();
}


int main(int argc, char** argv)
{
	// �ʱ�ȭ(FreeGLUT������)
	glutInit(&argc, argv);

	// �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	// ȭ���� (100, 100) ��ġ��
	glutInitWindowPosition(100, 100);

	// ���� 800, ���� 600����
	glutInitWindowSize(800, 600);

	// SimpleGLUT ��� ������ ���� �����츦 �����Ѵ�.
	glutCreateWindow("SimpleGLUT");
	
	// �Լ� ���
	glutDisplayFunc(OnDisplay);
	glutKeyboardFunc(OnKeyboard);
	
	if(OnSetup())
	{
		
		// �޼��� ����!
		glutMainLoop();
	}
	else
	{
		printf("Setup Failed\n");
		return 0;
	}

	OnClear();

	return 0;
}