#include "openSnakeConfig.h"
#include <string>
#include <iostream>

#ifdef _WIN32                                               // If Win, then use "/opt" instead of --opt
# define TCLAP_NAMESTARTSTRING "~~"
# define TCLAP_FLAGSTARTSTRING "/"
#endif
#include <tclap/CmdLine.h>

/*TODO OBSOLOTE,  delete?
void print_usage();
void print_version();
std::string get_version();
void proccess_flags_status ( bool gflag, bool nflag, bool sflag );
void print_about();
void print_man();*/

bool check_cin();

static int window;
static int menu_id;
static int submenu_id;
static int value {0};

void menu ( int num );
void createMenu ( void );

struct XYZ{
    int x = -1;
    int y = -1;
    int z = -1;
    bool is_set = false;
  };

struct SizeOptions{
    int grid_size = 0;
    int snake_num = 0;
    int snakeSize = 0;
  };

class Program{

private:
    std::string m_name;
    std::string m_version;
    std::string m_author;
    int m_argc;
    char** m_argv;

public:
    Program(int argc, char** argv);
    std::string getName();
    std::string getVersionStr();
    std::string authorInfo();
    std::string getVersionMsg();
    void handleArguments (struct XYZ &PointOnAxis, struct SizeOptions &NumericArgs);
};

