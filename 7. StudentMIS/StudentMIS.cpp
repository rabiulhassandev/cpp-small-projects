// - This Is A Simple Program (Student Management Information System) of C++,
// - Made By RABIUL HASSAN (22170910)

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <windows.h>

// namespace
using namespace std;

// function declaration
void menu();
void setColor(unsigned textColor, unsigned bgColor);
void StuSearch();
void studentAdd();
void studentModify();
void studentDelete();
void ShowStudentSelectedData();

class Student {
private:
    int stuNo;
    string name;
    char gender;
    string phone;
    string weChat;
    string dormitory;
    int score;

public:
    // Constructor
    Student(int no, const string& studentName, char studentGender, const string& studentPhone,
            const string& studentWeChat, const string& studentDormitory, int studentScore);

    // Getters
    int GetStuNo() const;
    string GetName() const;
    char GetGender() const;
    string GetPhone() const;
    string GetWeChat() const;
    string GetDormitory() const;
    int GetScore() const;

    // Setters
    void SetName(const string& studentName);
    void SetGender(char studentGender);
    void SetPhone(const string& studentPhone);
    void SetWeChat(const string& studentWeChat);
    void SetDormitory(const string& studentDormitory);
    void SetScore(int studentScore);

    // Other member functions as required


    // Implement the Student class member functions

};

// Constructor
    Student::Student(int no, const string& studentName, char studentGender, const string& studentPhone,
                     const string& studentWeChat, const string& studentDormitory, int studentScore)
        : stuNo(no), name(studentName), gender(studentGender), phone(studentPhone),
          weChat(studentWeChat), dormitory(studentDormitory), score(studentScore) {}

    // Getters
    int Student::GetStuNo() const {
        return stuNo;
    }

    string Student::GetName() const {
        return name;
    }

    char Student::GetGender() const {
        return gender;
    }

    string Student::GetPhone() const {
        return phone;
    }

    string Student::GetWeChat() const {
        return weChat;
    }

    string Student::GetDormitory() const {
        return dormitory;
    }

    int Student::GetScore() const {
        return score;
    }

    // Setters
    void Student::SetName(const string& studentName) {
        name = studentName;
    }

    void Student::SetGender(char studentGender) {
        gender = studentGender;
    }

    void Student::SetPhone(const string& studentPhone) {
        phone = studentPhone;
    }

    void Student::SetWeChat(const string& studentWeChat) {
        weChat = studentWeChat;
    }

    void Student::SetDormitory(const string& studentDormitory) {
        dormitory = studentDormitory;
    }

    void Student::SetScore(int studentScore) {
        score = studentScore;
    }


// Step 3: Implement the necessary global functions for MIS operations
// Global variables
vector<Student> studentData;

// Function to load data from file
void LoadData() {
    ifstream inputFile("data.txt");
    if (!inputFile) {
        setColor(12, 0);
        cout << "\n\tFailed to open the file." << endl;
        setColor(7, 0);
        return;
    }

    studentData.clear(); // clear previous all data

    int stuNo, score, count=0;
    string name, phone, weChat, dormitory;
    char gender;

    while (inputFile >> stuNo >> name >> gender >> phone >> weChat >> dormitory >> score) {
        Student student(stuNo, name, gender, phone, weChat, dormitory, score);
        studentData.push_back(student);
        count++;
    }

    setColor(2, 0);
    cout << "\n\tTotal " << count << " students data loaded successfully." << endl;
    setColor(7, 0);

    inputFile.close();
}

