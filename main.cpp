#include "Art_Student.h"
#include "Physics_Student.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<Art_Student*> art_students;
    std::vector<Physics_Student*> physics_students;

    art_students.push_back(new Art_Student());
    art_students.push_back(new Art_Student());
    art_students.push_back(new Art_Student());
    art_students.push_back(new Art_Student());
    art_students.push_back(new Art_Student());

    physics_students.push_back(new Physics_Student());
    physics_students.push_back(new Physics_Student());
    physics_students.push_back(new Physics_Student());
    physics_students.push_back(new Physics_Student());
    physics_students.push_back(new Physics_Student());

    art_students[0]->setName("Ava", "Lopez");
    art_students[0]->setGPA(3.90);
    art_students[0]->setGraduationYear(2026);
    art_students[0]->setGraduationSemester("Spring");
    art_students[0]->setEnrolledYear(2022);
    art_students[0]->setEnrolledSemester("Fall");
    art_students[0]->setLevel("undergrad");
    art_students[0]->setArtEmphasis("Art Studio");

    art_students[1]->setName("Noah", "Kim");
    art_students[1]->setGPA("3.70");
    art_students[1]->setGraduationYear(2027);
    art_students[1]->setGraduationSemester("Fall");
    art_students[1]->setEnrolledYear(2023);
    art_students[1]->setEnrolledSemester("Spring");
    art_students[1]->setLevel("undergrad");
    art_students[1]->setArtEmphasis("Art History");

    art_students[2]->setName("Mia", "Patel");
    art_students[2]->setGPA(3.45);
    art_students[2]->setGraduationYear(2025);
    art_students[2]->setGraduationSemester("Summer");
    art_students[2]->setEnrolledYear(2021);
    art_students[2]->setEnrolledSemester("Fall");
    art_students[2]->setLevel("grad");
    art_students[2]->setArtEmphasis("Art Education");

    art_students[3]->setName("Ethan", "Nguyen");
    art_students[3]->setGPA(3.85);
    art_students[3]->setGraduationYear(2026);
    art_students[3]->setGraduationSemester("Spring");
    art_students[3]->setEnrolledYear(2022);
    art_students[3]->setEnrolledSemester("Spring");
    art_students[3]->setLevel("undergrad");
    art_students[3]->setArtEmphasis("Art Studio");

    art_students[4]->setName("Sophia", "Garcia");
    art_students[4]->setGPA(3.95);
    art_students[4]->setGraduationYear(2028);
    art_students[4]->setGraduationSemester("Fall");
    art_students[4]->setEnrolledYear(2024);
    art_students[4]->setEnrolledSemester("Fall");
    art_students[4]->setLevel("grad");
    art_students[4]->setArtEmphasis("Art History");

    physics_students[0]->setName("Liam", "Carter");
    physics_students[0]->setGPA(3.88);
    physics_students[0]->setGraduationYear(2026);
    physics_students[0]->setGraduationSemester("Spring");
    physics_students[0]->setEnrolledYear(2022);
    physics_students[0]->setEnrolledSemester("Fall");
    physics_students[0]->setLevel("undergrad");
    physics_students[0]->setConcentration("Biophysics");

    physics_students[1]->setName("Olivia", "Brooks");
    physics_students[1]->setGPA(3.66);
    physics_students[1]->setGraduationYear(2027);
    physics_students[1]->setGraduationSemester("Fall");
    physics_students[1]->setEnrolledYear(2023);
    physics_students[1]->setEnrolledSemester("Spring");
    physics_students[1]->setLevel("undergrad");
    physics_students[1]->setConcentration("Earth and Planetary Sciences");

    physics_students[2]->setName("James", "Walker");
    physics_students[2]->setGPA(3.52);
    physics_students[2]->setGraduationYear(2025);
    physics_students[2]->setGraduationSemester("Summer");
    physics_students[2]->setEnrolledYear(2021);
    physics_students[2]->setEnrolledSemester("Fall");
    physics_students[2]->setLevel("grad");
    physics_students[2]->setConcentration("Biophysics");

    physics_students[3]->setName("Emma", "Diaz");
    physics_students[3]->setGPA(3.91);
    physics_students[3]->setGraduationYear(2026);
    physics_students[3]->setGraduationSemester("Spring");
    physics_students[3]->setEnrolledYear(2022);
    physics_students[3]->setEnrolledSemester("Fall");
    physics_students[3]->setLevel("undergrad");
    physics_students[3]->setConcentration("Earth and Planetary Sciences");

    physics_students[4]->setName("Benjamin", "Hall");
    physics_students[4]->setGPA(3.74);
    physics_students[4]->setGraduationYear(2028);
    physics_students[4]->setGraduationSemester("Fall");
    physics_students[4]->setEnrolledYear(2024);
    physics_students[4]->setEnrolledSemester("Spring");
    physics_students[4]->setLevel("grad");
    physics_students[4]->setConcentration("Biophysics");

    std::ofstream outfile("student_info.dat", std::ios::out);

    if (!outfile.is_open()) {
        std::cerr << "Error: could not open student_info.dat for writing.\n";

        for (Art_Student* student : art_students) {
            delete student;
        }
        for (Physics_Student* student : physics_students) {
            delete student;
        }

        return 1;
    }

    outfile << "=== Art Students ===\n";
    for (std::size_t i = 0; i < art_students.size(); ++i) {
        art_students[i]->writeToFile(outfile);
    }

    outfile << "\n=== Physics Students ===\n";
    for (std::size_t i = 0; i < physics_students.size(); ++i) {
        physics_students[i]->writeToFile(outfile);
    }

    outfile.close();

    for (Art_Student* student : art_students) {
        delete student;
    }
    for (Physics_Student* student : physics_students) {
        delete student;
    }

    std::cout << "Student information written to student_info.dat\n";
    return 0;
}
