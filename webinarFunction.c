#include "webinarFunction.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

struct node {
	int id;
	char judulWebinar[50];
	char tanggalPelaksanaan[50];
	char hargaWebinar[10];
	int kuotaWebinar;
	struct node *link;
};

struct data{
    int id;
    char nama[50];
    char email[50];
    char phoneNumber[50];
};

struct Node{
    struct data pendaftar;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *last = NULL;

struct search{
	char hurufPertama;
	int id;
	struct search *left;
	struct search *right;
};

int batas = 5;
const int atSymbol = 64, BACKSPACE = 8, CARRIAGE_RETURN = 13;

void infoWebinar (struct node *start) {
    int i = 1;
	struct node *current;
	
	if (start == NULL) {
		printf (">>> Daftar Webinar Kosong\n");
		return;
	}
			
	current = start;
	
	printf (">>> Berikut adalah daftar webinar yang tersedia\n\n");
	
	while (current != NULL) {
		printf("%d. %s || %s || %s || %d\n", i, current->judulWebinar, current->tanggalPelaksanaan, current->hargaWebinar, current->kuotaWebinar);
		current->id = i;
		current = current->link;
		i++;
	}
}

void tambahWebinar (struct node *start) {
    int i = 1;
	struct node *temp;
	struct node *current;
	
	temp = malloc(sizeof(struct node)); 
			
	printf ("Masukkan data informasi mengenai daftar webinar yang ingin ditambahkan\n\n");
					
	printf (">> Judul Webinar : ");
	scanf (" %255[^\n]s", &temp->judulWebinar);
	fflush (stdin);
	
	printf (">> Tanggal Pelaksanaan Webinar [misal 10 Mei 2022] : ");
	scanf (" %255[^\n]s", &temp->tanggalPelaksanaan);
	fflush (stdin);
	
	printf (">> Harga Webinar [Gratis/Berbayar] : ");
	scanf (" %255[^\n]s", &temp->hargaWebinar);
	fflush (stdin);
	
	printf (">> Kuota Webinar [misal 20]: ");
	scanf ("%d", &temp->kuotaWebinar);
	fflush (stdin);
	
	temp->id = i;
	
	current = start; 
	while (current->link != NULL) {
		current = current->link;
	}
	current->link = temp;
	temp->link = NULL;
}

struct node *hapusWebinar (struct node *start, int pil_hapusWebinar) {
	struct node *temp;
	struct node *current;
	
	if (start == NULL) {
		printf (">>> Daftar Webinar Kosong\n");
		return start;
	}
	
	else if (pil_hapusWebinar == 1) {
		temp = start;			
		start = start->link;
		free(temp);
		return start;
	}
	
	current = start;
	
