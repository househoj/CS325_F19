#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void stooge_sort(int*, int, int);

int main(){
    const int n = 1000002;
    int arr[n];
    float total, average;
    std::ofstream outfile;
    outfile.open("times.txt");

    for(int i = 500; i <= 1500; i = i+100){
        total = 0;
        average = 0;
        std::cout << "i: " << i << std::endl;
        for(int j = 1; j <= 3; j++){
            srand(time(NULL));
            for(int k = 0; k < i; k++){
                arr[k] = rand () % 10000;
            }
            clock_t t1, t2;
            t1 = clock();
            stooge_sort(arr, 0, i);

            t2 = clock();
            float diff ((float) t2 - (float) t1);
            float seconds = diff / CLOCKS_PER_SEC;
            total = total + seconds;
            std::cout << seconds << "s" << std::endl;
        }
        average = total / 3;
        std::cout << "Average: " << average << std::endl;
        outfile << average << " ";
    }
    outfile.close();
    std::cout << std::endl;
    return 0;
}

void stooge_sort(int arr[], int first, int last){
    int temp = 0;
    if(first >= last){
        return;
    }
    if(arr[first] > arr[last]){
        temp = arr[first];
        arr[first] = arr[last];
        arr[last] = temp;
    }
    if(last - first + 1 >= 3){
        int third = (last - first + 1) / 3;
        stooge_sort(arr, first, last - third);
        stooge_sort(arr, first + third, last);
        stooge_sort(arr, first, last - third);
    }
}
