#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void nhapChuoi(char *chuoi) {
    printf("Nhap vao chuoi: ");
    fgets(chuoi, 100, stdin);
    size_t len = strlen(chuoi);
    if (len > 0 && chuoi[len - 1] == '\n') {
        chuoi[len - 1] = '\0';
    }
}
void inChuoiDaoNguoc(char *chuoi){
    printf("chuoi vua nhap la: ");
    for(int i = strlen(chuoi); i >= 0; i--){
        printf("%c", chuoi[i]);
    }
}
void demTu(char *chuoi){
    int dem = 0;
    int n = strlen(chuoi) - 1;
    for(int i = 0; i < n; i++){
            if ((i == 0 || chuoi[i - 1] == ' ') && chuoi[i] != ' '){
                dem++;
            }
    }
    printf("so tu trong chuoi la: %d", dem);
}
void soSanhChuoi(char *chuoi){
    char chuoiSoSanh[100];
    printf("nhap chuoi de so sanh: ");
    fgets(chuoiSoSanh, 100, stdin);
    int doDaiChuoiGoc = strlen(chuoi);
    int doDaiChuoiSoSanh = strlen(chuoiSoSanh);
    if(doDaiChuoiGoc > doDaiChuoiSoSanh){
        printf("ngan hon chuoi ban dau");
    } else if (doDaiChuoiGoc < doDaiChuoiSoSanh){
        printf("dai hon chuoi ban dau");
    } else {
        printf("hai chuoi bang nhau");
    }
}
void inHoaChuCai(char *chuoi){
	printf("in hoa cac chu cai trong chuoi: ");
    for(int i = 0; i < strlen(chuoi); i++){
        if(isalpha(chuoi[i])){
            putchar(toupper(chuoi[i]));
        }
    }
}
void chenChuoi(char *chuoi) {
    char chuoiChen[100];
    printf("Nhap chuoi de chen vao chuoi goc: ");
    fgets(chuoiChen, 100, stdin);

    size_t len = strlen(chuoiChen);
    if (len > 0 && chuoiChen[len - 1] == '\n') {
        chuoiChen[len - 1] = '\0'; 
    }
    strcat(chuoi, chuoiChen); 
    printf("Chuoi khi duoc chen them la: ");
    fputs(chuoi, stdout);
}

int main(){
    char *chuoi = (char *)malloc(100*sizeof(char));
    int check = 0;
    int nguoiDungNhap;
    while(1){
        printf("\n1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Den so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("nhap lua chon: ");
        scanf("%d", &nguoiDungNhap);
        fflush(stdin);

        switch(nguoiDungNhap){
            case 1: //Nhap vao chuoi
            printf("\n");
                check = 1;
                nhapChuoi(chuoi);
                break;
            case 2: //In ra chuoi dao nguoc
                printf("\n");
                if(!check){
                    printf("chua nhap chuoi");
                    break;
                }
                inChuoiDaoNguoc(chuoi);
                break;
            case 3: //Den so luong tu trong chuoi
                printf("\n");
                if(!check){
                    printf("chua nhap chuoi");
                    break;
                }
                demTu(chuoi);
                break;
            case 4: //Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau
                printf("\n");
                if(!check){
                    printf("chua nhap chuoi");
                    break;
                }
                soSanhChuoi(chuoi);
                break;
            case 5: //In hoa tat ca chu cai trong chuoi
                printf("\n");
                if(!check){
                    printf("chua nhap chuoi");
                    break;
                }
                inHoaChuCai(chuoi);
                break;
            case 6: //Nhap vao chuoi khac va them chuoi do vao chuoi ban dau
                printf("\n");
                if(!check){
                    printf("chua nhap chuoi");
                    break;
                }
                chenChuoi(chuoi);
                break;
            case 7: //Thoat
                return 0;
            default:
                printf("nhap sai lua chon");
        }
    }
    
}