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
    static const size_t MIN_PHONE_LENGTH = 9;
    static const size_t MAX_PHONE_LENGTH = 15;

    string provider;
    string phoneNumber;
    double balance = 0.0;

    // Nomor telepon disimpan sebagai string agar angka 0 di depan tidak hilang.
    static void requireValidPhoneNumber(const string& phoneNumber) {
        bool validLength = phoneNumber.size() >= MIN_PHONE_LENGTH &&
                           phoneNumber.size() <= MAX_PHONE_LENGTH;
        bool allDigits = all_of(phoneNumber.begin(), phoneNumber.end(),
                                [](unsigned char ch) { return isdigit(ch) != 0; });
        if (!validLength || !allDigits) {
            throw invalid_argument("phoneNumber harus 9-15 digit angka");
        }
    }

    // Kondisi dibalik agar NaN juga ditolak.
    static void requireValidBalance(double balance) {
        if (!(balance >= 0.0) || isinf(balance)) {
            throw invalid_argument("balance harus berupa angka tidak negatif");
        }
    }

public:
    EWallet(){

    }

    /**
     * Membuat e-wallet.
     * @throws invalid_argument jika ada input yang tidak valid.
     * Waktu: O(n + L), memori: O(n + L), n = jumlah mata uang, L = panjang string.
     */
    EWallet(const string& id, const string& userID,
            const vector<string>& supportedCurrencies,
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
     * @throws invalid_argument jika provider kosong.
     * Waktu: O(L), memori: O(L).
     */
    void setProvider(const string& provider) {
        requireNotEmpty(provider, "provider");
        this->provider = provider;
    }

    /**
     * @throws invalid_argument jika bukan 9-15 digit angka.
     * Waktu: O(L), memori: O(L).
     */
    void setPhoneNumber(const string& phoneNumber) {
        requireValidPhoneNumber(phoneNumber);
        this->phoneNumber = phoneNumber;
    }

    /**
     * @throws invalid_argument jika negatif, NaN, atau tak hingga.
     * Waktu: O(1), memori: O(1).
     */
    void setBalance(double balance) {
        requireValidBalance(balance);
        this->balance = balance;
    }
};