// Function to display all students
void ShowAllStudents() {
    int count = 0;
    setColor(2, 0);
    cout << "\n\tSL.\t" << "Student ID\t" << "Name\t" << "Gender\t" << "Phone Number\t" << "WeChat\t" << "Dormitory No\t" << "Score\n" << endl;
    setColor(7, 0);
    for (const auto& student : studentData) {
        cout << "\t" << ++count << "\t" << student.GetStuNo() << "\t" << student.GetName() << "\t" << student.GetGender() << "\t" << student.GetPhone() << "\t" << student.GetWeChat() << "\t" << student.GetDormitory() << "\t" << student.GetScore() << "\t" << endl;
    }

    if(count == 0){
        setColor(12, 0);
        cout << "\tNo Data Found!" << endl;
        setColor(7, 0);
    }else{
        setColor(2, 0);
        cout << "\n\tTotal " << count << " Data Found." << endl;
        setColor(7, 0);
    }
}

// Function to search for a student by student number
bool SearchStudent(int stuNo) {
    for (const auto& student : studentData) {
        if (student.GetStuNo() == stuNo) {
            cout << "\n\tStudent Id: " << student.GetStuNo() << endl;
            cout << "\tName: " << student.GetName() << endl;
            cout << "\tGender: " << student.GetGender() << endl;
            cout << "\tPhone: " << student.GetPhone() << endl;
            cout << "\tWeChat: " << student.GetWeChat() << endl;
            cout << "\tDormitory: " << student.GetDormitory() << endl;
            cout << "\tScore: " << student.GetScore() << endl;

            setColor(2, 0);
            cout << "\n\tData Match Found!" << endl;
            setColor(7, 0);

            cout << endl;
            return true;
        }
    }

    setColor(12, 0);
    cout << "\n\tData Not Match Found!" << endl;
    setColor(7, 0);

    return false;
}

// Function to add a new student
void AddStudent(const Student& student) {
    studentData.push_back(student);

    setColor(2, 0);
    cout << "\n\tData Inserted Successfully!" << endl;
    setColor(7, 0);
}

// Function to modify a student by student number
bool ModifyStudent(int stuNo, const Student& modifiedStudent) {
    for (auto& student : studentData) {
        if (student.GetStuNo() == stuNo) {
            student = modifiedStudent;
            setColor(2, 0);
            cout << "\n\tStudent with Student ID " << stuNo << " modified successfully." << endl;
            setColor(7, 0);
            return true;
        }
    }

    setColor(12, 0);
    cout << "\n\tStudent with Student ID " << stuNo << " not found." << endl;
    setColor(7, 0);
    return false;
}

// Function to delete a student by student number
bool DeleteStudent(int stuNo) {
    for (auto it = studentData.begin(); it != studentData.end(); ++it) {
        if (it->GetStuNo() == stuNo) {
            studentData.erase(it);
            setColor(2, 0);
            cout << "\n\tStudent with Student ID " << stuNo << " deleted successfully." << endl;
            setColor(7, 0);
            return true;
        }
    }

    setColor(12, 0);
    cout << "\n\tStudent with Student ID " << stuNo << " not found." << endl;
    setColor(7, 0);
    return false;
}

// Function to sort students by student number
void SortByStuNo() {
    sort(studentData.begin(), studentData.end(), [](const Student& a, const Student& b) {
        return a.GetStuNo() < b.GetStuNo();
    });

    setColor(2, 0);
    cout << "\n\tData Sorted By Student Id." << endl;
    setColor(7, 0);

    string data_show;
    cout << "\n\tDo you want to show sorted list? (Y/N) :";
    cin >> data_show;

    if(data_show=="Y" or data_show=="y"){
        ShowAllStudents();
    }

}

// Function to sort students by name
void SortByName() {
    sort(studentData.begin(), studentData.end(), [](const Student& a, const Student& b) {
        return a.GetName() < b.GetName();
    });

    setColor(2, 0);
    cout << "\n\tData Sorted By Student Name." << endl;
    setColor(7, 0);

    string data_show;
    cout << "\n\tDo you want to show sorted list? (Y/N) :";
    cin >> data_show;

    if(data_show=="Y" or data_show=="y"){
        ShowAllStudents();
    }
}

