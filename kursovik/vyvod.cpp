    //4. Вывод исходных данных осуществляется в табличном виде;
#include <iostream> 
#include "main.h"

using  namespace  std;

void vyvod()
{
	void (*operations[])() = {vyvod_1, nothing};

	cout << "1. Вывод исходных данных осуществляется в табличном виде;" << endl;
	cout << "2. Возврат в главное меню"<< endl;

	int var;
	var = vybor(2);
	operations[var-1]();
}

void vyvod_1()
{}

