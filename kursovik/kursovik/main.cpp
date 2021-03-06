/*
 * В течение смены гибкое автоматизированное производство (ГАП) обрабатывает n типов деталей.
 * Известно время переналадки ГАП с одного типа деталей на другой tij, i=1..n, j=1..n.
 * Определить такой порядок переналадки, при котором время простоя оборудования минимально.
 * После завершения обработки всех деталей производство следует настроить на детали исходного типа для подготовки следующего цикла производства
 */

#include <iostream>
#include "main.h"
#include <stdlib.h>

using  namespace  std;

int N;
double ** T;

int main()
{
	void (*operations[])() = {vvod, vyvod, reshenie, sohr, vost, end}; //Массив указателе

	while(true)
	{
		cout << "ГЛАВНОЕ МЕНЮ" << endl;
		cout << "1. Формирования исходных данных" << endl;
		cout << "2. Вывода исходных данных на экран пользователя" << endl;
		cout << "3. Решения задачи различными способами" << endl;
		cout << "4. Сохранения исходных данных в файлах на магнитных дисках" << endl;
		cout << "5. Восстановления исходных данных с файлов на магнитных дисках" << endl;
		cout << "6. Завeршение работы" << endl;

		int var;
		var = vybor(6);
		operations[var-1]();
	}

	return 0;
}

void end() {exit(0);}
void nothing() {}
