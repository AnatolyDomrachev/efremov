//    5. Блок решений включает следующие точные или приближенные способы решения предложенных оптимизационных задач (задач выбора наилучших решений из множества допустимых решений):
//        5.1. Эвристическое решение;
//        5.2. Полный перебор множества допустимый решений.

#include <iostream> 
#include <vector>
#include "main.h"
#include <algorithm>

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
	
	for(auto x: result )
		cout << x+1 << " ";
	cout << endl;

	// append other
	while( result.size() != N )
	{
		//find i not in result
		for (int i=0; i<N; i++)
			if(find(result.begin(),result.end(),i) == result.end())
			{
				imin = i;
				break;
			}

		tmini = T[imin][result.front()];

		for (int i=imin; i<N; i++)
			if(i != result.front() && find(result.begin(),result.end(),i) == result.end() && T[i][result.front()] < tmini)
			{
				tmini = T[i][result.front()];
				imin = i;
			}

		//for j
		for (int j=0; j<N; j++)
			if(find(result.begin(),result.end(),j) == result.end())
			{
				jmin = j;
				break;
			}

		tminj = T[result.back()][jmin];

		for (int j=jmin; j<N; j++)
			if(j != result.back() && find(result.begin(),result.end(),j) == result.end() && T[result.back()][j] < tminj)
			{
				tminj = T[result.front()][j];
				jmin = j;
			}

		if(tmini < tminj)
			result.insert(result.begin(), imin);
		else
			result.push_back(jmin);
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

