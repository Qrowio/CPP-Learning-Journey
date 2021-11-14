#include <iostream>
#include "cpr/cpr.h"
#include <string>
#include "json.hpp"

using namespace nlohmann;

void replace(std::string& str, const std::string& original, const std::string& changed) {
    size_t s = str.find(original);
    if (s == std::string::npos)
        return;
    str.replace(s, original.length(), changed);
}

int main()
{
    next:
    std::string location;
    std::cout << "Enter a city that you want to know the temperature of" << std::endl;
    std::cin >> location;
    replace(location, " ", "%20");
    std::string resp = cpr::Get(cpr::Url("http://api.weatherstack.com/current?access_key=e00d6c4d9755cf657e3911ddf01eda05&query=" + location)).text;
    auto ParsedResponse = json::parse(resp);

    int Temperature = ParsedResponse["current"]["temperature"];
    int Feelslike = ParsedResponse["current"]["feelslike"];
    std::string isDay = ParsedResponse["current"]["is_day"];
    std::cout << "You selected " + location << std::endl;
    std::cout << location + " feels like " << Feelslike << std::endl;
    std::cout << "it is " << Temperature << " degrees" << std::endl;
    if (isDay == "yes") {
        std::cout << "It is currently day time" << std::endl;
    }
    else {
        std::cout << "It is night time" << std::endl;
    }

    std::string Discord = "In " + location + " it is currently " + std::to_string(Temperature) + " degrees" + ". It feels like " + std::to_string(Feelslike) + " degrees.";
    std::string Response = cpr::Post(cpr::Url(WEBHOOK), cpr::Payload{ {"content", Discord} }).text;

    std::cout << Response;


    goto next;
    system("PAUSE");
}