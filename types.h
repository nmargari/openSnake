typedef struct coord
{
  float x;
  float y;
  float z;
} coord;


class sphere
{
private:
  coord m_position;
  coord m_destination;

public:
    sphere ();
    sphere (coord & pos, coord & dest);

  coord getPosition ();
  coord getDestination ();

  void setPosition (coord pos);
  void setDestination (coord dest);

  /*coord position;
     coord destination; */

  void setRandomCoord ();
  void move ();
};


class snake
{
private:
  int m_size;
  coord *m_coordinates;

public:
    snake ();
    snake (int sz, coord * coordin);

  int getSize ();
  coord *getCoord ();

  void setSize (int sz);
  void setCoord (coord * coordin);

  /*int size;
     coord *coordinates; */

  void set_coordinates (int x, int y, int z);
  void random_move ();
};
