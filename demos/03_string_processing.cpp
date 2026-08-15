#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

// Hàm kiểm tra chuỗi đối xứng (Palindrome)
bool isPalindrome(const string& s) {
    string cleaned = "";
    for (char c : s) {
        if (isalnum(c)) {
            cleaned += tolower(c);
        }
    }
    int l = 0, r = cleaned.length() - 1;
    while (l < r) {
        if (cleaned[l] != cleaned[r]) return false;
        l++;
        r--;
    }
    return true;
}

// Hàm chuẩn hóa chuỗi: xóa khoảng trắng thừa và viết hoa chữ cái đầu mỗi từ
string normalizeString(const string& s) {
    stringstream ss(s);
    string word, result = "";
    while (ss >> word) {
        // Viết hoa chữ đầu, viết thường các chữ sau
        word[0] = toupper(word[0]);
        for (size_t i = 1; i < word.length(); ++i) {
            word[i] = tolower(word[i]);
        }
        if (!result.empty()) result += " ";
        result += word;
    }
    return result;
}

// Đếm số từ trong chuỗi
int countWords(const string& s) {
    stringstream ss(s);
    string word;
    int count = 0;
    while (ss >> word) {
        count++;
    }
    return count;
}

int main() {
    cout << "========================================\n";
    cout << " DEMO 03: XU LY CHUOI KY TU (STRING)    \n";
    cout << "========================================\n";

    cin.ignore(cin.rdbuf()->in_avail()); // Xóa bộ đệm
    string inputStr;
    cout << "Nhap mot chuoi bat ky: ";
    getline(cin, inputStr);

    if (inputStr.empty()) {
        inputStr = "   hELLo    wORLD!   raCECar   ";
        cout << "(Chuoi rong, su dung chuoi mac dinh: \"" << inputStr << "\")\n";
    }

    cout << "\n--- KET QUA PHAN TICH ---\n";
    cout << "Do dai chuoi goc      : " << inputStr.length() << " ky tu\n";
    cout << "So tu trong chuoi     : " << countWords(inputStr) << " tu\n";
    
    string normalized = normalizeString(inputStr);
    cout << "Chuoi sau chuan hoa   : \"" << normalized << "\"\n";

    // Đảo ngược chuỗi
    string reversed = inputStr;
    reverse(reversed.begin(), reversed.end());
    cout << "Chuoi dao nguoc       : \"" << reversed << "\"\n";

    // Kiểm tra Palindrome
    cout << "Kiem tra Palindrome   : " 
         << (isPalindrome(inputStr) ? "Dung (Chuoi doi xung)" : "Sai (Khong phai chuoi doi xung)") << "\n";

    return 0;
}
