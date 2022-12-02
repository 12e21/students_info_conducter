
#include "students_list.h"
#include "iostream"
//构造函数
Students_list::Students_list() {
    this->current_blank_index=0;
    this->total_length=100;
}
//析构函数
Students_list::~Students_list()=default;
//复制函数
void Students_list::students_copy(Student* dest_student_p, Student source_student) {
    (*dest_student_p).identity_id=source_student.identity_id;
    (*dest_student_p).phone_number=source_student.phone_number;
    (*dest_student_p).GPA=source_student.GPA;
    (*dest_student_p).discipline=source_student.discipline;
    (*dest_student_p).college=source_student.college;
    (*dest_student_p).name=source_student.name;
    (*dest_student_p).student_id=source_student.student_id;
}
//在末尾添加一个学生函数
void Students_list::add_single_student(int student_id, std::string name, std::string college, std::string discipline, float GPA,
                                       std::string phone_number, std::string identity_id){
this->student_list[current_blank_index].student_id=student_id;
this->student_list[current_blank_index].name=name;
this->student_list[current_blank_index].college=college;
this->student_list[current_blank_index].discipline=discipline;
this->student_list[current_blank_index].GPA=GPA;
this->student_list[current_blank_index].phone_number=phone_number;
this->student_list[current_blank_index].identity_id=identity_id;
this->current_blank_index++;
}
//清空指定索引学生信息
void Students_list::clear_single_student(int clear_index) {
    this->student_list[clear_index].student_id=0;
    this->student_list[clear_index].college='0';
    this->student_list[clear_index].discipline='0';
    this->student_list[clear_index].name="0";
    this->student_list[clear_index].GPA=0;
    this->student_list[clear_index].identity_id="0";
    this->student_list[clear_index].phone_number="0";
}
//删除指定索引学生函数
void Students_list::delet_single_student(int delete_index) {
    for(int i=0;i<(this->current_blank_index-delete_index-1);i++)
    {
        this->students_copy(&(this->student_list[delete_index+i]),this->student_list[delete_index+1+i]);
    }
    this->clear_single_student(current_blank_index-1);
    this->current_blank_index-=1;
}
//根据学号找索引
int Students_list::lookfor_index_from_studentID(int studentID) {
    int i=0;
    while(1)
    {
        if(this->student_list[i].student_id==studentID)
        {
            break;
        }
        else if(i==this->current_blank_index)
        {
            i=-1;
            break;
        }
        else
        {
            i++;
        }
    }
    return i;
}
