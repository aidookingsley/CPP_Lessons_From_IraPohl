// C++ Program to calculate the average marks of students
#include <iostream>
using namespace std;

//PASS OBJECTS TO FUNCTION
// class Student
// {
// public:
//     double marks;

//     // constructor to initialize marks
//     Student(double m)
//     {
//         marks = m;
//     }
// };

// // function that has objects as parameters
// void calculateAverage(Student s1, Student s2)
// {

//     // calculate the average of marks of s1 and s2
//     double average = (s1.marks + s2.marks) / 2;

//     cout << "Average Marks = " << average << endl;
// }

// int main()
// {
//     Student student1(88.0), student2(56.0);

//     // pass the objects as arguments
//     calculateAverage(student1, student2);

//     return 0;
// }

// RETURN OBJECT FROM A FUNCTION
class Student {
    public:
        double marks1, marks2;
};

// function that returns object of Student
Student createStudent() {
    Student student;

    // Initialize member variables of Student
    student.marks1 = 96.5;
    student.marks2 = 75.0;

    // print member variables of Student
    cout << "Marks 1 = "<<student.marks1<<endl;
    cout << "Marks 2 = "<<student.marks2<<endl;

    return student;
}

int main() {
    Student student1;

    // Call function
    student1 = createStudent();

    return 0;
}