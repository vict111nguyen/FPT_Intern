#include "Matran.cpp"

Matran A, B;

void menu()
{
    cout << "=============Menu-Tinh-Matran=============" << endl;
    cout << "0. Nhap vao hai ma tran A, B" << endl;
    cout << "1. Tinh ma tran C = A + B" << endl;
    cout << "2. Tinh ma tran D = A - B" << endl;
    cout << "3. Tinh ma tran E = A * B" << endl;
    cout << "4. Tinh ma tran F = A / B" << endl;
    cout << "5. Exit" << endl;
    cout << "===================End====================" << endl;
}
int chooseMenu()
{
    int input = 0;
    do
    {
        cout << "\nYour choice is: " << endl;
        cin >> input;
    } while (input < -1 || input > 5);
    return input;
}
void handleMenu()
{
    int choose = chooseMenu();
    switch (choose)
    {
    case 0:
    {
        cout << "Matran A:" << endl;
        cin >> A;
        cout << "Matran B:" << endl;
        cin >> B;
        system("pause");
        break;
    }

    case 1:
    {
        cout << "Matran C = A + B:" << endl;
        Matran C = A + B;
        cout << C;
        system("pause");
        break;
    }
    case 2:
    {
        cout << "Matran D = A - B:" << endl;
        Matran D = A - B;
        cout << D;
        system("pause");
        break;
    }
    case 3:
    {
        cout << "Matran E = A * B:" << endl;
        Matran E = A * B;
        cout << E;
        system("pause");
        break;
    }
    case 4:
    {
        cout << "Matran F = A / B:" << endl;
        Matran F = A / B;
        cout << F;
        system("pause");
        break;
    }
    case 5:
        cout << "Do you want to exit this program ? (y/n)\n\b- Y/y -> Quit\n\b- Other -> do nothing" << endl;
        char c;
        cin >> c;
        if (c == 'Y' || c == 'y')
        {
            exit(-1);
        }
        else
            system("pause");
        break;
    default:
        break;
    }
}
int main()
{
    while(true){
         system("cls");
         menu();
         handleMenu();
    }
    return 0;
}