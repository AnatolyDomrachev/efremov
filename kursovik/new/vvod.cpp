//3. Блок формирования исходных данных  должен предусматривать два режима:
//3.1. Ручной ввод исходных данных пользователем с клавиатуры;
//3.2. Генерация основных  объемов исходных данных случайным образом.

#include <iostream> 
#include "main.h"
#include <random> //нужны для рандома
#include <ctime>//нужны для рандома

using  namespace  std;

void vvod()
{
	void (*operations[])() = {vvod_1, vvod_2, nothing};

	cout << "1. Ручной ввод исходных данных пользователем с клавиатуры;" << endl;
	cout << "2. Генерация основных  объемов исходных данных случайным образом." << endl;
	cout << "3. Возврат в главное меню"<< endl;

	int var;
	var = vybor(3);
	operations[var-1]();

}

void vvod_1()
{
	cout << "Введите количество деталей"<< endl;
	N = vybor(200);

	//создаём динамический двумерный массив
	T = new double*[N];
	for (int i=0; i<N; i++)
		T[i] = new double[N];

	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if(i != j)
			{
				cout << "Введите t["<<i+1<<"]["<<j+1<<"]"<< endl;
				cin >> T[i][j];
			}
}

void vvod_2()
{
	srand(time(0));   //без этого будут одни и те же значения
	cout << "Введите количество деталей"<< endl;
	N = vybor(20);

	//создаём динамический двумерный массив
	T = new double*[N];
	for (int i=0; i<N; i++)
		T[i] = new double[N];

	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if(i != j)
			{
				T[i][j] = rand()%10+1; //рандом от 1 до 10
			}
}


