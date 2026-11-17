#include "../include/College.hpp"

College::College(const std::string& name)
    : m_college_name(std::move(name))
{
}

std::string College::getCollegeName() const
{
    return m_college_name;
}

Student* College::enrollStudent(User* user)
{
    auto student = new Student(user->getSsn(), user->getFirstname(), user->getLastname(), user->getBirthDate(), ++m_next_id);
    m_users[student->getInstitutionalId()] = student;
    return student;
}

Teacher* College::hireTeacher(User* user, Subject subject)
{
    auto teacher = new Teacher(user->getSsn(), user->getFirstname(), user->getLastname(), user->getBirthDate(), ++m_next_id, subject);
    m_users[teacher->getInstitutionalId()] = teacher;
    return teacher;
}

Staff* College::hireStaff(User* user, StaffRole role)
{
    auto staff = new Staff(user->getSsn(), user->getFirstname(), user->getLastname(), user->getBirthDate(), ++m_next_id, role);
    m_users[staff->getInstitutionalId()] = staff;
    return staff;
}

std::vector<CollegeUser*> College::getUsers() const
{
    std::vector<CollegeUser*> users;
    for (const auto& [id, user] : m_users)
    {
        users.push_back(user);
    }
    return users;
}

// Cleanup
void College::clearUsers()
{
    for (auto& [id, user] : m_users)
    {
        delete user;
    }
    m_users.clear();
}

College::~College()
{
    clearUsers();
}