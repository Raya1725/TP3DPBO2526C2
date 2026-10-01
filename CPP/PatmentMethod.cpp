#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PaymentMethod{
    private:
        string id;
        string userID;
        vector<string> supportedCurrencies;
    
    public:

        PaymentMethod(){

        }

        void setid(string id){
            this->id = id;
        }

        string getid(){
            return this->id;
        }

        void setuserid(string userID){
            this->userID = userID;
        }

        string geUserid(){
            return this->userID;
        }

        void setsupportedcurrencies(string userID){
            this->userID = userID;
        }

        vector<string> getallsupportedcurrencies(){
            return this->supportedCurrencies;
        }

        string& getsupportedcurrencies(){

        }

        ~PaymentMethod(){
            
        }
        
};