// Function to sort students by gender
void SortByGender() {
    sort(studentData.begin(), studentData.end(), [](const Student& a, const Student& b) {
        return a.GetGender() < b.GetGender();
    });

    setColor(2, 0);
    cout << "\n\tData Sorted By Student Gender." << endl;
    setColor(7, 0);

    string data_show;
    cout << "\n\tDo you want to show sorted list? (Y/N) :";
    cin >> data_show;

    if(data_show=="Y" or data_show=="y"){
        ShowAllStudents();
    }
}

// Function to sort students by phone
void SortByPhone() {
    sort(studentData.begin(), studentData.end(), [](const Student& a, const Student& b) {
        return a.GetPhone() < b.GetPhone();
    });

    setColor(2, 0);
    cout << "\n\tData Sorted By Student Phone." << endl;
    setColor(7, 0);

    string data_show;
    cout << "\n\tDo you want to show sorted list? (Y/N) :";
    cin >> data_show;

    if(data_show=="Y" or data_show=="y"){
        ShowAllStudents();
    }
}

// Function to sort students by WeChat
void SortByWeChat() {
    sort(studentData.begin(), studentData.end(), [](const Student& a, const Student& b) {
        return a.GetWeChat() < b.GetWeChat();
    });

    setColor(2, 0);
    cout << "\n\tData Sorted By Student WeChat." << endl;
    setColor(7, 0);

    string data_show;
    cout << "\n\tDo you want to show sorted list? (Y/N) :";
    cin >> data_show;

    if(data_show=="Y" or data_show=="y"){
        ShowAllStudents();
    }
}

// Function to sort students by dormitory
void SortByDormitory() {
    sort(studentData.begin(), studentData.end(), [](const Student& a, const Student& b) {
        return a.GetDormitory() < b.GetDormitory();
    });

    setColor(2, 0);
    cout << "\n\tData Sorted By Dormitory." << endl;
    setColor(7, 0);

    string data_show;
    cout << "\n\tDo you want to show sorted list? (Y/N) :";
    cin >> data_show;

    if(data_show=="Y" or data_show=="y"){
        ShowAllStudents();
    }
}

// Function to sort students by score
void SortByScore() {
    sort(studentData.begin(), studentData.end(), [](const Student& a, const Student& b) {
        return a.GetScore() < b.GetScore();
    });

    setColor(2, 0);
    cout << "\n\tData Sorted By Student Score." << endl;
    setColor(7, 0);

    string data_show;
    cout << "\n\tDo you want to show sorted list? (Y/N) :";
    cin >> data_show;

    if(data_show=="Y" or data_show=="y"){
        ShowAllStudents();
    }
}

// Function to display statistics data
void StatisticsData() {
    int totalStudents = studentData.size();
    int totalMaleStudents = count_if(studentData.begin(), studentData.end(), [](const Student& student) {
        return student.GetGender() == 'M';
    });
    int totalFemaleStudents = totalStudents - totalMaleStudents;
    int maxScore = max_element(studentData.begin(), studentData.end(), [](const Student& a, const Student& b) {
        return a.GetScore() < b.GetScore();
    })->GetScore();
    int minScore = min_element(studentData.begin(), studentData.end(), [](const Student& a, const Student& b) {
        return a.GetScore() < b.GetScore();
    })->GetScore();

    cout << "\n\tTotal Students: " << totalStudents << endl;
    cout << "\tTotal Male Students: " << totalMaleStudents << endl;
    cout << "\tTotal Female Students: " << totalFemaleStudents << endl;
    cout << "\tMaximum Score: " << maxScore << endl;
    cout << "\tMinimum Score: " << minScore << endl;
}

// Function to clear all data
void ClearData() {
    studentData.clear();

    setColor(2, 0);
    cout << "\n\tAll data cleared." << endl;
    setColor(7, 0);
}

