package ThirdHomework.chapter3;

import ThirdHomework.cqjtu.java.libary.Library;
import ThirdHomework.cqjtu.java.libary.Loan;
import ThirdHomework.cqjtu.java.libary.catalogue.Book;
import ThirdHomework.cqjtu.java.libary.Person;
import ThirdHomework.cqjtu.java.libary.catalogue.except.ItemNotFoundException;
import ThirdHomework.cqjtu.java.libary.catalogue.except.NoCopyAvailableException;
import ThirdHomework.io.FileReadWrite;
import org.junit.Test;

import java.io.IOException;

public class Chapter3 {
    @Test
public void app() throws IOException {
    Library centralLibrary = new Library("中心图书馆", 10);
    Book book1 = new Book("Clean Code", new Person("Robert", "Martin"), "9780136083238", 2008);
    book1.setCopies(25);
    centralLibrary.addItem(book1);

    // Update the file path to the correct location
    String bibex = FileReadWrite.readerFile("C:\\Users\\JackZhai\\IdeaProjects\\Javahomework\\src\\ThirdHomework\\resources\\Lee60.bib");
    Book book2 = Book.fromBibtex(bibex);
    book2.setCopies(30);
    centralLibrary.addItem(book2);

    centralLibrary.printCatalogue();

    Person user1 = new Person("chen", "he");
    try {
        Loan loan1 = centralLibrary.loanItem("9780136083238", user1);
        System.out.println(loan1);

        Loan loan2 = centralLibrary.loanItem("9780099549482", user1);
        System.out.println(loan2);
        centralLibrary.returnItem(loan2);
        centralLibrary.extendLoan(loan1, 10);
        System.out.println(loan1);
    } catch (ItemNotFoundException e) {
        e.printStackTrace();
    } catch (NoCopyAvailableException e) {
        e.printStackTrace();
    }
}
}