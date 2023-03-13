#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>
using namespace std;

double square(double num, double resolution);
double cubicroot(double num, double resolution);
unsigned char picture[1000][1000];
float r1 = 1;
float complex r2 = -0.5 + sqrt(3) / 2 * I;
float complex r2 = -0.5 + sqrt(3) / 2 * I;


int main() {
	double resolution = 0.00001;
	float complex z;
	for (int i = -500; i <= 499; i++) {
		for (int j = -500; i <= 499; j++) {
			z = cubicroot(i + j * I);
			if (z == r1) {
				picture[i + SIZE / 2][j + SIZE / 2] = 80;
			}
			else if (z == r2) {
				picture[i + SIZE / 2][j + SIZE / 2] = 160;
			}
			else if (z == r3) {
				picture[i + SIZE / 2][j + SIZE / 2] = 240;
			}
			else {
				picture[i + SIZE / 2][j + SIZE / 2] = 0;

		}
	}
	for (double i = 1; i <= 50; i++) {
		printf("%.5f\n", square(i, resolution));
		
	}
	return 0;
}

double square(double  num, double resolution) {
	double root = 1;
	double ort = 0;
	while ((root - resolution) > ort) {
		ort = root;
		root = ((num / root) + root) / 2;
	}
	return root;
}

double complex cubicroot(double complex num, double resolution) {
	double complex root = num;
	double complex ort = 0;
	while (root - resolution > ort) {
		ort = root;
		//root = (num - ((num * num * num - 1) / (3 * num * num)));
		root = ort - (ort - 1/(ort*ort))/3
	}
	return root;
}

//void write(double array[][1000], double solution)
