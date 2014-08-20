
#include <GL/GLUT.h>
#include <stdio.h>
#include "SOIL/SOIL.h"
#include "glext.h"

GLuint texture;

bool OnSetup()
{
	glEnable(GL_TEXTURE_2D);
	

	texture = SOIL_load_OGL_texture (
				"�����°�����.png",
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y );
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

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
	glTexCoord2f(-1, 2);
	glVertex2f(-1, 1);

	// ������ ��
	glTexCoord2f(2, 2);
	glVertex2f( 1, 1);
	
	// ���� �Ʒ�
	glTexCoord2f(-1, -1);
	glVertex2f(-1,-1);

	// ������ �Ʒ�
	glTexCoord2f(2, -1);
	glVertex2f( 1,-1);

	glEnd();

	glFlush();
}

void OnKeyboard(unsigned char key, int, int)
{
	switch(key) 
	{
	case 'q':
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		break;
	case 'w':
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		break;
	case 'e':
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		break;
	case 'r':
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
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