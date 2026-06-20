#include "PmergeMe.hpp"

int main(int ac, char **av) 
{
	if (ac < 1)
		return 1;
	PmergeMe merge(av + 1);




   return 0;
}



// int main() {
//     int arr[] = { 12, 11, 13, 5, 6, 7 };
//     int size = sizeof(arr) / sizeof(arr[0]);

//     cout << "Given array is \n";
//     printArray(arr, size);

//     mergeSort(arr, 0, size - 1);

//     cout << "\nSorted array is \n";
//     printArray(arr, size);
//     return 0;
// }