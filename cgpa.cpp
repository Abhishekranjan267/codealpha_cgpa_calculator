#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to convert grade into grade points
double getGradePoint(string grade)
{
    if (grade == "A+" || grade == "a+")
        return 10.0;
    else if (grade == "A" || grade == "a")
        return 9.0;
    else if (grade == "B+" || grade == "b+")
        return 8.0;
    else if (grade == "B" || grade == "b")
        return 7.0;
    else if (grade == "C+" || grade == "c+")
        return 6.0;
    else if (grade == "C" || grade == "c")
        return 5.0;
    else if (grade == "D" || grade == "d")
        return 4.0;
    else if (grade == "F" || grade == "f")
        return 0.0;
    else
        return -1.0;
}

int main()
{
    int courses;

    cout << "=====================================\n";
    cout << "        CGPA CALCULATOR\n";
    cout << "=====================================\n\n";

    // Number of courses
    cout << "Enter number of courses: ";
    cin >> courses;

    // Arrays to store course information
    string grade[courses];
    double credit[courses];
    double gradePoint[courses];

    double totalCredits = 0;
    double totalGradePoints = 0;

    // Input for each course
    for (int i = 0; i < courses; i++)
    {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter grade (A+, A, B+, B, C+, C, D, F): ";
        cin >> grade[i];

        gradePoint[i] = getGradePoint(grade[i]);

        // Check whether grade is valid
        while (gradePoint[i] == -1)
        {
            cout << "Invalid grade! Please enter again: ";
            cin >> grade[i];

            gradePoint[i] = getGradePoint(grade[i]);
        }

        cout << "Enter credit hours: ";
        cin >> credit[i];

        // Calculate grade points × credit hours
        totalCredits += credit[i];
        totalGradePoints += gradePoint[i] * credit[i];
    }

    // Calculate GPA
    double GPA = totalGradePoints / totalCredits;

    // Display result
    cout << "\n\n=====================================\n";
    cout << "           RESULT\n";
    cout << "=====================================\n";

    cout << left << setw(12) << "Course"
         << setw(12) << "Grade"
         << setw(15) << "Credits"
         << "Grade Point\n";

    cout << "-------------------------------------\n";

    for (int i = 0; i < courses; i++)
    {
        cout << left << setw(12) << i + 1
             << setw(12) << grade[i]
             << setw(15) << credit[i]
             << gradePoint[i] << endl;
    }

    cout << "-------------------------------------\n";

    cout << fixed << setprecision(2);

    cout << "Total Credits      : " << totalCredits << endl;
    cout << "Total Grade Points : " << totalGradePoints << endl;
    cout << "Semester GPA       : " << GPA << endl;

    cout << "\n=====================================\n";
    cout << "       CGPA: " << GPA << "\n";
    cout << "=====================================\n";

    return 0;
}