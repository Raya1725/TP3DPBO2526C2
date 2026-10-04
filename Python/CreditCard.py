from PaymentMethod import PaymentMethod

class CreditCard (PaymentMethod):
    def __init__(self, id= "", userId = "", supportedCurrencies = "", cardNumber = "", creditLimit = 0.0, expiryDate = ""):
        super().__init__(id, userId, supportedCurrencies)
        self.__cardNumber = cardNumber
        self.__creditLimit = creditLimit
        self.__expiryDate = expiryDate

    def getCardNumber(self):
        return self.__cardNumber

    def getCreditLimit(self):
        return self.__creditLimit

    def getExpiryDate(self):
        return self.__expiryDate

    def setCardNumber(self, cardNumber):
        self.__cardNumber = cardNumber

    def setCreditLimit(self, creditLimit):
        self.__creditLimit = creditLimit

    def setExpiryDate(self, expiryDate):
        self.__expiryDate = expiryDate

    def display(self):
        super().display()
        print(F"Card Number: {self.__cardNumber}")
        print(F"Credit Limit: {self.__creditLimit}")
        print(F"Expiry Date: {self.__expiryDate}")