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