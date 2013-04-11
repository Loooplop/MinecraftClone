#ifndef PLAYER_H
#define PLAYER_H
#include "vertice.h"
/*
 * No description
 */
class Player
{
	// private section
	public:
		// class constructor
		Player();
		// class destructor
		~Player();
		Vertice Coordinates;
		float xrot,yrot,zrot;
		Vertice CurrentBlock;
};

#endif // CAMERA_H

