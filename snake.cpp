#include "defines.h"
#include <iostream>

using namespace std;

// Constructors
snake::snake() {};
snake::snake( int sz, coord* coordin ) : m_size( sz ), m_coordinates( coordin ) {};
//

int snake::getSize()
{
    return this->m_size;
}

coord* snake::getCoord()
{
    return this->m_coordinates;
}

void snake::setSize( int sz )
{
    this->m_size = sz;
}

void snake::setCoord( coord* coordin )
{
    this->m_coordinates = coordin;
}


bool collision_detection( snake* s )
{
    for ( int i = 0; i < snake_num; i++ )
    {
        if ( snake_array + i == s )
            continue;

        for ( int j = 0; j < 2 * snake_array[i].getSize() - 1; j++ )
        {
            if ( snake_array[i].getCoord()[j].x == s->getCoord()[0].x && snake_array[i].getCoord()[j].y == s->getCoord()[0].y && snake_array[i].getCoord()[j].z == s->getCoord()[0].z )
            {
                return true;
            }
        }
    }

    return false;
}


void snake::set_coordinates( int x, int y, int z )
{
    this->m_coordinates = new coord [2 * this->m_size - 1];

    this->m_coordinates[0].x = x;
    this->m_coordinates[0].y = y;
    this->m_coordinates[0].z = z;
    //grid_table[x + grid_size/2][y + grid_size/2][z + grid_size/2] = 1;

    if ( 2 * this->m_size + this->m_coordinates[0].x - 1 <= grid_size / 2.0 )
    {
        for ( int i = 1; i < 2 * this->m_size - 1; i++ )
        {
            this->m_coordinates[i].x = this->m_coordinates[i - 1].x + 1;
            this->m_coordinates[i].y = this->m_coordinates[0].y;
            this->m_coordinates[i].z = this->m_coordinates[0].z;
            //grid_table[(int)(this->coordinates[i - 1].x + grid_size/2 + 1)][(int)(this->coordinates[i].y + grid_size/2)][(int)(this->coordinates[i].z + grid_size/2)] = 1;
        }
    }
    else if ( 2 * this->m_size + this->m_coordinates[0].y - 1 <= grid_size / 2.0 )
    {
        for ( int i = 1; i < 2 * this->m_size - 1; i++ )
        {
            this->m_coordinates[i].y = this->m_coordinates[i - 1].y + 1;
            this->m_coordinates[i].x = this->m_coordinates[0].x;
            this->m_coordinates[i].z = this->m_coordinates[0].z;
            //grid_table[(int)(this->coordinates[i].x + grid_size/2)][(int)(this->coordinates[i - 1].y + grid_size/2 + 1)][(int)(this->coordinates[i].z + grid_size/2)] = 1;
        }
    }
    else if ( 2 * this->m_size + this->m_coordinates[0].z - 1 <= grid_size / 2.0 )
    {
        for ( int i = 1; i < 2 * this->m_size - 1; i++ )
        {
            this->m_coordinates[i].z = this->m_coordinates[i - 1].z + 1;
            this->m_coordinates[i].y = this->m_coordinates[0].y;
            this->m_coordinates[i].x = this->m_coordinates[0].x;
            //grid_table[(int)(this->coordinates[i].x + grid_size/2)][(int)(this->coordinates[i].y + grid_size/2)][(int)(this->coordinates[i - 1].z + grid_size/2 + 1)] = 1;
        }
    }
    else if ( - ( 2 * this->m_size + this->m_coordinates[0].x - 1 ) >= -grid_size / 2.0 )
    {
        for ( int i = 1; i < 2 * this->m_size - 1; i++ )
        {
            this->m_coordinates[i].x = this->m_coordinates[i - 1].x - 1;
            this->m_coordinates[i].y = this->m_coordinates[0].y;
            this->m_coordinates[i].z = this->m_coordinates[0].z;
            //grid_table[(int)(this->coordinates[i - 1].x + grid_size/2 - 1)][(int)(this->coordinates[i].y + grid_size/2)][(int)(this->coordinates[i].z + grid_size/2)] = 1;
        }
    }
    else if ( - ( 2 * this->m_size + this->m_coordinates[0].y - 1 ) >= -grid_size / 2.0 )
    {
        for ( int i = 1; i < 2 * this->m_size - 1; i++ )
        {
            this->m_coordinates[i].y = this->m_coordinates[i - 1].y - 1;
            this->m_coordinates[i].x = this->m_coordinates[0].x;
            this->m_coordinates[i].z = this->m_coordinates[0].z;
            //grid_table[(int)(this->coordinates[i].x + grid_size/2)][(int)(this->coordinates[i - 1].y + grid_size/2 - 1)][(int)(this->coordinates[i].z + grid_size/2)] = 1;
        }
    }
    else if ( - ( 2 * this->m_size + this->m_coordinates[0].z - 1 ) >= -grid_size / 2.0 )
    {
        for ( int i = 1; i < 2 * this->m_size - 1; i++ )
        {
            this->m_coordinates[i].z = this->m_coordinates[i - 1].z - 1;
            this->m_coordinates[i].y = this->m_coordinates[0].y;
            this->m_coordinates[i].x = this->m_coordinates[0].x;
            //grid_table[(int)(this->coordinates[i].x + grid_size/2)][(int)(this->coordinates[i].y + grid_size/2)][(int)(this->coordinates[i - 1].z + grid_size/2 - 1)] = 1;
        }
    }
}

