typedef struct coord
{
	float x;
	float y;
	float z;
} coord;


class sphere
{
public:
	coord position;
	coord destination;

	void setRandomCoord();
	void move();
};


class snake
{
public:
	int size;
	coord *coordinates;

	void set_coordinates(int x, int y, int z);
	void random_move();
};

