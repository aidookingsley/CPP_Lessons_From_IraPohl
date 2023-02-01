#include <iostream>
#include <list>
using namespace std;
// Pint() chaining
// List

class list_element
{
public:
    list_element(int n = 0, list_element *ptr = 0) : d(n), next(ptr) {}
    int d;
    list_element *next;
};

class List
{
public:
    List() : head(0), cursor(0) {}
    void prepend(int n); // insert at front value n
    int get_element() { return cursor->d; }
    void advance() { cursor = cursor->next; }
    void print();

private:
    list_element *head;
    list_element *cursor; // helps with efficiency
};

// Prepend

void List::prepend(int n)
{
    if (head == nullptr) // empty list case
        cursor = head = new list_element(n, head);
    else // add to front-chain
        head = new list_element(n, head);
}

void List::print()
{
    list_element *h = head;
    while (h != nullptr)
    { // idiom for chaining
        cout << h->d << ",";
        h = h->next;
    }
    cout << "\n###" << endl;
}

// + should know how to use recursion
// + should know how to overload "<<" for list

int main()
{
    List a, b;
    a.prepend(9);
    a.prepend(8);
    cout << " list a " << endl;
    a.print();
    for (int i = 0; i < 40; ++i)
        b.prepend(i * i);
    cout << " list b " << endl;
    b.print();
}