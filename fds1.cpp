#include <iostream>
using namespace std;

class Student
{
private:
    int n;
    int roll[50];
    int marks[50];
    int total;
    char att[50];

public:
    void accept();
    void display();
    void max();
    void min();
    void avg();
    void absent();
    
};
void Student::accept(){
    cout<<"Enter the Students in SE : ";
    cin>>total;
    
    for (int i = 0; i < total; i++)
    {
     cout<<"Roll NO : ";
     cin>>roll[i];
     cout<<"Enter The attendence Status (present :P/p and Absent :A/a)";
     cin>>att[i];
     
    }
    
}

int main(){

}