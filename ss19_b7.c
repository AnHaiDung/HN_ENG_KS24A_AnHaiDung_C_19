#include <stdio.h>
struct SinhVien{
	int id;
	char name[50];
	int age;
	char phoneNumber[15];
};
void XoaSinhVien(struct SinhVien sv[],int *n,int id);
int main(){
	int id;
	int count=0;
	int n=5;
	struct SinhVien sv[5]={
	{1,"dung",18,"0987311189"},
	{2,"huy",18,"0987311190"},
	{3,"hoan",18,"0987311191"},
	{4,"tung",18,"0987311192"},
	{5,"mono",18,"0987311193"},
	};
	printf("nhap id sinh vien can xoa: ");
	scanf("%d",&id);
	XoaSinhVien(sv,&n,id);
	return 0;
}
void XoaSinhVien(struct SinhVien sv[],int *n,int id){
	int count=0;
	int index;
	for(int i=0;i<*n;i++){
		if(sv[i].id==id){
			count=1;
			index=i;
			break;
		}
	}
	if(count==0){
		printf("Id khong ton tai");
	}else{
		for(int i=0;i<(*n)-1;i++){
			sv[i]=sv[i+1];
		}
		(*n)--;
		for(int i=0;i< *n;i++){
			printf("\nID sv: %d", sv[i].id);
			printf("\nTen sv: %s", sv[i].name);
			printf("\nTuoi sv: %d", sv[i].age);
			printf("\nSdt sv: %s ", sv[i].phoneNumber);
		}
	}
}
