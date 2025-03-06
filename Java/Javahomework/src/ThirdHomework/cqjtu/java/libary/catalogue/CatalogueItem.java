package ThirdHomework.cqjtu.java.libary.catalogue;

public class CatalogueItem {
    private String title;

    private int year;

    private int copies;

    public CatalogueItem() {
        this("Item");
    }

    public CatalogueItem(String title) {
        this.title = title;
        this.copies=0;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public int getCopies() {
        return copies;
    }

    public void setCopies(int copies) {
        this.copies = copies;
    }

    /**
     * Adds copies of a catalogue item
     * @param n number of copies of catalogue item to add
     */
    public void addCopies(int n) {
        // TODO: Implement
        if(n>0){
            this.copies+=n;
        }
    }

    /**
     * Adds a single copy of a catalogue item
     */
    public void addCopy() {
        // TODO: Implement
        addCopies(1);
    }

    /**
     * Checks whether there is at least one copy of the catalogue item available
     * @return True if a copy of the catalogue item is available and false otherwise
     */
    public boolean isAvailable() {
        // TODO: Implement
        if (this.getCopies()>=1){
            return true;
        }
        return false;
    }

}
