#include <iostream>
using namespace std;

class Student {
    string name;
    int rollNo;
    float marks[5];
    float percentage;
    char grade;
    
    void calculate() {
        float total = 0;
        for(int i = 0; i < 5; i++) total += marks[i];
        percentage = total / 5;
        
        if(percentage >= 90) grade = 'A';
        else if(percentage >= 80) grade = 'B';
        else if(percentage >= 70) grade = 'C';
        else if(percentage >= 60) grade = 'D';
        else grade = 'F';
    }

public:
    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll no: ";
        cin >> rollNo;
        cout << "Enter 5 subject marks: ";
        for(int i = 0; i < 5; i++) cin >> marks[i];
        calculate();
    }
    
    void display() {
        cout << "\nName: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Percentage: " << percentage << "%" << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    Student s;
    s.input();
    s.display();
    return 0;
}
