# 🚀 C++ Demo Projects & Git Guide (WD21301)

Bộ sưu tập các bài tập demo C++ từ cơ bản đến nâng cao dành cho học tập, thực hành lập trình C++ và làm quen với quy trình làm việc Git / GitHub.

---

## 📑 Mục Lục
- [1. Cấu Trúc Dự Án](#1-cấu-trúc-dự-án)
- [2. Danh Sách Các Bài Demo](#2-danh-sách-các-bài-demo)
  - [Demo 01: Tính toán cơ bản & Kiểm tra số](#demo-01-tính-toán-cơ-bản--kiểm-tra-số)
  - [Demo 02: Thao tác Mảng & Thuật toán Sắp xếp](#demo-02-thao-tác-mảng--thuật-toán-sắp-xếp)
  - [Demo 03: Xử lý Chuỗi (String) & Palindrome](#demo-03-xử-lý-chuỗi-string--palindrome)
  - [Demo 04: Lập trình Hướng Đối Tượng (OOP Sinh viên)](#demo-04-lập-trình-hướng-đối-tượng-oop-sinh-viên)
  - [Demo 05: Đọc & Ghi File dữ liệu (File I/O)](#demo-05-đọc--ghi-file-dữ-liệu-file-io)
- [3. Hướng Dẫn Biên Dịch & Chạy](#3-hướng-dẫn-biên-dịch--chạy)
  - [Cách 1: Sử dụng Makefile (Nhanh nhất)](#cách-1-sử-dụng-makefile-nhanh-nhất)
  - [Cách 2: Sử dụng lệnh g++ thủ công](#cách-2-sử-dụng-lệnh-g-thủ-công)
- [4. Hướng Dẫn Git Cơ Bản](#4-hướng-dẫn-git-cơ-bản)

---

## 1. Cấu Trúc Dự Án

```text
WD21301DemoGit/
├── demos/
│   ├── 01_basic_calculator.cpp       # Demo 01: Toán tử, điều kiện, hàm số nguyên tố
│   ├── 02_array_and_sorting.cpp      # Demo 02: Vector, Bubble Sort, Binary Search
│   ├── 03_string_processing.cpp      # Demo 03: Stringstream, chuẩn hóa chuỗi, Palindrome
│   ├── 04_oop_student_management.cpp # Demo 04: Class OOP, Getter/Setter, sắp xếp GPA
│   └── 05_file_handling.cpp          # Demo 05: Đọc/ghi file CSV với ifstream, ofstream
├── main.cpp                          # Menu CLI tương tác tổng hợp các demo
├── Makefile                          # Tự động hóa biên dịch toàn bộ dự án
├── .gitignore                        # Loại trừ file build và file tạm
└── README.md                         # Tài liệu hướng dẫn chi tiết
```

---

## 2. Danh Sách Các Bài Demo

### Demo 01: Tính toán cơ bản & Kiểm tra số
- **File:** `demos/01_basic_calculator.cpp`
- **Kiến thức:**
  - Nhập/xuất dữ liệu chuẩn (`std::cin`, `std::cout`, định dạng `iomanip`).
  - Các phép toán số học cộng, trừ, nhân, chia (xử lý chia cho 0), lũy thừa (`pow`).
  - Kiểm tra chẵn/lẻ và hàm kiểm tra số nguyên tố tối ưu ($O(\sqrt{n})$).
- **Lệnh chạy:**
  ```bash
  g++ -std=c++17 demos/01_basic_calculator.cpp -o bin/demo01
  ./bin/demo01
  ```

---

### Demo 02: Thao tác Mảng & Thuật toán Sắp xếp
- **File:** `demos/02_array_and_sorting.cpp`
- **Kiến thức:**
  - Mảng động `std::vector`, duyệt và tính toán thống kê (Min, Max, Tổng, Trung bình cộng).
  - Thuật toán sắp xếp nổi bọt (**Bubble Sort**) có gắn cờ tối ưu `swapped`.
  - Thuật toán tìm kiếm nhị phân (**Binary Search**) trên mảng đã sắp xếp.
- **Lệnh chạy:**
  ```bash
  g++ -std=c++17 demos/02_array_and_sorting.cpp -o bin/demo02
  ./bin/demo02
  ```

---

### Demo 03: Xử lý Chuỗi (String) & Palindrome
- **File:** `demos/03_string_processing.cpp`
- **Kiến thức:**
  - `std::string`, `std::getline`, `std::stringstream` để tách từ.
  - Chuẩn hóa chuỗi (xóa khoảng trắng thừa, viết hoa chữ cái đầu mỗi từ).
  - Đảo ngược chuỗi (`std::reverse`) và kiểm tra chuỗi đối xứng (**Palindrome**).
- **Lệnh chạy:**
  ```bash
  g++ -std=c++17 demos/03_string_processing.cpp -o bin/demo03
  ./bin/demo03
  ```

---

### Demo 04: Lập trình Hướng Đối Tượng (OOP Sinh viên)
- **File:** `demos/04_oop_student_management.cpp`
- **Kiến thức:**
  - Lập trình hướng đối tượng OOP: Encapsulation (đóng gói), Constructor, Getter/Setter.
  - Tính điểm trung bình (GPA), xếp loại học lực tự động.
  - Định dạng bảng console đẹp mắt với `setw`, `left`, `right`.
  - Sắp xếp danh sách đối tượng sinh viên theo GPA giảm dần sử dụng `std::sort` với hàm Lambda.
- **Lệnh chạy:**
  ```bash
  g++ -std=c++17 demos/04_oop_student_management.cpp -o bin/demo04
  ./bin/demo04
  ```

---

### Demo 05: Đọc & Ghi File dữ liệu (File I/O)
- **File:** `demos/05_file_handling.cpp`
- **Kiến thức:**
  - Thao tác tệp: `std::ofstream` (ghi file) và `std::ifstream` (đọc file).
  - Định dạng file dữ liệu dạng CSV (Comma-Separated Values).
  - Xử lý đọc parse dữ liệu từng dòng với `stringstream` và tính toán tổng giá trị tồn kho.
- **Lệnh chạy:**
  ```bash
  g++ -std=c++17 demos/05_file_handling.cpp -o bin/demo05
  ./bin/demo05
  ```

---

## 3. Hướng Dẫn Biên Dịch & Chạy

### Cách 1: Sử dụng Makefile (Nhanh nhất)

1. **Biên dịch toàn bộ dự án:**
   ```bash
   make all
   ```
2. **Chạy Menu chính:**
   ```bash
   make run
   # hoặc: ./bin/main
   ```
3. **Dọn dẹp các file binary sau khi chạy:**
   ```bash
   make clean
   ```

---

### Cách 2: Sử dụng lệnh g++ thủ công

Biên dịch từng bài mong muốn vào thư mục `bin/`:
```bash
# Tạo thư mục bin nếu chưa có
mkdir -p bin

# Biên dịch Menu chính
g++ -std=c++17 main.cpp -o bin/main

# Chạy
./bin/main
```

---

## 4. Hướng Dẫn Git Cơ Bản Cho Dự Án

### 1. Khởi tạo & Kiểm tra trạng thái
```bash
git status          # Kiểm tra trạng thái các file đã sửa
git diff            # Xem chi tiết các dòng code đã thay đổi
```

### 2. Thêm file và Commit
```bash
git add .                           # Thêm toàn bộ file vào staging
git commit -m "feat: thêm các bài demo C++ và tài liệu README"
```

### 3. Đẩy code lên GitHub
```bash
git branch -M main                  # Đặt tên nhánh chính là main
git remote add origin <URL_REPO>    # Liên kết với GitHub repo (nếu chưa có)
git push -u origin main             # Đẩy code lên GitHub
```

### 4. Làm việc nhóm qua Branch (Nhánh)
```bash
git checkout -b feature/demo-moi    # Tạo và chuyển sang nhánh mới
# ... thực hiện code ...
git add .
git commit -m "feat: bổ sung tính năng mới"
git push origin feature/demo-moi    # Đẩy nhánh lên và tạo Pull Request (PR)
```

---

*Chúc các bạn học tốt và làm chủ C++ cùng Git! 🚀*
