#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct data{
    int id;
    char nama[50];
    char email[50];
    char phoneNumber[50];
};
struct node{
    struct data pendaftar;
    struct node *next;
};

struct node *head = NULL;
struct node *last = NULL;

const int atSymbol = 64;

bool isEmpty();
char menu();
void insert(struct data pendaftar);

void displayList();

bool isEmpty(){
    return head == NULL;
}
char menu(){
    char choice;
    printf("1. Input data pendaftar\n");
    printf("2. Cetak data pendaftar\n");
    printf("3. Cari data pendaftar\n");
    printf("4. Total data pendaftar\n");
    printf("5. Exit\n\n");
    printf("Pilihan: ");
    scanf(" %c",&choice);
    return choice;
}
void insert(struct data pendaftar){
    if(isEmpty(head)){
        struct node *temp = (struct node*) malloc(sizeof(struct node));
        temp->pendaftar = pendaftar;
        temp->next = NULL;
        head = temp;
        last = temp;
    }else{
        struct node *temp = (struct node*) malloc(sizeof(struct node));
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
        struct node*current = head;
        printf("-----Bukti Pembayaran-----");
        printf("\n");
        while(current!=NULL){
            printf("Id Pendaftar : %d\n", current->pendaftar.id );
            printf("Nama Pendaftar : %s\n", current->pendaftar.nama );
            printf("Email Pendaftar : %s\n", current->pendaftar.email );
            printf("No telepon Pendaftar :%s\n", current->pendaftar.phoneNumber );
            printf("---------------------------------\n");
            current = current->next;
        }
    }
}
void searchId(){
    int tempid;
    if(!isEmpty(head)){
        printf("id nama yang dicari: ");
        scanf("%d", &tempid);
        struct node *temp = head;
        while(temp->next!=NULL){
            if(temp->pendaftar.id==tempid){
                break;
            }
            temp = temp->next;
        }
        if(temp->pendaftar.id==tempid){
            printf("Nama pendaftar: %s\n",temp->pendaftar.nama);
            printf("Nama Pendaftar : %s\n", temp->pendaftar.nama );
            printf("Email Pendaftar : %s\n", temp->pendaftar.email );
            printf("No telepon Pendaftar :%s\n", temp->pendaftar.phoneNumber );

        }else{
            printf("data id %d tidak ditemukan", tempid);
        }
    }else{
        printf("Data kosong");
    }
}
void showTotal(){
    struct node *temp = head;
    int total = 0;
    while(temp!=NULL){
        total += 1;
        temp = temp->next;
    }
    printf("Total data pendaftar yang mendaftar webinar : %d\n", total);
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
int main()
{
    char choice;
    struct data pendaftar;
    int flag = 0;
    do{
        system("cls");
        choice = menu();
        switch(choice){
            case '1':
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

                insert(pendaftar);
                break;
            case '2':
                displayList(head);
                break;
            case '3':
                searchId();
                break;
            case '4':
                showTotal();
                break;
            case '5':
                printf("Exit");
                break;
            default:
                printf("Input salah");
                break;
        }
        getch();
    }while(choice!='6');
    return 0;
}