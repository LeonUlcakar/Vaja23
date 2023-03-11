#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

double square(int num, double resolution);
double cubicroot(int num, double resolution);

int main() {
	double resolution = 0.00001;
	//double array[1000][1000];
	for (int i = -500; i < 499; i++) {
		cout << cubicroot(i, resolution) << endl;
		
	}
	return 0;
}

double square(int num, double resolution) {
	double root = 1;
	double ort = 0;
	while ((root - resolution) > ort) {
		ort = root;
		root = ((num / root) + root) / 2;
	}
	return root;
}

double cubicroot(int num, double resolution) {
	double root = 1;
	double ort = 0;
	while (root - resolution > ort) {
		ort = root;
		root = (num - ((num * num * num - 1) / (3 * num * num)));
	}
	return root;
}

//void write(double array[][1000], double solution)
