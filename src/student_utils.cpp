#include "student_utils.h"

StudentDatabase::StudentDatabase() : nextId(1) {}

void StudentDatabase::addStudent(const std::string& name, const std::string& lastName, int nomZach) {
    students.push_back({ nextId++, name, lastName, nomZach });
}

void StudentDatabase::removeStudentById(int id) {
    for (auto it = students.begin(); it != students.end(); )
        if (it->id == id) it = students.erase(it);
        else ++it;
}

void StudentDatabase::printStudents() const {
    if (students.empty()) {
        std::cout << "Список студентов пуст.\n";
        return;
    }
    for (const auto& s : students)
        std::cout << "ID: " << s.id
        << ", Имя: " << s.name
        << ", Фамилия: " << s.lastName
        << ", Номер зачетки: " << s.nomZach << "\n";
}

void StudentDatabase::findStudentName(const std::string& name) const {
    bool found = false;
    for (const auto& s : students)
        if (s.name.find(name) == 0) {
            std::cout << "ID: " << s.id
                << ", Имя: " << s.name
                << ", Фамилия: " << s.lastName
                << ", Номер зачетки: " << s.nomZach << "\n";
            found = true;
        }
    if (!found)
        std::cout << "Студенты с именем, начинающимся на \"" << name << "\" не найдены.\n";
}
