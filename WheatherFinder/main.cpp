#include <iostream>
#include "cpr/cpr.h"

int main()
{
    std::string resp = cpr::Get(cpr::Url("https://httpbin.org/get")).text;
    std::cout << resp;
    system("PAUSE");
}