#include <iostream>
#include <string>
using namespace std; 

class Person {
private:
    string name;
    int age;
    string gender;
    static int counter;  

public:
    Person(string& name, int age, string& gender)
        : name(name), age(age), gender(gender) {
        cout << "Person构造函数被调用" << endl;
        counter++; 
    }

    string getName() { return name; }
    int getAge() { return age; }
    string getGender() { return gender; }

    virtual void display() {
        cout << "姓名: " << name << ", 年龄: " << age << ", 性别: " << gender << endl;
    }

    virtual ~Person() = default;
    
    static int getCounter() { return counter; }
};

// 初始化静态成员变量
int Person::counter = 0;

// Employee类，虚继承自Person
class Employee : virtual public Person {
private:
    string employeeId;
    string department;
    double salary;

public:
    Employee(string& name, int age, string& gender,
             string& employeeId, string& department, double salary)
        : Person(name, age, gender), employeeId(employeeId), department(department), salary(salary) {
        cout << "员工构造函数被调用" << endl;

    }

    string getEmployeeId() { return employeeId; }
    string getDepartment() { return department; }
    double getSalary() { return salary; }

    void display() override {
        Person::display();
        cout << "工号: " << employeeId 
                  << ", 部门: " << department 
                  << ", 薪资: " << salary << endl;
    }
};

// Postgraduate类，虚继承自Person
class Postgraduate : virtual public Person {
private:
    string studentId;
    string major;
    string tutor;

public:
    Postgraduate(string& name, int age, string& gender,
                 string& studentId, string& major, string& tutor)
        : Person(name, age, gender), studentId(studentId), major(major), tutor(tutor) {
        cout << "研究生构造函数被调用" << endl;
    }

    string getStudentId() { return studentId; }
    string getMajor() { return major; }
    string getTutor() { return tutor; }

    void display() override {
        Person::display();
        cout << "学号: " << studentId 
                  << ", 专业: " << major 
                  << ", 导师: " << tutor << endl;
    }
};

// OnJobPostgraduate类，同时继承Employee和Postgraduate
class OnJobPostgraduate : public Employee, public Postgraduate {
private:
    int workYears;

public:
    OnJobPostgraduate(string& name, int age, string& gender,
                      string& employeeId, string& department, double salary,
                      string& studentId, string& major, string& tutor,
                      int workYears)
        : Person(name, age, gender),  // 只需调用一次Person构造函数
          Employee(name, age, gender, employeeId, department, salary),
          Postgraduate(name, age, gender, studentId, major, tutor),
          workYears(workYears) {
        cout << "在职研究生构造函数被调用" << endl;
    }

    int getWorkYears() { return workYears; }

    void display() override {
        // 直接调用Person类的display，避免重复调用
        Person::display();
        cout << "工号: " << getEmployeeId() 
                  << ", 部门: " << getDepartment() 
                  << ", 薪资: " << getSalary() << endl;
        cout << "学号: " << getStudentId() 
                  << ", 专业: " << getMajor() 
                  << ", 导师: " << getTutor() << endl;
        cout << "工作年限: " << workYears << endl;
        
    }
};

// 验证虚基类解决菱形继承问题的类
class NonVirtualBase {
public:
    int x;
    NonVirtualBase(int x) : x(x) {
        cout << "普通基类构造函数被调用，x = " << x << endl;
    }
};

class DerivedA : public NonVirtualBase {
public:
    DerivedA(int x) : NonVirtualBase(x) {
        cout << "派生类A构造函数被调用" << endl;
    }
};

class DerivedB : public NonVirtualBase {
public:
    DerivedB(int x) : NonVirtualBase(x) {
        cout << "派生类B构造函数被调用" << endl;
    }
};

class Problem : public DerivedA, public DerivedB {
public:
    Problem(int a, int b) : DerivedA(a), DerivedB(b) {
        cout << "构造函数被调用" << endl;
    }
    
    // 需要明确指定使用哪个基类的x
    void printX() {
        cout << "DerivedA::x = " << DerivedA::x << endl;
        cout << "DerivedB::x = " << DerivedB::x << endl;
        // 直接访问x会产生歧义
        // cout << "x = " << x << endl; // 编译错误
    }
};

// 虚继承解决方案
class VirtualBase {
public:
    int x;
    VirtualBase(int x) : x(x) {
        cout << "虚基类构造函数被调用，x = " << x << endl;
    }
};

class VDerivedA : virtual public VirtualBase {
public:
    VDerivedA(int x) : VirtualBase(x) {
        cout << "虚派生类A构造函数被调用" << endl;
    }
};

class VDerivedB : virtual public VirtualBase {
public:
    VDerivedB(int x) : VirtualBase(x) {
        cout << "虚派生类B构造函数被调用" << endl;
    }
};

class VDiamondSolution : public VDerivedA, public VDerivedB {
public:
    VDiamondSolution(int x) : VirtualBase(x), VDerivedA(x), VDerivedB(x) {
        cout << "虚菱形解决方案类构造函数被调用" << endl;
    }
    
    // 可以直接访问x，因为只有一个VirtualBase实例
    void printX() {
        cout << "x = " << x << endl;
        
        // 这里可以直接访问x是因为通过虚继承只有一个VirtualBase实例
        // 所以不会产生二义性问题
    }
};


int main() {
    string name = "张三";
    int age = 28;
    string gender = "男";
    string empId = "E10086";
    string dept = "研发部";
    double salary = 15000.0;
    string stuId = "S20230001";
    string major = "计算机科学";
    string tutor = "李教授";
    int workYears = 5;
    
    cout << "创建在职研究生" << endl;
    OnJobPostgraduate ojp(name, age, gender, 
                          empId, dept, salary,
                          stuId, major, tutor, 
                          workYears);
        
    cout << "\n在职研究生信息" << endl;
    ojp.display();
    
    cout << "\n测试虚继承" << endl;

    cout << "\n不使用虚继承的情况：" << endl;
    Problem dp(10, 20);
    dp.printX();
    
    cout << "\n使用虚继承的情况：" << endl;
    VDiamondSolution vds(30);
    vds.printX();
    
    cout << "\n创建的Person对象数量: " << Person::getCounter() << endl;
    
    return 0;
}