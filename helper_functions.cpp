#include <iostream>

using namespace std;

// TODO -v (version) is a good idea, but cmake should configure version
// at compile time, from one variable inside of CMakeLists.txt, instead
// of a variable here. Will check this later.

void print_usage(){
    string message;
    cout << "Usage : openSnake -[OPTION] NUMBER\n";
    cout << "[OPTION] = -g, -n, -s, -c, -h\n\n";
    cout << " -g NUM \t Size for grid\n";
    cout << " -n NUM \t NUM of snakes that will be created\n";
    cout << " -s NUM \t NUM will be the size of the snake(s)\n";
    cout << " -c \t\t (optional) If enabled, set coordinates to zero\n";
    cout << " -h \t\t Print this message\n";
}
