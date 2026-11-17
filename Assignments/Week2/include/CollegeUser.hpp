#pragma once

#include "User.hpp"

// A college user is anytone inside this college, such as students, teachers or staff.
class CollegeUser : public User
{
    protected:
        size_t InstitutionalId; // Internal unique identifier for the college user

    public:
        CollegeUser(size_t SSN, const std::string& FIRSTNAME, const std::string& LASTNAME, std::chrono::year_month_day BIRTHDATE, size_t INSTITUTIONALID);

        // There is no setter for InstitutionalId, it is set only through the constructor.
        // Once inside the college system, the InstitutionalId remains constant for the user.
        size_t getInstitutionalId() const;

        virtual std::string toString();
};