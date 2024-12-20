#include <stdio.h>
#include <string.h>

int main() {
	int choice,addIndex;
	int count=0;
	struct Dish{
		int id;
	    char name[50];
	    int price;
	};
	struct Dish menu[100];
	printf("Nhap so luong mon an: ");
	scanf("%d", &count);
	fflush(stdin);
	for (int i = 0; i<count; i++){
		menu[i].id= i+1;
		printf("Mon an thu %d: \n", menu[i].id);
	    printf("Nhap ten: ");
	    fgets(menu[i].name, sizeof(menu[i].name), stdin);
	    printf("Nhap gia tien: ");
	    scanf("%d", &menu[i].price);
	    fflush(stdin);
	}
	do{
		printf("\t----Menu---\t\n");
		printf("1.In ra menu\n");
		printf("2.Them phan tu\n");
		printf("3.Sua phan tu\n");
		printf("4.Xoa phan tu\n");
		printf("5.Sap xep tang dan theo gia\n");
		printf("6.Tim kiem phan tu (linear search)\n");
		printf("7.Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:{
				printf("\t\tMenu:\n");
				for (int i=0; i<count; i++){
					printf("%d. %s: %d\n", menu[i].id, menu[i].name, menu[i].price);
				}
				break;
			}
			case 2:{
				if(count>0){
					menu[count].id=count+1;
					printf("Nhap mon an thu %d: \n", count+1);
					fflush(stdin);
					printf("Nhap ten mon an: ");
					fgets(menu[count].name, sizeof(menu[count].name), stdin);
	    			printf("Nhap gia tien: ");
	    			scanf("%d", &menu[count].price);
	    			getchar();
	    			count++;
	    		} else{
	    			printf("Chua co menu\n");
				}
				break;
			}
			case 3:{
				if(count>0){
					fflush(stdin);
					printf("Sua mon an thu %d: \n", count);
					printf("Nhap ten mon an: ");
					fgets(menu[count-1].name, sizeof(menu[count-1].name), stdin);
	    			printf("Nhap gia tien: ");
	    			scanf("%d", &menu[count-1].price);
	    			getchar();
					break;
				} else{
					printf("Chua co menu\n");
				}
			}
			case 4:{
				if(count>0){
					menu[count].id=count-1;
					printf("Xoa mon an thu %d: \n", count);
	    			getchar();
	    			count--;
	    		} else{
	    			printf("Chua co menu\n");
				}
				break;
			}
			case 5:{
				struct Dish temp;
				if(count>1){
					for (int i=0; i<count-1; i++){
				        for (int j=i+1; j<count; j++){
				            if (menu[i].price>menu[j].price){
				                temp=menu[i];
				                menu[i]=menu[j];
				                menu[j]=temp;
				            }
				        }
				    }
					printf("Menu da duoc sap xep\n");
	    		} else{
	    			printf("Chua co menu\n");
				}
				break;
			}
			case 6:{
				char search[50];
				printf("Nhap vao mon an can tim: ");
				scanf("%s", search);
				for (int i=0; i<count; i++){
					if (strcmp(menu[i].name, search)==0){
						printf("Mon an o vi tri: %d\n", menu[i].id);
						break;
					} else {
						printf("Khong ton tai mon an");
					}
				}
			}
			case 7:{
				printf("Hen gap lai\n");
				break;
			}
			default:{
				printf("Lua con khong hop le\n");
				break;
			}
		}
	}while(choice!=7);
	return 0;
}

