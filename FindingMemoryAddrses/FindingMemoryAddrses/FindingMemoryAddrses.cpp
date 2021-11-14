#include <iostream>

int main()
{
    int find = 69;
    int* findLocation = &find;
    std::cout << "You found me at " << findLocation << std::endl;
    std::cout << "My value is " << *findLocation << std::endl;
    *findLocation = 420;
    std::cout << "You updated my value " << *findLocation << " + " << find << std::endl;
}