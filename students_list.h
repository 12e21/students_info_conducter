

#ifndef STUDENT_INFO_CONDUCT_STUDENTS_LIST_H
#define STUDENT_INFO_CONDUCT_STUDENTS_LIST_H
#include "student.h"
#include "fstream"
#include "stdlib.h"

class Students_list{
private:
public:
    int current_blank_index;
    int total_length;
    Student student_list[100];
    Students_list();
    ~Students_list();
    void add_single_student(int student_id,std::string name,std::string college,std::string discipline,
                            float GPA,std::string phone_number,std::string identity_id);
    void clear_single_student(int clear_index);
    void delet_single_student(int delete_index);
    void students_copy(Student* dest_student_p,Student source_student);
    int lookfor_index_from_studentID(int studentID);
    void write_single_student(std::ofstream* outfile_p,int student_index);
    void write_all_students(std::string file_path);
    void read_single_student(std::ifstream* infile_p);
    void read_all_students(std::string file_path);
};

#endif //STUDENT_INFO_CONDUCT_STUDENTS_LIST_H
