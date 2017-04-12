#include <iostream>
#include "openSnakeConfig.h"
#include "helper_functions.h"
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

void createMenu(void)
{
    submenu_id = glutCreateMenu(menu);
    menu_id = glutCreateMenu(menu);

    glutAddMenuEntry("Quit " PROJECT_NAME, 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// End of the menu
////////////////////////////////////////////////////////////////////////////


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
    string version_message{"You are using " + m_name + ", version " + m_version };
    return version_message;
}

void Program::handleArguments(struct XYZ &PointOnAxis, struct SizeOptions &NumericArgs)
{
    try {

        // ' ' is the delimeter (space). We can use '=' eg -n=1 -g=50 etc...
        TCLAP::CmdLine cmd("3D Snake game", ' ', this->getVersionStr());

        TCLAP::ValueArg<int> gridSizeArg ( "g", "grid-size", "Size of the grid", true, 0, "int" );
        cmd.add ( gridSizeArg );

        TCLAP::ValueArg<int> numSnkArg ( "n", "number-snakes", "Number of snakes to create", true, 0, "int" );
        cmd.add ( numSnkArg );

        TCLAP::ValueArg<int> sizeSnkArg ( "s", "snake-size", "Size of the snake(s)", true, 0, "int" );
        cmd.add ( sizeSnkArg );

        TCLAP::SwitchArg coordSnkArg ( "c", "coordinates", "Set coordinates to 0", cmd, false );
        TCLAP::SwitchArg aboutArg("a", "about", "Print info about", cmd, false);

        cmd.parse ( this->m_argc, this->m_argv );

        // Check whether these args are zero or negative!!
        // When grid size is smaller that 35 a black window is created
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

        if (numSnkArg.getValue() <= 0)
        {
            TCLAP::ArgException exc("Zero or negative number of snakes!",
                                    "--number-snakes",
                                    "Negative or zero ArgException");
            TCLAP::StdOutput out;
            out.failure(cmd, exc);
        }

        if (sizeSnkArg.getValue() <= 0)
        {
            TCLAP::ArgException exc("Zero or negative size of snakes!",
                                    "--snake-size",
                                    "Negative or zero ArgException");
            TCLAP::StdOutput out;
            out.failure(cmd, exc);
        }

        // Νο exception arrised, good to go!!
        NumericArgs.grid_size = gridSizeArg.getValue();
        NumericArgs.snake_num = numSnkArg.getValue();
        NumericArgs.snakeSize = sizeSnkArg.getValue();


        // If the user gave -c, then append default (0) coordinates
        if (coordSnkArg.getValue())
        {
            PointOnAxis.x = 0;
            PointOnAxis.y = 0;
            PointOnAxis.z = 0;
            PointOnAxis.is_set = true;
        }

        // If the user gave -a, then print about info
        if (aboutArg.getValue())
        {
            cout << this->authorInfo() << endl;
        }

      }
    catch ( TCLAP::ArgException& e )
    {
        cerr << "Error : " << e.error() << " for arg "
        << e.argId() << endl;
    }
}
// end of Program::xxx