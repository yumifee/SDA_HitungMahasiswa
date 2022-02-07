//Nama		: Yumi Febriana
//Kelas		: 1B JTK
//NIM		: 211511063
//Tanggal	: 2/7/2022
// MK		: SDA

#include <stdio.h>
#include <conio.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <windows.h>

using namespace std;
typedef struct{
	char jurusan [5];
	char prodi [45];
	int jmlwanita , jmlpria;
}Data_a;
typedef struct {
	char jurusan [15];
	int Tot_Prodi;
	int jml_mayopria;
	int jml_mhsjur;
}Data_b;

void input();
void TampilData();
void RekapTotal();

int main(){
	int menu;
	for(;;)
	{
	system("cls");
	printf("|============================|\n");
	printf("|          MAHASISWA         |\n");
	printf("|         PILIH  MENU        |\n");
	printf("|============================|\n");
	printf("|1. Entry Data               |\n");
	printf("|2. Tampil Data              |\n");
	printf("|3. Rekap Data               |\n");
	printf("|4. Selesai                  |\n");
	printf("|============================|\n");
	printf("|============================|\n");
	printf("\n");
	printf("Pilih Menu : ");
	scanf("%d" ,&menu);
	
	switch (menu){
		case 1 :
			input();
			break;
		case 2 :
			system("cls");
			TampilData();
			system("pause");
			break;
		case 3 :
			system("cls");
			RekapTotal();
			system("pause");
			break;
		case 4 :
			return 0;
		default :
			printf("\t\n\nSalah Input");
			system("cls");
			break;
	}	
	}
}
void input(){
	Data_a A;
	char lagi;
	FILE *file_a;
	
	if((file_a=fopen("DataA.dat","ab+"))==NULL){
		printf("File tidak dapat dibuka\n");
		exit(1);
	}
	for (;;){
		fflush(stdin);
		printf("Jurusan :");
		scanf ("%s", A.jurusan);
		fflush(stdin);
		printf("Prodi :");
		scanf ("%[^\n]s", A.prodi);
		fflush(stdin);
		printf("Jumlah Wanita :");
		scanf ("%d", &A.jmlwanita);
		fflush(stdin);
		printf("Jumlah pria :");
		scanf ("%d", &A.jmlpria);
		fflush(stdin);
		fprintf(file_a,"%s,%s,%d,%d,", A.jurusan , A.prodi , A.jmlwanita , A.jmlpria);
		printf ("Entry Data Lagi? (y/t)");
		lagi = getche();
		printf("\n");
		if (lagi == 't' || lagi == 'T')
			break;
	}
	fclose(file_a);
}

void TampilData(){
	
	Data_a A;
	Data_b B;
	FILE *file_a;

	if ((file_a=fopen("DataA.dat","ab+"))==NULL)
	{
		printf ("File Tidak Dapat Dibuka");
	}
		printf ("\n DATA MAHASISWA ADALAH : \n\n");
		printf ( "Jurusan\t\tProdi\t\t\t\t\t\tWanita\tPria \n");
	
	while (fscanf(file_a,"%[^,],%[^,],%d,%d,", A.jurusan,A.prodi,&A.jmlwanita,&A.jmlpria)!=EOF)
	{
		printf("%s\t\t%s\t\t\t\t\%d\t\%d\n",A.jurusan,A.prodi,A.jmlwanita,A.jmlpria);
	}
	fclose(file_a);
}

void RekapTotal(){
	FILE *file_A;
	FILE *file_b;
	Data_a A;
	Data_b B;
	int compare;
	
	if((file_A = fopen("DataA.dat","rb"))==NULL){
		printf("File tidak dapat dibuka");
		exit(1);
	}
	
	if((file_b = fopen("DataB.dat","wb"))==NULL){
		printf("File tidak dapat dibuka");
		exit(1);
	}
	
	fscanf(file_A,"%[^,],%[^,],%d,%d,\n",A.jurusan,A.prodi,&A.jmlwanita,&A.jmlpria);
	while(!feof(file_A)){
		strcpy(B.jurusan,A.jurusan);
		B.Tot_Prodi = 0;
		B.jml_mayopria = 0;
		B.jml_mhsjur = 0;
		compare = strcmp(A.jurusan,B.jurusan);
		while(!feof(file_A) && (compare == 0)){
			B.Tot_Prodi = B.Tot_Prodi + 1;
			B.jml_mhsjur = B.jml_mhsjur + A.jmlwanita + A.jmlpria;
			if(A.jmlwanita < A.jmlpria){
				B.jml_mayopria = B.jml_mayopria+ 1;
			}
			fscanf(file_A,"%[^,],%[^,],%d,%d,",A.jurusan,A.prodi,&A.jmlpria,&A.jmlwanita);
			compare = strcmp(A.jurusan,B.jurusan);
		}
		fprintf(file_b,"%s,%d,%d,%d,\n",B.jurusan,B.Tot_Prodi,B.jml_mayopria,B.jml_mhsjur);
		printf("%s\t\%d\t\%d\t\%d\n", B.jurusan,B.Tot_Prodi,B.jml_mayopria,B.jml_mhsjur);
	}
	fclose(file_A); 
	fclose(file_b); 
}
int data(){
	main();
}
