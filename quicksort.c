#include <stdio.h>
#include <stdlib.h>

#define N 2000000

void swap(int *arr, int a, int b){
	int t=arr[a];
	arr[a]=arr[b];
	arr[b]=t;
}

//Devuelve el indice del pivote(o la cantidad de elementos a la izquierda).
int particionar(int *arr, int n){
	int i=0, j=n-1;
    while(i!=j){
        if(arr[i+1]<=arr[i]){
            swap(arr, i, i+1);
            i++;
        }
        else {
            swap(arr, j, i+1);
            j--;
        }
    }
    return i;
}

void quicksort(int *arr, int n){
    if(n>1){
	    int pivote=particionar(arr, n);
	    quicksort(arr, pivote);
	    quicksort(arr+pivote+1, n-pivote-1);
    }
}

int main(){
	int arr[N];
	for(int i=0; i<N;i++) arr[i]=rand()%(N*10);
	quicksort(arr, N);
	// for(int i=0;i<N;i++) printf("%d ", arr[i]);
  return 0;
}
