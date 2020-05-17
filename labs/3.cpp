//В заданной последовательности чисел найти самую длинную подпоследовательность, которая является геометрической прогрессией
//2 4 8 1 2 4 8 3

#include <iostream> 
#include <stdlib.h>
#include <cmath>

using  namespace  std;

int N;

int ps(double* arr, int n)
{
	int size = 3;
	for(int i = n+1; i<N-2;i++)
		if(arr[i+1]/arr[i] == arr[i+2]/arr[i+1] )
			size++;

		else break;

	return size;
}
		


int main()
{
	cout << "Enter array size ";
	cin >> N;
	double * arr = new double[N];


	cout << "Enter array elements ";
	for(int i=0; i<N; i++)
		cin >> arr[i];

	int i=0;
	int imax = 0;
	int prog_size;
	int max_size = 0;

	while(i < N-2)
	{
		if(arr[i+1]/arr[i] == arr[i+2]/arr[i+1] )
		{
			prog_size = ps(arr,i);
			if(prog_size > max_size)
			{
				max_size = prog_size;
				imax = i;
			}

			i += prog_size;
			continue;
		}

		i++;
	}

	for(int i=imax; i < imax + max_size; i++)
		cout << arr[i] << " ";

	return 0;
}
	
