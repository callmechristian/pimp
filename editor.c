#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "editor.h"
#include "anim.h"
#include "animRes.h"


void mainEditorLoop(int boxSize) {

    int imageMatrix[boxSize][boxSize];
    int cursorSize = 1;
    int cursorX = 0;
    int cursorY = 0;

    int _draw = 0;
    int _erase = 0;
    int _loop = 1;

    for(int i=0; i<boxSize; i++) {
        for(int j=0; j<boxSize; j++) {
            imageMatrix[i][j] = 0;                   //make sure image is blank
        }
    }


    while(_loop) {
        system("cls");

        for(int i=0; i<boxSize; i++) {
            for(int j=0; j<boxSize; j++) {
                if(cursorX == j && cursorY == i) {
                    if(!_draw){
                        if(imageMatrix[i][j] != 1) imageMatrix[i][j] = 0;
                        _draw = 0;
                    } else {
                        if(cursorSize == 1) {
                                imageMatrix[i][j] = 1;
                        } else {
                                for(int k=-cursorSize+1; k<cursorSize; k++) {
                                    for(int m=-cursorSize+1; m<cursorSize; m++) {
                                        imageMatrix[i+k][j+m] = 1;
                                    }
                                }
                        }
                        _draw = 0;
                    }
                }
            }
        }

        for(int i=0; i<boxSize; i++) {
            for(int j=0; j<boxSize; j++) {
                if(cursorX == j && cursorY == i) {
                    if(_erase) {
                        if(cursorSize == 1) {
                                imageMatrix[i][j] = 0;
                        } else {
                                for(int k=-cursorSize+1; k<cursorSize; k++) {
                                    for(int m=-cursorSize+1; m<cursorSize; m++) {
                                        imageMatrix[i+k][j+m] = 0;
                                    }
                                }
                        }
                            _erase = 0;
                    }
                }
            }
        }

        for(int i=0; i<boxSize; i++) {
            for(int j=0; j<boxSize; j++) {
                if(!(cursorX == j && cursorY == i)) {
                    switch(imageMatrix[i][j]) {
                            case 0:
                                printf(".");
                                break;
                            case 1:
                                printf("x");
                                break;
                            default:
                                printf("?");
                                break;
                    }
                } else {
                    printf("#");
                }
            }
            printf("\n");
        }

        char userString[256];
        int userValue;

        switch(getchar()) { //key bindings
            case 'w':
                if(cursorY > 0) cursorY--;
                break;
            case 's':
                if(cursorY < boxSize-1) cursorY++;
                break;
            case 'd':
                if(cursorX < boxSize-1)cursorX++;
                break;
            case 'a':
                if(cursorX > 0)cursorX--;
                break;
            case ' ':
                _draw = 1;
                break;
            case 'x':
                _erase = 1;
                break;
            case 'c':
                for(int i=0; i<boxSize; i++) {
                    for(int j=0; j<boxSize; j++) {
                        imageMatrix[i][j] = 0;                   //clear matrix
                    }
                }
                break;
            case 'b':
                _loop = 0;
                system("cls");
                break;
            case '1':
                cursorSize = 1;
                system("cls");
                break;
            case '2':
                cursorSize = 2;
                system("cls");
                break;
            case '3':
                cursorSize = 3;
                system("cls");
                break;
            case '?':
                system("cls");
                printAnim(editorManual);
                printf("\n\n                            Press any key to return\n\n");
                printf("                                        ");
                getch();
                break;
            case 'i': //open converted image
                system("cls");
                printAnim(fileInputTXT);
                printf("\n\n                                        ");
                scanf("%s", userString);
                system("cls");
                printAnim(valueInputImageSize);
                scanf("%d", &userValue);
                loadImageFile(userString, boxSize, imageMatrix);
                break;
            case 'o': //open editor save file
                system("cls");
                printAnim(fileInputTXT);
                printf("\n\n                                        ");
                scanf("%s", userString);
                system("cls");
                printAnim(valueInputImageSize);
                scanf("%d", &userValue);
                loadDrawing(userString, userValue, imageMatrix);
                break;
            case 'p': // save editor project
                system("cls");
                printAnim(fileOutput);
                printf("\n\n                                        ");
                scanf("%s", userString);
                saveDrawing(boxSize, imageMatrix, userString);
                break;
        }

        //cursorLocation[cursorY][cursorX] = 1; //set new location
        //}
    }
}

void saveDrawing(int imageSize, int imageMatrix[imageSize][imageSize], char saveName[]) {

    FILE *ptr_save_file;

    ptr_save_file = fopen(saveName, "w");

    for(int i=0; i<imageSize; i++) {
        for(int j=0; j<imageSize; j++) {
                switch(imageMatrix[i][j]) {
                        case 0:
                            fputc('0', ptr_save_file);
                            break;
                        case 1:
                            fputc('1', ptr_save_file);
                            break;
                }
        }
        printf("\n");
    }

    fclose(ptr_save_file);

}

void loadDrawing(char saveName[], int boxSize, int imageMatrix[boxSize][boxSize]) {
    FILE *ptr_save_file;

    ptr_save_file = fopen(saveName, "r");
    char c;

    for(int i=0; i<boxSize; i++) {
        for(int j=0; j<boxSize; j++) {
            c=fgetc(ptr_save_file);
            switch(c) {
                case '0':
                    imageMatrix[i][j] = 0;
                    break;
                case '1':
                    imageMatrix[i][j] = 1;
                    break;
            }
        }
    }
    fclose(ptr_save_file);
}

void loadImageFile(char imageFile[], int imageSize, int imageMatrix[imageSize][imageSize]) {
    if(imageSize != 64) {
        printf("Image size mismatch. Please reload the editor with a 64x64 layout.");
        system("pause");
        return;
    }

    FILE *ptr_image_file;

    ptr_image_file = fopen(imageFile, "r");
    char c;

    for(int i=0; i<imageSize; i++) {
        for(int j=0; j<imageSize; j++) {
            c=fgetc(ptr_image_file);
            switch(c) {
                case '0':
                    imageMatrix[i][j] = 0;
                    break;
                case '1':
                    imageMatrix[i][j] = 1;
                    break;
            }
        }
    }
    fclose(ptr_image_file);
}
