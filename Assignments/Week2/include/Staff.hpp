#pragma once

#include "CollegeUser.hpp"

enum StaffRole
{
    TEACHER,
    ADMINISTRATIVE,
    SUPPORT
};

// A generic staff member in the college system, including teachers, administrative and support roles.
class Staff : public CollegeUser
{
    protected:
        StaffRole Role;

    public:
        Staff(size_t SSN, const std::string& FIRSTNAME, const std::string& LASTNAME, std::chrono::year_month_day BIRTHDATE, size_t INSTITUTIONALID, StaffRole ROLE);

        void setRole(StaffRole ROLE);

        StaffRole getRole() const;

        std::string toString() override;
};