void snake::random_move()
{
    int x, y, z, random, k, l, m;



    for ( int i = 0; i < 2 * this->m_size - 1; i++ )
    {
again:
        random = randomNumber( 0, 5 );

        if ( i == 0 )
        {

            x = this->m_coordinates[i].x;
            y = this->m_coordinates[i].y;
            z = this->m_coordinates[i].z;

            if ( y + 1 > grid_size / 2.0 - 2.0 && y - 1 < -grid_size / 2.0 + 2.0 && x + 1 > grid_size / 2.0 - 2.0 && x - 1 < -grid_size / 2.0 + 2.0 && z - 1 < -grid_size / 2.0 + 2.0 && z + 1 > grid_size / 2.0 - 2.0 )
            {
                cerr << "A snake can't move" << endl;
                return ;
            }

            switch ( random )
            {
                case UP:
                {

                    if ( y + 1 > grid_size / 2.0 - 2.0 )
                        goto again;

                    for ( int j = 0; j < 2 * this->m_size - 1; j++ )
                    {
                        if ( this->m_coordinates[i].y + 1 == this->m_coordinates[j].y )
                            goto again;
                    }

                    this->m_coordinates[i].y++;

                    if ( collision_detection( this ) )
                    {
                        this->m_coordinates[i].y--;
                        goto again;
                    }

                    break;
                }

                case DOWN:
                {
                    if ( y - 1 < -grid_size / 2.0 + 2.0 )
                        goto again;

                    for ( int j = 0; j < 2 * this->m_size - 1; j++ )
                    {
                        if ( this->m_coordinates[i].y - 1 == this->m_coordinates[j].y )
                            goto again;
                    }

                    this->m_coordinates[i].y--;

                    if ( collision_detection( this ) )
                    {
                        this->m_coordinates[i].y++;
                        goto again;
                    }

                    break;
                }

                case RIGHT:
                {
                    if ( x + 1 > grid_size / 2.0 - 2.0 )
                        goto again;

                    for ( int j = 0; j < 2 * this->m_size - 1; j++ )
                    {
                        if ( this->m_coordinates[i].x + 1 == this->m_coordinates[j].x )
                            goto again;
                    }

                    this->m_coordinates[i].x++;

                    if ( collision_detection( this ) )
                    {
                        this->m_coordinates[i].x--;
                        goto again;
                    }

                    break;
                }

                case LEFT:
                {

                    if ( x - 1 < -grid_size / 2.0 + 2.0 )
                        goto again;

                    for ( int j = 0; j < 2 * this->m_size - 1; j++ )
                    {
                        if ( this->m_coordinates[i].x - 1 == this->m_coordinates[j].x )
                            goto again;
                    }

                    this->m_coordinates[i].x--;

                    if ( collision_detection( this ) )
                    {
                        this->m_coordinates[i].x++;
                        goto again;
                    }

                    break;
                }

                case IN:
                {
                    if ( z - 1 < -grid_size / 2.0 + 2.0 )
                        goto again;

                    for ( int j = 0; j < 2 * this->m_size - 1; j++ )
                    {
                        if ( this->m_coordinates[i].z - 1 == this->m_coordinates[j].z )
                            goto again;
                    }

                    this->m_coordinates[i].z--;

                    if ( collision_detection( this ) )
                    {
                        this->m_coordinates[i].z++;
                        goto again;
                    }

                    break;
                }

                case OUT:
                {
                    if ( z + 1 > grid_size / 2.0 - 2.0 )
                        goto again;

                    for ( int j = 0; j < 2 * this->m_size - 1; j++ )
                    {
                        if ( this->m_coordinates[i].z + 1 == this->m_coordinates[j].z )
                            goto again;
                    }

                    this->m_coordinates[i].z++;

                    if ( collision_detection( this ) )
                    {
                        this->m_coordinates[i].z--;
                        goto again;
                    }

                    break;
                }
            }
        }
        else
        {
            k = this->m_coordinates[i].x;
            l = this->m_coordinates[i].y;
            m = this->m_coordinates[i].z;

            this->m_coordinates[i].x = x;
            this->m_coordinates[i].y = y;
            this->m_coordinates[i].z = z;

            x = k;
            y = l;
            z = m;
        }
    }
}













