#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void showMenu() {
    cout << "\n======================================================\n";
    cout << "          CHƯƠNG TRÌNH DEMO C++ - DỰ ÁN WD21301       \n";
    cout << "======================================================\n";
    cout << " 1. Demo 01: Tính toán cơ bản & Số học               \n";
    cout << " 2. Demo 02: Thao tác Mảng & Thuật toán Sắp xếp      \n";
    cout << " 3. Demo 03: Xử lý Chuỗi (String) & Palindrome       \n";
    cout << " 4. Demo 04: Lập trình Hướng đối tượng (OOP Sinh viên)\n";
    cout << " 5. Demo 05: Đọc & Ghi File dữ liệu (File I/O)       \n";
    cout << " 0. Thoát chương trình                               \n";
    cout << "======================================================\n";
    cout << "Nhập lựa chọn của bạn [0-5]: ";
}

int main() {
    int choice;
    do {
        showMenu();
        if (!(cin >> choice)) {
            cin.clear();
            string ignoreStr;
            getline(cin, ignoreStr);
            cout << "Lựa chọn không hợp lệ! Vui lòng nhập số.\n";
            continue;
        }

        cout << "\n";
        switch (choice) {
            case 1:
                system("./bin/demo01 || ./demos/01_basic_calculator");
                break;
            case 2:
                system("./bin/demo02 || ./demos/02_array_and_sorting");
                break;
            case 3:
                system("./bin/demo03 || ./demos/03_string_processing");
                break;
            case 4:
                system("./bin/demo04 || ./demos/04_oop_student_management");
                break;
            case 5:
                system("./bin/demo05 || ./demos/05_file_handling");
                break;
            case 0:
                cout << "Cảm ơn bạn đã sử dụng chương trình demo C++. Tạm biệt!\n";
                break;
            default:
                cout << "Lựa chọn không tồn tại! Vui lòng chọn từ 0 đến 5.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}