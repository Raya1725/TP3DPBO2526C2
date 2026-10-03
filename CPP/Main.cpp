#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "PaymentMethod.cpp"
#include "CreditCard.cpp"
#include "EWallet.cpp"
#include "BankTransfer.cpp"

using namespace std;

template <typename T>
void displayAll(const vector<T>& list) {
    if (list.empty()) {
        cout << "No data." << endl;
    }
    for (const T& item : list) {
        item.display();
        cout << endl;
    }
}

int main(){
    
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(0);
    int option;
    vector<CreditCard> DaftarCreditCard;
    vector<EWallet> DaftarEWallet;
    vector<BankTransfer> DaftarBankTransfer;
    do{
        cout << "What you want to do with the data" << endl;
        cout << "1. Edit data" << endl;
        cout << "2. Show data" << endl;
        cout << "3. Exit program" << endl;
        cout << "Choose(1 - 3): ";
        cin >> option;
        switch(option){
            int dataOption;
            case 1: {
                cout << "Select the data you want to change." << endl;
                cout << "1. CreditCard" << endl;
                cout << "2. EWallet" << endl;
                cout << "3. BankTransfer" << endl;
                cout << "Choose(1 - 3): ";
                cin >> dataOption;
                string id;
                string userId;
                string supportedCurrencies;
                switch(dataOption){
                    case 1:{
                        CreditCard C = CreditCard();
                        string cardNumber;
                        double creditLimit;
                        string expirydate;
                        cout << "Enter credit card id: ";
                        cin >> id;
                        cout << "Enter user id: ";
                        cin >> userId;
                        cin.ignore();
                        cout << "Enter supported currencies: ";
                        getline(cin, supportedCurrencies);
                        cout << "Enter card number: ";
                        cin >> cardNumber;
                        cout << "Enter credit limit: ";
                        cin >> creditLimit;
                        cout << "Enter expirty date: ";
                        cin >> expirydate;
                        C = CreditCard(id, userId, supportedCurrencies, cardNumber, creditLimit, expirydate);
                        DaftarCreditCard.push_back(C);
                        break;
                    }
                    case 2:{
                        EWallet E = EWallet();
                        string provider;
                        string phoneNumber;
                        double balance;
                        cout << "Enter ewallet id: ";
                        cin >> id;
                        cout << "Enter user id: ";
                        cin >> userId;
                        cin.ignore();
                        cout << "Enter supported currencies: ";
                        getline(cin, supportedCurrencies);
                        cout << "Enter provider: ";
                        getline(cin, provider);
                        cout << "Enter phone number: ";
                        cin >> phoneNumber;
                        cout << "Enter balance: ";
                        cin >> balance;
                        E = EWallet(id, userId, supportedCurrencies, provider, phoneNumber, balance);
                        DaftarEWallet.push_back(E);
                        break;
                    }
                    case 3:{
                        BankTransfer B = BankTransfer();
                        string bankName;
                        string accountHolderName;
                        string virtualAccountNumber;
                        cout << "Enter bank id: ";
                        cin >> id;
                        cout << "Enter user id: ";
                        cin >> userId;
                        cin.ignore();
                        cout << "Enter suppoerted currencies: ";
                        getline(cin, supportedCurrencies);
                        cout << "Enter bank name: ";
                        cin >> bankName;
                        cout << "Enter account holder name: ";
                        cin >> accountHolderName;
                        cout << "Enter virtual account number: ";
                        cin >> virtualAccountNumber;
                        B = BankTransfer(id, userId, supportedCurrencies, bankName, accountHolderName, virtualAccountNumber);
                        DaftarBankTransfer.push_back(B);
                        break;
                    }
                }
                break;
            }
            
            case 2: {
                cout << "Select the data you want to show." << endl;
                cout << "1. CreditCard" << endl;
                cout << "2. EWallet" << endl;
                cout << "3. BankTransfer" << endl;
                cout << "4. All data" << endl;
                cout << "Choose(1 - 4): ";
                cin >> dataOption;
                switch(dataOption){
                    case 1:{    
                        cout << "Credit card data: " << endl;
                        cout << endl;
                        displayAll(DaftarCreditCard);             
                        break;
                    }
                    case 2:{    
                        cout << "Ewallet data: " << endl;
                        cout << endl;
                        displayAll(DaftarEWallet);
                        break;
                    }
                    case 3:{
                        cout << "Bank transfer data: " << endl;
                        cout << endl;
                        displayAll(DaftarBankTransfer);
                        break;
                    }
                    case 4:{
                        cout << "Credit card data: " << endl;
                        displayAll(DaftarCreditCard);             
                        cout << endl;
                        cout << "Ewallet data: " << endl;
                        displayAll(DaftarEWallet);
                        cout << endl;
                        cout << "Bank transfer data: " << endl;
                        displayAll(DaftarBankTransfer);
                        cout << endl;
                        break;
                    }
                }
                break;
            }

            case 3: {
                cout << "Program finished." << endl;
                break;
            }
            
            default: {
                cout << "option invalid" << endl;
            } 
        
        }   
    }while(option != 3);

    return 0;
}