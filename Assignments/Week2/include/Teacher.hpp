#pragma once

#include "Staff.hpp"

enum Subject
{
    MATH,
    SCIENCE,
    HISTORY,
    ENGLISH,
    ART
};

class Teacher : public Staff
{
    protected:
        Subject m_subject;

    public:
        Teacher(size_t SSN, const std::string& FIRSTNAME, const std::string& LASTNAME, std::chrono::year_month_day BIRTHDATE, size_t INSTITUTIONALID, Subject TEACHINGSUBJECT);
        
        // We assume a teacher ONLY teaches one subject at a time, no history tracking of previous subjects is maintained.
        void setTeachingSubject(Subject TEACHINGSUBJECT);

        Subject getTeachingSubject() const;

        std::string toString() const override;
};