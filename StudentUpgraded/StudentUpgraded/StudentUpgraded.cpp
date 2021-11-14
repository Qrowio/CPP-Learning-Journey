#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

class studentInfo {
public:
    std::string childName;
    std::string studentLogin;
    int childID;

    void getGrade() {
        system("cls");
        std::string grades;
        std::ifstream getGrades("grades.txt");
        std::cout << "Your child's name is " + childName << std::endl;
        std::cout << childName + "'s grades: " << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
        while (std::getline(getGrades, grades)) {
            std::cout << grades + "%" << std::endl;
        }
    }
};

int main()
{
here:
    system("cls");
    studentInfo studentInfo;
    std::ifstream myLogin("student.txt");
    std::getline(myLogin, studentInfo.studentLogin);
    std::cout << "Welcome to Imperial College London student grade checker" << std::endl;
    std::cout << "Please enter your childs name" << std::endl;
    std::cin >> studentInfo.childName;
    std::cout << "Please enter your childs ID" << std::endl;
    std::cin >> studentInfo.childID;

    if (studentInfo.childName + ":" + std::to_string(studentInfo.childID) == studentInfo.studentLogin) {
        studentInfo.getGrade();
    }
    else {
        std::cout << "Your child doesn't exist";
        Sleep(1000);
        goto here;
    }
    system("PAUSE");
}