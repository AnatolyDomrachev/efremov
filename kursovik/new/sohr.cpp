//    6. Сохранение и восстановление исходных данных осуществляется по выбору студента тремя способами:
//        6.1. В текстовых файлах;
//        6.2. В типизированных двоичных файлах;

#include <iostream> 
#include "main.h"
#include <fstream>

using  namespace  std;

void sohr()
{
	char fname[50];
	cout << "enfer fmane: ";
	cin >> fname;       
	ofstream file;
	file.open (fname);
	file << N << endl ;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if(i != j)
				file << "t["<<i+1<<"]["<<j+1<<"]\t"<< T[i][j] << endl;
	file.close();


}
