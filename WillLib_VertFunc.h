#ifndef IMAGELOAER_H
#define IMAGELOAER_H
#include <GL/glut.h>
#include <stdarg.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>
#include "Player.h"
#include "block.h"
#include "vertice.h"

inline void WG_Vert(Vertice L)
{
         glVertex3f(L.CoordinateX,L.CoordinateY,L.CoordinateZ);  
};
//                      X-Value,Y-Value,Z-Value,SizeofCube,SideTexture,TopTexture,BottomTexture //
inline void CreateBlock(float x,float y,float z,float s,GLuint i,Block T)
{
  float S=s/2;
  glEnable(GL_TEXTURE_2D);
	glBindTexture( GL_TEXTURE_2D, i);
    // when texture area is large, bilinear filter the first mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    
   
   
   //////////////////////////////////////////////////
  //Top
   //glColor3f(0.64f,0.16f,0.16f);
   if(T.Top==true){
   glBegin(GL_QUADS);
   glNormal3f(0.0f, 1.0f, 0.0f);
   glTexCoord2d(0.5,1.0);glVertex3f(x-S,y+S,z-S);
   glTexCoord2d(1.0,1.0);glVertex3f(x+S,y+S,z-S);
   glTexCoord2d(1.0,0.5);glVertex3f(x+S,y+S,z+S);
   glTexCoord2d(0.5,0.5);glVertex3f(x-S,y+S,z+S);
    glEnd();
   }
    
    ////////////////////////////////////////////
    if(T.Bottom==true){
  glBegin(GL_QUADS);
   //Bottom
    //glColor3f(0.56f,0.11f,0.81f);
    glNormal3f(0.0f, -1.0f, 0.0f);
   glTexCoord2d(0.0,0.5);glVertex3f(x-S,y-S,z+S);
   glTexCoord2d(0.5,0.5);glVertex3f(x+S,y-S,z+S);
   glTexCoord2d(0.5,0.0);glVertex3f(x+S,y-S,z-S);
   glTexCoord2d(0.0,0.0);glVertex3f(x-S,y-S,z-S);
    glEnd();
}
    if(T.Front==true){
  glBegin(GL_QUADS);
  //Front
  //glColor3f(1.0f,0.0f,0.0f);
  glNormal3f(0.0f, 0.0f, 1.0f);
  glTexCoord2d(0.0,1.0); glVertex3f(x-S,y+S,z+S);
  glTexCoord2d(0.5,1.0); glVertex3f(x+S,y+S,z+S);
  glTexCoord2d(0.5,0.5); glVertex3f(x+S,y-S,z+S);
  glTexCoord2d(0.0,0.5); glVertex3f(x-S,y-S,z+S);
  glEnd();
}
if(T.Back==true){
  glBegin(GL_QUADS);
  //Back
    //glColor3f(1.0f,0.5f,1.0f);
  glNormal3f(0.0f, 0.0f, -1.0f);
  glTexCoord2d(0.0,1.0);glVertex3f(x-S,y+S,z-S);
  glTexCoord2d(0.5,1.0);glVertex3f(x+S,y+S,z-S);
  glTexCoord2d(0.5,0.5);glVertex3f(x+S,y-S,z-S);
  glTexCoord2d(0.0,0.5);glVertex3f(x-S,y-S,z-S);
   glEnd();
}
   if(T.Left==true){
   glBegin(GL_QUADS);
  //Left
  //glColor3f(0.0f,1.0f,0.0f);
  glNormal3f(-1.0f, 0.0f, 0.0f);
  glTexCoord2d(0.0,1.0);glVertex3f(x-S,y+S,z+S);
  glTexCoord2d(0.5,1.0);glVertex3f(x-S,y+S,z-S);
  glTexCoord2d(0.5,0.5);glVertex3f(x-S,y-S,z-S);
  glTexCoord2d(0.0,0.5);glVertex3f(x-S,y-S,z+S);
   glEnd();
}
if(T.Right==true){
  glBegin(GL_QUADS);
  //Right
   //glColor3f(0.0f,0.0f,1.0f);
   glNormal3f(1.0f, 0.0f, 0.0f);
  glTexCoord2d(0.0,1.0);glVertex3f(x+S,y+S,z+S);
  glTexCoord2d(0.5,1.0);glVertex3f(x+S,y+S,z-S);
  glTexCoord2d(0.5,0.5);glVertex3f(x+S,y-S,z-S);
  glTexCoord2d(0.0,0.5);glVertex3f(x+S,y-S,z+S);
   glEnd();
}
};
inline void CreateNonLightBlock(float x,float y,float z,float s,GLuint i,GLuint a,GLuint R)
{
  float S=s/2;
  glEnable(GL_TEXTURE_2D);
	glBindTexture( GL_TEXTURE_2D, i);
    // when texture area is large, bilinear filter the first mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
  glBegin(GL_QUADS);
  //Front
  //glColor3f(1.0f,0.0f,0.0f);
  //glNormal3f(0.0f, 0.0f, 1.0f);
  glTexCoord2d(0.0,1.0); glVertex3f(x-S,y-S,z+S);
  glTexCoord2d(1.0,1.0); glVertex3f(x+S,y-S,z+S);
  glTexCoord2d(1.0,0.0); glVertex3f(x+S,y+S,z+S);
  glTexCoord2d(0.0,0.0); glVertex3f(x-S,y+S,z+S);
  glEnd();
  glBegin(GL_QUADS);
  //Back
    //glColor3f(1.0f,0.5f,1.0f);
  //glNormal3f(0.0f, 0.0f, -1.0f);
  glTexCoord2d(0.0,1.0);glVertex3f(x-S,y-S,z-S);
  glTexCoord2d(1.0,1.0);glVertex3f(x+S,y-S,z-S);
  glTexCoord2d(1.0,0.0);glVertex3f(x+S,y+S,z-S);
  glTexCoord2d(0.0,0.0);glVertex3f(x-S,y+S,z-S);
   glEnd();
   
   glBegin(GL_QUADS);
  //Left
  //glColor3f(0.0f,1.0f,0.0f);
  //glNormal3f(-1.0f, 0.0f, 0.0f);
  glTexCoord2d(0.0,1.0);glVertex3f(x-S,y-S,z+S);
  glTexCoord2d(1.0,1.0);glVertex3f(x-S,y-S,z-S);
  glTexCoord2d(1.0,0.0);glVertex3f(x-S,y+S,z-S);
  glTexCoord2d(0.0,0.0);glVertex3f(x-S,y+S,z+S);
   glEnd();
  glBegin(GL_QUADS);
  //Right
   //glColor3f(0.0f,0.0f,1.0f);
   //glNormal3f(1.0f, 0.0f, 0.0f);
  glTexCoord2d(0.0,1.0);glVertex3f(x+S,y-S,z+S);
  glTexCoord2d(1.0,1.0);glVertex3f(x+S,y-S,z-S);
  glTexCoord2d(1.0,0.0);glVertex3f(x+S,y+S,z-S);
  glTexCoord2d(0.0,0.0);glVertex3f(x+S,y+S,z+S);
   glEnd();
   
   
   glBindTexture( GL_TEXTURE_2D, a);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
  glBegin(GL_QUADS);
  //Top
   //glColor3f(0.64f,0.16f,0.16f);
   //glNormal3f(0.0f, 1.0f, 0.0f);
   glTexCoord2d(0.0,1.0);glVertex3f(x-S,y+S,z-S);
   glTexCoord2d(1.0,1.0);glVertex3f(x+S,y+S,z-S);
   glTexCoord2d(1.0,0.0);glVertex3f(x+S,y+S,z+S);
   glTexCoord2d(0.0,0.0);glVertex3f(x-S,y+S,z+S);
    glEnd();
    
    glBindTexture( GL_TEXTURE_2D, R);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
  glBegin(GL_QUADS);
   //Bottom
    //glColor3f(0.56f,0.11f,0.81f);
    //glNormal3f(0.0f, -1.0f, 0.0f);
   glTexCoord2d(0.0,1.0);glVertex3f(x-S,y-S,z-S);
   glTexCoord2d(1.0,1.0);glVertex3f(x+S,y-S,z-S);
   glTexCoord2d(1.0,0.0);glVertex3f(x+S,y-S,z+S);
   glTexCoord2d(0.0,0.0);glVertex3f(x-S,y-S,z+S);
    glEnd();
};
inline int GetHeight(int x,int z,int HeightLimit)
{
    int s=rand()%HeightLimit+1;
	return s;	
};
#define OutsideBth 0
#define WithinX 1
#define WithinY 2
#define WithinZ 3
#define WithinXYZ 4
using namespace std;
inline int IsInsideSquare(float PlayerPosX,float PlayerPosY,float PlayerPosZ,float xMin,float xMax,float zMin,float zMax)
{
	int i=0;
	int Axis;
	if(PlayerPosX <=xMax && PlayerPosX >=xMin)
	{
		i+=1;
		Axis=3;
	};
	if(PlayerPosZ <=zMax && PlayerPosZ >=zMin)
		{
			i+=1;
			Axis=4;
		}
		switch(i)
		{
			case 0:
				return OutsideBth;
				break;
			case 1:
				if(Axis==3)
				{
				return WithinX;
			    }
				else if(Axis==4)
				{
					return WithinZ;
				}
				break;
			case 2:
				return 3;
				break;
		};
};
inline int IsPlayerInsideSquare(Player Human,float xMin,float xMax,float yMin,float yMax, float zMin,float zMax)
{
	int a;
	if(Human.Coordinates.CoordinateX < xMax && Human.Coordinates.CoordinateX >xMin)
	{
	     if(Human.Coordinates.CoordinateY < yMax && Human.Coordinates.CoordinateY > yMin)
	     {
	        if(Human.Coordinates.CoordinateZ <= zMax && Human.Coordinates.CoordinateZ >=zMin)
	            {
                    return 4;
                };
         };
    };
}
inline void CoutInsideSquare(int x)
{
			if(x==0)
			{
				cout<<"Outside Square"<<endl;
			};
			if(x==4)
			{
				cout<<"Inside Square"<<endl;
			};
}
     inline void RenderPlayerModel(float x,float y,float z,float s,GLuint i)
     {
     	
     	 float S=s/2;
  glEnable(GL_TEXTURE_2D);
	glBindTexture( GL_TEXTURE_2D, i);
    // when texture area is large, bilinear filter the first mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    
   
   
   //////////////////////////////////////////////////
  //Top
   //glColor3f(0.64f,0.16f,0.16f);
   glBegin(GL_QUADS);
   glNormal3f(0.0f, 1.0f, 0.0f);
   glTexCoord2d(0.5,1.0);glVertex3f(x-S,y+S,z-S);
   glTexCoord2d(1.0,1.0);glVertex3f(x+S,y+S,z-S);
   glTexCoord2d(1.0,0.5);glVertex3f(x+S,y+S,z+S);
   glTexCoord2d(0.5,0.5);glVertex3f(x-S,y+S,z+S);
    glEnd();
    
    ////////////////////////////////////////////
  glBegin(GL_QUADS);
   //Bottom
    //glColor3f(0.56f,0.11f,0.81f);
    glNormal3f(0.0f, -1.0f, 0.0f);
   glTexCoord2d(0.0,0.5);glVertex3f(x-S,y-S,z+S);
   glTexCoord2d(0.5,0.5);glVertex3f(x+S,y-S,z+S);
   glTexCoord2d(0.5,0.0);glVertex3f(x+S,y-S,z-S);
   glTexCoord2d(0.0,0.0);glVertex3f(x-S,y-S,z-S);
    glEnd();
    
  glBegin(GL_QUADS);
  //Front
  //glColor3f(1.0f,0.0f,0.0f);
  glNormal3f(0.0f, 0.0f, 1.0f);
  glTexCoord2d(0.0,1.0); glVertex3f(x-S,y+S,z+S);
  glTexCoord2d(0.5,1.0); glVertex3f(x+S,y+S,z+S);
  glTexCoord2d(0.5,0.5); glVertex3f(x+S,y-S,z+S);
  glTexCoord2d(0.0,0.5); glVertex3f(x-S,y-S,z+S);
  glEnd();
  glBegin(GL_QUADS);
  //Back
    //glColor3f(1.0f,0.5f,1.0f);
  glNormal3f(0.0f, 0.0f, -1.0f);
  glTexCoord2d(0.0,1.0);glVertex3f(x-S,y+S,z-S);
  glTexCoord2d(0.5,1.0);glVertex3f(x+S,y+S,z-S);
  glTexCoord2d(0.5,0.5);glVertex3f(x+S,y-S,z-S);
  glTexCoord2d(0.0,0.5);glVertex3f(x-S,y-S,z-S);
   glEnd();
   
   glBegin(GL_QUADS);
  //Left
  //glColor3f(0.0f,1.0f,0.0f);
  glNormal3f(-1.0f, 0.0f, 0.0f);
  glTexCoord2d(0.0,1.0);glVertex3f(x-S,y+S,z+S);
  glTexCoord2d(0.5,1.0);glVertex3f(x-S,y+S,z-S);
  glTexCoord2d(0.5,0.5);glVertex3f(x-S,y-S,z-S);
  glTexCoord2d(0.0,0.5);glVertex3f(x-S,y-S,z+S);
   glEnd();
  glBegin(GL_QUADS);
  //Right
   //glColor3f(0.0f,0.0f,1.0f);
   glNormal3f(1.0f, 0.0f, 0.0f);
  glTexCoord2d(0.0,1.0);glVertex3f(x+S,y+S,z+S);
  glTexCoord2d(0.5,1.0);glVertex3f(x+S,y+S,z-S);
  glTexCoord2d(0.5,0.5);glVertex3f(x+S,y-S,z-S);
  glTexCoord2d(0.0,0.5);glVertex3f(x+S,y-S,z+S);
   glEnd();
};
#endif
