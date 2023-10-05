#include <iostream>
#include <iomanip>
using namespace std;

class CGoods {
private:
    char code[4];
    char name[20];
    char unit[10];
    int unitPrice, value;
    int numberOfGoods;

public:
    void input();
    int calculateValue() {
        return value = unitPrice * numberOfGoods;
    }

    const char* getCode() const {
        return code;
    }

    const char* getName() const {
        return name;
    }

    const char* getUnit() const {
        return unit;
    }

    int getUnitPrice() const {
        return unitPrice;
    }

    int getNumberOfGoods() const {
        return numberOfGoods;
    }
};

class ShippingPrice : public CGoods {
    int shippingUnitPrice;

public:
    void inputShippingUnitPrice() {
        cout << "Input shipping unit price (dong): ";
        cin >> shippingUnitPrice;
    }

    int calculateTransportationCosts() {
        return shippingUnitPrice * getNumberOfGoods();
    }

    int calculatePayment() {
        return calculateValue() + calculateTransportationCosts();
    }
};

void CGoods::input() {
    cout << "Input code: ";
    cin >> code;
    cout << "Input name: ";
    cin.ignore(); // Clear the newline character from the buffer
    cin.getline(name, sizeof(name));
    cout << "Input unit to calculate: ";
    cin.getline(unit, sizeof(unit));
    cout << "Input unit price (dong): ";
    cin >> unitPrice;
    cout << "Input number of goods: ";
    cin >> numberOfGoods;
}

int main() {
    ShippingPrice G1;
    G1.input();
    G1.inputShippingUnitPrice();
    cout << "-----------------------------------" << endl;
    cout << "Price of goods: " << G1.calculateValue() << endl;
    cout << "Transportation Costs is: " << G1.calculateTransportationCosts() << endl;
    cout << "Payment is: " << G1.calculatePayment() << endl;
}
