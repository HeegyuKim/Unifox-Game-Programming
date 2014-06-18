

#include <GL/GLUT.h>
#include <Windows.h>


bool depthEnable = false;

void OnDisplay()
{
	// 검정색으로 지우자
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


	// 그리렴!
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
	// 초기화
	glutInit(&argc, argv);

	// 초기화
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_SINGLE);

	// 화면의 (100, 100) 위치에
	glutInitWindowPosition(100, 100);

	// 가로 800, 세로 600으로
	glutInitWindowSize(800, 600);

	// SimpleGLUT 라는 제목을 가진 윈도우를 생성한다.
	glutCreateWindow("DepthTest");

	// 렌더링 함수 등록
	glutDisplayFunc(OnDisplay);
	glutKeyboardFunc(OnKeyboard);
	// 메세지 루프!
	glutMainLoop();

	return 0;
}