#pragma once
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <string>
#include <vector>

#include "PaymentMethod.cpp"

using namespace std;

class BankTransfer : public PaymentMethod {
    private:

        string bankName;
        string accountHolderName;
        string virtualAccountNumber;

    public:
        BankTransfer(){

        }

        /**
         * Membuat metode transfer bank.
         * Waktu: O(n + L), memori: O(n + L), n = jumlah mata uang, L = panjang string.
         */
        BankTransfer(const string& id, const string& userID,
                    const string& supportedCurrencies,
                    const string& bankName, const string& accountHolderName,
                    const string& virtualAccountNumber)
            : PaymentMethod(id, userID, supportedCurrencies) {
            this->bankName = bankName;
            this->accountHolderName = accountHolderName;
            this->virtualAccountNumber = virtualAccountNumber;
        }

        /** Waktu: O(1), memori: O(1). */
        const string& getBankName() const { 
            return this->bankName; 
        }

        /** Waktu: O(1), memori: O(1). */
        const string& getAccountHolderName() const { 
            return this->accountHolderName; 
        }

        /** Waktu: O(1), memori: O(1). */
        const string& getVirtualAccountNumber() const { 
            return this->virtualAccountNumber; 
        }

        /**
         * Waktu: O(L), memori: O(L).
         */
        void setBankName(const string& bankName) {
            this->bankName = bankName;
        }

        /**
         * Waktu: O(L), memori: O(L).
         */
        void setAccountHolderName(const string& accountHolderName) {
            this->accountHolderName = accountHolderName;
        }

        /**
         * Waktu: O(L), memori: O(L).
         */
        void setVirtualAccountNumber(const string& virtualAccountNumber) {
            this->virtualAccountNumber = virtualAccountNumber;
        }

        ~BankTransfer(){

        }

        /** Waktu: O(n), memori: O(1). */
        void display() const override {
            PaymentMethod::display();
            cout << "Bank Name: " << this->bankName << endl;
            cout << "Account Holder Name: " << this->accountHolderName << endl;
            cout << "Virtual Account Number: " << this->virtualAccountNumber << endl;
        }
};