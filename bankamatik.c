// Kullanıcıdan başlangıç değerlerini alıcaz yapmak istediği işlemi sorup işlem yaptırıcaz

#include <stdio.h>


int main(){
    // başlangıç bakiyesi
    float baslangic_bakiyesi = 7500, bakiye;
    int islem_no;
    float yatirilan_para, cekilen_para;
    float gunluk_para_cekme_limiti = 3000;


    // kullanıcıya menu sunup yapmak isteediği işlemi tuşlatıcaz
    printf("\nMenu :\n"
                   "1) Para Yatirma\n"
                   "2) Para Cekme\n"
                   "3) Bakiye Goruntuleme\n");
                
    printf("Lutfen yapmak istediginiz islemi seciniz : ");
    scanf("%d", &islem_no);

    // seçilen numaraya göre işlemler
    switch (islem_no) {
        case 1:
        printf("Yatirmak istediginiz para miktarini giriniz : ");
        scanf("%f", &yatirilan_para);
        printf("$%.2f miktari yatiriliyor.\n", yatirilan_para);
        bakiye = baslangic_bakiyesi + yatirilan_para;
        printf("Islem basariyla gerceklesti. Hesabinizdaki bakiye miktari : $%.2f\n", bakiye);
        break;

        case 2 :
        printf("Cekmek istediginiz para miktarini giriniz : ");
        fflush(stdin);
        scanf("%f", &cekilen_para);

        // mevcut bakiye bu parayi çekmeye yeterli mi kontrol et
        if(cekilen_para <= gunluk_para_cekme_limiti){
            if(baslangic_bakiyesi >= cekilen_para){
                printf("\nMevcut bakiye yeterli islem yapiliyor...");
                bakiye = baslangic_bakiyesi -  cekilen_para;
                printf("\nIslem basariyla gerceklesti. Kalan bakiyeniz : $%.2f\n", bakiye);
            }
            else {
                printf("\nMevcut bakiyeniz yeterli degildir.\n");
                printf("Islem yapilamiyor iyi gunler dileriz.");
            }
        }else {
            printf("Bu miktar gunkuk para cekme limitinin uzerinde.\n");
            printf("Islem yapilamiyor.\n");

        }
        break;
        
        case 3 :
        printf("Mevcut bakiyeniz : $%.2f", baslangic_bakiyesi);
        break;

        default:
        printf("Gecersiz islem.");
}
    return 0 ;
}
