#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;

class Employee {
private:
    int id;            
    string name;      
    string department; 
    double money;     
    
public:
    
    Employee() {}
    
    
    int getId() const { return id; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
    double getmoney() const { return money; }
    
    void setId(int i) { id = i; }
    void setName(string n) { name = n; }
    void setDepartment(string d) { department = d; }
    void setmoney(double s) { money = s; }
    
    friend istream& operator>>(istream& is, Employee& emp) {
        is >> emp.id >> emp.name >> emp.department >> emp.money;
        
        // 吃掉换行符
        if (is.peek() == '\n') {
            is.get();  
        }
        
        return is;
    }
    
    friend ostream& operator<<(ostream& os, const Employee& emp) {
        os << "工号: " << emp.id << ", 姓名: " << emp.name 
           << ", 部门: " << emp.department << ", 工资: " << emp.money;
        return os;
    }
};

class MyCompare {
    public:
        bool operator()(const Employee& e1, const Employee& e2) const {
            if (e1.getmoney() != e2.getmoney()) {
                return e1.getmoney() > e2.getmoney(); 
            }
            return e1.getId() < e2.getId(); 
        }
    };


    void print(set<Employee, MyCompare>& obj) {
        for (set<Employee, MyCompare>::iterator it = obj.begin(); it != obj.end(); ++it) {
            cout << *it << endl;
        }
    }

int main() {
    set<Employee, MyCompare> employees;
    
    cout << "请输入5位员工信息（工号 姓名 部门 工资）：" << endl;
    for (int i = 0; i < 5; i++) {
        Employee emp;
        cin >> emp;
        employees.insert(emp);
    }
    
    cout << "按排序规则输出员工信息：" << endl;
    print(employees);
    
    return 0;
}
