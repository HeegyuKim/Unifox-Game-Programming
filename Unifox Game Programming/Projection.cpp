

#include <GL/GLUT.h>
#include <Windows.h>


float yaw = 0, pitch = 0, roll = 0;

void OnDisplay()
{
	// ���������� ������
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Projection functions
	gluPerspective(90, 800.0 / 600.0, 0.1, 100);
	//glOrtho(-1, 1, -1, 1, 0.1, 100);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -1);
	glRotatef(yaw, 1, 0, 0);
	glRotatef(pitch, 0, 1, 0);
	glRotatef(roll, 0, 0, 1);

	glutWireCube(0.5);

	// �׸���!
	glFlush();
}

void OnKeyboard(unsigned char key, int x, int y)
{
	switch(key) {
	case 'w':
		yaw += 3;
		break;
	case 's':
		yaw -= 3;
		break;
	case 'a':
		pitch += 3;
		break;
	case 'd':
		pitch -= 3;
		break;
	case 'q':
		roll += 3;
		break;
	case 'e':
		roll -= 3;
		break;
	}
	glutPostRedisplay();
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
	glutCreateWindow("Projection");

	// ������ �Լ� ���
	glutDisplayFunc(OnDisplay);
	glutKeyboardFunc(OnKeyboard);
	// �޼��� ����!
	glutMainLoop();

	return 0;
}