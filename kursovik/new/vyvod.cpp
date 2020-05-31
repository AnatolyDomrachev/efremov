    //4. Вывод исходных данных осуществляется в табличном виде;
#include <iostream> 
#include "main.h"

using  namespace  std;

void vyvod()
{
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if(i != j)
				cout << "t["<<i+1<<"]["<<j+1<<"]\t"<< T[i][j] << endl;
}

