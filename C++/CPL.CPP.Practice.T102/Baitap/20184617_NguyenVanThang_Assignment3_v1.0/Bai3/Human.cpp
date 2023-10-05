#include "Human.h"

void Human::setData(string So_CMND, string HoTen, int tuoi, int namsinh, string nghe_nghiep){
    this->m_HoTen = HoTen;
    this->m_So_CMND = So_CMND;
    this->m_tuoi = tuoi;
    this->m_namsinh = namsinh;
    this->m_nghe_nghiep = nghe_nghiep;
}
void Human::inputname(){
    // Họ Tên
    cout << "Ho Ten: ";
    fflush(stdin);
    getline(cin, m_HoTen);
    //Số CMND
    cout<< "So chung minh nhan dan: ";
    getline(cin, m_So_CMND);
    // tuoi
    cout << "Tuoi: ";
    cin >> m_tuoi;
    // Năm sinh 
    cout << "Nam sinh: ";
    cin >> m_namsinh;
    // Nghề nghiệp
    cout << "Nghe nghiep: ";
    fflush(stdin);
    getline(cin, m_nghe_nghiep);
    // Set Data
    //this->setData(So_CMND, HoTen, tuoi, namsinh, nghe_nghiep);
}




