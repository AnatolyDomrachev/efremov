//    6. ���࠭���� � ����⠭������� ��室��� ������ �����⢫���� �� �롮�� ��㤥�� �६� ᯮᮡ���:
//        6.1. � ⥪�⮢�� 䠩���;
//        6.2. � ⨯���஢����� ������� 䠩���;

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
