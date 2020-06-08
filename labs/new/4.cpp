//Выбрать три различные точки из заданного множества точек на плоскости так, чтобы была минимальной разность между количествами точек, лежащих внутри и вне треугольника с вершинами в выбранных точках

#include <iostream> 
#include <stdlib.h>
#include <cmath>

using  namespace  std;

int N;
struct point
{
	double x;
	double y;
};

int fnump(struct point *arr, int p1, int p2, int p3)
{
	int a,b,c,num=0;
	double x0,y0,x1,x2,x3,y1,y2,y3;

	x1 = arr[p1].x;
	y1 = arr[p1].y;
	x2 = arr[p2].x;
	y2 = arr[p2].y;
	x3 = arr[p3].x;
	y3 = arr[p3].y;

	for(int i = 0; i<N; i++)
	{
		x0 = arr[i].x;
		y0 = arr[i].y;
		a = (x1-x0)*(y2-y1)-(x2-x1)*(y1-y0);
		b = (x2-x0)*(y3-y2)-(x3-x2)*(y2-y0);
		c = (x3-x0)*(y1-y3)-(x1-x3)*(y3-y0);
		if((a>0 && b>0 && c>0) || (a<0 && b<0 && c<0))
			num++;
	}

	return num;
}

int main()
{
	cout << "Enter array size ";
	cin >> N;
	struct point * arr = new struct point[N];

	cout << "Enter array elements ";
	for(int i=0; i<N; i++)
	{
		cin >> arr[i].x;
		cin >> arr[i].y;
	}

	int nump;
	int minp = fnump(arr,0,1,2);
	int imin,jmin,kmin;

	for(int i = 0; i<N; i++)
		for(int j = 0; j<N; j++)
			if(j != i)
				for(int k = 0; k<N; k++)
					if(k != i && k != j)
					{
						nump = fnump(arr,i,j,k);
						if(nump < minp)
						{
							minp = nump;
							imin = i;
							jmin = j;
							kmin = k;
						}
					}

	cout << arr[imin].x << " , ";
	cout << arr[imin].y << " ; ";
	cout << arr[jmin].x << " , ";
	cout << arr[jmin].y << " ; ";
	cout << arr[kmin].x << " , ";
	cout << arr[kmin].y << " ; ";

	return 0;
}


