

#include <GL/GLUT.h>
// Ȥ�� "glut.h"

// typedef unsigned int GLuint
GLuint texture = 0;

// �ڿ����� �����ϴ� �Լ�
void OnSetup()
{
	// 2���� �ؽ��� ��� Ȱ��ȭ
	glEnable(GL_TEXTURE_2D);

	// �ؽ�ó ID�� 1�� �߱޹޾Ƽ� �Ҵ��ض�
	glGenTextures(1, &texture);
	
	// �� ID�� 2���� �ؽ��Ŀ� ���ε��մϴ�.
	glBindTexture(GL_TEXTURE_2D, texture);

	// ���� �Ӽ��� ������ �ֽð�
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// �����͸� �־��ݴϴ�.
	// ����, �ʷ�, �Ķ�
	// ���, ����Ÿ(Magenta), �þ�(Cyan)
	// �Ͼ�, ����, ȸ��
	GLuint texels[] = {
		0xff0000, 0x00ff00, 0x0000ff,	
		0xffff00, 0xff00ff, 0x00ffff,	
		0xffffff, 0x000000, 0x888888,	
	};

	glTexImage2D(GL_TEXTURE_2D, 0,
		GL_RGB, 3, 3, 0,
		GL_RGBA, GL_UNSIGNED_BYTE,
		texels);
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
	
	// �簢�� �׸���
	glBegin(GL_QUADS);

	// ���� ��
	glTexCoord2f(0, 1);
	glVertex2f(-0.5f, 0.5f);
	
	// ������ ��
	glTexCoord2f(1, 1);
	glVertex2f(0.5f, 0.5f);

	// ������ �Ʒ�
	glTexCoord2f(1, 0);
	glVertex2f(0.5f, -0.5f);
	
	// ���� �Ʒ�
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
	glutCreateWindow("MakeTexture");
	
	OnSetup();
	glutDisplayFunc(OnDisplay);
	glutMainLoop();
	OnClear();

	return 0;
}