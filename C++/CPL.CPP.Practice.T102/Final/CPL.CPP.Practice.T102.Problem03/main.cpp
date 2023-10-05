#include <iostream>

using namespace std;

//Ham tinh tong cac uoc cua 1 so
int getDivisorsSum(int num)
{
    int sum = 0;

    for (int i = 1; i < num; i++)
    {
        //Neu i la uoc cua num thi cong them i vao sum
        if (num % i == 0)
            sum = sum + i;
    }
    return sum;
}

bool friendNumber(int a, int b)
{
    //Tinh tong cac uoc cua a va b
    int sum_a = getDivisorsSum(a);
    int sum_b = getDivisorsSum(b);
    //Kiem tra xem a va b co la friendNumber khong
    if ((sum_a == b) && (sum_b == a))
        return true;
    else
        return false;
}

int main()
{
    cout << friendNumber(220, 284) << endl;
    return 0;
}