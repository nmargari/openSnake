#include <iostream>
#include "openSnakeConfig.h"
#include "helper_functions.h"
#include "defines.h"
#include <limits>
#include <GL/glut.h>
#include <string>

#ifdef _WIN32                                               // If Win, then use "/opt" instead of --opt
# define TCLAP_NAMESTARTSTRING "~~"
# define TCLAP_FLAGSTARTSTRING "/"
#endif
#include <tclap/CmdLine.h>
#include <tclap/DocBookOutput.h>

using namespace std;


////////////////////////////////////////////////////////////////////////////
// Program's implementation
Program::Program ( int argc, char** argv )
{
    m_name = PROJECT_NAME;
    m_version = openSnake_VERSION;
    m_author = AUTHOR_INFO;
    m_argc = argc;
    m_argv = argv;
}

std::string Program::getVersionStr()
{
    return m_version;
}

std::string Program::getName()
{
    return m_name;
}

std::string Program::authorInfo()
{
    return m_author;
}

std::string Program::getVersionMsg()
{
    return ("You are using " + m_name + ", version " + m_version);
}

ArgumentStatus Program::handleArguments(XYZ& PointOnAxis, SizeOptions& NumericArgs)
{
    ArgumentStatus ArgStatus;                               // Create ArgStatus to hold booleans isSet

    try {                                                   // Handle exceptions for tclap to process them

        // ' ' is the delimeter (space). We can use '=' eg -n=1 -g=50 etc...
        TCLAP::CmdLine cmd("3D Snake game", ' ', this->getVersionStr());

        TCLAP::ValueArg<int> gridSizeArg ( "g", "grid-size", "Size of the grid", false, 50, "int" );
        cmd.add ( gridSizeArg );

        TCLAP::ValueArg<int> numSnkArg ( "n", "number-snakes", "Number of snakes to create", false, 1, "int" );
        cmd.add ( numSnkArg );

        TCLAP::ValueArg<int> sizeSnkArg ( "s", "snake-size", "Size of the snake(s)", false, 2, "int" );
        cmd.add ( sizeSnkArg );

        TCLAP::SwitchArg coordSnkArg ( "c", "coordinates", "Set coordinates to 0", cmd, false );
        TCLAP::SwitchArg aboutArg("a", "about", "Print info about", cmd, false);

        cmd.parse ( this->m_argc, this->m_argv );

        //////////////////////////////////////////////////////////////
        // This block of code checks if it's value is the proper
        // Check whether these args are zero or negative!!
        // When grid size is smaller that 35 a black window is created!

        if (gridSizeArg.isSet())
        {
            if (gridSizeArg.getValue() > 0 && gridSizeArg.getValue() < 35)
            {
                TCLAP::ArgException exc("Small (under 35) grid_size!",
                    "--grid_size",
                    "Small grid size ArgException");

                TCLAP::StdOutput out;
                out.failure(cmd, exc);
            }
            else if (gridSizeArg.getValue() <= 0)
            {
                TCLAP::ArgException exc("Negative or zero grid_size!",
                    "--grid_size",
                    "Negative or zero grid size ArgException");

                TCLAP::StdOutput out;
                out.failure(cmd, exc);
            }
            ArgStatus.grid_Size_Arg_isSet = true;
        }


        // End of -g checks
        ///////////////////////////////////////////////////////////


        //////////////////////////////////////////////////////////////
        // This block of code checks if it's value is the proper

        if (numSnkArg.isSet())
        {
            if (numSnkArg.getValue() <= 0)
            {
                TCLAP::ArgException exc("Zero or negative number of snakes!",
                    "--number-snakes",
                    "Negative or zero ArgException");
                TCLAP::StdOutput out;
                out.failure(cmd, exc);
            }
            ArgStatus.num_Snake_Arg_isSet = true;
        }

        // End of -n checks
        ///////////////////////////////////////////////////////////


        //////////////////////////////////////////////////////////////
        // This block of code checks if it's value is the proper
        // TODO Nikos how big should the snake begin it's life??

        if (sizeSnkArg.isSet())
        {
            if (sizeSnkArg.getValue() > 20)
            {
                TCLAP::ArgException exc("Way too big size of snakes!",
                    "--snake-size",
                    "Big snake size ArgException");
                TCLAP::StdOutput out;
                out.failure(cmd, exc);
            }
            else if (sizeSnkArg.getValue() <= 0)
            {
                TCLAP::ArgException exc("Zero or negative size of snakes!",
                    "--snake-size",
                    "Negative or zero ArgException");
                TCLAP::StdOutput out;
                out.failure(cmd, exc);
            }
            ArgStatus.snke_Size_Arg_isSet = true;
        }

        // End of -s checks
        ///////////////////////////////////////////////////////////

        // Νο exception arrised, good to go!! Extract the numbers from
        // the arguments and pass them to the struct
        NumericArgs.grid_size = gridSizeArg.getValue();
        NumericArgs.snake_num = numSnkArg.getValue();
        NumericArgs.snakeSize = sizeSnkArg.getValue();


        // If the user gave -c, then append default (0) coordinates and
        // set TRUE the respective flag
        if (coordSnkArg.isSet())
        {
            PointOnAxis.x = 0;
            PointOnAxis.y = 0;
            PointOnAxis.z = 0;
            ArgStatus.coordin_Arg_isSet = true;
        }

        // If the user gave -a, then print about info and set TRUE the
        // respective flag
        if (aboutArg.isSet())
        {
            cout << this->authorInfo() << endl;
            ArgStatus.aboutInfo_Arg_isSet = true;
        }

      }
    catch ( TCLAP::ArgException& e )
    {
        cerr << "Error : " << e.error() << " for arg "
        << e.argId() << endl;
    }

    return ArgStatus;                                       // Finally return which flags are set!

}
// end of Program::xxx

// Other free functions (not members of Program)

/////////////////////////////////////////////////////////////////////////
// Check cin's status and return bool
bool check_cin()
{
    cerr << "Not a numeric value. ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // If cin is good now, pass the check
        if (cin.good())
        {
            return true;
        }

        return false;
}
// end

///////////////////////////////////////////////////////////////////////////
// I created an-not-usefull menu to Quit,  when rigth click

void menu (int num)
{
    if (!num)
    {
        glutDestroyWindow(window);
        exit(EXIT_SUCCESS);
    }
    else
    {
        value = num;
    }
    glutPostRedisplay();
}

void createMenu()
{
    submenu_id = glutCreateMenu(menu);
    menu_id = glutCreateMenu(menu);

    glutAddMenuEntry("Quit " PROJECT_NAME, 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// End of the menu
////////////////////////////////////////////////////////////////////////////

