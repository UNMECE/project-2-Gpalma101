#include "Art_Student.h"

#include <algorithm>
#include <cctype>

namespace {
std::string toLowerCopyArt(const std::string& text) {
    std::string result = text;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return result;
}
}

Art_Student::Art_Student()
    : Student(),
      artEmphasis_("Art Studio") {}

Art_Student::Art_Student(const std::string& firstName,
                         const std::string& lastName,
                         double gpa,
                         int graduationYear,
                         const std::string& graduationSemester,
                         int enrolledYear,
                         const std::string& enrolledSemester,
                         const std::string& level,
                         const std::string& artEmphasis)
    : Student(firstName, lastName, gpa, graduationYear, graduationSemester,
              enrolledYear, enrolledSemester, level),
      artEmphasis_(normalizeArtEmphasis(artEmphasis)) {}

Art_Student::~Art_Student() = default;

void Art_Student::setArtEmphasis(const std::string& artEmphasis) {
    artEmphasis_ = normalizeArtEmphasis(artEmphasis);
}

std::string Art_Student::getArtEmphasis() const {
    return artEmphasis_;
}

std::string Art_Student::normalizeArtEmphasis(const std::string& artEmphasis) {
    std::string text = toLowerCopyArt(artEmphasis);

    if (text == "art studio") return "Art Studio";
    if (text == "art history") return "Art History";
    if (text == "art education") return "Art Education";

    return "Art Studio";
}

void Art_Student::writeToFile(std::ostream& out) const {
    out << "Student Type: Art Student\n";
    Student::writeToFile(out);
    out << "Art Emphasis: " << artEmphasis_ << '\n';
    out << "----------------------------------------\n";
}
