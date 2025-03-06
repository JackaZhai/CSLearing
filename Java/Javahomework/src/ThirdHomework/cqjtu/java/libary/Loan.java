package ThirdHomework.cqjtu.java.libary;

import ThirdHomework.cqjtu.java.libary.catalogue.CatalogueItem;
import ThirdHomework.cqjtu.java.libary.catalogue.except.ItemAlreadyReturnedException;

import java.sql.SQLOutput;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Calendar;
import java.util.Date;
import java.util.SimpleTimeZone;

public class Loan {
    
    private CatalogueItem item;
    private Person user;
    private Date loanDate;
    private Date dueDate;
    private Date returnedDate;
    private SimpleDateFormat df=new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");

    /**
     * Constructor that takes as parameters the item being loaned,
     * the user borrowing the item, and the loan length.
     * Sets the loan date and time to
     * the current date using {@link LocalDateTime#now()},
     * the due date to the current date plus loan length
     * and the returned date to null.
     * 
     * @param item CatalogueItem being loaned
     * @param user Person loaning item
     * @param loanLength Number of days the loan is valid for
     */
    public Loan(CatalogueItem item, Person user, int loanLength) {
        // TODO: Implement
        this.item = item;
        this.user = user;
        Calendar calendar=Calendar.getInstance();
        this.loanDate=calendar.getTime();
        calendar.add(Calendar.DAY_OF_MONTH,loanLength);
        this.dueDate=calendar.getTime();
    }

    public CatalogueItem getItem() {
        // TODO: Implement
        return this.item;
    }

    public Person getUser() {
        // TODO: Implement
        return this.user;
    }

    public Date getLoanDate() {
        // TODO: Implement
        return this.loanDate;
    }

    public Date getReturnedDate() {
        // TODO: Implement
        return this.returnedDate;
    }

    public Date getDueDate() {
        // TODO: Implement
        return this.dueDate;
    }

    /**
     * Prints loan receipt in the following format:
     * <Loan date in format dd-MM-yyyy HH-mm-ss>
     * <User name> has borrowed <Book title>
     * Date due: <Date item is due to be returned>
     * Returned: <Returned date and time in format dd-MM-yyyy HH-mm-ss if already returned; otherwise "n/a">
     * Thank you!
     */
    public void printReceipt() {
        // TODO: Implement

    }

    /**
     * Updates field {@link Loan#returnedDate} with current date and time
     * @throws ItemAlreadyReturnedException if the item was already returned
     */
    public void returnItem() throws ItemAlreadyReturnedException {
        // TODO: Implement
        if(this.returnedDate!=null){
            throw new ItemAlreadyReturnedException("图书已经归还");
        }
        this.returnedDate=Calendar.getInstance().getTime();
    }

    /**
     * Extends the loan term by adding the given amount of days to field {@link Loan#dueDate}
     * @throws ItemAlreadyReturnedException if the item was already returned
     */
    public void extendLoan(int days) throws ItemAlreadyReturnedException {
        // TODO: Implement
        if(this.returnedDate!=null){
            throw new ItemAlreadyReturnedException("图书已经归还");
        }
        Calendar calendar=Calendar.getInstance();
        calendar.setTime(this.dueDate);
        calendar.add(Calendar.DAY_OF_MONTH,days);
        this.dueDate=calendar.getTime();
    }

    /**
     * Returns a string representation of a Loan
     *
     * @return A string representation of a loan in
     * the format "Loan: User=<User name>; Item=<Book title>; Type=<"Book" or "Magazine">; Due=<Due date dd-MM-yyyy>"
     */
    @Override
    public String toString() {
        // TODO: Implement
        String info="loan:user=<"+this.user.toString()+">;"+"Item=<"+this.item.getTitle()+">;"+"Type=<Book or Magazine >"+"Due=<"+df.format(this.dueDate)+">";
        return info;
    }
}