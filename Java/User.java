public class User {
    private String name;
    private String address;
    private String email;

    // Composition: ketiga objek dibuat oleh User sendiri di konstruktor,
    // sehingga tidak ada tanpa User.
    private CreditCard creditCard;
    private EWallet eWallet;
    private BankTransfer bankTransfer;

    public User() {
        this.creditCard = new CreditCard();
        this.eWallet = new EWallet();
        this.bankTransfer = new BankTransfer();
    }

    /**
     * Membuat user beserta metode pembayarannya yang masih kosong.
     * Waktu: O(L), memori: O(L), L = panjang string.
     */
    public User(String name, String address, String email) {
        this.name = name;
        this.address = address;
        this.email = email;
        this.creditCard = new CreditCard();
        this.eWallet = new EWallet();
        this.bankTransfer = new BankTransfer();
    }

    /** Waktu: O(1), memori: O(1). */
    public String getName() {
        return this.name;
    }

    /** Waktu: O(1), memori: O(1). */
    public String getAddress() {
        return this.address;
    }

    /** Waktu: O(1), memori: O(1). */
    public String getEmail() {
        return this.email;
    }

    /** Waktu: O(1), memori: O(1). */
    public CreditCard getCreditCard() {
        return this.creditCard;
    }

    /** Waktu: O(1), memori: O(1). */
    public EWallet getEWallet() {
        return this.eWallet;
    }

    /** Waktu: O(1), memori: O(1). */
    public BankTransfer getBankTransfer() {
        return this.bankTransfer;
    }

    /** Waktu: O(1), memori: O(1). */
    public void setName(String name) {
        this.name = name;
    }

    /** Waktu: O(1), memori: O(1). */
    public void setAddress(String address) {
        this.address = address;
    }

    /** Waktu: O(1), memori: O(1). */
    public void setEmail(String email) {
        this.email = email;
    }

    /** Waktu: O(L), memori: O(1). */
    public void display() {
        System.out.println("Name: " + this.name);
        System.out.println("Address: " + this.address);
        System.out.println("Email: " + this.email);
        System.out.println();
        this.creditCard.display();
        System.out.println();
        this.eWallet.display();
        System.out.println();
        this.bankTransfer.display();
    }
}