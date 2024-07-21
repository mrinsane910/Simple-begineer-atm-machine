#include <string.h>
#include <iostream>
#include <vector>

class studentsystem
{
protected:
    struct Student
    {
        std::string name{};
        std::string dept{};
        std::string program{};
        std::string semester{};
        std::string CGPA{};
        std::string rollno{};
        std::string gender{};
        bool deletionStatus{false};
    };

public:
    std::vector<Student> students;
    void addstudent()
    {
        Student s;

        std::cout << "Enter Name: ";
        std::cin >> s.name;
        std::cout << "Enter Program: ";
        std::cin >> s.program;
        std::cout << "Enter Semester: ";
        std::cin >> s.semester;
        std::cout << "Enter CGPA: ";
        std::cin >> s.CGPA;
        std::cout << "Enter Rollno: ";
        std::cin >> s.rollno;
        std::cout << "Enter Gender: ";
        std::cin >> s.gender;
        students.push_back(s);

        std::cout << "New Student Added In The Database!\n";
    }

    void ShowStudentData()
    {
        if (!students.empty())
        {
            std::string roll{};
            std::cout << "Enter Roll No: ";
            std::cin >> roll;

            bool found = false;
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].rollno == roll && students[i].deletionStatus == false)
                {
                    std::cout << "----------Student Details----------" << std::endl;

                    std::cout << "Name: " << students[i].name << std::endl;
                    std::cout << "Department: " << students[i].dept << std::endl;
                    std::cout << "Program: " << students[i].program << std::endl;
                    std::cout << "Semester: " << students[i].semester << std::endl;
                    std::cout << "CGPA: " << students[i].CGPA << std::endl;
                    std::cout << "Roll No: " << students[i].rollno << std::endl;
                    std::cout << "Gender: " << students[i].gender << std::endl;
                    found = true;
                    break;
                }
                else if (students[i].rollno == roll && students[i].deletionStatus)
                {
                    std::cout << "The Student No Longer Exists in the DataBase! " << std::endl;
                    break;
                }
            }
        }
        else
            std::cout << "Database Is Empty!" << std::endl;
    }
    void DeleteStudentData()
    {
        if (!students.empty())
        {
            std::string roll{};
            std::cout << "Enter Roll No: ";
            std::cin >> roll;

            bool found = false;
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].rollno == roll && students[i].deletionStatus == false)
                {
                    students[i].deletionStatus = true;
                    found = true;
                    break;
                }
                else if (students[i].deletionStatus == true && students[i].rollno == roll)
                {
                    std::cout << std::endl;
                    std::cout << "The Student Already Does not Exist! " << std::endl;
                    break;
                }
            }
            if (found)
            {
                std::cout << std::endl;
                std::cout << "Student With Roll Number " << roll << " Deleted From Database!" << std::endl;
            }
            else
                std::cout << "No Student With Roll Number " << roll << " Found In Database!" << std::endl;
        }
        else
            std::cout << "Database Is Empty!" << std::endl;
    }

    static void showdetailMenu()
    {
        std::cout << "Which Member Do You Want To Modify? " << std::endl;
        std::cout << "1. Name" << std::endl;
        std::cout << "2. Program" << std::endl;
        std::cout << "3. Semester" << std::endl;
        std::cout << "4. CGPA" << std::endl;
        std::cout << "5. Roll No" << std::endl;
        std::cout << "6. Gender" << std::endl;
        std::cout << "7. All Of These" << std::endl;
        std::cout << "8 .Exit " << std::endl;
    }
    void UpdateStudentData()
    {
        if (!students.empty())
        {
            std::string roll{};
            std::cout << "Enter Roll No: ";
            std::cin >> roll;

            bool found = false;
            int StudentIndex = -1;
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].rollno == roll && students[i].deletionStatus == false)
                {
                    found = true;
                    StudentIndex = i;
                    break;
                }
                else if (students[i].deletionStatus == true && students[i].rollno == roll)
                {
                    std::cout << "The Student Already Does not Exist! " << std::endl;
                    break;
                }
            }

            if (!found)
            {
                std::cerr << "No Student with roll number " << roll << " found." << std::endl;
            }
            else
            {
                studentsystem::showdetailMenu();
                int choice{};
                std::cout << "Enter Your Choice" << std::endl;
                std::cin >> choice;
                switch (choice)
                {
                case 1:

                    std::cout << "Enter New Name: ";
                    std::cin >> students[StudentIndex].name;
                    std::cout << std::endl;
                    std::cout << "----------Student Name Updated Successfully!----------" << std::endl;
                    break;

                case 2:

                    std::cout << "Enter New Program: ";
                    std::cin >> students[StudentIndex].program;
                    std::cout << std::endl;
                    std::cout << "----------Student Program Updated Successfully!----------" << std::endl;
                    break;

                case 3:

                    std::cout << "Enter New Semester: ";
                    std::cin >> students[StudentIndex].semester;
                    std::cout << std::endl;
                    std::cout << "----------Student Semester Updated Successfully!----------" << std::endl;
                    break;

                case 4:

                    std::cout << "Enter New CGPA: ";
                    std::cin >> students[StudentIndex].CGPA;
                    std::cout << std::endl;
                    std::cout << "----------Student CGPA Updated Successfully!----------" << std::endl;
                    break;

                case 5:

                    std::cout << "Enter New Roll No: ";
                    std::cin >> students[StudentIndex].rollno;
                    std::cout << std::endl;
                    std::cout << "----------Student Roll No Updated Successfully!----------" << std::endl;
                    break;

                case 6:

                    std::cout << "Enter New Gender: ";
                    std::cin >> students[StudentIndex].gender;
                    std::cout << std::endl;
                    std::cout << "----------Student Gender Updated Successfully!----------" << std::endl;
                    break;

                case 7:

                    std::cout << "Enter New Name: ";
                    std::cin >> students[StudentIndex].name;
                    std::cout << "Enter New Program: ";
                    std::cin >> students[StudentIndex].program;
                    std::cin.ignore();
                    std::cout << "Enter New Semester: ";
                    std::cin >> students[StudentIndex].semester;
                    std::cout << "Enter New CGPA: ";
                    std::cin >> students[StudentIndex].CGPA;
                    std::cout << "Enter New Roll No: ";
                    std::cin >> students[StudentIndex].rollno;
                    std::cout << "Enter New Gender: ";
                    std::cin >> students[StudentIndex].gender;
                    std::cout << std::endl;
                    std::cout << "----------Student Details Updated Successfully!----------" << std::endl;
                    break;

                case 8:

                    std::cout << "Exiting..." << std::endl;
                    break;
                }
            }
        }
        else
            std::cerr << "Database Is Empty!" << std::endl;
    }
    void TransferData()
    {
        if (!students.empty())
        {
            std::string roll{};
            std::cout << "Enter Roll No: ";
            std::cin >> roll;

            bool found = false;
            int StudentIndex = -1;
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].rollno == roll && students[i].deletionStatus == false)
                {
                    found = true;
                    StudentIndex = i;
                    break;
                }
                else if (students[i].deletionStatus == true && students[i].rollno == roll)
                {
                    std::cout << "The Student Does not Exist! " << std::endl;
                    break;
                }
            }
            if (found)
            {
                std::cout << "Enter New Department: ";
                std::cin >> students[StudentIndex].dept;
                std::cout << std::endl;

                std::cout << "Enter New Program: ";
                std::cin >> students[StudentIndex].program;
                std::cout << std::endl;

                std::cout << "Enter New Semester: ";
                std::cin >> students[StudentIndex].semester;
                std::cout << std::endl;

                std::cout << "----------Student Transfered Successfully!----------" << std::endl;
            }
        }
        else
            std::cerr << "Database Is Empty!" << std::endl;
    }

    // studentsystem() : students() {}
};

