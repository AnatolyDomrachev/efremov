//    5. Блок решений включает следующие точные или приближенные способы решения предложенных оптимизационных задач (задач выбора наилучших решений из множества допустимых решений):
//        5.1. Эвристическое решение;
//        5.2. Полный перебор множества допустимый решений.

#include <iostream> 
#include <vector> //чтобы использовать vector
#include "main.h"
#include <algorithm> //чтобы использовать алгоритмы vector

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

	//поиск минимального времени перехода
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

	// добавляем остальные детали
	while( result.size() != N )
	{
		//проверяем что детали номер i ещё нет в результате
		for (int i=0; i<N; i++)
			if(find(result.begin(),result.end(),i) == result.end()) //поиск значения i в векторе result
			//если не найдено
			{
				imin = i;
				break;
			}

		// Ищем от какой детали быстрее всего перейти к первой детали результата
		// Какую из оставшихся поставить перед первой в результате
		tmini = T[imin][result.front()]; //Считаем, что минимальное время это переход от imin к первому элементу result

		for (int i=imin; i<N; i++)
			if(i != result.front() && find(result.begin(),result.end(),i) == result.end() && T[i][result.front()] < tmini)
			//if(i != result.front() - i не первый элемент результата
			 //find(result.begin(),result.end(),i) == result.end() - i нет в результате
			 //T[i][result.front()] < tmini) - переход от i к первому элементу результата меньше tmini
			{
				tmini = T[i][result.front()];
				imin = i;
			}

		// Ищем к какой детали быстрее всего перейти от последней детали результата
		// Какую из оставшихся поставить после последней в результате
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

		//Проверяем где выгоднее поставить детель - вначале или вконце результата
		if(tmini < tminj)
			result.insert(result.begin(), imin); //Добавление детали в начало результата
		else
			result.push_back(jmin); //Добавление детали в конец результата
	
		//вывод результата
		for(auto x: result )
			cout << x+1 << " ";
		cout << endl;
	
	}
}

void reshenie_2()
{}

