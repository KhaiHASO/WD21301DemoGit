#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

class Student {
private:
    string id;
    string name;
    double mathScore;
    double physicsScore;
    double chemistryScore;

public:
    Student() : id(""), name(""), mathScore(0), physicsScore(0), chemistryScore(0) {}

    Student(string id, string name, double math, double phys, double chem)
        : id(id), name(name), mathScore(math), physicsScore(phys), chemistryScore(chem) {}

    // Getters & Setters
    string getId() const { return id; }
    string getName() const { return name; }
    double getGpa() const {
        return (mathScore + physicsScore + chemistryScore) / 3.0;
    }

    string getAcademicRank() const {
        double gpa = getGpa();
        if (gpa >= 8.5) return "Xuat sac";
        if (gpa >= 8.0) return "Gioi";
        if (gpa >= 6.5) return "Kha";
        if (gpa >= 5.0) return "Trung binh";
        return "Yeu";
    }

    void displayRow() const {
        cout << "| " << left << setw(10) << id
             << "| " << setw(22) << name
             << "| " << right << setw(6) << fixed << setprecision(1) << mathScore
             << "| " << setw(6) << physicsScore
             << "| " << setw(6) << chemistryScore
             << "| " << setw(6) << fixed << setprecision(2) << getGpa()
             << "| " << left << setw(12) << getAcademicRank() << " |\n";
    }
};

void printHeader() {
    cout << "+-----------+-----------------------+-------+-------+-------+-------+--------------+\n";
    cout << "| Ma SV     | Ho va Ten             | Toan  | Ly    | Hoa   | GPA   | Xep loai     |\n";
    cout << "+-----------+-----------------------+-------+-------+-------+-------+--------------+\n";
}

void printFooter() {
    cout << "+-----------+-----------------------+-------+-------+-------+-------+--------------+\n";
}

int main() {
    cout << "========================================================================\n";
    cout << " DEMO 04: LAP TRINH HUONG DOI TUONG (OOP) - QUAN LY SINH VIEN           \n";
    cout << "========================================================================\n";

    vector<Student> students = {
        Student("SV001", "Nguyen Van An", 8.5, 9.0, 8.0),
        Student("SV002", "Tran Thi Binh", 7.0, 6.5, 8.0),
        Student("SV003", "Le Hoang Cuong", 9.5, 9.0, 9.5),
        Student("SV004", "Pham Minh Duc", 5.0, 4.5, 6.0),
        Student("SV005", "Vu Thi Hoa", 8.0, 8.5, 7.5)
    };

    cout << "\n>>> DANH SACH SINH VIEN BAN DAU <<<\n";
    printHeader();
    for (const auto& s : students) {
        s.displayRow();
    }
    printFooter();

    // Sắp xếp danh sách sinh viên theo GPA giảm dần
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.getGpa() > b.getGpa();
    });

    cout << "\n>>> DANH SACH SINH VIEN SAU KHI SAP XEP THEO GPA GIAM DAN <<<\n";
    printHeader();
    for (const auto& s : students) {
        s.displayRow();
    }
    printFooter();

    // Thống kê sinh viên thủ khoa (GPA cao nhất)
    if (!students.empty()) {
        const auto& topStudent = students[0];
        cout << "\n=> Sinh vien thu khoa: " << topStudent.getName() 
             << " (" << topStudent.getId() << ") voi GPA = " 
             << fixed << setprecision(2) << topStudent.getGpa() << " [" << topStudent.getAcademicRank() << "]\n";
    }

    return 0;
}
