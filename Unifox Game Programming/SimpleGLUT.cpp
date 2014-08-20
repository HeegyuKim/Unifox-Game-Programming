

#include <GL/GLUT.h>
// Ȥ�� "glut.h" �� <glut.h>
#include <stdio.h>
/*
	GLUT �� ȭ���� �ٽ� �׸��⸦ ���� �� ȣ��Ǽ�
	ȭ���� �׸��� �Լ��Դϴ�.
*/
void OnDisplay()
{
	printf("OnDisplay ȣ��!\n");

	// glClear �Լ��� ���� ����(GL_COLOR_BUFFER_BIT�� �־��־)
	// �� ���� �� ���� ������ �����մϴ�. 
	// �Ʒ����� ����� ������ �Ͼ��RGBA(1, 1, 1, 1)�Դϴ�.
	glClearColor(1, 1, 1, 1);

	// glClear �Լ��� OpenGL�� ���۸� �����.
	// GL_COLOR_BUFFER_BIT �� �������� ȭ�� ���۸� ��Ÿ����.
	// �� �ܿ��� ���� ����(GL_DEPTH_BUFFER_BIT) ��
	// ���ٽ� ����(GL_STENCIL_BUFFER_BIT) ���� �ְ�
	// OR(|) �����ڷ� ��� ������ �� �ִ�.
	glClear(GL_COLOR_BUFFER_BIT);


	// ���²� ȣ���ߴ� OpenGL �Լ����� ��ٷ� ȣ����� �ʰ�
	// ����� �ִ�. ���� �� �۾����� �����ؾ� �Ѵ�.
	glFlush();
}


int main(int argc, char** argv)
{
	// GLUT�� �ʱ�ȭ�մϴ�(FreeGLUT������).
	glutInit(&argc, argv);

	// �����츦 �����ϰ� OpenGL �� �ʱ�ȭ�� �� �ɼ�
	// GLUT_RGB: ������۸� RGB �������� ������
	// GLUT_RGBA: ������۸� RGBA �������� ������
	// GLUT_SINGLE: ���� ���۸� �Ѱ��� ������
	// GLUT_DOUBLE: ���� ���۸� �ΰ� ���� ���� ���۸��� �϶�.
	//			�� ��� �ĸ� ���ۿ� ���� ���۸� ��ü�ϱ� ���ؼ�
	//			glutSwapBuffers() �Լ��� ȣ���ؾ� �մϴ�.
	// GLUT_DEPTH: ���� ���۵� �����ض�.
	// GLUT_STENCIL: ���ٽ� ���۵� �����ض�.
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	// �����츦 ���� �� �������� ��ġ�� �����մϴ�.
	// (x��ǥ, y��ǥ)
	glutInitWindowPosition(100, 100);
	
	// �����츦 ���� �� �������� ũ�⸦ �����մϴ�.
	// (����, ����)
	glutInitWindowSize(800, 600);

	// SimpleGLUT ��� ������ ���� �����츦 �����մϴ�.
	glutCreateWindow("SimpleGLUT");

	// ���� �⺻ �����찡 �ٽ� �׷����� �� ��, �׸��� �������
	// �� �Լ��� �����մϴ�.
	// �̷ν� �����찡 �ٽ� �׷��� �� OnDisplay �Լ��� ȣ��˴ϴ�.
	glutDisplayFunc(OnDisplay);

	// �޼��� ������ ���ϴ�. �޼��� ������ ���� �̺�Ʈ���� ó���ϰ�
	// OnDisplay() ���� ����� ���� �Լ����� ȣ���� �ݴϴ�.
	// ���� �����츦 ������ �ڵ����� �Լ��� �����ϴ�.
	glutMainLoop();

	return 0;
}