from PaymentMethod import PaymentMethod

class EWallet (PaymentMethod):

    def __init__(self, id = "", userId = "", supportedCurrencies = "", provider = "", phoneNumber = "", balance = 0.0):
        super().__init__(id, userId, supportedCurrencies)
        self.__provider = provider
        self.__phoneNumber = phoneNumber
        self.__balance = balance

    def getProvider(self):
        return self.__provider

    def getPhoneNumber(self):
        return self.__phoneNumber

    def getBalance(self):
        return self.__balance

    def setProvider(self, provider):
        self.__provider = provider

    def setPhoneNumber(self, phoneNumber):
        self.__phoneNumber = phoneNumber

    def setBalance(self, balance):
        self.__balance = balance

    def display(self):
        super().display()
        print(f"Provider: {self.__provider}")
        print(f"Phone Number: {self.__phoneNumber}")
        print(f"Balance: {self.__balance}")