#include "webinarFunction.h"

void insertRoot(struct search **root, char firstChar, struct node *temps){
	if(*root == NULL){
		*root = (struct search *) malloc(sizeof(struct search));

		if(*root != NULL){
			(*root)->hurufPertama = firstChar;
			(*root)->id = temps->id;
			(*root)->left = NULL;
			(*root)->right = NULL;
		} else {
			printf("%c gagal ditambah", firstChar);
		}
	} else {
		if(firstChar < (*root)->hurufPertama){
			insertRoot(&(*root)->left, firstChar, temps);
		} else if(firstChar > (*root)->hurufPertama){
			insertRoot(&(*root)->right, firstChar, temps);
		}
	}
}

void inOrder(struct search **root){
	if(*root != NULL){
		inOrder(&(*root)->left);
		printf("id: %d, %c\n", (*root)->id ,(*root)->hurufPertama);
		inOrder(&(*root)->right);
	}
}


int main(){
    // Animasi Pembukaan program
	system ("COLOR 70");
	
	int i, j;
	printf ("\n\n\n\n\n\n\n\n\n\n\n");
	for (i = 0; i < 3; i++) {
		printf ("\t\t\t\t\t");
		for (j = 0; j < 47; j++) {
			printf ("=");
			usleep(1000);
		}
		printf ("\n");
	}
	
	printf ("\t\t\t\t\t");
	for (i = 0; i < 17; i++) {
		printf ("=");	
		usleep(1000);	
	}
	
	printf (" Sejuta Ilmu ");
	
	for (i = 0; i < 17; i++) {
		printf ("=");	
		usleep(1000);	
	}
	
	printf ("\n");
	for (i = 0; i < 3; i++) {
		printf ("\t\t\t\t\t");
		for (j = 0; j < 47; j++) {
			printf ("=");
			usleep(1000);
		}
		printf ("\n");
	}
	
	char a = 177;
	char b = 219;
	
	printf ("\n\n\n\n\n\n\n\n\n\n\n");
	printf ("\t\t");
	
	for (i = 0; i < 88; i++) {
		printf ("%c", a);
		printf ("\r");
		printf ("\t\t");
		for (i = 0; i < 88; i++) {
			printf ("%c", b);
			usleep(10000);
		}
	}
	// Akhir dari animasi pembukaan program

    //Inisialisasi variabel utama
    int opt;
    struct node * start = NULL; 
	struct node * temp; 
	struct node * current;

	//node pertama
    temp = (struct node *)malloc(sizeof(struct node)); 
	temp->id = 1;
	strcpy (temp->judulWebinar, "Globalisasi");
	strcpy (temp->tanggalPelaksanaan, "30 April 2022");
	strcpy (temp->hargaWebinar, "Berbayar");
	temp->kuotaWebinar = 50;
	
	temp->link = start; 
	start = temp;
	
	//node kedua
	temp = malloc(sizeof(struct node)); 
	temp->id = 2;
	strcpy (temp->judulWebinar, "Aku Manusia Biasa");
	strcpy (temp->tanggalPelaksanaan, "25 Mei 2022");
	strcpy (temp->hargaWebinar, "Gratis");
	temp->kuotaWebinar = 50;
	
	current = start; 
	while (current->link != NULL) {
		current = current->link;
	}
	current->link = temp;
	temp->link = NULL;

	//node ketiga
	temp = malloc(sizeof(struct node)); 
	temp->id = 3;
	strcpy (temp->judulWebinar, "Manusia Makhluk Sempurna");
	strcpy (temp->tanggalPelaksanaan, "2 Mei 2022");
	strcpy (temp->hargaWebinar, "Berbayar");
	temp->kuotaWebinar = 50;
	
	current = start; 
	while (current->link != NULL) {
		current = current->link;
	}
	current->link = temp;
	temp->link = NULL;
	
	//node keempat
	temp = malloc(sizeof(struct node)); 
	temp->id = 4;
	strcpy (temp->judulWebinar, "Indonesia Merdeka");
	strcpy (temp->tanggalPelaksanaan, "17 Agustus 2022");
	strcpy (temp->hargaWebinar, "Gratis");
	temp->kuotaWebinar = 50;
	
	current = start; 
	while (current->link != NULL) {
		current = current->link;
	}
	current->link = temp;
	temp->link = NULL;
	
	//node kelima
	temp = malloc(sizeof(struct node)); 
	temp->id = 5;
	strcpy (temp->judulWebinar, "Cara Investasi ala Warren Buffet");
	strcpy (temp->tanggalPelaksanaan, "26 Juni 2022");
	strcpy (temp->hargaWebinar, "Gratis");
	temp->kuotaWebinar = 50;
	
	current = start; 
	while (current->link != NULL) {
		current = current->link;
	}
	current->link = temp;
	temp->link = NULL;
	
	// binary tree dari sebuah link list
	struct search *root = NULL;
	struct node *temps;
	char firstChar;

	temps = start;
	while (temps != NULL){
		firstChar = temps->judulWebinar[0];
		insertRoot(&root, firstChar, temps);
		temps = temps->link;
	}
	
	

    // Program Start Menu
    do{   
        do{
        	system("cls"); 
        	printf("Selamat Datang di Aplikasi Info Webinar\n\n");

        	printf("=== Start Menu ===\n");
        	printf ("1. Admin\n");
        	printf ("2. Guest\n");
        	printf ("3. Panduan\n");
        	printf ("4. Kredit\n");
        	printf ("5. Exit Program\n\n");
            printf("Pilih Menu di Atas:\n> ");
            scanf("%d", &opt);

            if(opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt!= 5){
                printf ("\n*** Harap masukkan pilihan yang sesuai ***\n");
				sleep(2);
				system ("cls");
            }

        } while (opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt != 5);
        
        switch (opt){
        case 1:
            adminMenu(start);
            break;
        case 2:
            guestMenu(start, &root);
            break;
        case 3: 
            panduanStartMenu();
            fflush(stdin);
            printf("Tekan Enter untuk kembali...");
            getchar();
            break;
        case 4 : 
        	anggotaKelompok();
        	fflush(stdin);
            printf("\n\nTekan Enter untuk kembali...");
            getchar();
        	break;
        default:
            system("cls");
            printf ("\t\t\t\t");
			for (i = 0; i < 50; i++) {
					printf ("=");
					usleep(1000);
			}
			printf ("\n");
			
			printf ("\t\t\t\t");
			printf ("=");	
			usleep(1000);	

			printf (" Terima Kasih telah menggunakan aplikasi kami:D ");
			
			printf ("=");	
			usleep(1000);
			
			printf ("\n\t\t\t\t");
			for (i = 0; i < 50; i++) {
					printf ("=");
					usleep(1000);
			} 
			printf ("\n\n");
            break;
        }
    } while (opt != 5);
	// Akhir dari program Start Menu

    return 0;
}
