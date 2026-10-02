// BankTransfer.h
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
        static const size_t MIN_VA_LENGTH = 8;
        static const size_t MAX_VA_LENGTH = 20;

        string bankName;
        string accountHolderName;
        string virtualAccountNumber;

        // Nomor VA disimpan sebagai string agar angka 0 di depan tidak hilang.
        static void requireValidVirtualAccountNumber(const string& virtualAccountNumber) {
            bool validLength = virtualAccountNumber.size() >= MIN_VA_LENGTH &&
                            virtualAccountNumber.size() <= MAX_VA_LENGTH;
            bool allDigits = all_of(virtualAccountNumber.begin(), virtualAccountNumber.end(),
                                    [](unsigned char ch) { return isdigit(ch) != 0; });
            if (!validLength || !allDigits) {
                throw invalid_argument("virtualAccountNumber harus 8-20 digit angka");
            }
        }

    public:
    BankTransfer() = default;

        /**
         * Membuat metode transfer bank.
         * @throws invalid_argument jika ada input yang tidak valid.
         * Waktu: O(n + L), memori: O(n + L), n = jumlah mata uang, L = panjang string.
         */
        BankTransfer(const string& id, const string& userID,
                    const vector<string>& supportedCurrencies,
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
         * @throws invalid_argument jika bankName kosong.
         * Waktu: O(L), memori: O(L).
         */
        void setBankName(const string& bankName) {
            requireNotEmpty(bankName, "bankName");
            this->bankName = bankName;
        }

        /**
         * @throws invalid_argument jika accountHolderName kosong.
         * Waktu: O(L), memori: O(L).
         */
        void setAccountHolderName(const string& accountHolderName) {
            requireNotEmpty(accountHolderName, "accountHolderName");
            this->accountHolderName = accountHolderName;
        }

        /**
         * @throws invalid_argument jika bukan 8-20 digit angka.
         * Waktu: O(L), memori: O(L).
         */
        void setVirtualAccountNumber(const string& virtualAccountNumber) {
            requireValidVirtualAccountNumber(virtualAccountNumber);
            this->virtualAccountNumber = virtualAccountNumber;
        }
};