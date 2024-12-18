#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>

void nhapChuoi(char *chuoi){
    printf("nhap vao mot chuoi: ");
    fgets(chuoi, 100, stdin);
}

void inChuoi(char *chuoi){
    printf("chuoi vua nhap la: ");
    fputs(chuoi, stdout);
}

void timChuCai(char *chuoi){
    int dem = 0;
    printf("chu cai trong chuoi la: ");
    for(int i = 0; i < strlen(chuoi) - 1; i++){
        if(isalpha(chuoi[i])){
            printf("%c", chuoi[i]);
            dem++;
        }
    }
    if(dem > 0){
        printf("\nso luong chu cai la: %d", dem);
    } else {
        printf("khong co chu cai trong chuoi");
    }
}

void timChuSo(char *chuoi){
    int dem = 0;
    printf("chu so trong chuoi la: ");
    for(int i = 0; i < strlen(chuoi) - 1; i++){
        if(isdigit(chuoi[i])){
            printf("%c", chuoi[i]);
            dem++;
        }
    }
    if(dem > 0){
        printf("\nso luong chu so la: %d", dem);
    } else {
        printf("khong co chu so trong chuoi");
    }
}

void timKyTu(char *chuoi){
    int dem = 0;
    printf("ky tu dac biet trong chuoi la: ");
    for(int i = 0; i < strlen(chuoi) - 1; i++){
        if(!isalnum(chuoi[i])){
            printf("%c", chuoi[i]);
            dem++;
        }
    }
    if(dem > 0){
        printf("\nso luong ky tu dac biet la: %d", dem);
    } else {
        printf("khong co ky tu dac biet trong chuoi");
    }
}
int main(){
    int nguoiDungNhap;
    char *chuoi = (char*)malloc(100*sizeof(char));
    int check = 0;
    while(1){
        printf("\n1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &nguoiDungNhap);
        fflush(stdin);

        switch(nguoiDungNhap){
            case 1: //Nhap vao chuoi
                printf("\n");
                check = 1;
                nhapChuoi(chuoi);     
                break;

            case 2: //In ra chuoi
                printf("\n");
                if(check == 0){
                    printf("chua nhap chuoi");
                    break;
                }
                inChuoi(chuoi);
                break;

            case 3: //Dem so luong chu cai trong chuoi va in ra
                printf("\n");
                if(check == 0){
                    printf("chua nhap chuoi");
                    break;
                }
                timChuCai(chuoi);
                // chuCai = 0;
                // printf("chu cai trong chuoi la: ");
                // for(int i = 0; i < strlen(chuoi) - 1; i++){
                //     if((*(chuoi + i) >= 'a' && *(chuoi + i) <= 'z') || (*(chuoi + i) >= 'A' && *(chuoi + i) <= 'Z')){
                //         chuCai++;
                //         printf("%c", *(chuoi + i));
                //     }
                // }   
                // if(chuCai > 0){
                //     printf("\nso luong chu cai trong chuoi la %d", chuCai);
                // } else {
                //     printf("khong co chu cai trong mang");
                // }
                break;
            case 4: //Dem so luong chu so trong chuoi va in ra
                printf("\n");
                if(check == 0){
                    printf("chua nhap chuoi");
                    break;
                }
                timChuSo(chuoi);
                // chuSo = 0;
                // printf("chu so trong chuoi la: ");
                // for(int i = 0; i < strlen(chuoi) - 1; i++){
                //     if(*(chuoi + i) >= '0' && *(chuoi + i) <= '9'){
                //         printf("%c", *(chuoi + i));
                //         chuSo++;
                //     }
                // }
                // if(chuSo > 0){
                //     printf("\nso luong chu so trong chuoi la: %d", chuSo);
                // } else{
                //     printf("khong co chu so trong mang");
                // }
                break;
            
            case 5: //Dem so luong ky tu dac biet trong chuoi va in ra
                printf("\n");
                if(check == 0){
                    printf("chua nhap chuoi");
                    break;
                }
                timKyTu(chuoi);
                break;
            
            case 6: //Thoat
                return 0;
            
            default:
                printf("\n");
                printf("nhap sai lua chon");
        }
    }
}

