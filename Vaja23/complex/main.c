#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#include "knjiznicaBMP_cb_allplatforms/bitmap.h"

float complex Cbrt(float complex z0){
    float complex zn,zm=z0;
    while(cabs(zn-zm)>0.00001){
        zn=zm;
        zm=zn-(zn-1/(zn*zn))/3;

    }
    return zm;
}

float r1=1;
float complex r2=-0.5 + sqrt(3)/2 * I;
float complex r3=-0.5 - sqrt(3)/2 * I;
#define SIZE 10000
unsigned char picture[SIZE][SIZE];

int main() {
    float complex z;
    int temp=0;
    for(int i=-SIZE/2; i<SIZE/2; i++){
        for(int j=-SIZE/2; j<SIZE/2; j++){
            z=Cbrt(i + j*I);
            //printf("Z = %.2f %+.2fi\n", creal(z), cimag(z));
            if(z==r1){
                picture[i+SIZE/2][j+SIZE/2]=80;
            }
            else if(z==r2){
                picture[i+SIZE/2][j+SIZE/2]=160;

            }
            else if(z==r3){
                picture[i+SIZE/2][j+SIZE/2]=240;
            }
            else{
                picture[i+SIZE/2][j+SIZE/2]=0;
            }
        }
        temp=i+SIZE/2;
        printf("%d\n", temp);
    }
    shraniBMP(picture, SIZE, SIZE, "slikca.bmp");
    return 0;
}
