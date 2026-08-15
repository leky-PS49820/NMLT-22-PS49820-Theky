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
