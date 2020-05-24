//Найти самый длинный несамопересекающийся путь коня на доске 6*6
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
int vars[][2] = {{1,2},{1,-2},{2,1},{2,-1},{-1,-2},{-1,2},{-2,-1},{-2,1}};
vector<struct xy> result;	
struct xy coord;

bool obsh_tochka(struct xy c2)
{
	return true;
}

bool litle_rast_sred(struct xy c2)
{
	return true;
}

bool cross(struct xy c2)
{
	if(obsh_tochka(c2) || litle_rast_sred(c2))
		return false;
	else
		return true;
}

void next()
{
	struct xy c1;
	struct xy c2;
	c1 = result.back();

	for(int i =0; i<8 ; i++)
	{
		c2.x = c1.x + vars[i][0];
		c2.y = c1.y + vars[i][1];
		if(
				c2.x < N ||
				c2.y < N ||
				!cross(c2)
				)
			break;
	}

	result.push_back(c2);
	next();
}

int main()
{
	char buf[2];

	cout << "Введите начальное расположение коня на доске: ";
	cin >> buf;
	coord.x = buf[0] - 'a';
	coord.y = buf[1] - '1';
	
	//cout << x << y;
	result.push_back(coord);
	next();

	for(auto c: result )
	{
		cout << c.x;
		cout << c.y;
	}
	return 0;
}
