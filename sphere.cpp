#include "defines.h"
#include <iostream>
#include <cmath>

bool i = true;

using namespace std;

coord sphere::getDestination()
{
    return this->m_destination;
}

coord sphere::getPosition()
{
    return this->m_position;
}

void sphere::setDestination( coord dest )
{
    this->m_destination = dest;
}

void sphere::setPosition( coord pos )
{
    this->m_position = pos;
}

void sphere::setRandomCoord()
{
    this->m_position.x = randomNumber( -grid_size / 2 + 1, grid_size / 2 - 1 );
    this->m_position.y = randomNumber( -grid_size / 2 + 1, grid_size / 2 - 1 );
    this->m_position.z = randomNumber( -grid_size / 2 + 1, grid_size / 2 - 1 );

    this->m_destination.x = randomNumber( -grid_size / 2 - 1, grid_size / 2 + 1 ) + 100;
    this->m_destination.y = randomNumber( -grid_size / 2 - 1, grid_size / 2 + 1 ) + 100;
    this->m_destination.z = randomNumber( -grid_size / 2 - 1, grid_size / 2 + 1 ) + 100;
}

void sphere::move()
{
    static float xMove, yMove, zMove;

    if ( i )
    {
        xMove = abs( abs( this->m_destination.x ) - abs( this->m_position.x ) );
        yMove = abs( abs( this->m_destination.y ) - abs( this->m_position.y ) );
        zMove = abs( abs( this->m_destination.z ) - abs( this->m_position.z ) );
        i = false;
    }

    if ( this->m_position.x < -grid_size / 2 + 1 || this->m_position.x > grid_size / 2 - 1 )
        this->m_position.x = -this->m_position.x;

    if ( this->m_position.y < -grid_size / 2 + 1 || this->m_position.y > grid_size / 2 - 1 )
        this->m_position.y = -this->m_position.y;

    if ( this->m_position.z < -grid_size / 2 + 1 || this->m_position.z > grid_size / 2 - 1 )
        this->m_position.z = -this->m_position.z;

    if ( xMove >= yMove && xMove >= zMove )
    {
        if ( this->m_destination.x - this->m_position.x >= 0 )
        {
            this->m_position.x += 1;

            if ( this->m_destination.y - this->m_position.y >= 0 )
            {
                this->m_position.y += ( float )yMove / xMove;

                if ( this->m_destination.z - this->m_position.z >= 0 )
                {
                    this->m_position.z += ( float )zMove / xMove;
                }
                else
                {
                    this->m_position.z -= ( float )zMove / xMove;
                }
            }
            else
            {
                this->m_position.y -= ( float )yMove / xMove;

                if ( this->m_destination.z - this->m_position.z >= 0 )
                {
                    this->m_position.z += ( float )zMove / xMove;
                }
                else
                {
                    this->m_position.z -= ( float )zMove / xMove;
                }
            }
        }
        else
        {
            this->m_position.x -= 1;

            if ( this->m_destination.y - this->m_position.y >= 0 )
            {
                this->m_position.y += ( float )yMove / xMove;

                if ( this->m_destination.z - this->m_position.z >= 0 )
                {
                    this->m_position.z += ( float )zMove / xMove;
                }
                else
                {
                    this->m_position.z -= ( float )zMove / xMove;
                }
            }
            else
            {
                this->m_position.y -= ( float )yMove / xMove;

                if ( this->m_destination.z - this->m_position.z >= 0 )
                {
                    this->m_position.z += ( float )zMove / xMove;
                }
                else
                {
                    this->m_position.z -= ( float )zMove / xMove;
                }
            }
        }

    }
    else if ( yMove >= xMove && yMove >= zMove )
    {
        if ( this->m_destination.x - this->m_position.x >= 0 )
        {
            this->m_position.x += ( float )xMove / yMove;

            if ( this->m_destination.y - this->m_position.y >= 0 )
            {
                this->m_position.y += 1;

                if ( this->m_destination.z - this->m_position.z >= 0 )
                {
                    this->m_position.z += ( float )zMove / yMove;
                }
                else
                {
                    this->m_position.z -= ( float )zMove / yMove;
                }
            }
            else
            {
                this->m_position.y -= 1;

                if ( this->m_destination.z - this->m_position.z >= 0 )
                {
                    this->m_position.z += ( float )zMove / yMove;
                }
                else
                {
                    this->m_position.z -= ( float )zMove / yMove;
                }
            }
        }
        else
        {
            this->m_position.x -= ( float )xMove / yMove;

            if ( this->m_destination.y - this->m_position.y >= 0 )
            {
                this->m_position.y += 1;

                if ( this->m_destination.z - this->m_position.z >= 0 )
                {
                    this->m_position.z += ( float )zMove / yMove;
                }
                else
                {
                    this->m_position.z -= ( float )zMove / yMove;
                }
            }
            else
            {
                this->m_position.y -= 1;

                if ( this->m_destination.z - this->m_position.z >= 0 )
                {
                    this->m_position.z += ( float )zMove / yMove;
                }
                else
                {
                    this->m_position.z -= ( float )zMove / yMove;
                }
            }
        }
    }
    else
    {
        if ( this->m_destination.x - this->m_position.x >= 0 )
        {
            this->m_position.x += ( float )xMove / zMove;

            if ( this->m_destination.y - this->m_position.y >= 0 )
            {
                this->m_position.y += yMove / zMove;

                if ( this->m_destination.z - this->m_position.z >= 0 )
                {
                    this->m_position.z += 1;
                }
                else
                {
                    this->m_position.z -= 1;
                }
            }
            else
            {
                this->m_position.y -= yMove / zMove;

                if ( this->m_destination.z - this->m_position.z >= 0 )
                {
                    this->m_position.z += 1;
                }
                else
                {
                    this->m_position.z -= 1;
                }
            }
        }
        else
        {
            this->m_position.x -= ( float )xMove / zMove;

            if ( this->m_destination.y - this->m_position.y >= 0 )
            {
                this->m_position.y += yMove / zMove;

                if ( this->m_destination.z - this->m_position.z >= 0 )
                {
                    this->m_position.z += 1;
                }
                else
                {
                    this->m_position.z -= 1;
                }
            }
            else
            {
                this->m_position.y -= yMove / zMove;

                if ( this->m_destination.z - this->m_position.z >= 0 )
                {
                    this->m_position.z += ( float )zMove / zMove;
                }
                else
                {
                    this->m_position.z -= ( float )zMove / zMove;
                }
            }
        }
    }
}
