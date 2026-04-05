#include "Student.h"

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <sstream>

namespace {
std::string toLowerCopy(const std::string& text) {
    std::string result = text;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return result;
}
}

Student::Student()
    : firstName_("Unknown"),
      lastName_("Unknown"),
      gpa_(0.0),
      graduationYear_(0),
      graduationSemester_("Unknown"),
      enrolledYear_(0),
      enrolledSemester_("Unknown"),
      level_("undergrad") {}

Student::Student(const std::string& firstName,
                 const std::string& lastName,
                 double gpa,
                 int graduationYear,
                 const std::string& graduationSemester,
                 int enrolledYear,
                 const std::string& enrolledSemester,
                 const std::string& level)
    : firstName_(firstName),
      lastName_(lastName),
      gpa_(0.0),
      graduationYear_(graduationYear),
      graduationSemester_(normalizeSemester(graduationSemester)),
      enrolledYear_(enrolledYear),
      enrolledSemester_(normalizeSemester(enrolledSemester)),
      level_(normalizeLevel(level)) {
    setGPA(gpa);
}

Student::~Student() = default;

void Student::setName(const std::string& firstName, const std::string& lastName) {
    firstName_ = firstName;
    lastName_ = lastName;
}

void Student::setFirstName(const std::string& firstName) {
    firstName_ = firstName;
}

void Student::setLastName(const std::string& lastName) {
    lastName_ = lastName;
}

void Student::setGPA(double gpa) {
    if (gpa < 0.0) {
        gpa_ = 0.0;
    } else if (gpa > 4.0) {
        gpa_ = 4.0;
    } else {
        gpa_ = gpa;
    }
}

void Student::setGPA(const std::string& gpaText) {
    try {
        setGPA(std::stod(gpaText));
    } catch (...) {
        gpa_ = 0.0;
    }
}

void Student::setGraduationYear(int year) {
    graduationYear_ = year;
}

void Student::setGraduationSemester(const std::string& semester) {
    graduationSemester_ = normalizeSemester(semester);
}

void Student::setEnrolledYear(int year) {
    enrolledYear_ = year;
}

void Student::setEnrolledSemester(const std::string& semester) {
    enrolledSemester_ = normalizeSemester(semester);
}

void Student::setLevel(const std::string& level) {
    level_ = normalizeLevel(level);
}

std::string Student::getFirstName() const {
    return firstName_;
}

std::string Student::getLastName() const {
    return lastName_;
}

double Student::getGPA() const {
    return gpa_;
}

int Student::getGraduationYear() const {
    return graduationYear_;
}

std::string Student::getGraduationSemester() const {
    return graduationSemester_;
}

int Student::getEnrolledYear() const {
    return enrolledYear_;
}

std::string Student::getEnrolledSemester() const {
    return enrolledSemester_;
}

std::string Student::getLevel() const {
    return level_;
}

std::string Student::normalizeSemester(const std::string& semester) {
    std::string text = toLowerCopy(semester);

    if (text == "spring") return "Spring";
    if (text == "summer") return "Summer";
    if (text == "fall") return "Fall";
    if (text == "winter") return "Winter";

    return "Unknown";
}

std::string Student::normalizeLevel(const std::string& level) {
    std::string text = toLowerCopy(level);

    if (text == "undergrad" || text == "undergraduate") return "undergrad";
    if (text == "grad" || text == "graduate") return "grad";

    return "undergrad";
}

void Student::writeToFile(std::ostream& out) const {
    out << "Name: " << firstName_ << ' ' << lastName_ << '\n';
    out << "GPA: " << std::fixed << std::setprecision(2) << gpa_ << '\n';
    out << "Graduation Year: " << graduationYear_ << '\n';
    out << "Graduation Semester: " << graduationSemester_ << '\n';
    out << "Enrolled Year: " << enrolledYear_ << '\n';
    out << "Enrolled Semester: " << enrolledSemester_ << '\n';
    out << "Level: " << level_ << '\n';
}
