#include <iostream>
using namespace std;

int partition(int arr[], int lb, int ub)
{
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    while(start<end){
        while (arr[start]<=pivot)
        {
            start++;
        }
        while (arr[end]>pivot)
        {
            end--;
        }
        if(start<end){
            swap(arr[start],arr[end]);
        }
        
    }
    swap(arr[lb],arr[end]);
    return end;

}

void quickSort(int arr[], int start, int end)
{
	if (start >= end)
		return;
	int p = partition(arr, start, end);
	quickSort(arr, start, p-1);
	quickSort(arr, p + 1, end);
}

int main()
{

	int arr[] = { 9, 3, 4, 2, 1, 8 };
	int n = 6;

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
    cout<<endl;

	return 0;
}
