#include <iostream>
#include <fstream>
#include "block.h"
#include "WillLib_VertFunc.h"
#include <stdio.h>
using namespace std;
int chti(char LetterNumber)
{
  switch(LetterNumber)
  {
  case '0':
       return 0;
       break;
  case '1':
       return 1;
       break;             
  };       
};
int *ReadBlockFile(const char*filename)
{
    ifstream file;
    char output[25];
   static int Data[25];
    file.open(filename);
     file>>output;
      file.close();
      for(int i=0;i<25;i++)
      {
       Data[i]=chti(output[i]);
       };
       free(output);
       return Data;
};
void RenderBlocks(const char*filename,float y, GLuint i,GLuint a,GLuint s)
{
       int *Data=ReadBlockFile(filename);
       Block Qu[25];
       Qu[0].Rendered(Data[0]); Qu[0].TTT(-2.0f,y,2.0f);
       Qu[1].Rendered(Data[1]); Qu[1].TTT(-1.0f,y,2.0f);
       Qu[2].Rendered(Data[2]); Qu[2].TTT(0.0f,y,2.0f);
       Qu[3].Rendered(Data[3]); Qu[3].TTT(1.0f,y,2.0f);
       Qu[4].Rendered(Data[4]); Qu[4].TTT(2.0f,y,2.0f);
       
       Qu[5].Rendered(Data[5]); Qu[5].TTT(-2.0f,y,1.0f);
       Qu[6].Rendered(Data[6]); Qu[6].TTT(-1.0f,y,1.0f);
       Qu[7].Rendered(Data[7]); Qu[7].TTT(0.0f,y,1.0f);
       Qu[8].Rendered(Data[8]); Qu[8].TTT(1.0f,y,1.0f);
       Qu[9].Rendered(Data[9]); Qu[9].TTT(2.0f,y,1.0f);
       
       Qu[10].Rendered(Data[10]); Qu[10].TTT(-2.0f,y,0.0f);
       Qu[11].Rendered(Data[11]); Qu[11].TTT(-1.0f,y,0.0f);
       Qu[12].Rendered(Data[12]); Qu[12].TTT(0.0f,y,0.0f);
       Qu[13].Rendered(Data[13]); Qu[13].TTT(1.0f,y,0.0f);
       Qu[14].Rendered(Data[14]); Qu[14].TTT(2.0f,y,0.0f);
       
       Qu[15].Rendered(Data[15]); Qu[15].TTT(-2.0f,y,-1.0f);
       Qu[16].Rendered(Data[16]); Qu[16].TTT(-1.0f,y,-1.0f);
       Qu[17].Rendered(Data[17]); Qu[17].TTT(0.0f,y,-1.0f);
       Qu[18].Rendered(Data[18]); Qu[18].TTT(1.0f,y,-1.0f);
       Qu[19].Rendered(Data[19]); Qu[19].TTT(2.0f,y,-1.0f);
       
       Qu[20].Rendered(Data[20]); Qu[20].TTT(-2.0f,y,-2.0f);
       Qu[21].Rendered(Data[21]); Qu[21].TTT(-1.0f,y,-2.0f);
       Qu[22].Rendered(Data[22]); Qu[22].TTT(0.0f,y,-2.0f);
       Qu[23].Rendered(Data[23]); Qu[23].TTT(1.0f,y,-2.0f);
       Qu[24].Rendered(Data[24]); Qu[24].TTT(2.0f,y,-2.0f);
        for(int y=0;y<26;y++)
       {
       if(Qu[y].BeRendered==true)
       {
        CreateBlock(Qu[y].x*4.0f,Qu[y].y*4.0f,Qu[y].z*4.0f,4.0f,i,Qu[y]);                     
       }
       else if(Qu[y].BeRendered==false){}        
       };     
};
