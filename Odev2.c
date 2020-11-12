#include <stdio.h>
#include <stdlib.h>

struct ogrenci{
  int numara;
  int not;
  int index;
  struct ogrenci *next;
};

typedef struct ogrenci node;

//Kullanılacak fonksiyonların tanımlamaları.
node * ekle(node* r, int numara, int not);
void notaGoreYazdir(node * r, int not);
void indexAyarla(node * r);
void tabloyuGoster(node * r);
node * sil(node* r, int index);
node * degistir(node * r, int numara, int yeniNot);

int main(void) {
	node * root;

	root = NULL;
	root = ekle(root,18060311,40);	
	root = ekle(root,20060045,50);	
	root = ekle(root,19061091,75);	
	root = ekle(root,20060134,90);	
	root = ekle(root,20060678,40);	
	root = ekle(root,18061086,75);	
	root = ekle(root,20060032,50);	
	root = ekle(root,20060067,60);	
	root = ekle(root,19060456,60);	
	root = ekle(root,18060245,75);	
	root = ekle(root,20060110,40);	
	root = ekle(root,20060234,90);	
	root = ekle(root,20060141,60);	
	root = ekle(root,20060011,50);	
	root = ekle(root,20060012,60);

/*
- Index tablosunun güncel halini görebilmek için 1 girebilirsiniz.
- Tabloya veri eklemek için 2 girebilirsiniz. Eklediğiniz veri eklenirken numara ve not baz alınarak doğru yere eklenecektir.(Ödevin 1. şartını yerine getirir.)
- Tablodan veri silmek için 3 girebilirsiniz. Aldığı tek parametre indexdir. Eğer verdiğiniz index tabloda mevcutsa silerken eğer tabloda yoksa uyarı mesajı verir.(Ödevin 2. şartını yerine getirir.)
- Bir öğrencinin notunu değiştirmek için 4 girebilirsiniz. Eğer aradığınız öğrenci mevcut ise o öğrencinin notunu değiştirip doğru indexde olmasını sağlayacaktır. Fonksiyonun ilk parametresi öğrencinin numarası, 2. parametresi ise öğrencinin yeni notu. (Ödevin 3. şartını yerine getirir.)
- Gireceğiniz nottan daha yüksek not alan öğrencileri görmek için 5 girebilirsiniz. Parametre olarak sizden bir not değeri ister ve bu nottan daha yüksek alan öğrencileri gösterir. (Ödevin 4. şartını yerine getirir.)
*/

  while(1){
    int secenek;

    printf("\nTabloyu goruntulemek icin 1,\nOgrenci eklemek icin 2,\nNot degistirmek icin 3,\nOgrenci silmek icin 4,\nGireceginiz nottan yuksek alan ogrencileri gormek icin 5 giriniz:");
    
    scanf("%d",&secenek);
    int not,numara,index;
    printf("\n");

    switch(secenek){
      case 1:
        printf("Güncel Index Tablosu:\n");
        tabloyuGoster(root);
        break;
      case 2:
         
          printf("\nTabloya eklemek istediğiniz ogrencinin numarasi:");
          scanf("%d",&numara);
          printf("\nTabloya eklemek istediğiniz ogrencinin notu:");
          scanf("%d",&not);
          root = ekle(root, numara, not);
      break;
      case 3:
          
          printf("\nNotunu değiştirmek istediğiniz öğrencinin numarası:");
          scanf("%d",&numara);
          printf("\n%d numaralı öğrencinin yeni notu:",numara);
          scanf("%d",&not);
          root = degistir(root, numara, not);
      break;
      case 4:
          
          printf("\nSilmek istediğiniz öğrencinin tablodaki indexini girin:");
          scanf("%d",&index);
          root = sil(root, index);
      break;
      case 5: 
          
          printf("\nHangi notun üstündeki öğrenciler gösterilsin:");
          scanf("%d",&not);
          notaGoreYazdir(root, not);
      break;

    }
  }
}


//Bağlı listenin elemanlarını pointer NULL gösterene kadar ekrana yazdırır.
void tabloyuGoster(node * r){
  while (r != NULL){
    printf("Index:%-2d Numara:%d Not:%d\n",r->index, r->numara, r->not );
    r = r->next;

  }
}

/*2. parametre olarak girilen not değerini alır ve bağlı listenin elemanları üzerinde sırayla dolaşmaya başlar. Bağlı listenin elemanları verilen parametreden büyük olduğu sürece yazdırılır.
*/
void notaGoreYazdir(node * r, int not){
  while (r != NULL){
    if(r->not > not){
      printf("Index:%-2d Numara:%d Not:%d\n",r->index, r->numara, r->not );
    }
    r = r->next;
  }
  return;
}

//Kodumdaki bazı fonksiyonlar return olarak bağlı listenin başındaki rootu döndürüyor. Bu fonksiyon her bir root return işleminden önce çalışarak, sıralı olan bağlı listedeki elemanlara 0 dan başlayarak sırayla index değerlerini veriyor.
void indexAyarla(node * r){
  int i = 0;
  while (r != NULL){
    r->index = i;
    r = r->next;
    i++;
}
}

