#include <stdio.h>
#include <stdlib.h>


int* ReadFromFile(char* path)
{
	FILE* myFile;
	myFile = fopen(path,"r");
	int tabSize;
	fscanf(myFile,"%d",&tabSize);
	int* myTab = malloc(sizeof(int)*(tabSize));

	for(int i = 0;i < tabSize;i++)
	{
		fscanf(myFile,"%d",&myTab[i]);
	}	
	return myTab;
}


void PrinTab(int* tab,int n, int m)
{
	for(int i = n;i < m;i++)
		printf("[%d]\n",tab[i]);
}

int MyFunction(int* tab, int n,int tabSize)
{
	int** tab2D = malloc(sizeof(int*)*2);
	for(int i = 0;i < 2;i++)
		tab2D[i] = malloc(sizeof(int)*tabSize);

	int* reszTab = malloc(sizeof(int)*tabSize);
	for(int i = 0;i < n;i++)
		reszTab[i] = -1;

	for(int i = 0;i < tabSize;i++)
		tab2D[0][i] = tab[i];

	tab2D[1][0] = tab2D[0][0]%n;
	for(int i = 1;i < tabSize;i++)
	{
		tab2D[1][i] = (tab2D[1][i-1]+tab2D[0][i])%n;
		if(reszTab[ tab2D[1][i] ] == -1)
			reszTab[ tab2D[1][i] ] = i;
		else
			{

				PrinTab(tab2D[0],reszTab[tab2D[1][i]]+1,i);
			}

		if(tab2D[1][i] == 0){
			PrinTab(tab2D[0],0,i);
			return 0;
		}
	}
	
	


	return 0;
}


int main()
{
	int* tab = ReadFromFile("podz1.csv");
	MyFunction(tab,100,1000);
	
	return 0;
}