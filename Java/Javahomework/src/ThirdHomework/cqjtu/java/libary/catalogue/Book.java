package ThirdHomework.cqjtu.java.libary.catalogue;

import ThirdHomework.cqjtu.java.libary.Person;

public class Book extends CatalogueItem {

    private Person author;
    private String isbn;

    public Book(String title) {
        super(title);
    }

    public Book(String title, Person author) {
        this(title);
        this.author = author;
    }

    public Book(String title, Person author, String isbn) {
        this(title, author);
        this.isbn = isbn;
    }

    public Book(String title, Person author, String isbn, int year) {
        this(title, author, isbn);
        this.setYear(year);
    }

    public Person getAuthor() {
        return author;
    }

    public void setAuthor(Person author) {
        this.author = author;
    }

    public String getIsbn() {
        return isbn;
    }

    @Override
    public boolean equals(Object other) {
        if (other != null && other instanceof Book) {
            Book b = (Book) other;
            String bTitle = b.getTitle();
            String aTitle = this.getTitle();
            return bTitle.startsWith(aTitle) || aTitle.startsWith(bTitle);
        }
        return false;
    }

    public static Book fromBibtex(String bibtex) throws IllegalArgumentException {
    int k = bibtex.indexOf(",");
    bibtex = bibtex.substring(k + 1, bibtex.length() - 1);
    bibtex = bibtex.replace("\n", "");
    String[] info = bibtex.split(",");
    String title = info[0].split("=")[1].trim().replace("\"", "");
    String n = info[1].split("=")[1].trim().replace("\"", "");
    String[] name = n.split(" ");
    Person author = new Person(name[0], name[1]);
    String isbn = info[2].split("=")[1].trim().replace("\"", "");
    String year = info[3].split("=")[1].trim().replace("\"", "").replace("{", "").replace("}", "");
    return new Book(title, author, isbn, Integer.parseInt(year));
}

    @Override
    public String toString() {
        return "Book: Author=<" + this.author.toString() + ">; ISBN=<" + this.isbn + ">; Title=<" + this.getTitle() + ">";
    }

    @Override
    public int hashCode() {
        return super.hashCode();
    }
}