
#include <GL/GLUT.h>
#include <stdio.h>
#include "SOIL/SOIL.h"
#include "glext.h"
#include <Windows.h>

GLuint texture = 0;

//
// 24bit ��Ʈ���� �д´�
bool LoadBitmap(const char* filename, char** data, int* width, int* height)
{
	bool result;
	FILE *fp = fopen(filename, "rb");
	if(!fp)
		return false;
	
	BITMAPFILEHEADER file = {0};
	BITMAPINFOHEADER info = {0};

	// ���� ����� �д´�.
	fread(&file, sizeof(file), 1, fp);

	// ��Ʈ�� ������ �´°�?
	result = file.bfType == 0x4D42;
	if(result)
	{
		// �׷��ٸ� ������ �� �д´�.
		fread(&info, sizeof(info), 1, fp);
	}

	
	// ���� ���̰� 24��Ʈ�ΰ�?
	result = info.biBitCount == 24;
	if(result)
	{
		// �ȼ� ������ �ִ� ��ġ�� 
		// ���� Ŀ���� �ű��.
		fseek(fp, file.bfOffBits, SEEK_SET);

		// �Ҵ�
		*data = (char*)malloc(info.biSizeImage);
		*width = info.biWidth;
		*height = info.biHeight;

		// �ȼ����� �д´�.
		fread(*data, info.biSizeImage, 1, fp);
	}

	// ���� �ݱ�
	fclose(fp);

	return result;
}

bool OnSetup()
{
	
	char *data = 0;
	int width, height;

	bool result = LoadBitmap("�����.bmp", &data,
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
	// ����� ������ �Ͼ��
	glClearColor(1, 1, 1, 1);

	// ���� ���۸� �����.
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLE_STRIP);

	// ���� ��
	glTexCoord2f(0, 1);
	glVertex2f(-1, 1);

	// ������ ��
	glTexCoord2f(1, 1);
	glVertex2f( 1, 1);
	
	// ���� �Ʒ�
	glTexCoord2f(0, 0);
	glVertex2f(-1,-1);

	// ������ �Ʒ�
	glTexCoord2f(1, 0);
	glVertex2f( 1,-1);

	glEnd();

	glFlush();
}


int main(int argc, char** argv)
{
	// �ʱ�ȭ(FreeGLUT������)
	glutInit(&argc, argv);

	// �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	// ȭ���� (100, 100) ��ġ��
	glutInitWindowPosition(100, 100);

	// ���� 800, ���� 600����
	glutInitWindowSize(800, 600);

	// SimpleGLUT ��� ������ ���� �����츦 �����Ѵ�.
	glutCreateWindow("SimpleGLUT");
	
	// �Լ� ���
	glutDisplayFunc(OnDisplay);

	
	if(OnSetup())
	{
		
		// �޼��� ����!
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