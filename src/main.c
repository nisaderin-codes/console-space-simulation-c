#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GEZEGEN_SAYISI 8
#define PI 3.14159265358979323846

//Fonksiyon Prototipleri

void bilimInsaniAdiAl(char bilimInsaniAdi[]);
void menuYazdir(void);

double mutlakDeger(double deger);

void deneySerbestDusme(char bilimInsaniAdi[], double *yercekimi, char *gezegenAdlari[], int gezegenSayisi);
void deneyYukariAtis(char bilimInsaniAdi[], double *yercekimi, char *gezegenAdlari[], int gezegenSayisi);
void deneyAgirlik(char bilimInsaniAdi[], double *yercekimi, char *gezegenAdlari[], int gezegenSayisi);
void deneyPotansiyelEnerji(char bilimInsaniAdi[], double *yercekimi, char *gezegenAdlari[], int gezegenSayisi);
void deneyHidrostatikBasinc(char bilimInsaniAdi[], double *yercekimi, char *gezegenAdlari[], int gezegenSayisi);
void deneyArsimet(char bilimInsaniAdi[], double *yercekimi, char *gezegenAdlari[], int gezegenSayisi);
void deneySarkacPeriyodu(char bilimInsaniAdi[], double *yercekimi, char *gezegenAdlari[], int gezegenSayisi);
void deneyIpGerilmesi(char bilimInsaniAdi[], double *yercekimi, char *gezegenAdlari[], int gezegenSayisi);
void deneyAsansor(char bilimInsaniAdi[], double *yercekimi, char *gezegenAdlari[], int gezegenSayisi);

int main(void)
{
    printf("-------------------UZAY SIMULASYONUNA HOSGELDINIZ-------------------\n\n\n");

    char bilimInsaniAdi[51]; //isim icin 50 karakter verildi, sonlandirici karakter de dusunuldugu icin 51 karakterlik olusturuldu.

    //-Gezegen adlari ve yercekimi ivmeleri
    char *gezegenAdlari[GEZEGEN_SAYISI] = {"Merkur", "Venus", "Dunya", "Mars", "Jupiter", "Saturn", "Uranus", "Neptun"};

    double yercekimi[GEZEGEN_SAYISI] = {3.70, 8.87, 9.81, 3.71, 23.12, 8.96, 8.69, 11.00};

    int secim;

    bilimInsaniAdiAl(bilimInsaniAdi); //Bilim insaninin ismi bir kere alindi.


    //Dongu ile kisi -1 girene kadar menu gosterildi.
    while (1)
    {
        menuYazdir();
        printf("Seciminiz: ");
        scanf("%d", &secim);

        if (secim == -1){
            printf("Program sonlandirildi.\n");
            break;
        }

        switch (secim){
            case 1:
                deneySerbestDusme(bilimInsaniAdi, yercekimi, gezegenAdlari, GEZEGEN_SAYISI);break;

            case 2:
                deneyYukariAtis(bilimInsaniAdi, yercekimi, gezegenAdlari, GEZEGEN_SAYISI);break;

            case 3:
                deneyAgirlik(bilimInsaniAdi, yercekimi, gezegenAdlari, GEZEGEN_SAYISI);break;

            case 4:
                deneyPotansiyelEnerji(bilimInsaniAdi, yercekimi, gezegenAdlari, GEZEGEN_SAYISI);break;

            case 5:
                deneyHidrostatikBasinc(bilimInsaniAdi, yercekimi, gezegenAdlari, GEZEGEN_SAYISI);break;

            case 6:
                deneyArsimet(bilimInsaniAdi, yercekimi, gezegenAdlari, GEZEGEN_SAYISI);break;

            case 7:
                deneySarkacPeriyodu(bilimInsaniAdi, yercekimi, gezegenAdlari, GEZEGEN_SAYISI);break;

            case 8:
                deneyIpGerilmesi(bilimInsaniAdi, yercekimi, gezegenAdlari, GEZEGEN_SAYISI);break;

            case 9:
                deneyAsansor(bilimInsaniAdi, yercekimi, gezegenAdlari, GEZEGEN_SAYISI);break;

            default:
                printf("Hatali secim! 1-9 arasi bir secim yapiniz veya cikis icin -1 giriniz.\n");break;
        }
    }
    return 0;
}

//BILIM INSANININ ADINI ALMA FONKSIYONU
void bilimInsaniAdiAl(char bilimInsaniAdi[])
{
    printf("Merhaba bilim insani, isminiz nedir?: ");
    fgets(bilimInsaniAdi, 51, stdin); //Bilim insaninin adi tek kelime degilse diye scanf yerine fgets kullandim.
}

