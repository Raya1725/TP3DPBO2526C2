from User import User


def readNumber(prompt, numberType):
    while True:
        try:
            return numberType(input(prompt))
        except ValueError:
            prompt = "enter only number: "


def selectUser(userList):
    if not userList:
        print("No user yet.")
        return -1
    print("Select the user.")
    for index, user in enumerate(userList):
        print(f"{index + 1}. {user.getName()}")
    choice = readNumber(f"Choose(1 - {len(userList)}): ", int)
    if choice < 1 or choice > len(userList):
        print("option invalid")
        return -1
    return choice - 1


def main():
    userList = []
    option = 0
    while option != 4:
        print("What you want to do with the data")
        print("1. Add user")
        print("2. Edit data")
        print("3. Show data")
        print("4. Exit program")
        option = readNumber("Choose(1 - 4): ", int)
        match option:
            case 1:
                name = input("Enter name: ")
                address = input("Enter address: ")
                email = input("Enter email: ")
                userList.append(User(name, address, email))
            case 2:
                userIndex = selectUser(userList)
                if userIndex == -1:
                    continue
                user = userList[userIndex]
                print("Select the data you want to change.")
                print("1. CreditCard")
                print("2. EWallet")
                print("3. BankTransfer")
                dataOption = readNumber("Choose(1 - 3): ", int)
                match dataOption:
                    case 1:
                        id = input("Enter credit card id: ")
                        userId = input("Enter user id: ")
                        supportedCurrencies = input("Enter supported currencies: ")
                        cardNumber = input("Enter card number: ")
                        creditLimit = readNumber("Enter credit limit: ", float)
                        expiryDate = input("Enter expiry date: ")
                        user.getCreditCard().setId(id)
                        user.getCreditCard().setUserId(userId)
                        user.getCreditCard().setSupportedCurrencies(supportedCurrencies)
                        user.getCreditCard().setCardNumber(cardNumber)
                        user.getCreditCard().setCreditLimit(creditLimit)
                        user.getCreditCard().setExpiryDate(expiryDate)
                    case 2:
                        id = input("Enter Ewallet id: ")
                        userId = input("Enter user id: ")
                        supportedCurrencies = input("Enter supported currencies: ")
                        provider = input("Enter provider: ")
                        phoneNumber = input("Enter phone number: ")
                        balance = readNumber("Enter balance: ", float)
                        user.getEWallet().setId(id)
                        user.getEWallet().setUserId(userId)
                        user.getEWallet().setSupportedCurrencies(supportedCurrencies)
                        user.getEWallet().setProvider(provider)
                        user.getEWallet().setPhoneNumber(phoneNumber)
                        user.getEWallet().setBalance(balance)
                    case 3:
                        id = input("Enter bank id: ")
                        userId = input("Enter user id: ")
                        supportedCurrencies = input("Enter supported currencies: ")
                        bankName = input("Enter bank name: ")
                        accountHolderName = input("Enter account holder name: ")
                        virtualAccountNumber = input("Enter virtual account number: ")
                        user.getBankTransfer().setId(id)
                        user.getBankTransfer().setUserId(userId)
                        user.getBankTransfer().setSupportedCurrencies(supportedCurrencies)
                        user.getBankTransfer().setBankName(bankName)
                        user.getBankTransfer().setAccountHolderName(accountHolderName)
                        user.getBankTransfer().setVirtualAccountNumber(virtualAccountNumber)
                    case _:
                        print("option invalid")
            case 3:
                userIndex = selectUser(userList)
                if userIndex == -1:
                    continue
                user = userList[userIndex]
                print("Select the data you want to show.")
                print("1. CreditCard")
                print("2. EWallet")
                print("3. BankTransfer")
                print("4. All data")
                dataOption = readNumber("Choose(1 - 4): ", int)
                match dataOption:
                    case 1:
                        print("Credit card data: ")
                        user.getCreditCard().display()
                    case 2:
                        print("Ewallet data: ")
                        user.getEWallet().display()
                    case 3:
                        print("Bank transfer data: ")
                        user.getBankTransfer().display()
                    case 4:
                        print("User data: ")
                        user.display()
                        print()
                    case _:
                        print("option invalid")
            case 4:
                print("Program finished.")
            case _:
                print("option invalid")


if __name__ == "__main__":
    main()