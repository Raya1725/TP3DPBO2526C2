#include <iostream>
#include <string>
#include <vector>
#include "PaymentMethod.cpp"
#include "CreditCard.cpp"
#include "EWallet.cpp"
#include "BankTransfer.cpp"

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    int pilihan;
    cin >> pilihan;
    cout << "Select the data you want to change." << endl;
    cout << "1. CreditCard" << endl;
    cout << "2. EWallet" << endl;
    cout << "3. BankTransfer" << endl;

    return 0;
}
