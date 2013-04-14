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
#include "Player.h"
#define BlockSize 4.0f
#define Speed .25f
#define CHUNK_SIZE_Refer 10.0f
int H;
int W;
    void Move_CameraBack(Player &P)
    {
    P.Coordinates.CoordinateZ += Speed;	
    }
    void Move_CameraFront(Player &P)
    {
    P.Coordinates.CoordinateZ -= Speed ;
     }
    void Move_CameraRight(Player &P){
    P.Coordinates.CoordinateX += Speed;
     }
     void Move_CameraLeft(Player &P){
            P.Coordinates.CoordinateX -=Speed;
     }
bool Wireframe=true;
Player Human;
Chunk ch;
Block h;
int d;
int I=0;
GLuint i;
void GetPlayerBlock(int x,int y,int z);
void LoadTexture()
{
		if(I==0)
		{
		  i=loadTexture("C:/Users/Progr_Anim/Desktop/Ryu/MinecraftClone/Textures/DirtBlock.bmp");
		  
	ch.Optimization(Human);
		  I=1;
		}
		else
		{
		
		};
}
void CreateBlocks()
{
     glBegin(GL_LINES);
        glVertex3f(Human.GetPosX()-0.1f,Human.GetPosY(),Human.GetPosZ()-2.0f);
        glVertex3f(Human.GetPosX()+0.1f,Human.GetPosY(),Human.GetPosZ()-2.0f);
        
        glVertex3f(Human.GetPosX(),Human.GetPosY()-0.1f,Human.GetPosZ()-2.0f);
        glVertex3f(Human.GetPosX(),Human.GetPosY()+0.1f,Human.GetPosZ()-2.0f);
     glEnd();
     
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
void renderBitmapString(
		float x,
		float y,
		float z,
		void *font,
		char *string) {

  char *c;
  glRasterPos3f(x, y,z);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
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
  void CalculateFrameRate()
    {

        static float framesPerSecond    = 0.0f;       // This will store our fps
        static float lastTime   = 0.0f;       // This will hold the time from the last frame
        float currentTime = GetTickCount() * 0.001f;    
        ++framesPerSecond;
        if( currentTime - lastTime > 1.0f )
        {
            lastTime = currentTime;
            d=(int)framesPerSecond;
            framesPerSecond = 0;
        }
    }
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	camera();
	char Loc[30];
	char CuBck[30];
	char FPS[10];
	sprintf(CuBck,"Current_Block:%.0f,%.0f,%.0f",Human.GetCuBckX(),Human.GetCuBckY(),Human.GetCuBckZ());
	sprintf(Loc,"Loc:%.2f,%.2f,%.2f",Human.GetPosX(),Human.GetPosY(),Human.GetPosZ());
	sprintf(FPS,"FPS=%d",d);
	renderBitmapString(Human.GetPosX()-1.1f,Human.GetPosY()+0.8f,Human.GetPosZ()-2.0f,GLUT_BITMAP_HELVETICA_10,Loc);
	renderBitmapString(Human.GetPosX()-1.1f,Human.GetPosY()+0.76f,Human.GetPosZ()-2.0f,GLUT_BITMAP_HELVETICA_10,FPS);
	renderBitmapString(Human.GetPosX()-1.1f,Human.GetPosY()+0.72f,Human.GetPosZ()-2.0f,GLUT_BITMAP_HELVETICA_10,CuBck);
	LoadTexture();
	WireFrame();
	CreateBlocks();
	glutSwapBuffers();
	CalculateFrameRate();
}
void Key(unsigned char key,int x,int y)
{
    if (key=='w')
    {
       Move_CameraFront(Human);
       
	ch.Optimization(Human);
    }

    if (key=='s')
    {
    	 Move_CameraBack(Human);
    	 
	ch.Optimization(Human);
    }

    if (key=='d')
    {
    	Move_CameraRight(Human);
    	
	ch.Optimization(Human);
    }

    if (key=='a')
    {
       Move_CameraLeft(Human);
       
	ch.Optimization(Human);
    }
    if(key=='b')
    {
      ch.CnkDta[(int)Human.GetCuBckX()][(int)Human.GetCuBckY()][(int)Human.GetCuBckZ()-1].BeRendered=false;
      ch.Setup_Sphere();          
    };
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
    	//cout<<Human.CurrentBlock.CoordinateX<<","<<Human.CurrentBlock.CoordinateY<<","<<Human.CurrentBlock.CoordinateZ<<endl;
    }
    if(key=='t')
    {
    	
		Human.Coordinates.CoordinateY-=.5f;
		ch.Optimization(Human);
		//ch.CnkDta[5][7][3].BeRendered=false;
    }
    if(key=='y')
    {
    	Human.Coordinates.CoordinateY+=.5f;
    	ch.Optimization(Human);
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


