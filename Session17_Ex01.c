#include <stdio.h>
#include <stdlib.h> 

int main() {
    int nguoiDungNhap;
    int check = 0; 
    int *mang = NULL;
    int soPhanTu = 0;

    while (1) {
        printf("\n1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("nhap lua chon: ");
        scanf("%d", &nguoiDungNhap);

        switch (nguoiDungNhap) {
            case 1: //Nhap vao so phan tu va tung phan tu
                if (mang != NULL) {
                    free(mang); 
                }
                check = 1;
                printf("nhap so phan tu trong mang: ");
                scanf("%d", &soPhanTu);
                if (soPhanTu <= 0) {
                    printf("so phan tu khong hop le\n");
                    check = 0;
                    break;
                }
                mang = (int *)malloc(soPhanTu * sizeof(int)); 
                if (mang == NULL) {
                    printf("Khong du bo nho\n");
                    return 1;
                }
                for (int i = 0; i < soPhanTu; i++) {
                    printf("mang[%d]= ", i);
                    scanf("%d", mang + i);
                }
                break;

            case 2: // Hien thi cac phan tu trong mang
                if (check == 0) {
                    printf("chua nhap mang\n");
                    break;
                }
                printf("cac phan tu trong mang la:\n");
                for (int i = 0; i < soPhanTu; i++) {
                    printf("mang[%d]= %d ", i, *(mang + i));
                }
                break;

            case 3: // Tinh do dai mang
                if (check == 0) {
                    printf("chua nhap mang\n");
                    break;
                }
                printf("do dai mang la: %d\n", soPhanTu);
                break;

            case 4: // Tinh tong cac phan tu trong mang
                if (check == 0) {
                    printf("chua nhap mang\n");
                    break;
                }
                int tong = 0;
                for (int i = 0; i < soPhanTu; i++) {
                    tong += mang[i];
                }
                printf("tong cac phan tu trong mang la: %d", tong);
                break;

            case 5: // Hien thi phan tu lon nhat
                if (check == 0) {
                    printf("chua nhap mang\n");
                    break;
                }
                int max = mang[0];
                for (int i = 1; i < soPhanTu; i++) {
                    if (mang[i] > max) {
                        max = mang[i];
                    }
                }
                printf("phan tu lon nhat trong mang la: %d", max);
                break;

            case 6: // Thoat
                if (mang != NULL) {
                    free(mang); 
                }
                return 0;

            default:
                printf("lua chon khong hop le");
        }
    }
}
