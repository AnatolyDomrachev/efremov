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
<<<<<<< HEAD
	int maxi = result.size()-2;
=======
	double sc1x;
	double sc1y;
	double rast;
	double sc2x = (c2.x + c1.x)/2;
	double sc2y = (c2.y + c1.y)/2;
>>>>>>> parent of 0c1d968... 1

	for(int i=0; i<maxi ; i++)
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
				c2.y < N 
				&&
<<<<<<< HEAD
				c2.y >= 0 
				//&&
				//!in_result(c2)
				&&
=======
>>>>>>> parent of 0c1d968... 1
				!cross(c2)
			)
		{
			result.push_back(c2);
			new_hod = true;
			next();
		}
	}

	if(!new_hod)
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

	cout << "Введите начальное расположение коня на доске: ";
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
