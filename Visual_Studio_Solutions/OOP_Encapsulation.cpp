#include <iostream>
using std::string;

class Employee
{
private:  //You cannot access outside the class
	string Name;
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
		std::cout << "Name: " << Name << std::endl;
		std::cout << "Company: " << Company << std::endl;
		std::cout << "age: " << Age << std::endl;
	}

	//constructor for constructing objects of the class
	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}

protected:  // something between public and private
};

void main2()
{
	Employee employee1 = Employee("Salahuddin", "KAIST", 26);
	employee1.IntruduceYOURSELF();

	Employee employee2 = Employee("Hareera", "KAIST", 02);
	employee2.IntruduceYOURSELF();

	employee1.setAge(39);
	std::cout << employee1.getName() << " is " << employee1.getAge() << " years old." << std::endl;
}