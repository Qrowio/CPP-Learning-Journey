#include <iostream>

int main()
{
    int vowels = 0;
    std::string inputString;
    std::cout << "Enter a string to get the vowels\n";
    std::cin >> inputString;
    
    for (int i = 0; i <= inputString.size(); i++) {
        if (toupper(inputString[i]) == 'A' || toupper(inputString[i]) == 'E' || toupper(inputString[i]) == 'I' || toupper(inputString[i]) == 'O' || toupper(inputString[i]) == 'U') {
            vowels++;
        }
    }
    std::cout << vowels;
}