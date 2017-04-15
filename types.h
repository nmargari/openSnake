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

  void setRandomCoord ();
  void move ();
};


class snake
{
protected:
  int m_size;
  coord *m_coordinates;

public:
    snake ();
    snake (int sz, coord * coordin);
    virtual ~ snake ();

  int getSize ();
  coord *getCoord ();

  void setSize (int sz);
  void setCoord (coord * coordin);

  void set_coordinates (int x, int y, int z);

  virtual void random_move ();
  virtual bool collision_detection (snake * s);
};

class CollitionDetector:public snake
{
public:
  CollitionDetector ();
  ~CollitionDetector ();

  virtual void random_move ();
  virtual bool collision_detection (snake * s);

};
