#include <iostream>
#include <fstream>

void stooge_sort(int*, int, int);

int main(int argc, char* argv[]) {
	int n = 0;
	std::ifstream myfile;
	myfile.open(argv[1]);
	myfile >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		myfile >> arr[i];
	}
	stooge_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
			std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	myfile.close();
	return 0;
}

void stooge_sort(int arr[], int first, int last) {
	int temp = 0;
	if (first >= last) {
		return;
	}

	if (arr[first] > arr[last]) {
		temp = arr[first];
		arr[first] = arr[last];
		arr[last] = temp;
	}

	if (last - first + 1 >= 3) {
		int third = (last - first + 1) / 3;

		stooge_sort(arr, first, last - third);
		stooge_sort(arr, first + third, last);
		stooge_sort(arr, first, last - third);
	}
}