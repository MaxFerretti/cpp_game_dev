#pragma once

#include "CollegeUser.hpp"

class Student : public CollegeUser
{
    public:
        Student(size_t SSN, const std::string& FIRSTNAME, const std::string& LASTNAME, std::chrono::year_month_day BIRTHDATE, size_t INSTITUTIONALID);

        std::string toString() const override;
 
};