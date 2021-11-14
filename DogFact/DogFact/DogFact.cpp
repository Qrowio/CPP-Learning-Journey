#include <iostream>
#include "cpr/cpr.h"
#include "json.hpp"
#include <string>

using namespace nlohmann;

int main()
{
    std::string getRequest = cpr::Get(cpr::Url("https://some-random-api.ml/facts/dog")).text;
    auto parseRequest = json::parse(getRequest);

    std::string fact = parseRequest["fact"];
    std::cout << fact << std::endl;

   // std::cout << parseRequest;
}
