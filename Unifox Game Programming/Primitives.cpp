

#include <GL/GLUT.h>


void OnDisplay()
{
	// 검정색으로 지우자
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

	// 그리렴!
	glFlush();
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
	glutCreateWindow("Primitives");

	// 렌더링 함수 등록
	glutDisplayFunc(OnDisplay);

	// 메세지 루프!
	glutMainLoop();

	return 0;
}