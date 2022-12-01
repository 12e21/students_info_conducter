
//
// Created by www on 22-12-1.
//

#ifndef STUDENT_INFO_CONDUCT_UI_H
#define STUDENT_INFO_CONDUCT_UI_H
#include "students_list.h"

class UI {
private:
    Students_list studentsList;
public:
    UI();
    ~UI();
    void show_single_student_ui();
    void show_single_student(int show_index);
    void show_all_student_ui();
    void add_single_student_ui();
    void delete_single_student_ui();
};


#endif //STUDENT_INFO_CONDUCT_UI_H
