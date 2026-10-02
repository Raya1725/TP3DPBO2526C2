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
        vector<string> supportedCurrencies;
        
        // Mencegah kode mata uang kosong masuk lewat konstruktor atau setter.
        static void requireValidCurrencies(const vector<string>& currencies) {
            for (const string& currency : currencies) {
                requireNotEmpty(currency, "currency");
            }
        }

    protected:
        // Satu tempat validasi agar tidak ada duplikasi logika (DRY).
        static void requireNotEmpty(const string& value, const string& fieldName) {
            if (value.empty()) {
                throw invalid_argument(fieldName + " tidak boleh kosong");
            }
        }


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
                    const vector<string>& supportedCurrencies) {
            // Validasi dulu agar objek tidak pernah berada dalam keadaan tidak valid.
            requireNotEmpty(id, "id");
            requireNotEmpty(userID, "userID");
            requireValidCurrencies(supportedCurrencies);

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
        const vector<string>& getSupportedCurrencies() const {
            return this->supportedCurrencies;
        }

        /**
         * @throws invalid_argument jika id kosong.
         * Waktu: O(L), memori: O(L), L = panjang id.
         */
        void setId(const string& id) {
            requireNotEmpty(id, "id");
            this->id = id;
        }

        /**
         * @throws invalid_argument jika userID kosong.
         * Waktu: O(L), memori: O(L), L = panjang userID.
         */
        void setUserId(const string& userID) {
            requireNotEmpty(userID, "userID");
            this->userID = userID;
        }

        /**
         * Mengganti seluruh daftar mata uang.
         * @throws invalid_argument jika ada mata uang kosong.
         * Waktu: O(n), memori: O(n).
         */
        void setSupportedCurrencies(const vector<string>& supportedCurrencies) {
            requireValidCurrencies(supportedCurrencies);
            this->supportedCurrencies = supportedCurrencies;
        }

        /**
         * Menambahkan satu mata uang ke daftar yang sudah ada.
         * @throws invalid_argument jika currency kosong.
         * Waktu: O(1) amortized, memori: O(1).
         */
        void addSupportedCurrency(const string& supportedCurrencies) {
            requireNotEmpty(supportedCurrencies, "supportedCurrencies");
            this->supportedCurrencies.push_back(supportedCurrencies);
        }
};