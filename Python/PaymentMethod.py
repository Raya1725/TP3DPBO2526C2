class PaymentMethod:
    def __init__(self, id = "", userId =  "", supportedCurrencies = ""):
        self.__id = id
        self.__userId = userId
        self.__supportedCurrencies = supportedCurrencies

    def getId(self):
        return self.__id;

    def getUserId(self):
        return self.__userId

    def getSupportedCurrencies(self):
        return self.__supportedCurrencies

    def setId(self, id):
        self.__id = id

    def setUserId(self, userId):
        self.__userId = userId

    def setSupportedCurrencies(self, supportedCurrencies):
        self.__supportedCurrencies = supportedCurrencies

    def display(self):
        print(f"ID: {self.__id}")
        print(f"User ID: {self.__userId}")
        print(f"Supported Currencies: {self.__supportedCurrencies}")