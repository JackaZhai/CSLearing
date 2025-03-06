package FirstHomework;

import org.junit.Test;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

import static org.junit.Assert.assertEquals;

public class MyCalendarTest {

    @Test
    public void testGetDaysInMonth() {
        MyCalendar myCalendar = new MyCalendar(2024, 10);
        assertEquals(31, myCalendar.getDaysInMonth());
    }

    @Test
    public void testGetDayOfWeek() {
        MyCalendar myCalendar = new MyCalendar(2024, 10);
        assertEquals("二", myCalendar.getDayOfWeek(1));
    }

    @Test
    public void testToString() {
        MyCalendar myCalendar = new MyCalendar(2024, 10);
        String expectedOutput = "---------2024年10月----------\n" +
                                "一\t二\t三\t四\t五\t六\t日\n" +
                                "\t1\t2\t3\t4\t5\t6\t\n" +
                                "7\t8\t9\t10\t11\t12\t13\t\n" +
                                "14\t15\t16\t17\t18\t19\t20\t\n" +
                                "21\t22\t23\t24\t25\t26\t27\t\n" +
                                "28\t29\t30\t31\t\n";

        // 捕获 System.out 的输出
        ByteArrayOutputStream outContent = new ByteArrayOutputStream();
        System.setOut(new PrintStream(outContent));

        // 调用 toString 方法
        myCalendar.toString();

        // 恢复 System.out
        System.setOut(System.out);

        // 获取输出并进行比较
        assertEquals(expectedOutput, outContent.toString());
    }
}