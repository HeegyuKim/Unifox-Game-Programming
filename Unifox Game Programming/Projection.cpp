

#include <GL/GLUT.h>
#include <Windows.h>


float yaw = 0, pitch = 0, roll = 0;

void OnDisplay()
{
	// 검정색으로 지우자
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

	// 그리렴!
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
	// 초기화
	glutInit(&argc, argv);

	// 초기화
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	// 화면의 (100, 100) 위치에
	glutInitWindowPosition(100, 100);

	// 가로 800, 세로 600으로
	glutInitWindowSize(800, 600);

	// SimpleGLUT 라는 제목을 가진 윈도우를 생성한다.
	glutCreateWindow("Projection");

	// 렌더링 함수 등록
	glutDisplayFunc(OnDisplay);
	glutKeyboardFunc(OnKeyboard);
	// 메세지 루프!
	glutMainLoop();

	return 0;
}