#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

struct node {
	int id;
	char judulWebinar[50];
	char tanggalPelaksanaan[50];
	char hargaWebinar[10];
	int kuotaWebinar;
	struct node *link;
};

void infoWebinar (struct node *start, int i);
void tambahWebinar (struct node *start, int i);
struct node *hapusWebinar (struct node *start, int i, int hapusWebinar);
void panduanAdmin ();

int i = 1;

int main () {
	system ("COLOR 70");
	
    int opt;
    
	int pilihan;
    int perulangan = 1;
    char kembali;
    
    int pil_hapusWebinar;
	
	struct node * start = NULL; 
	struct node * temp; 
	struct node * current;


	temp = (struct node *)malloc(sizeof(struct node)); 
	temp->id = 1;
	strcpy (temp->judulWebinar, "Globalisasi");
	strcpy (temp->tanggalPelaksanaan, "30 April 2022");
	strcpy (temp->hargaWebinar, "Berbayar");
	temp->kuotaWebinar = 50;
	
	temp->link = start; 
	start = temp;
	
	
	temp = malloc(sizeof(struct node)); 
	temp->id = 2;
	strcpy (temp->judulWebinar, "Internet of Things");
	strcpy (temp->tanggalPelaksanaan, "25 Mei 2022");
	strcpy (temp->hargaWebinar, "Gratis");
	temp->kuotaWebinar = 50;
	
	current = start; 
	while (current->link != NULL) {
		current = current->link;
	}
	current->link = temp;
	temp->link = NULL;

	
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

	while (perulangan == 1) {
		system ("cls");
		printf ("=== Daftar Fitur ===\n");
		printf ("1. Info Webinar\n");
		printf ("2. Menambahkan Webinar\n");
		printf ("3. Menghapus Webinar\n");
		printf ("4. Panduan Admin\n");
		printf ("5. Exit\n\n");
		printf ("> Pilih menu di atas : ");
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
			printf ("> Pilih menu di atas : ");
			scanf ("%d", &pilihan);
		}
		
		switch (pilihan) // percabangan input "pilihan"
		{
		case 1: 
			system ("cls");
			
			infoWebinar (start, i);
			
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
		
		case 2:
			system ("cls");
			
			tambahWebinar (start, i);
	
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
			
			infoWebinar (start, i);
			
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
		
		case 3:
			system ("cls");
			
			infoWebinar (start, i);
			
			printf ("\n> Webinar mana yang ingin Anda hapus ? ");
			scanf ("%d", &pil_hapusWebinar);
			
			while (pil_hapusWebinar < 1 || pil_hapusWebinar > i) {
				printf ("*** Harap masukkan jawaban yang sesuai ***\n");
				printf ("> Webinar mana yang ingin Anda hapus ? ");
				scanf ("%d", &pil_hapusWebinar);
			}
			
			start = hapusWebinar (start, i, pil_hapusWebinar);
			
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
			
			infoWebinar (start, i);
					
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
	return 0;
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

void infoWebinar (struct node *start, int i) {
	struct node *current;
	
	if (start == NULL) {
		printf (">>> Daftar Webinar Kosong\n");
		return;
	}
			
	current = start;
	
	printf (">>> Berikut adalah daftar webinar yang tersedia\n\n");
	
	i = 1;
	while (current != NULL) {
		printf("%d. %s || %s || %s || %d\n", i, current->judulWebinar, current->tanggalPelaksanaan, current->hargaWebinar, current->kuotaWebinar);
		current->id = i;
		current = current->link;
		i++;
	}
}

void tambahWebinar (struct node *start, int i) {
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
	
	printf (">> Harga Webinar [gratis/berbayar] : ");
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

struct node *hapusWebinar (struct node *start, int i, int pil_hapusWebinar) {
	struct node *temp;
	struct node *current;
	
	if (start == NULL) {
		printf (">>> Daftar Webinar Kosong\n");
		return;
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
