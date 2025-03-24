Giới thiệu: Dự án Quản Lý Sinh Viên
Mô tả dự án

Dự án Quản Lý Sinh Viên là một chương trình viết bằng C++ giúp quản lý thông tin sinh viên trong một hệ thống đơn giản. Chương trình cho phép nhập, lưu trữ, tìm kiếm và sắp xếp danh sách sinh viên một cách hiệu quả. Dữ liệu sinh viên được lưu vào file nhị phân để đảm bảo tính ổn định và dễ dàng truy xuất.

Các tính năng chính
Nhập thông tin sinh viên: Người dùng có thể nhập dữ liệu sinh viên bao gồm mã số sinh viên, họ tên, ngày sinh, nơi sinh, lớp học, điểm thi và hệ thống tự động tính điểm trung bình cũng như xếp loại học lực.

Hiển thị danh sách sinh viên: Xuất danh sách sinh viên ra màn hình với định dạng bảng rõ ràng.

Tìm kiếm sinh viên theo mã số: Cho phép người dùng nhập mã số sinh viên để tìm kiếm thông tin chi tiết.

Tìm kiếm sinh viên theo lớp học: Xuất danh sách sinh viên thuộc một lớp học cụ thể.

Lọc danh sách theo xếp loại: Hiển thị danh sách sinh viên theo từng loại học lực (Giỏi, Khá, Trung Bình, Yếu).

Lưu danh sách vào file: Ghi toàn bộ danh sách sinh viên vào file nhị phân "ctql.dat".

Đọc danh sách từ file và sắp xếp theo mã số: Đọc dữ liệu từ file, sắp xếp theo mã số sinh viên tăng dần và hiển thị danh sách ra màn hình.

Thoát chương trình: Cho phép người dùng kết thúc chương trình.

Cách hoạt động
Chương trình sử dụng vector để lưu trữ danh sách sinh viên trong bộ nhớ.

Khi lưu, dữ liệu được ghi vào file "ctql.dat" ở định dạng nhị phân để đảm bảo truy xuất nhanh chóng.

Khi đọc từ file, danh sách sẽ được làm mới, sau đó sắp xếp theo mã số sinh viên trước khi hiển thị.
Giao diện Menu
Người dùng sẽ làm việc với chương trình thông qua menu điều khiển:

![Screenshot 2025-03-24 175734](https://github.com/user-attachments/assets/7155ede1-5636-47d8-8de4-c7b13d3686e3)

Người dùng nhập số từ 1-8 để chọn chức năng tương ứng.

Công nghệ sử dụng
Ngôn ngữ lập trình: C++

Thư viện: iostream, vector, fstream, algorithm, iomanip

Lưu trữ dữ liệu: File nhị phân (ctql.dat)
