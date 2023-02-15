#include <iostream>
#include <vector>

struct Cat
{
    Cat() : name(""), color(""), age(0), weight(0) {}
    Cat(std::string n, std::string c, int a, int w) : name(std::move(n)), color(std::move(c)), age(a), weight(w) {}
    std::string name;
    std::string color;
    int age;
    int weight;
};

void too_many_cats()
{
    Cat houseCats[] = {{"Meowmix", "black", 9, 12},
                       {"Thundercat", "grey", 4, 16}};
    std::cout << houseCats[0].name << std::endl;
    std::cout << houseCats[2].name << std::endl;
}

void write_file(const char *str)
{
    char *buff = new char[8]; // std::unique_ptr<char[]> buff(new char[str.length() + 1]); smart pointer to avoid memleak

    strcpy(buff, str);

    FILE *file = fopen("out.txt", "w");
    if (!file)
        return;
    for (char *c = buff; *c; ++c)
    {
        fputc((int)*c, file);
    }
    delete[] buff;
}

void vector_check()
{
    std::vector<int> items; // std::vector<int> items_copy = items;
    items.push_back(1);
    items.push_back(2);
    items.push_back(3);
    std::vector<int>::iterator iter;
    // for (iter = items_copy.begin(); iter != items_copy.end(); ++iter)
    for (iter = items.begin(); iter != items.end(); ++iter)
    {
        if (*iter == 2) // if (iter != items.end() && *iter == 2)
        {
            items.erase(iter);
        }
    }
}

int main()
{
    too_many_cats();
    write_file(static_cast<const char *>("Hello World"));
    vector_check();
}

// To avoid using invalid iterators or references to elements of a local container after the container is destroyed, you can copy the elements of the container to a new container or a data structure that has a longer lifetime than the local container. Here's an example of how you can achieve this:
void process_items(std::vector<int> items)
{
    // creates a new vector to hold a copy of the items
    std::vector<int> items_copy(items.begin(), items.end());

    // Use an iterator to traverse the copy of the items
    for (std::vector<int>::iterator iter = items_copy.begin(); iter != items_copy.end(); ++iter)
    {
        // Do some processing on the item
        if (*iter == 2)
        {
            // If the items meets a certain condition, erase it from the original vector
            items.erase(std::remove(items.begin(), items.end(), *iter), items.end());
        }
    }
}
