#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Hàm in mảng
void printArray(const vector<int>& arr, const string& message = "") {
    if (!message.empty()) cout << message << ": ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";
}

// Thuật toán Bubble Sort (Sắp xếp nổi bọt)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Tối ưu: Dừng nếu mảng đã được sắp xếp
    }
}

// Tìm kiếm nhị phân (Binary Search) trên mảng đã sắp xếp
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    cout << "========================================\n";
    cout << " DEMO 02: THAO TAC MANG & SAP XEP       \n";
    cout << "========================================\n";

    int n;
    cout << "Nhap so luong phan tu cua mang (n > 0): ";
    if (!(cin >> n) || n <= 0) {
        cout << "Gia tri n khong hop le. Mac dinh su dung 6 phan tu.\n";
        n = 6;
    }

    vector<int> arr(n);
    cout << "Nhap " << n << " so nguyen cach nhau boi dau cach:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    printArray(arr, "\nMang ban dau");

    // Thống kê min, max, tổng, trung bình
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());
    int sumVal = accumulate(arr.begin(), arr.end(), 0);
    double avgVal = static_cast<double>(sumVal) / n;

    cout << "\n--- THONG KE MANG ---\n";
    cout << "Gia tri nho nhat (Min) : " << minVal << "\n";
    cout << "Gia tri lon nhat (Max) : " << maxVal << "\n";
    cout << "Tong cac phan tu       : " << sumVal << "\n";
    cout << "Trung binh cong        : " << avgVal << "\n";

    // Sắp xếp
    vector<int> sortedArr = arr;
    bubbleSort(sortedArr);
    printArray(sortedArr, "\nMang sau khi sap xep tang dan (Bubble Sort)");

    // Tìm kiếm nhị phân
    int target;
    cout << "\nNhap gia tri can tim kiem: ";
    cin >> target;
    int index = binarySearch(sortedArr, target);
    if (index != -1) {
        cout << "=> Tim thay " << target << " tai vi tri index = " << index << " (trong mang da sap xep).\n";
    } else {
        cout << "=> Khong tim thay " << target << " trong mang.\n";
    }

    return 0;
}
