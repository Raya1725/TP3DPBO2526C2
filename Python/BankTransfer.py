from PaymentMethod import PaymentMethod

class BankTransfer (PaymentMethod):
    def __init__(self, id = "", userId = "", supportedCurrencies = "", bankName = "", accountHolderName = "", virtualAccountNumber = ""):
        super().__init__(id, userId, supportedCurrencies)
        self.__bankName = bankName
        self.__accountHolderName = accountHolderName
        self.__virtualAccountNumber = virtualAccountNumber

    def getBankName(self):
        return self.__bankName

    def getAccountHolderName(self):
        return self.__accountHolderName

    def getVirtualAccountNumber(self):
        return self.__virtualAccountNumber

    def setBankName(self, bankName):
        self.__bankName = bankName

    def setAccountHolderName(self, accountHolderName):
        self.__accountHolderName = accountHolderName

    def setVirtualAccountNumber(self, virtualAccountNumber):
        self.__virtualAccountNumber = virtualAccountNumber

    def display(self):
        super().display()
        print(F"Bank Name: {self.__bankName}")
        print(F"Account Holder Name: {self.__accountHolderName}")
        print(F"Virtual Account Number: {self.__virtualAccountNumber}")