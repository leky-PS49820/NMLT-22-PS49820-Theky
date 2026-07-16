#include <stdio.h>

// Định nghĩa hằng số PI cho bài toán hình tròn
#define PI 3.14159

int main() {
    // === BÀI TOÁN 1: HÌNH CHỮ NHẬT ===
    float chieuDai, chieuRong;
    float chuViHCN, dienTichHCN;

    printf("=== TINH TOAN HINH CHU NHAT ===\n");
    printf("Nhap chieu dai: ");
    scanf("%f", &chieuDai);
    printf("Nhap chieu rong: ");
    scanf("%f", &chieuRong);

    // Công thức tính toán hình chữ nhật
    chuViHCN = (chieuDai + chieuRong) * 2;
    dienTichHCN = chieuDai * chieuRong;

    printf("-> Chu vi HCN: %.2f\n", chuViHCN);
    printf("-> Dien tich HCN: %.2f\n\n", dienTichHCN);


    // === BÀI TOÁN 2: HÌNH TRÒN ===
    float banKinh;
    float chuViTron, dienTichTron;

    printf("=== TINH TOAN HINH TRON ===\n");
    printf("Nhap ban kinh: ");
    scanf("%f", &banKinh);

    // Công thức tính toán hình tròn
    chuViTron = 2 * PI * banKinh;
    dienTichTron = PI * banKinh * banKinh;

    printf("-> Chu vi hinh tron: %.2f\n", chuViTron);
    printf("-> Dien tich hinh tron: %.2f\n", dienTichTron);

    return 0;
}