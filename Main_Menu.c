#include <stdio.h>
#include <math.h>

// CHỨC NĂNG 1: Tính trung bình tổng các số chia hết cho 2 trong khoảng [min, max]
void tinhTrungBinhChiaHetCho2() {
    int min, max;
    int tong = 0;
    int bienDem = 0;

    printf("\n--- CHUC NANG 1: TINH TRUNG BINH TONG CAC SO CHIA HET CHO 2 ---\n");
    printf("Nhap gia tri min: ");
    scanf("%d", &min);
    printf("Nhap gia tri max: ");
    scanf("%d", &max);

    // Bắt lỗi nếu min > max
    if (min > max) {
        printf("Loi: Gia tri min phai nho hon hoac bang max!\n");
        return;
    }

    // Duyệt từ min đến max
    for (int i = min; i <= max; i++) {
        if (i % 2 == 0) {
            tong += i;
            bienDem++;
        }
    }

    // Kiểm tra để tránh lỗi chia cho 0
    if (bienDem == 0) {
        printf("Khong co so nao chia het cho 2 trong khoang [%d, %d].\n", min, max);
    } else {
        float trungBinh = (float)tong / bienDem;
        printf("Trung binh cong cac so chia het cho 2 tu %d den %d la: %.2f\n", min, max, trungBinh);
    }
}

// CHỨC NĂNG 2: Kiểm tra số nguyên tố
void kiemTraSoNguyenTo() {
    int x;
    int laSoNguyenTo = 1; // Giả sử x là số nguyên tố (1: đúng, 0: sai)

    printf("\n--- CHUC NANG 2: KIEM TRA SO NGUYEN TO ---\n");
    printf("Nhap so nguyen x: ");
    scanf("%d", &x);

    if (x < 2) {
        laSoNguyenTo = 0;
    } else {
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                laSoNguyenTo = 0; // Tìm thấy ước số khác -> Không phải SNT
                break;
            }
        }
    }

    if (laSoNguyenTo == 1) {
        printf("So %d LA so nguyen to.\n", x);
    } else {
        printf("So %d KHONG PHAI la so nguyen to.\n", x);
    }
}

// CHỨC NĂNG 3: Kiểm tra số chính phương
void kiemTraSoChinhPhuong() {
    int x;
    int laSoChinhPhuong = 0; // 0: sai, 1: đúng

    printf("\n--- CHUC NANG 3: KIEM TRA SO CHINH PHUONG ---\n");
    printf("Nhap so nguyen x: ");
    scanf("%d", &x);

    if (x > 0) {
        for (int i = 1; i * i <= x; i++) {
            if (i * i == x) {
                laSoChinhPhuong = 1;
                break;
            }
        }
    }

    if (laSoChinhPhuong == 1) {
        printf("So %d LA so chinh phuong.\n", x);
    } else {
        printf("So %d KHONG PHAI la so chinh phuong.\n", x);
    }
}

int main() {
    int luachon;

    // Vòng lặp do-while giữ Menu hiển thị liên tục
    do {
        printf("\n+---------------------------------------------------+\n");
        printf("|              MENU CHUONG TRINH LAB 4              |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Tinh trung binh tong cac so chia het cho 2     |\n");
        printf("| 2. Kiem tra So nguyen to                          |\n");
        printf("| 3. Kiem tra So chinh phuong                       |\n");
        printf("| 4. Thoat chuong trinh                            |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-4): ");
        scanf("%d", &luachon);

        switch (luachon) {
            case 1:
                tinhTrungBinhChiaHetCho2();
                break;
            case 2:
                kiemTraSoNguyenTo();
                break;
            case 3:
                kiemTraSoChinhPhuong();
                break;
            case 4:
                printf("\nDa thoat chuong trinh Lab 4. Tam biet!\n");
                break;
            default:
                printf("\nLua chon khong hop le! Vui long chon tu 1 den 4.\n");
                break;
        }
    } while (luachon != 4); // Lặp lại nếu người dùng chưa chọn 4

    return 0;
}