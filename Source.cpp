#include<iostream>
# include <fstream>
# include <conio.h>
#include<windows.h>               //Sleep() function needs this header file
using namespace std;
const int rows=20;
const int cols=20;
void MakeNull(char M[][cols])
{

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			M[i][j]='\0';                              //\0
		}
	}
	
}
void display (char M[][20])
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout<<M[i][j];
		}
		cout<<endl;
	}
}
int countNeighbors(char M[][cols], int i, int j)
{
	 int count=0;
	if(i!=0 && j!=19)
	{
		if(M[i-1][j+1] == 'X')
		{
			count++;
		}
	}
	if(i!=0)
	{
		if(M[i-1][j] == 'X')
		{
			count++;
		}
	}
	if(i!=0 && j!=0)
	{
		if(M[i-1][j-1] == 'X')
		{
			count++;
		}
	}
	if(j!=0)
	{
		 if(M[i][j-1] == 'X')
		{
			count++;
		}
	}
	if(i!=19 && j!=0)
	{
		if(M[i+1][j-1]=='X')
		{
			count++;
		}
	}
	if(j!=19)
	{
	    if(M[i][j+1] == 'X')
		{
			count++;
		}
	}
	if(i!=19 && j!=19)
	{
		if(M[i+1][j+1] == 'X')
		{
			count++;
		}
	}
	if(i!=19)
	{
	    if(M[i+1][j] == 'X')
	    {
	        count++;
	    }
	}
	
	return count;	

}
void aliveCell(char M[][cols],int r,int c)
{
	if(M[r][c]=='\0')
		M[r][c]='X';
}
void LoadMatrix(char M[][20])
{
	int row;
	int col = 0;
	char ch1,ch2;
	ifstream infile;
	ofstream outfile;
	infile.open("Life.txt");

	if(infile.is_open())
	{
		while(! infile.eof () )
		{	
			
			infile>>row;
			infile>>ch1;
			infile >>col;
			infile.get(ch2);
			aliveCell(M,row,col);
		}
		infile.close();
		outfile.close();
	}
}
void makeNextGeneration(char m[][cols])
{
	char B[rows][cols];
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{	
			B[i][j]=m[i][j];
		}
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{							//  ||
			if(m[i][j]=='X')                  //alive cells
			{
				int a=countNeighbors(m,i,j);
				if(a==1 || a==0)
				{
					B[i][j]='\0';
				}                                                        
				if(a==2 ||  a==3)
				{
					B[i][j]='X';
				}
				if(a>=4 )
				{
					B[i][j]='\0';
				}
			}		
			                        // not alive
			if(m[i][j]=='\0')
			{
				int b=countNeighbors(m,i,j);
				if(b==3)
				{
					B[i][j]='X';
				}
				if(b>3 || b<3)
				{
					B[i][j]='\0';
				}
			}
		}
		cout<<endl;
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{	
			m[i][j]=B[i][j];
		}
	}
}
int main()
{
	int number=0,num;
	cout<<"Enter the Number of Generations You want to produce  :  ";
	cin>>number;
	cout<<"Choose 1 if you wants to let every next generation display in one second’s span automatically"<<endl <<endl<< "Choose 2 if you wants to go to next generation on a key press.";
	cin>>num;
	while(cin.fail() || num!=1 || num!=2  )
	{
		cin.clear();
		cin.ignore();
		cout<<"Wrong input enter input again";
		cin>>num;
		if(num==1 || num==2)
			break;
	}

	char m[20][20];
	MakeNull(m);
	LoadMatrix(m);
	display(m);
	for(int i=1;i<=number;i++)
	{
		if(num==1)
		{
			makeNextGeneration(m);
			system("cls");
			display(m);
			Sleep(1000);
		}
		if(num==2)
		{
			if(getch())
			{
				makeNextGeneration(m);
				system("cls");
				display(m);
			}
		}
		
	}
	return 0;
}
