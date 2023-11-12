#include <iostream>

using namespace std;

class Course {
private:
    string courseName;
    string* students;
    int numStudents;
    int maxStudents;

public:
    // Constructor
    Course(const string& name, int maxStudents)
        : courseName(name), numStudents(0), maxStudents(maxStudents) {
        students = new string[maxStudents];
    }

    // Deep Copy Constructor
    Course(const Course& other)
        : courseName(other.courseName), numStudents(other.numStudents), maxStudents(other.maxStudents) {
        students = new string[maxStudents];
        for (int i = 0; i < numStudents; ++i) {
            students[i] = other.students[i];
        }
    }


    ~Course() {
        delete[] students;
    }


    string getCourseName() const {
        return courseName;
    }


    void addStudent(const string& student) {
        if (numStudents < maxStudents) {
            students[numStudents] = student;
            ++numStudents;
        }
        else {
            cout << "Course is full. Cannot add more students." << endl;
        }
    }

    // Function to drop a student
    void dropStudent(const string& student) {
        int index = findStudentIndex(student);
        if (index != -1) {
         
            for (int i = index; i < numStudents - 1; ++i) {
                students[i] = students[i + 1];
            }
            --numStudents;
        }
        else {
            cout << "Student not found in the course." << endl;
        }
    }


    const string* getStudents() const {
        return students;
    }

  
    int getNumStudents() const {
        return numStudents;
    }

private:
 
    int findStudentIndex(const string& student) const {
        for (int i = 0; i < numStudents; ++i) {
            if (students[i] == student) {
                return i;
            }
        }
        return -1; 
    }
};

int main() {
  
    Course mathCourse("Math", 3);


    mathCourse.addStudent("ahmed");
    mathCourse.addStudent("furqan");
    mathCourse.addStudent("iffi");

    
    cout << "Students in " << mathCourse.getCourseName() << ": ";
    const string* mathStudents = mathCourse.getStudents();
    for (int i = 0; i < mathCourse.getNumStudents(); ++i) {
        cout << mathStudents[i] << " ";
    }
    cout << endl;

    
    Course copyCourse = mathCourse; 

 
    mathCourse.dropStudent("irfan");

    cout << "Students in " << mathCourse.getCourseName() << " after dropping Bob: ";
    mathStudents = mathCourse.getStudents();
    for (int i = 0; i < mathCourse.getNumStudents(); ++i) {
        cout << mathStudents[i] << " ";
    }
    cout << endl;

    
    cout << "Students in " << copyCourse.getCourseName() << ": ";
    const string* copyStudents = copyCourse.getStudents();
    for (int i = 0; i < copyCourse.getNumStudents(); ++i) {
        cout << copyStudents[i] << " ";
    }
    cout << endl;

    return 0;
}
