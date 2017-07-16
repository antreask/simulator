/*
#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <stdio.h>      // printf, NULL
#include <stdlib.h>     // strtoull
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;


template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}



int main()
{

    ifstream myfile ("total.txt");
    ofstream bench_names("bench_names.txt");
    ofstream bench_cycles("bench_cycles.txt");
    int i=0;
    if (myfile.is_open())
    {
        string line;

        while (getline (myfile,line) )
        {
            vector<std::string> x = split(line, ' ');
            cout <<x[0] << " "<< x[3] << endl;
            bench_names << x[0]<<"\n";
            bench_cycles << x[3]<<"\n";
        }
        myfile.close();
    }
    else
        cout << "No input file\n";

    bench_names.close();
    bench_cycles.close();



}*/
