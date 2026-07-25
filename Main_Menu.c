#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int chon;

    do {
        printf("+---------------------------------------------------+\n");
        printf("|           MENU CHUONG TRINH LAB 4                 |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Tinh trung binh tong cac so chia het cho 2     |\n");
        printf("| 2. Kiem tra So nguyen to                          |\n");
        printf("| 3. Kiem tra So chinh phuong                       |\n");
        printf("| 4. Thoat chuong trinh                             |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-4): ");
        scanf("%d", &chon);

        switch (chon) {
           case 1: {
                int min, max;
                int tong = 0;
                int bienDem = 0;

                printf("\n--- CHUC NANG 1: TINH TRUNG BINH TONG CAC SO CHIA HET CHO 2 ---\n");
                printf("Nhap vao gia tri min: ");
                scanf("%d", &min);
                printf("Nhap vao gia tri max: ");
                scanf("%d", &max);

                // Xuly truong hop nguoi dung nhap min > max
                if (min > max) {
                    printf("Loi: Gia tri min phai nho hon hoac bang max!\n\n");
                    break;
                }

                // Duyet cac so tu min den max bang vong lap for
                for (int i = min; i <= max; i++) {
                    if (i % 2 == 0) {
                        tong += i;
                        bienDem++;
                    }
                }

                // Bat loi chia cho 0 (division by zero)
                if (bienDem == 0) {
                    printf("Khong co so nao chia het cho 2 trong khoang [%d, %d].\n\n", min, max);
                } else {
                    float trungBinh = (float)tong / bienDem;
                    printf("Trung binh tong cac so chia het cho 2 tu %d den %d la: %.2f\n\n", min, max, trungBinh);
                }
                break;
            }
            case 2:
                printf("\n--- Chuc nang 2 dang duoc phat trien ---\n\n");
                break;
            case 3:
                printf("\n--- Chuc nang 3 dang duoc phat trien ---\n\n");
                break;
            case 4:
                printf("\nCam on ban da su dung chuong trinh. Tam biet!\n");
                break;
            default:
                printf("\nChuc nang khong hop le. Vui long chon tu 1 den 4!\n\n");
                break;
        }

    } while (chon != 4);

    return 0;
}