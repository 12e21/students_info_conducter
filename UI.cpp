
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
    std::cout<<std::endl;

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
void UI::write_all_students_ui() {
    std::string file_path;
    std::cout<<"正在使用将全部学生信息导出为文件功能"<<std::endl;
    std::cout<<"请输入导出文件路径"<<std::endl;
    std::cin>>file_path;
    this->studentsList.write_all_students(file_path);
    std::cout<<"导出成功"<<std::endl;
}
void UI::read_file_students_ui() {
    std::string file_path;
    std::cout<<"正在使用将学生信息文件导入功能"<<std::endl;
    std::cout<<"请输入导入文件的路径"<<std::endl;
    std::cin>>file_path;
    this->studentsList.read_all_students(file_path);
    std::cout<<"导入成功"<<std::endl;
}
void UI::change_single_student_ui() {
    int student_id=0;
    int change_index=0;
    std::string name;
    std::string college;
    std::string discipline;
    float GPA;
    std::string phone_number;
    std::string identity_id;

    std::cout<<"正在使用修改单个学生信息功能"<<std::endl;
    std::cout<<"请输入要修改的学生的学号"<<std::endl;
    std::cin>>student_id;
    change_index=this->studentsList.lookfor_index_from_studentID(student_id);
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
    this->studentsList.change_single_student(change_index,student_id,name,college,
                                             discipline,GPA,phone_number,identity_id);
    std::cout<<"修改成功"<<std::endl;

}
void UI::statistic_college_students_ui() {
    std::string college;
    int college_students_ids[100]={0};
    int college_students_count=0;
    std::cout<<"正在使用统计某学院学生人数及学号功能"<<std::endl;
    std::cout<<"请输入要统计的学院:"<<std::endl;
    std::cin>>college;
    this->studentsList.statistic_college(college,&college_students_count,
                                         college_students_ids);
    std::cout<<college<<"共有"<<college_students_count<<"人"<<std::endl;
    std::cout<<"学号如下:"<<std::endl;
    for(int i=0;i<college_students_count;i++)
    {
        std::cout<<*(college_students_ids+i)<<std::endl;
    }
    std::cout<<"统计完毕"<<std::endl;
}
void UI::sort_GPA_ui() {
    int sort_students_count=0;
    int sort_student_ids[100];
    std::cout<<"正在使用按GPA排序功能"<<std::endl;
    this->studentsList.sort_GPA(sort_student_ids,&sort_students_count);
    std::cout<<"以下学号按GPA由高到低排列"<<std::endl;
    for(int i=0;i<sort_students_count;i++)
    {
        std::cout<<sort_student_ids[i]<<std::endl;
    }
    std::cout<<"排序完成"<<std::endl;

}

void UI::main_program_ui() {
    std::cout<<"欢迎使用学生信息管理系统"<<std::endl;
    while (true)
    {
        int user_choice=0;
        std::cout<<"请选择功能:"<<std::endl;
        std::cout<<"0. "<<"退出"<<std::endl;
        std::cout<<"1. "<<"添加单个学生信息"<<std::endl;
        std::cout<<"2. "<<"删除单个学生信息"<<std::endl;
        std::cout<<"3. "<<"显示单个学生信息"<<std::endl;
        std::cout<<"4. "<<"显示全部学生信息"<<std::endl;
        std::cout<<"5. "<<"修改单个学生信息"<<std::endl;
        std::cout<<"6. "<<"统计某个学院的学生"<<std::endl;
        std::cout<<"7. "<<"将学生按GPA排序"<<std::endl;
        std::cout<<"8. "<<"把当前学生信息存入文件"<<std::endl;
        std::cout<<"9. "<<"将学生信息文件读入系统"<<std::endl;
        std::cin>>user_choice;
        switch (user_choice) {
            case 0:
                return;
            case 1:
                this->add_single_student_ui();
                break;
            case 2:
                this->delete_single_student_ui();
                break;
            case 3:
                this->show_single_student_ui();
                break;
            case 4:
                this->show_all_student_ui();
                break;
            case 5:
                this->change_single_student_ui();
                break;
            case 6:
                this->statistic_college_students_ui();
                break;
            case 7:
                this->sort_GPA_ui();
                break;
            case 8:
                this->write_all_students_ui();
                break;
            case 9:
                this->read_file_students_ui();
                break;
        }
    }
}