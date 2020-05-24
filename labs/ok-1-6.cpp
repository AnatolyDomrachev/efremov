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
	for(auto c: result )
		if( c.x == c2.x && c.y == c2.y)
			return true;

	return false;
}

// расстояние между средними точками отрезков ходов должно быть меньше одного. тогда пересекаются
bool litle_rast_sred(struct xy c2)
{
	struct xy c1 = result.back();
	double sc1x;
	double sc1y;
	double rast;
	double sc2x = (c2.x + c1.x)/2;
	double sc2y = (c2.y + c1.y)/2;

	for(int i=0; i<result.size()-1; i++)
	{
		sc1x = (result[i].x + result[i+1].x ) / 2;
		sc1y = (result[i].y + result[i+1].y ) / 2;
		rast = sqrt(pow(sc2x-sc1x,2) + pow(sc2y-sc1y,2));
		if(rast < 1)
			return true;
	}

	return false;
}

bool cross(struct xy c2)
{
	if(obsh_tochka(c2) || litle_rast_sred(c2))
		return true;
	else
		return false;
}

void next()
{
	struct xy c1;
	struct xy c2;
	bool new_hod = false;

	c1 = result.back();

	for(int i =0; i<8 ; i++)
	{
		c2.x = c1.x + vars[i][0];
		c2.y = c1.y + vars[i][1];
		if(
				c2.x < N 
				&&
				c2.y < N 
				&&
				!cross(c2)
				)
		{
			new_hod = true;
			break;
		}
	}

	if(new_hod)
	{
		result.push_back(c2);
		next();
	}
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
		cout << c.x << " " << c.y << endl;
	return 0;
}
