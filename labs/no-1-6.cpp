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
vector<struct xy> max_result;	
int max_num = 0;
struct xy coord, c1, c2;

bool in_result()
{
	for(auto c: result )
		if( c.x == c2.x && c.y == c2.y)
			return true;

	return false;
}

bool cross2(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) 
{
    
    double Ua, Ub, numerator_a, numerator_b, denominator;
    
    denominator=(y4-y3)*(x1-x2)-(x4-x3)*(y1-y2);
    if (denominator == 0){
        if ( (x1*y2-x2*y1)*(x4-x3) - (x3*y4-x4*y3)*(x2-x1) == 0 && (x1*y2-x2*y1)*(y4-y3) - (x3*y4-x4*y3)*(y2-y1) == 0)
		return true;
            //cout << "Отрезки пересекаются";
        //else cout << "Отрезки не пересекаются";
    }
    else{
        numerator_a=(x4-x2)*(y4-y3)-(x4-x3)*(y4-y2);
        numerator_b=(x1-x2)*(y4-y2)-(x4-x2)*(y1-y2);
        Ua=numerator_a/denominator;
        Ub=numerator_b/denominator;
        //cout << (Ua >=0 && Ua <=1 && Ub >=0 && Ub <=1 ? "Отрезки пересекаются" : "Отрезки не пересекаются");
	if(Ua >=0 && Ua <=1 && Ub >=0 && Ub <=1)
		return true;
    }
    return false;
}

bool cross()
{
	c1 = result.back();
	int maxi = result.size()-2;

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

	bool new_hod = false;
	c1 = result.back();

	for(int i =0; i<8 ; i++)
	{
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
				//&&
				//!in_result(c2)
				&&
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
			result.pop_back();
		}
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

	for(auto c: max_result )
		cout << c.x << " " << c.y << endl;
	return 0;
}
