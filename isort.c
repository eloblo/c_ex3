#include <stdio.h>

#define SIZE 50

void shift_elements(int *arr, int i);
void insertion_sort(int *arr, int len);

int main(){
	int arr[SIZE];
	int i;
	for(i = 0; i < SIZE; i++){
		if(!scanf("%d",arr+i)){
			printf("error in input\n");
			return 1;
		}
	}
	insertion_sort(arr,SIZE);
	return 0;
}

void shift_elements(int *arr, int i){
	if(i <= 0 || arr == NULL){
		return;
	}
	int index = 1;
	int temp1, temp2;
	temp1 = *arr;
	while(index <= i){
		temp2 = *(arr+index);
		*(arr+index) = temp1;
		temp1 = temp2;
		index++;
	}
	*arr = temp1;
}

void insertion_sort(int *arr, int len){
	if(len <= 0 || arr == NULL){
		return;
	}
	int i,j;
	for(i = 1; i < len; i++){
		j = i;
		while(*(arr+j-1) > *(arr+j) && j > 0){
			shift_elements(arr+j-1,1);
			j--;	
		}
	}
	for(i =0; i < len; i++){
		printf("%d,",*(arr+i));
	}
	printf("\n");
}

