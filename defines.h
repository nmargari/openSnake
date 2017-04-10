#include "types.h"

#define WIN_X_SIZE 		700
#define WIN_Y_SIZE 		700
#define WIN_X_POSITION		500
#define WIN_Y_POSITION		100

#define UP			0
#define DOWN			1
#define RIGHT			2
#define LEFT			3
#define IN			4
#define OUT			5

#define TOP_BACK_LEFT		0
#define TOP_BACK_RIGHT		1
#define TOP_FRONT_LEFT		2
#define TOP_FRONT_RIGHT		3
#define DOWN_BACK_LEFT		4
#define DOWN_BACK_RIGHT		5
#define DOWN_FRONT_LEFT		6
#define DOWN_FRONT_RIGHT	7

extern int grid_size;
extern int snake_num;
extern int *snake_size;
extern int **snake_position;
extern int ***grid;
extern snake *snake_array;
extern int timer;
//extern int ***grid_table;
extern sphere hugeSphere;


void init(void);
void display(void);
void reshape (int w, int h);
void keyboard (unsigned char key, int x, int y);
void specialKey(int key, int x, int y);
void createGrid(int size);
void createSpace();
void drawSnake();
int randomNumber(int low, int high);
void update(int value);
void createLight(int i);
void createSphere(sphere *s);
float randomFNumber();
void createAxis();

// TODO Nikos, check these prototypes and in which header they should belong
void print_usage();
void print_version();