//MENU GOSTERME FONKSIYONU
void menuYazdir(void)
{
    printf("\n--- DENEY MENUSU ---\n");
    printf("1) Serbest Dusme Deneyi\n");
    printf("2) Yukari Atis Deneyi\n");
    printf("3) Agirlik Deneyi\n");
    printf("4) Kutlecekimsel Potansiyel Enerji Deneyi\n");
    printf("5) Hidrostatik Basinc Deneyi\n");
    printf("6) Arsimet Kaldirma Kuvveti Deneyi\n");
    printf("7) Basit Sarkac Periyodu Deneyi\n");
    printf("8) Sabit Ip Gerilmesi Deneyi\n");
    printf("9) Asansor Deneyi\n");
    printf("Cikis: -1\n");
}

// MUTLAK DEGER FONKSIYONU
double mutlakDeger(double deger)
{
    return (deger < 0) ? -deger : deger;    //Eger deger negatifse pozitife cevrilir.
}

// 1)SERBEST DUSME DENEYI: h = 1/2 g t^2
void deneySerbestDusme(char bilimInsaniAdi[], double *yercekimi, char *gezegenAdlari[], int gezegenSayisi)
{
    double sure, yukseklik;
    int i;

    printf("\nBilim Insani: %s\n", bilimInsaniAdi);
    printf("Serbest Dusme Deneyi\n");

    printf("Sure t (s): ");
    scanf("%lf", &sure);
    sure = mutlakDeger(sure);

    //Tum gezegenler icin hesaplama:
    for (i = 0; i < gezegenSayisi; i++)
    {
        double g = *(yercekimi + i);
        char *gezegen = *(gezegenAdlari + i);

        yukseklik = 0.5 * g * sure * sure;
        printf("%s: dusulen yol h = %.3f m\n", gezegen, yukseklik);
    }
}

// 2)YUKARI YONDE ATIS DENEYI: hmax = v0^2 / (2g)
void deneyYukariAtis(char bilimInsaniAdi[], double *yercekimi, char *gezegenAdlari[], int gezegenSayisi)
{
    double ilkHiz, hmax;
    int i;

    printf("\nBilim Insani: %s\n", bilimInsaniAdi);
    printf("Yukari Atis Deneyi\n");

    printf("Ilk hiz v0 (m/s): ");
    scanf("%lf", &ilkHiz);

    //Tum gezegenler icin hesaplama:
    for (i = 0; i < gezegenSayisi; i++)
    {
        double g = *(yercekimi + i);
        char *gezegen = *(gezegenAdlari + i);

        hmax = (ilkHiz * ilkHiz) / (2.0 * g);
        printf("%s: maksimum yukseklik h_max = %.3f m\n", gezegen, hmax);
    }
}


// 3)AGIRLIK DENEYI: G = m*g
void deneyAgirlik(char bilimInsaniAdi[], double *yercekimi, char *gezegenAdlari[], int gezegenSayisi)
{
    double kutle, agirlik;
    int i;

    printf("\nBilim Insani: %s\n", bilimInsaniAdi);
    printf("Agirlik Deneyi\n");

    printf("Kutle m (kg): ");
    scanf("%lf", &kutle);
    kutle = mutlakDeger(kutle);

    //Tum gezegenler icin hesaplama:
    for (i = 0; i < gezegenSayisi; i++)
    {
        double g = *(yercekimi + i);
        char *gezegen = *(gezegenAdlari + i);

        agirlik = kutle * g;
        printf("%s: agirlik G = %.3f N\n", gezegen, agirlik);
    }
}

// 4)KUTLECEKIMSEL POTANSIYEL ENERJI DENEYI: Ep = m*g*h
void deneyPotansiyelEnerji(char bilimInsaniAdi[], double *yercekimi, char *gezegenAdlari[], int gezegenSayisi)
{
    double kutle, yukseklik, enerji;
    int i;

    printf("\nBilim Insani: %s\n", bilimInsaniAdi);
    printf("Potansiyel Enerji Deneyi\n");

    printf("Kutle m (kg): ");
    scanf("%lf", &kutle);
    kutle = mutlakDeger(kutle);

    printf("Yukseklik h (m): ");
    scanf("%lf", &yukseklik);
    yukseklik = mutlakDeger(yukseklik);

    //Tum gezegenler icin hesaplama:
    for (i = 0; i < gezegenSayisi; i++)
    {
        double g = *(yercekimi + i);
        char *gezegen = *(gezegenAdlari + i);

        enerji = kutle * g * yukseklik;
        printf("%s: potansiyel enerji Ep = %.3f J\n", gezegen, enerji);
    }
}

