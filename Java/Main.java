import java.util.Scanner;
import java.util.ArrayList;

public class Main{

    /**
     * Mengecek apakah id sudah ada di daftar.
     *
     * Waktu: O(n), memori: O(1).
     */
    static boolean isIdExist(ArrayList<? extends PaymentMethod> list, String id) {
        for (PaymentMethod item : list) {
            if (item.getId().equals(id)) {
                return true;
            }
        }
        return false;
    }

    /** Waktu: O(m * L), memori: O(1). */
    static void displayAll(ArrayList<? extends PaymentMethod> list) {
        if (list.isEmpty()) {
            System.out.println("No data.");
            return;
        }
        for (PaymentMethod item : list) {
            item.display();
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int option;
        int dataOption;
        ArrayList<BankTransfer> daftarBankTransfers = new ArrayList<>();
        ArrayList<EWallet> daftarEwallet = new ArrayList<>();
        ArrayList<CreditCard> daftarCreditcards = new ArrayList<>();
        do{
            System.out.println("What you want to do with the data");
            System.out.println("1. Edit data");
            System.out.println("2. Show data");
            System.out.println("3. Exit program");
            System.out.print("Choose(1 - 3): ");
            while(!sc.hasNextInt()){
                System.out.print("enter only number: ");
                sc.next();
            }
            option = sc.nextInt();
            sc.nextLine();
            switch(option){
                case 1:{
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
                    String supportedCurreincies;
                    switch(dataOption){
                        case 1:{
                            CreditCard C = new CreditCard();  
                            String cardNumber;
                            double creditLimit;
                            String expiryDate;
                            System.out.print("Enter credit card id: ");
                            id = sc.nextLine();
                            while (isIdExist(daftarCreditcards, id)) {
                                System.out.print("Id already exists, enter another: ");
                                id = sc.nextLine();
                            }
                            System.out.print("Enter user id: ");
                            userId = sc.nextLine();
                            while (isIdExist(daftarCreditcards, userId)) {
                                System.out.print("Id already exists, enter another: ");
                                userId = sc.nextLine();
                            }
                            System.out.print("Enter supported currencies: ");
                            supportedCurreincies = sc.nextLine();
                            System.out.print("Enter card number: ");
                            cardNumber = sc.nextLine();
                            System.out.print("Enter credit limit: ");
                            while(!sc.hasNextInt()){
                                System.out.print("enter only number: ");
                                sc.nextLine();
                            }
                            creditLimit = sc.nextDouble();
                            sc.nextLine();
                            System.out.print("Enter expiry date: ");
                            expiryDate = sc.nextLine();
                            C = new CreditCard(id, userId, supportedCurreincies, cardNumber, creditLimit, expiryDate);
                            daftarCreditcards.add(C);
                            break;
                        }
                        case 2:{
                            EWallet E;
                            String provider;
                            String phoneNumber;
                            double balance;
                            System.out.print("Enter Ewallet id: ");
                            id = sc.nextLine();
                            while (isIdExist(daftarEwallet, id)) {
                                System.out.print("Id already exists, enter another: ");
                                id = sc.nextLine();
                            }
                            System.out.print("Enter user id: ");
                            userId = sc.nextLine();
                            while (isIdExist(daftarEwallet, userId)) {
                                System.out.print("Id already exists, enter another: ");
                                userId = sc.nextLine();
                            }
                            System.out.print("Enter supported currencies: ");
                            supportedCurreincies = sc.nextLine();
                            System.out.print("Enter provider: ");
                            provider = sc.nextLine();
                            System.out.print("Enter phone number: ");
                            phoneNumber = sc.nextLine();
                            System.out.print("Enter balance: ");
                            while(!sc.hasNextInt()){
                                System.out.print("enter only number: ");
                                sc.nextLine();
                            }
                            balance = sc.nextDouble();
                            sc.nextLine();
                            E = new EWallet(id, userId, supportedCurreincies, provider, phoneNumber, balance);
                            daftarEwallet.add(E);
                            break;
                        }
                        case 3:{
                            BankTransfer B;
                            String bankName;
                            String accountHolderName;
                            String virtualAccountNumber;
                            System.out.print("Enter bank id: ");
                            id = sc.nextLine();
                            while (isIdExist(daftarBankTransfers, id)) {
                                System.out.print("Id already exists, enter another: ");
                                id = sc.nextLine();
                            }
                            System.out.print("Enter user id: ");
                            userId = sc.nextLine();
                            while (isIdExist(daftarBankTransfers, userId)) {
                                System.out.print("Id already exists, enter another: ");
                                userId = sc.nextLine();
                            }
                            System.out.print("Enter supported currencies: ");
                            supportedCurreincies = sc.nextLine();
                            System.out.print("Enter bank name: ");
                            bankName = sc.nextLine();
                            System.out.print("Enter account holder name: ");
                            accountHolderName = sc.nextLine();
                            System.out.print("Enter virtual account number: ");
                            virtualAccountNumber = sc.nextLine();
                            B = new BankTransfer(id, userId, supportedCurreincies, bankName, accountHolderName, virtualAccountNumber);
                            daftarBankTransfers.add(B);
                            break;
                        }
                        default: {
                            System.out.println("option invalid");
                            break;
                        }
                    }
                    break;
                }
                case 2:{
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
                            displayAll(daftarCreditcards);             
                            break;
                        }
                        case 2:{
                            System.out.println("Ewallet data: ");
                            displayAll(daftarEwallet);
                            break;
                        }
                        case 3:{
                            System.out.println("Bank transfer data: ");
                            displayAll(daftarBankTransfers);
                            break;
                        }
                        case 4:{
                            System.out.println("Credit card data: ");
                            displayAll(daftarCreditcards);             
                            System.out.println();
                            System.out.println("Ewallet data: ");
                            displayAll(daftarEwallet);
                            System.out.println();
                            System.out.println("Bank transfer data: ");
                            displayAll(daftarBankTransfers);
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
                case 3: {
                    System.out.println("Program finished.");
                    break;
                }
                
                default: {
                    System.out.println("option invalid");
                    break;
                }
            }
        }while(option != 3);
        sc.close();
    }
}