	while (current->link != NULL) {
		if (current->link->id == pil_hapusWebinar) {
			temp = current->link;
			current->link = temp->link;
			free(temp);
			return start;
		}
		current = current->link;
	}
}

void panduanAdmin () {
	
	printf ("\t\t\t\t===============================\n");
	printf ("\t\t\t\t***** Panduan Role Admin ******\n");
	printf ("\t\t\t\t===============================\n");
	
	printf ("> Admin merupakan role penting dalam aplikasi ini\n");
	printf ("> Admin memiliki beberapa kendali terhadap suatu hal yang tidak dapat dilakukan oleh 'guest'\n");
	printf (">> Untuk mendapatkan kendali sebagai seorang Admin, diperlukan proses login terlebih dahulu\n");
	printf (">> Oleh karena itu, Admin perlu mengetahui username dan password agar dapat login sebagai Admin\n");
	printf (">>> Admin dapat melihat daftar webinar seperti guest\n");
	printf (">>> Admin dapat menambahkan webinar hingga maksimal 10 webinar dapat ditampung oleh aplikasi ini\n");
	printf (">>> Admin juga dapat melakukan penghapusan webinar jika dirasa webinar tersebut sudah berlalu\n");
}

// awal dari menu admin
void adminMenu(struct node *start){
    int i, j;
    int opt;
    
    char uchar;
    char username[20];
    char password[20];
    
    int pilihan;
    int perulangan = 1;
    char kembali;

    int pil_hapusWebinar;

    system("cls");
	
	// algoritma 
	printf ("\t\t\t\t\t");
	for (i = 0; i < 47; i++) {
			printf ("=");
			usleep(1000);
	}
	printf ("\n");
	
	printf ("\t\t\t\t\t");
	for (i = 0; i < 8; i++) {
		printf ("=");	
		usleep(1000);	
	}
	
	printf (" Selamat Datang di Menu Admin ");
	
	for (i = 0; i < 9; i++) {
		printf ("=");	
		usleep(1000);	
	}
	
	printf ("\n\t\t\t\t\t");
	for (i = 0; i < 47; i++) {
			printf ("=");
			usleep(1000);
	} 
	printf ("\n\n");

    // kode login sistem
	printf ("Harap melakukan login terlebih dahulu\n\n");
	
	printf ("Username : ");
	fflush (stdin);
	scanf ("%s", username);
	
	printf ("Password : ");
	fflush (stdin);
	
	for (i = 0; (uchar = getch()) != CARRIAGE_RETURN; ++i) {
		if (uchar == BACKSPACE) {
			if (i > 0) {
				printf ("%s", "\b\033[K");
				i -= 2;
				continue; 
			}
			else {
				--i;
			}
		}
		else {
			password [i] = uchar;
			printf ("%c", '*');
		}
	}
	password[i] = '\0';
	printf ("\n");
	
	// perulangan permintaan input ketika username/password salah
	while (strcmp (username, "admin") != 0 || strcmp (password, "admin") != 0) {
		printf ("\n*** Username atau Password yang Anda masukkan salah ***\n");
		printf (">>>>>>>>>>>>>>>> Silahkan Coba Kembali <<<<<<<<<<<<<<<<\n\n");
		sleep(2);

		printf ("Username : ");
		fflush (stdin);
		scanf ("%s", username);
	
		printf ("Password : ");
		fflush (stdin);
		
		for (i = 0; (uchar = getch()) != CARRIAGE_RETURN; ++i) {
			if (uchar == BACKSPACE) {
				if (i > 0) {
					printf ("%s", "\b\033[K");
					i -= 2;
					continue; 
				}
				else {
					--i;
				}
			}
			else {
				password [i] = uchar;
				printf ("%c", '*');
			}
		}
		password[i] = '\0';
		printf ("\n");
	}
	
	if (strcmp (username, "admin") == 0) {
		if (strcmp (password, "admin") == 0) { // jika username dan password benar
			printf ("\nLogin berhasil...\n");
			printf ("Loading...\n");
			Sleep(1000);
			char a = 177;
			char b = 219;
	
			printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf ("\t\t");
	
			for (i = 0; i < 88; i++) {
				printf ("%c", a);
				printf ("\r");
				printf ("\t\t");
				for (i = 0; i < 88; i++) {
					printf ("%c", b);
					usleep(1000);
				}
			}
			// perulangan apabila pengguna ingin kembali ke menu "Daftar Fitur"
			while (perulangan == 1) {
				system("cls");
				printf ("=== Daftar Fitur ===\n");
				printf ("1. Info Webinar\n");
				printf ("2. Menambahkan Webinar\n");
				printf ("3. Menghapus Webinar\n");
				printf ("4. Panduan Admin\n");
				printf ("5. Exit\n\n");
				printf ("Pilih menu di atas : \n>");
				scanf ("%d", &pilihan);
				
				while (pilihan != 1 && pilihan != 2 && pilihan != 3 && pilihan != 4 && pilihan != 5) { // error handling input "pilihan"
					printf ("\n*** Harap masukkan pilihan yang sesuai ***\n");
					sleep(1);
					system ("cls");
					
					printf ("=== Daftar Fitur ===\n");
					printf ("1. Info Webinar\n");
					printf ("2. Menambahkan Webinar\n");
					printf ("3. Menghapus Webinar\n");
					printf ("4. Panduan Admin\n");
					printf ("5. Exit\n\n");
					printf ("Pilih menu di atas : \n>");
					scanf ("%d", &pilihan);
				}
				
				switch (pilihan) // percabangan input "pilihan"
				{
				case 1: // bagian daftar webinar yang tersedia yang telah diurutkan secara alfabet (sorting berdasarkan judul)
					system ("cls");
					infoWebinar (start);
			
                    printf ("\n> Apakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
                    fflush(stdin);
                    kembali = getchar();
                    
                    // error handling input "kembali"
                    while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
                        printf ("*** Harap masukkan jawaban yang sesuai ***\n");
                        printf ("\n> Apakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
                        fflush(stdin);
                        kembali = getchar();
                    }
                    
                    if (kembali == 'y' || kembali == 'Y') {
                        perulangan = 1;
                    }	
                    
                    else if (kembali == 'n' || kembali == 'N') {
                        perulangan = -1;
                    }	
					
					break;
				case 2: // bagian menambahkan daftar webinar yang dapat diikuti oleh pengguna
					tambahWebinar (start);
	
                    printf ("\n\n\n\t\t\t*** Webinar baru berhasil ditambahkan ***\n\n");	
                    
                    printf ("loading");
                    for (i = 1; i <= 3; i++) {
                        printf(".");
                        usleep(500000);
                    }
                    
                    system ("cls"); 
                    
                    printf ("\t\t\t ================================\n");
                    printf ("\t\t\t ==== Daftar Webinar Terbaru ====\n");
                    printf ("\t\t\t ================================\n\n");
                    
                    infoWebinar (start);
                    
                    printf ("\n> Apakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
                    fflush(stdin);
                    kembali = getchar();
                    
                    // error handling input "kembali"
                    while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
                        printf ("*** Harap masukkan jawaban yang sesuai ***\n");
                        printf ("\n> Apakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
                        fflush(stdin);
                        kembali = getchar();
                    }
                    
                    if (kembali == 'y' || kembali == 'Y') {
                        perulangan = 1;
                    }	
                    
                    else if (kembali == 'n' || kembali == 'N') {
                        perulangan = -1;
                    }
					break;
				case 3: // bagian menghapus daftar webinar yang tersedia jika memang sudah kadaluarsa / sudah terlaksana
					system ("cls");
					infoWebinar (start);
			
                    printf ("\n> Webinar mana yang ingin Anda hapus ? ");
                    scanf ("%d", &pil_hapusWebinar);
                    
                    while (pil_hapusWebinar < 1 || pil_hapusWebinar > i) {
                        printf ("*** Harap masukkan jawaban yang sesuai ***\n");
                        printf ("> Webinar mana yang ingin Anda hapus ? ");
                        scanf ("%d", &pil_hapusWebinar);
                    }
                    
                    start = hapusWebinar (start, pil_hapusWebinar);
                    
                    printf ("\n\n\n\t\t\t *** Webinar berhasil di hapus *** \n\n");
                    
                    printf ("loading");
                    for (i = 1; i <= 3; i++) {
                        printf(".");
                        usleep(500000);
                    }
                    
                    system ("cls"); // print daftar webinar setelah penghapusan salah satu webinar
                    
                    printf ("\t\t\t ================================\n");
                    printf ("\t\t\t ==== Daftar Webinar Terbaru ====\n");
                    printf ("\t\t\t ================================\n\n");
                    
                    infoWebinar (start);
                            
                    printf ("\n> Apakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
                    fflush(stdin);
                    kembali = getchar();
                    
                    // error handling input "kembali"
                    while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
                        printf ("*** Harap masukkan jawaban yang sesuai ***\n");
                        printf ("\n> Apakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
                        fflush(stdin);
                        kembali = getchar();
                    }
                    
                    if (kembali == 'y' || kembali == 'Y') {
                        perulangan = 1;
                    }	
                    
                    else if (kembali == 'n' || kembali == 'N') {
                        perulangan = -1;
                    }
					break;
				case 4:
					system ("cls");
					panduanAdmin(); // memanggil fungsi panduanAdmin
			
                    printf ("\n> Apakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
                    fflush(stdin);
                    kembali = getchar();
                    
                    // error handling input "kembali"
                    while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
                        printf ("*** Harap masukkan jawaban yang sesuai ***\n");
                        printf ("\n> Apakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
                        fflush(stdin);
                        kembali = getchar();
                    }
                    
                    if (kembali == 'y' || kembali == 'Y') {
                        perulangan = 1;
                    }	
                    
                    else if (kembali == 'n' || kembali == 'N') {
                        perulangan = -1;
                    }	
					
					break;
				default:
					perulangan = -1; // kembali ke start menu
					break;
				}
			}
		}	
	}
}
// akhir dari menu admin


bool isEmpty(){
    return head == NULL;
}

void insert(struct data pendaftar){
    if(isEmpty(head)){
        struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
        temp->pendaftar = pendaftar;
        temp->next = NULL;
        head = temp;
        last = temp;
    }else{
        struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
        temp->pendaftar = pendaftar;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

}

void displayList(){
    if(isEmpty(head)){
        printf("Data kosong");
    }else{
        struct Node*current = head;
        printf("\t\t=======================================\n");
	    printf ("\t\t==== Bukti Pembelian Tiket Webinar ====\n");
	    printf ("\t\t=======================================\n");
        printf("\n");
        while(current!=NULL){
            printf("\t\tId Pendaftar : %d\n", current->pendaftar.id );
            printf("\t\tNama Pendaftar : %s\n", current->pendaftar.nama );
            printf("\t\tEmail Pendaftar : %s\n", current->pendaftar.email );
            printf("\t\tNo telepon Pendaftar :%s\n", current->pendaftar.phoneNumber );
            printf ("\t\tWaktu Transaksi : %s", __TIME__);
            printf("\n\t\t----------------------------------\n");
            current = current->next;
        }
    }
    fflush(stdin);
    printf("Tekan Enter untuk lanjut...");
    getchar();
}

int phoneNumberCheck(char phoneNumber[]){
	int i;

	if(strlen(phoneNumber) != 12){
		return 1;
	}

	for (i = 0; i < strlen(phoneNumber); i++){
		if(phoneNumber[i] < '0' || phoneNumber[i] > '9'){
			return 1;
		}
	}

	return 0;
}

int emailChecking(char email[]){
	int i;
	for (i = 0; i < strlen(email); i++){
		if(email[i] == atSymbol){
			return 0;
		}
	}
	return 1;
}

void daftarWebinar (struct node *start) {
	int i, j, pilihan, flag = 0;
    struct data pendaftar;

	system ("cls");
	printf ("\t\t\t\t\t");
	for (i = 0; i < 47; i++) {
			printf ("=");
			usleep(1000);
	}
	printf ("\n");
	
	printf ("\t\t\t\t\t");
	for (i = 0; i < 9; i++) {
		printf ("=");	
		usleep(1000);	
	}
	
	printf (" Proses Pendaftaran Webinar ");
	
	for (i = 0; i < 10; i++) {
		printf ("=");	
		usleep(1000);	
	}
	
	printf ("\n\t\t\t\t\t");
	for (i = 0; i < 47; i++) {
			printf ("=");
			usleep(1000);
	} 
	printf ("\n\n");
	
    printf("Id Pendaftar (Harus Angka) : ");
    scanf("%d", &(pendaftar.id));
	
    printf("> Masukkan Nama Anda : ");
	scanf(" %255[^\n]s", &(pendaftar.nama));  	  	
    fflush(stdin);

	do
	{
		printf("> Masukkan Email Anda : ");
        scanf(" %255[^\n]s", &(pendaftar.email));
        fflush(stdin);

        if(flag = emailChecking((pendaftar.email))){
            printf("*** Email harus ada @, Coba Lagi! ***\n\n");
        }
		
	} while (flag);
	
	do
	{
		printf("> Masukkan No. Telepon Anda : ");
        scanf(" %255[^\n]s", &(pendaftar.phoneNumber));
        fflush(stdin);

        if(flag = phoneNumberCheck((pendaftar.phoneNumber))){
            printf("*** Mohon masukkan nomor telepon dengan benar! (12 angka) ***\n\n");
        }
		
	} while (flag);
    
	
	printf("\n======== Berikut Nama Judul Webinar dan Waktunya ========\n");
	printf("\n");	
	infoWebinar (start);
	
	printf("\nPilih Webinar yang tersedia : ");
	scanf("%i", &pilihan);
    insert(pendaftar);

    if (pilihan == 1) {
		start->kuotaWebinar -= 1;
	}
    while (start->link != NULL){
        if(start->link->id == pilihan){
            start->link->kuotaWebinar -= 1;
        }
        start = start->link;
    }
    
	system("cls");
	
	displayList();
	
    system("cls");
	printf ("\t");
	printf ("==========================================================\n\t");
	printf ("Terima Kasih Telat Mendaftar Webinar Melalui Aplikasi Kami\n\t");
	printf ("==========================================================\t");
}

// Berbagai fungsi panduan
void panduanStartMenu () {
    system("cls");
    printf("Pada Menu Awal ini ada tiga pilihan\n");
    printf("1. User bisa memilih admin, jika user berupa developer dari aplikasi ini\n");
    printf("2. User bisa memilih guest, jika user adalah seorang tamu yang ingin mencari info webinar\n");
    printf("3. User bisa memilih exit, jika ingin keluar dari aplikasi\n\n");
}

void panduanInfoWebinar () {
    system("cls");
    printf("1. User dapat melihat berbagai macam webinar yang ada di aplikasi ini\n");
    printf("2. Informasi yang ditampilkan: \n a. Judul Webinar\n b. Tanggal Pelaksanaan\n c. Harga Webinar\n d. Kuota Webinar\n\n");
}

void panduanDaftarWebinar(){
    system("cls");
    printf("1. User memasukkan nama, email, dan nomor telepon\n");
    printf("2. User memilih webinar yang diinginkan\n");
    printf("3. User hanya dapat mendaftar webinar yang kuota masih tersedia\n");
    printf("4. User bisa mengecek kembali data yang dimasukkan, pastikan data sudah benar\n");
    printf("5. Jika sudah selesai mendaftar, user bisa kembali ke guest menu\n\n");
}

void panduanSearchWebinar(){
    system("cls");
    printf("1. User memasukkan huruf pertama judul webinar\n");
    printf("2. User bisa memasukkan huruf kedua untuk mencari judul webinar\n");
    printf("3. Jika sudah muncul webinar yang ingin diikuti, user bisa kembali ke guest menu\n\n");
}

void panduanGuestMenu(){
    int opt;
    do{   
        system("cls"); 
        printf("=== Panduan Guest Menu ===\n");
        printf ("1. Info Webinar\n");
        printf ("2. Daftar Webinar\n");
        printf ("3. Search Webinar\n");
        printf ("4. Exit\n\n");
        do{
            printf("Pilih menu di atas:\n> ");
            scanf("%d", &opt);

            if(opt != 1 && opt != 2 && opt != 3 && opt != 4){
                printf("Mohon masukkan pilihan yang benar!\n\n");
            }

        } while (opt != 1 && opt != 2 && opt != 3 && opt != 4);
        
        switch (opt){
        case 1:
            panduanInfoWebinar();
            fflush(stdin);
            printf("Tekan Enter untuk kembali...");
            getchar();
            break;
        case 2:
            panduanDaftarWebinar();
            fflush(stdin);
            printf("Tekan Enter untuk kembali...");
            getchar();
            break;
        case 3: 
            panduanSearchWebinar();
            fflush(stdin);
            printf("Tekan Enter untuk kembali...");
            getchar();
            break;
        default:
            fflush(stdin);
            break;
        }
    } while (opt != 4);
}
// akhir dari program panduan


//program search dengan algoritma binary search tree
void searchWebinar(struct search **root, struct node *start, char firstChar){

	struct node *temp;
	temp = start;

	if(*root != NULL){
		if(firstChar < (*root)->hurufPertama){
			searchWebinar(&(*root)->left, start, firstChar);
		} else if( firstChar > (*root)->hurufPertama){
			searchWebinar(&(*root)->right, start, firstChar);
		} else {
			printf("Judul ditemukan...\n\n");
			printf("Berikut judul webinar yang Anda cari: \n");
			while(temp != NULL){
				if((*root)->id == temp->id){
					printf("%d. %s", temp->id, temp->judulWebinar);
				}
				temp = temp->link;
			}
		}
	} else {
		printf("Judul tidak ditemukan...\n");
	}
	
}
// akhir dari program search

// awal dari menu guest
void guestMenu(struct node *start, struct search **root) {

	int i;
    int opt;
	int perulangan = 1;
	char kembali;
	char firstChar, lanjut;
	int flag = 0;
	
	system ("cls");
	printf ("\t\t\t\t\t");
	for (i = 0; i < 47; i++) {
			printf ("=");
			usleep(1000);
	}
	printf ("\n");
	
	printf ("\t\t\t\t\t");
	for (i = 0; i < 8; i++) {
		printf ("=");	
		usleep(1000);	
	}
	
	printf (" Selamat Datang di Menu Guest ");
	
	for (i = 0; i < 9; i++) {
		printf ("=");	
		usleep(1000);	
	}
	
	printf ("\n\t\t\t\t\t");
	for (i = 0; i < 47; i++) {
			printf ("=");
			usleep(1000);
	} 
	printf ("\n\n");
	
	while (perulangan == 1) {
		system("cls");
		printf("=== Guest Menu ===\n");
		printf ("1. Info Webinar\n");
		printf ("2. Daftar Webinar\n");
		printf ("3. Search Webinar\n");
		printf ("4. Panduan\n");
		printf ("5. Exit\n\n");
		
	    printf("Pilih menu di atas:\n> ");
	    scanf("%d", &opt);

    	while (opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt != 5) {
	    	printf ("*** Harap masukkan pilihan yang sesuai ***\n\n");
			sleep (1);
			
		    printf("Pilih menu di atas:\n> ");
		    scanf("%d", &opt);
		}

	    switch (opt){
	    case 1:
	    	system ("cls");
	    	
	        infoWebinar(start);
	        
		    printf ("\nApakah Anda ingin kembali ke Guest Menu [y/n] ? ");
			fflush(stdin);
			kembali = getchar();
			
			while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
				printf ("*** Harap masukkan jawaban yang sesuai ***\n");
				printf ("\nApakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
				fflush(stdin);
				kembali = getchar();
			}
			
			if (kembali == 'y' || kembali == 'Y') {
				perulangan = 1;
			}	
			
			else if (kembali == 'n' || kembali == 'N') {
				perulangan = -1;
			}		
	        break;
	        
	    case 2:
	        daftarWebinar(start);
	        
	        printf ("\n\nApakah Anda ingin kembali ke Guest Menu [y/n] ? ");
			fflush(stdin);
			kembali = getchar();
			
			while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
				printf ("*** Harap masukkan jawaban yang sesuai ***\n");
				printf ("\nApakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
				fflush(stdin);
				kembali = getchar();
			}
			
			if (kembali == 'y' || kembali == 'Y') {
				perulangan = 1;
			}	
			
			else if (kembali == 'n' || kembali == 'N') {
				perulangan = -1;
			}		
	        break;
	        
	    case 3:
			system("cls");
			printf("====== Search ======\n\n");
			do
			{
				do
				{
					printf("\nMasukkan huruf pertama dari webinar yang ingin Anda cari: ");
					fflush(stdin);
					scanf("%c", &firstChar);

					if(firstChar < 'A' || firstChar > 'Z'){
						printf("Tolong masukkan huruf kapital!\n");
						flag = 1;
					} else {
						flag = 0;
					}
				} while (flag);
				
				
				searchWebinar(root, start, firstChar);

				printf("\nIngin mencari lagi? [y/n]: ");
				fflush(stdin);
				scanf("%c", &lanjut);

				if(lanjut == 'y' || lanjut == 'Y'){
					flag = 1;
				} else {
					flag = 0;
				}
			} while (flag);

	        printf ("\nApakah Anda ingin kembali ke Guest Menu [y/n] ? ");
			fflush(stdin);
			kembali = getchar();
			
			while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
				printf ("*** Harap masukkan jawaban yang sesuai ***\n");
				printf ("\nApakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
				fflush(stdin);
				kembali = getchar();
			}
			
			if (kembali == 'y' || kembali == 'Y') {
				perulangan = 1;
			}	
			
			else if (kembali == 'n' || kembali == 'N') {
				perulangan = -1;
			}		
	        break;
	        
	    case 4:
	        panduanGuestMenu();	
	        break;
	        
	    default:
			perulangan = -1;
	        break;
		}	
	}
}
// akhir dari menu guest

//credit
void anggotaKelompok () {
	int i, j;
	
	system ("cls");
	printf ("\n\n\n\n\n\n\n\n\n\n\n");
	printf ("\t\t\t\t\t");
	
	for (j = 0; j < 47; j++) {
		printf ("=");
		usleep(1000);
	}
	printf ("\n");
	
	printf ("\t\t\t\t\t1. Irham Muslim \t\t 2006574313\n");
	usleep(100000);
	printf ("\t\t\t\t\t2. Tubagus Dylan Rachmat \t 2006574521\n");
	usleep(100000);
	printf ("\t\t\t\t\t3. Raihan Nagib \t\t 2006574654\n");
	usleep(100000);
	
	printf ("\t\t\t\t\t");
	for (j = 0; j < 47; j++) {
		printf ("=");
		usleep(1000);
	}
	printf ("\n");
}
// akhir dari kredit
