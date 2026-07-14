#include <stdio.h>

int main() {
    // 1. Khai báo các biến chứa thông tin sinh viên
    char mssv[50];
    char hoTen[100];
    int namSinh;
    float diemTB;
    int tuoi;

    // 2. Nhập thông tin sinh viên từ bàn phím
    printf("Nhap ma so sinh vien: ");
    scanf("%s", mssv); // Nhập chuỗi liền không dấu cách (ví dụ: PS49820)

    // Xóa bộ nhớ đệm để tránh bị trôi lệnh khi nhập chuỗi tiếp theo
    while (getchar() != '\n'); 

    printf("Nhap Ho va Ten: ");
    fgets(hoTen, sizeof(hoTen), stdin);
    
    // Xóa ký tự xuống dòng '\n' do lệnh fgets tự động nhận ở cuối chuỗi
    for (int i = 0; hoTen[i] != '\0'; i++) {
        if (hoTen[i] == '\n') {
            hoTen[i] = '\0';
            break;
        }
    }

    printf("Nhap Nam sinh: ");
    scanf("%d", &namSinh);

    printf("Nhap Diem Trung Binh: ");
    scanf("%f", &diemTB);

    // 3. Tự động tính toán tuổi dựa trên năm hiện tại 2026
    tuoi = 2026 - namSinh;

    // 4. Xuất kết quả ra màn hình theo đúng định dạng mẫu của đề bài
    printf("\nNHAP MON LAP TRINH\n");
    printf("-----------------------------------\n");
    printf("Ma so sinh vien: %s\n", mssv);
    printf("Ho Va Ten: %s\n", hoTen);
    printf("Nam sinh: %d\n", namSinh);
    printf("Tuoi: %d\n", tuoi);
    printf("Diem Trung Binh: %.2f\n", diemTB);

    return 0;
}