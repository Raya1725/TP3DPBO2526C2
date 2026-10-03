from EWallet import EWallet
from CreditCard import CreditCard
from BankTransfer import BankTransfer


class User:
    def __init__(self, name, address, email):
        self.__name = name
        self.__address = address
        self.__email = email
        # Composition: ketiga objek dibuat oleh User sendiri.
        self.__Creditcard = CreditCard()
        self.__Ewallet = EWallet()
        self.__Banktransfer = BankTransfer()

    def getName(self):
        return self.__name

    def getAddress(self):
        return self.__address

    def getEmail(self):
        return self.__email

    def getCreditCard(self):
        return self.__Creditcard

    def getEWallet(self):
        return self.__Ewallet

    def getBankTransfer(self):
        return self.__Banktransfer

    def setName(self, name):
        self.__name = name

    def setAddress(self, address):
        self.__address = address

    def setEmail(self, email):
        self.__email = email

    def display(self):
        print(f"Name: {self.__name}")
        print(f"Address: {self.__address}")
        print(f"Email: {self.__email}")
        print()
        self.__Creditcard.display()
        print()
        self.__Ewallet.display()
        print()
        self.__Banktransfer.display()