#pragma once
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class PaymentMethod {
    private:
        string id;
        string userID;
        string supportedCurrencies;

    public:
        PaymentMethod(){
            
        };

        /**
         * Membuat metode pembayaran.
         * @param id Identitas metode pembayaran, tidak boleh kosong.
         * @param userID Identitas pemilik, tidak boleh kosong.
         * @param supportedCurrencies Daftar kode mata uang, tidak boleh ada yang kosong.
         * @throws invalid_argument jika ada input yang kosong.
         * Waktu: O(n), memori: O(n), n = jumlah mata uang.
         */
        PaymentMethod(const string& id, const string& userID,
                    const string& supportedCurrencies) {
            // Validasi dulu agar objek tidak pernah berada dalam keadaan tidak valid.
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

        /**
         * @throws invalid_argument jika id kosong.
         * Waktu: O(L), memori: O(L), L = panjang id.
         */
        void setId(const string& id) {
            this->id = id;
        }

        /**
         * @throws invalid_argument jika userID kosong.
         * Waktu: O(L), memori: O(L), L = panjang userID.
         */
        void setUserId(const string& userID) {
            this->userID = userID;
        }

        /**
         * Mengganti seluruh daftar mata uang.
         * @throws invalid_argument jika ada mata uang kosong.
         * Waktu: O(n), memori: O(n).
         */
        void setSupportedCurrencies(const string& supportedCurrencies) {
            this->supportedCurrencies = supportedCurrencies;
        }

        ~PaymentMethod(){

        }

        /*
          Menampilkan data umum metode pembayaran.
          Waktu: O(n), memori: O(1), n = jumlah mata uang.
         */
        virtual void display() const {
            cout << "ID: " << this->id << endl;
            cout << "User ID: " << this->userID << endl;
            cout << "Supported Currencies: " << this->supportedCurrencies << endl;            
        }
};