#ifndef PHYSICS_STUDENT_H
#define PHYSICS_STUDENT_H

#include "Student.h"

class Physics_Student : public Student {
public:
    Physics_Student();
    Physics_Student(const std::string& firstName,
                    const std::string& lastName,
                    double gpa,
                    int graduationYear,
                    const std::string& graduationSemester,
                    int enrolledYear,
                    const std::string& enrolledSemester,
                    const std::string& level,
                    const std::string& concentration);
    ~Physics_Student() override;

    void setConcentration(const std::string& concentration);
    std::string getConcentration() const;

    void writeToFile(std::ostream& out) const override;

private:
    std::string concentration_;

    static std::string normalizeConcentration(const std::string& concentration);
};

#endif
