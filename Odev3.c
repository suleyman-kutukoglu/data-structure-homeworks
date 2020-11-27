#include <stdio.h>
#include <stdlib.h>

typedef struct node{

  int diskBoyutu; //3 en büyük, 2 orta, 1 en küçük disk.
  struct node* next; 
}node;

//Verilen bağlı listenin başına eğer altında daha küçük disk yoksa disk ekler.
node* push(node* head, int diskSize);

//İşlemlerin doğrulunun kontrolü için çubukları her disk taşıma işleminden sonra yazdırır.
void cubuklariYazdir(node* solCubuk, node* ortaCubuk, node* sagCubuk);

//Yazdığım pop fonksiyonu, bağlı liste boş değilse bağlı listenin ilk elemanını siler ve bu işlemden dolayı bağlı listeyi gösteren pointer değiştiği için yeni pointer ataması yapar. Pop fonksiyonum sildiği değeri döndürdüğü için aynı anda pointer ataması yapmamın yolu, bağlı listeyi gösteren pointerin adresini parametre göndermekti. Bu yüzden pop fonksiyonum böyle bir parametre alıyor. 
int pop(node **pptr);


int main(void){

  node * solCubuk = NULL;
  node * ortaCubuk = NULL;
  node * sagCubuk = NULL;

  solCubuk = push(solCubuk, 3);
  solCubuk = push(solCubuk, 2);
  solCubuk = push(solCubuk, 1);
  printf("**********************\n");
  cubuklariYazdir(solCubuk, ortaCubuk, sagCubuk);

  //Sol çubukta en üstte yer alan en küçük diski siler ve sağ çubuğa ekler.
  sagCubuk = push(sagCubuk, pop(&solCubuk));
  cubuklariYazdir(solCubuk, ortaCubuk, sagCubuk);

  //Sol çubukta en üstte yer alan orta boy diski siler ve orta çubuğa ekler.
  ortaCubuk = push(ortaCubuk, pop(&solCubuk));
  cubuklariYazdir(solCubuk, ortaCubuk, sagCubuk);

  //Sağ çubukta yer alan en küçük diski siler ve orta çubukta bulunan orta boy diskin üzerine yerleştirir.
  ortaCubuk = push(ortaCubuk, pop(&sagCubuk));
  cubuklariYazdir(solCubuk, ortaCubuk, sagCubuk);

  //Sağ çubuk bir önceki işlemden dolayı boştur. Sol çubuktaki son disk olan en büyük diski alır ve sağ çubuğa yerleştirir.
  sagCubuk = push(sagCubuk, pop(&solCubuk));
  cubuklariYazdir(solCubuk, ortaCubuk, sagCubuk);

  //Sol çubuk bir önceki işlemden dolayı boştur. Orta çubukta en üstte yer alan en küçük diski alır ve sol çubuğa yerleştirir.
  solCubuk = push(solCubuk, pop(&ortaCubuk));
  cubuklariYazdir(solCubuk, ortaCubuk, sagCubuk);

  //Orta çubukta bir önceki işlemden dolayı sadece orta boy disk vardır. Orta çubuktaki son disk olan orta boy diski alır ve sağ çubuğa yerleştirir.
  sagCubuk = push(sagCubuk, pop(&ortaCubuk));
  cubuklariYazdir(solCubuk, ortaCubuk, sagCubuk);

  //Sol çubukta bulunan en küçük diski, sağ çubuktaki en büyük diskin üzerindeki orta boy diskin üzerine yerleştirir. 7 Adımda tamamlanır.
  sagCubuk = push(sagCubuk, pop(&solCubuk));
  cubuklariYazdir(solCubuk, ortaCubuk, sagCubuk);
}

node* push(node* head,int diskBoyutu)
{
    node* tmp = (node*)malloc(sizeof(node));
    if(tmp == NULL)
    {
        exit(0);
    }
    //Küçük disklerin üzerine büyük disk eklenmemesi için yaptığım kontrol.
    if (head != NULL && head->diskBoyutu < diskBoyutu){
      printf("Diskler sadece kendisinden daha büyük disklerin üzerine eklenebilir!");
      return head;
    }
    tmp->diskBoyutu = diskBoyutu;
    tmp->next = head;
    head = tmp;
    return head;
}


int pop(node **pptr){

  node * head = *pptr;
  if(head == NULL){
    printf("Çubukta silinecek disk yok!");
    return -1;
  }

  node* tmp = head;
  int silinenDiskBoyutu = head->diskBoyutu;
  head = head->next;
  free(tmp);
  //Burada bağlı listemin başını gösteren pointeri yeni pointerimle değiştiriyorum. Pop fonksiyonu silinen disk boyutunu döndürdüğü için aynı anda return head gibi birşey yapamadığımdan böyle bir çözüme gittim.
  *pptr = head;
  return silinenDiskBoyutu;
}

//Her adımı görsel olarak görebilmek için böyle bir fonksiyon yazdım.
void cubuklariYazdir(node* solCubuk, node* ortaCubuk, node* sagCubuk)
{
    node *current;
    current = solCubuk;
    if(current!= NULL)
    {
        printf("Sol Çubuk: ");
        do
        {
            printf("%d-",current->diskBoyutu);
            current = current->next;
        }
        while (current!= NULL);
        printf("|\n");
    }
    else
    {
        printf("Sol çubuk şuan boş!\n");
    }
    current = ortaCubuk;
    if(current!= NULL)
    {
        printf("Orta Çubuk: ");
        do
        {
            printf("%d-",current->diskBoyutu);
            current = current->next;
        }
        while (current!= NULL);
        printf("|\n");
    }
    else
    {
        printf("Orta çubuk şuan boş!\n");
    }
    current = sagCubuk;
    if(current!= NULL)
    {
        printf("Sağ Çubuk: ");
        do
        {
            printf("%d-",current->diskBoyutu);
            current = current->next;
        }
        while (current!= NULL);
        printf("|\n");
    }
    else
    {
        printf("Sağ çubuk şuan boş!\n");
    }
    printf("**********************\n");
}