class IT : public studentsystem
{
public:
    void addstudent() {}
};

class BBA : public studentsystem
{

public:
    void addstudent() {}
};

class English : public studentsystem
{

public:
    void addstudent() {}
};

class Urdu : public studentsystem
{

public:
    void addstudent() {}
};

class Chemistry : public studentsystem
{

public:
    void addstudent() {}
};

class BioTechnology : public studentsystem
{

public:
    void addstudent() {}
};

class AnimalScience : public studentsystem
{

public:
    void addstudent() {}
};

class Astrology : public studentsystem
{

public:
    void addstudent() {}
};

class Arts : public studentsystem
{

public:
    void addstudent() {}
};

class Meterology : public studentsystem
{

public:
    void addstudent() {}
};

class History : public studentsystem
{

public:
    void addstudent() {}
};
class Mathematics : public studentsystem
{

public:
    void addstudent() {}
};
class Physics : public studentsystem
{
public:
    void addstudent() {}
};
class Agriculture : public studentsystem
{
public:
    void addstudent() {}
};
class Engineering : public studentsystem
{
public:
    void addstudent() {}
};
class Mas_Com : public studentsystem
{
public:
    void addstudent() {}
};

void showmenu()
{
    std::cout << "-------------Welcome to Univeristy of Sargodha!-------------" << '\n';
    std::cout << "1.Add Student  Data " << '\n';
    std::cout << "2.Delete Student Data " << '\n';
    std::cout << "3.Update Student Data " << '\n';
    std::cout << "4.Display Student Data " << '\n';
    std::cout << "5.Transfer Student Data " << '\n';
    std::cout << "6.Exit " << '\n';
}

