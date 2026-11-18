#include "../include/Teacher.hpp"

Teacher::Teacher(size_t SSN, const std::string& FIRSTNAME, const std::string& LASTNAME, std::chrono::year_month_day BIRTHDATE, size_t INSTITUTIONALID, Subject TEACHINGSUBJECT)
    : Staff(SSN, FIRSTNAME, LASTNAME, BIRTHDATE, INSTITUTIONALID, StaffRole::TEACHER), m_subject(TEACHINGSUBJECT)   
{
}

void Teacher::setTeachingSubject(Subject TEACHINGSUBJECT)
{
    m_subject = TEACHINGSUBJECT;
}

Subject Teacher::getTeachingSubject() const
{
    return m_subject;
}

std::string subjectToString(Subject subject)
{
    switch (subject)
    {
        case Subject::ART:
            return "Art";
        case Subject::MATH:
            return "Math";
        case Subject::SCIENCE:
            return "Science";
        case Subject::ENGLISH:
            return "English";
        case Subject::HISTORY:
            return "History";
    }
    return "Unknown";
}

std::string Teacher::toString() const
{
    return std::format("{} Teaching Subject: {}", Staff::toString(), subjectToString(m_subject));
}
