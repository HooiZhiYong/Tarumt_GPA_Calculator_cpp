#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

double getValidSubject();
double getValidCreditHour();

int main() {

    double gpa = 0;
    double gradePoint = 0, creditHour = 0, numOfSubject = 0;
    double totalCreditHourThisSem = 0, totalQualityPointThisSem = 0;
    string subGrade = "", subName = "";

    cout << "COPYRIGHT TARUMT GPA CALCULATOR USER GUIDE v1.0.0\n";
    cout << "How to use:\n";
    cout << "1. Enter all subject you are enrolled in, incluing the RESIT paper this semester\n";
    cout << "2. You are allowed to leave a BLANK on [ Enter subject name: ]\n";
    cout << "3. Please enter the CORRECT credit hours and grades as you expected\n";
    cout << "   Thanks and regret\n\n";

    cout << "Enter your number of subjects this semester: ";
    numOfSubject = getValidSubject();
    cin.ignore();

    for (int i = 0; i < numOfSubject; i++) {
        cout << "\nSubject " << i + 1 << ":\n";

        cout << "Enter subject name: ";
        getline(cin, subName);

        cout << "Enter credit hour: ";
        creditHour = getValidCreditHour();
        totalCreditHourThisSem += creditHour;

        cin.ignore();
        bool validGrade = false;
        while (!validGrade) {
            cout << "Enter subject grade: ";
            getline(cin, subGrade);

            if (subGrade == "A+" || subGrade == "a+") {
                gradePoint = 4.00;
                validGrade = true;
            }
            else if (subGrade == "A" || subGrade == "a") {
                gradePoint = 4.00;
                validGrade = true;
            }
            else if (subGrade == "A-" || subGrade == "a-") {
                gradePoint = 3.67;
                validGrade = true;
            }
            else if (subGrade == "B+" || subGrade == "b+") {
                gradePoint = 3.33;
                validGrade = true;
            }
            else if (subGrade == "B" || subGrade == "b") {
                gradePoint = 3.00;
                validGrade = true;
            }
            else if (subGrade == "B-" || subGrade == "b-") {
                gradePoint = 2.67;
                validGrade = true;
            }
            else if (subGrade == "C+" || subGrade == "c+") {
                gradePoint = 2.33;
                validGrade = true;
            }
            else if (subGrade == "C" || subGrade == "c") {
                gradePoint = 2.00;
                validGrade = true;
            }
            else if (subGrade == "F" || subGrade == "f") {
                gradePoint = 0.00;
                validGrade = true;
            }
            else {
                cout << "Invalid grade! Please enter again.\n";
            }
        }
        double qualityPoint = gradePoint * creditHour;
        totalQualityPointThisSem += qualityPoint;
    }

    if (totalCreditHourThisSem > 0)
        gpa = totalQualityPointThisSem / totalCreditHourThisSem;

    cout << "\n----- RESULT -----\n";
    cout << "GPA this semester: " << gpa << endl;
    cout << endl;

    cout << "copyright 2025 made by Hooi Zhi Yong :)\n";

    return 0;
}

/* create by finalzyyy / Hooi Zhi Yong */
/* copyright 2025 */
/* version 1.0.0 */

// validations
double getValidSubject() {

    double subject;

    cin >> subject;
    while (cin.fail() || subject < 1 || subject > 10) {
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "Invalid number! Enter number of subjects (1-10): ";
        cin >> subject;
    }
    return subject;
}

double getValidCreditHour() {

    double hour;

    cin >> hour;
    while (cin.fail() || hour < 1 || hour > 4) {
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "Invalid credit hours! Enter credit hour (1-4): ";
        cin >> hour;
    }
    
    return hour;
}