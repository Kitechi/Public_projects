#include <iostream>
using std::string;

class Employee
{
public:   //You can access outside
	string Name;
	string Company;
	int Age;

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
private:  //You cannot access outside
protected:  // something between public and private
};

int main()
{
	/*Employee employee1;   // When you creat your own constructor you loss the default constructor
	employee1.Name = "Salahuddin";
	employee1.Company = "KAIST";
	employee1.Age = 26;
	employee1.IntruduceYOURSELF();

	Employee employee2;
	employee2.Name = "Hareera";
	employee2.Company = "KAIST";
	employee2.Age = 02;
	employee2.IntruduceYOURSELF();*/

	Employee employee1 = Employee("Salahuddin", "KAIST", 26);
	employee1.IntruduceYOURSELF();

	Employee employee2 = Employee("Hareera", "KAIST", 02);
	employee2.IntruduceYOURSELF();

}