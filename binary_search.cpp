#include<iostream>
using namespace std;
bool binary_search(int el,int l,int r, int arr [])
{
	int mid;
	if(l<=r)
	{
		mid=(l+r)/2;
		if(arr[mid]==el)
			return true;
		if(el < arr[mid])
			return binary_search(el, l, mid-1, arr);
		if(el>arr[mid])
			return binary_search(el, mid+1, r, arr);		
	}
	else{
		return false;
	}

}
int main()
{
	int arr[6]={4, 5, 6, 7, 1, 3};
	int n=sizeof(arr)/sizeof(arr[0]);
	if(binary_search(-26, 0, n-1, arr))
	{
		cout<<"Element found";
	}
	else{
		cout<<"Element not found";
	}
}
