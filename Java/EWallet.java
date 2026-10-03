public class EWallet extends PaymentMethod {
    private String provider;
    private String phoneNumber;
    private double balance = 0.0;

    public EWallet() {

    }

    /**
     * Membuat e-wallet.
     * Waktu: O(L), memori: O(L), L = panjang string.
     */
    public EWallet(String id, String userID, String supportedCurrencies,
                   String provider, String phoneNumber, double balance) {
        super(id, userID, supportedCurrencies);
        setProvider(provider);
        setPhoneNumber(phoneNumber);
        setBalance(balance);
    }

    /** Waktu: O(1), memori: O(1). */
    public String getProvider() {
        return this.provider;
    }

    /** Waktu: O(1), memori: O(1). */
    public String getPhoneNumber() {
        return this.phoneNumber;
    }

    /** Waktu: O(1), memori: O(1). */
    public double getBalance() {
        return this.balance;
    }

    /** Waktu: O(1), memori: O(1). */
    public void setProvider(String provider) {
        this.provider = provider;
    }

    /** Waktu: O(1), memori: O(1). */
    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    /** Waktu: O(1), memori: O(1). */
    public void setBalance(double balance) {
        this.balance = balance;
    }

    /** Waktu: O(L), memori: O(1). */
    @Override
    public void display() {
        super.display();
        System.out.println("Provider: " + this.provider);
        System.out.println("Phone Number: " + this.phoneNumber);
        System.out.println("Balance: " + this.balance);
    }
}