void showdepartments()
{
    std::cout << "-------------Departments-------------" << '\n';

    std::cout << "\t\t 1.IT \n\t\t2.Mas.Com \n\t\t3.BBA  \n\t\t4.Physics \n\t\t5.Chemistry \n\t\t6.BioTechnology \n\t\t7.Engineering \n\t\t8.Urdu \n\t\t9.Mathematics \n\t\t10.History \n\t\t11.Agriculture \n\t\t12.English \n\t\t13.Animal Sciences \n\t\t14.Meterology \n\t\t15.Arts \n\t\t16.Astrology" << '\n';
}

int main()
{
    int choice{};
    int dept{};
    studentsystem *ptr;
    IT it;
    BBA bba;
    Mas_Com mascom;
    Physics physics;
    Chemistry chemistry;
    BioTechnology bio;
    Urdu urdu;
    Mathematics math;
    History history;
    Agriculture agri;
    English eng;
    AnimalScience animal;
    Meterology mete;
    Arts arts;
    Astrology astro;
    Engineering engr;

    do
    {
        system("cls");
        showmenu();
        std::cout << "Enter Your Choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");

            showdepartments();

            std::cout << "Choose Your Department: ";
            std::cin >> dept;

            if (dept == 1)
            {
                ptr = &it;
                ptr->addstudent();
                system("pause");
            }

            else if (dept == 2)
            {
                ptr = &mascom;
                ptr->addstudent();
                system("pause");
            }

            else if (dept == 3)
            {
                ptr = &bba;
                ptr->addstudent();
                system("pause");
            }

            else if (dept == 4)
            {
                ptr = &physics;
                ptr->addstudent();
                system("pause");
            }

            else if (dept == 5)
            {
                ptr = &chemistry;
                ptr->addstudent();
                system("pause");
            }

            else if (dept == 6)
            {
                ptr = &bio;
                ptr->addstudent();

                system("pause");
            }
            else if (dept == 7)
            {
                ptr = &engr;
                ptr->addstudent();
                system("pause");
            }

            else if (dept == 8)
            {
                ptr = &urdu;
                ptr->addstudent();
                system("pause");
            }

            else if (dept == 9)
            {
                ptr = &math;
                ptr->addstudent();
                system("pause");
            }

            else if (dept == 10)
            {
                ptr = &history;
                ptr->addstudent();
                system("pause");
            }

            else if (dept == 11)
            {
                ptr = &agri;
                ptr->addstudent();
                system("pause");
            }

            else if (dept == 12)
            {
                ptr = &eng;
                ptr->addstudent();
                system("pause");
            }

            else if (dept == 13)
            {
                ptr = &animal;
                ptr->addstudent();
                system("pause");
            }
            else if (dept == 14)
            {
                ptr = &mete;
                ptr->addstudent();
                system("pause");
            }

            else if (dept == 15)
            {
                ptr = &arts;
                ptr->addstudent();
                system("pause");
            }

            else if (dept == 16)
            {
                ptr = &astro;
                ptr->addstudent();
                system("pause");
            }

            else
            {
                std::cerr << "Inavlid department: " << std::endl;
                system("pause");
            }
            break;

        case 2:
            showdepartments();

            std::cout << "Choose Your Department: ";
            std::cin >> dept;

            if (dept == 1)
            {
                ptr = &it;
                ptr->DeleteStudentData();
                system("pause");
            }

            else if (dept == 2)
            {
                ptr = &mascom;
                ptr->DeleteStudentData();
                system("pause");
            }

            else if (dept == 3)
            {
                ptr = &bba;
                ptr->DeleteStudentData();
                system("pause");
            }

            else if (dept == 4)
            {
                ptr = &physics;
                ptr->DeleteStudentData();
                system("pause");
            }

            else if (dept == 5)
            {
                ptr = &chemistry;
                ptr->DeleteStudentData();
                system("pause");
            }

            else if (dept == 6)
            {
                ptr = &bio;
                ptr->DeleteStudentData();
                system("pause");
            }

            else if (dept == 7)
            {
                ptr = &engr;
                ptr->DeleteStudentData();
                system("pause");
            }

            else if (dept == 8)
            {
                ptr = &urdu;
                ptr->DeleteStudentData();
                system("pause");
            }

            else if (dept == 9)
            {
                ptr = &math;
                ptr->DeleteStudentData();
                system("pause");
            }

            else if (dept == 10)
            {
                ptr = &history;
                ptr->DeleteStudentData();
                system("pause");
            }

            else if (dept == 11)
            {
                ptr = &agri;
                ptr->DeleteStudentData();
                system("pause");
            }

            else if (dept == 12)
            {
                ptr = &eng;
                ptr->DeleteStudentData();
                system("pause");
            }

            else if (dept == 13)
            {
                ptr = &animal;
                ptr->DeleteStudentData();
                system("pause");
            }

            else if (dept == 14)
            {
                ptr = &mete;
                ptr->DeleteStudentData();
                system("pause");
            }

            else if (dept == 15)
            {
                ptr = &arts;
                ptr->DeleteStudentData();
                system("pause");
            }

            else if (dept == 16)
            {
                ptr = &astro;
                ptr->DeleteStudentData();
                system("pause");
            }

            else
            {
                std::cerr << "Invalid dept: " << std::endl;
                system("pause");
            }
            break;
        case 3:
            system("cls");

            showdepartments();
            std::cout << "Choose Your Department: ";
            std::cin >> dept;

            if (dept == 1)
            {
                ptr = &it;
                ptr->UpdateStudentData();
                system("pause");
            }

            else if (dept == 2)
            {
                ptr = &mascom;
                ptr->UpdateStudentData();
                system("pause");
            }

            else if (dept == 3)
            {
                ptr = &bba;
                ptr->UpdateStudentData();
                system("pause");
            }

            else if (dept == 4)
            {
                ptr = &physics;
                ptr->UpdateStudentData();
                system("pause");
            }

            else if (dept == 5)
            {
                ptr = &chemistry;
                ptr->UpdateStudentData();
                system("pause");
            }

            else if (dept == 6)
            {
                ptr = &bio;
                ptr->UpdateStudentData();
                system("pause");
            }

            else if (dept == 7)
            {
                ptr = &engr;
                ptr->UpdateStudentData();
                system("pause");
            }

            else if (dept == 8)
            {
                ptr = &urdu;
                ptr->UpdateStudentData();
                system("pause");
            }

            else if (dept == 9)
            {
                ptr = &math;
                ptr->UpdateStudentData();
                system("pause");
            }

            else if (dept == 10)
            {
                ptr = &history;
                ptr->UpdateStudentData();
                system("pause");
            }

            else if (dept == 11)
            {
                ptr = &agri;
                ptr->UpdateStudentData();
                system("pause");
            }

            else if (dept == 12)
            {
                ptr = &eng;
                ptr->UpdateStudentData();
                system("pause");
            }

            else if (dept == 13)
            {
                ptr = &animal;
                ptr->UpdateStudentData();
                system("pause");
            }

            else if (dept == 14)
            {
                ptr = &mete;
                ptr->UpdateStudentData();
                system("pause");
            }

            else if (dept == 15)
            {
                ptr = &arts;
                ptr->UpdateStudentData();
                system("pause");
            }

            else if (dept == 16)
            {
                ptr = &astro;
                ptr->UpdateStudentData();
                system("pause");
            }

            else
            {
                std::cerr << "Invalid dept: " << std::endl;
                system("pause");
            }
            break;

        case 4:
            system("cls");
            showdepartments();
            std::cout << "Choose Your Department: ";
            std::cin >> dept;

            if (dept == 1)
            {
                ptr = &it;
                ptr->ShowStudentData();
                system("pause");
            }

            else if (dept == 2)
            {
                ptr = &mascom;
                ptr->ShowStudentData();
                system("pause");
            }

            else if (dept == 3)
            {
                ptr = &bba;
                ptr->ShowStudentData();
                system("pause");
            }

            else if (dept == 4)
            {
                ptr = &physics;
                ptr->ShowStudentData();
                system("pause");
            }

            else if (dept == 5)
            {
                ptr = &chemistry;
                ptr->ShowStudentData();
                system("pause");
            }

            else if (dept == 6)
            {
                ptr = &bio;
                ptr->ShowStudentData();
                system("pause");
            }

            else if (dept == 7)
            {
                ptr = &engr;
                ptr->ShowStudentData();
                system("pause");
            }

            else if (dept == 8)
            {
                ptr = &urdu;
                ptr->ShowStudentData();
                system("pause");
            }

            else if (dept == 9)
            {
                ptr = &math;
                ptr->ShowStudentData();
                system("pause");
            }

            else if (dept == 10)
            {
                ptr = &history;
                ptr->ShowStudentData();
                system("pause");
            }

            else if (dept == 11)
            {
                ptr = &agri;
                ptr->ShowStudentData();
                system("pause");
            }

            else if (dept == 12)
            {
                ptr = &eng;
                ptr->ShowStudentData();
                system("pause");
            }

            else if (dept == 13)
            {
                ptr = &animal;
                ptr->ShowStudentData();
                system("pause");
            }

            else if (dept == 14)
            {
                ptr = &mete;
                ptr->ShowStudentData();
                system("pause");
            }

            else if (dept == 15)
            {
                ptr = &arts;
                ptr->ShowStudentData();
                system("pause");
            }

            else if (dept == 16)
            {
                ptr = &astro;
                ptr->ShowStudentData();
                system("pause");
            }

            else
            {
                std::cout << "Invalid dept: " << std::endl;
                system("pause");
            }
            break;

        case 6:
            system("cls");
            std::cerr << "Exiting...!" << std::endl;

            break;

        default:
            std::cerr << "Invalid choice: " << std::endl;
            system("pause");
            break;

        case 5:
            system("cls");
            showdepartments();
            std::cout << "Choose Your Department: ";
            std::cin >> dept;

            if (dept == 1)
            {
                ptr = &it;
                ptr->TransferData();
                system("pause");
            }
            else if (dept == 2)
            {
                ptr = &mascom;
                ptr->TransferData();
                system("pause");
            }
            else if (dept == 3)
            {
                ptr = &bba;
                ptr->TransferData();
                system("pause");
            }
            else if (dept == 4)
            {
                ptr = &physics;
                ptr->TransferData();
                system("pause");
            }
            else if (dept == 5)
            {
                ptr = &chemistry;
                ptr->TransferData();
                system("pause");
            }
            else if (dept == 6)
            {
                ptr = &bio;
                ptr->TransferData();
                system("pause");
            }
            else if (dept == 7)
            {
                ptr = &engr;
                ptr->TransferData();
                system("pause");
            }
            else if (dept == 8)
            {
                ptr = &urdu;
                ptr->TransferData();
                system("pause");
            }
            else if (dept == 9)
            {
                ptr = &math;
                ptr->TransferData();
                system("pause");
            }
            else if (dept == 10)
            {
                ptr = &history;
                ptr->TransferData();
                system("pause");
            }
            else if (dept == 11)
            {
                ptr = &agri;
                ptr->TransferData();
                system("pause");
            }
            else if (dept == 12)
            {
                ptr = &eng;
                ptr->TransferData();
                system("pause");
            }
            else if (dept == 13)
            {
                ptr = &animal;
                ptr->TransferData();
                system("pause");
            }
            else if (dept == 14)
            {
                ptr = &mete;
                ptr->TransferData();
                system("pause");
            }
            else if (dept == 15)
            {
                ptr = &arts;
                ptr->TransferData();
                system("pause");
            }
            else if (dept == 16)
            {
                ptr = &astro;
                ptr->TransferData();
                system("pause");
            }
            else
            {
                std::cerr << "Invalid dept: " << std::endl;
                system("pause");
            }
            break;
        }
    } while (choice != 6);
    return 0;
}