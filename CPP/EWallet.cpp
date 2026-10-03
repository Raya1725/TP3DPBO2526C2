#pragma once
#include <algorithm>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>

#include "PaymentMethod.cpp"

using namespace std;

class EWallet : public PaymentMethod {
    private:

        string provider;
        string phoneNumber;
        double balance = 0.0;

    public:
        EWallet(){

        }

        /**
         * Membuat e-wallet.
         * Waktu: O(n + L), memori: O(n + L), n = jumlah mata uang, L = panjang string.
         */
        EWallet(const string& id, const string& userID,
                const string& supportedCurrencies,
                const string& provider, const string& phoneNumber, double balance)
            : PaymentMethod(id, userID, supportedCurrencies) {
            setProvider(provider);
            setPhoneNumber(phoneNumber);
            setBalance(balance);
        }

        /** Waktu: O(1), memori: O(1). */
        const string& getProvider() const { return this->provider; }

        /** Waktu: O(1), memori: O(1). */
        const string& getPhoneNumber() const { return this->phoneNumber; }

        /** Waktu: O(1), memori: O(1). */
        double getBalance() const { return this->balance; }

        /**
         * Waktu: O(L), memori: O(L).
         */
        void setProvider(const string& provider) {
            this->provider = provider;
        }

        /**
         * Waktu: O(L), memori: O(L).
         */
        void setPhoneNumber(const string& phoneNumber) {
            this->phoneNumber = phoneNumber;
        }

        /**
         * Waktu: O(1), memori: O(1).
         */
        void setBalance(double balance) {
            this->balance = balance;
        }
        ~EWallet(){
            
        }

        /** Waktu: O(n), memori: O(1). */
        void display() const override {
            PaymentMethod::display();
            cout << "Provider: " << this->provider << endl;
            cout << "Phone Number: " << this->phoneNumber << endl;
            cout << "Balance: " << this->balance << endl;
        }
};