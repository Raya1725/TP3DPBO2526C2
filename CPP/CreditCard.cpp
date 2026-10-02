#pragma once
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <string>
#include <vector>

#include "PaymentMethod.cpp"

using namespace std;

class CreditCard : public PaymentMethod {
    private:
        static const size_t MIN_CARD_NUMBER_LENGTH = 13;
        static const size_t MAX_CARD_NUMBER_LENGTH = 19;

        string cardNumber;
        double creditLimit = 0.0;
        string expiryDate;

        // Nomor kartu disimpan sebagai string karena 16 digit melebihi batas int.
        static void requireValidCardNumber(const string& cardNumber) {
            bool allDigits = all_of(cardNumber.begin(), cardNumber.end(),[](unsigned char ch) { return isdigit(ch) != 0; });
            bool validLength = cardNumber.size() >= MIN_CARD_NUMBER_LENGTH && cardNumber.size() <= MAX_CARD_NUMBER_LENGTH;
            if (!allDigits || !validLength) {
                throw invalid_argument("cardNumber harus 13-19 digit angka");
            }
        }

        static void requireValidCreditLimit(double creditLimit) {
            // Kondisi dibalik agar NaN juga ditolak.
            if (!(creditLimit >= 0.0)) {
                throw invalid_argument("creditLimit tidak boleh negatif atau NaN");
            }
        }

    public:
        CreditCard(){
            
        }
        /**
         * Membuat kartu kredit.
         * @throws invalid_argument jika ada input yang tidak valid.
         * Waktu: O(n + L), memori: O(n + L), n = jumlah mata uang, L = panjang string.
         */
        CreditCard(const string& id, const string& userID, const vector<string>& supportedCurrencies, const string& cardNumber, double creditLimit, const string& expiryDate) : PaymentMethod(id, userID, supportedCurrencies){
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

        /**
         * @throws invalid_argument jika bukan 13-19 digit angka.
         * Waktu: O(L), memori: O(L).
         */
        void setCardNumber(const string& cardNumber) {
            requireValidCardNumber(cardNumber);
            this->cardNumber = cardNumber;
        }

        /**
         * @throws invalid_argument jika negatif atau NaN.
         * Waktu: O(1), memori: O(1).
         */
        void setCreditLimit(double creditLimit) {
            requireValidCreditLimit(creditLimit);
            this->creditLimit = creditLimit;
        }

        /**
         * @throws invalid_argument jika kosong.
         * Waktu: O(L), memori: O(L).
         */
        void setExpiryDate(const string& expiryDate) {
            requireNotEmpty(expiryDate, "expiryDate");
            this->expiryDate = expiryDate;
        }
};