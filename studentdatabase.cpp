#include <iostream>
#include <string>
using namespace std;
class student
{
public:
	string Name;
	int Roll_number;
	string standard;
	string division;
	long int Telephone_number;
	string Date_of_birth;
	string Blood_group;
	string Contact_address;
	int Driving_licence;
	static int count; //STATIC VARIABLE
	friend class Friend;
	student()
	{ //Default constructure
		Name = ' ';
		Roll_number = 0;
		standard = ' ';
		division = ' ';
		Telephone_number = 0;
		Date_of_birth = ' ';
		Blood_group = " ";
		Contact_address = " ";
		Driving_licence = 0;
		count++;
	}
	void read() //read function
	{
		cout << "Enter name of student : ";
		cin >> Name;
		cout << "Enter Roll_number of student : ";
		cin >> Roll_number;
		cout << "Enter standard of student : ";
		cin >> standard;
		cout << "Enter division of student : ";
		cin >> division;
		cout << "Enter Telephone_number of student : ";
		cin >> Telephone_number;
		cout << "Enter Date_of_birth of student : ";
		cin >> Date_of_birth;
		cout << "Enter Blood_group of student : ";
		cin >> Blood_group;
		cout << "Enter Contact_address of student : ";
		cin >> Contact_address;
		cout << "Enter Driving_licence of student : ";
		cin >> Driving_licence;
	}
	inline void display() //inline display function
	{
		cout << "Name is : " << Name << endl;
		cout << "Roll_number is : " << Roll_number << endl;
		cout << "standard is : " << standard << endl;
		cout << "division is : " << division << endl;
		cout << "Telephone_number is : " << Telephone_number << endl;
		cout << "Date_of_birth is : " << Date_of_birth << endl;
		cout << "Blood_group is : " << Blood_group << endl;
		cout << "Contact_address is : " << Contact_address << endl;
		cout << "Driving_licence is : " << Driving_licence << endl;
	}
	~student()
	{ //Destructure
		cout << "Destructure is called" << endl;
	}
	student(student &obj)
	{ //copy constructure
		Name = obj.Name;
		Roll_number = obj.Roll_number;
		standard = obj.standard;
		division = obj.division;
		Telephone_number = obj.Telephone_number;
		Date_of_birth = obj.Date_of_birth;
		Blood_group = obj.Blood_group;
		Contact_address = obj.Contact_address;
		Driving_licence = obj.Driving_licence;
	}
	student(string Name, int Roll_number, string standard, string division, long int Telephone_number, int Date_of_birth, string Blood_group, string Contact_address, int Driving_licence)
	{					   //parametrised constructor
		this->Name = Name; //this pointer
		this->Roll_number = Roll_number;
		this->standard = standard;
		this->division = division;
		this->Telephone_number = Telephone_number;
		this->Date_of_birth = Date_of_birth;
		this->Blood_group = Blood_group;
		this->Contact_address = Contact_address;
		this->Driving_licence = Driving_licence;
		count++;
	}
};
class Friend //friend class
{
public:
	void view(student &pal)
	{
		pal.display();
	}
};

int student::count = 0;
int main()
{ //constructor, default constructor,
	int n;

	cout << "\n Number of students:";
	cin >> n;
	student s[n];

	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter data for student number : " << i + 1 << endl;
		s[i].read();
	}

	for (int i = 0; i < n; i++)
	{
		cout << "\nDetails of student number : " << i + 1;
		s[i].display();
		cout << "\n===========================================" << endl;
	}
	//friend function,copy constructure
	student hari, yash;
	hari.read();
	Friend om;
	om.view(hari);
	yash = hari;
	yash.display();

	//  dynamically alloted odject
	student *sadya = new student;
	sadya->student::read();
	sadya->student::display();

	delete sadya;
	//  static varible
	cout << "Total Number Of Students : " << student::count << endl;
	return 0;
}
