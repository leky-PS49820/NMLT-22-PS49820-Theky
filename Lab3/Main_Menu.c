#include <stdio.h>
#include <math.h>

// CHỨC NĂNG 1: Tính học lực sinh viên
void tinhHocLuc() {
    float diem;

    printf("\n--- CHUC NANG 1: TINH HOC LUC SINH VIEN ---\n");
    printf("Nhap diem so cua sinh vien (0.0 - 10.0): ");
    scanf("%f", &diem);

    if (diem < 0.0 || diem > 10.0) {
        printf("Diem so nhap vao khong hop le!\n");
    } else {
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

// CHỨC NĂNG 2: Giải phương trình bậc hai tổng quát
void giaiPTBacHai() {
    float a, b, c;

    printf("\n--- CHUC NANG 2: GIAI PHUONG TRINH BAC HAI ---\n");
    printf("Nhap he so a: ");
    scanf("%f", &a);
    printf("Nhap he so b: ");
    scanf("%f", &b);
    printf("Nhap he so c: ");
    scanf("%f", &c);

    // TRƯỜNG HỢP 1: a == 0 (Phương trình bậc nhất bx + c = 0)
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Phuong trinh co vo so nghiem.\n");
            } else {
                printf("Phuong trinh vo nghiem.\n");
            }
        } else {
            float x = -c / b;
            printf("Phuong trinh tro thanh bac nhat, co nghiem duy nhat x = %.2f\n", x);
        }
    } 
    // TRƯỜNG HỢP 2: a != 0 (Phương trình bậc hai ax^2 + bx + c = 0)
    else {
        float delta = b * b - 4 * a * c;

        if (delta < 0) {
            printf("Phuong trinh vo nghiem (Delta < 0).\n");
        } else if (delta == 0) {
            float x = -b / (2 * a);
            printf("Phuong trinh co nghiem kep x = %.2f\n", x);
        } else {
            float x1 = (-b + sqrt(delta)) / (2 * a);
            float x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Phuong trinh co 2 nghiem phan biet:\n");
            printf("  x1 = %.2f\n", x1);
            printf("  x2 = %.2f\n", x2);
        }
    }
}

// CHỨC NĂNG 3: Tính tiền điện lũy tiến
void tinhTienDien() {
    float kWh;
    double tongTien = 0;

    printf("\n--- CHUC NANG 3: TINH TIEN DIEN TIEU THU HANG THANG ---\n");
    printf("Nhap tong so kWh dien tieu thu trong thang: ");
    scanf("%f", &kWh);

    if (kWh < 0) {
        printf("So kWh dien phai la so duong (>= 0)!\n");
    } else {
        // Tính tiền theo từng bậc lũy tiến
        if (kWh <= 50) {
            tongTien = kWh * 1678;
        } else if (kWh <= 100) {
            tongTien = 50 * 1678 + (kWh - 50) * 1734;
        } else if (kWh <= 200) {
            tongTien = 50 * 1678 + 50 * 1734 + (kWh - 100) * 2014;
        } else if (kWh <= 300) {
            tongTien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kWh - 200) * 2536;
        } else if (kWh <= 400) {
            tongTien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kWh - 300) * 2834;
        } else {
            tongTien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kWh - 400) * 2927;
        }

        printf("Tong so tien dien phai trả la: %.0f VND\n", tongTien);
    }
}

int main() {
    int luachon;

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

    switch (luachon) {
        case 1:
            tinhHocLuc();
            break;
        case 2:
            giaiPTBacHai();
            break;
        case 3:
            tinhTienDien();
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