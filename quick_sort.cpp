#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[], int l, int r)
{
	int pivot=arr[r];
	int i=l-1;
	for(int j=l; j<r;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[r]);
	return (i+1);
}

void quickSort(int arr[],int l,int r)
{
	if(l<r)
	{
		int p;
		p=partition(arr, l, r);
		quickSort(arr, l, p-1);
		quickSort(arr, p+1, r);
	}
}

int main()
{
	int arr[6]={12, 34, 56, 89, 10, 2};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"-----------------------Before Sorting------------------"<<endl;
	for(int i=0; i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n-----------------------After Sorting------------------"<<endl;
	quickSort(arr, 0, n-1);
	for(int i=0; i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
