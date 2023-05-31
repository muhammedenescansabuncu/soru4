#include <stdio.h>
#include <stdlib.h>

// Baðlantýlý liste düðümü yapýsý
struct Node {
    int veri;
    struct Node* sonraki;
};

struct Node* bas = NULL;
struct Node* son = NULL;

// Yeni bir düðüm oluþturma
struct Node* dugumOlustur(int veri) {
    struct Node* yeniDugum = (struct Node*)malloc(sizeof(struct Node));
    yeniDugum->veri = veri;
    yeniDugum->sonraki = NULL;
    return yeniDugum;
}

// Listeye eleman ekleme
void ekle(int veri) {
    struct Node* yeniDugum = dugumOlustur(veri);
    
    if (bas == NULL) {
        bas = yeniDugum;
        son = yeniDugum;
    } else {
        son->sonraki = yeniDugum;
        son = yeniDugum;
    }
    
    printf("%d degeri eklendi.\n", veri);
}

// Listeden eleman silme
void sil() {
    if (bas == NULL) {
        printf("Liste bos, silme islemi yapilamaz.\n");
        return;
    }
    
    struct Node* silinecek = bas;
    int silinenDeger = silinecek->veri;
    
    bas = bas->sonraki;
    
    free(silinecek);
    
    printf("%d degeri silindi.\n", silinenDeger);
}

// Listeyi görüntüleme
void goruntule() {
    if (bas == NULL) {
        printf("Liste bos.\n");
        return;
    }
    
    struct Node* temp = bas;
    printf("Liste: ");
    while (temp != NULL) {
        printf("%d ", temp->veri);
        temp = temp->sonraki;
    }
    printf("\n");
}

int main() {
    int secim, deger;
    
    while (1) {
        printf("1. Ekleme\n2. Silme\n3. Goruntuleme\nSeciminiz: ");
        scanf("%d", &secim);
        
        switch (secim) {
            case 1:
                printf("Eklemek istediginiz degeri giriniz: ");
                scanf("%d", &deger);
                ekle(deger);
                break;
            case 2:
                sil();
                break;
            case 3:
                goruntule();
                break;
            default:
                printf("Gecersiz secim. Tekrar deneyin.\n");
        }
    }
    
    return 0;
}
