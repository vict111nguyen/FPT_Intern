#include <iostream>
using namespace std;

#define max 50

void NhapMaTran(int A[max][max], int n)

{
    int i,j;
    for(i = 0; i<n ; i++)
        for(j = 0; j<n ; j++)
        {
            cout<<"["<<i<<"]"<<"["<<j<<"] = ";
            cin >>A[i][j];
        }
}
void XuatMaTran(int A[max][max], int n)
{
    int i,j;
    for(i = 0; i<n ; i++)
    {
        cout<<("\n");
        for(j = 0; j<n ; j++)
            cout<<A[i][j]<<" ";
    }
}

void Tong(int A[max][max], int B[max][max], int C[max][max], int n){
    int i,j;
    for(i = 0; i<n ; i++)
        for(j = 0; j<n ; j++){
        C[i][j] = A[i][j]+B[i][j];
        }
}

void Hieu(int A[max][max], int B[max][max], int C[max][max], int n){
    int i,j;
    for(i = 0; i<n ; i++)
        for(j = 0; j<n ; j++){
        C[i][j] = A[i][j] - B[i][j];
        }
}

void Seletion(){
    int A[max][max],B[max][max], C[max][max], n;
    char selection;                   //Lựa chon chế độ: 1, 2, 3 hoặc 4                        
    char sl;                          //Ký tự nhập vào từ ban phím để thoát (chọn y -> thoát)                    
    cout<<"Nhap cap cua ma tran n = ";
    cin>>n;
    while(sl!='y'){
        system("cls");
        cout <<"Nhap  lua chon: \nChon 1 de nhap ma tran A va ma tran B \nChon 2 de cong ma tran C = A + B \nChon 3 de tru ma tran C = A - B \nChon 4 de thoat chuong trinh \n(Hay chon 1 de nhap mang neu ban chua nhap cac ma tran)"<<endl;
        cin>>selection;
        switch (selection){
        case '1':
            cout<<"Nhap vao ma tran A\n";
            NhapMaTran(A,n);
            cout<<"Nhap vao ma tran B\n";
            NhapMaTran(B,n);
            system("pause");
            continue;
        case '2':
            Tong(A,B,C,n);
            cout<<"\nMa tran C=A+B la:\n ";
            XuatMaTran(C,n);
            cout<<"\n";
            system("pause");
            break;
        case '3': 
            Hieu(A,B,C,n);
            cout<<"\nMa tran C=A-B\n"; 
            XuatMaTran(C,n);
            cout<<"\n";
            system("pause");
            break;
        case '4':
            cout<<"Do you want to exit this program ? (y/n)"<< endl;
            cin >> sl;
            if (sl=='y') break;
            else continue;
            system("pause");
        default: 
            cout<<"Moi nhap 1,2,3 hoac 4"<<endl;
        }
    }    
}

int main()
{
    Seletion();   
    return 0;
}