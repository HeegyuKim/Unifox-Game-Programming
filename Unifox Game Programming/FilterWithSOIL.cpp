

#include <GL/GLUT.h>
#include <stdio.h>
#include "SOIL/SOIL.h"

GLuint texture;

bool OnSetup()
{
	glEnable(GL_TEXTURE_2D);

	texture = SOIL_load_OGL_texture (
				"제로픈개발자.png",
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y );
	
	return texture != 0;
}

void OnClear()
{
	if(texture)
		glDeleteTextures(1, &texture);
}

void OnDisplay()
{
	// 지우는 색깔은 하얀색
	glClearColor(1, 1, 1, 1);

	// 색상 버퍼를 지운다.
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLE_STRIP);

	// 왼쪽 위
	glTexCoord2f(0, 1);
	glVertex2f(-1, 1);

	// 오른쪽 위
	glTexCoord2f(1, 1);
	glVertex2f( 1, 1);
	
	// 왼쪽 아래
	glTexCoord2f(0, 0);
	glVertex2f(-1,-1);

	// 오른쪽 아래
	glTexCoord2f(1, 0);
	glVertex2f( 1,-1);

	glEnd();

	glFlush();
}

void OnKeyboard(unsigned char key, int, int)
{
	switch(key) 
	{
	case 'q':
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		break;
	case 'w':
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		break;
	default:
		return;
	}

	glutPostRedisplay();
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
	
	// 함수 등록
	glutDisplayFunc(OnDisplay);
	glutKeyboardFunc(OnKeyboard);
	
	if(OnSetup())
	{
		
		// 메세지 루프!
		glutMainLoop();
	}
	else
	{
		printf("Setup Failed\n");
		return 0;
	}

	OnClear();

	return 0;
}