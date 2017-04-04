#include "defines.h"
#include <iostream>
#include <cmath>

bool i = true;

using namespace std;
void sphere::setRandomCoord()
{
	this->position.x = randomNumber(-grid_size/2 + 1, grid_size/2 - 1);
	this->position.y = randomNumber(-grid_size/2 + 1, grid_size/2 - 1);
	this->position.z = randomNumber(-grid_size/2 + 1, grid_size/2 - 1);

	this->destination.x = randomNumber(-grid_size/2 - 1, grid_size/2 + 1) + 100;
	this->destination.y = randomNumber(-grid_size/2 - 1, grid_size/2 + 1) + 100;
	this->destination.z = randomNumber(-grid_size/2 - 1, grid_size/2 + 1) + 100;
}

void sphere::move()
{
	static float xMove, yMove, zMove;

	if(i)
	{
		xMove = abs(abs(this->destination.x) - abs(this->position.x));
		yMove = abs(abs(this->destination.y) - abs(this->position.y));
		zMove = abs(abs(this->destination.z) - abs(this->position.z));
		i = false;
	}

	if(this->position.x < -grid_size/2 + 1 || this->position.x > grid_size/2 - 1)
			this->position.x = -this->position.x;
	if(this->position.y < -grid_size/2 + 1 || this->position.y > grid_size/2 - 1)
			this->position.y = -this->position.y;
	if(this->position.z < -grid_size/2 + 1 || this->position.z > grid_size/2 - 1)
			this->position.z = -this->position.z;

	if(xMove >= yMove && xMove >= zMove)
	{
		if(this->destination.x - this->position.x >= 0)
		{
			this->position.x += 1;
			if(this->destination.y - this->position.y >= 0)
			{
				this->position.y += (float)yMove/xMove;
				if(this->destination.z - this->position.z >= 0)
				{
					this->position.z += (float)zMove/xMove;
				}
				else
				{
					this->position.z -= (float)zMove/xMove;
				}
			}
			else
			{
				this->position.y -= (float)yMove/xMove;
				if(this->destination.z - this->position.z >= 0)
				{
					this->position.z += (float)zMove/xMove;
				}
				else
				{
					this->position.z -= (float)zMove/xMove;
				}
			}
		}
		else
		{
			this->position.x -= 1;
			if(this->destination.y - this->position.y >= 0)
			{
				this->position.y += (float)yMove/xMove;
				if(this->destination.z - this->position.z >= 0)
				{
					this->position.z += (float)zMove/xMove;
				}
				else
				{
					this->position.z -= (float)zMove/xMove;
				}
			}
			else
			{
				this->position.y -= (float)yMove/xMove;
				if(this->destination.z - this->position.z >= 0)
				{
					this->position.z += (float)zMove/xMove;
				}
				else
				{
					this->position.z -= (float)zMove/xMove;
				}
			}
		}
		
	}
	else if(yMove >= xMove && yMove >= zMove)
	{
		if(this->destination.x - this->position.x >= 0)
		{
			this->position.x += (float)xMove/yMove;
			if(this->destination.y - this->position.y >= 0)
			{
				this->position.y += 1;
				if(this->destination.z - this->position.z >= 0)
				{
					this->position.z += (float)zMove/yMove;
				}
				else
				{
					this->position.z -= (float)zMove/yMove;
				}
			}
			else
			{
				this->position.y -= 1;
				if(this->destination.z - this->position.z >= 0)
				{
					this->position.z += (float)zMove/yMove;
				}
				else
				{
					this->position.z -= (float)zMove/yMove;
				}
			}
		}
		else
		{
			this->position.x -= (float)xMove/yMove;
			if(this->destination.y - this->position.y >= 0)
			{
				this->position.y += 1;
				if(this->destination.z - this->position.z >= 0)
				{
					this->position.z += (float)zMove/yMove;
				}
				else
				{
					this->position.z -= (float)zMove/yMove;
				}
			}
			else
			{
				this->position.y -= 1;
				if(this->destination.z - this->position.z >= 0)
				{
					this->position.z += (float)zMove/yMove;
				}
				else
				{
					this->position.z -= (float)zMove/yMove;
				}
			}
		}
	}
	else
	{
		if(this->destination.x - this->position.x >= 0)
		{
			this->position.x += (float)xMove/zMove;
			if(this->destination.y - this->position.y >= 0)
			{
				this->position.y += yMove/zMove;
				if(this->destination.z - this->position.z >= 0)
				{
					this->position.z += 1;
				}
				else
				{
					this->position.z -= 1;
				}
			}
			else
			{
				this->position.y -= yMove/zMove;
				if(this->destination.z - this->position.z >= 0)
				{
					this->position.z += 1;
				}
				else
				{
					this->position.z -= 1;
				}
			}
		}
		else
		{
			this->position.x -= (float)xMove/zMove;
			if(this->destination.y - this->position.y >= 0)
			{
				this->position.y += yMove/zMove;
				if(this->destination.z - this->position.z >= 0)
				{
					this->position.z += 1;
				}
				else
				{
					this->position.z -= 1;
				}
			}
			else
			{
				this->position.y -= yMove/zMove;
				if(this->destination.z - this->position.z >= 0)
				{
					this->position.z += (float)zMove/zMove;
				}
				else
				{
					this->position.z -= (float)zMove/zMove;
				}
			}
		}
	} 

}
