#include <iostream>

using namespace std;
/*
    + Ban dau neu khong cat thi banh se co 1 phan duy nhat: f(0) = 1
        - Nhat cat 1 chia banh thanh 2: f(1) = 2 = 1 + 1 = f(0) + 1
        - Nhat cat 2 chia banh thanh 4: f(2) = 4 = 2 + 2 = f(1) + 2
        - Nhat cat 3 chia banh thanh 7: f(3) = 7 = 4 + 3 = f(2) + 3
    + Nhu vay co the thay sau nhat cat n thi so phan banh se tang them n
        => Nhat cat n chia banh thanh: f(n) = f(n-1) + n
    + Den day ta co the viet ham de quy nhu sau:
=============================================================================
int cakeCutting(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 2;
    return cakeCutting(n - 1) + n;
}
=============================================================================
    + Tuy nhien do phuc tap cua thuat toan se la O(n).
    + De toi uu, ta co the khai trien cong thuc de quy nhu sau:
        f(n) = n + f(n-1)
             = n + n-1 + n-2 +...+ 1 + f(0)
             = n(n+1)/2 + f(0)
             = n(n+1)/2 + 1
    + Khi nay ta khong can thuc hien de quy ma chi can 1 cong thuc 
        f(n) = n(n+1)/2 + 1 la co the giai quyet duoc bai toan 
    =>  Do phuc tap thuat toan chi con la O(1).
*/

int cakeCutting(int n)
{
    return (n*(n+1))/2 + 1;
}
int main()
{
    cout << "n = 0 => cakeCutting(n): " << cakeCutting(0) << endl;
    cout << "n = 1 => cakeCutting(n): " << cakeCutting(1) << endl;
    cout << "n = 20 => cakeCutting(n): " << cakeCutting(20) << endl;

    return 0;
}