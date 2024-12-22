#include <stdio.h>
struct SinhVien{
	int id;
	char name[50];
	int age;
	char phoneNumber[15];
};
void SapxepSinhVien(struct SinhVien sv[],int *n);
int main(){
	int n=5;
	struct SinhVien sv[5]={
	{1,"a",18,"0987311189"},
	{2,"c",18,"0987311190"},
	{3,"e",18,"0987311191"},
	{4,"b",18,"0987311192"},
	{5,"d",18,"0987311193"},
	};
	SapxepSinhVien(sv,&n);
	return 0;
}
void SapxepSinhVien(struct SinhVien sv[],int *n){
	for(int i=0;i< *n;i++){
		for (int j=0;j<*n-i-1; j++) {
            if (strcmp(sv[j].name,sv[j+1].name)>0) {
                struct SinhVien temp=sv[j+1];
                sv[j+1]=sv[j];
                sv[j] = temp;
            }
        }
	}
	 for (int i=0;i< *n;i++) {
        printf("\nID sv: %d", sv[i].id);
        printf("\nTen sv: %s", sv[i].name);
        printf("\nTuoi sv: %d", sv[i].age);
        printf("\nSdt sv: %s\n", sv[i].phoneNumber);
    }
}
