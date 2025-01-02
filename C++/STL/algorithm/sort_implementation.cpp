#include <iostream>
#include <string>

namespace mySpace{
    template <typename T = int >
    int partition(T arr[], int low, int high){
        int pi = (low + high) / 2; // some random partition index
        T pivot = arr[pi];
        while(low <= high){
            while(low <= high && arr[low] <= pivot) low++;
            while(low < high && arr[high] > pivot) high--;
            if(low < high){
                if(high == pi){
                    pi = low;
                }
                std::swap(arr[low++], arr[high--]);
            } 
        }
        std::swap(arr[low-1], arr[pi]);
        return low - 1;
    }

    template <typename T = int >
    void quick_sort(T arr[], int low, int high){
        if(low < high){
            int pi = partition(arr, low, high);
            quick_sort <T> (arr, low, pi - 1);
            quick_sort <T> (arr, pi+1, high);
        }
    }
    
    template < typename T = int >
    void sort(T arr[], int n){
        // quick sort algo
        quick_sort <T> (arr, 0, n-1);
    }
}

int main(){
    
    {
        int arr[] = {32, 1, 3, 2};
        int n = sizeof(arr) / sizeof(arr[0]);
        mySpace::sort <int> (arr, n);
        for(int i = 0; i < n; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "--------\n";
    {
        std::string arr[] = {"sandeep", "amma", "nanna", "anna"};
        int n = sizeof(arr) / sizeof(arr[0]);
        mySpace::sort <std::string> (arr, n);
        for(int i = 0; i < n; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
}