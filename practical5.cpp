#include <iostream>
using namespace std;

// Template function for Selection Sort
template <typename T>

void selection_sort(T arr[],int size)
{
	T temp;
	for (int i =0;i<size;i++)
	{
		for (int j=i+1;j<size;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}	
	}	
}
template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Integer array
    
    int list[5];
    int n ;
    cout<<"Enter the size of array :";
	cin>>n;
	cout<<endl;
	int value;
	cout<<"Enter Element :"<<endl;
	for (int i =0;i<n;i++)
	{
			cout<<"["<<i<<"] :";
			cin>>value;
			list[i]=value;
			//cout<<endl;
	}
	
    cout << "Original Integer Array: ";
    printArray(list, n);

    // Sort integer array
    selection_sort(list, n);

    cout << "Sorted Integer Array: ";
    printArray(list, n);

    return 0;
}

