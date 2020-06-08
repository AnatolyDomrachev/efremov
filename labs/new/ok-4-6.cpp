//���� ᠬ� ������ ��ᠬ����ᥪ��騩�� ���� ���� �� ��᪥ 6*6
//
#include <iostream> 
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>

using  namespace  std;

struct xy
{
	int x;
	int y;
};

const int N = 6;
int vars[][2] = {
	{1,2},
	{2,1},
	{2,-1},
	{1,-2},
	{-1,-2},
	{-2,-1},
	{-2,1},
	{-1,2}
};
vector<struct xy> result;	
vector<struct xy> max_result;	
int max_num = 0;

bool cross2(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) 
{
    
    double Ua, Ub, numerator_a, numerator_b, denominator;
    
    denominator=(y4-y3)*(x1-x2)-(x4-x3)*(y1-y2);
    if (denominator == 0){
        if ( (x1*y2-x2*y1)*(x4-x3) - (x3*y4-x4*y3)*(x2-x1) == 0 && (x1*y2-x2*y1)*(y4-y3) - (x3*y4-x4*y3)*(y2-y1) == 0)
		return true;
    }
    else{
        numerator_a=(x4-x2)*(y4-y3)-(x4-x3)*(y4-y2);
        numerator_b=(x1-x2)*(y4-y2)-(x4-x2)*(y1-y2);
        Ua=numerator_a/denominator;
        Ub=numerator_b/denominator;
	if(Ua >=0 && Ua <=1 && Ub >=0 && Ub <=1)
		return true;
    }
    return false;
}

bool cross(struct xy c2)
{
	struct xy c1 = result.back();
	int maxi = result.size()-2; // -2 㡨ࠥ� �� ��ᬮ�७�� ᠬ ���� 室 � �� 室, ����� ��०� ���

	for(int i=0; i<maxi ; i++)
	{
		if(cross2(result[i].x , result[i].y , result[i+1].x , result[i+1].y , c1.x, c1.y, c2.x, c2.y))
			return true;
	}

	return false;
}

void next()
{

	for(auto c: result )
		cout << c.x << " " << c.y << endl;
	cout << endl;

	struct xy c1;
	struct xy c2;
	bool new_hod;

	for(int i =0; i<8 ; i++)
	{
		c1 = result.back();
		new_hod = false;
		c2.x = c1.x + vars[i][0];
		c2.y = c1.y + vars[i][1];
		if(
				c2.x < N 
				&&
				c2.x >= 0 
				&&
				c2.y < N 
				&&
				c2.y >= 0 
				&&
				!cross(c2) // �஢�ઠ �� ���� 室 �� ��ࠧ�� ����祭�� � 㦥 ����騬���
			)
		{
			result.push_back(c2);
			new_hod = true;
			next();
		}
	}

	if(!new_hod) // ���� 室 ��� ����祭�� ᤥ���� ����������
	{
		if(result.size() > max_num)
		{
			max_result = result;
			max_num = result.size();
		}

		result.pop_back();
	}
}

int main()
{
	char buf[2];
	struct xy coord;

	cout << "������ ��砫쭮� �ᯮ������� ���� �� ��᪥: ";
	cin >> buf;
	coord.x = buf[0] - 'a';
	coord.y = buf[1] - '1';
	
	//cout << x << y;
	result.push_back(coord);
	next();

	char ch;
	for(auto c: max_result )
	{
		ch = 'a' + c.x;
		cout << ch << " " << c.y+1 << endl;
	}

	return 0;
}
