
#include <GL/GLUT.h>
#include <stdio.h>
#include "SOIL/SOIL.h"
#include "glext.h"

GLuint texture;

bool OnSetup()
{
	glEnable(GL_TEXTURE_2D);
	

	texture = SOIL_load_OGL_texture (
				"제로픈개발자.png",
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y );
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

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
	glTexCoord2f(-1, 2);
	glVertex2f(-1, 1);

	// 오른쪽 위
	glTexCoord2f(2, 2);
	glVertex2f( 1, 1);
	
	// 왼쪽 아래
	glTexCoord2f(-1, -1);
	glVertex2f(-1,-1);

	// 오른쪽 아래
	glTexCoord2f(2, -1);
	glVertex2f( 1,-1);

	glEnd();

	glFlush();
}

void OnKeyboard(unsigned char key, int, int)
{
	switch(key) 
	{
	case 'q':
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		break;
	case 'w':
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		break;
	case 'e':
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		break;
	case 'r':
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
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