/*Bağlı liste üzerinde sırayla dolaşarak iter pointerinin gösterdiği yapının index değeriyle, parametre olarak verilen index değerini karşılaştırır. Eğer while döngüsü iter pointerinin sona gelmesinden dolayı sonlanmadıysa geçici bir yapı oluşturur, bu yapıya silinecek yapıyı atar ve bu yapıyı hafızadan siler. İlk elemanı silme ihtimalimize karşı root değişebileceğinden node * tipinde return edilir.*/
node * sil(node* r, int index){
  node *temp;
  node *iter = r;

  if (r->index == index){
    temp = r;
    r = r->next;
    free(temp);
    indexAyarla(r);
    return r;
  }

  while(iter->next !=  NULL && iter->next->index != index){

    iter = iter->next;

  }
  if(iter->next == NULL){
    printf("Silmek istediğiniz index tabloda yok.\n");
    return r;
  }
  temp = iter->next;
  iter->next = temp->next;

  free(temp);
  indexAyarla(r);
  return r;  
}

/*
  Değiştir fonksiyonu değiştirmeyi istediğimiz öğrenciyi önce siler, sonrasında yeni not değeriyle ekler. Bu yüzden de öğrenciyi silerken veya eklerken bazı durumlara bakmalıydım. Eğer en yüksek nota ve numara önceliğine sahip ilk öğrenciyi siliyorsam linked list'in başını gösteren root değişebilir dolayısıyla yeniRoot diye bir pointer tanımlayıp sil fonksiyonundan dönen pointeri burada tutuyorum. Daha sonrasında ekle fonksiyonunu çağırırken bu yeni pointeri kullanıyorum ve eklerken eğer değişen değer başa eklenecek bir değerse root değişecek diye de bu ekle fonksiyonunun return ettiği sonucunu return ediyorum.
  */
node * degistir(node * r, int numara, int yeniNot) {

  node *iter = r;

  while(iter->next !=  NULL && iter->numara != numara){

    iter = iter->next;

  }
  if(iter->next == NULL && iter->numara != numara){
    printf("Degistirmek istediginiz numara index tablosunda yok.\n");
    return r;
  }

  int index = iter->index;

  node * yeniRoot = sil(r, index);

  return ekle(yeniRoot,numara,yeniNot);
}
/* Kullandığım ekle fonksiyonu, eklemek istediğimiz öğrencileri henüz eklerken sıralı bir şekilde  eklemek üzerine çalışıyor. Bir öğrenci eklerken dikkat etmem gereken birkaç olay vardı. İlk olay, eklemek istediğim öğrencinin notu ve numarası index tablosunda 1. sırada görünmesi gerekiyorsa bağlı listenin başını gösteren root pointerini değiştirmeliydim. Bu yüzden fonksiyonun başındaki if ve else if durumlarıyla root pointerini değiştirebilecek durumları kontrol ettim. Daha sonrasında eğer root değişmiyorsa iki ihtimal kalıyor. Bu ihtimallerden biri, yeni eklenecek öğrencinin index tablosunda sonuncu olma durumu. Diğer ihtimal ise bu öğrencinin aralarda bir yerde olma durumu. Bu olayı tespit edebilmek için öncelikle bir root ile aynı yeri gösteren bir iter pointeri tanımladım. Bu iter pointerini tanımlama sebebim tamamen listenin üzerinde gezinirken root pointerini kaybetmemek. While döngüsü ile iter pointerini eğer while döngüsünü bozan bir durum yoksa sürekli listedeki bir sonraki elemanı gösterecek şekilde tasarladım. While döngüsü, iter pointerinin gösterdiği bir sonraki kutu eğer NULL ise sonlanır ve öğrenciyi sona ekler. Eğer while döngüsü listenin son elemanına gelmeden sonlanıyorsa eğer bu sonlanmanın 2 sebebi vardır. İlki, eklemek istediğimiz öğrencinin notu, iter pointerinin gösterdiği öğrencinin notundan daha büyüktür ve döngü kırılır öğrenci araya eklenir. İkinci durum ise eklemek istediğimiz öğrenci ile iter pointerinin gösterdiği öğrencinin notu aynıdır ve aynı zamanda eklemek istediğimiz öğrencinin numarası daha küçüktür. Bu durumda da döngü bozulur ve öğrenci araya eklenir.*/
node * ekle(node* r, int numara, int not){
  if(r == NULL){ 

      r =(node*)malloc(sizeof(node));
      r->next= NULL;
      r->not = not;
      r->numara = numara;
      indexAyarla(r);  
      return r;
  }
  if(r->not < not){

      node * temp = (node*)malloc(sizeof(node));
      temp->not = not;
      temp ->numara = numara;
      temp->next = r;
      r = temp;
      indexAyarla(r);
      return temp;
    }
  else if(r->not == not && r->numara > numara){
   
      node * temp = (node*)malloc(sizeof(node));
      temp->not = not;
      temp ->numara = numara;
      temp->next = r;
      r = temp;
      indexAyarla(r);
      return temp;
  }
  node * iter = r;

  while(((iter->next !=NULL && iter->next->not >= not) )) {

    if(iter->next->not == not && iter->next->numara > numara){
      break;
      
    }

    iter = iter->next;
  
  }
  node * temp = (node*)malloc(sizeof(node));
  temp->next = iter->next;
  iter ->next = temp;
  temp -> not = not;
  temp ->numara = numara;
  indexAyarla(r);
  return r;
}
