package ThirdHomework.cqjtu.java.libary;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Date;

import ThirdHomework.cqjtu.java.libary.catalogue.Book;
import ThirdHomework.cqjtu.java.libary.catalogue.CatalogueItem;
import ThirdHomework.cqjtu.java.libary.catalogue.except.ItemAlreadyReturnedException;
import ThirdHomework.cqjtu.java.libary.catalogue.except.ItemNotFoundException;
import ThirdHomework.cqjtu.java.libary.catalogue.except.NoCopyAvailableException;

public class Library {
    /**
     * Use this constant to initialise the catalogue
     */
    private final int CATALOGUE_CAPACITY = 100;
    private String name;
    private CatalogueItem[] catalogue = new CatalogueItem[CATALOGUE_CAPACITY];
    private Loan[] loans =new Loan[100];
    private int loanLength;

    /**
     * Constructor that initialises the library name to "Library"
     * and the loan length to 10 days
     */
    public Library() {
        // TODO: Implement
        this.name ="Library";
        this.loanLength=10;
    }

    /**
     * Constructor that takes a library name as parameter and
     * initialises the loan length to 10 days
     * @param name The name of the library
     */
    public Library(String name) {
        // TODO: Implement
        this.name=name;
        this.loanLength=10;
    }

    /**
     * Constructor that takes a library name and the loan length
     * as parameters
     * @param name The name of the library
     * @param loanLength The number of days books should be loaned for
     */
    public Library(String name, int loanLength) {
        // TODO: Implement
        this.name = name;
        this.loanLength = loanLength;
    }

    /**
     * Returns a simple welcome message
     * @return "Welcome to <library name>"
     */
    public String welcome() {
        // TODO: Implement
        return "welcome to <"+this.name+">";
    }

    /**
     * Returns the library name
     * @return Library name
     */
    public String getName() {
        // TODO: Implement
        return this.name;
    }

    /**
     * Add the given book to the catalogue.
     *
     * @param newItem Item to be added to catalogue
     * @return Returns true if there is space in the catalogue and new item is successfully added; false otherwise
     */
    public boolean addItem(CatalogueItem newItem) {
        // TODO: Implement
        for(int i=0;i<catalogue.length;i++){
            if(catalogue[i]==null){
                catalogue[i]=newItem;
                return true;
            }
        }
        return false;
    }

    /**
     * Finds item with given title or ISBN and removes a copy from the catalogue.
     * Assumes there are no duplicated title or ISBN.
     * @param titleOrISBN Exact title or ISBN of the item to be removed.
     */
    public void removeItem(String titleOrISBN) {
        // TODO: Implement
        CatalogueItem item=findItem(titleOrISBN);
        if(item!=null){
            Arrays.stream(catalogue).forEach(e->{
                if(e==item){
                    e.setCopies(e.getCopies()-1);
                }
            });
        }
    }

    /**
     * Find item with given title or ISBN and remove a given number of copies from the catalogue.
     * Assumes there are no duplicated title or ISBN.
     * @param titleOrISBN Exact title or ISBN of the item to be removed
     * @param n Number of copies to remove
     */
    public void removeItem(String titleOrISBN, int n) {
        // TODO: Implement
        CatalogueItem item=findItem(titleOrISBN);
        Arrays.stream(catalogue).forEach(e->{
            if(e==item){
                if(n>e.getCopies()){
                    e=null;
                }
                else {
                    e.setCopies(e.getCopies()-n);
                }
            }
        });

    }

    /**
     * Registers the loan of a book given its exact title or ISBN.
     * 
     * @param titleOrISBN The title or ISBN of the book to be loaned
     * @param user Name of user loaning catalogue item
     * @return true if the item's title or ISBN exist in the catalogue and there is a copy available; false otherwise
     * @throws ItemNotFoundException if a book with the given title does not exist in the catalogue
     * @throws NoCopyAvailableException if there are no copies available of the given book
     */
    public Loan loanItem(String titleOrISBN, Person user) throws ItemNotFoundException, NoCopyAvailableException {
        // TODO: Implement
        CatalogueItem catalogueItem = findItem(titleOrISBN);
        if(catalogueItem==null){
            throw new ItemNotFoundException("在目录中没有这本书");
        }else {
            if(!catalogueItem.isAvailable()){
                throw new NoCopyAvailableException("该本书的副本全部借出!");
            }
        }
        Loan loan= new Loan(catalogueItem,user,this.loanLength);

        return loan;
    }

