#include <iostream>
#include <stdlib.h>

#ifdef _WIN32                                               // If Win, then use "/opt" instead of --opt
# define TCLAP_NAMESTARTSTRING "~~"
# define TCLAP_FLAGSTARTSTRING "/"
#endif
#include <tclap/CmdLine.h>

#include <GL/glut.h>

#include "defines.h"
#include "helper_functions.h"
#include "openSnakeConfig.h"

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
    int x { -1}, y { -1}, z { -1};

    try {
        Program thisProject;

        // Just a demonstration
        cout << thisProject.getVersionMsg() << endl;

        TCLAP::CmdLine cmd("", ' ', thisProject.getVersionStr());

        TCLAP::ValueArg<int> gridSizeArg ( "g", "grid-size", "Size of the grid", true, 0, "int" );
        cmd.add ( gridSizeArg );

        TCLAP::ValueArg<int> numSnkArg ( "n", "number-snakes", "Number of snakes to create", true, 0, "int" );
        cmd.add ( numSnkArg );

        TCLAP::ValueArg<int> sizeSnkArg ( "s", "snake-size", "Size of the snake(s)", true, 0, "int" );
        cmd.add ( sizeSnkArg );

        TCLAP::SwitchArg coordSnkArg ( "c", "coordinates", "Set coordinates to 0", cmd, false );
        TCLAP::SwitchArg aboutArg("a", "about", "Print info about", cmd, false);

        cmd.parse ( argc, argv );

        grid_size = gridSizeArg.getValue();
        snake_num = numSnkArg.getValue();
        snakeSize = sizeSnkArg.getValue();

        // If the user gave -c, then append default (0) coordinates
        if (coordSnkArg.getValue()) { x = y = z = 0; }

        // If the user gave -a, then print about info
        if (aboutArg.getValue()){ print_about(); }


    }
    catch ( TCLAP::ArgException& e )
    {
        cerr << "Error : " << e.error() << " for arg "
             << e.argId() << endl;
    }

    // Either the user didn't provide a valid number or
    // the user provided 0
    if ( grid_size <= 0 || snake_num <= 0 || snakeSize <= 0 )
    {
        //print_usage();
        cerr << "\nMake sure you didn't give a zero value";
        exit ( EXIT_FAILURE );
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

        if ( ( x < 0 ) || ( y < 0 ) || ( z < 0 ) )
        {
            while ( ( cout << "Position for snake #" << i + 1 << "(x,y,z): " ) &&
                    ! ( cin >> x >> y >> z ) )
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
    //glutCreateWindow(PROJECT_NAME);                    // Use this to automatically set the title
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
