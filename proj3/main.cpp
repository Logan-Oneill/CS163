#include "table.h"

/*
    Course();
    ~Course();
    int create_course();
    int copy_course(const Course &copyFrom);
    int display_course();

    char * courseNum;
    char * courseName;
    int sectionNum;
    int CRN;
    char * courseSched;
    char * courseDesc;
*/

int main()
{
    Course myCourse;
    myCourse.create_course();
    myCourse.display_course();
    
    Course aCourse;

    Table myTable;
    myTable.insert(myCourse);
    char * temp = new char[50];
    strcpy(temp, "55");
    if(myTable.retrieveByNum(temp, aCourse)) cout << endl << "Found!" << endl;
    else cout << "not found" << endl;
    
    aCourse.display_course();

    
    return 0;
}