    /**
     * Find an item in the catalogue given a title or ISBN.
     * 
     * @param titleOrISBN Title or ISBN of item to find
     * @return The catalogue item found or null otherwise
     */
    private CatalogueItem findItem(String titleOrISBN) {
        // TODO: Implement
        for (CatalogueItem catalogueItem : catalogue) {
            if (catalogueItem !=null){
                boolean t=catalogueItem.getTitle().equals(titleOrISBN);
                Book b=(Book) catalogueItem;
                boolean t1=b.getIsbn().equals(titleOrISBN);
                if(t||t1){
                    return catalogueItem;
                }
            }
        }
        return null;
    }

    /**
     * Mark the item in a Returns a given loan
     */
    public void returnItem(Loan loan) {
        // TODO: Implement
        if (loan != null) {
            try {
                loan.returnItem();
            } catch (ItemAlreadyReturnedException e) {
                e.printStackTrace();
            }
        }
    }
    /**
     * Extends the given loan
     * @return
     */
    public void extendLoan(Loan loan, int days) {
        // TODO: Implement
        if(loan!=null) {
            try {
                loan.extendLoan(days);
            } catch (ItemAlreadyReturnedException e) {
                e.printStackTrace();
            }
        }
    }

    /**
     * Return the number of copies available for a given catalogue item
     * @param item the item
     * @return number of copies available for the given item
     */
    public int copiesAvailable(CatalogueItem item) {
         //TODO: Implement
        return -1;
    }

    /**
     * Returns the current list of books in the catalogue excluding nulls
     *
     * @return Array of books contained in the catalogue (excluding nulls)
     */
    public CatalogueItem[] getCatalogue(){
         //TODO: Implement
        return null;
    }

    /**
     * Print the full catalogue in the following format (sorted by title)
     * ====================
     * <Output of call to {@link Library#welcome()}>
     * Catalogue
     * ====================
     * <Output of call to method toString in the item>
     * ====================
     */
    public void printCatalogue() {
        // TODO: Implement
        System.out.println("====================");
        System.out.println(this.welcome());
        System.out.println("====================");
        Arrays.sort(this.catalogue, new Comparator<CatalogueItem>() {
            @Override
            public int compare(CatalogueItem o1, CatalogueItem o2) {
                if(o1 != null && o2 != null) {
                    String t1 = o1.getTitle();
                    String t2 = o2.getTitle();
                    return t1.compareTo(t2);
                }
                return 0;

            }
        });
        for(CatalogueItem catalogueItem : catalogue) {
            if (catalogueItem != null) {
                System.out.println(catalogueItem);
            }
        }
        System.out.println("====================");
    }


    /**
     * Print the list of loans that are overdue (i.e., due date has passed),
     * sorted by the number of days they are overdue by, and in the following
     * format:
     * ====================
     * Loans Overdue
     * ====================
     * <Output of call to {@link Loan#toString()}; one overdue loan>
     * ====================
     */
    public void printOverdue() {
            // TODO: Implement
            System.out.println("====================");
            System.out.println("Loans Overdue");
            System.out.println("====================");
            Arrays.sort(this.loans, new Comparator<Loan>() {
                @Override
                public int compare(Loan o1, Loan o2) {
                    if (o1 != null && o2 != null) {
                        Date t1 = o1.getDueDate();
                        Date t2 = o2.getDueDate();
                        if (t1.after(t2)) {
                            return 1;
                        }
                    }
                    return 0;
                }
            });
            for (Loan l : this.loans) {
                if (l != null) {
                    if (l.getDueDate().before(new Date())) {
                        System.out.println(l);
                    }
                }
            }
    }}



