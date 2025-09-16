#pragma once
#include <list>
#include <string>
#include <iostream>

struct Student {
    int id;
    std::string name;
    std::string lastName;
    int nomZach;
};

class StudentDatabase {
public:
    StudentDatabase();
    void addStudent(const std::string& name, const std::string& lastName, int nomZach);
    void removeStudentById(int id);
    void printStudents() const;
    void findStudentName(const std::string& name) const;

private:
    std::list<Student> students;
    int nextId;
};
