public class CreditCard extends PaymentMethod {
    private String cardNumber;
    private double creditLimit = 0.0;
    private String expiryDate;

    public CreditCard() {

    }

    /**
     * Membuat kartu kredit.
     * Waktu: O(L), memori: O(L), L = panjang string.
     */
    public CreditCard(String id, String userID, String supportedCurrencies,
                      String cardNumber, double creditLimit, String expiryDate) {
        super(id, userID, supportedCurrencies);
        this.cardNumber = cardNumber;
        this.creditLimit = creditLimit;
        this.expiryDate = expiryDate;
    }

    /** Waktu: O(1), memori: O(1). */
    public String getCardNumber() {
        return this.cardNumber;
    }

    /** Waktu: O(1), memori: O(1). */
    public double getCreditLimit() {
        return this.creditLimit;
    }

    /** Waktu: O(1), memori: O(1). */
    public String getExpiryDate() {
        return this.expiryDate;
    }

    /** Waktu: O(1), memori: O(1). */
    public void setCardNumber(String cardNumber) {
        this.cardNumber = cardNumber;
    }

    /** Waktu: O(1), memori: O(1). */
    public void setCreditLimit(double creditLimit) {
        this.creditLimit = creditLimit;
    }

    /** Waktu: O(1), memori: O(1). */
    public void setExpiryDate(String expiryDate) {
        this.expiryDate = expiryDate;
    }

    /** Waktu: O(L), memori: O(1). */
    @Override
    public void display() {
        super.display();
        System.out.println("Card Number: " + this.cardNumber);
        System.out.println("Credit Limit: " + this.creditLimit);
        System.out.println("Expiry Date: " + this.expiryDate);
    }
}