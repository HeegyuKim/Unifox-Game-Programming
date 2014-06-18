

#include <GL/GLUT.h>


void OnDisplay()
{
	// ���������� ������
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	// glShadeModel()
	
	glBegin(GL_TRIANGLES);

	glVertex2f(0, 1);
	glVertex2f(1, 0);
	glVertex2f(-1, 0);

	glVertex2f(0, 0);
	glVertex2f(1, -1);
	glVertex2f(-1, -1);

	glEnd();

	// �׸���!
	glFlush();
}


int main(int argc, char** argv)
{
	// �ʱ�ȭ
	glutInit(&argc, argv);

	// �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	// ȭ���� (100, 100) ��ġ��
	glutInitWindowPosition(100, 100);

	// ���� 800, ���� 600����
	glutInitWindowSize(800, 600);

	// SimpleGLUT ��� ������ ���� �����츦 �����Ѵ�.
	glutCreateWindow("Primitives");

	// ������ �Լ� ���
	glutDisplayFunc(OnDisplay);

	// �޼��� ����!
	glutMainLoop();

	return 0;
}