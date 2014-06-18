

#include <GL/GLUT.h>


// 화면의 중심점을 기준으로 한 
// 일정 크기의 직사각형을 그리는 함수
void DrawQuad(float size)
{
	glBegin(GL_QUADS);
	
	glVertex2f(size, size);
	glVertex2f(-size, size);
	glVertex2f(-size, -size);
	glVertex2f(size, -size);

	glEnd();
}

void OnDisplay()
{
	// 지우는 색깔은 하얀색
	glClearColor(1, 1, 1, 1);

	// 색상 버퍼를 지운다.
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//
	// 화면 중심에 검은 사각형을
	// x축으로 1.5배
	// y축으로 0.25배
	// z축은 1
	// 척도 변환(Scaling)
	glColor3d(0, 0, 0);
	glScalef(1.5f, 0.25f, 1);
	DrawQuad(0.05f);
	
	//
	// 위에서 설정한 변환들이 남아 있으므로
	// 변환 초기화
	glLoadIdentity();


	// 빨간색 상자
	// 45도 회전한 뒤
	// (0.25, 0, 0) 이동
	// 회전 축은 Z-축 벡터(0, 0, 1)
	glColor3d(1, 0, 0);
	glTranslatef(0.25f, 0, 0);
	glRotatef(45, 0, 0, 1);
	DrawQuad(0.05f);

	
	glLoadIdentity();


	// 파란색 상자
	// (0.25, 0.25, 0) 이동한 뒤
	// 원점을 기준으로 45도 회전
	// 회전 축은 Z-축 벡터(0, 0, 1)
	glColor3d(0, 1, 0);
	glRotatef(45, 0, 0, 1);
	glTranslatef(0.25f, 0.25f, 0);
	DrawQuad(0.05f);
	

	glLoadIdentity();


	// 노란색 상자
	// 크기를 2배로 키운 뒤에
	// (-0.5, -0.25)로 옮기기
	glColor3d(1, 1, 0);
	glScalef(2, 2, 1);
	glTranslatef(-0.5f, -0.25f, 0);
	DrawQuad(0.05f);

	
	glLoadIdentity();


	// 회색 상자
	// (-0.25, 0.25)로 옮긴 후
	// 크기를 3배로 키우기
	glColor3d(0.2, 0.2, 0.2);
	glTranslatef(-0.25f, 0.25f, 0);
	glScalef(3, 3, 1);
	DrawQuad(0.05f);


	glutSwapBuffers();
}


int main(int argc, char** argv)
{
	// 초기화(FreeGLUT에서만)
	glutInit(&argc, argv);

	// 초기화
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	// 화면의 (100, 100) 위치에
	glutInitWindowPosition(100, 100);

	// 가로 800, 세로 600으로
	glutInitWindowSize(600, 600);

	// SimpleGLUT 라는 제목을 가진 윈도우를 생성한다.
	glutCreateWindow("Transform");

	// 렌더링 함수 등록
	glutDisplayFunc(OnDisplay);

	// 메세지 루프!
	glutMainLoop();

	return 0;
}