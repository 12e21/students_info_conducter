
#include "students_list.h"
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
//将单一学生信息写入文件
void Students_list::write_single_student(std::ofstream *outfile_p,int student_index) {
    *outfile_p<<this->student_list[student_index].student_id<<std::endl;
    *outfile_p<<this->student_list[student_index].name<<std::endl;
    *outfile_p<<this->student_list[student_index].discipline<<std::endl;
    *outfile_p<<this->student_list[student_index].college<<std::endl;
    *outfile_p<<this->student_list[student_index].GPA<<std::endl;
    *outfile_p<<this->student_list[student_index].phone_number<<std::endl;
    *outfile_p<<this->student_list[student_index].identity_id<<std::endl;
}
//将全部学生信息写入文件
void Students_list::write_all_students(std::string file_path) {
    std::ofstream outfile;
    outfile.open(file_path,std::ios::out |std::ios::trunc);
    outfile<<this->current_blank_index<<std::endl;
    for(int i=0;i<current_blank_index;i++)
    {
        this->write_single_student(&outfile,i);
    }
    outfile.close();
}
//从文件导入单一学生信息到程序
void Students_list::read_single_student(std::ifstream *infile_p) {
    int student_id;
    std::string name;
    std::string college;
    std::string discipline;
    float GPA;
    std::string phone_number;
    std::string identity_id;
    *infile_p>>student_id;
    *infile_p>>name;
    *infile_p>>discipline;
    *infile_p>>college;
    *infile_p>>GPA;
    *infile_p>>phone_number;
    *infile_p>>identity_id;
    this->add_single_student(student_id,name,college,discipline,GPA,phone_number,identity_id);
}
//从文件导入所有学生信息到程序
void Students_list::read_all_students(std::string file_path) {
    std::ifstream infile;
    infile.open(file_path,std::ios::in);
    int total_students_count=0;
    infile>>total_students_count;
    for(int i=0;i<total_students_count;i++)
    {
        read_single_student(&infile);
    }
    infile.close();
}
//修改单个学生
void Students_list::change_single_student(int change_index,int student_id, std::string name,
                                          std::string college, std::string discipline, float GPA,
                                          std::string phone_number, std::string identity_id) {
    this->student_list[change_index].student_id=student_id;
    this->student_list[change_index].name=name;
    this->student_list[change_index].college=college;
    this->student_list[change_index].discipline=discipline;
    this->student_list[change_index].GPA=GPA;
    this->student_list[change_index].phone_number=phone_number;
    this->student_list[change_index].identity_id=identity_id;

}