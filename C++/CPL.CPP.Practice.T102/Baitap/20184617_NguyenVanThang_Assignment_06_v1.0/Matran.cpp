#include "Matran.h"
#include <assert.h>


Matran::~Matran()
{
    delete[] m_mtr;
}
Matran::Matran(int row, int col){
    m_row = row;
    m_col = col;
    m_mtr = new double[row * col];
    for (int i = 0; i < m_row; i++)
    {
        for (int j = 0; j < m_col; j++)
        {
            m_mtr[i * m_col + j] = 0;
        }
    }   
}
double *Matran::maTran(int row, int col)
{
    double *temp = new double[row * col];

    for (int i = 0; i < row * col; i++)
    {
        temp[i] = m_mtr[i];
    }
    return temp;
}
Matran::Matran (const Matran &m){
    m_col = m.m_col;
    m_row = m.m_row;
    m_mtr = new double[m.m_col * m.m_row];
    for (int i = 0; i < m_row; i++)
    {
        for (int j = 0; j < m_col; j++)
        {
            m_mtr[i * m_col + j] = m.m_mtr[i * m.m_col + j];
        }
    } 
}

istream &operator>>(istream &in, Matran &matrix)
{
    cout << "Nhap vao so hang cua ma tran: ", in >> matrix.m_row;
    cout << "Nhap vao so cot cua ma tran:  ", in >> matrix.m_col;
    matrix.m_mtr = new double[matrix.m_row * matrix.m_col];

    for (int i = 0; i < matrix.m_row; i++)
    {
        for (int j = 0; j < matrix.m_col; j++)
        {
            cout << "[ " << i + 1 << ", " << j + 1 << "]: ";
            in >> matrix.m_mtr[i * matrix.m_col + j];
        }
    }
    return in;
}
ostream &operator<<(ostream &out, const Matran &matrix)
{

    for (int i = 0; i < matrix.m_row; i++)
    {
        if (i == 0)
        {
            cout << "[";
        }
        else
        {
            cout << "]\n[";
        }

        for (int j = 0; j < matrix.m_col; j++)
        {
            if (j == matrix.m_col - 1)
            {
                if (i == matrix.m_row - 1)
                {
                    cout << matrix.m_mtr[i * matrix.m_col + j] << "]\n";
                }
                else
                {

                    cout << matrix.m_mtr[i * matrix.m_col + j];
                }
            }
            else
                cout << matrix.m_mtr[i * matrix.m_col + j] << ", ";
        }
    }
    return out;
}

Matran &Matran::operator+=(const Matran &mt)
{
    assert(m_col == mt.m_col && m_row == mt.m_row);
    for (unsigned int i = 0; i < m_row; i++)
    {
        for (unsigned int j = 0; j < m_col; j++)
        {
            m_mtr[i * mt.m_col + j] += mt.m_mtr[i * mt.m_col + j];
        }
    }
    return *this;
}

Matran Matran::operator+(const Matran &mt)
{
    Matran temp = *this;
    assert(m_col == mt.m_col && m_row == mt.m_row);
    temp += mt;
    return temp;
}
Matran &Matran::operator-=(const Matran &mt)
{
    assert(m_col == mt.m_col && m_row == mt.m_row);
    for (unsigned int i = 0; i < m_row; i++)
    {
        for (unsigned int j = 0; j < m_col; j++)
        {
            m_mtr[i * mt.m_col + j] -= mt.m_mtr[i * mt.m_col + j];
        }
    }
    return *this;
}
Matran Matran::operator-(const Matran &mt)
{
    Matran temp = *this;
    assert(m_col == mt.m_col && m_row == mt.m_row);
    temp -= mt;
    return temp;
}
Matran Matran::operator*(const Matran &b)
{
    Matran a = *this;
    assert(a.m_col == b.m_row);
    Matran c(a.m_row, b.m_col);
    for (int i = 0; i < a.m_row; i++)
    {
        for (int j = 0; j < b.m_col; j++)
        {
            for (int k = 0; k < a.m_col; k++)
            {
                c.m_mtr[i * c.m_col + j] += a.m_mtr[i * a.m_col + k] * b.m_mtr[k * b.m_col + j];
            }
        }
    }
    return c;
}

Matran Matran::getCofactor(int r, int c)
{
    assert(m_col == m_row);
    Matran temp(m_row - 1, m_col - 1);
    int i = 0, j = 0;
    for (int row = 0; row < m_col; row++)
    {
        for (int col = 0; col < m_col; col++)
        {
            if (row != r && col != c)
            {
                temp(i, j++) = m_mtr[row * m_col + col];
                if (j == m_col - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return temp;
}

double Matran::determinant()
{
    assert(m_col == m_row);
    double D = 0;
    if (m_col == 1)
    {
        return m_mtr[0];
    }
    Matran temp = *this;
    int sign = 1;

    for (int f = 0; f < m_col; f++)
    {
        Matran a = this->getCofactor(0, f);
        D += sign * m_mtr[f] * a.determinant();
        sign = -sign;
    }
    return D;
}
Matran Matran::adjoint()
{
    assert(m_col == m_row);
    if (m_col == 1)
    {
        m_mtr[0] = 1;
        return *this;
    }
    Matran adj = *this;
    int sign = 1;
    for (int i = 0; i < m_row; i++)
    {
        for (int j = 0; j < m_col; j++)
        {
            Matran temp = this->getCofactor(i, j);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj.m_mtr[j * m_col + i] = (sign)*temp.determinant();
        }
    }
    return adj;
}
Matran Matran::inverse()
{
    double Det = this->determinant();
    if (Det == 0)
    {
        cout << "Can't find Inverse Matran" << endl;
    }
    Matran adj = this->adjoint();
    
    Matran inv(m_col, m_col);
    for (int i = 0; i < m_col; i++)
    {
        for (int j = 0; j < m_col; j++)
        {
            inv.m_mtr[i * m_col + j] = adj.m_mtr[i * m_col + j] / Det;
        }
    }

    return inv;
}
Matran Matran::operator/(Matran &mt)
{
    return (*this) * (mt.inverse());
}
double &Matran::operator()(int row, int col)
{
    return m_mtr[row * m_col + col];
}

