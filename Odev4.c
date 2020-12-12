#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Her bir kategoriyi ayrı struct tipi olarak tanımladım.

Daha sonrasında her bir struct için ayrı bağlı liste oluşturup verileri bu bağlı listelerde tuttum.

Kodda her olasılığı test etmeye çalıştım. O yüzden satırca uzun oldu.
*/

typedef struct et{
  char  urunAdi[20];
  int birimMaliyeti;
  char urunKategorisi;
  char etTuru;
  char paketlemeTarihi[10]; //01.01.2021 gibi max 10 karakter.
  char sonKullanmaTarihi[10];
  struct et* next; 
}et;

typedef struct tarim{
  char  urunAdi[20];
  int birimMaliyeti;
  char urunKategorisi;
  char tarimTuru;
  char alinmaTarihi[10];
  struct tarim* next; 
}tarim;

typedef struct sut{
  char  urunAdi[20];
  int birimMaliyeti;
  char urunKategorisi;
  char sonKullanmaTarihi[10];
  struct sut* next; 
}sut;

typedef struct konserve{
  char  urunAdi[20];
  int birimMaliyeti;
  char urunKategorisi;
  int reyonNumarasi;
  char reyonTarafi;
  char sonKullanmaTarihiAyYil[12];//Ağustos 2020 gibi düşündüm fakat 06-2020 olarak da girilebilir.
  struct konserve* next; 
}konserve;

typedef struct gidaDisi{
  char  urunAdi[20];
  int birimMaliyeti;
  char urunKategorisi;
  char urunTuru;
  int reyonNumarasi;
  char reyonTarafi;
  struct gidaDisi* next; 
}gidaDisi;

//Ödevde istenen fonksiyonların ön tanımı.
void urun_ekle();
void urun_goster();

//urun_ekle() fonksiyonu içerisinde kod kirliliği yaratmamak için urun_ekle() fonksiyonu içerisinde aşağıdaki fonksiyonları duruma göre çağırıyorum.
void ekle_etBagliListe(char urunAdi[20], int birimMaliyeti,char urunKategorisi, char etTuru, char paketlemeTarihi[10], char sonKullanmaTarihi[20]);

void ekle_tarimBagliListe(char urunAdi[20], int birimMaliyeti,char urunKategorisi,char tarimTuru, char alinmaTarihi[10]);

void ekle_sutBagliListe(char urunAdi[20], int birimMaliyeti,char urunKategorisi, char sonKullanmaTarihi[10]);

void ekle_konserveBagliListe(char urunAdi[20], int birimMaliyeti,char urunKategorisi,int reyonNumarasi, char reyonTarafi, char sonKullanmaTarihiAyYil[12]);

void ekle_gidaDisiBagliListe(char urunAdi[20], int birimMaliyeti,char urunKategorisi, char urunTuru, int reyonNumarasi, char reyonTarafi);


//Fonksiyonların içinden erişebilmek için global değişken olarak tüm bağlı listeleri ilk olarak NULL tanımladım.
et * etBagliListe = NULL;
tarim * tarimBagliListe = NULL;
sut * sutBagliListe = NULL;
konserve * konserveBagliListe = NULL;
gidaDisi * gidaDisiBagliListe = NULL;

int main(void) {
  
  urun_ekle();
  urun_ekle();
  urun_goster();

  return 0;
}

