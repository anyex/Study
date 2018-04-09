

#include <stdio.h>
#include <stdlib.h>


#define VNUM 5
#define MV 65536


int P[VNUM];
int Dist[VNUM];
int Mark[VNUM];
int Matrix[VNUM][VNUM] =
{
	{ 0, 10, MV, 30, 100 },
	{ MV, 0, 50, MV, MV },
	{ MV, MV, 0, MV, 10 },
	{ MV, MV, 20, 0, 60 },
	{ MV, MV, MV, MV, 0 },
};

void Dijkstra(int sv)
{
	//初始化
	int i = 0,j=0;
	int K = 0;
	int Snum = 0;
	if (sv >= 0)
	{
		for (i = 0; i < VNUM; i++)
		{
			Dist[i] = Matrix[sv][i];
			Mark[i] = 0;
			P[i] = sv;
		}

	}
	Mark[sv] = 1;
	int num = 1;
	//找出最短K
	for(i=0;i<VNUM;i++)
	{
		int min = MV;
		int K = -1;
		for (j = 0; j < VNUM; j++)
		{
			if (min > Dist[j]&&(Mark[j]==0))
			{
				min = Dist[j];
				K = j;
			}
		}
		
		if (K > -1)
		{
			P[num++] = K;
			Mark[K] = 1;
		}
		//找出下一结点的更短路径
		for (j = 0; j < VNUM; j++)
		{
			if (Mark[j] == 0)
			{
				if (Dist[j] > (Dist[K] + Matrix[K][j]))
				{
					Dist[j] = Dist[K] + Matrix[K][j];
				}
			}
		}

	}

	for (i = 0; i < VNUM-1; i++)
	{
		printf("%d--权值(%d)->%d\t",P[0],Dist[i+1],P[i+1]);
		
	}

}
int main()
{
	Dijkstra(0);
	return 0;
}

