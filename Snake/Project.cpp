#include<GL\gL.h>
#include<GL\glut.h>
#include "game.h"

#define COLUMNS 40
#define ROWS 40
#define FPS 10

bool gameOver=false;

extern short sDirection;


void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
	initGrid(COLUMNS,ROWS);
}

void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	drawSnake();
	drawFood();
	glutSwapBuffers();

	if(gameOver)
	{
		exit(0);
	}
}
void reshape(int w, int h)
{
	glViewport(0.0,0.0,(GLsizei) w,(GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
}
void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000/FPS,timer,0);
}
void Keyboard(int key,int,int)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		if(sDirection!=DOWN)
			sDirection=UP;
		break;
	case GLUT_KEY_DOWN:
		if(sDirection!=UP)
			sDirection=DOWN;
		break;
	case GLUT_KEY_LEFT:
			if(sDirection!=RIGHT)
				sDirection=LEFT;
		break;
	case GLUT_KEY_RIGHT:
		if(sDirection!=LEFT)
			sDirection=RIGHT;
		break;
	default:
		break;
	}
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500,500);
	glutCreateWindow("SNAKE");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,timer,0);
	glutSpecialFunc(Keyboard);
	init();
	glutMainLoop();
	return 0;
}
