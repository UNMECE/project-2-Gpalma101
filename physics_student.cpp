#include "Physics_Student.h"

#include <algorithm>
#include <cctype>

namespace {
std::string toLowerCopyPhysics(const std::string& text) {
    std::string result = text;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return result;
}
}

Physics_Student::Physics_Student()
    : Student(),
      concentration_("Biophysics") {}

Physics_Student::Physics_Student(const std::string& firstName,
                                 const std::string& lastName,
                                 double gpa,
                                 int graduationYear,
                                 const std::string& graduationSemester,
                                 int enrolledYear,
                                 const std::string& enrolledSemester,
                                 const std::string& level,
                                 const std::string& concentration)
    : Student(firstName, lastName, gpa, graduationYear, graduationSemester,
              enrolledYear, enrolledSemester, level),
      concentration_(normalizeConcentration(concentration)) {}

Physics_Student::~Physics_Student() = default;

void Physics_Student::setConcentration(const std::string& concentration) {
    concentration_ = normalizeConcentration(concentration);
}

std::string Physics_Student::getConcentration() const {
    return concentration_;
}

std::string Physics_Student::normalizeConcentration(const std::string& concentration) {
    std::string text = toLowerCopyPhysics(concentration);

    if (text == "biophysics") return "Biophysics";
    if (text == "earth and planetary sciences") return "Earth and Planetary Sciences";

    return "Biophysics";
}

void Physics_Student::writeToFile(std::ostream& out) const {
    out << "Student Type: Physics Student\n";
    Student::writeToFile(out);
    out << "Concentration: " << concentration_ << '\n';
    out << "----------------------------------------\n";
}
