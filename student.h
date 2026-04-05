#ifndef STUDENT_H
#define STUDENT_H

#include <ostream>
#include <string>

class Student {
public:
    Student();
    Student(const std::string& firstName,
            const std::string& lastName,
            double gpa,
            int graduationYear,
            const std::string& graduationSemester,
            int enrolledYear,
            const std::string& enrolledSemester,
            const std::string& level);
    virtual ~Student();

    void setName(const std::string& firstName, const std::string& lastName);
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);

    void setGPA(double gpa);
    void setGPA(const std::string& gpaText);

    void setGraduationYear(int year);
    void setGraduationSemester(const std::string& semester);
    void setEnrolledYear(int year);
    void setEnrolledSemester(const std::string& semester);
    void setLevel(const std::string& level);

    std::string getFirstName() const;
    std::string getLastName() const;
    double getGPA() const;
    int getGraduationYear() const;
    std::string getGraduationSemester() const;
    int getEnrolledYear() const;
    std::string getEnrolledSemester() const;
    std::string getLevel() const;

    virtual void writeToFile(std::ostream& out) const;

protected:
    std::string firstName_;
    std::string lastName_;
    double gpa_;
    int graduationYear_;
    std::string graduationSemester_;
    int enrolledYear_;
    std::string enrolledSemester_;
    std::string level_;

    static std::string normalizeSemester(const std::string& semester);
    static std::string normalizeLevel(const std::string& level);
};

#endif
