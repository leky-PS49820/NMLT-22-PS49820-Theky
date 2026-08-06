#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>

void menu();
void chucNang1();
void chucNang2();
void chucNang3();
void chucNang4();
void chucNang5();

float tinhTrungBinhCong(int a[], int n);
void timMaxMin(int a[], int n);
void sapXepGiamDan(int a[], int n);
void maTranBinhPhuong(int row, int col);
void locSoLeMaTran(int row, int col);
void swap(int *a, int *b);

int main() {
    int chon;
    do {
        menu();
        printf(">> Xin moi chon chuc nang (1-6): ");
        if (scanf("%d", &chon) != 1) {
            while (getchar() != '\n'); // Xoa bo nho dem chong lap vo tan
            chon = 0;
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
                chucNang5();
                break;
            case 6:
                printf("\nTam biet!\n");
                break;
            default:
                printf("\nBan phai chon chuc nang tu 1 - 6!\n");
                break;
        }
    } while (chon != 6);

    return 0;
}

void menu() {
    printf("\n+---------------------------------------------------+\n");
    printf("|              MENU CHUONG TRINH LAB 6              |\n");
    printf("+---------------------------------------------------+\n");
    printf("| 1. Tinh trung binh tong so chia het cho 3 va 5    |\n");
    printf("| 2. Tim gia tri Lon nhat va Nho nhat trong Mang    |\n");
    printf("| 3. Sap xep Mang theo thu tu Giam dan              |\n");
    printf("| 4. Ma tran binh phuong (Mang 2 chieu)             |\n");
    printf("| 5. Loc va xuat vi tri cac So le trong Ma tran     |\n");
    printf("| 6. Thoat chuong trinh                             |\n");
    printf("+---------------------------------------------------+\n");
}

void chucNang1() {
    int n;
    int a[100];
    printf("\n--- Chuc nang 1: Tinh TBC chia het cho 3 va 5 ---\n");
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap A[%d] = ", i);
        scanf("%d", &a[i]);
    }

    float tbc = tinhTrungBinhCong(a, n);
    if (tbc == -FLT_MAX) {
        printf("Khong co so nao chia het cho ca 3 va 5!\n");
    } else {
        printf("Trung binh cong cac so chia het cho 3 va 5: %.2f\n", tbc);
    }
}

void chucNang2() {
    int n;
    int a[100];
    printf("\n--- Chuc nang 2: Tim Max va Min trong mang ---\n");
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap A[%d] = ", i);
        scanf("%d", &a[i]);
    }

    timMaxMin(a, n);
}

void chucNang3() {
    int n;
    int a[100];
    printf("\n--- Chuc nang 3: Sap xep mang giam dan ---\n");
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap A[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("Mang sau khi sap xep giam dan: ");
    sapXepGiamDan(a, n);
}

void chucNang4() {
    int row, col;
    printf("\n--- Chuc nang 4: Ma tran binh phuong ---\n");
    printf("Nhap so hang (row): ");
    scanf("%d", &row);
    printf("Nhap so cot (col): ");
    scanf("%d", &col);

    maTranBinhPhuong(row, col);
}

void chucNang5() {
    int row, col;
    printf("\n--- Chuc nang 5: Loc so le trong Ma tran ---\n");
    printf("Nhap so hang (row): ");
    scanf("%d", &row);
    printf("Nhap so cot (col): ");
    scanf("%d", &col);

    locSoLeMaTran(row, col);
}

// --- CAC HAM XU LY LOGIC ---

float tinhTrungBinhCong(int a[], int n) {
    int tong = 0;
    int soDem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 3 == 0 && a[i] % 5 == 0) {
            tong += a[i];
            soDem++;
        }
    }
    if (soDem == 0) {
        return -FLT_MAX;
    } else {
        return (float)tong / soDem;
    }
}

void timMaxMin(int a[], int n) {
    int min = a[0];
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (min > a[i]) {
            min = a[i];
        }
        if (max < a[i]) {
            max = a[i];
        }
    }
    printf("Gia tri Min = %d\t Gia tri Max = %d\n", min, max);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sapXepGiamDan(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) { // Dung dau < de sap xep GIAM DAN
                swap(&a[i], &a[j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void maTranBinhPhuong(int row, int col) {
    int a[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nMa tran binh phuong ket qua:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%4d\t", a[i][j] * a[i][j]);
        }
        printf("\n");
    }
}

void locSoLeMaTran(int row, int col) {
    int a[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nCac so le va vi tri trong ma tran:\n");
    int soDemLe = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (a[i][j] % 2 != 0) { // Kiem tra so le
                printf("Gia tri: %d \t vi tri hang %d, cot %d [A[%d][%d]]\n", a[i][j], i, j, i, j);
                soDemLe++;
            }
        }
    }
    if (soDemLe == 0) {
        printf("Khong co so le nao trong ma tran!\n");
    }
}
