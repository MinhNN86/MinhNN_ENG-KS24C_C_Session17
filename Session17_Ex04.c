#include <stdio.h>
#include <stdlib.h>

void nhapMang(int *mang, int soPhanTu){
    for(int i = 0; i < soPhanTu; i++){
        printf("mang[%d]= ", i);
        scanf("%d", mang + i);
    }
}
void inPhanTuChan(int *mang, int soPhanTu){
    int checkPhanTuChan = 0;
    printf("phan tu chan trong mang la: ");
    for(int i = 0; i < soPhanTu; i++){
        if(*(mang + i) % 2 == 0){
            printf("%d ", *(mang + i));
            checkPhanTuChan = 1;
        }
    }
    if(!checkPhanTuChan){
        printf("mang khong co phan tu chan");
    }
}
void inSoNguyenTo(int *mang, int soPhanTu){
    int coSoNguyenTo = 0;
    printf("so nguyen to trong mang la: ");
    for(int i = 0; i < soPhanTu; i++){
        int checkSoNguyenTo = 1;
        if (mang[i] < 2){
            checkSoNguyenTo = 0;
        } else {
            for(int j = 2; j < mang[i]; j++){
                if(mang[i] % j == 0){
                    checkSoNguyenTo = 0;
                }
            }
        }
        if(checkSoNguyenTo == 1){
            printf("%d ", mang[i]);
            coSoNguyenTo = 1;
        }
    }
    if(!coSoNguyenTo){
        printf("mang khong co so nguyen to");
    }
}
void daoNguocMang(int *mang, int soPhanTu){
    int mangDaoNguoc[soPhanTu];
    int dem = 0;
    for(int i = soPhanTu - 1; i >= 0; i--){
        mangDaoNguoc[dem] = mang[i];
        dem++;
    }
    for(int i = 0; i < soPhanTu; i++){
        mang[i] = mangDaoNguoc[i];
    }
    printf("da dao nguoc mang");
}
void sapXepMang(int *mang, int soPhanTu) {
    int temp;
    int luaChonSapXep;
    int checkSapXep = 0;

    while (checkSapXep == 0) {
        printf("\n1. Tang dan\n");
        printf("2. Giam dan\n");
        printf("Lua chon sap xep: ");
        scanf("%d", &luaChonSapXep);

        switch (luaChonSapXep) {
            case 1: // Tang dan
                checkSapXep = 1;
                for (int i = 0; i < soPhanTu - 1; i++) {
                    for (int j = 0; j < soPhanTu - 1 - i; j++) {
                        if (mang[j] > mang[j + 1]) {
                            temp = mang[j];
                            mang[j] = mang[j + 1];
                            mang[j + 1] = temp;
                        }
                    }
                }
                break;

            case 2: // Giam dan
                checkSapXep = 1;
                for (int i = 0; i < soPhanTu - 1; i++) {
                    for (int j = 0; j < soPhanTu - 1 - i; j++) {
                        if (mang[j] < mang[j + 1]) {
                            temp = mang[j];
                            mang[j] = mang[j + 1];
                            mang[j + 1] = temp;
                        }
                    }
                }
                break;

            default: 
                printf("Nhap sai lua chon");
        }
    }
    printf("da sap xep mang");
}
void timPhanTu(int *mang, int soPhanTu){
    int phanTuTimKiem;
    int checkTimKiem = 0;
    printf("Nhap vao mot phan tu de tim kiem trong mang: ");
    scanf("%d", &phanTuTimKiem);
    for(int i = 0; i < soPhanTu; i++){
        if(mang[i] == phanTuTimKiem){
            printf("phan tu %d tim thay o vi tri %d trong mang\n", phanTuTimKiem, i);
            checkTimKiem = 1;
        }
    }
    if(!checkTimKiem){
        printf("khong tim thay phan tu trong mang");
    }
}
int main(){
    int luaChon;
    int kichThuoc = 10;
    int *mang= (int *)malloc(kichThuoc*sizeof(int));
    int check = 0;
    int soPhanTu;
    while(1){
        printf("\n1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra so phan tu la so chan\n");
        printf("3. In ra so phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("6. Tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("lua chon: ");
        scanf("%d", &luaChon);
        switch(luaChon){
            case 1: //Nhap vao so phan tu va tung phan tu
                check = 1;
                printf("nhap vao so phan tu trong mang: ");
                scanf("%d", &soPhanTu);
                if(soPhanTu > kichThuoc){
                    mang= (int *)realloc(mang, (soPhanTu - kichThuoc) * sizeof(int));
                }
                nhapMang(mang, soPhanTu);
                break;
            case 2: //In ra so phan tu la so chan
            	if(!check){
            		printf("chua nhap mang");
            		break;
				}
				inPhanTuChan(mang, soPhanTu);
				break;
            case 3: //In ra so phan tu la so nguyen to
                if(!check){
            		printf("chua nhap mang");
            		break;
				}
                inSoNguyenTo(mang, soPhanTu);
                break;
			case 4: //Dao nguoc mang
			    if (!check) {
			        printf("chua nhap mang\n");
			        break;
			    }
			    daoNguocMang(mang, soPhanTu);
			    break;
            case 5: //Sap xep mang
                if (!check) {
			        printf("chua nhap mang\n");
			        break;
			    }
                sapXepMang(mang, soPhanTu);
                break;
            case 6: //Nhap vao mot phan tu va tim kiem phan tu trong mang
                if (!check) {
			        printf("chua nhap mang\n");
			        break;
			    }
                timPhanTu(mang, soPhanTu);
                break;
            case 7: //Thoat
                free(mang);
                return 0;
            default:
                printf("nhap sai lua chon");
        }   
    }
}