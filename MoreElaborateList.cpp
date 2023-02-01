#include <iostream>
#include <list>
using namespace std;

class list_element
{
public:
    list_element(int n = 0, list_element *ptr = 0) : d(n), next(ptr) {}
    int d;
    list_element *next;
};

class myList
{
public:
    void print();
    void prepend(int n);             // insert at front value n
    myList() : head(0), cursor(0) {} // default constructor
    myList(const int *arr, int n);
    myList(const myList &lst, int n) // copy constructor
    {
        if (lst.head == 0)
        {
            head = nullptr;
            cursor = nullptr;
        }
        else
            // set up
            cursor = lst.head;
        list_element *h = new list_element();
        list_element *previous;
        head = h;
        h->d = lst.head->d;
        previous = h;

        for (cursor = lst.head; cursor != 0;)
        {
            h = new list_element();
            h->d = cursor->d;
            previous->next = h;
            cursor = cursor->next;
            previous = h;
        }
        cursor = head;
    }

    ~myList() // delete
    {
        for (cursor = head; cursor != 0;)
        {
            cursor = head->next;
            delete head;
            head = cursor;
        }
    } // Here the destructor chains through the list returning each list_element created by a corresponding new.

private:
    list_element *head;
    list_element *cursor;
};

// Prepend

void myList::prepend(int n)
{
    if (head == nullptr) // empty list case
        cursor = head = new list_element(n, head);
    else // add to front-chain
        head = new list_element(n, head);
}

void myList::print()
{
    list_element *h = head;
    while (h != nullptr)
    { // idiom for chaining
        cout << h->d << ",";
        h = h->next;
    }
    cout << "\n###" << endl;
}

int main()
{
    myList a, b;
    int data[10] = {3, 4, 6, 7, -3, 5};
    myList d(data, 6);
    myList e(data, 10);
    a.prepend(9);
    a.prepend(8);
    cout << " list a " << endl;
    a.print();

    for (int i = 0; i < 40; ++i)
        b.prepend(i * i);
    cout << " list b " << endl;
    b.print();
    myList c(b);
    c.print();
    d.print();
    e.print();
}

// Deep vs Referential copy
/*
First we will examine the copy constructor. We want to build an equivalent list that is a "deep" copy.

A "shallow" copy would be a reerential copy where the new list head would be the same value as the old list head.

shallow copy is a highly efficient form of copying (why?) but has more limited utility than a deep copy(why?).

*/