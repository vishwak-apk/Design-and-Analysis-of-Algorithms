#include <iostream>
int main() {
    int i,j,n,temp;
    
    std::cout<<"Enter the Value of n: ";
    std::cin>>n;
    int arr[n];
    std::cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        std::cin>>arr[i];
    }

    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    std::cout << " Sorted array: ";
    for (int k = 0; k < n; k++) {
        std::cout << arr[k] << " ";
    }
    std::cout << std::endl;
    return 0;
}
