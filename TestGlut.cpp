/*
 * testGLUTevent.cpp
 *
 *  Created on: 2014��5��11��
 *      Author: xu
 */

#include <GL/glut.h>
#include <stdio.h>

#include "common.h"

#ifdef GLUT_TEST

void display() {}

// һ�㰴�������пɴ�ӡ�ַ���ESCҲ���ڣ�
void keyboardHander(unsigned char ch, int x, int y)
{
	printf("key %d(%c) x: %d, y: %d\n", ch, ch, x, y);
	fflush(stdout);
}

// ���ⰴ��
void specialKeyHandler(int key, int x, int y)
{
	printf("special key");

	switch(key) {
	case GLUT_KEY_UP:
		printf("%d(%s) ", key, "GLUT_KEY_UP");
		break;
	case GLUT_KEY_DOWN:
		printf("%d(%s) ", key, "GLUT_KEY_DOWN");
		break;
	case GLUT_KEY_LEFT:
		printf("%d(%s) ", key, "GLUT_KEY_LEFT");
		break;
	case GLUT_KEY_RIGHT:
		printf("%d(%s) ", key, "GLUT_KEY_RIGHT");
		break;
	default:
		printf("%d(%s) ", key, "Other Special keys");
	}
	printf("x: %d, y: %d\n", x, y);
	fflush(stdout);
}

// ��갴��
void mouseHandler(int button, int state, int x, int y)
{
	printf("mouse pos: (%3d, %3d) button: %s(%d), state: %s(%d)\n", x, y,
				GLUT_LEFT_BUTTON == button ? "GLUT_LEFT_BUTTON"
				: GLUT_RIGHT_BUTTON == button ? "GLUT_RIGHT_BUTTON"
				: GLUT_MIDDLE_BUTTON == button ? "GLUT_MIDDLE_BUTTON"
				: "UNKOW"
			, button,
				GLUT_UP == state ? "GLUT_UP"
				: GLUT_DOWN == state ? "GLUT_DOWN"
				: "UNKNOW"
			, state
			);
	fflush(stdout);
}

// ����϶�
void motionHandler(int x, int y)
{
	printf("motion to %d, %d\n", x, y);
	fflush(stdout);
}

// ����ƶ�
void passiveMotionHandler(int x, int y)
{
	printf("passive motion to %d, %d\n", x, y);
	fflush(stdout);
}

void testTimer(int i)
{
	printf("Alarm %d\n", i);
	fflush(stdout);
	if( i < 5 )
		glutTimerFunc(1000, testTimer, i+1);
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Getting started with OpenGL 4.3");

	glutDisplayFunc(display);

	glutKeyboardFunc(keyboardHander); // ���̰���(һ��)
	glutSpecialFunc(specialKeyHandler); // ���ⰴ��

	glutMouseFunc(mouseHandler); // ��갴��
	glutMotionFunc(motionHandler);  // ����϶�
	glutPassiveMotionFunc(passiveMotionHandler); // ����ƶ�

	glutTimerFunc(1000, testTimer, 1); // ��ʱ��

	glutMainLoop(); // start main loop.
	return 0;
}


#endif // GLUT_TEST


