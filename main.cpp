#include <iostream>
#include <stdlib.h>
#include <limits>

#include <GL/glut.h>

#include "defines.h"

int grid_size;
int snake_num;
int *snake_size;
int **snake_position;
int ***grid;
int timer = 500;
//int ***grid_table;

snake *snake_array;
sphere hugeSphere;

using namespace std;

int main(int argc, char** argv)
{
	coord *coordinates;
	int x, y, z;

        while((cout << "Grid size: ") &&
               !(cin >> grid_size))
               {
                   cerr << "Not a numeric value. ";
                   cin.clear();
                   cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }

        while ((cout << "Snake number: ") &&
              !(cin >> snake_num))
              {
                  cerr << "Not a numeric value. ";
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
              }

	snake_array = new snake [snake_num];

	//grid_table = new int ** [grid_size];

//setting the grid_table
/*	for(int i = 0; i < grid_size; i++)
	{
		grid_table[i] = new int * [grid_size];

		for(int j = 0; j < grid_size; j++)
		{
			grid_table[i][j] = new int [grid_size];

			for(int k = 0; k < grid_size; k++)
			{
				grid_table[i][j][k] = 0;
			}
		}

	}*/

	for(int i = 0; i < snake_num; i++)
	{
		cout << "Snake's #" << i + 1 << " size: ";
		cin >> snake_array[i].size;
	}

	for(int i = 0; i < snake_num; i++)
	{
		coordinates = new coord [2 * snake_array[i].size - 1];
		cout << "Position for snake #" << i + 1 << "(x,y,z): ";
		cin >> x >> y >> z;
		snake_array[i].set_coordinates(x, y, z);
	}

    	glutInit(&argc, argv);
    	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    	glutInitWindowSize (WIN_X_SIZE, WIN_Y_SIZE);
    	glutCreateWindow("Open Snake");

    	init ();

    	glutReshapeFunc(reshape);
    	glutDisplayFunc(display);
    	glutKeyboardFunc(keyboard);
	//glutKeyboardUpFunc(keyboard);
	//glutIgnoreKeyRepeat(1);
    	glutSpecialFunc(specialKey);

	glutTimerFunc(timer, update, 0);

    	glutMainLoop();

    	return 0;
}

