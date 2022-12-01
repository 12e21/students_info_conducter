
#ifndef STUDENT_INFO_CONDUCT_STUDENT_H
#define STUDENT_INFO_CONDUCT_STUDENT_H
#include <string>
class Student
{
private:
public:
    Student();
    ~Student();
    int student_id;
    std::string name;
    int college;
    int discipline;
    float GPA;
    std::string phone_number;
    std::string identity_id;

};

#endif //STUDENT_INFO_CONDUCT_STUDENT_H