// Function to save data to file
void SaveDataToFile() {

    string filename;

    cout << "\tEnter a filename: ";
    cin >> filename;

    ofstream outputFile(filename + ".txt");

    if (!outputFile) {
        cout << "Failed to open the file." << endl;
        return;
    }

    for (const auto& student : studentData) {
        outputFile << student.GetStuNo() << "\t";
        outputFile << student.GetName() << "\t";
        outputFile << student.GetGender() << "\t";
        outputFile << student.GetPhone() << "\t";
        outputFile << student.GetWeChat() << "\t";
        outputFile << student.GetDormitory() << "\t";
        outputFile << student.GetScore() << endl;
    }
    outputFile.close();

    setColor(2, 0);
    cout << "\tData saved to file successfully." << endl;
    setColor(7, 0);
}

// Function to show selected student data
bool ShowSelectedData(int stuNo) {
    for (const auto& student : studentData) {
        if (student.GetStuNo() == stuNo) {
            cout << "\n\tStudent Id: " << student.GetStuNo() << endl;
            cout << "\tName: " << student.GetName() << endl;
            cout << "\tGender: " << student.GetGender() << endl;
            cout << "\tPhone: " << student.GetPhone() << endl;
            cout << "\tWeChat: " << student.GetWeChat() << endl;
            cout << "\tDormitory: " << student.GetDormitory() << endl;
            cout << "\tScore: " << student.GetScore() << endl;

            setColor(2, 0);
            cout << "\n\tSelected Data Showing!" << endl;
            setColor(7, 0);
            return true;
        }
    }

    setColor(12, 0);
    cout << "\n\tSelected Student with Student Id " << stuNo << " Not Found!" << endl;
    setColor(7, 0);

    return false;
}


// Step 4: Implement the main program and user interface
int main() {
    int choice;

    do {
        menu(); // load main menu

        cout << "\n\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                LoadData();
                break;
            case 2:
                ShowAllStudents();
                break;
            case 3: {
                StuSearch();
                break;
            }
            case 4: {
                studentAdd();
                break;
            }
            case 5: {
                studentModify();
                break;
            }
            case 6: {
                studentDelete();
                break;
            }
            case 7:
                SortByStuNo();
                break;
            case 8:
                SortByName();
                break;
            case 9:
                SortByGender();
                break;
            case 10:
                SortByPhone();
                break;
            case 11:
                SortByWeChat();
                break;
            case 12:
                SortByDormitory();
                break;
            case 13:
                SortByScore();
                break;
            case 14:
                StatisticsData();
                break;
            case 15:
                ClearData();
                break;
            case 16:
                SaveDataToFile();
                break;
            case 17: {
                ShowStudentSelectedData();
                break;
            }
            case 18:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;

    } while (choice != 18);

    return 0;
}

// main menu
void menu(){
    cout << "\n\t********************Students MIS*************************" << endl;
    cout << "\t$                                                        $" << endl;
    cout << "\t$    1. Load Data             2. Show All Students       $" << endl;
    cout << "\t$                                                        $" << endl;
    cout << "\t$    3. Search Student        4. Add Student             $" << endl;
    cout << "\t$                                                        $" << endl;
    cout << "\t$    5. Modify Student        6. Delete Student          $" << endl;
    cout << "\t$                                                        $" << endl;
    cout << "\t$    7. Sort by StuNo         8. Sort by Name            $" << endl;
    cout << "\t$                                                        $" << endl;
    cout << "\t$    9. Sort by Gender        10. Sort by Phone          $" << endl;
    cout << "\t$                                                        $" << endl;
    cout << "\t$    11. Sort by WeChat       12. Sort by Dormitory      $" << endl;
    cout << "\t$                                                        $" << endl;
    cout << "\t$    13. Sort by Score        14. Statistics Data        $" << endl;
    cout << "\t$                                                        $" << endl;
    cout << "\t$    15. Clear Data           16. Save Data To File      $" << endl;
    cout << "\t$                                                        $" << endl;
    cout << "\t$    17. Show Selected Data   18. Exit                   $" << endl;
    cout << "\t$                                                        $" << endl;
    cout << "\t***************RABIUL HASSAN@CopyRight2023****************" << endl;
}

