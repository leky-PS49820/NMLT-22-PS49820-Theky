#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Khai báo nguyên mẫu hàm (Function Prototypes)
void menu();
void demNguyenAmPhuAm();
void kiemTraDangNhap();
void sapXepChuoi();
void thapPhanSangNhiPhan();

int main() {
    int chon;
    do {
        menu();
        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &chon);
        switch (chon) {
            case 1: demNguyenAmPhuAm(); break;
            case 2: kiemTraDangNhap(); break;
            case 3: sapXepChuoi(); break;
            case 4: thapPhanSangNhiPhan(); break;
            case 5: printf("Thoat chuong trinh. Tam biet!\n"); break;
            default: printf("Ban phai chon chuc nang tu 1 - 5\n"); break;
        }
    } while (chon != 5);
    return 0;
}

void menu() {
    printf("\n+---------------------------------------------------+");
    printf("\n|            MENU CHUONG TRINH LAB 7                |");
    printf("\n+---------------------------------------------------+");
    printf("\n| 1. Dem Nguyen am va Phu am trong chuoi           |");
    printf("\n| 2. Dang nhap he thong (User & Password)          |");
    printf("\n| 3. Sap xep danh sach Chuoi theo thu tu Alphabet  |");
    printf("\n| 4. Chuyen doi so Thap phan sang Nhi phan (Chuoi) |");
    printf("\n| 5. Thoat chuong trinh                             |");
    printf("\n+---------------------------------------------------+\n");
}

// Khung hàm rỗng để chương trình không bị lỗi biên dịch
// Chức năng 1: Đếm Nguyên âm và Phụ âm trong chuỗi
void demNguyenAmPhuAm() {
    char s[100];
    int demNA = 0, demPA = 0;

    printf("\n--- CHUC NANG 1: DEM NGUYEN AM VA PHU AM ---\n");
    printf("Nhap chuoi ky tu: ");
    while (getchar() != '\n'); // Xóa bộ nhớ đệm
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Xóa ký tự xuống dòng

    for (int i = 0; s[i] != '\0'; i++) {
        char c = tolower((unsigned char)s[i]);
        if (isalpha((unsigned char)c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                demNA++;
            } else {
                demPA++;
            }
        }
    }

    printf("-> So nguyen am: %d\n", demNA);
    printf("-> So phu am: %d\n", demPA);
}
// Chức năng 2: Đăng nhập hệ thống (User & Password)
void kiemTraDangNhap() {
    char userSys[] = "admin";
    char passSys[] = "123456";
    char user[50], pass[50];

    printf("\n--- CHUC NANG 2: DANG NHAP HE THONG ---\n");
    printf("Nhap User: ");
    scanf("%s", user);
    printf("Nhap Pass: ");
    scanf("%s", pass);

    if (strcmp(user, userSys) == 0 && strcmp(pass, passSys) == 0) {
        printf(">> Dang nhap thanh cong!\n");
    } else {
        printf(">> Username hoac Password khong chinh xac!\n");
    }
}
// Chức năng 3: Sắp xếp danh sách Chuỗi theo thứ tự Alphabet
void sapXepChuoi() {
    char s[5][50];
    char temp[50];
    printf("\n--- CHUC NANG 3: SAP XEP DANH SACH CHUOI ---\n");
    while (getchar() != '\n'); // Xóa bộ nhớ đệm
    for (int i = 0; i < 5; i++) {
        printf("Nhap chuoi [%d]: ", i + 1);
        fgets(s[i], sizeof(s[i]), stdin);
        s[i][strcspn(s[i], "\n")] = '\0';
    }

    // Thuật toán hoán vị sắp xếp Alphabet
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (strcmp(s[i], s[j]) > 0) {
                strcpy(temp, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], temp);
            }
        }
    }

    printf("\nDanh sach chuoi sau khi sap xep tang dan (Alphabet):\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, s[i]);
    }
}
// Chức năng 4: Chuyển đổi số Thập phân sang Nhị phân (Chuỗi)
void thapPhanSangNhiPhan() {
    int n;
    printf("\n--- CHUC NANG 4: CHUYEN THAP PHAN SANG NHI PHAN ---\n");
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Vui long nhap so nguyen duong (> 0)!\n");
        return;
    }

    char nhiPhan[50];
    int len = 0;
    int tempN = n;

    while (tempN > 0) {
        nhiPhan[len++] = (tempN % 2) + '0';
        tempN /= 2;
    }
    nhiPhan[len] = '\0';

    printf("Ket qua nhi phan cua %d la: ", n);
    for (int i = len - 1; i >= 0; i--) {
        putchar(nhiPhan[i]);
    }
    printf("\n");
}
