/* display.c - displays stuff */

#include <string.h>
#include <stdio.h>

#include "display.h"
#include "anim.h"

void Box(int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            printf("#");
        }
        printf("\n");
    }
}

void Triangle(int rows) {
    int k=0;

    for(int i=1; i<=rows; ++i, k=0) {
        for(int space=1; space<=rows-i; ++space) {
            printf("  ");
        }

        while(k != 2*i-1) {
            printf("# ");
            ++k;
        }

        printf("\n");
    }
}

void HollowBox(int boxSize) {
    for(int i=0; i<boxSize; i++) {
        for(int j=0; j<boxSize; j++) {
                if(i==0 || j==0 || j==boxSize-1 || i==boxSize-1) printf("#");
                    else printf(" ");
        }
        printf("\n");
    }
}

void Complex(int boxSize, char *target, int dispImgSize) {
    int k = 0;

    for(int i=0; i<boxSize; i++) {
        for(int j=0; j<boxSize; j++) {
                if(i==0 || j==0 || j==boxSize-1 || i==boxSize-1) printf("#");
                    else {
                        if(*(target+k) != 'x') {
                            printf("%c", *(target+k));
                            if(k<dispImgSize-1) k++;
                        } else {

                            if(*(target+k) == 'x' && *(target+k+1) == 'x') {
                                printf(" #\n");
                                for(int m=0; m<boxSize; m++) printf("#");
                                return;
                            }

                            do{
                                if(j!=boxSize-1){
                                    printf(" ");
                                } else {
                                    printf("#");
                                }

                                j++;
                            } while(boxSize-j>0);
                            if(k<dispImgSize-1) k++;
                        }
                    }
        }
        printf("\n");
    }
}

void drawImage(char a[], int imgSize) {

    printf("\n\n");                               //to avoid window conflicts

    int outp;

    FILE *ptr_txt_nrm;
    ptr_txt_nrm = fopen(a, "r");

    for (int i = 0; i<imgSize; i++) {
        for(int j = 0; j<imgSize; j++) {
            outp=fgetc(ptr_txt_nrm);
            printf("%c", outp);
            if(j==imgSize-1) printf("\n");      //next row depending on image size
        }
    }
}

void printMenu(char menuName[]) {
    printAnim(menuName);
    printf("\n\n\n");
    printf("                                     Choice\n\n");
    printf("                                        ");
}
