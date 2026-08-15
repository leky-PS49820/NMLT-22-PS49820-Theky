#include <stdio.h>
#include <string.h>

// Dinh nghia cau truc SinhVien
struct SinhVien {
    char mssv[50];
    char tenSV[50];
    char nganhHoc[50];
    float diemTB;
};

// Khai bao cac nguyen mau ham
void menu();
void nhapXuatSinhVien(struct SinhVien mangSV[], int *n);
void sapXepSinhVien(struct SinhVien mangSV[], int n);
void timKiemSinhVien(struct SinhVien mangSV[], int n);
void xuatHocBong(struct SinhVien mangSV[], int n);

int main() {
    struct SinhVien mangSV[100];
    int n = 0; // So luong sinh vien ban dau
    int chon;

    do {
        menu();
        printf(">> Xin moi chon chuc nang (1-5): ");
        if (scanf("%d", &chon) != 1) {
            while (getchar() != '\n');
            chon = 0;
        }

        switch (chon) {
            case 1:
                nhapXuatSinhVien(mangSV, &n);
                break;
            case 2:
                sapXepSinhVien(mangSV, n);
                break;
            case 3:
                timKiemSinhVien(mangSV, n);
                break;
            case 4:
                xuatHocBong(mangSV, n);
                break;
            case 5:
                printf("\nTam biet va hen gap lai!\n");
                break;
            default:
                printf("\nVui long chon chuc nang tu 1 đen 5!\n");
                break;
        }
    } while (chon != 5);

    return 0;
}

// Hàm hien thi Menu
void menu() {
    printf("\n+---------------------------------------------------+\n");
    printf("|        HE THONG QUAN LY SINH VIEN (LAB 8)         |\n");
    printf("+---------------------------------------------------+\n");
    printf("| 1. Nhap va Xuat danh sach sinh vien               |\n");
    printf("| 2. Sap xep sinh vien theo diem TB tang dan        |\n");
    printf("| 3. Tim kiem sinh vien theo Ma so sinh vien (MSSV) |\n");
    printf("| 4. Xuat danh sach sinh vien dat Hoc bong (>= 8.0) |\n");
    printf("| 5. Thoat chuong trinh                             |\n");
    printf("+---------------------------------------------------+\n");
}
// Chuc nang 1: Nhap va Xuat sinh vien
void nhapXuatSinhVien(struct SinhVien mangSV[], int *n) {
    printf("\n--- CHUC NANG 1: NHAP VA XUAT DANH SACH SINH VIEN ---\n");
    printf("Nhap so luong sinh vien: ");
    scanf("%d", n);
    getchar(); // Xoa bo nho dem ky tu xuong dong

    for (int i = 0; i < *n; i++) {
        printf("\n---> Nhap thong tin sinh vien thu %d:\n", i + 1);
        printf("MSSV: ");
        gets(mangSV[i].mssv);

        printf("Ho va Ten: ");
        gets(mangSV[i].tenSV);

        printf("Nganh hoc: ");
        gets(mangSV[i].nganhHoc);

        printf("Diem trung binh: ");
        scanf("%f", &mangSV[i].diemTB);
        getchar(); // Xoa ky tu xuong dong sau khi nhap diem
    }

    // Xuat danh sach
    printf("\n================ DANH SACH SINH VIEN ================\n");
    printf("%-12s | %-20s | %-15s | %-8s\n", "MSSV", "Ho va Ten", "Nganh Hoc", "Diem TB");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < *n; i++) {
        printf("%-12s | %-20s | %-15s | %-8.2f\n", 
               mangSV[i].mssv, mangSV[i].tenSV, mangSV[i].nganhHoc, mangSV[i].diemTB);
    }
}
// Chuc nang 2: Sap xep theo diem TB tang dan
void sapXepSinhVien(struct SinhVien mangSV[], int n) {
    if (n == 0) {
        printf("\nDanh sach rong! Vui long nhap sinh vien o Chuc nang 1 truoc.\n");
        return;
    }

    printf("\n--- CHUC NANG 2: SAP XEP SINH VIEN THEO DIEM TB TANG DAN ---\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mangSV[i].diemTB > mangSV[j].diemTB) {
                // Hoan vi 2 struct
                struct SinhVien temp = mangSV[i];
                mangSV[i] = mangSV[j];
                mangSV[j] = temp;
            }
        }
    }

    printf("\n=== DANH SACH SAU KHI SAP XEP TANG DAN THEO DIEM ===\n");
    printf("%-12s | %-20s | %-15s | %-8s\n", "MSSV", "Ho va Ten", "Nganh Hoc", "Diem TB");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-12s | %-20s | %-15s | %-8.2f\n", 
               mangSV[i].mssv, mangSV[i].tenSV, mangSV[i].nganhHoc, mangSV[i].diemTB);
    }
}
// Chuc nang 3: Tim kiem theo MSSV
void timKiemSinhVien(struct SinhVien mangSV[], int n) {
    if (n == 0) {
        printf("\nDanh sach rong! Vui long nhap sinh vien o Chuc nang 1 truoc.\n");
        return;
    }

    char mssvTim[50];
    getchar(); // Xoa bộ nho dem
    printf("\n--- CHUC NANG 3: TIM KIEM SINH VIEN THEO MSSV ---\n");
    printf("Nhap MSSV can tim: ");
    gets(mssvTim);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(mangSV[i].mssv, mssvTim) == 0) {
            printf("\n--> DA TIM THAY SINH VIEN:\n");
            printf("MSSV: %s\n", mangSV[i].mssv);
            printf("Ho va Ten: %s\n", mangSV[i].tenSV);
            printf("Nganh hoc: %s\n", mangSV[i].nganhHoc);
            printf("Diem TB: %.2f\n", mangSV[i].diemTB);
            found = 1;
            break; // Tim thay roi thi dung
        }
    }

    if (found == 0) {
        printf("\nKhong tim thay sinh vien co MSSV: %s!\n", mssvTim);
    }
}
// Chuc nang 4: Xuat danh sach Dat Hoc Bong (Diem TB >= 8.0)
void xuatHocBong(struct SinhVien mangSV[], int n) {
    if (n == 0) {
        printf("\nDanh sach rong! Vui long nhap sinh vien o Chuc nang 1 truoc.\n");
        return;
    }

    printf("\n--- CHUC NANG 4: DANH SACH SINH VIEN DAT HOC BONG (>= 8.0) ---\n");
    int count = 0;
    printf("%-12s | %-20s | %-15s | %-8s\n", "MSSV", "Ho va Ten", "Nganh Hoc", "Diem TB");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        if (mangSV[i].diemTB >= 8.0) {
            printf("%-12s | %-20s | %-15s | %-8.2f\n", 
                   mangSV[i].mssv, mangSV[i].tenSV, mangSV[i].nganhHoc, mangSV[i].diemTB);
            count++;
        }
    }

    if (count == 0) {
        printf("Khong co sinh vien nao dat hoc bong (Diem TB >= 8.0).\n");
    }
}
