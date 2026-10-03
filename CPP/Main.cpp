#include <iostream>
#include <string>
#include <vector>
#include "PaymentMethod.cpp"
#include "CreditCard.cpp"
#include "EWallet.cpp"
#include "BankTransfer.cpp"

using namespace std;

    template <typename T>
    void displayAll(const vector<T>& list) {
        if (list.empty()) {
            cout << "No data." << endl;
            return;
        }
        for (const T& item : list) {
            item.display();
            cout << endl;
        }
    }

int main(){

    ios::sync_with_stdio(0);
    int option;
    vector<CreditCard> DaftarCreditCard;
    vector<EWallet> DaftarEWallet;
    vector<BankTransfer> DaftarBankTransfer;
    do{
        cout << "What you want to do with the data" << endl;
        cout << "1. Edit data" << endl;
        cout << "2. Show all data" << endl;
        cout << "3. Exit program" << endl;
        cout << "Choose(1 - 3): ";
        cin >> option;
        switch(option){
            int dataOption;
            case 1:
                cout << "Select the data you want to change." << endl;
                cout << "1. CreditCard" << endl;
                cout << "2. EWallet" << endl;
                cout << "3. BankTransfer" << endl;
                cout << "Choose(1 - 3): ";
                cin >> dataOption;
            break;
            
            case 2:
                cout << "Select the data you want to show." << endl;
                cout << "1. CreditCard" << endl;
                cout << "2. EWallet" << endl;
                cout << "3. BankTransfer" << endl;
                cout << "4. All data" << endl;
                cout << "Choose(1 - 4): ";
                cin >> dataOption;
                switch(dataOption){
                    case 1:
                    displayAll(DaftarCreditCard);             
                    break;
                    case 2:
                    displayAll(DaftarEWallet);
                    break;
                    case 3:
                    displayAll(DaftarBankTransfer);
                    break;
                    case 4:
                    displayAll(DaftarCreditCard);             
                    displayAll(DaftarEWallet);
                    displayAll(DaftarBankTransfer);
                    break;
                }
            break;

            case 3:
                cout << "Program finished." << endl;
            break;
            
            default:
                cout << "option invalid" << endl;
        }   
    }while(option != 3);

    return 0;
}
