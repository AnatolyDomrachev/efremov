//    6. Сохранение и восстановление исходных данных осуществляется по выбору студента тремя способами:
//        6.1. В текстовых файлах;
//        6.2. В типизированных двоичных файлах;

#include <iostream> 
#include "main.h"
#include <fstream>

using  namespace  std;

void vost()
{
	char fname[50];
	cout << "enfer fmane: ";
	cin >> fname;       
	ifstream file;
	file.open (fname);
	file >> N ;
	cout << N << endl;
	T = new double*[N];
	for (int i=0; i<N; i++)
		T[i] = new double[N];

	char buf[20];
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if(i != j)
			{
				file >> buf;
				file >> T[i][j];
			}

	/*
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if(i != j)
				file << "t["<<i+1<<"]["<<j+1<<"]\t"<< T[i][j] << endl;
	*/
	file.close();


}


