package ThirdHomework.cqjtu.java.libary;

import java.text.ParseException;
import java.util.Objects;

public class Person {
    String firstName;
    String lastName;

    public Person(String firstName, String lastName) {
        // TODO: Implement
        this.firstName = firstName ;
        this.lastName = lastName ;
    }

    /**
     * Returns a string representation of a person
     *
     * @return A string representation of a person in
     * the format "<last name>, <first name>"
     */
    @Override
    public String toString() {
        // TODO: Implement
        return "<"+this.lastName +">,<"  +this.firstName+">";
    }

    @Override
    public boolean equals(Object o) {
        // TODO: Implement
        if (this == o) return true;
        if (!(o instanceof Person)) return false;
        Person person = (Person) o;
        return Objects.equals(firstName, person.firstName) &&
                Objects.equals(lastName, person.lastName);
    }

    @Override
    public int hashCode() {
        // TODO: Implement
        return Objects.hash(firstName, lastName);
    }
}
