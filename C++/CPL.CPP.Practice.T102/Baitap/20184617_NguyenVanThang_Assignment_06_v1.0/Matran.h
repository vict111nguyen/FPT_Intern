#ifndef _MATRAN_H_
#define _MATRAN_H_
#include<iostream>
using namespace std;

class Matran{
    int m_row = 0;
    int m_col = 0;
    int m_size = 0;
    double *m_mtr;

public:
    Matran(){}
    ~Matran();
    Matran(int row, int col);
    Matran (const Matran &m);

    double &operator()(int row, int col);
    friend ostream &operator<<(ostream &out, const Matran &Matran);
    friend istream &operator>>(istream &in, Matran &Matran);
    // Overloading operator +, -, *, /
    Matran operator+(const Matran &Mtr);
    Matran &operator+=(const Matran &Mtr);
    Matran operator-(const Matran &Matran);
    Matran &operator-=(const Matran &Matran);
    Matran operator*(const Matran &Matran);
    Matran &operator*=(const Matran &Matran);
    Matran &operator=(const Matran &Matran);
    Matran operator/(Matran &mt);

    int Det();
    double *maTran(int n, int m);
    // Hàm nghịch đảo ma trân
    void trap();
    // Ma tran con bo di hang row+1 va cot col+1
    Matran getCofactor(int row, int col);
    // Det cua ma tran vuong
    double determinant();
    // Ma tran don vi cap n
    static Matran identity(int n)
    {
        Matran a(n, n);
        while (n--)
            a(n, n) = 1;
        return a;
    }
    // Ma tran bu
    Matran adjoint();
    // Ma tran nghich dao
    Matran inverse();

};

#endif //_MATRAN_H
