#include<stdio.h>
#include<stdlib.h>
void traversal(int *a,int n) {
	int i;
	for(i=0;i<n;i++) {
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void merge(int a[],int low,int mid,int high) {
	int i=low,j=mid+1,k=low;
	int b[100];
	while(i<=mid && j<=high) {
		if(a[i]<a[j]) {
			b[k]=a[i];
			i++;
			k++;
		}
		else{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	
	while(i<=mid) {
		b[k]=a[i];
		i++;
		k++;
	}
	while(j<=high) {
		b[k]=a[j];
			j++;
			k++;
	}
	
	
	for(i=low;i<=high;i++) {
		a[i]=b[i];
	}
}

void mergesort(int a[],int low,int high) {
	int mid;
	if(low<high) {
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
	
}

int  main () {
	int n,i;
	printf("Enter no.of elements : ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements : \n");
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	
	traversal(a,n);
	printf("After sorting : \n");
	mergesort(a,0,n-1);
	traversal(a,n);
}
