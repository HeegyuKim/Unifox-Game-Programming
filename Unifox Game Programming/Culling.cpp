

#include <GL/GLUT.h>
#include <Windows.h>


bool cw = true;

void OnDisplay()
{
	// ���������� ������
	glClearColor(0, 0, 0, 1);
	glClearDepth(1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, 800.0/600.0f, 0.1, 100);

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glFrontFace(cw? GL_CW : GL_CCW);
	glCullFace(GL_BACK);
	glLineWidth(1.5f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -1);
	//glRotatef(45, 1, 1, 0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glutSolidTeapot(0.5);
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0, 0, 0);
	glutSolidTeapot(0.5);

	// �׸���!
	glFlush();
}

void OnKeyboard(unsigned char key, int x, int y)
{
	switch(key) {
	case 'a':
		cw = !cw;
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
	glutCreateWindow("Culling");

	// ������ �Լ� ���
	glutDisplayFunc(OnDisplay);
	glutKeyboardFunc(OnKeyboard);
	// �޼��� ����!
	glutMainLoop();

	return 0;
}