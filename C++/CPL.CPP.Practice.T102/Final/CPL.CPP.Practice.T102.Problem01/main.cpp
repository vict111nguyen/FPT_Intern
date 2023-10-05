#include <iostream>
#include <cmath>

using namespace std;
//Check is Triangle 
bool isTriangle(float a, float b, float c)
{
	//Sum of 2 edge > orther edge
    return (sqrt(a) + sqrt(b) > sqrt(c)) && (sqrt(b) + sqrt(c) > sqrt(a)) && (sqrt(c) + sqrt(a) > sqrt(b));
}
//Check is Right Triangle
bool isRightTriangle(float a, float b, float c)
{
	//Using Pytagoras Theorem
    return (a==b+c) || (b==a+c) || (c==a+b);
}
//Check is Isosceles Triangle
bool isIsoscelesTriangle(float a, float b, float c)
{
	//Isosceles Triangle have 2 edge equal
    return (a == b) || (b == c) || (c == a);
}
//Check is Equilateral Triangle
bool isEquilateralTriangle(float a, float b, float c)
{
	//Equilateral Triangle have 3 edge equal
    return (a == b) && (b == c) && (c == a);
}
//Check type of Triangle
void typeOfTriangle(float threePointsCoordinates[])
{
    // A(x1,y1), B(x2,y2), C(x3,y3)
    float x1(threePointsCoordinates[0]),
        y1(threePointsCoordinates[1]),
        x2(threePointsCoordinates[2]),
        y2(threePointsCoordinates[3]),
        x3(threePointsCoordinates[4]),
        y3(threePointsCoordinates[5]);
    // Cacl square edge AB, AC, BC
	// c = AB^2
    float c = pow(x2 - x1, 2) + pow(y2 - y1, 2);
	//b = AC^2
    float b = pow(x3 - x1, 2) + pow(y3 - y1, 2);
	//a = BC^2
    float a = pow(x3 - x2, 2) + pow(y3 - y2, 2);
    //Check is Triangle
    if (isTriangle(a, b, c))
    {
		//Check is Right Triangle
        if (isRightTriangle(a, b, c))
        {
			//Check is Right-Isosceles Triangle
            if(isIsoscelesTriangle(a, b, c)){
                cout << "Right-Isosceles Triangle" << endl;
            }
			//if not a Right-Isosceles Triangle
            else cout << "Right Triangle" << endl;
        }
		//Check Isosceles Triangle
        else if(isIsoscelesTriangle(a, b, c)){
			//Check Equilateral Triangle
            if(isEquilateralTriangle(a, b, c)){
                cout << "Equilateral Triangle" << endl;
            }
			//If not a Equilateral Triangle
            else cout << "Isosceles Triangle" << endl;
        }
		//If not special Triangle
        else cout << "Normal Triangle" << endl;
    }
	//If not a Triangle
    else cout << "Not a Triangle" << endl;
}

int main()
{
	//Input
    float t[] = {0, 0, 0, 0, 0, 0};
	//Output
    typeOfTriangle(t);
	
    return 0;
}