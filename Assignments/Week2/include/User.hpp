#pragma once

#include <iostream>
#include <chrono>

// A generic person with basic personal information, not tied to any specific institution or role
class User 
{
    protected:
        size_t ssn; // Social Security Number - Unique identifier for the user
        std::string m_firstname;
        std::string m_lastname; 
        std::chrono::year_month_day m_birthdate;

    public:
        User(size_t SSN, const std::string& FIRSTNAME, const std::string& LASTNAME, std::chrono::year_month_day BIRTHDATE);
        virtual ~User() = default;

        // We assume a user cannot change their SSN, first name, last name, or birth date after creation
        // There could be exceptions in real life but for simplicity, we do not allow changes after creation

        size_t getSsn() const;
        std::string getFirstname() const;
        std::string getLastname() const;
        std::chrono::year_month_day getBirthDate() const;
};