#include "openSnakeConfig.h"
#include <string>
#include <iostream>

void print_usage();
void print_version();
std::string get_version();
void check_cin();
void proccess_flags_status ( bool gflag, bool nflag, bool sflag );
void print_about();
void print_man();

static int window;
static int menu_id;
static int submenu_id;
static int value {0};

void menu ( int num );
void createMenu ( void );

class Program{

private:
    std::string m_name;
    std::string m_version;
    std::string m_author;

public:
    Program();
    std::string getName();
    std::string getVersionStr();
    std::string authorInfo();
    std::string getVersionMsg();
};