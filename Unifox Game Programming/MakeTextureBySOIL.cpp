

#include <GL/GLUT.h>
// Ȥ�� "glut.h"
#include "SOIL/SOIL.h"

// typedef unsigned int GLuint
GLuint texture = 0;

// �ڿ����� �����ϴ� �Լ�
void OnSetup()
{
	// 2���� �ؽ��� ��� Ȱ��ȭ
	glEnable(GL_TEXTURE_2D);

	texture = SOIL_load_OGL_texture (
				"�����°�����.png",
				SOIL_LOAD_AUTO, // 0
				SOIL_CREATE_NEW_ID, // 0

				// Y �� ������ �ֽð� �Ӹʵ� ����� ���
				SOIL_FLAG_INVERT_Y | SOIL_FLAG_MIPMAPS	
				);

}

// �ڿ����� �����ϴ� �Լ�
void OnClear()
{
	glDeleteTextures(1, &texture);
}

void OnDisplay()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	// �ؽ�ó ����
	glBindTexture(GL_TEXTURE_2D, texture);
	
	glBegin(GL_QUADS);

	glTexCoord2f(0, 1);
	glVertex2f(-0.5f, 0.5f);
	
	glTexCoord2f(1, 1);
	glVertex2f(0.5f, 0.5f);

	glTexCoord2f(1, 0);
	glVertex2f(0.5f, -0.5f);

	glTexCoord2f(0, 0);
	glVertex2f(-0.5f, -0.5f);

	glEnd();

	glFlush();
}


int main(int argc, char** argv)
{
	// GLUT�� �ʱ�ȭ�մϴ�(FreeGLUT������).
	glutInit(&argc, argv);


	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("SimpleGLUT");
	
	OnSetup();
	glutDisplayFunc(OnDisplay);
	glutMainLoop();
	OnClear();

	return 0;
}