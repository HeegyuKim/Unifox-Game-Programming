

#include <GL/GLUT.h>
#include <Windows.h>


bool depthEnable = false;

void OnDisplay()
{
	// ���������� ������
	glClearColor(0, 0, 0, 1);
	glClearDepth(1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, 0.1, 100);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glEnable(GL_CULL_FACE);
	if(depthEnable) 
		glEnable(GL_DEPTH_TEST);
	else
		glDisable(GL_DEPTH_TEST);
	glLineWidth(2);

	glColor3f(1, 1, 1);
	glTranslatef(0, 0, -1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glutSolidSphere(0.5, 16, 16);
	glTranslatef(0.5, 0, -1);
	glutSolidSphere(0.25, 16, 16);

	
	glEnable(GL_DEPTH_TEST);
	glColor3f(0, 0, 0);
	glLoadIdentity();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glTranslatef(0, 0, -1);
	glutSolidSphere(0.5, 16, 16);
	glTranslatef(0.5, 0, -1);
	glutSolidSphere(0.25, 16, 16);


	// �׸���!
	glFlush();
}

void OnKeyboard(unsigned char key, int x, int y)
{
	switch(key) {
	case 'a':
		depthEnable = !depthEnable;
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	// �ʱ�ȭ
	glutInit(&argc, argv);

	// �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_SINGLE);

	// ȭ���� (100, 100) ��ġ��
	glutInitWindowPosition(100, 100);

	// ���� 800, ���� 600����
	glutInitWindowSize(800, 600);

	// SimpleGLUT ��� ������ ���� �����츦 �����Ѵ�.
	glutCreateWindow("DepthTest");

	// ������ �Լ� ���
	glutDisplayFunc(OnDisplay);
	glutKeyboardFunc(OnKeyboard);
	// �޼��� ����!
	glutMainLoop();

	return 0;
}