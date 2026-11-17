#pragma once

#include <iostream>
#include <unordered_map>
#include "CollegeUser.hpp"
#include "Student.hpp"
#include "Teacher.hpp"
#include "Staff.hpp"


class College
{
    private:
        std::string m_college_name;
        // Our "database" of College Users, we keep track only of internal users (students, teachers, staff), not any generic users
        std::unordered_map<int, CollegeUser*> m_users;

        size_t m_next_id = 0; // To assign unique IDs to users

    public:
        College(const std::string& name);
        void clearUsers();
        ~College();

        // Get the name of the college, no setter since we cannot afford the bureaucracy of changing it later
        std::string getCollegeName() const;
        
        // Methods to add people to the college, converting generic Users into specific College Users (Students, Teachers, Staff)
        Student* enrollStudent(User* user);
        Teacher* hireTeacher(User* user, Subject subject);
        Staff* hireStaff(User* user, StaffRole role);

        std::vector<CollegeUser*> getUsers() const;

};
