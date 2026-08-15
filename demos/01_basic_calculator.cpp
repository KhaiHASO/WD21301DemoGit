#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
        
// Hàm tính lũy thừa
double power(double base, int exp) {
    return pow(base, exp);
}

int main() {
    cout << "========================================\n";
    cout << " DEMO 01: TINH TOAN CO BAN & KIEM TRA   \n";
    cout << "========================================\n";

    double a, b;
    cout << "Nhap so thu nhat (a): ";
    if (!(cin >> a)) return 0;
    cout << "Nhap so thu hai (b): ";
    if (!(cin >> b)) return 0;

    cout << "\n--- KET QUA PHEP TOAN ---\n";
    cout << fixed << setprecision(2);
    cout << "a + b = " << (a + b) << "\n";
    cout << "a - b = " << (a - b) << "\n";
    cout << "a * b = " << (a * b) << "\n";
    if (b != 0) {
        cout << "a / b = " << (a / b) << "\n";
    } else {
        cout << "a / b = Khong the chia cho 0!\n";
    }
    cout << "a ^ 2 = " << power(a, 2) << "\n";
    cout << "b ^ 2 = " << power(b, 2) << "\n";

    cout << "\n--- KIEM TRA SO NGUYEN ---\n";
    int intA = static_cast<int>(a);
    int intB = static_cast<int>(b);

    cout << "Phan nguyen cua a (" << intA << ") la so: " 
         << (intA % 2 == 0 ? "Chan" : "Le") 
         << (isPrime(intA) ? " va la So nguyen to" : " va Khong phai so nguyen to") << "\n";

    cout << "Phan nguyen cua b (" << intB << ") la so: " 
         << (intB % 2 == 0 ? "Chan" : "Le") 
         << (isPrime(intB) ? " va la So nguyen to" : " va Khong phai so nguyen to") << "\n";

    return 0;
}
