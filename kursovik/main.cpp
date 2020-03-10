/*
 * В течение смены гибкое автоматизированное производство (ГАП) обрабатывает n типов деталей. 
 * Известно время переналадки ГАП с одного типа деталей на другой tij, i=1..n, j=1..n.
 * Определить такой порядок переналадки, при котором время простоя оборудования минимально. 
 * После завершения обработки всех деталей производство следует настроить на детали исходного типа для подготовки следующего цикла производства
 */

#include <iostream> 
#include <fstream> 

using  namespace  std;

int vybor(int max_num)
{
	string buf = "no number";

	while( !( isdigit(buf[0]) && buf.at(0) - 48 <= max_num ))
	{
		cout << "Ваш выбор: " << endl;
		fflush(stdin);
		cin >> buf;
		fflush(stdin);
	}

	return buf.at(0) - 48;
}

int main()
{
        cout << "ГЛАВНОЕ МЕНЮ" << endl;

        cout << "1. Формирования исходных данных" << endl;
        cout << "2. Вывода исходных данных на экран пользователя" << endl;
        cout << "3. Решения задачи различными способами" << endl;
        cout << "4. Вывода результатов решения задачи" << endl;
        cout << "5. Сохранения исходных данных в файлах на магнитных дисках" << endl;
        cout << "6. Восстановления исходных данных с файлов на магнитных дисках" << endl;

	int var = 0;
	var = vybor(6);

	return 0;
}
