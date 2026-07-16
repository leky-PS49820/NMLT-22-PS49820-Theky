#include <stdio.h>

int main() {
    // Khai báo biến điểm số cho 3 môn (dùng kiểu float vì điểm có thể lẻ)
    float toan, ly, hoa;
    float diemTB;

    printf("=== CHUONG TRINH QUAN LY DIEM SO ===\n");

    // Nhập dữ liệu từ bàn phím
    printf("Nhap diem mon Toan: ");
    scanf("%f", &toan);

    printf("Nhap diem mon Ly: ");
    scanf("%f", &ly);

    printf("Nhap diem mon Hoa: ");
    scanf("%f", &hoa);

    /* VẬN DỤNG KỸ THUẬT ÉP KIỂU (CASTING):
       Ép tổng điểm sang kiểu (float) trước khi thực hiện phép chia cho 6,
       đảm bảo kết quả thu về là số thực chính xác và tránh lỗi chia nguyên (integer division).
    */
    diemTB = (float)(toan * 3 + ly * 2 + hoa) / 6;

    // Hiển thị kết quả làm tròn đúng 2 chữ số thập phân bằng cách dùng %.2f
    printf("\nDiem trung binh cua ban la: %.2f\n", diemTB);

    return 0;
}