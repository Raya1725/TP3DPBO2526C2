import java.util.Scanner;
import java.util.ArrayList;

public class Main{

    /**
     * Menampilkan daftar user lalu meminta user memilih salah satu.
     *
     * @return Indeks user yang dipilih, atau -1 jika daftar kosong atau pilihan tidak valid.
     *
     * Waktu: O(n), memori: O(1).
     */
    static int selectUser(ArrayList<User> list, Scanner sc) {
        if (list.isEmpty()) {
            System.out.println("No user yet.");
            return -1;
        }
        System.out.println("Select the user.");
        for (int i = 0; i < list.size(); i++) {
            System.out.println((i + 1) + ". " + list.get(i).getName());
        }
        System.out.print("Choose(1 - " + list.size() + "): ");
        while(!sc.hasNextInt()){
            System.out.print("enter only number: ");
            sc.nextLine();
        }
        int choice = sc.nextInt();
        sc.nextLine();
        if (choice < 1 || choice > list.size()) {
            System.out.println("option invalid");
            return -1;
        }
        return choice - 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int option;
        int dataOption;
        ArrayList<User> daftarUser = new ArrayList<>();
        do{
            System.out.println("What you want to do with the data");
            System.out.println("1. Add user");
            System.out.println("2. Edit data");
            System.out.println("3. Show data");
            System.out.println("4. Exit program");
            System.out.print("Choose(1 - 4): ");
            while(!sc.hasNextInt()){
                System.out.print("enter only number: ");
                sc.next();
            }
            option = sc.nextInt();
            sc.nextLine();
            switch(option){
                case 1:{
                    String name;
                    String address;
                    String email;
                    System.out.print("Enter name: ");
                    name = sc.nextLine();
                    System.out.print("Enter address: ");
                    address = sc.nextLine();
                    System.out.print("Enter email: ");
                    email = sc.nextLine();
                    daftarUser.add(new User(name, address, email));
                    break;
                }
                case 2:{
                    int userIndex = selectUser(daftarUser, sc);
                    if(userIndex == -1){
                        break;
                    }
                    User user = daftarUser.get(userIndex);
                    System.out.println("Select the data you want to change.");
                    System.out.println("1. CreditCard");
                    System.out.println("2. EWallet");
                    System.out.println("3. BankTransfer");
                    System.out.print("Choose(1 - 3): ");
                    while(!sc.hasNextInt()){
                        System.out.print("enter only number: ");
                        sc.nextLine();
                    }
                    dataOption = sc.nextInt();
                    sc.nextLine();
                    String id;
                    String userId;
                    String supportedCurrencies;
                    switch(dataOption){
                        case 1:{
                            String cardNumber;
                            double creditLimit;
                            String expiryDate;
                            System.out.print("Enter credit card id: ");
                            id = sc.nextLine();
                            System.out.print("Enter user id: ");
                            userId = sc.nextLine();
                            System.out.print("Enter supported currencies: ");
                            supportedCurrencies = sc.nextLine();
                            System.out.print("Enter card number: ");
                            cardNumber = sc.nextLine();
                            System.out.print("Enter credit limit: ");
                            while(!sc.hasNextDouble()){
                                System.out.print("enter only number: ");
                                sc.nextLine();
                            }
                            creditLimit = sc.nextDouble();
                            sc.nextLine();
                            System.out.print("Enter expiry date: ");
                            expiryDate = sc.nextLine();
                            user.getCreditCard().setId(id);
                            user.getCreditCard().setUserId(userId);
                            user.getCreditCard().setSupportedCurrencies(supportedCurrencies);
                            user.getCreditCard().setCardNumber(cardNumber);
                            user.getCreditCard().setCreditLimit(creditLimit);
                            user.getCreditCard().setExpiryDate(expiryDate);
                            break;
                        }
                        case 2:{
                            String provider;
                            String phoneNumber;
                            double balance;
                            System.out.print("Enter Ewallet id: ");
                            id = sc.nextLine();
                            System.out.print("Enter user id: ");
                            userId = sc.nextLine();
                            System.out.print("Enter supported currencies: ");
                            supportedCurrencies = sc.nextLine();
                            System.out.print("Enter provider: ");
                            provider = sc.nextLine();
                            System.out.print("Enter phone number: ");
                            phoneNumber = sc.nextLine();
                            System.out.print("Enter balance: ");
                            while(!sc.hasNextDouble()){
                                System.out.print("enter only number: ");
                                sc.nextLine();
                            }
                            balance = sc.nextDouble();
                            sc.nextLine();
                            user.getEWallet().setId(id);
                            user.getEWallet().setUserId(userId);
                            user.getEWallet().setSupportedCurrencies(supportedCurrencies);
                            user.getEWallet().setProvider(provider);
                            user.getEWallet().setPhoneNumber(phoneNumber);
                            user.getEWallet().setBalance(balance);
                            break;
                        }
                        case 3:{
                            String bankName;
                            String accountHolderName;
                            String virtualAccountNumber;
                            System.out.print("Enter bank id: ");
                            id = sc.nextLine();
                            System.out.print("Enter user id: ");
                            userId = sc.nextLine();
                            System.out.print("Enter supported currencies: ");
                            supportedCurrencies = sc.nextLine();
                            System.out.print("Enter bank name: ");
                            bankName = sc.nextLine();
                            System.out.print("Enter account holder name: ");
                            accountHolderName = sc.nextLine();
                            System.out.print("Enter virtual account number: ");
                            virtualAccountNumber = sc.nextLine();
                            user.getBankTransfer().setId(id);
                            user.getBankTransfer().setUserId(userId);
                            user.getBankTransfer().setSupportedCurrencies(supportedCurrencies);
                            user.getBankTransfer().setBankName(bankName);
                            user.getBankTransfer().setAccountHolderName(accountHolderName);
                            user.getBankTransfer().setVirtualAccountNumber(virtualAccountNumber);
                            break;
                        }
                        default: {
                            System.out.println("option invalid");
                            break;
                        }
                    }
                    break;
                }
                case 3:{
                    int userIndex = selectUser(daftarUser, sc);
                    if(userIndex == -1){
                        break;
                    }
                    User user = daftarUser.get(userIndex);
                    System.out.println("Select the data you want to show.");
                    System.out.println("1. CreditCard");
                    System.out.println("2. EWallet");
                    System.out.println("3. BankTransfer");
                    System.out.println("4. All data");
                    System.out.print("Choose(1 - 4): ");
                    while(!sc.hasNextInt()){
                        System.out.print("enter only number: ");
                        sc.nextLine();
                    }
                    dataOption = sc.nextInt();
                    sc.nextLine();
                    switch(dataOption){
                        case 1:{
                            System.out.println("Credit card data: ");
                            user.getCreditCard().display();
                            break;
                        }
                        case 2:{
                            System.out.println("Ewallet data: ");
                            user.getEWallet().display();
                            break;
                        }
                        case 3:{
                            System.out.println("Bank transfer data: ");
                            user.getBankTransfer().display();
                            break;
                        }
                        case 4:{
                            System.out.println("User data: ");
                            user.display();
                            System.out.println();
                            break;
                        }
                        default: {
                            System.out.println("option invalid");
                            break;
                        }
                    }
                    break;
                }
                case 4: {
                    System.out.println("Program finished.");
                    break;
                }

                default: {
                    System.out.println("option invalid");
                    break;
                }
            }
        }while(option != 4);
        sc.close();
    }
}