for each block{
 read file
 stuff bools into array
 read array and put 0 or 1 with [x][y][z] into block   
}
for each block{
 if BeRendered is true
 then render block with ([x]*BlockSize,[y]*BlockSize,[z]*Blocksize,Blocksize)   
}


[x][y(Manual)][z]
[x-2][y][z]
12345
12345
12345
12345
12345
block[3][3][3]


Chech if Player is in Chunk();
Which XZ Block is Player IS();
Calculate the height of XZ Block();
If Higher-Apply Gravity
If Lower-Increase Height
Update Player's position();

for each block
{
	for z
	{
		for x
		{
			for y
			{
				
			}
		}
	}
}
#define OutsideBth 0
#define WithinX 1
#define WithinZ 2
#define WithinXZ 3
int IsInsideSquare(float PlayerPosX,float PlayerPosY,float PlayerPosZ,float xMin,float xMax,float zMin,float zMax)
{
	int i=0
	int Axis;
	if(PlayerPosX <xMax && PlayerPosX >xMin)
	{
		i+=1;
		Axis=3;
	}
	if(PlayerPosZ <zMax && PlayerPosZ >zMin)
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
				return WithinXZ;
				break;
		};
};
void CoutInsideSquare(int x)
{
	switch(x)
		{
			case 0:
				cout<<"Outside Square"<<endl;
				break;
			case 1:
				if(Axis==3)
				{
				cout<<"Within X Limits"<<endl;
			    }
				else if(Axis==4)
				{
					cout<<"Within Z Limits"<<endl;
				}
				break;
			case 2:
				cout<<"Inside Square"<<endl;
				break;
		};
}
