

#include <GL/GLUT.h>
// 혹은 "glut.h"

// typedef unsigned int GLuint
GLuint texture = 0;

// 자원들을 생성하는 함수
void OnSetup()
{
	// 2차원 텍스쳐 기능 활성화
	glEnable(GL_TEXTURE_2D);

	// 텍스처 ID를 1개 발급받아서 할당해라
	glGenTextures(1, &texture);
	
	// 이 ID를 2차원 텍스쳐에 바인드합니다.
	glBindTexture(GL_TEXTURE_2D, texture);

	// 각종 속성을 지정해 주시고
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// 데이터를 넣어줍니다.
	// 빨강, 초록, 파랑
	// 노랑, 마젠타(Magenta), 시안(Cyan)
	// 하양, 검정, 회색
	GLuint texels[] = {
		0xff0000, 0x00ff00, 0x0000ff,	
		0xffff00, 0xff00ff, 0x00ffff,	
		0xffffff, 0x000000, 0x888888,	
	};

	glTexImage2D(GL_TEXTURE_2D, 0,
		GL_RGB, 3, 3, 0,
		GL_RGBA, GL_UNSIGNED_BYTE,
		texels);
}

// 자원들을 제거하는 함수
void OnClear()
{
	glDeleteTextures(1, &texture);
}

void OnDisplay()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	// 텍스처 지정
	glBindTexture(GL_TEXTURE_2D, texture);
	
	// 사각형 그리기
	glBegin(GL_QUADS);

	// 왼쪽 위
	glTexCoord2f(0, 1);
	glVertex2f(-0.5f, 0.5f);
	
	// 오른쪽 위
	glTexCoord2f(1, 1);
	glVertex2f(0.5f, 0.5f);

	// 오른쪽 아래
	glTexCoord2f(1, 0);
	glVertex2f(0.5f, -0.5f);
	
	// 왼쪽 아래
	glTexCoord2f(0, 0);
	glVertex2f(-0.5f, -0.5f);

	glEnd();

	glFlush();
}


int main(int argc, char** argv)
{
	// GLUT를 초기화합니다(FreeGLUT에서만).
	glutInit(&argc, argv);


	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("MakeTexture");
	
	OnSetup();
	glutDisplayFunc(OnDisplay);
	glutMainLoop();
	OnClear();

	return 0;
}