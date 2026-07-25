#include <stdio.h>

// Khai báo hàm cho Chức năng 1
void tinhHocLuc() {
    float diem;

    printf("\n--- CHUC NANG 1: TINH HOC LUC SINH VIEN ---\n");
    printf("Nhap diem so cua sinh vien (0.0 - 10.0): ");
    scanf("%f", &diem);

    // Bắt lỗi đầu vào ngoài phạm vi 0.0 - 10.0
    if (diem < 0.0 || diem > 10.0) {
        printf("Diem so nhap vao khong hop le!\n");
    } else {
        // Phân loại học lực bằng cấu trúc if-else bậc thang
        if (diem >= 9.0) {
            printf("Hoc luc: Xuat sac\n");
        } else if (diem >= 8.0) {
            printf("Hoc luc: Gioi\n");
        } else if (diem >= 6.5) {
            printf("Hoc luc: Kha\n");
        } else if (diem >= 5.0) {
            printf("Hoc luc: Trung binh\n");
        } else if (diem >= 3.5) {
            printf("Hoc luc: Yeu\n");
        } else {
            printf("Hoc luc: Kem\n");
        }
    }
}

int main() {
    int luachon;

    // Hiển thị khung Menu
    printf("+---------------------------------------------------+\n");
    printf("|              MENU CHUONG TRINH LAB 3              |\n");
    printf("+---------------------------------------------------+\n");
    printf("| 1. Chuc nang tinh hoc luc sinh vien               |\n");
    printf("| 2. Chuc nang giai phuong trinh bac hai            |\n");
    printf("| 3. Chuc nang tinh tien dien tieu thu hang thang   |\n");
    printf("| 4. Thoat chuong trinh                            |\n");
    printf("+---------------------------------------------------+\n");
    printf(">> Chon chuc nang cua ban (1-4): ");
    scanf("%d", &luachon);

    // Điều khiển các chức năng bằng switch-case
    switch (luachon) {
        case 1:
            tinhHocLuc();
            break;
        case 2:
            printf("\nChuc nang 2 dang duoc phat triển...\n");
            break;
        case 3:
            printf("\nChuc nang 3 dang duoc phat triển...\n");
            break;
        case 4:
            printf("\nDa thoat chuong trinh!\n");
            break;
        default:
            printf("\nLua chon khong hop le! Vui long chon tu 1 den 4.\n");
            break;
    }

    return 0;
}