public class PaymentMethod {
    private String id;
    private String userID;
    private String supportedCurrencies;

    public PaymentMethod() {

    }

    /**
     * Membuat metode pembayaran.
     * Waktu: O(L), memori: O(L), L = panjang string.
     */
    public PaymentMethod(String id, String userID, String supportedCurrencies) {
        this.id = id;
        this.userID = userID;
        this.supportedCurrencies = supportedCurrencies;
    }

    /** Waktu: O(1), memori: O(1). */
    public String getId() {
        return this.id;
    }

    /** Waktu: O(1), memori: O(1). */
    public String getUserId() {
        return this.userID;
    }

    /** Waktu: O(1), memori: O(1). */
    public String getSupportedCurrencies() {
        return this.supportedCurrencies;
    }

    /** Waktu: O(1), memori: O(1). */
    public void setId(String id) {
        this.id = id;
    }

    /** Waktu: O(1), memori: O(1). */
    public void setUserId(String userID) {
        this.userID = userID;
    }

    /** Waktu: O(1), memori: O(1). */
    public void setSupportedCurrencies(String supportedCurrencies) {
        this.supportedCurrencies = supportedCurrencies;
    }

    /**
     * Menampilkan data umum metode pembayaran.
     * Waktu: O(L), memori: O(1).
     */
    public void display() {
        System.out.println("ID: " + this.id);
        System.out.println("User ID: " + this.userID);
        System.out.println("Supported Currencies: " + this.supportedCurrencies);
    }
}