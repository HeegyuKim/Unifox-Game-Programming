

#include <GL/GLUT.h>


void OnDisplay()
{
	// 지우는 색깔은 하얀색
	glClearColor(1, 1, 1, 1);

	// 색상 버퍼를 지운다.
	glClear(GL_COLOR_BUFFER_BIT);
}


int main(int argc, char** argv)
{
	// 초기화(FreeGLUT에서만)
	glutInit(&argc, argv);

	// 초기화
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	// 화면의 (100, 100) 위치에
	glutInitWindowPosition(100, 100);

	// 가로 800, 세로 600으로
	glutInitWindowSize(800, 600);

	// SimpleGLUT 라는 제목을 가진 윈도우를 생성한다.
	glutCreateWindow("SimpleGLUT");

	// 렌더링 함수 등록
	glutDisplayFunc(OnDisplay);

	// 메세지 루프!
	glutMainLoop();

	return 0;
}