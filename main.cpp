//Heaser files
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//Base class stores information shared by all students
class Student
{

//Varibles that store information shared by all students
protected:
    string first_name;
    string last_name;
    double gpa;
    int grad_year;
    string grad_semester;
    int enroll_year;
    string enroll_semester;
    string student_level;

public:
//Sets default values for a new student
    Student()
    {
        first_name = "Unknown";
        last_name = "Unknown";
        gpa = 0.0;
        grad_year = 0;
        grad_semester = "Unknown";
        enroll_year = 0;
        enroll_semester = "Unknown";
        student_level = "Undergraduate";
    }


//Destructor for the Student class
    virtual ~Student()
    {
    }

    void setName(string first, string last)
    {
        first_name = first;
        last_name = last;
    }

    void setGPA(double value)
    {
        if (value >= 0.0 && value <= 4.0)
            gpa = value;
    }

    void setGradYear(int year)
    {
        grad_year = year;
    }

    void setGradSemester(string semester)
    {
        grad_semester = semester;
    }

    void setEnrollYear(int year)
    {
        enroll_year = year;
    }

    void setEnrollSemester(string semester)
    {
        enroll_semester = semester;
    }

    void setStudentLevel(string level)
    {
        if (level == "Undergraduate" || level == "Graduate")
            student_level = level;
    }

//Functions used to retrive student information 
    string getName()
    {
        return first_name + " " + last_name;
    }

    double getGPA()
    {
        return gpa;
    }

    int getGradYear()
    {
        return grad_year;
    }

    string getGradSemester()
    {
        return grad_semester;
    }

    int getEnrollYear()
    {
        return enroll_year;
    }

    string getEnrollSemester()
    {
        return enroll_semester;
    }

    string getStudentLevel()
    {
        return student_level;
    }
};

//Derived class adds art emphasis to student information
class Art_Student : public Student
{
private:
    string art_emphasis;

public:
    Art_Student()
    {
        art_emphasis = "Art Studio";
    }

    ~Art_Student()
    {
    }

//Allows the three art emphasis options 
    void setArtEmphasis(string emphasis)
    {
        if (emphasis == "Art Studio" ||
            emphasis == "Art History" ||
            emphasis == "Art Education")
        {
            art_emphasis = emphasis;
        }
    }

    string getArtEmphasis()
    {
        return art_emphasis;
    }
};

//Class that adds a physics concentration
class Physics_Student : public Student
{
private:
    string concentration;

public:
//Sets the default physics concentration
    Physics_Student()
    {
        concentration = "Biophysics";
    }

    ~Physics_Student()
    {
    }
// Only allows the two physics concentration options 
    void setConcentration(string value)
    {
        if (value == "Biophysics" ||
            value == "Earth and Planetary Sciences")
{
            concentration = value;
        }
    }

    string getConcentration()
    {
        return concentration;
    }
};

