#include <iostream>
#include "UI.h"
int main()
{
    UI Test;
    Test.read_file_students_ui();
    Test.add_single_student_ui();
    Test.statistic_college_students_ui();
    Test.sort_GPA_ui();
    Test.write_all_students_ui();
}