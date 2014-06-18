

#include <GL/GLUT.h>


// ȭ���� �߽����� �������� �� 
// ���� ũ���� ���簢���� �׸��� �Լ�
void DrawQuad(float size)
{
	glBegin(GL_QUADS);
	
	glVertex2f(size, size);
	glVertex2f(-size, size);
	glVertex2f(-size, -size);
	glVertex2f(size, -size);

	glEnd();
}

void OnDisplay()
{
	// ����� ������ �Ͼ��
	glClearColor(1, 1, 1, 1);

	// ���� ���۸� �����.
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//
	// ȭ�� �߽ɿ� ���� �簢����
	// x������ 1.5��
	// y������ 0.25��
	// z���� 1
	// ô�� ��ȯ(Scaling)
	glColor3d(0, 0, 0);
	glScalef(1.5f, 0.25f, 1);
	DrawQuad(0.05f);
	
	//
	// ������ ������ ��ȯ���� ���� �����Ƿ�
	// ��ȯ �ʱ�ȭ
	glLoadIdentity();


	// ������ ����
	// 45�� ȸ���� ��
	// (0.25, 0, 0) �̵�
	// ȸ�� ���� Z-�� ����(0, 0, 1)
	glColor3d(1, 0, 0);
	glTranslatef(0.25f, 0, 0);
	glRotatef(45, 0, 0, 1);
	DrawQuad(0.05f);

	
	glLoadIdentity();


	// �Ķ��� ����
	// (0.25, 0.25, 0) �̵��� ��
	// ������ �������� 45�� ȸ��
	// ȸ�� ���� Z-�� ����(0, 0, 1)
	glColor3d(0, 1, 0);
	glRotatef(45, 0, 0, 1);
	glTranslatef(0.25f, 0.25f, 0);
	DrawQuad(0.05f);
	

	glLoadIdentity();


	// ����� ����
	// ũ�⸦ 2��� Ű�� �ڿ�
	// (-0.5, -0.25)�� �ű��
	glColor3d(1, 1, 0);
	glScalef(2, 2, 1);
	glTranslatef(-0.5f, -0.25f, 0);
	DrawQuad(0.05f);

	
	glLoadIdentity();


	// ȸ�� ����
	// (-0.25, 0.25)�� �ű� ��
	// ũ�⸦ 3��� Ű���
	glColor3d(0.2, 0.2, 0.2);
	glTranslatef(-0.25f, 0.25f, 0);
	glScalef(3, 3, 1);
	DrawQuad(0.05f);


	glutSwapBuffers();
}


int main(int argc, char** argv)
{
	// �ʱ�ȭ(FreeGLUT������)
	glutInit(&argc, argv);

	// �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	// ȭ���� (100, 100) ��ġ��
	glutInitWindowPosition(100, 100);

	// ���� 800, ���� 600����
	glutInitWindowSize(600, 600);

	// SimpleGLUT ��� ������ ���� �����츦 �����Ѵ�.
	glutCreateWindow("Transform");

	// ������ �Լ� ���
	glutDisplayFunc(OnDisplay);

	// �޼��� ����!
	glutMainLoop();

	return 0;
}