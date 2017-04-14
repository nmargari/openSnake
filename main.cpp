#include <iostream>
#include <stdlib.h>

#include <GL/glut.h>

#include "defines.h"
#include "helper_functions.h"

int grid_size {-1};
int snake_num = 1;
// TODO Double check what *snake_size does and if snakeSize is not needed!
int snakeSize {-1};
int* snake_size;
int** snake_position;
int*** grid;
int timer = 500;
//int ***grid_table;

snake* snake_array = nullptr;
sphere hugeSphere;

using namespace std;

int main ( int argc, char** argv )
{
    coord* coordinates;
    Program project{argc, argv};


    XYZ PointOnAxis;                                        // Stores x, y, z
    SizeOptions NumericArgs;                                // Stores every numeric argument
    ArgumentStatus ArgStatus;                               // Stores booleans for numerics arguments

    ArgStatus = project.handleArguments(PointOnAxis, NumericArgs);


    // These variables are global, meaning they should appended a value
    // and go on with their use, while struct just fufiled it's purpose;
    // it passed variables from handleArguments, clean and tidy
    grid_size = NumericArgs.grid_size;
    snake_num = NumericArgs.snake_num;
    snakeSize = NumericArgs.snakeSize;


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

    // TODO In these fors, we can check ArgStatus.snake_Size_Arg_isSet and if FALSE,
    // we can create an openGL dialog (or slider) to append our snake(s) the size etc. Rather
    // than reading form cmd line the size, a dialog could do the job. This way we will avoid
    // the situation in which the game is run from menu, (by definition)*command line* args will
    // be missing and cin won't be able to cut it!!

    for ( int i = 0; i < snake_num; i++ )
    {
        if ( ! ( ArgStatus.snke_Size_Arg_isSet ) )
        {
            while ( ( cout << "Snake's # " << i + 1 << "size: " ) &&
                    ( !cin >> snake_array[i].getSize() ) )
            {
                if (!check_cin())
                {
                    cerr << "Something horrible happend with the input stream\n";
                    exit(EXIT_FAILURE);
                }
            }
        }
        else
        {
            // Append the command line argument
            snake_array[i].setSize(snakeSize);
        }

    }

    for ( int i = 0; i < snake_num; i++ )
    {
        coordinates = new coord [2 * snake_array[i].getSize() - 1];

        if ( !ArgStatus.coordin_Arg_isSet )
        {
            while (cout << "Position for snake #" << i + 1 << "(x,y,z): " &&
                !(cin >> PointOnAxis.x >> PointOnAxis.y >> PointOnAxis.z))
                    {
                        if (!check_cin())
                        {
                            cerr << "Something horrible happend with the input stream\n";
                            exit(EXIT_FAILURE);
                        }
                    }
        }
        snake_array[i].set_coordinates( PointOnAxis.x, PointOnAxis.y, PointOnAxis.z);
    }

    glutInit ( &argc, argv );
    glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize ( WIN_X_SIZE, WIN_Y_SIZE );
    window = glutCreateWindow ( "Open Snake" );
    //glutCreateWindow(project.getName());                    // Use this to automatically set the title
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
