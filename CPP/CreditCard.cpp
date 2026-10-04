#pragma once
#include <iostream>
#include <string>

#include "PaymentMethod.cpp"

using namespace std;

class CreditCard : public PaymentMethod {
    private:

        string cardNumber;
        double creditLimit = 0.0;
        string expiryDate;

    public:
        CreditCard(){
            
        }
        /**
         * Membuat kartu kredit.
         * Waktu: O(L), memori: O(L), L = panjang string.
         */
        CreditCard(const string& id, const string& userID, const string& supportedCurrencies, const string& cardNumber, double creditLimit, const string& expiryDate) : PaymentMethod(id, userID, supportedCurrencies){
            this->cardNumber = cardNumber;
            this->creditLimit = creditLimit;
            this->expiryDate = expiryDate;
        }

        /** Waktu: O(1), memori: O(1). */
        const string& getCardNumber() const { 
            return this->cardNumber; 
        }

        /** Waktu: O(1), memori: O(1). */
        double getCreditLimit() const { 
            return this->creditLimit; 
        }

        /** Waktu: O(1), memori: O(1). */
        const string& getExpiryDate() const { 
            return this->expiryDate; 
        }

        /** Waktu: O(L), memori: O(L). */
        void setCardNumber(const string& cardNumber) {
            this->cardNumber = cardNumber;
        }

        /** Waktu: O(1), memori: O(1). */
        void setCreditLimit(double creditLimit) {
            this->creditLimit = creditLimit;
        }

        /** Waktu: O(L), memori: O(L). */
        void setExpiryDate(const string& expiryDate) {
            this->expiryDate = expiryDate;
        }

        ~CreditCard(){

        }

        /** Waktu: O(L), memori: O(1). */
        void display() const override {
            PaymentMethod::display();
            cout << "Card Number: " << this->cardNumber << endl;
            cout << "Credit Limit: " << this->creditLimit << endl;
            cout << "Expiry Date: " << this->expiryDate << endl;
        }
};