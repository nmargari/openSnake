#include <iostream>
#include "openSnakeConfig.h"
#include "defines.h"
#include "helper_functions.h"
#include <limits>
#include <GL/glut.h>
#include <string>

using namespace std;

/*void print_usage()
{
    cout << "\nUsage : openSnake -[OPTION] NUMBER\n\n";
    cout << " -a, --about\t\t Print info about the author\n";
    cout << " -c \t\t\t If enabled, set coordinates to zero\n";
    cout << " -g, --grid-size N \t Size for grid\n";
    cout << " -h, --help \t\t Print this message and exit\n";
    cout << " -n, --number-snakes N\t How many snakes will be created\n";
    cout << " -v, --version \t\t Print version and exit\n";
    cout << " -s, --snake-size N \t Size of the snake(s)";
    cout << endl;
}*/

/*string get_version()
{
    string majorStr = to_string(openSnake_VERSION_MAJOR);
    string minorStr = to_string(openSnake_VERSION_MINOR);
    string patchStr = to_string(openSnake_VERSION_PATCH);

    string version = majorStr + "." + minorStr + "." + patchStr;
    return version;
}*/

void check_cin()
{
    cerr << "Not a numeric value. ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/*void print_about()
{
    char msg[] = "Credits to Nikos Margaritis\nnick.margas@gmail.com, https://github.com/nmargari/ \n";
    cout << msg << endl;

}*/


// I created an-not-usefull menu to Quit,  when rigth click
//
void menu (int num)
{
    if (!num){
        glutDestroyWindow(window);
        exit(EXIT_SUCCESS);
    }else
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
//
// End of the menu

// Program's implementation
Program::Program()
{
    m_name = PROJECT_NAME;
    m_version = openSnake_VERSION;
    m_author = AUTHOR_INFO;
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

