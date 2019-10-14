#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]){
    int n, temp, curr;
    int* i_vals;
    int* m_vals;
    int* suba;
    int* subb;
    std::ifstream myfile;
    myfile.open(argv[1]);
/////////////////////////////////    
    myfile >> n;
    i_vals = new int[n];
    //std::cout << n << " integers" << std::endl;
    for(int i = 0; i < n; i++){
        myfile >> i_vals[i];
        //std::cout << "i_vals[" << i << "] = " << i_vals[i] << std::endl;
    }
    for(int i = 1; i < n; i++){
        temp = i_vals[i];
        curr = i - 1;
        while(curr >= 0 && i_vals[curr] > temp){
            i_vals[curr + 1] = i_vals[curr];
            curr = curr - 1;
        }
        i_vals[curr + 1] = temp;
    }
    //std::cout << "After insertion sort..." << std::endl;
    for(int i = 0; i < n; i++){
        //std::cout << "i_vals[" << i << "] = " << i_vals[i] << std::endl;
    }
///////////////////////////////// 
    myfile >> n;
    m_vals = new int[n];
    int sublength_a = floor(n/2);
    int sublength_b = n - sublength_a;
    std::cout << n << "; " << sublength_a << "; " << sublength_b << std::endl;
    std::cout << n << " integers" << std::endl;
    for(int i = 0; i < n; i++){
        myfile >> m_vals[i];
        std::cout << "m_vals[" << i << "] = " << m_vals[i] << std::endl;
    }
    suba = new int[sublength_a];
    subb = new int[sublength_b];
    for(int i = 0; i < sublength_a; i++){
        suba[i] = m_vals[i];
    }
    for(int i = 0; i < sublength_b; i++){
        subb[i] = m_vals[i + sublength_a];
    }

    /*for(int i = 0; i < sublength_a; i++){
        std::cout << "suba[" << i << "] = " << suba[i] << std::endl;
    }
    for(int i = 0; i < sublength_b; i++){
        std::cout << "subb[" << i << "] = " << subb[i] << std::endl;
    }*/
/////////////////////////////////    
    myfile.close();
    delete[] i_vals;
    delete[] m_vals;
    delete[] suba;
    delete[] subb;
    return 0;
}