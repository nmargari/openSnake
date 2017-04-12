#include <iostream>
#include "openSnakeConfig.h"
#include "defines.h"
#include "helper_functions.h"
#include <limits>
#include <GL/glut.h>

using namespace std;

// TODO -v (version) is a good idea, but cmake should configure version
// at compile time, from one variable inside of CMakeLists.txt, instead
// of a variable here. Will check this later.

void print_usage()
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
}

string get_version()
{
    string majorStr = to_string(openSnake_VERSION_MAJOR);
    string minorStr = to_string(openSnake_VERSION_MINOR);
    string patchStr = to_string(openSnake_VERSION_PATCH);

    string version = majorStr + "." + minorStr + "." + patchStr;
    return version;
}

void check_cin()
{
    cerr << "Not a numeric value. ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void print_about(){
    char msg[] = "Credits to Nikos Margaritis\nnick.margas@gmail.com, https://github.com/nmargari/ \n";
    cout << msg << endl;

}

void menu (int num){
    if (!num){
        glutDestroyWindow(window);
        exit(EXIT_SUCCESS);
    }else {
        value = num;
    }
    glutPostRedisplay();
}

void createMenu(void){
    submenu_id = glutCreateMenu(menu);
    menu_id = glutCreateMenu(menu);

    glutAddMenuEntry("Quit " PROJECT_NAME, 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}







