#include <stdio.h>

int main() {
    // 1. Khai báo các biến lưu trữ dữ liệu
    char mssv[50];
    char hoTen[100];
    float diemToan, diemLy, diemHoa;
    float diemTrungBinh;

    // 2. Nhập thông tin sinh viên và điểm số từ bàn phím
    printf("Nhap ma so sinh vien: ");
    scanf("%s", mssv); // Nhập chuỗi liền không khoảng cách

    // Xóa bộ nhớ đệm để tránh trôi lệnh fgets kế tiếp
    while (getchar() != '\n'); 

    printf("Nhap Ho va Ten: ");
    fgets(hoTen, sizeof(hoTen), stdin);
    
    // Xóa ký tự xuống dòng '\n' thừa ở cuối chuỗi do fgets tạo ra
    for (int i = 0; hoTen[i] != '\0'; i++) {
        if (hoTen[i] == '\n') {
            hoTen[i] = '\0';
            break;
        }
    }

    printf("Nhap diem Toan: ");
    scanf("%f", &diemToan);

    printf("Nhap diem Ly: ");
    scanf("%f", &diemLy);

    printf("Nhap diem Hoa: ");
    scanf("%f", &diemHoa);

    // 3. Tính điểm trung bình có nhân hệ số theo công thức đề bài cho
    diemTrungBinh = (diemToan * 2 + diemLy + diemHoa) / 4;

    // 4. Xuất thông tin ra màn hình theo đúng định dạng mẫu
    printf("\n-----------------------------------\n");
    printf("Ma so sinh vien: %s\n", mssv);
    printf("Ho Va Ten: %s\n", hoTen);
    printf("Diem Trung Binh: %.2f\n", diemTrungBinh); // Làm tròn 2 chữ số thập phân

    return 0;
}