public class BankTransfer extends PaymentMethod {
    private String bankName;
    private String accountHolderName;
    private String virtualAccountNumber;

    public BankTransfer() {

    }

    /**
     * Membuat metode transfer bank.
     * Waktu: O(L), memori: O(L), L = panjang string.
     */
    public BankTransfer(String id, String userID, String supportedCurrencies,
                        String bankName, String accountHolderName,
                        String virtualAccountNumber) {
        super(id, userID, supportedCurrencies);
        this.bankName = bankName;
        this.accountHolderName = accountHolderName;
        this.virtualAccountNumber = virtualAccountNumber;
    }

    /** Waktu: O(1), memori: O(1). */
    public String getBankName() {
        return this.bankName;
    }

    /** Waktu: O(1), memori: O(1). */
    public String getAccountHolderName() {
        return this.accountHolderName;
    }

    /** Waktu: O(1), memori: O(1). */
    public String getVirtualAccountNumber() {
        return this.virtualAccountNumber;
    }

    /** Waktu: O(1), memori: O(1). */
    public void setBankName(String bankName) {
        this.bankName = bankName;
    }

    /** Waktu: O(1), memori: O(1). */
    public void setAccountHolderName(String accountHolderName) {
        this.accountHolderName = accountHolderName;
    }

    /** Waktu: O(1), memori: O(1). */
    public void setVirtualAccountNumber(String virtualAccountNumber) {
        this.virtualAccountNumber = virtualAccountNumber;
    }

    /** Waktu: O(L), memori: O(1). */
    @Override
    public void display() {
        super.display();
        System.out.println("Bank Name: " + this.bankName);
        System.out.println("Account Holder Name: " + this.accountHolderName);
        System.out.println("Virtual Account Number: " + this.virtualAccountNumber);
    }
}