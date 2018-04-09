
  #include "stdio.h"
  #include "stdlib.h"

   #define VNUM 9
   #define MV 65536//��ʾ�߲��ɴ�

int P[VNUM];//��¼��
int Cost[VNUM];//�洢ÿһ������Ҫ�ķѵĳɱ�
int Mark[VNUM];//��Ƕ���
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

void Prim(int sv)//��sv��㿪ʼ
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
			if ((min > Cost[j])&&( !Mark[j]))//�����һ��δ����ǵĵ���Ϊ��С��·��
			{
				min = Cost[j];
				index = j;
			}
		}

		if (index != -1)//˵���ҵ�����С·���ı�
		{
			Mark[index] = 1;
			printf("(%d,%d,%d)", P[index], index, Cost[index]);

		}

		for (j = 0; j < VNUM; j++)
		{
			//�Ӹոձ���ʾ�Ķ�����Ϊ��ʼ����
			if (!Mark[j] && (Matrix[index][j] < Cost[j]))
			{
				Cost[j] = Matrix[index][j];
				P[j] = index;//����и�С�ģ���ô�˱ߵ���ʼ����ΪP[i]��Ȩֵ���浽const������
			}
		}
	}
}

int main()
{
	Prim(0);

	return 0;
}
