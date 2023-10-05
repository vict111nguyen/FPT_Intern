#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<string>
using namespace std;


class Can_bo{
public:
    string ten, vitri, que_quan;
    int tuoi;
    
    float luong;

	//Hàm nhập các dữ liệu vào
	void Input()
	{
		cin.ignore(); 
		cout<<"Nhap ho ten: ";
		getline(cin,ten); 
		cout<<"Tuoi: ";
		cin>>tuoi;
        cin.ignore(); 
        cout<<"Vi tri: ";
        getline(cin,vitri);
		cout<<"Que quan: ";
		getline(cin,que_quan); 
        cout<<"Luong: ";
        cin>>luong; 
	}
	
	//Hàm hiển thị các dữ liệu trên cùng một dòng
	void Output()
	{
		cout<<"Ho ten: " << ten ; 
		cout<<" - Tuoi: "<< tuoi ; 
        cout<<" - Vi tri "<< vitri; 
		cout<<" - Que quan: "<< que_quan;	
        cout<<" - Luong: "<< luong <<endl; 	
	}
    
	//Hàm getter lấy giá trị lương để sắp xếp
    float get_luong(){
        return luong;
    }

};

int main(){
	int i,j,n;
	Can_bo a[20];
	//Nhập số lượng cán bộ và dữ liệu về từng cán bộ nhân viên
	cout<<"So luong can bo la: n= ";
	cin >> n; 
	for(i=0;i<n;i++)	
	{
		cout<<"Can bo thu "<<(i+1)<<": \n"; 
		a[i].Input();	
	}

	//Hàm sắp xếp và đổi vị trí các nhân viên (đổi từng dữ liệu)
	for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
	        if(a[i].get_luong()>a[j].get_luong()){
                swap (a[i].ten, a[j].ten);
                swap (a[i].tuoi, a[j].tuoi);
                swap (a[i].vitri, a[j].vitri);
                swap (a[i].que_quan, a[j].que_quan);
                swap (a[i].luong, a[j].luong);
            }
        }
    }

	//Hiển thị danh sách cán bộ theo mức lương từ thấp đến cao theo yêu cầu đề bài	
	cout<<"Danh sach can bo theo muc luong tu thap den cao la: \n"; 
	for(i=0;i<n;i++)
	{
		cout<<"Can bo thu "<<(i+1)<<": "; 
        a[i].Output();	
	}
    getch();
	return 0;
}

