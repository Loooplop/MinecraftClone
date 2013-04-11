#include "chunk.h" // class's header file
#include "WillLib_VertFunc.h"
#include "noise.h"
#include <iostream>
#define Block 4.0f
using namespace std;
//define BlockSsize 4;
Chunk::Chunk()
{
	int height;
	for(int x=0;x<CHUNK_SIZE;x++)
    {
	   for(int z=0;z<CHUNK_SIZE;z++)
	     {
	     	height=(int)scaled_octave_noise_2d(2.0f,0.5f,0.25f,0,CHUNK_SIZE-1,x,z);
		    for(int y=0;y<height;y++)
		    {
	            CnkDta[x][y][z].BeRendered=true;
            }
            for(int y=height;y<CHUNK_SIZE;y++)
            {
            	CnkDta[x][y][z].BeRendered=false;
            }
         }
    };
}
// class destructor
Chunk::~Chunk()
{
	// insert your code here
}

void Chunk::Optimization(Player &Human)
{
	if(IsPlayerInsideSquare(Human,(0.0f)-2.0f,(CHUNK_SIZE*Block)+2.0f,(0.0f)-2.0f,(CHUNK_SIZE*Block)+2.0f,(0.0f)-2.0f,(CHUNK_SIZE*Block)+2.0f)==4)
	{
     for(int x=0;x<CHUNK_SIZE;x++)
     {
     	for(int z=0;z<CHUNK_SIZE;z++)
     	{
		    for(int y=0;y<CHUNK_SIZE;y++)
		    {
	            if(IsPlayerInsideSquare(Human,(x*Block)-2.0f,(x*Block)+2.0f,(y*Block)-2.0f,(y*Block)+2.0f,(z*Block)-2.0f,(z*Block)+2.0f)==4)
	            {
	            	if(CnkDta[x][y][z].BeRendered==true)
	            	{
	            		cout<<"This Block is Solid"<<endl;
	            	};
					if(CnkDta[x][y][z].BeRendered==false)
	            	{
	            		cout<<"This Block is Not Solid"<<endl;
	            	};
	            	Human.CurrentBlock.AddDefault(x,y,z);
	            	break;
	            };
	            
            };
        };
     };
    }
    else
	{
    	cout<<"Outside Chunk"<<endl;
    };
}
void Chunk::RenderChunk(float Chunkx,float Chunky,float Chunkz,GLuint A,Player Play)
{
	Chunk::Setup_Sphere();
	for(int x=0;x<CHUNK_SIZE;x++)
    {
	   for(int y=0;y<CHUNK_SIZE;y++)
	     {
		    for(int z=0;z<CHUNK_SIZE;z++)
		    {
	            if(CnkDta[x][y][z].BeRendered==true)
	            {
	            	CreateBlock(x*Block+(Chunkx*CHUNK_SIZE*Block),y*Block+(Chunky*CHUNK_SIZE*Block),z*Block+(Chunkz*CHUNK_SIZE*Block),Block,A,CnkDta[x][y][z]);
	            }
            }
         }
    };
}
void Chunk::Setup_Sphere()
{
   for(int x=0;x<CHUNK_SIZE;x++)
    {
	   for(int y=0;y<CHUNK_SIZE;y++)
	     {
		    for(int z=0;z<CHUNK_SIZE;z++)
		    {
	            if(CnkDta[x][y][z].BeRendered==true)
	            {
	            	if(CnkDta[x][y+1][z].BeRendered==true)
	            	{
	            		CnkDta[x][y][z].Top=false;
	            	}
	            	if(CnkDta[x][y-1][z].BeRendered==true)
	            	{
	            		CnkDta[x][y][z].Bottom=false;
	            	}
	            	if(CnkDta[x+1][y][z].BeRendered==true)
	            	{
	            		CnkDta[x][y][z].Right=false;
	            	}
	            	if(CnkDta[x-1][y][z].BeRendered==true)
	            	{
	            		CnkDta[x][y][z].Left=false;
	            	}
	            	if(CnkDta[x][y][z+1].BeRendered==true&&z<=CHUNK_SIZE-2)
	            	{
	            		CnkDta[x][y][z].Front=false;
	            	}
	            	if(CnkDta[x][y][z-1].BeRendered==true&&z>0)
	            	{
	            		CnkDta[x][y][z].Back=false;
	            	}
	            }
            }
         }
    };
}
