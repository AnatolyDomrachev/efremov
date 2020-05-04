//    6. Сохранение и восстановление исходных данных осуществляется по выбору студента тремя способами:
//        6.1. В текстовых файлах;
//        6.2. В типизированных двоичных файлах;

#include <iostream> 
#include "main.h"

using  namespace  std;

void sohr()
{
	void (*operations[])() = {sohr_1, sohr_2, nothing};

	cout << "1. В текстовых файлах;" << endl;
	cout << "2. В типизированных двоичных файлах;" << endl;
	cout << "3. Возврат в главное меню"<< endl;

	int var;
	var = vybor(3);
	operations[var-1]();
}

void sohr_1()
{}

void sohr_2()
{}
