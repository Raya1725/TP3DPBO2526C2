#pragma once
#include <iostream>
#include <string>

using namespace std;

class PaymentMethod {
    private:
        string id;
        string userID;
        string supportedCurrencies;

    public:
        PaymentMethod(){

        }

        /**
         * Membuat metode pembayaran.
         * Waktu: O(L), memori: O(L), L = panjang string.
         */
        PaymentMethod(const string& id, const string& userID,
                    const string& supportedCurrencies) {
            this->id = id;
            this->userID = userID;
            this->supportedCurrencies = supportedCurrencies;
        }

        /** Waktu: O(1), memori: O(1). */
        const string& getId() const { 
            return this->id; 
        }

        /** Waktu: O(1), memori: O(1). */
        const string& getUserId() const { 
            return this->userID; 
        }

        /** Waktu: O(1), memori: O(1). */
        const string& getSupportedCurrencies() const {
            return this->supportedCurrencies;
        }

        /** Waktu: O(L), memori: O(L). */
        void setId(const string& id) {
            this->id = id;
        }

        /** Waktu: O(L), memori: O(L). */
        void setUserId(const string& userID) {
            this->userID = userID;
        }

        /** Waktu: O(L), memori: O(L). */
        void setSupportedCurrencies(const string& supportedCurrencies) {
            this->supportedCurrencies = supportedCurrencies;
        }

        virtual ~PaymentMethod(){ }

        /**
         * Menampilkan data umum metode pembayaran.
         * Waktu: O(L), memori: O(1).
         */
        virtual void display() const {
            cout << "ID: " << this->id << endl;
            cout << "User ID: " << this->userID << endl;
            cout << "Supported Currencies: " << this->supportedCurrencies << endl;            
        }
};