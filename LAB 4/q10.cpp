
#include <iostream>
using namespace std;

class AttendanceManager;  // Forward declaration

class Classroom {
private:
    string className;
    int totalStudents;
    int presentStudents;
    string attendanceStatus;

public:
    // Constructor
    Classroom(string name, int total, int present, string status) {
        className = name;
        totalStudents = total;
        presentStudents = present;
        attendanceStatus = status;
    }

    // Declare AttendanceManager as friend class
    friend class AttendanceManager;
};

class AttendanceManager {
public:

    // Display classroom information
    void displayInfo(Classroom &c) {
        cout << "----- Classroom Information -----" << endl;
        cout << "Class Name: " << c.className << endl;
        cout << "Total Students: " << c.totalStudents << endl;
        cout << "Present Students: " << c.presentStudents << endl;
        cout << "Attendance Status: " << c.attendanceStatus << endl;
    }

    // Update number of present students
    void updatePresent(Classroom &c, int present) {
        if (present <= c.totalStudents) {
            c.presentStudents = present;
            cout << "Present student count updated." << endl;
        } else {
            cout << "Invalid number of students." << endl;
        }
    }

    // Mark attendance as completed
    void completeAttendance(Classroom &c) {
        c.attendanceStatus = "Completed";
        cout << "Attendance marked as completed." << endl;
    }

    // Display attendance status
    void displayStatus(Classroom &c) {
        cout << "Attendance Status: "
             << c.attendanceStatus << endl;
    }

    // Calculate and display absent students
    void calculateAbsent(Classroom &c) {
        int absent = c.totalStudents - c.presentStudents;

        cout << "Absent Students: " << absent << endl;
    }
};

int main() {
    Classroom c("CSE B1", 60, 52, "Pending");
    AttendanceManager manager;

    manager.displayInfo(c);

    manager.updatePresent(c, 55);
    manager.completeAttendance(c);

    manager.calculateAbsent(c);
    manager.displayStatus(c);

    return 0;
}

