#include "../include/CollegeUser.hpp"

CollegeUser::CollegeUser(size_t SSN, const std::string& FIRSTNAME, const std::string& LASTNAME, std::chrono::year_month_day BIRTHDATE, size_t INSTITUTIONALID)
    : User(SSN, FIRSTNAME, LASTNAME, BIRTHDATE), InstitutionalId(INSTITUTIONALID)
{
}

size_t CollegeUser::getInstitutionalId() const
{
    return InstitutionalId;
}

std::string CollegeUser::toString()
{
    return std::format("ID: [{}]  Name: {} {} {}-{}-{}", getInstitutionalId(), getFirstname(), getLastname(), getBirthDate().year(), getBirthDate().month(), getBirthDate().day());
}