#include <GL/glut.h>
#include <math.h>

const unsigned int W = 200;
const unsigned int H = 200;

void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	unsigned int data[3][W][H];
	for (size_t y = 0; y < W; ++y)
	{
		for (size_t x = 0; x < H; ++x)
		{
			data[0][x][y] = (rand() % 255) * 255 * 255 * 255;
			data[1][x][y] = (rand() % 255) * 255 * 255 * 255;
			data[2][x][y] = (rand() % 255) * 255 * 255 * 255;
		}
	}

	glDrawPixels(W, H, GL_RGB, GL_UNSIGNED_INT, data);

	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(W, H);
	glutCreateWindow("GLUT");
	glutDisplayFunc(display);
	glutMainLoop();
}