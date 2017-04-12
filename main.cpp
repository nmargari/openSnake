#include <iostream>
#include <stdlib.h>

#include <GL/glut.h>

#include "defines.h"
#include "helper_functions.h"

int grid_size {-1};
int snake_num {-1};
// TODO Double check what *snake_size does and if snakeSize is not needed!
int snakeSize {-1};
int* snake_size;
int** snake_position;
int*** grid;
int timer = 500;
//int ***grid_table;

snake* snake_array;
sphere hugeSphere;

using namespace std;

int main ( int argc, char** argv )
{
    coord* coordinates;
    struct XYZ PointOnAxis;
    struct SizeOptions NumericArgs;


    // Magic number :( . Abnormal initial value. This will fail if the
    // user indeed wants the snake to start from (-999, -999, -999)!
    int x {-999}, y {-999}, z {-999};

    Program thisProject{argc, argv};

    thisProject.handleArguments(PointOnAxis, NumericArgs);

    x = PointOnAxis.x;
    y = PointOnAxis.y;
    z = PointOnAxis.z;

    grid_size = NumericArgs.grid_size;
    snake_num = NumericArgs.snake_num;
    snakeSize = NumericArgs.snakeSize;

    // Either the user didn't provide a valid number or
    // the user provided 0
    /*if ( grid_size <= 0 || snake_num <= 0 || snakeSize <= 0 )
    {
        cerr << "\nMake sure you didn't give a zero value";
        exit ( EXIT_FAILURE );
    }*/

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

    for ( int i = 0; i < snake_num; i++ )
    {
        if ( ! ( snakeSize ) )
        {
            while ( ( cout << "Snake's # " << i + 1 << "size: " ) &&
                    ( !cin >> snake_array[i].size ) )
            {
                check_cin();
            }
        }
        else
        {
            // Append the command line argument
            snake_array[i].size = snakeSize;
        }

    }

    for ( int i = 0; i < snake_num; i++ )
    {
        coordinates = new coord [2 * snake_array[i].size - 1];

        if ( !PointOnAxis.is_set )
        {
            while (cout << "Position for snake #" << i + 1 << "(x,y,z): " &&
                    !(cin >> x >> y >> z))
                    {
                        check_cin();
                    }
        }

        snake_array[i].set_coordinates ( x, y, z );
    }

    glutInit ( &argc, argv );
    glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize ( WIN_X_SIZE, WIN_Y_SIZE );
    window = glutCreateWindow ( "Open Snake" );
    //glutCreateWindow(thisProject.getName());                    // Use this to automatically set the title
    createMenu();

    init ();

    glutReshapeFunc ( reshape );
    glutDisplayFunc ( display );
    glutKeyboardFunc ( keyboard );
    //glutKeyboardUpFunc(keyboard);
    //glutIgnoreKeyRepeat(1);
    glutSpecialFunc ( specialKey );

    glutTimerFunc ( timer, update, 0 );

    glutMainLoop();

    return 0;
}
