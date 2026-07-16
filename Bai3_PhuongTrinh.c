#include <stdio.h>

int main() {
    // Khai báo biến hệ số a, b và nghiệm x kiểu số thực (float) để kết quả ra số thập phân chính xác
    float a, b;
    float x;

    printf("=== GIAI PHUONG TRINH BAC NHAT ax + b = 0 ===\n");

    // Nhập hệ số a và b từ bàn phím
    printf("Nhap he so a (a khac 0): ");
    scanf("%f", &a);

    printf("Nhap he so b: ");
    scanf("%f", &b);

    // Tính nghiệm theo công thức: x = -b / a
    x = -b / a;

    // Hiển thị kết quả làm tròn đến 2 chữ số thập phân
    printf("\nNghiem cua phuong trinh %.2fx + %.2f = 0 la: x = %.2f\n", a, b, x);

    return 0;
}