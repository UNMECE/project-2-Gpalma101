#ifndef ART_STUDENT_H
#define ART_STUDENT_H

#include "Student.h"

class Art_Student : public Student {
public:
    Art_Student();
    Art_Student(const std::string& firstName,
                const std::string& lastName,
                double gpa,
                int graduationYear,
                const std::string& graduationSemester,
                int enrolledYear,
                const std::string& enrolledSemester,
                const std::string& level,
                const std::string& artEmphasis);
    ~Art_Student() override;

    void setArtEmphasis(const std::string& artEmphasis);
    std::string getArtEmphasis() const;

    void writeToFile(std::ostream& out) const override;

private:
    std::string artEmphasis_;

    static std::string normalizeArtEmphasis(const std::string& artEmphasis);
};

#endif
