#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
using namespace std;
int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int count = 1; count <= 100; ++count)
    {
        std::cout << std::rand() << '\t';

        // display 5 random numbers per row
        if (count % 5 == 0)
            std::cout << '\n';
    }
    cout << "Generate a random number between float 0.0 and 1.0: " << static_cast<float>(rand()) / static_cast<float>(RAND_MAX) << endl;

    cout << "Generate a random number between float 1.2 and 3.4: " << 1.2 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (3.4 - 1.2))) << endl
         << endl;

    cout << "5 Random numbers generated between 0 and 1: " << endl;
    srand((unsigned)time(NULL));

    for (int i = 0; i < 5; ++i)
    {
        cout << (float)rand() / RAND_MAX << endl;
    }
    cout << endl;
    cout << endl;

    srand(time(0)); // Initialize random number generator.
    cout << "Random numbers generated between 1 and 10: " << endl;
    for (int j = 0; j < 10; ++j)
    {
        cout << (rand() % 10) + 1 << " ";
    }

    return 0;
}