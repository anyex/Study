
  #include "stdio.h"
  #include "stdlib.h"

   #define VNUM 9
   #define MV 65536//表示边不可达

int P[VNUM];//记录边
int Cost[VNUM];//存储每一条边所要耗费的成本
int Mark[VNUM];//标记顶点
int Matrix[VNUM][VNUM] =
{
	{ 0, 10, MV, MV, MV, 11, MV, MV, MV },
	{ 10, 0, 18, MV, MV, MV, 16, MV, 12 },
	{ MV, 18, 0, 22, MV, MV, MV, MV, 8 },
	{ MV, MV, 22, 0, 20, MV, MV, 16, 21 },
	{ MV, MV, MV, 20, 0, 26, MV, 7, MV },
	{ 11, MV, MV, MV, 26, 0, 17, MV, MV },
	{ MV, 16, MV, MV, MV, 17, 0, 19, MV },
	{ MV, MV, MV, 16, 7, MV, 19, 0, MV },
	{ MV, 12, 8, 21, MV, MV, MV, MV, 0 },
};

void Prim(int sv)//从sv结点开始
{
	int i = 0;
	int j = 0;

	if ((0 <= sv) && (sv < VNUM))
	{
		for (i = 0; i < VNUM; i++)
		{
			Cost[i] = Matrix[sv][i];
			P[i] = sv;
			Mark[i] = 0;
		}
	}

	Mark[sv] = 1;
	for (i = 0; i < VNUM; i++)
	{
		int index = -1;
		int min = MV;
		
		for (j = 0; j < VNUM; j++)
		{
			if ((min > Cost[j])&&( !Mark[j]))//如果是一个未被标记的点且为更小的路径
			{
				min = Cost[j];
				index = j;
			}
		}

		if (index != -1)//说明找到了最小路径的边
		{
			Mark[index] = 1;
			printf("(%d,%d,%d)", P[index], index, Cost[index]);

		}

		for (j = 0; j < VNUM; j++)
		{
			//从刚刚被标示的顶点作为起始顶点
			if (!Mark[j] && (Matrix[index][j] < Cost[j]))
			{
				Cost[j] = Matrix[index][j];
				P[j] = index;//如果有更小的，那么此边的起始顶点为P[i]，权值保存到const数组中
			}
		}
	}
}

int main()
{
	Prim(0);

	return 0;
}
