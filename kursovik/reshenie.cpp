//    5. Блок решений включает следующие точные или приближенные способы решения предложенных оптимизационных задач (задач выбора наилучших решений из множества допустимых решений):
//        5.1. Эвристическое решение;
//        5.2. Полный перебор множества допустимый решений.

#include <iostream> 
#include <vector>
#include "main.h"

using  namespace  std;

struct node
{
	int i;
	int j;
};

void reshenie()
{
	void (*operations[])() = {reshenie_1, reshenie_2, nothing};

	cout << "1. Эвристическое решение;" << endl;
	cout << "2. Полный перебор множества допустимый решений." << endl;
	cout << "3. Возврат в главное меню"<< endl;

	int var;
	var = vybor(3);
	operations[var-1]();
}

void reshenie_1()
{
	vector<int> result;	

	//search min
	int imin=0, jmin=0, ib, jb;
	int *begin, *end;
	double tmin = T[0][1];
	double tmini,tminj;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if(i != j && T[i][j] < tmin)
			{
				tmin = T[i][j];
				imin = i;
				jmin = j;
			}
	result.push_back(imin);
	result.push_back(jmin);

	while( result.size() != N )
	{
		begin = result.begin();
		end = result.end();
		//find i not in result
		for (int i=0; i<N; i++)
			if(find(begin,end,i) == end)
			{
				imin = i;
				break;
			}

		tmin = T[imin][*begin];

		for (int i=imin; i<N; i++)
			if(i != j && find(begin,end,i) == end; && T[i][*begin] < tmini)
			{
				tmini = T[i][*begin];
				imin = i;
			}

		result.insert(begin, imin);
/*
		tminj = j;
		for (int j=0; j<N; j++)
			if(i != j && T[result.end()][j] < tmin)
			{
				tmin = T[result.end()][j];
				jmin = j;
			}

*/
	
		for(auto x: result )
			cout << x+1 << " ";
		cout << endl;
	
	}
	
/*
	//sort array by time
	double tmin = T[0][0];
	double* Tsort = new double[N*N];
	for (int k=0; k<N; k++)
		for (int l=0; l<N; l++)
		{
			for (int i=k; i<N; i++)
				for (int j=l; j<N; j++)
					if(i != j)
						if(T[i][j] < tmin)
						{
							tmin = T[i][j];
							imin = i;
							jmin = j;
						}
*/


	
}

void reshenie_2()
{}

