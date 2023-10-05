#include "Human.cpp"


class Town{
private: 
    int m_SoNguoi;
    int m_SoNha;
    Human* m_Thongtin1nguoi;
public: 
    //Ham nhap vao thong tin cua tung nguoi trong n hộ dân
    void input(){
        cout << "Nhap so nguoi: " ; cin >> m_SoNguoi;
        cout << "Nhap so nha: " ; cin >> m_SoNha;
        m_Thongtin1nguoi = new Human[m_SoNguoi];
        for(int i=0;i<m_SoNguoi;i++){
            cout << "Thanh vien so " << i+1 << " :" << endl; 
            m_Thongtin1nguoi[i].inputname();
        }
    }
    void DisplayAll(){
        cout << "Thong tin cua ho dan so: " << m_SoNha << endl;
        cout << setw(W_NO) << left << "No."
        << setw(W_NAME) << "HoTen:"
        << setw(W_Age) << "Tuoi:"
        << setw(W_ID) << "So CMND:"
        << setw(W_year) << "Nam sinh:"
        << setw(W_Job) << "Nghe nghiep:" << endl;
        cout << setfill('-') << setw(W_NO + W_NAME + W_Age + W_year + W_ID + W_Job - 1) << "-" << endl;
        cout << setfill(' ');
        for(int i = 0 ; i< m_SoNguoi ; i++){
            m_Thongtin1nguoi[i].DisplayData(i+1);
        }
    }
    void Timkiem_HoTen(string name);
    void Timkiem_Sonha(int sonha );
};
//Ham in ra title cua bang
void printTitle()
{
    cout << setw(W_NO) << left << "No."
         << setw(W_NAME) << "HoTen:"
         << setw(W_Age) << "Tuoi:"
         << setw(W_ID) << "So CMND:"
         << setw(W_year)<< "Nam sinh:"
         << setw(W_Job) << "Nghe nghiep:" << endl;
    cout << setfill('-') << setw(W_NO + W_NAME + W_Age + W_year + W_ID + W_Job - 1) << "-" << endl;
    cout << setfill(' ');
}

int N = 0;
//Hàm tìm kiếm hộ dân theo tên
void Town :: Timkiem_HoTen(string name)
{
    for (int i = 0; i < N; i++)
    {
        if (m_Thongtin1nguoi[i].getName().compare(name) == 0)
        {
            cout<< "Da tim thay " << name <<" Ho dan thu " << i + 1 << endl;
            DisplayAll();
        }
    } 
}
void Town::Timkiem_Sonha(int sonha ){
    if(m_SoNha == sonha) {
        cout<< "Da tim thay Ho dan co so nha " << sonha << endl;
        DisplayAll();
    }
}
Town* T;

void menu(){
    cout << "==================MENU====================" << endl;
    cout << "1. Nhap thong tin cho thi tran" << endl;
    cout << "2. Tim thong tin cua ho dan" << endl;
    cout << "3. Hien thi thong tin cua thi tran" << endl;
    cout << "4. Thoat" << endl;
    cout << "===================END====================" << endl;
}

void handleMenuFind(){
    bool isBack = false;
    while(!isBack){
        system("cls");
        cout << "===========MENU-tim nha============" << endl;
        cout << "1. Tim thong tin ho dan theo ten " << endl;
        cout << "2. Tim thong tin ho dan theo so nha" << endl;
        cout << "3. Tro lai menu chinh" << endl;
        cout << "===================END====================" << endl;

        int input = 0;
        do{
            cout << "\nLua chon cua ban la: " ;
            cin >> input ;
        }
        while(input < 0 || input > 3);

        switch(input){
            case 1:
                {
                    string Hoten = "";
                    cout << "Ten cua nguoi ban muon tim: ";
                    fflush(stdin);
                    getline(cin, Hoten);
                    for(int i = 0 ;i < N ;i++){
                        T[i].Timkiem_HoTen(Hoten);
                    }
                system("pause");
                break;
                }   
            case 2:
                {
                    int num;
                    cout << "So nha la: ";
                    cin >> num;
                    for(int i =0 ;i < N ;i++){
                        T[i].Timkiem_Sonha(num);
                    }
                system("pause");
                break;
                } 
            case 3:
                isBack = true;
                break;
            default:
                break;
        }
    }
    
}

int chooseMenu(){
    int input = 0;
    do{
        cout << "\nLua chon cua ban la: " ;
        cin >> input ;
    }
    while(input < 0 || input > 4);
    return input;
}
void handleMenu(){
    int choose = chooseMenu();
    switch(choose)
    {
    case 1:{
        cout << "Nhap so ho dan trong thi tran: " ; cin >> N;
        T = new Town[N];
        for(int i=0;i<N;i++){
            cout << "\n============Nhap thong tin ho dan " << i+1  << "============" << endl;
            T[i].input();
        }
        system("pause");
        break;
    }
    case 2:{
        handleMenuFind();
        break;
    }
    case 3:{
        cout << "Thong tin ve thi tran :" << endl;
        for(int i=0;i<N;i++){
            T[i].DisplayAll();
        }
        system("pause");
        break;
    }
    case 4:
        cout << "Do you want to exit this program ? (y/n)\
                \n\b- Y/y -> Quit\
                \n\b- Other -> do nothing" << endl;
        char c;
        cin >> c;
        if(c == 'Y' || c == 'y'){
            cout << "GOOGBYE!!" << endl;  
            exit(-1);
        }
        else system("pause");
        break;
    default:
        system("pause");
        break;
    }
}
int main(){
    while(true){
        system("cls");
        menu();
        handleMenu();
    }
    return 0;
}