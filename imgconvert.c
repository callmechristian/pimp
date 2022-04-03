/* imgconvert.c - converts bmp to terminal output */

#include <string.h>
#include <stdio.h>

#include "imgconvert.h"
#include "anim.h"

void convertInverted(char inputBMP[], char outputTXT[], int imgSize, int threshold) {
    FILE *ptr_bmp_in;
    FILE *ptr_txt_out;
    int c;
    int red;
    int green;
    int blue;
    int px;
    int pxCounter;                                 //counting pixels since 1999

    ptr_bmp_in=fopen(inputBMP,"rb");               //open target file
    ptr_txt_out=fopen(outputTXT, "w");             //create output file (will be inverted)

    if(!ptr_bmp_in) {                              //unable to open input image
        printf("Unable to open file\n");
        return 1;
    }
    if(!ptr_txt_out) {                             //unable to create output file
        printf("Unable to create file\n");
        return 2;
    }

    int i = 0;

    while(i < 138) {
        c = fgetc(ptr_bmp_in);                     //skip first 138 values because of BMP formatting
        i++;
    }

    pxCounter = 0;                                 //initialize a pixel counter
    while((c=fgetc(ptr_bmp_in)) != EOF){           //process data to end of file
        switch(pxCounter){                         //check if in the same pixel
                case 0:                            //if red value of pixel RGB
                    red = c;
                    pxCounter++;
                    break;
                case 1:                            //if green value of pixel RGB
                    green = c;
                    pxCounter++;
                    break;
                case 2:                            //if blue value of pixel RGB
                    blue = c;
                    pxCounter = 0;                 //blue marks end of pixel RGB
                    px = red + green + blue;       //average RGB = brightness
                    if(px < threshold) {           //compare RGB to threshold
                        fputc('0',ptr_txt_out);    //area that is lighter than threshold
                    } else {
                        fputc('1',ptr_txt_out);    //area that is darker than threshold
                    };
                    break;
        };
    };

    fclose(ptr_bmp_in);                            //close files and end conversion
    fclose(ptr_txt_out);

    fakeLoading(500, 5, "Writing inverted image file", ".", " Done!");
    return 0;
}

void flipVertical(char inputTXT[], int imgSize, char outputTXT[]) {

    FILE *ptr_txt_out;
    FILE *ptr_txt_nrm;

    printf("\nStarting vertical flip...\n");

    ptr_txt_out=fopen(inputTXT, "r");                //open converted data file
    ptr_txt_nrm=fopen(outputTXT, "w");                  //open output data file to flip image

    int ctr = 0;
    int outp;
    int invert[4096];

    for(int i = 0; i<imgSize; i++) {                      //stores 0/1 in an array
        for(int j = 0; j<imgSize; j++) {
            invert[ctr] = fgetc(ptr_txt_out);
            ctr++;
        }
    }

    ctr--; //------------------------------------------------fix ctr increase over max file size by 1

    for (int i = 0; i<imgSize; i++) {
        for(int j = 0; j<imgSize; j++) {
            outp = invert[ctr];
            fputc(outp, ptr_txt_nrm);              //output is flipped horizontally
            //printf("%d", outp);                  //for debug purposes
            ctr--;
        }
    }

    fclose(ptr_txt_out);
    fclose(ptr_txt_nrm);

    fakeLoading(500, 5, "Writing data", ".", " Done!");

    return 0;
}

void convertToASCII(char inputBMP[], int imgSize, char outputTXT[], int threshold) {
    convertInverted(inputBMP, "tmp", imgSize, threshold);
    flipVertical("tmp", imgSize, "tmp2");
    flipHorizontal("tmp2", imgSize, outputTXT);
    return 0;
}

void flipHorizontal(char inputTXT[], int imgSize, char outputTXT[]) {
    FILE *ptr_txt_out;
    FILE *ptr_txt_nrm;

    char inverterArray[imgSize];
    int arrayCounter = 0;

    printf("\nHorizontally flipping image...\n");

    ptr_txt_out=fopen(inputTXT, "r");             //open converted data file
    ptr_txt_nrm=fopen(outputTXT, "w");            //open output data file to flip image

    for (int i = 0; i<imgSize; i++) {
        while(arrayCounter<imgSize) {
            inverterArray[arrayCounter] = fgetc(ptr_txt_out); //saves all pixels
            arrayCounter++;
        }
        while(arrayCounter > 0) {
            fputc(inverterArray[arrayCounter], ptr_txt_nrm); //rewrites the file from from end to front from the saved pixels
            arrayCounter--;
        }
    }

    fclose(ptr_txt_out);
    fclose(ptr_txt_nrm);
    fakeLoading(500, 5, "Writing flipped file", ".", " Done!");
    return 0;
}

void convertToBMP(char inputTXT[], char outputBMP[], int imgSize) { //doesn't work
    FILE *ptr_txt_in;
    FILE *ptr_bmp_out;
    int c = 0;
    int pxCounter = 0;                            //counting pixels since 1999
    int i = 0;

    ptr_txt_in=fopen(inputTXT,"r");               //open target file
    ptr_bmp_out=fopen(outputBMP, "wb");             //create output file (will be inverted)

    if(!ptr_txt_in) {                              //unable to open input image
        printf("Unable to open file\n");
        return 1;
    }
    if(!ptr_bmp_out) {                             //unable to create output file
        printf("Unable to create file\n");
        return 2;
    }

    while(i < 138) {
        fputc(00000000, ptr_bmp_out);                     //138 blank bmp formatting?
        i++;
    }

    while(pxCounter < imgSize*imgSize) {
        c = getc(ptr_txt_in);
        if(c == '0') {
            for(int j=0; j<3; j++){ //for white pixel
                fputc(00000000, ptr_bmp_out); //output 0 as binary
            }
        } else {
            for(int j=0; j<3; j++){ //for black pixel
                fputc(11111111, ptr_bmp_out); //output 255 as binary
            }
        }
        pxCounter++;
    };

    fclose(ptr_bmp_out);                            //close files and end conversion
    fclose(ptr_txt_in);

    fakeLoading(500, 5, "Writing image", ".", "Done!");

    return 0;
}
