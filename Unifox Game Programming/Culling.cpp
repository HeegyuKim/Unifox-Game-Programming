

#include <GL/GLUT.h>
#include <Windows.h>


bool cw = true;

void OnDisplay()
{
	// 검정색으로 지우자
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

	// 그리렴!
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
	// 초기화
	glutInit(&argc, argv);

	// 초기화
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_SINGLE);

	// 화면의 (100, 100) 위치에
	glutInitWindowPosition(100, 100);

	// 가로 800, 세로 600으로
	glutInitWindowSize(800, 600);

	// SimpleGLUT 라는 제목을 가진 윈도우를 생성한다.
	glutCreateWindow("Culling");

	// 렌더링 함수 등록
	glutDisplayFunc(OnDisplay);
	glutKeyboardFunc(OnKeyboard);
	// 메세지 루프!
	glutMainLoop();

	return 0;
}