void urun_ekle(){

  char urunAdi[20];
  int birimMaliyeti;
  char urunKategorisi;
  char etTuru;
  char paketlemeTarihi[10];
  char sonKullanmaTarihi[10];
  char sonKullanmaTarihiAyYil[12];
  char tarimTuru;
  char alinmaTarihi[10];
  int reyonNumarasi;
  char reyonTarafi;
  char urunTuru;



  char kategori;
  printf("Urun Kategorisini Seciniz (E, T, K, S, G) --> ");
  scanf(" %c", &kategori);

  switch(kategori){

    case 'E':

      printf("\nUrun adini giriniz -> ");
      scanf("%s",urunAdi);
      printf("\nUrunun TL cinsinden birim maliyetini giriniz -> ");
      scanf("%d",&birimMaliyeti);
      printf("\nEt turunu giriniz (R,B,P) -> ");
      scanf(" %c", &etTuru);
      printf("\nPaketleme tarihini giriniz (#-#-#) -> ");
      scanf("%s",paketlemeTarihi);
      printf("\nSon kullanma tarihini giriniz (#-#-#) -> ");
      scanf("%s",sonKullanmaTarihi);
      printf("\n");

      ekle_etBagliListe(urunAdi, birimMaliyeti,kategori, etTuru, paketlemeTarihi, sonKullanmaTarihi);

      break;
    case 'T':
      printf("\nUrun adini giriniz -> ");
      scanf("%s",urunAdi);
      printf("\nUrunun TL cinsinden birim maliyetini giriniz -> ");
      scanf("%d",&birimMaliyeti);
      printf("\nTarim turunu giriniz (M,S) -> ");
      scanf(" %c", &tarimTuru);
      printf("\nAlınma tarihini giriniz (#-#-#) -> ");
      scanf("%s",alinmaTarihi);
      printf("\n");

      ekle_tarimBagliListe(urunAdi, birimMaliyeti,kategori, tarimTuru, alinmaTarihi);

      break;
    case 'K':
      printf("\nUrun adini giriniz -> ");
      scanf("%s",urunAdi);
      printf("\nUrunun TL cinsinden birim maliyetini giriniz -> ");
      scanf("%d",&birimMaliyeti);
      printf("\nUrunun reyon numarasini giriniz  -> ");
      scanf("%d",&reyonNumarasi);
      printf("\nUrunun reyon tarafini giriniz -> ");
      scanf(" %c",&reyonTarafi);

      printf("\nSon kullanma tarihini ay ve yil olarak giriniz (#-#) -> ");
      scanf("%s",sonKullanmaTarihiAyYil);
      printf("\n");

      ekle_konserveBagliListe(urunAdi, birimMaliyeti,kategori,reyonNumarasi, reyonTarafi, sonKullanmaTarihiAyYil);
      break;
    case 'S':
      printf("\nUrun adini giriniz -> ");
      scanf("%s",urunAdi);
      printf("\nUrunun TL cinsinden birim maliyetini giriniz -> ");
      scanf("%d",&birimMaliyeti);
      printf("\nSon kullanma tarihini giriniz (#-#-#) -> ");
      scanf("%s",sonKullanmaTarihi);
      printf("\n");

      ekle_sutBagliListe(urunAdi, birimMaliyeti,kategori, sonKullanmaTarihi);

      break;
    case 'G':
      printf("\nUrun adini giriniz -> ");
      scanf("%s",urunAdi);
      printf("\nUrunun TL cinsinden birim maliyetini giriniz -> ");
      scanf("%d",&birimMaliyeti);
      printf("\nUrunun turunu giriniz (C,P,D)  -> ");
      scanf(" %c",&urunTuru);
      printf("\nUrunun reyon numarasini giriniz  -> ");
      scanf("%d",&reyonNumarasi);
      printf("\nUrunun reyon tarafini giriniz -> ");
      scanf(" %c",&reyonTarafi); 
      printf("\n");

      ekle_gidaDisiBagliListe(urunAdi, birimMaliyeti,urunTuru,kategori,reyonNumarasi, reyonTarafi);
      break;      
  }
}

