#include "String.cpp"

int main(){
    Mystring s1,s2;
    cout << "Nhap chuoi: \n";
    cout << "Chuoi 1: "; cin >> s1;
    cout << "Chuoi 2: "; cin >> s2;
    // Chieu dai chuoi
    cout << s1.get_length();
    char arr[80];
    //Copy string s1 from char position 0 to 3
    Mystring s_cpy;
    s_cpy.copy(arr, s_cpy.get_length(), 0);
    
    // Swap s1 and s2

    //Đảo chuỗi
    s2.swp(s1);
    cout << "Chuoi 1 va chuoi 2 sau khi dao chuoi \n";
    cout << "Chuoi 1: " << s1 << endl;
    cout << "Chuoi 2: " << s2 << endl;

    Mystring s4 = s1;
    cout << "Chuoi copy tu chuoi 1: " << s_cpy ;
}