// 5)HIDROSTATIK BASINC DENEYI: P = rho*g*h
void deneyHidrostatikBasinc(char bilimInsaniAdi[], double *yercekimi, char *gezegenAdlari[], int gezegenSayisi)
{
    double yogunluk, derinlik, basinc;
    int i;

    printf("\nBilim Insani: %s\n", bilimInsaniAdi);
    printf("Hidrostatik Basinc Deneyi\n");

    printf("Sivi yogunlugu rho (kg/m^3): ");
    scanf("%lf", &yogunluk);
    yogunluk = mutlakDeger(yogunluk);

    printf("Derinlik h (m): ");
    scanf("%lf", &derinlik);
    derinlik = mutlakDeger(derinlik);

    //Tum gezegenler icin hesaplama:
    for (i = 0; i < gezegenSayisi; i++)
    {
        double g = *(yercekimi + i);
        char *gezegen = *(gezegenAdlari + i);

        basinc = yogunluk * g * derinlik;
        printf("%s: hidrostatik basinc P = %.3f Pa\n", gezegen, basinc);
    }
}

// 6)ARSIMET KALDIRMA KUVVETI DENEYI: Fk = rho*g*V
void deneyArsimet(char bilimInsaniAdi[], double *yercekimi, char *gezegenAdlari[], int gezegenSayisi)
{
    double yogunluk, hacim, kuvvet;
    int i;

    printf("\nBilim Insani: %s\n", bilimInsaniAdi);
    printf("Arsimet Kuvveti Deneyi\n");

    printf("Sivi yogunlugu rho (kg/m^3): ");
    scanf("%lf", &yogunluk);
    yogunluk = mutlakDeger(yogunluk);

    printf("Batan hacim V (m^3): ");
    scanf("%lf", &hacim);
    hacim = mutlakDeger(hacim);

    //Tum gezegenler icin hesaplama:
    for (i = 0; i < gezegenSayisi; i++)
    {
        double g = *(yercekimi + i);
        char *gezegen = *(gezegenAdlari + i);

        kuvvet = yogunluk * g * hacim;
        printf("%s: kaldirma kuvveti Fk = %.3f N\n", gezegen, kuvvet);
    }
}

// 7)BASIT SARKAC PERIYODU DENEYI: T = 2*pi*sqrt(L/g)
void deneySarkacPeriyodu(char bilimInsaniAdi[], double *yercekimi, char *gezegenAdlari[], int gezegenSayisi)
{
    double uzunluk, periyot;
    int i;

    printf("\nBilim Insani: %s\n", bilimInsaniAdi);
    printf("Basit Sarkac Periyodu Deneyi\n");

    printf("Ip uzunlugu L (m): ");
    scanf("%lf", &uzunluk);
    uzunluk = mutlakDeger(uzunluk);

    //Tum gezegenler icin hesaplama:
    for (i = 0; i < gezegenSayisi; i++)
    {
        double g = *(yercekimi + i);
        char *gezegen = *(gezegenAdlari + i);

        periyot = 2.0 * PI * sqrt(uzunluk / g);
        printf("%s: periyot T = %.3f s\n", gezegen, periyot);
    }
}

// 8)SABIT IP GERILMESI DENEYI: T = m*g
void deneyIpGerilmesi(char bilimInsaniAdi[], double *yercekimi, char *gezegenAdlari[], int gezegenSayisi)
{
    double kutle, gerilme;
    int i;

    printf("\nBilim Insani: %s\n", bilimInsaniAdi);
    printf("Sabit Ip Gerilmesi Deneyi\n");

    printf("Kutle m (kg): ");
    scanf("%lf", &kutle);
    kutle = mutlakDeger(kutle);

    //Tum gezegenler icin hesaplama:
    for (i = 0; i < gezegenSayisi; i++)
    {
        double g = *(yercekimi + i);
        char *gezegen = *(gezegenAdlari + i);

        gerilme = kutle * g;
        printf("%s: ip gerilmesi T = %.3f N\n", gezegen, gerilme);
    }
}

// 9)ASANSOR DENEYI: N = m(g + a) veya N = m(g - a)
void deneyAsansor(char bilimInsaniAdi[], double *yercekimi, char *gezegenAdlari[], int gezegenSayisi)
{
    double kutle, ivme, normalKuvvet;
    int durum;
    int i;

    printf("\nBilim Insani: %s\n", bilimInsaniAdi);
    printf("Asansor Deneyi\n");

    printf("Kutle m (kg): ");
    scanf("%lf", &kutle);
    kutle = mutlakDeger(kutle);

    printf("Asansor ivmesi a (m/s^2): ");
    scanf("%lf", &ivme);
    //ivmenin buyuklugu kullanicidan alindi.
    ivme = mutlakDeger(ivme);

    printf("Durum seciniz:\n");
    printf("1) N = m(g + a)\n");
    printf("2) N = m(g - a)\n");
    printf("Secim: ");
    scanf("%d", &durum);

    //Tum gezegenler icin hesaplama:
    for (i = 0; i < gezegenSayisi; i++)
    {
        double g = *(yercekimi + i);
        char *gezegen = *(gezegenAdlari + i);

        if (durum == 1) normalKuvvet = kutle * (g + ivme);
        else normalKuvvet = kutle * (g - ivme);

        printf("%s: hissedilen agirlik N = %.3f N\n", gezegen, normalKuvvet);
    }
}
