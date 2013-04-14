#include "Player.h" // class's header file
#define BlockSizes 4.0f
// class constructor
Player::Player()
{
	Coordinates.AddDefault(0.0f,0.0f,0.0f);
}
// class destructor
Player::~Player()
{
	// insert your code here
}
void Player::Apply_Gravity()
{
    Coordinates.CoordinateY -= 0.1f;                       
}
float Player::GetPosX()
{
     return Coordinates.CoordinateX;
};
float Player::GetPosY()
{
     return Coordinates.CoordinateY; 
};
float Player::GetPosZ()
{
      return Coordinates.CoordinateZ;
};

float Player::GetCuBckX()
{
     return CurrentBlock.CoordinateX;
};
float Player::GetCuBckY()
{
     return CurrentBlock.CoordinateY; 
};
float Player::GetCuBckZ()
{
      return CurrentBlock.CoordinateZ;
};
