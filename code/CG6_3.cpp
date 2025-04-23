#include <iostream> 
#include <string> 
using namespace std; 
class Person 
{ 
public:
Person(string name1="", char s='M')
{ 
    name=name1; 
    sex=s; 
} 
virtual void ShowMe(); 
friend istream& operator>>(istream & in, Person &p); 
protected: 
       char sex; 
       string name; 
}; 

void Person::ShowMe() 
{ 
    cout << "姓名:" << name << endl;
    cout << "性别:" << sex << endl;
} 
 
istream& operator>>(istream & in, Person &p)
{
    in >> p.name >> p.sex;
    return in;
}

class Staff: virtual public Person 
{ 
protected: 
       int wID; //工作号 
public: 
       Staff(int id=0,string name1="", char s='M'):Person(name1,s) 
       {wID=id;} 
virtual  void ShowMe(); 
friend istream& operator>>(istream & in, Staff &p); 
}; 

void Staff::ShowMe() 
{ 
    Person::ShowMe();
    cout << "工号:" << wID << endl;
} 

istream& operator>>(istream & in, Staff &p)
{
    in >> (Person&)p >> p.wID;
    return in;
}

class Student: virtual public Person
{ 
protected: 
       int sID; //学号 
public: 
       Student(int id=0,string name1="", char s='M'):Person(name1,s) 
       {sID=id;} 
  virtual void ShowMe(); 
  friend istream& operator>>(istream & in,Student &p); 
}; 

void Student::ShowMe() 
{ 
    Person::ShowMe();
    cout << "学号:" << sID << endl;
} 

istream& operator>>(istream & in, Student &p)
{
    in >> (Person&)p >> p.sID;
    return in;
}

class Staff_Student: public Student, public Staff
{ 
public: 
       Staff_Student(string name1="", char s='M',int id1=0,int id2=0):Person(name1,s),Student(id1,name1,s),Staff(id2,name1,s) 
       {  }; 
    virtual void ShowMe(); 
    friend istream& operator>>(istream & in,Staff_Student &p); 
}; 

void Staff_Student::ShowMe() 
{ 
    Person::ShowMe();
    cout << "学号:" << sID << endl;
    cout << "工号:" << wID << endl;
} 

istream& operator>>(istream & in, Staff_Student &p)
{
    in >> p.name >> p.sex >> p.sID >> p.wID;
    return in;
}

class School 
{
private: 
  Person *p[100]; 
  int size; 
public: 
       School(); 
       ~School()
       { 
       } 
void append(Person &); 
void display(); 
}; 

School::School() 
{
    size=0; 
} 

void School::append(Person& p1) 
{ 
    p[size] = &p1;
    size++;
} 

void School::display() 
{ 
    int i; 
    for(i=0;i<size;i++) 
      p[i]->ShowMe(); 
} 

int main() 
{ 
School sch; 
Staff s1; 
cin>>s1; 
sch.append(s1); 
Student st1; 
cin>>st1; 
sch.append(st1); 
Staff_Student ss1("SS1",'F',1001,1003); 
cin>>ss1; 
sch.append(ss1); 
sch.display(); 
return 0;
}
