#ifndef _HUMAN_H_
#define _HUMAN_H_

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//Do rong cua cac cot trong bang
#define W_NO 5
#define W_NAME 30
#define W_Age 10
#define W_ID 15
#define W_year 15
#define W_Job 15

class Human{
private: 
    string m_HoTen, m_So_CMND;
    int m_tuoi, m_namsinh;
    string m_nghe_nghiep;
public:
    //Ham nhap vao thong tin
    void inputname();
    //Ham gan tat ca thong tin cua nhan vien
    void setData(string So_CMND, string HoTen, int tuoi, int namsinh, string nghe_nghiep);
    //Hien thi thong tin nhan vien
    void DisplayData(int no){
    cout << setprecision(5);
    cout << setw(W_NO) << left << no\
         << setw(W_NAME) << this->m_HoTen\
         << setw(W_Age) << this->m_tuoi\
         << setw(W_ID) << this->m_So_CMND\
         << setw(W_year) << this->m_namsinh\
         << setw(W_Job) << this->m_nghe_nghiep<< endl;
}

    void setName(string Hoten){this->m_HoTen = Hoten;}
    string getName(){return this->m_HoTen;}

};

#endif //_HUMAN_H_