void urun_goster(){

    et * iterEt = etBagliListe;
    tarim * iterTarim = tarimBagliListe;
    sut * iterSut = sutBagliListe;
    konserve * iterKonserve = konserveBagliListe;
    gidaDisi * iterGidaDisi = gidaDisiBagliListe;

    //Tüm bağlı listeler boşsa kayıtlı urun yoktur.
    if(iterEt == NULL && iterTarim == NULL && iterSut == NULL && iterKonserve == NULL && iterGidaDisi == NULL)
    printf("Kayıtlı ürün bulunamadı!");

    printf("------KAYITLI URUN LISTESI------\n");

//Her bir bağlı liste için özel olarak yazdırırlar.
  while(iterEt != NULL){


    printf("Urun Kategorisi: %c\nUrun Adi: %s\nBirim Maliyeti: %d TL\nEt Turu: %c\nPaketleme Tarihi: %s\nSon Kullanma Tarihi: %s\n",iterEt->urunKategorisi, iterEt->urunAdi,iterEt->birimMaliyeti,iterEt->etTuru,iterEt->paketlemeTarihi,iterEt->sonKullanmaTarihi);
    printf("-------------------------------\n");
    iterEt = iterEt->next;
  }
  while(iterTarim != NULL){


    printf("Urun Kategorisi: %c\nUrun Adi: %s\nBirim Maliyeti: %d TL\nTarim Turu: %c\nAlınma Tarihi: %s\n",iterTarim->urunKategorisi, iterTarim->urunAdi,iterTarim->birimMaliyeti,iterTarim->tarimTuru,iterTarim->alinmaTarihi);
    printf("-------------------------------\n");
    iterTarim = iterTarim->next;
  }
  while(iterSut != NULL){

    printf("Urun Kategorisi: %c\nUrun Adi: %s\nBirim Maliyeti: %d TL\nSon Kullanma Tarihi: %s\n",iterSut->urunKategorisi, iterSut->urunAdi,iterSut->birimMaliyeti,iterSut->sonKullanmaTarihi);
    printf("-------------------------------\n");
    iterSut = iterSut->next;
  }
  while(iterKonserve != NULL){

    printf("Urun Kategorisi: %c\nUrun Adi: %s\nBirim Maliyeti: %d TL\nReyon Numarasi: %d\nReyon Tarafı: %c\nSon Kullanma Tarihi Ay Yıl: %s\n",iterKonserve->urunKategorisi, iterKonserve->urunAdi,iterKonserve->birimMaliyeti,iterKonserve->reyonNumarasi,iterKonserve->reyonTarafi, iterKonserve->sonKullanmaTarihiAyYil);
    printf("-------------------------------\n");
    iterKonserve = iterKonserve->next;
  }
  while(iterGidaDisi != NULL){

    printf("Urun Kategorisi: %c\nUrun Adi: %s\nBirim Maliyeti: %d TL\nUrun Turu: %c\nReyon Numarasi: %d\nReyon Tarafı: %c\n",iterGidaDisi->urunKategorisi, iterGidaDisi->urunAdi,iterGidaDisi->birimMaliyeti,iterGidaDisi->urunTuru, iterGidaDisi->reyonNumarasi,iterGidaDisi->reyonTarafi);
    printf("-------------------------------\n");
    iterGidaDisi = iterGidaDisi->next;
  }
}

void ekle_etBagliListe(char urunAdi[20], int birimMaliyeti,char urunKategorisi, char etTuru, char paketlemeTarihi[10], char sonKullanmaTarihi[20]){

  et * iter = etBagliListe;

  if(iter == NULL){;
    iter =(et*)malloc(sizeof(et));
    iter->next= NULL;
    strcpy(iter -> urunAdi, urunAdi);
    iter->birimMaliyeti = birimMaliyeti;
    iter->urunKategorisi = urunKategorisi;
    strcpy(&iter->etTuru, &etTuru);
    strcpy(iter -> paketlemeTarihi, paketlemeTarihi);
    strcpy(iter -> sonKullanmaTarihi, sonKullanmaTarihi);
    etBagliListe = iter;
    return;
  }

  while(iter->next !=NULL)  {
    iter = iter->next;

  }
   et * temp = (et *)malloc(sizeof(et));
   temp->next = iter->next;
   iter ->next = temp;
   strcpy(temp -> urunAdi, urunAdi);
   temp->birimMaliyeti = birimMaliyeti;
   temp->urunKategorisi = urunKategorisi;
   temp->etTuru = etTuru;
   strcpy(temp -> paketlemeTarihi, paketlemeTarihi);
   strcpy(temp -> sonKullanmaTarihi, sonKullanmaTarihi);
   return;
}

void ekle_tarimBagliListe(char urunAdi[20], int birimMaliyeti,char urunKategorisi,char tarimTuru, char alinmaTarihi[10]){

  tarim * iter = tarimBagliListe;

  if(iter == NULL){;
    iter =(tarim*)malloc(sizeof(tarim));
    iter->next= NULL;
    strcpy(iter -> urunAdi, urunAdi);
    iter->birimMaliyeti = birimMaliyeti;
    iter->urunKategorisi = urunKategorisi;
    strcpy(&iter->tarimTuru, &tarimTuru);
    strcpy(iter -> alinmaTarihi, alinmaTarihi);

    tarimBagliListe = iter;
    return;
  }

  while(iter->next !=NULL)  {
    iter = iter->next;

  }

   tarim * temp = (tarim *)malloc(sizeof(tarim));
   temp->next = iter->next;
   iter ->next = temp;
   strcpy(temp -> urunAdi, urunAdi);
   temp->birimMaliyeti = birimMaliyeti;
   temp->urunKategorisi = urunKategorisi;
   temp->tarimTuru = tarimTuru;
   strcpy(temp -> alinmaTarihi, alinmaTarihi);
   return;
}

