#include "../include/Student.hpp"
#include <format>

Student::Student(size_t SSN, const std::string& FIRSTNAME, const std::string& LASTNAME, std::chrono::year_month_day BIRTHDATE, size_t INSTITUTIONALID)
    : CollegeUser(SSN, FIRSTNAME, LASTNAME, BIRTHDATE, INSTITUTIONALID)
{
}


std::string Student::toString()
{
    return std::format("{} Student", CollegeUser::toString());
}