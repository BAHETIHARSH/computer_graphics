#include <iostream>
using namespace std;

class Student
{
public:
    string name, dob, bloodgroup, contact_address, driving_license_no, division;
    int rollnumber, standard;
    long int telephone_number;

    void get()
    {
        cout << "enter the name : ";
        cin >> name;
        cout << "enter the Roll Number : ";
        cin >> rollnumber;
        cout << "enter the Class : ";
        cin >> standard;
        cout << "enter the Division : ";
        cin >> division;
        cout << "enter the Date Of Birth : ";
        cin >> dob;
        cout << "enter the Blood Group : ";
        cin >> bloodgroup;
        cout << "enter the Contact Address : ";
        cin >> contact_address;
        cout << "enter the Telephone Number : ";
        cin >> telephone_number;
        cout << "enter the Driving License No. : ";
        cin >> driving_license_no;
    }
    void display()
    {
        cout << " the name : " << name << endl;
        cout << " the Roll Number : " << rollnumber << endl;
        cout << " the Class : " << standard << endl;
        cout << " the Division : " << division << endl;
        cout << " the Date Of Birth : " << dob << endl;
        cout << " the Blood Group : " << bloodgroup << endl;
        cout << " the Contact Address : " << contact_address << endl;
        cout << " the Telephone Number : " << telephone_number << endl;
        cout << " the Driving License No. : " << driving_license_no << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the Number of Student : ";
    cin >> n;

    Student A[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Details of " << i + 1 << " th student" << endl;
        A[i].get();
        cout << "===========================================" << endl;
    };
    for (int i = 0; i < n; i++)
    {
        cout << "the Details of " << i + 1 << "th student" << endl;
        A[i].display();
        cout << "===========================================" << endl;
    };
}
