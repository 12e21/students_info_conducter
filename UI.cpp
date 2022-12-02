
#include "UI.h"
#include <iostream>
UI::UI() {
    Students_list students_list;
}
UI::~UI() =default;

void UI::add_single_student_ui() {
    int student_id;
    std::string name;
    std::string college;
    std::string discipline;
    float GPA;
    std::string phone_number;
    std::string identity_id;
    std::cout<<"正在使用添加单一学生功能"<<std::endl;
    std::cout<<"请输入学号"<<std::endl;
    std::cin>>student_id;
    std::cout<<"请输入姓名"<<std::endl;
    std::cin>>name;
    std::cout<<"请输入学院"<<std::endl;
    std::cin>>college;
    std::cout<<"请输入专业"<<std::endl;
    std::cin>>discipline;
    std::cout<<"请输入GPA"<<std::endl;
    std::cin>>GPA;
    std::cout<<"请输入电话号码"<<std::endl;
    std::cin>>phone_number;
    std::cout<<"请输入身份证号"<<std::endl;
    std::cin>>identity_id;
    this->studentsList.add_single_student(student_id,name,college,discipline,GPA,phone_number,identity_id);
}
void UI::delete_single_student_ui() {
    int del_studentID=0;
    int del_index=0;
    std::cout<<"正在使用删除单一学生功能"<<std::endl;
    std::cout<<"请输入要删除的学生的学号"<<std::endl;
    std::cin>>del_studentID;
    del_index=this->studentsList.lookfor_index_from_studentID(del_studentID);
    while (del_index==-1)
    {
        std::cout<<"请确保您输入的学号有效"<<std::endl;
        std::cin>>del_studentID;
        del_index=this->studentsList.lookfor_index_from_studentID(del_studentID);
    }
    this->studentsList.delet_single_student(del_index);
    std::cout<<"已成功删除改学生"<<std::endl;
}

void UI::show_single_student(int show_index) {
    std::cout<<"学号: "<<this->studentsList.student_list[show_index].student_id<<std::endl;
    std::cout<<"姓名: "<<this->studentsList.student_list[show_index].name<<std::endl;
    std::cout<<"专业: "<<this->studentsList.student_list[show_index].discipline<<std::endl;
    std::cout<<"学院: "<<this->studentsList.student_list[show_index].college<<std::endl;
    std::cout<<"GPA: "<<this->studentsList.student_list[show_index].GPA<<std::endl;
    std::cout<<"电话: "<<this->studentsList.student_list[show_index].phone_number<<std::endl;
    std::cout<<"身份证号: "<<this->studentsList.student_list[show_index].identity_id<<std::endl;

}
void UI::show_single_student_ui() {
    int show_ID=0;
    int show_index=0;
    std::cout<<"正在使用显示单一学生功能"<<std::endl;
    std::cout<<"请输入要显示学生的学号"<<std::endl;
    std::cin>>show_ID;
    show_index=this->studentsList.lookfor_index_from_studentID(show_ID);
    while (show_index==-1)
    {
        std::cout<<"请确保您输入的学号有效"<<std::endl;
        std::cin>>show_ID;
        show_index=this->studentsList.lookfor_index_from_studentID(show_ID);
    }
    this->show_single_student(show_index);
}
void UI::show_all_student_ui()
{
    std::cout<<"正在使用显示所有学生信息功能"<<std::endl;
    for(int i=0;i<(this->studentsList.current_blank_index);i++)
    {
        show_single_student(i);
    }
}