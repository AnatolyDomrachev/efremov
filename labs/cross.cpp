#include <iostream>
#include <cmath>
using namespace std;
 
int main() 
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    double Ua, Ub, numerator_a, numerator_b, denominator;
    
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    denominator=(y4-y3)*(x1-x2)-(x4-x3)*(y1-y2);
    if (denominator == 0){
        if ( (x1*y2-x2*y1)*(x4-x3) - (x3*y4-x4*y3)*(x2-x1) == 0 && (x1*y2-x2*y1)*(y4-y3) - (x3*y4-x4*y3)*(y2-y1) == 0)
            cout << "Отрезки пересекаются";
        else cout << "Отрезки не пересекаются";
    }
    else{
        numerator_a=(x4-x2)*(y4-y3)-(x4-x3)*(y4-y2);
        numerator_b=(x1-x2)*(y4-y2)-(x4-x2)*(y1-y2);
        Ua=numerator_a/denominator;
        Ub=numerator_b/denominator;
        cout << (Ua >=0 && Ua <=1 && Ub >=0 && Ub <=1 ? "Отрезки пересекаются" : "Отрезки не пересекаются");
    }
    return 0;
}
