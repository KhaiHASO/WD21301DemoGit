#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Product {
    int id;
    string name;
    double price;
    int quantity;
};

void writeToFile(const string& filename, const vector<Product>& products) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Loi: Khong the mo file de ghi: " << filename << "\n";
        return;
    }

    // Ghi tiêu đề CSV
    outFile << "ID,Name,Price,Quantity\n";
    for (const auto& p : products) {
        outFile << p.id << "," << p.name << "," << p.price << "," << p.quantity << "\n";
    }

    outFile.close();
    cout << "=> Da ghi thanh cong " << products.size() << " san pham vao file: " << filename << "\n";
}

vector<Product> readFromFile(const string& filename) {
    vector<Product> products;
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Loi: Khong the mo file de doc: " << filename << "\n";
        return products;
    }

    string line;
    // Bỏ qua dòng tiêu đề
    if (getline(inFile, line)) {
        // Đọc từng dòng dữ liệu
        while (getline(inFile, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string idStr, name, priceStr, qtyStr;

            if (getline(ss, idStr, ',') &&
                getline(ss, name, ',') &&
                getline(ss, priceStr, ',') &&
                getline(ss, qtyStr, ',')) {
                Product p;
                p.id = stoi(idStr);
                p.name = name;
                p.price = stod(priceStr);
                p.quantity = stoi(qtyStr);
                products.push_back(p);
            }
        }
    }

    inFile.close();
    return products;
}

int main() {
    cout << "========================================\n";
    cout << " DEMO 05: DOC & GHI FILE (FILE I/O)     \n";
    cout << "========================================\n";

    string filename = "products_data.csv";

    // 1. Tạo dữ liệu mẫu và ghi ra file
    vector<Product> initialList = {
        {101, "Laptop Dell XPS", 1299.99, 15},
        {102, "Ban phim co Keychron", 89.50, 40},
        {103, "Chuot Logitech MX Master 3", 99.00, 25},
        {104, "Man hinh LG 27 Inch 4K", 349.00, 10}
    };

    cout << "\n[1] Ghi danh sach san pham ra file CSV...\n";
    writeToFile(filename, initialList);

    // 2. Đọc lại dữ liệu từ file vừa ghi
    cout << "\n[2] Doc du lieu tu file CSV vua tao...\n";
    vector<Product> loadedList = readFromFile(filename);

    cout << "\n--- DANH SACH SAN PHAM DOC DUOC ---\n";
    double totalInventoryValue = 0;
    for (const auto& p : loadedList) {
        double itemTotal = p.price * p.quantity;
        totalInventoryValue += itemTotal;
        cout << "- [ID: " << p.id << "] " << p.name 
             << " | Don gia: $" << p.price 
             << " | So luong: " << p.quantity 
             << " | Tong: $" << itemTotal << "\n";
    }

    cout << "------------------------------------\n";
    cout << "=> Tong gia tri kho hang: $" << totalInventoryValue << "\n";

    return 0;
}
