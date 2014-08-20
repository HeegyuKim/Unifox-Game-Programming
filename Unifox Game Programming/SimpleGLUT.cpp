

#include <GL/GLUT.h>
// 혹은 "glut.h" 나 <glut.h>
#include <stdio.h>
/*
	GLUT 가 화면을 다시 그리기를 원할 때 호출되서
	화면을 그리는 함수입니다.
*/
void OnDisplay()
{
	printf("OnDisplay 호출!\n");

	// glClear 함수로 색상 버퍼(GL_COLOR_BUFFER_BIT를 넣어주어서)
	// 를 지울 때 지울 색깔을 지정합니다. 
	// 아래에선 지우는 색깔은 하얀색RGBA(1, 1, 1, 1)입니다.
	glClearColor(1, 1, 1, 1);

	// glClear 함수는 OpenGL의 버퍼를 지운다.
	// GL_COLOR_BUFFER_BIT 는 윈도우의 화면 버퍼를 나타낸다.
	// 이 외에도 깊이 버퍼(GL_DEPTH_BUFFER_BIT) 나
	// 스텐실 버퍼(GL_STENCIL_BUFFER_BIT) 등이 있고
	// OR(|) 연산자로 묶어서 전달할 수 있다.
	glClear(GL_COLOR_BUFFER_BIT);


	// 여태껏 호출했던 OpenGL 함수들은 곧바로 호출되지 않고
	// 모아져 있다. 이제 그 작업들을 실행해야 한다.
	glFlush();
}


int main(int argc, char** argv)
{
	// GLUT를 초기화합니다(FreeGLUT에서만).
	glutInit(&argc, argv);

	// 윈도우를 생성하고 OpenGL 을 초기화할 때 옵션
	// GLUT_RGB: 색상버퍼를 RGB 형식으로 만들어라
	// GLUT_RGBA: 색상버퍼를 RGBA 형식으로 만들어라
	// GLUT_SINGLE: 색상 버퍼를 한개만 만들어라
	// GLUT_DOUBLE: 색상 버퍼를 두개 만들어서 더블 버퍼링을 하라.
	//			이 경우 후면 버퍼와 전면 버퍼를 교체하기 위해선
	//			glutSwapBuffers() 함수를 호출해야 합니다.
	// GLUT_DEPTH: 깊이 버퍼도 생성해라.
	// GLUT_STENCIL: 스텐실 버퍼도 생성해라.
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	// 윈도우를 만들 때 윈도우의 위치를 지정합니다.
	// (x좌표, y좌표)
	glutInitWindowPosition(100, 100);
	
	// 윈도우를 만들 때 윈도우의 크기를 지정합니다.
	// (가로, 세로)
	glutInitWindowSize(800, 600);

	// SimpleGLUT 라는 제목을 가진 윈도우를 생성합니다.
	glutCreateWindow("SimpleGLUT");

	// 현재 기본 윈도우가 다시 그려져야 할 때, 그리는 내용들이
	// 들어간 함수를 지정합니다.
	// 이로써 윈도우가 다시 그려질 때 OnDisplay 함수가 호출됩니다.
	glutDisplayFunc(OnDisplay);

	// 메세지 루프를 돕니다. 메세지 루프를 돌며 이벤트들을 처리하고
	// OnDisplay() 같은 사용자 지정 함수들을 호출해 줍니다.
	// 만약 윈도우를 닫으면 자동으로 함수가 끝납니다.
	glutMainLoop();

	return 0;
}