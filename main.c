#include <stdio.h>
#include <stdlib.h>

typedef struct Ogrenci
{
    char ad[15];
    char soyad[15];
    int dersNotu;
}OGR;


void DosyayaYaz(FILE *oDosya, int oSayisi);
OGR *DosyadanOku(FILE *oDosya, int oSayisi);
void NotDegerlendir(FILE *gDosya, FILE *kDosya, OGR *ogr, int oSayisi);


int main()
{

    int ogrSayisi;
    FILE *ogrDosya, *gecDosya, *kalDosya;
    OGR *ogrenciler;

    printf("Ogrenci sayisini giriniz: ");
    scanf("%d", &ogrSayisi);

    ogrDosya = fopen("ogrenciler.txt","w");

    if(ogrDosya == NULL){

        printf("Ogrenci ekleme dosyasi acilamadi.");
        return -1;

    }

DosyayaYaz(ogrDosya, ogrSayisi);
system("CLS");
    printf("\n[1]- Ogrenci bilgileri dosyaya basarili bir sekilde yazildi..\n");

//////////////////////////////////////////////////////////////////////////////////////////////

    ogrDosya = fopen("ogrenciler.txt","r");

    if(ogrDosya == NULL){

        printf("Ogrenci okuma dosyasi acilamadi.");
        return -1;

    }

ogrenciler = DosyadanOku(ogrDosya, ogrSayisi);
    getch();
    system("CLS");
    printf("\n[2]- Ogrenci bilgileri dosyadan diziye aktarildi..\n");

    ///////////////////////////////////////////////////////////////////////////////////////////

    gecDosya = fopen("gecenler.txt","w");
    kalDosya = fopen("kalanlar.txt","w");

    if(gecDosya == NULL || kalDosya == NULL){

        printf("Gecen veya kalan ogrenci dosyasi acilamadi.");
        return -1;

    }

NotDegerlendir(gecDosya, kalDosya, ogrenciler, ogrSayisi);
    getch();
    system("CLS");
    printf("\n[3]- Kalan ve gecen ogrenciler dosyaya yazdirildi..\n");


    return 0;

}



void DosyayaYaz(FILE *oDosya, int oSayisi)
{

     char ad[15], soyad[15];
     int dersNotu, i;

     for(i=0;i<oSayisi;i++){

        printf("%d.ogrencinin ad, soyad ve notunu giriniz: ", i+1);
        scanf("%s %s %d", ad, soyad, &dersNotu);

        fprintf(oDosya, "%s %s %d\n", ad, soyad, dersNotu);

     }
     fclose(oDosya);

}



OGR *DosyadanOku(FILE *oDosya, int oSayisi)
{

    int i=0;
    OGR *ogr = (OGR*)malloc(oSayisi*sizeof(OGR));

    while(!feof(oDosya)){

        fscanf(oDosya, "%s %s %d", (ogr+i)->ad, (ogr+i)->soyad, &(ogr+i)->dersNotu);
        i++;

    }
    fclose(oDosya);

    return ogr;

}



void NotDegerlendir(FILE *gDosya, FILE *kDosya, OGR *ogr, int oSayisi)
{

    int i;

    for(i=0;i<oSayisi;i++){

        if((ogr+i)->dersNotu >= 60){

            fprintf(gDosya, "%s %s %d\n", (ogr+i)->ad, (ogr+i)->soyad, (ogr+i)->dersNotu);

        }
        else
            fprintf(kDosya, "%s %s %d\n", (ogr+i)->ad, (ogr+i)->soyad, (ogr+i)->dersNotu);

    }
    fclose(gDosya);
    fclose(kDosya);

}
