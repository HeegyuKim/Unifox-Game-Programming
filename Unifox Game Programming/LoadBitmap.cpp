
#include <GL/GLUT.h>
#include <stdio.h>
#include "SOIL/SOIL.h"
#include "glext.h"
#include <Windows.h>

GLuint texture = 0;

//
// 24bit 비트맵을 읽는다
bool LoadBitmap(const char* filename, char** data, int* width, int* height)
{
	bool result;
	FILE *fp = fopen(filename, "rb");
	if(!fp)
		return false;
	
	BITMAPFILEHEADER file = {0};
	BITMAPINFOHEADER info = {0};

	// 파일 헤더를 읽는다.
	fread(&file, sizeof(file), 1, fp);

	// 비트맵 파일이 맞는가?
	result = file.bfType == 0x4D42;
	if(result)
	{
		// 그렇다면 정보를 더 읽는다.
		fread(&info, sizeof(info), 1, fp);
	}

	
	// 색상 깊이가 24비트인가?
	result = info.biBitCount == 24;
	if(result)
	{
		// 픽셀 정보가 있는 위치로 
		// 파일 커서를 옮긴다.
		fseek(fp, file.bfOffBits, SEEK_SET);

		// 할당
		*data = (char*)malloc(info.biSizeImage);
		*width = info.biWidth;
		*height = info.biHeight;

		// 픽셀들을 읽는다.
		fread(*data, info.biSizeImage, 1, fp);
	}

	// 파일 닫기
	fclose(fp);

	return result;
}

bool OnSetup()
{
	
	char *data = 0;
	int width, height;

	bool result = LoadBitmap("선장님.bmp", &data,
				&width, &height);
	if(!result || !data)
		return false;
	
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		width, height, 0, GL_BGR,
		GL_UNSIGNED_BYTE, data);

	free(data);

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