//Main function
//Student objects are created and stored 
int main()
{
//Vectors used to store pointers to each type of student 
    vector<Art_Student*> art_students;
    vector<Physics_Student*> physics_students;

//Information that will be assigned to the students
    string art_first[5] = {
        "DJ", "Rafael", "Thomas", "Emily", "Aiden"
    };

    string art_last[5] = {
        "Jaramillo", "Mercado", "Bennett", "Torres", "Martinez"
    };

    double art_gpa[5] = {
        3.7, 3.9, 3.2, 3.5, 3.9
    };

    string art_emphasis[5] = {
        "Art Studio",
        "Art History",
        "Art Education",
        "Art Studio",
        "Art History"
    };

    string physics_first[5] = {
        "Leroy", "Paige", "Harley", "Coco", "Benito"
    };

    string physics_last[5] = {
        "Vasquez", "Vasquez", "Jaramillo", "Chavez", "Martinez"
    };

    double physics_gpa[5] = {
        3.6, 3.8, 3.4, 3.9, 3.5
    };

    string physics_concentration[5] = {
        "Biophysics",
        "Earth and Planetary Sciences",
        "Biophysics",
        "Earth and Planetary Sciences",
        "Biophysics"
    };

    // Create and assign Art students
    for (int i = 0; i < 5; i++)
    {
        Art_Student* student = new Art_Student;

        student->setName(art_first[i], art_last[i]);
        student->setGPA(art_gpa[i]);
        student->setGradYear(2027 + (i % 3));
        student->setGradSemester(i % 2 == 0 ? "Spring" : "Fall");
        student->setEnrollYear(2023 + (i % 3));
        student->setEnrollSemester("Fall");
        student->setStudentLevel(i == 4 ? "Graduate" : "Undergraduate");
        student->setArtEmphasis(art_emphasis[i]);

        art_students.push_back(student);
    }

    // Create and assign Physics students
    for (int i = 0; i < 5; i++)
    {
        Physics_Student* student = new Physics_Student;

        student->setName(physics_first[i], physics_last[i]);
        student->setGPA(physics_gpa[i]);
        student->setGradYear(2027 + (i % 3));
        student->setGradSemester(i % 2 == 0 ? "Fall" : "Spring");
        student->setEnrollYear(2022 + (i % 4));
        student->setEnrollSemester(i % 2 == 0 ? "Fall" : "Spring");
        student->setStudentLevel(i < 3 ? "Undergraduate" : "Graduate");
        student->setConcentration(physics_concentration[i]);

        physics_students.push_back(student);
    }

//open the file to save srudent information
    ofstream outfile("student_info.dat");

//check the file
    if (!outfile.is_open())
    {
        cout << "Unable to open output file." << endl;

        for (int i = 0; i < art_students.size(); i++)
            delete art_students[i];

        for (int i = 0; i < physics_students.size(); i++)
            delete physics_students[i];

        return 1;
    }

    outfile << "ART STUDENTS" << endl;
    outfile << "========================" << endl;

//Write all the art student information to the file 
    for (int i = 0; i < art_students.size(); i++)
    {
        outfile << "Student " << i + 1 << endl;
        outfile << "Name: " << art_students[i]->getName() << endl;
        outfile << "GPA: " << art_students[i]->getGPA() << endl;
        outfile << "Graduation Year: " << art_students[i]->getGradYear() << endl;
        outfile << "Graduation Semester: " << art_students[i]->getGradSemester() << endl;
        outfile << "Enrollment Year: " << art_students[i]->getEnrollYear() << endl;
        outfile << "Enrollment Semester: " << art_students[i]->getEnrollSemester() << endl;
        outfile << "Student Level: " << art_students[i]->getStudentLevel() << endl;
        outfile << "Art Emphasis: " << art_students[i]->getArtEmphasis() << endl;
        outfile << "------------------------" << endl;
    }

    outfile << endl;
    outfile << "PHYSICS STUDENTS" << endl;
    outfile << "========================" << endl;

//Write all Physics students information 
    for (int i = 0; i < physics_students.size(); i++)
    {
        outfile << "Student " << i + 1 << endl;
        outfile << "Name: " << physics_students[i]->getName() << endl;
        outfile << "GPA: " << physics_students[i]->getGPA() << endl;
        outfile << "Graduation Year: " << physics_students[i]->getGradYear() << endl;
        outfile << "Graduation Semester: " << physics_students[i]->getGradSemester() << endl;
        outfile << "Enrollment Year: " << physics_students[i]->getEnrollYear() << endl;
        outfile << "Enrollment Semester: " << physics_students[i]->getEnrollSemester() << endl;
        outfile << "Student Level: " << physics_students[i]->getStudentLevel() << endl;
        outfile << "Concentration: " << physics_students[i]->getConcentration() << endl;
        outfile << "------------------------" << endl;
    }

//Close the file after writing the information
    outfile.close();

    // Release memory
    for (int i = 0; i < art_students.size(); i++)
    {
        delete art_students[i];
    }

    for (int i = 0; i < physics_students.size(); i++)
    {
        delete physics_students[i];
    }

    cout << "Student information saved to student_info.dat" << endl;

    return 0;
}
