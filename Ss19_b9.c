#include <stdio.h>
#include <string.h>

struct SinhVien {
	int id;
	char name[50];
	int age;
	char phoneNumber[15];
};

void showSV(struct SinhVien sv[], int n);
void addSV(struct SinhVien sv[], int *n);
void fixSV(struct SinhVien sv[], int n);
void delSV(struct SinhVien sv[], int *n);
void findSV(struct SinhVien sv[], int n);
void arrangeSV(struct SinhVien sv[], int n);

int main(){
	struct SinhVien sv[100] = {
		{1,"dung",18,"0987311189"},
	    {2,"huy",18,"0987311190"},
	    {3,"hoan",18,"0987311191"},
	    {4,"tung",18,"0987311192"},
	    {5,"mono",18,"0987311193"},
    };
    
    int chose;
	int n = 5;
    do {
    	printf("Menu\n");
    	printf("1.Hien thi danh sach sinh vien\n ");
    	printf("2.Them sinh vien\n ");
    	printf("3.Sua thong tin sinh vien\n ");
    	printf("4.Xoa sinh vien\n ");
    	printf("5.Tim kiem sinh vien\n ");
    	printf("6.Sap xep danh sach sinh vien\n ");
    	printf("7.Thoat\n ");
    	scanf("%d",&chose);
    	fflush(stdin);
    	switch(chose){
    		case 1:{
    			showSV(sv, n);
				break;
			}
			case 2:{
				addSV(sv, &n);
				break;
			}
			case 3:{
				fixSV(sv, n);
				break;
			}
			case 4:{
				delSV(sv, &n);
				break;
			}
			case 5:{
				findSV(sv, n);
				break;
			}
			case 6:{
				arrangeSV(sv, n); 
				break;
			}
			case 7:{
				printf("\nBan chon thoat");
				break;
			}
			default:
				printf("khong thuoc menu");
		}
	}while(chose!=7);
	return 0;
}

void showSV(struct SinhVien sv[],int n){
	for(int i=0;i<n;i++){
		printf("ID sv: %d\n",sv[i].id);
		printf("Ten sv: %s\n",sv[i].name);
		printf("Tuoi sv: %d\n",sv[i].age);
		printf("Sdt sv: %s\n ",sv[i].phoneNumber);
	}	
}

void addSV(struct SinhVien sv[], int *n){
	int index;
	printf("Vi tri them: ",*n+1);
	scanf("%d",&index);
	
	while(index<1||index>(*n)+1){
	    printf("Vui long nhap dung\n");
		printf("Vi tri them: ", (*n)+1);
		scanf("%d", &index);
	}
	fflush(stdin);
	for ( int i = *n; i>= index ; i--){
		sv[i].id = sv[i-1].id +1;
		strcpy( sv[i].name, sv[i-1].name);
		sv[i].age = sv[i-1].age;
		strcpy( sv[i].phoneNumber, sv[i-1].phoneNumber);
	}
	
	sv[index-1].id = index ;
	printf("Nhap ten sv: ");
	fgets( sv[index-1].name, sizeof( sv[index-1].name), stdin);
	int size = strlen(sv[index-1].name);
	sv[index-1].name[size-1] = '\0';
	
	printf("Nhap tuoi: ");
	scanf("%f", &sv[index-1].age);
	fflush(stdin);
	
	printf("\nNhap sdt: ");
	fgets( sv[index-1].phoneNumber,sizeof( sv[index-1].phoneNumber),stdin);
	
	(*n)++;
	for ( int i=0;i<*n ;i++){
		printf("ID: %d\n", sv[i].id);
		printf("Ten: %s\n", sv[i].name);
		printf("Tuoi: %d\n", sv[i].age);
		printf("Sdt: %s\n ", sv[i].phoneNumber);
	}
}

void fixSV( struct SinhVien sv[],int n){
	int index;
	printf("Vi tri sua: ", n);
	scanf("%d", &index);
	
	while ( index < 1 || index > n ){
		printf("Vui long nhap dung\n");
		printf("Vi tri sua: ", n);
		scanf("%d", &index);
	}
	fflush(stdin);
	sv[index-1].id = index ;
	printf("Nhap ten sv:");
	fgets( sv[index-1].name, sizeof( sv[index-1].name), stdin);
	int len = strlen(sv[index-1].name);
	sv[index-1].name[len-1] = '\0';
	
	printf("Nhap tuoi: ");
	scanf("%f", &sv[index-1].age);
	fflush(stdin);
	
	printf("Nhap sdt: ");
	fgets( sv[index-1].phoneNumber, sizeof( sv[index-1].phoneNumber), stdin);
	
	printf("Ket qua: \n");
	for ( int i = 0; i< n; i++){
		printf("ID: %d\n", sv[i].id);
		printf("Ten: %s\n", sv[i].name);
		printf("Tuoi: %d\n", sv[i].age);
		printf("Sdt: %s\n ", sv[i].phoneNumber);
	}
}

void delSV( struct SinhVien sv[],int *n){
	int index;
	printf("Vi tri xoa: ",*n);
	scanf("%d", &index);
	while( index < 1 || index > *n ){
		printf("Vui long nhap dung\n");
		printf("Vi tri them:\n ", *n);
		scanf("%d", &index);
	}
	fflush(stdin);
	for( int i = index-1 ; i < (*n)-1  ; i++){
		sv[i].id = sv[i+1].id ;
		strcpy( sv[i].name, sv[i+1].name);
		sv[i].age = sv[i+1].age;
		strcpy( sv[i].phoneNumber, sv[i+1].phoneNumber);
	}
	(*n)--;
	for ( int i = 0; i< *n ; i++){
		printf("ID: %d\n", sv[i].id);
		printf("Ten: %s\n", sv[i].name);
		printf("Tuoi: %d\n", sv[i].age);
		printf("Sdt: %s\n ", sv[i].phoneNumber);
	}
}
void findSV( struct SinhVien sv[], int n){
	char input[50];
	int count = 0;	
	printf("Nhap ten can tim: ");
	fgets( input, 50, stdin);
	int size = strlen(input);
	input[size-1] = '\0';
	for ( int i = 0; i<n; i++){
		if ( strcmp(sv[i].name, input)==0){
			count = 1;
			printf("SV can tim: \n");
			printf("ID: %d\n", sv[i].id);
			printf("Ten: %s\n", sv[i].name);
			printf("Tuoi: %d\n", sv[i].age);
			printf("Sdt: %s\n ", sv[i].phoneNumber);
			break;
		}
	}
	if(count==0) printf("Khong thay sv\n");
}
void arrangeSV( struct SinhVien sv[], int n){
	for( int i = 0; i< n; i++){
		for ( int j = 0; j< n-1-i; j++){
			if ( strcmp(sv[j].name, sv[j+1].name ) > 0 ){
				struct SinhVien temp = sv[j];
                sv[j] = sv[j+1];
                sv[j+1] = temp;
			}
		}
	}
	for ( int i = 0; i< n ; i++){
		printf("ID: %d\n", sv[i].id);
		printf("Ten: %s\n", sv[i].name);
		printf("Tuoi: %d\n", sv[i].age);
		printf("Sdt: %s\n ", sv[i].phoneNumber);
	}
}
