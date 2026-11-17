#include "../include/Staff.hpp"

Staff::Staff(size_t SSN, const std::string& FIRSTNAME, const std::string& LASTNAME, std::chrono::year_month_day BIRTHDATE, size_t INSTITUTIONALID, StaffRole ROLE)
    : CollegeUser(SSN, FIRSTNAME, LASTNAME, BIRTHDATE, INSTITUTIONALID), Role(ROLE)
{
}

StaffRole Staff::getRole() const
{
    return Role;
}

void Staff::setRole(StaffRole ROLE)
{
    Role = ROLE;
}

std::string roleToString(StaffRole role)
{
    switch (role)
    {
        case TEACHER:
            return "Teacher";
        case ADMINISTRATIVE:
            return "Administrative";
        case SUPPORT:
            return "Support";
    }
    return "Unknown";
}
std::string Staff::toString()
{
    return std::format("{} Role: {}", CollegeUser::toString(),  roleToString(Role));
}