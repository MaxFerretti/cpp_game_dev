#include "../include/User.hpp"

User::User(size_t SSN, const std::string& FIRSTNAME, const std::string& LASTNAME, std::chrono::year_month_day BIRTHDATE)
    : ssn(SSN), m_firstname(std::move(FIRSTNAME)), m_lastname(std::move(LASTNAME)), m_birthdate(BIRTHDATE)
{
}

size_t User::getSsn() const
{
    return ssn;
}

std::string User::getFirstname() const
{
    return std::string(m_firstname);
}

std::string User::getLastname() const
{
    return std::string(m_lastname);
}

std::chrono::year_month_day User::getBirthDate() const
{
    return m_birthdate;
}