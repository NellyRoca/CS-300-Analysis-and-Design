#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Struct for storing course info
struct Course {
    string courseNumber;
    string courseName;
    vector<string> prerequisites;
};

// Show the main menu
void DisplayMenu() {
    cout << endl;
    cout << "1. Load Data Structure." << endl;
    cout << "2. Print Course List." << endl;
    cout << "3. Print Course." << endl;
    cout << "9. Exit" << endl;
    cout << "What would you like to do? ";
}

// Convert string to uppercase for case-insensitive comparison
string ToUpper(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

// Load the course data from file
void LoadCourses(string filename, vector<Course>& courses) {
    courses.clear();  // Reset in case user loads again

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        Course course;

        // Get course number
        getline(ss, course.courseNumber, ',');
        // Get course name
        getline(ss, course.courseName, ',');

        // Get prerequisites (if any)
        while (getline(ss, token, ',')) {
            course.prerequisites.push_back(token);
        }

        courses.push_back(course);
    }

    file.close();
    cout << "Courses loaded successfully." << endl;
}

// Print course list sorted by course number
void PrintCourseList(const vector<Course>& courses) {
    if (courses.empty()) {
        cout << "No courses loaded yet. Please load the data first." << endl;
        return;
    }

    // Copy and sort courses by course number
    vector<Course> sortedCourses = courses;
    sort(sortedCourses.begin(), sortedCourses.end(), [](Course a, Course b) {
        return a.courseNumber < b.courseNumber;
        });

    cout << "Here is a sample schedule:" << endl;
    for (const Course& c : sortedCourses) {
        cout << c.courseNumber << ", " << c.courseName << endl;
    }
}

// Print course info for a specific course
void PrintCourseInfo(const vector<Course>& courses, string courseNumber) {
    if (courses.empty()) {
        cout << "No courses loaded yet. Please load the data first." << endl;
        return;
    }

    courseNumber = ToUpper(courseNumber);
    bool found = false;

    for (const Course& c : courses) {
        if (ToUpper(c.courseNumber) == courseNumber) {
            found = true;
            cout << c.courseNumber << ", " << c.courseName << endl;

            if (c.prerequisites.empty()) {
                cout << "Prerequisites: None" << endl;
            }
            else {
                cout << "Prerequisites: ";
                for (size_t i = 0; i < c.prerequisites.size(); ++i) {
                    cout << c.prerequisites[i];
                    if (i < c.prerequisites.size() - 1)
                        cout << ", ";
                }
                cout << endl;
            }
            break;
        }
    }

    if (!found) {
        cout << "Course not found." << endl;
    }
}

// Main function
int main() {
    vector<Course> courses;
    int choice;
    string filename;

    cout << "Welcome to the course planner." << endl;

    do {
        DisplayMenu();
        cin >> choice;
        cin.ignore(); // flush newline

        switch (choice) {
        case 1:
            cout << "Enter the filename: ";
            getline(cin, filename);
            LoadCourses(filename, courses);
            break;
        case 2:
            PrintCourseList(courses);
            break;
        case 3: {
            cout << "What course do you want to know about? ";
            string courseNum;
            getline(cin, courseNum);
            PrintCourseInfo(courses, courseNum);
            break;
        }
        case 9:
            cout << "Thank you for using the course planner!" << endl;
            break;
        default:
            cout << choice << " is not a valid option." << endl;
        }

    } while (choice != 9);

    return 0;
}
