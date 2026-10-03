#pragma once
#include <iostream>
#include <string>

#include "PaymentMethod.cpp"
#include "CreditCard.cpp"
#include "EWallet.cpp"
#include "BankTransfer.cpp"

using namespace std;

class User {
    private:
        string name;
        string address;
        string email;

        // Composition: objek anggota (bukan pointer) dibuat otomatis saat User
        // dibuat dan dihancurkan otomatis saat User dihancurkan.
        CreditCard creditCard;
        EWallet eWallet;
        BankTransfer bankTransfer;

    public:
        User(){

        }

        /**
         * Membuat user beserta metode pembayarannya yang masih kosong.
         * Waktu: O(L), memori: O(L), L = panjang string.
         */
        User(const string& name, const string& address, const string& email) {
            this->name = name;
            this->address = address;
            this->email = email;
        }

        /** Waktu: O(1), memori: O(1). */
        const string& getName() const {
            return this->name;
        }

        /** Waktu: O(1), memori: O(1). */
        const string& getAddress() const {
            return this->address;
        }

        /** Waktu: O(1), memori: O(1). */
        const string& getEmail() const {
            return this->email;
        }

        // Dikembalikan sebagai referensi agar perubahan lewat getter
        // mengubah objek milik User, bukan salinannya.
        /** Waktu: O(1), memori: O(1). */
        CreditCard& getCreditCard() {
            return this->creditCard;
        }

        /** Waktu: O(1), memori: O(1). */
        EWallet& getEWallet() {
            return this->eWallet;
        }

        /** Waktu: O(1), memori: O(1). */
        BankTransfer& getBankTransfer() {
            return this->bankTransfer;
        }

        /** Waktu: O(L), memori: O(L). */
        void setName(const string& name) {
            this->name = name;
        }

        /** Waktu: O(L), memori: O(L). */
        void setAddress(const string& address) {
            this->address = address;
        }

        /** Waktu: O(L), memori: O(L). */
        void setEmail(const string& email) {
            this->email = email;
        }

        /** Waktu: O(L), memori: O(1). */
        void display() const {
            cout << "Name: " << this->name << endl;
            cout << "Address: " << this->address << endl;
            cout << "Email: " << this->email << endl;
            cout << endl;
            this->creditCard.display();
            cout << endl;
            this->eWallet.display();
            cout << endl;
            this->bankTransfer.display();
        }
};