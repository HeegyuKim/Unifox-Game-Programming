

#include <GL/GLUT.h>


void OnDisplay()
{
	// ����� ������ �Ͼ��
	glClearColor(1, 1, 1, 1);

	// ���� ���۸� �����.
	glClear(GL_COLOR_BUFFER_BIT);
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

	// ������ �Լ� ���
	glutDisplayFunc(OnDisplay);

	// �޼��� ����!
	glutMainLoop();

	return 0;
}