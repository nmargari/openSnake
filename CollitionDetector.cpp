#include "defines.h"
#include <iostream>
using namespace std;

CollitionDetector::CollitionDetector()
{
    //
}

bool CollitionDetector::collision_detection( snake* s )
{
    for ( int i = 0; i < snake_num; i++ )
    {
        if ( snake_array + i == s )
            continue;

        for ( int j = 0; j < 2 * snake_array[i].getSize() - 1; j++ )
        {
            if ( snake_array[i].getCoord()[j].x == s->getCoord()[0].x &&
                 snake_array[i].getCoord()[j].y == s->getCoord()[0].y &&
                 snake_array[i].getCoord()[j].z == s->getCoord()[0].z )
            {
                return true;
            }
        }
    }

    return false;
}

void CollitionDetector::random_move()
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
