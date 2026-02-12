#include <stdio.h>

int main()
{
	int i,j,key,pass=0;
	int arr[]={4,6,3,2,5,1};
	for (i=1;i<=6;i++){
	
	key=arr[i];
	j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j=j-1;
			pass++;
		}
	arr[j+1]=key;
	}
	for(int k = 0; k<6; k++)
	printf("%d",arr[k]);
	printf("\nNo of passes :%d",pass);
}
