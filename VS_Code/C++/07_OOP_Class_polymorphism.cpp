#include <iostream>
// using std::string;
using namespace std;

class AbstractEmployee{
    virtual void AskForPromotion()=0;
};

class Employee:AbstractEmployee
{
private:  //You cannot access outside the class
	
	string Company;
	int Age;

public:   //You can access outside the class
	//Setter
	void setName(string name) {
		Name = name;
	}
	void setCompany(string company) {
		Company = company;
	}
	void setAge(int age) {
        if (age>=18)
		Age = age;
	}
	//getter
	string getName() {
		return Name;
	}
	string getCompany() {
		return Company;
	}
	int getAge() {
		return Age;
	}
	//function for introducing class
	void IntruduceYOURSELF() {
		cout << "Name: " << Name << endl;
		cout << "Company: " << Company << endl;
		cout << "age: " << Age << endl;
	}

	//constructor for constructing objects of the class
	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}

    void AskForPromotion(){
        if (Age>30)
        std::cout << Name <<" Got promoted!" <<std::endl;
        else
        std::cout << Name <<" You are not eligible!"<<std::endl;
    }
    
    virtual void Work(){
        cout<<Name<<" is checking email, task backlog, performing tasks..."<<endl;
    }
protected:  // something between public and private
    string Name;
};

class Developer: public Employee{
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string favProgrammingLanguage):Employee(name,company,age) //Employee constructor will automatically assign these values
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }

    void FixBug(){
        cout<<Name<<" Fixed bug using "<<FavProgrammingLanguage<<endl; //We can now access Name directly as it is protected member of class Employee
    }

    void Work(){
        cout<<Name<<" is writing "<<FavProgrammingLanguage<<" code "<<endl;
    }
    
};

class Teacher:public Employee{
public:
    string Subject;
    void PrepareLesson (){
        cout << Name<< " is preparing " << Subject <<" lesson" <<endl;
    }

    Teacher(string name, string company, int age, string subject)
        :Employee(name,company,age) //Employee constructor will automatically assign these values
    {
        Subject = subject;
    }

    void Work(){
        cout<<Name<<" is teaching "<<Subject<<endl;
    }
};

int main()      //The most common use of Polymorphism is when a parent class reference is used to a child class object
{
    Developer d = Developer("Salahuddin", "OKY LTD", 26, "C++");
    Teacher t = Teacher("Salah", "KAIST", 35, "Maths");
    // d.Work();
    // t.Work();
    t.AskForPromotion(); //it is now available outside the class because the inheritance type is public now
    Employee* e1 = &d;
    Employee* e2 = &t;

    e1->Work();
    e2->Work();
   
    return 0;
}