#include <iostream>
#include <string>

int main()
{
    int amountWords = 0;
    std::string userString;
    std::cout << "Count words in a string\n";
    std::cout << "Enter a string" << std::endl;
    std::getline(std::cin, userString);
    for (int i = 0; i < userString.size(); i++) {
        if (userString[i] == ' ') {
            amountWords++;
        }
    };
    std::cout << "There are " + std::to_string(amountWords + 1) + " words" << std::endl;
}