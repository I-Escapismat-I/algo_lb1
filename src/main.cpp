#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <locale>

struct Student
{
    std::string name;
    int age;
    double gpa;
};

class StudentDatabase
{
    public:
    void addStudent(const Student& student)
    {
        students.push_back(student);
    }
    void removeStudent(const std::string& name)
    {
        students.erase(std::remove_if(students.begin(), students.end(),
                                      [&name](const Student& s) { return s.name == name; }),
                       students.end());
    }
    void printStudents() const
    {
        for (const auto& student : students)
        {
            std::cout << "Name: " << student.name << ", Age: " << student.age << ", GPA: " << student.gpa << std::endl;
        }
    }
    void findStudentName(const std::string & name) const
    {
        for(auto & student : students)
        {
            if(student.name.find(name) == 0)
            {
                std::cout << "Name: " << student.name << ", Age: " << student.age << ", GPA: " << student.gpa << std::endl;
            }
        }
    }
    private:
    std::vector<Student> students;
};

int main()
{

    StudentDatabase db;
    db.addStudent({"Alice", 20, 3.5});
    db.addStudent({"Bob", 22, 3.7});
    db.addStudent({"Bad", 21, 3.9});
    db.addStudent({"Booby", 21, 3.9});
    db.findStudentName("Bo");

    return 0;
}