#include <stdio.h>
#include <stdbool.h>

// Khai bao nguyen mau ham
void menu();
void chucNang1();
void chucNang2();
void chucNang3();
void chucNang4();

int soLonNhat(int a, int b, int c);
bool kiemTraNamNhuan(int nam);
void swap(int *a, int *b);
const char* checkTriangle(float a, float b, float c);

int main() {
    int chon;
    do {
        menu();
        printf(">> Xin moi chon chuc nang (1-5): ");
        
        // Nhap va kiem tra neu nhap sai kieu du lieu
        if (scanf("%d", &chon) != 1) {
            while (getchar() != '\n'); // Xoa bo nho dem chong lap vo tan
            chon = 0; // Gan gia tri mac dinh de bao loi default
        }

        switch (chon) {
            case 1:
                chucNang1();
                break;
            case 2:
                chucNang2();
                break;
            case 3:
                chucNang3();
                break;
            case 4:
                chucNang4();
                break;
            case 5:
                printf("\nTam biet!\n");
                break;
            default:
                printf("\nBan phai chon chuc nang tu 1 - 5!\n");
                break;
        }
    } while (chon != 5);

    return 0;
}

void menu() {
    printf("\n+---------------------------------------------------+\n");
    printf("|              MENU CHUONG TRINH LAB 5              |\n");
    printf("+---------------------------------------------------+\n");
    printf("| 1. Tim gia tri lon nhat trong 3 so                |\n");
    printf("| 2. Kiem tra Nam nhuan                             |\n");
    printf("| 3. Hoan vi 2 so (Su dung Con tro)                 |\n");
    printf("| 4. Kiem tra & Phan loai Tam giac                  |\n");
    printf("| 5. Thoat chuong trinh                             |\n");
    printf("+---------------------------------------------------+\n");
}

void chucNang1() {
    int a, b, c;
    printf("\n--- Chuc nang 1: Tim so lon nhat ---\n");
    printf("Nhap a, b, c: ");
    scanf("%d%d%d", &a, &b, &c);
    printf("So lon nhat la: %d\n", soLonNhat(a, b, c));
}

int soLonNhat(int a, int b, int c) {
    int lonNhat = a;
    if (lonNhat < b) {
        lonNhat = b;
    }
    if (lonNhat < c) {
        lonNhat = c;
    }
    return lonNhat;
}

void chucNang2() {
    int nam;
    printf("\n--- Chuc nang 2: Kiem tra nam nhuan ---\n");
    printf("Nhap nam: ");
    scanf("%d", &nam);
    if (kiemTraNamNhuan(nam)) {
        printf("Nam %d la nam nhuan.\n", nam);
    } else {
        printf("Nam %d khong phai la nam nhuan.\n", nam);
    }
}

bool kiemTraNamNhuan(int nam) {
    if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
        return true;
    else
        return false;
}

void chucNang3() {
    int x, y;
    printf("\n--- Chuc nang 3: Hoan vi 2 so ---\n");
    printf("Nhap hai so x, y: ");
    scanf("%d%d", &x, &y);
    printf("Truoc khi hoan vi: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("Sau khi hoan vi:   x = %d, y = %d\n", x, y);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void chucNang4() {
    float a, b, c;
    printf("\n--- Chuc nang 4: Kiem tra & Phan loai tam giac ---\n");
    printf("Nhap 3 canh a, b, c: ");
    scanf("%f%f%f", &a, &b, &c);
    printf("Ket qua: %s\n", checkTriangle(a, b, c));
}

const char* checkTriangle(float a, float b, float c) {
    if (a + b > c && a + c > b && b + c > a && a > 0 && b > 0 && c > 0) {
        if (a == b && b == c)
            return "Tam giac deu.";
        else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
            if (a == b || a == c || b == c)
                return "Tam giac vuong can.";
            else
                return "Tam giac vuong.";
        } else if (a == b || a == c || b == c) {
            return "Tam giac can.";
        } else
            return "Tam giac thuong.";
    } else {
        return "Khong phai la bo 3 canh cua tam giac.";
    }
}