/*
	int x, y, z, random, k, l, m;

	for(int j = 0; j < 2 * this->size - 1; j++)
	{


		if (j == 0)
		{
			x = this->coordinates[j].x;
			y = this->coordinates[j].y;
			z = this->coordinates[j].z;
			//cout << x << " " << y << " " << z << endl;
again:
			random = randomNumber(0, 5);

			//cout << random << endl;
			switch (random)
			{
			case UP:
				if(y + 1 > grid_size/2 -1 )
					goto again;
				if(this->coordinates[j].y + 1 >= grid_size/2.0 - 0.5 || grid_table[x + grid_size/2][y + grid_size/2 + 1][z + grid_size/2] == 1)
					goto again;
				this->coordinates[j].y += 1;
				grid_table[x + grid_size/2][y + grid_size/2][z + grid_size/2] = 0;
				grid_table[x + grid_size/2][y + grid_size/2 + 1][z + grid_size/2] = 1;
				break;
			case DOWN:
				if(y - 1 < -grid_size/2 + 1)
					goto again;
				if(this->coordinates[j].y - 1 <= -grid_size/2 - 0.5 || grid_table[x + grid_size/2][y + grid_size/2 - 1][z + grid_size/2] == 1)
					goto again;
				this->coordinates[j].y -= 1;
				grid_table[x + grid_size/2][y + grid_size/2][z + grid_size/2] = 0;
				grid_table[x + grid_size/2][y + grid_size/2 - 1][z + grid_size/2] = 1;
				break;
			case RIGHT:
				if(x + 1 > grid_size/2 - 1)
					goto again;
				if(this->coordinates[j].x + 1 >= grid_size/2.0 - 0.5 || grid_table[x + grid_size/2 + 1][y + grid_size/2][z + grid_size/2] == 1)
					goto again;
				this->coordinates[j].x += 1;
				grid_table[x + grid_size/2][y + grid_size/2][z + grid_size/2] = 0;
				grid_table[x + grid_size/2 + 1][y + grid_size/2][z + grid_size/2] = 1;
				break;
			case LEFT:
				if(x - 1 < -grid_size/2 + 1)
					goto again;
				if(this->coordinates[j].x - 1 <= -grid_size/2.0 - 0.5 || grid_table[x + grid_size/2 - 1][y + grid_size/2][z + grid_size/2] == 1)
					goto again;
				this->coordinates[j].x -= 1;
				grid_table[x + grid_size/2][y + grid_size/2][z + grid_size/2] = 0;
				grid_table[x + grid_size/2 - 1][y + grid_size/2][z + grid_size/2] = 1;
				break;
			case IN:
				if(z - 1 < -grid_size/2 + 1)
					goto again;
				if(this->coordinates[j].z + 1 >= grid_size/2.0 - 0.5 || grid_table[x + grid_size/2][y + grid_size/2][z + grid_size/2 - 1] == 1)
					goto again;
				this->coordinates[j].z -= 1;
				grid_table[x + grid_size/2][y + grid_size/2][z + grid_size/2] = 0;
				grid_table[x + grid_size/2][y + grid_size/2][z + grid_size/2 - 1] = 1;
				break;
			case OUT:
				if(z + 1 > grid_size/2 - 1)
					goto again;
				if(this->coordinates[j].z - 1 <= -grid_size/2.0 - 0.5 || grid_table[x + grid_size/2][y + grid_size/2][z + grid_size/2 + 1] == 1)
					goto again;
				this->coordinates[j].z += 1;
				grid_table[x + grid_size/2][y + grid_size/2][z + grid_size/2] = 0;
				grid_table[x + grid_size/2][y + grid_size/2][z + grid_size/2 + 1] = 1;
				break;
			}
		}
		else
		{
			k = this->coordinates[j].x;
			l = this->coordinates[j].y;
			m = this->coordinates[j].z;

			grid_table[k + grid_size/2][l + grid_size/2][m + grid_size/2] = 0;
			grid_table[x + grid_size/2][y + grid_size/2 - 1][z + grid_size/2] = 1;

			this->coordinates[j].x = x;
			this->coordinates[j].y = y;
			this->coordinates[j].z = z;

			x = k;
			y = l;
			z = m;
		}
	}
}*/