void ekle_sutBagliListe(char urunAdi[20], int birimMaliyeti,char urunKategorisi, char sonKullanmaTarihi[10]){
    
  sut * iter = sutBagliListe;

  if(iter == NULL){;
    iter =(sut*)malloc(sizeof(sut));
    iter->next= NULL;
    strcpy(iter -> urunAdi, urunAdi);
    iter->birimMaliyeti = birimMaliyeti;
    iter->urunKategorisi = urunKategorisi;
    strcpy(iter -> sonKullanmaTarihi, sonKullanmaTarihi);

    sutBagliListe = iter;
    return;
  }

  while(iter->next !=NULL)  {
    iter = iter->next;

  }

   sut * temp = (sut *)malloc(sizeof(sut));
   temp->next = iter->next;
   iter ->next = temp;
   strcpy(temp -> urunAdi, urunAdi);
   temp->birimMaliyeti = birimMaliyeti;
   temp->urunKategorisi = urunKategorisi;
   strcpy(temp -> sonKullanmaTarihi, sonKullanmaTarihi);
   return;
}

void ekle_konserveBagliListe(char urunAdi[20], int birimMaliyeti,char urunKategorisi,int reyonNumarasi, char reyonTarafi, char sonKullanmaTarihiAyYil[12]){

   konserve * iter = konserveBagliListe;

  if(iter == NULL){;
    iter =(konserve*)malloc(sizeof(konserve));
    iter->next= NULL;
    strcpy(iter -> urunAdi, urunAdi);
    iter->birimMaliyeti = birimMaliyeti;
    iter->urunKategorisi = urunKategorisi;
    iter->reyonNumarasi = reyonNumarasi;
    iter->reyonTarafi = reyonTarafi;
    strcpy(iter -> sonKullanmaTarihiAyYil, sonKullanmaTarihiAyYil);

    konserveBagliListe = iter;
    return;
  }

  while(iter->next !=NULL)  {
    iter = iter->next;

  }

   konserve * temp = (konserve *)malloc(sizeof(konserve));
   temp->next = iter->next;
   iter ->next = temp;
    strcpy(temp -> urunAdi, urunAdi);
    temp->birimMaliyeti = birimMaliyeti;
    temp->urunKategorisi = urunKategorisi;
    temp->reyonNumarasi = reyonNumarasi;
    temp->reyonTarafi = reyonTarafi;
    strcpy(temp -> sonKullanmaTarihiAyYil, sonKullanmaTarihiAyYil);
   return;
}

void ekle_gidaDisiBagliListe(char urunAdi[20], int birimMaliyeti,char urunKategorisi, char urunTuru, int reyonNumarasi, char reyonTarafi){

  gidaDisi * iter = gidaDisiBagliListe;

  if(iter == NULL){;
    iter =(gidaDisi*)malloc(sizeof(gidaDisi));
    iter->next= NULL;
    strcpy(iter -> urunAdi, urunAdi);
    iter->birimMaliyeti = birimMaliyeti;
    iter->urunKategorisi = urunKategorisi;
    iter->urunTuru = urunTuru;
    iter->reyonNumarasi = reyonNumarasi;
    iter->reyonTarafi = reyonTarafi;

    gidaDisiBagliListe = iter;
    return;
  }

  while(iter->next !=NULL)  {
    iter = iter->next;

  }

   gidaDisi * temp = (gidaDisi *)malloc(sizeof(gidaDisi));
   temp->next = iter->next;
   iter ->next = temp;
    strcpy(temp -> urunAdi, urunAdi);
    temp->birimMaliyeti = birimMaliyeti;
    temp->urunKategorisi = urunKategorisi;
    temp->urunTuru = urunTuru;
    temp->reyonNumarasi = reyonNumarasi;
    temp->reyonTarafi = reyonTarafi;
   return;
}