// set color
void setColor(unsigned textColor, unsigned bgColor){
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, textColor%16 | bgColor%16*16);
}

// Student Search
void StuSearch(){
    setColor(2, 0);
    cout << "\n\t==========Press 888 to exit============" << endl;
    setColor(7, 0);

    int stuNo;
    cout << "\n\tEnter the student number: ";
    while(!(cin>>stuNo) || (stuNo<=0) ){
        cout << "\tInvalid. Please input an integer:";
        cin.clear();
        cin.sync();
    }

    if(stuNo==888){
        return;
    }else if(!SearchStudent(stuNo)){
        StuSearch();
    }
    return;
}

// add new student
void studentAdd(){
    int stuNo;
    string name, phone, weChat, dormitory;
    char gender;

    cout << "\n\tEnter the student number: ";
    while(!(cin>>stuNo) || (stuNo<=0) ){
        cout << "\tInvalid. Please input an integer:";
        cin.clear();
        cin.sync();
    }
    cout << "\tEnter the name: ";
    cin >> name;
    cout << "\tEnter the gender (M/F): ";
    cin >> gender;
    cout << "\tEnter the phone number: ";
    cin >> phone;
    cout << "\tEnter the WeChat ID: ";
    cin >> weChat;
    cout << "\tEnter the dormitory: ";
    cin >> dormitory;

    Student newStudent(stuNo, name, gender, phone, weChat, dormitory, 0);
    AddStudent(newStudent);

    return;
}

// student modify
void studentModify(){
    setColor(2, 0);
    cout << "\n\t==========Press 888 to exit============" << endl;
    setColor(7, 0);

    int stuNo;
    string name, phone, weChat, dormitory;
    char gender;

    cout << "\n\tEnter the student number: ";
    while(!(cin>>stuNo) || (stuNo<=0) ){
        cout << "\tInvalid. Please input an integer:";
        cin.clear();
        cin.sync();
    }

    if(stuNo==888){
        return;
    }

    cout << "\tEnter the name: ";
    cin >> name;
    cout << "\tEnter the gender (M/F): ";
    cin >> gender;
    cout << "\tEnter the phone number: ";
    cin >> phone;
    cout << "\tEnter the WeChat ID: ";
    cin >> weChat;
    cout << "\tEnter the dormitory: ";
    cin >> dormitory;

    Student modifiedStudent(stuNo, name, gender, phone, weChat, dormitory, 0);

    if(!ModifyStudent(stuNo, modifiedStudent)){
        studentModify();
    }

    return;
}

// student delete
void studentDelete(){
    setColor(2, 0);
    cout << "\n\t==========Press 888 to exit============" << endl;
    setColor(7, 0);

    int stuNo;

    cout << "\n\tEnter the student number: ";
    while(!(cin>>stuNo) || (stuNo<=0) ){
        cout << "\tInvalid. Please input an integer:";
        cin.clear();
        cin.sync();
    }

    if(stuNo==888){
        return;
    }

    if(!DeleteStudent(stuNo)){
        studentDelete();
    }

    return;
}

// Student Search
void ShowStudentSelectedData(){
    setColor(2, 0);
    cout << "\n\t==========Press 888 to exit============" << endl;
    setColor(7, 0);

    int stuNo;
    cout << "\n\tEnter the student number: ";
    while(!(cin>>stuNo) || (stuNo<=0) ){
        cout << "\tInvalid. Please input an integer:";
        cin.clear();
        cin.sync();
    }

    if(stuNo==888){
        return;
    }else if(!ShowSelectedData(stuNo)){
        ShowStudentSelectedData();
    }
    return;
}
