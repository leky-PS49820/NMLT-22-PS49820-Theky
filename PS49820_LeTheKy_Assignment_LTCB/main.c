#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

// ==========================================
// HÀM BỔ TRỢ HỆ THỐNG
// ==========================================

void xoaBoDem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int findUCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long findBCNN(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return (long long)abs(a) * abs(b) / findUCLN(a, b);
}

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

bool isPerfectSquare(int x) {
    if (x < 0) return false;
    int sq = (int)sqrt(x);
    return (sq * sq == x);
}

typedef struct {
    int tu;
    int mau;
} PhanSo;

PhanSo rutGonPhanSo(PhanSo ps) {
    int ucln = findUCLN(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
    if (ps.mau < 0) { // Đưa dấu âm lên tử số
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
    return ps;
}

typedef struct {
    char hoTen[50];
    float diem;
    char hocLuc[20];
} SinhVien;

// ==========================================
// 10 CHỨC NĂNG CỦA ASSIGNMENT
// ==========================================

// --- CHỨC NĂNG 1 ---
void chucNang1() {
    float x_input;
    printf("\n=== CHUC NANG 1: KIEM TRA SO NGUYEN ===\n");
    printf("Nhap vao so x: ");
    scanf("%f", &x_input);

    if (x_input == (int)x_input) {
        int x = (int)x_input;
        printf("-> %d LA SO NGUYEN.\n", x);
        
        if (isPrime(x)) printf("-> %d LA SO NGUYEN TO.\n", x);
        else printf("-> %d KHONG PHAI so nguyen to.\n", x);

        if (isPerfectSquare(x)) printf("-> %d LA SO CHINH PHUONG.\n", x);
        else printf("-> %d KHONG PHAI so chinh phuong.\n", x);
    } else {
        printf("-> %.2f KHONG PHAI so nguyen.\n", x_input);
    }
}

// --- CHỨC NĂNG 2 ---
void chucNang2() {
    int x, y;
    printf("\n=== CHUC NANG 2: TIM UCLN VA BCNN ===\n");
    printf("Nhap so nguyen x: "); scanf("%d", &x);
    printf("Nhap so nguyen y: "); scanf("%d", &y);

    int ucln = findUCLN(x, y);
    long long bcnn = findBCNN(x, y);

    printf("-> UCLN cua %d va %d la: %d\n", x, y, ucln);
    if (bcnn == 0) printf("-> BCNN khong xac dinh do co so 0.\n");
    else printf("-> BCNN cua %d va %d la: %lld\n", x, y, bcnn);
}

// --- CHỨC NĂNG 3 ---
void chucNang3() {
    int gioBatDau, gioKetThuc;
    printf("\n=== CHUC NANG 3: TINH TIEN KARAOKE ===\n");
    printf("Nhap gio bat dau (12h - 23h): "); scanf("%d", &gioBatDau);
    printf("Nhap gio ket thuc (12h - 23h): "); scanf("%d", &gioKetThuc);

    if (gioBatDau < 12 || gioKetThuc > 23 || gioBatDau >= gioKetThuc) {
        printf("Loi: Quan chi mo cua 12h-23h va gio ket thuc phai lon hon gio bat dau!\n");
        return;
    }

    int tongGio = gioKetThuc - gioBatDau;
    double tongTien = 0;

    if (tongGio <= 3) {
        tongTien = tongGio * 150000;
    } else {
        tongTien = (3 * 150000) + ((tongGio - 3) * 150000 * 0.7);
    }

    if (gioBatDau >= 14 && gioBatDau <= 17) {
        tongTien *= 0.9; // Giảm 10%
    }

    printf("-> So gio hat: %d gio\n", tongGio);
    printf("-> Tong tien thanh toan: %.0f VNĐ\n", tongTien);
}

// --- CHỨC NĂNG 4 ---
void chucNang4() {
    float kwh;
    double tongTien = 0;

    printf("\n=== CHUC NANG 4: TINH TIEN DIEN ===\n");
    printf("Nhap so kWh dien su dung: "); scanf("%f", &kwh);

    if (kwh < 0) {
        printf("Loi: So kWh khong duoc am!\n");
        return;
    }

    if (kwh <= 50) tongTien = kwh * 1678;
    else if (kwh <= 100) tongTien = (50 * 1678) + ((kwh - 50) * 1734);
    else if (kwh <= 200) tongTien = (50 * 1678) + (50 * 1734) + ((kwh - 100) * 2014);
    else if (kwh <= 300) tongTien = (50 * 1678) + (50 * 1734) + (100 * 2014) + ((kwh - 200) * 2536);
    else if (kwh <= 400) tongTien = (50 * 1678) + (50 * 1734) + (100 * 2014) + (100 * 2536) + ((kwh - 300) * 2834);
    else tongTien = (50 * 1678) + (50 * 1734) + (100 * 2014) + (100 * 2536) + (100 * 2834) + ((kwh - 400) * 2927);

    printf("-> So kWh: %.1f\n", kwh);
    printf("-> Tong tien dien: %.0f VNĐ\n", tongTien);
}

// --- CHỨC NĂNG 5 ---
void chucNang5() {
    int soTien;
    int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int n = sizeof(menhGia) / sizeof(menhGia[0]);

    printf("\n=== CHUC NANG 5: DOI TIEN ===\n");
    printf("Nhap so tien can doi: "); scanf("%d", &soTien);

    if (soTien <= 0) {
        printf("Loi: So tien phai lon hon 0!\n");
        return;
    }

    printf("-> So tien %d duoc doi ra:\n", soTien);
    int temp = soTien;
    for (int i = 0; i < n; i++) {
        int soTo = temp / menhGia[i];
        if (soTo > 0) {
            printf("   - %d to mệnh gia %d\n", soTo, menhGia[i]);
            temp %= menhGia[i];
        }
    }
}

// --- CHỨC NĂNG 6 ---
void chucNang6() {
    double tienVay;
    printf("\n=== CHUC NANG 6: TINH LAI SUAT VAY NGAN HANG TRA GOP ===\n");
    printf("Nhap so tien muon vay (VNĐ): "); scanf("%lf", &tienVay);

    if (tienVay <= 0) {
        printf("Loi: So tien vay phai lon hon 0!\n");
        return;
    }

    double gocPhaiTra = tienVay / 12;
    double tienConLai = tienVay;
    double laiSuat = 0.05; // 5%

    printf("\n----------------------------------------------------------------------\n");
    printf("| %-7s | %-15s | %-15s | %-15s | %-15s |\n", "Ky han", "Lai phai tra", "Goc phai tra", "So tien tra", "Tien con lai");
    printf("----------------------------------------------------------------------\n");

    for (int i = 1; i <= 12; i++) {
        double laiPhaiTra = tienConLai * laiSuat;
        double soTienPhaiTra = gocPhaiTra + laiPhaiTra;
        tienConLai -= gocPhaiTra;
        if (tienConLai < 0) tienConLai = 0;

        printf("| %-7d | %-15.0f | %-15.0f | %-15.0f | %-15.0f |\n", 
               i, laiPhaiTra, gocPhaiTra, soTienPhaiTra, tienConLai);
    }
    printf("----------------------------------------------------------------------\n");
}

// --- CHỨC NĂNG 7 ---
void chucNang7() {
    float pctVay;
    double giaTriXe = 500000000; // 500 triệu

    printf("\n=== CHUC NANG 7: VAY TIEN MUA XE ===\n");
    printf("Nhap %s vay toi da (vi du 80): ", "%");
    scanf("%f", &pctVay);

    if (pctVay <= 0 || pctVay > 100) {
        printf("Loi: Phan tram vay khong hop le!\n");
        return;
    }

    double pctTraTruoc = 100.0 - pctVay;
    double tienTraTruoc = giaTriXe * (pctTraTruoc / 100.0);
    double tienVay = giaTriXe * (pctVay / 100.0);

    int soThang = 24 * 12; // 288 tháng
    double laiSuatThang = 0.072 / 12; // 7.2%/năm
    double gocHangThang = tienVay / soThang;
    double laiThangDau = tienVay * laiSuatThang;

    printf("\n--- KET QUA TINH TOAN VAY MUA XE ---\n");
    printf("-> Gia tri xe: %.0f VNĐ\n", giaTriXe);
    printf("-> So tien TRẢ TRƯỚC (%.1f%%): %.0f VNĐ\n", pctTraTruoc, tienTraTruoc);
    printf("-> So tien VAY (%.1f%%): %.0f VNĐ\n", pctVay, tienVay);
    printf("-> Thoi han vay: 24 nam (%d thang)\n", soThang);
    printf("-> Goc phai tra hang thang: %.0f VNĐ\n", gocHangThang);
    printf("-> Tien phai tra THÁNG ĐẦU TIÊN (Goc + Lai): %.0f VNĐ\n", gocHangThang + laiThangDau);
}

// --- CHỨC NĂNG 8 ---
void chucNang8() {
    int n;
    printf("\n=== CHUC NANG 8: SAP XEP THONG TIN SINH VIEN ===\n");
    printf("Nhap so luong sinh vien: "); scanf("%d", &n);

    if (n <= 0) {
        printf("Loi: So luong sinh vien phai lon hon 0!\n");
        return;
    }

    SinhVien ds[100];
    for (int i = 0; i < n; i++) {
        xoaBoDem();
        printf("\nNhap ho ten SV %d: ", i + 1);
        fgets(ds[i].hoTen, sizeof(ds[i].hoTen), stdin);
        ds[i].hoTen[strcspn(ds[i].hoTen, "\n")] = 0; // Xóa kí tự xuống dòng

        printf("Nhap diem SV %d: ", i + 1);
        scanf("%f", &ds[i].diem);

        // Xếp loại
        if (ds[i].diem >= 9.0) strcpy(ds[i].hocLuc, "Xuat sac");
        else if (ds[i].diem >= 8.0) strcpy(ds[i].hocLuc, "Gioi");
        else if (ds[i].diem >= 6.5) strcpy(ds[i].hocLuc, "Kha");
        else if (ds[i].diem >= 5.0) strcpy(ds[i].hocLuc, "Trung binh");
        else strcpy(ds[i].hocLuc, "Yeu");
    }

    // Sắp xếp giảm dần theo điểm (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diem < ds[j].diem) {
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    printf("\n----------------------------------------------------------\n");
    printf("| %-3s | %-25s | %-6s | %-12s |\n", "STT", "Ho va Ten", "Diem", "Hoc luc");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("| %-3d | %-25s | %-6.1f | %-12s |\n", i + 1, ds[i].hoTen, ds[i].diem, ds[i].hocLuc);
    }
    printf("----------------------------------------------------------\n");
}

// --- CHỨC NĂNG 9 ---
void chucNang9() {
    int s1, s2;
    printf("\n=== CHUC NANG 9: GAME FPOLY-LOTT (2/15) ===\n");
    printf("Nhap so thu nhat (01 - 15): "); scanf("%d", &s1);
    printf("Nhap so thu hai (01 - 15): "); scanf("%d", &s2);

    if (s1 < 1 || s1 > 15 || s2 < 1 || s2 > 15) {
        printf("Loi: So nhap vào phai trong khoang tu 01 den 15!\n");
        return;
    }

    srand(time(NULL));
    int r1 = rand() % 15 + 1;
    int r2 = rand() % 15 + 1;

    printf("\n-> So he thong quay ra la: [%02d] va [%02d]\n", r1, r2);

    int dem = 0;
    if (s1 == r1 || s1 == r2) dem++;
    if (s2 == r1 || s2 == r2) dem++;

    if (dem == 2) {
        printf(">>> CHUC MUNG BAN DA TRUNG GIAI NHAT! <<<\n");
    } else if (dem == 1) {
        printf(">>> CHUC MUNG BAN DA TRUNG GIAI NHI! <<<\n");
    } else {
        printf(">>> Chuc ban may man lan sau! <<<\n");
    }
}

// --- CHỨC NĂNG 10 ---
void chucNang10() {
    PhanSo ps1, ps2;
    printf("\n=== CHUC NANG 10: TINH TOAN PHAN SO ===\n");
    printf("Nhap phan so 1 (Tu Mau): "); scanf("%d %d", &ps1.tu, &ps1.mau);
    printf("Nhap phan so 2 (Tu Mau): "); scanf("%d %d", &ps2.tu, &ps2.mau);

    if (ps1.mau == 0 || ps2.mau == 0) {
        printf("Loi: Mau so phai khac 0!\n");
        return;
    }

    // TỔNG
    PhanSo tong = {ps1.tu * ps2.mau + ps2.tu * ps1.mau, ps1.mau * ps2.mau};
    tong = rutGonPhanSo(tong);

    // HIỆU
    PhanSo hieu = {ps1.tu * ps2.mau - ps2.tu * ps1.mau, ps1.mau * ps2.mau};
    hieu = rutGonPhanSo(hieu);

    // TÍCH
    PhanSo tich = {ps1.tu * ps2.tu, ps1.mau * ps2.mau};
    tich = rutGonPhanSo(tich);

    // THƯƠNG
    printf("\n--- KET QUA PHEP TINH PHAN SO ---\n");
    printf("Tong   : %d/%d + %d/%d = %d/%d\n", ps1.tu, ps1.mau, ps2.tu, ps2.mau, tong.tu, tong.mau);
    printf("Hieu   : %d/%d - %d/%d = %d/%d\n", ps1.tu, ps1.mau, ps2.tu, ps2.mau, hieu.tu, hieu.mau);
    printf("Tich   : %d/%d * %d/%d = %d/%d\n", ps1.tu, ps1.mau, ps2.tu, ps2.mau, tich.tu, tich.mau);

    if (ps2.tu == 0) {
        printf("Thuong : Khong the chia do tu so phan so 2 bang 0!\n");
    } else {
        PhanSo thuong = {ps1.tu * ps2.mau, ps1.mau * ps2.tu};
        thuong = rutGonPhanSo(thuong);
        printf("Thuong : %d/%d / %d/%d = %d/%d\n", ps1.tu, ps1.mau, ps2.tu, ps2.mau, thuong.tu, thuong.mau);
    }
}

// ==========================================
// HÀM MAIN VÀ MENU DÒNG LỆNH LẶP
// ==========================================

int main() {
    int chon;

    do {
        printf("\n+---------------------------------------------------+\n");
        printf("|         ASSIGNMENT MON NHAP MON LAP TRINH         |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Kiem tra so nguyen                             |\n");
        printf("| 2. Tim UCLN va BCNN cua 2 so                      |\n");
        printf("| 3. Chuong trinh tinh tien quan Karaoke            |\n");
        printf("| 4. Tinh tien dien                                 |\n");
        printf("| 5. Chuc nang doi tien                             |\n");
        printf("| 6. Tinh lai suat vay ngan hang tra gop            |\n");
        printf("| 7. Vay tien mua xe                                |\n");
        printf("| 8. Sap xep thong tin sinh vien                    |\n");
        printf("| 9. Game FPOLY-LOTT (2/15)                         |\n");
        printf("| 10. Tinh toan phan so                             |\n");
        printf("| 0. Thoat chuong trinh                             |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (0-10): ");
        scanf("%d", &chon);

        switch (chon) {
            case 1: chucNang1(); break;
            case 2: chucNang2(); break;
            case 3: chucNang3(); break;
            case 4: chucNang4(); break;
            case 5: chucNang5(); break;
            case 6: chucNang6(); break;
            case 7: chucNang7(); break;
            case 8: chucNang8(); break;
            case 9: chucNang9(); break;
            case 10: chucNang10(); break;
            case 0:
                printf("\nCam on ban da su dung chuong trinh. Tam biet!\n");
                break;
            default:
                printf("\nChuc nang khong hop le! Vui long chon tu 0 den 10.\n");
                break;
        }

    } while (chon != 0);

    return 0;
}