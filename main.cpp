#include <GL/glut.h>
#include <stdarg.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "block.h"
#include "ReadBlockData.h"
#include "texturemanager.h"
#include "chunk.h"
#define BlockSize 4.0f
#define CHUNK_SIZE_Refer 10.0f

    void Move_CameraBack(Player &P)
    {
    P.Coordinates.CoordinateZ += .5f;	
    }
    void Move_CameraFront(Player &P)
    {
    P.Coordinates.CoordinateZ -= .5f ;
     }
    void Move_CameraRight(Player &P){
    P.Coordinates.CoordinateX += .5f;
     }
     void Move_CameraLeft(Player &P){
            P.Coordinates.CoordinateX -=.5f;
     }
bool Wireframe=true;
Player Human;
Chunk ch;
Block h;
int I=0;
GLuint i;
void GetPlayerBlock(int x,int y,int z);
void LoadTexture()
{
		if(I==0)
		{
		  i=loadTexture("C:/Users/Progr_Anim/Desktop/Ryu/MinecraftClone/Textures/DirtBlock.bmp");
		  I=1;
		}
		else
		{
		
		};
}
void CreateBlocks()
{
    ch.RenderChunk(0.0f,0.0f,0.0f,i,Human);
};
void CoutPlayerPos(float newXpos,float newYpos,float newZpos)
{
		cout<<"Player Pos =  "<<"("<<newXpos<<","<<newYpos<<","<<newZpos<<")"<<endl;
}
void resize(int width, int height)
{	
    glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,(double)width/(double)height,1.0,300.0);
}
void camera (void) {
    glRotatef(Human.xrot,1.0,0.0,0.0);  //rotate our camera on teh x-axis (left and right)
    glRotatef(Human.yrot,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
    glTranslated(-Human.Coordinates.CoordinateX,-Human.Coordinates.CoordinateY,-Human.Coordinates.CoordinateZ); //translate the screen to the position of our camera
}
void WireFrame(void)
{
	if(Wireframe==true)
    	{
    		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    	}
    	else if(Wireframe==false)
    	{
    		glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    	};
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	
	
    //setShaders("Vert.txt","Frag.txt");
	camera();
	LoadTexture();
	WireFrame();
	CreateBlocks();
    glutSwapBuffers();
}
void Key(unsigned char key,int x,int y)
{
    if (key=='w')
    {
       Move_CameraFront(Human);
    }

    if (key=='s')
    {
    	 Move_CameraBack(Human);
    }

    if (key=='d')
    {
    	Move_CameraRight(Human);
    }

    if (key=='a')
    {
       Move_CameraLeft(Human);
    }
    if(key=='c')
    {
    	if(Wireframe==true)
    	{
    		Wireframe=false;
    	}
    	else if(Wireframe==false)
    	{
    		Wireframe=true;
    	};
    }
    if(key=='g')
    {
    	//CoutPlayerPos(Human.Coordinates.CoordinateX,Human.Coordinates.CoordinateY,Human.Coordinates.CoordinateZ);
    	ch.Optimization(Human);
    	cout<<Human.CurrentBlock.CoordinateX<<","<<Human.CurrentBlock.CoordinateY<<","<<Human.CurrentBlock.CoordinateZ<<endl;
    }
    if(key=='t')
    {
    	
		Human.Coordinates.CoordinateY-=.5f;
		//ch.CnkDta[5][7][3].BeRendered=false;
    }
    if(key=='y')
    {
    	Human.Coordinates.CoordinateY+=.5f;
    	//ch.CnkDta[5][7][3].BeRendered=true;
		
    }
    if (key==27)
    {
    exit(0);
    }; 
};
int main(int argc, char *argv[])
{

   
    glutInitWindowSize(640,480);
    glutInitWindowPosition(40,40);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Minercraft");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(Key);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();

    return 0;
}


