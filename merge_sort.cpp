#include<iostream>
using namespace std;
void merge(int [], int, int, int);
void mergesort(int arr[], int l, int r)
{
	if(l<r)
	{
	 	int mid=(l+r)/2;
	 	mergesort(arr, l, mid);
	 	mergesort(arr, mid+1, r);
	 	merge(arr, l, r, mid);
	}
}
void merge(int arr[], int l, int r, int m)
{
	int i=l, k=l, j=m+1;
	int temp[10];
	while (i<=m&&j<=r)
	{
		if(arr[i]<arr[j])
		{
			temp[k]=arr[i];
			i++;
			k++;
		}
		else{
			temp[k]=arr[j];
			j++;
			k++;
		}
	}
	while (i<=m)
	{
		temp[k]=arr[i];
		i++;
		k++;
	}
	while(j<=r)
	{
		temp[k]=arr[j];
		j++;
		k++;
	}
	for(int i=l;i<=r;i++)
	{
		arr[i]=temp[i];
	}
}
int main()
{
	int arr[5]={9, 7, 3, 6, 3};
	int n=sizeof(arr)/sizeof(arr[0]);
	mergesort(arr, 0, n-1);
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
