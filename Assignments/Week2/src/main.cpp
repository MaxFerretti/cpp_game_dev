#include <iostream>
#include "../include/College.hpp"
#include "../include/Student.hpp"
#include "../include/Teacher.hpp"
#include "../include/Staff.hpp"
#include "../include/CollegeUser.hpp"
#include "../include/OnlineCollege.hpp"

College* Populate(College* college);

void PrintInfo(std::string text);
void PrintOutput(std::string text);
void PrintHeader(std::string text);

int main()
{
    OnlineCollege rebelway("Rebelway", "www.rebelway.com");

    Populate(&rebelway);

    PrintHeader("This is the assignment for Week 2 - a simple College simulator\n");

    PrintInfo("College: ");
    PrintOutput(rebelway.getCollegeName() + "\n");
    PrintInfo("You can reach the online college on ");
    PrintOutput(rebelway.getPlatformUrl() + "\n");

    PrintInfo("Users enrolled in the college:\n");
    for (auto user : rebelway.getUsers())
    {
        PrintOutput(user->toString() + "\n");
    }

    return 0;
}

void PrintHeader(std::string text)
{
    std::cout << "\033[34m" << text << "\033[0m";
}
void PrintInfo(std::string text)
{
    std::cout << "\033[36m" << text << "\033[0m";
}
void PrintOutput(std::string text)
{
    std::cout << "\033[32m" << text << "\033[0m";
}


College* Populate(College* college)
{
    // Teachers 
    auto teacher1 = User(123456789, "John", "Doe", std::chrono::year_month_day{std::chrono::year{1980}, std::chrono::month{1}, std::chrono::day{1}});
    college->hireTeacher(&teacher1, Subject::ART);

    // Students
    auto student1 = User(987654321, "Jane", "Smith", std::chrono::year_month_day{std::chrono::year{2000}, std::chrono::month{5}, std::chrono::day{15}});
    college->enrollStudent(&student1);

    auto student2 = User(192837465, "Alice", "Johnson", std::chrono::year_month_day{std::chrono::year{2001}, std::chrono::month{7}, std::chrono::day{20}});
    college->enrollStudent(&student2);

    // Staff 
    auto staff1 = User(564738291, "Bob", "Brown", std::chrono::year_month_day{std::chrono::year{1975}, std::chrono::month{3}, std::chrono::day{10}});
    college->hireStaff(&staff1, StaffRole::ADMINISTRATIVE);

    auto staff2 = User(837465192, "Eve", "Davis", std::chrono::year_month_day{std::chrono::year{1985}, std::chrono::month{11}, std::chrono::day{25}});
    college->hireStaff(&staff2, StaffRole::SUPPORT);   

    return college;
}
