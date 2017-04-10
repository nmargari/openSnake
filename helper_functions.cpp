#include <iostream>
#include "openSnakeConfig.h"
#include "defines.h"
#include <limits>

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
    cout << " -v, --verbose \t\t Print version and exit\n";
    cout << " -s, --snake-size N \t Size of the snake(s)";
    cout << endl;
}

void print_version()
{
    cout << "You are running " << PROJECT_NAME << " v"
         << openSnake_VERSION_MAJOR << "."
         << openSnake_VERSION_MINOR << endl;
}

void check_cin()
{
    cerr << "Not a numeric value. ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// TODO Not the most elegant solution to warn if an option
// is missing. Must rethink this check.
void proccess_flags_status(bool gflag,
                           bool nflag,
                           bool sflag)
{
    if (!gflag)
    {
        cerr << "-g is needed!\n";
    }

    if (!nflag)
    {
        cerr << "-n is needed!\n";
    }

    if (!sflag)
    {
        cerr << "-s is needed!\n";
    }

}

void print_about(){
    char msg[] = "Credits to Nikos Margaritis\nnick.margas@gmail.com, https://github.com/nmargari/ \n";
    cout << msg << endl;

}

// TODO Manual for the game
void print_man(){
    char msg_usage[] = "manual..\n";
    cout << msg_usage;
}

