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
            case 1:
                printf("\n--- Chuc nang 1 dang duoc phat trien ---\n\n");
                break;
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