#include <iostream>
#include <string>

using namespace std;

class student
{
public:
    enum year
    {
        fresh,
        soph,
        junior,
        senior,
        grad
    };
    student(const std::string &nm, int id, double g, year x);
    virtual ~student() {}
    virtual void print();

protected:
    int student_id;
    double gpa;
    year y;
    std::string name;
};

class grad_student : public student
{
public:
    enum support
    {
        ta,
        ra,
        fellowship,
        other
    };
    grad_student(const std::string &nm, int id, double g, year x, support t, const std::string &d, const std::string &th);
    void print() override;

private:
    support s;
    std::string dept;
    std::string thesis;
};

student::student(const std::string &nm, int id, double g, year x) : student_id(id), gpa(g), y(x), name(nm) {}

grad_student::grad_student(const std::string &nm, int id, double g, year x, support t, const std::string &d, const std::string &th) : student(nm, id, g, x), s(t), dept(d), thesis(th) {}

void student::print()
{
    cout << "\n"
         << name << " , " << student_id << " , " << y << " , " << gpa << endl;
}

void grad_student::print()
{
    student::print(); // base class info is printed
    cout << dept << " , " << s << "\n"
         << thesis << endl;
}
// Test pointer conversion rules

int main()
{
    student s("Mae Pohl", 100, 3.425, student::fresh);
    grad_student gs("Morris Pohl", 200, 3.2564, student::grad, grad_student::ta, "Pharmacy", "Retail Pharmacies");
    student *ps = &s;
    student *pgs = &gs;

    ps->print();  // student::print
    pgs->print(); // grad_student::print
}