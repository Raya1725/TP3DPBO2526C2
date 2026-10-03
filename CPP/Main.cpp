#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include "PaymentMethod.cpp"
#include "CreditCard.cpp"
#include "EWallet.cpp"
#include "BankTransfer.cpp"
#include "User.cpp"

using namespace std;

/**
 * Menampilkan daftar user lalu meminta user memilih salah satu.
 *
 * @return Indeks user yang dipilih, atau -1 jika daftar kosong atau pilihan tidak valid.
 *
 * Waktu: O(n), memori: O(1).
 */
int selectUser(const vector<User>& list) {
    if (list.empty()) {
        cout << "No user yet." << endl;
        return -1;
    }
    cout << "Select the user." << endl;
    for (int i = 0; i < (int)list.size(); i++) {
        cout << i + 1 << ". " << list[i].getName() << endl;
    }
    cout << "Choose(1 - " << list.size() << "): ";
    int choice;
    cin >> choice;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "enter only number: ";
        cin >> choice;
    }
    if (choice < 1 || choice > (int)list.size()) {
        cout << "option invalid" << endl;
        return -1;
    }
    return choice - 1;
}

int main(){

    ios::sync_with_stdio(0);
    cout << fixed << setprecision(0);
    int option;
    int dataOption;
    vector<User> DaftarUser;
    do{
        cout << "What you want to do with the data" << endl;
        cout << "1. Add user" << endl;
        cout << "2. Edit data" << endl;
        cout << "3. Show data" << endl;
        cout << "4. Exit program" << endl;
        cout << "Choose(1 - 4): ";
        cin >> option;
        while(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "enter only number: ";
            cin >> option;
        }
        cin.ignore();
        switch(option){
            case 1: {
                string name;
                string address;
                string email;
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter address: ";
                getline(cin, address);
                cout << "Enter email: ";
                getline(cin, email);
                DaftarUser.push_back(User(name, address, email));
                break;
            }

            case 2: {
                int userIndex = selectUser(DaftarUser);
                if(userIndex == -1){
                    break;
                }
                User& user = DaftarUser[userIndex];
                cout << "Select the data you want to change." << endl;
                cout << "1. CreditCard" << endl;
                cout << "2. EWallet" << endl;
                cout << "3. BankTransfer" << endl;
                cout << "Choose(1 - 3): ";
                cin >> dataOption;
                while(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "enter only number: ";
                    cin >> dataOption;
                }
                string id;
                string userId;
                string supportedCurrencies;
                switch(dataOption){
                    case 1:{
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
                        while(cin.fail()){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "enter only number: ";
                            cin >> creditLimit;
                        }
                        cin.ignore();
                        cout << "Enter expirty date: ";
                        cin >> expirydate;
                        user.getCreditCard().setId(id);
                        user.getCreditCard().setUserId(userId);
                        user.getCreditCard().setSupportedCurrencies(supportedCurrencies);
                        user.getCreditCard().setCardNumber(cardNumber);
                        user.getCreditCard().setCreditLimit(creditLimit);
                        user.getCreditCard().setExpiryDate(expirydate);
                        break;
                    }
                    case 2:{
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
                        while(cin.fail()){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "enter only number: ";
                            cin >> balance;
                        }
                        cin.ignore();
                        user.getEWallet().setId(id);
                        user.getEWallet().setUserId(userId);
                        user.getEWallet().setSupportedCurrencies(supportedCurrencies);
                        user.getEWallet().setProvider(provider);
                        user.getEWallet().setPhoneNumber(phoneNumber);
                        user.getEWallet().setBalance(balance);
                        break;
                    }
                    case 3:{
                        string bankName;
                        string accountHolderName;
                        string virtualAccountNumber;
                        cout << "Enter bank id: ";
                        cin >> id;
                        cout << "Enter user id: ";
                        cin >> userId;
                        cin.ignore();
                        cout << "Enter supported currencies: ";
                        getline(cin, supportedCurrencies);
                        cout << "Enter bank name: ";
                        cin >> bankName;
                        cout << "Enter account holder name: ";
                        cin >> accountHolderName;
                        cout << "Enter virtual account number: ";
                        cin >> virtualAccountNumber;
                        user.getBankTransfer().setId(id);
                        user.getBankTransfer().setUserId(userId);
                        user.getBankTransfer().setSupportedCurrencies(supportedCurrencies);
                        user.getBankTransfer().setBankName(bankName);
                        user.getBankTransfer().setAccountHolderName(accountHolderName);
                        user.getBankTransfer().setVirtualAccountNumber(virtualAccountNumber);
                        break;
                    }
                }
                break;
            }

            case 3: {
                int userIndex = selectUser(DaftarUser);
                if(userIndex == -1){
                    break;
                }
                User& user = DaftarUser[userIndex];
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
                        user.getCreditCard().display();
                        break;
                    }
                    case 2:{
                        cout << "Ewallet data: " << endl;
                        cout << endl;
                        user.getEWallet().display();
                        break;
                    }
                    case 3:{
                        cout << "Bank transfer data: " << endl;
                        cout << endl;
                        user.getBankTransfer().display();
                        break;
                    }
                    case 4:{
                        cout << "User data: " << endl;
                        cout << endl;
                        user.display();
                        cout << endl;
                        break;
                    }
                }
                break;
            }

            case 4: {
                cout << "Program finished." << endl;
                break;
            }

            default: {
                cout << "option invalid" << endl;
            }

        }
    }while(option != 4);

    return 0;
}