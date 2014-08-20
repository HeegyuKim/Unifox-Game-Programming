

#include <GL/GLUT.h>
// 혹은 "glut.h"
#include "SOIL/SOIL.h"

// typedef unsigned int GLuint
GLuint texture = 0;

// 자원들을 생성하는 함수
void OnSetup()
{
	// 2차원 텍스쳐 기능 활성화
	glEnable(GL_TEXTURE_2D);

	texture = SOIL_load_OGL_texture (
				"제로픈개발자.png",
				SOIL_LOAD_AUTO, // 0
				SOIL_CREATE_NEW_ID, // 0

				// Y 축 뒤집어 주시고 밉맵도 만들어 줘요
				SOIL_FLAG_INVERT_Y | SOIL_FLAG_MIPMAPS	
				);

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
	
	glBegin(GL_QUADS);

	glTexCoord2f(0, 1);
	glVertex2f(-0.5f, 0.5f);
	
	glTexCoord2f(1, 1);
	glVertex2f(0.5f, 0.5f);

	glTexCoord2f(1, 0);
	glVertex2f(0.5f, -0.5f);

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
	glutCreateWindow("SimpleGLUT");
	
	OnSetup();
	glutDisplayFunc(OnDisplay);
	glutMainLoop();
	OnClear();

	return 0;
}