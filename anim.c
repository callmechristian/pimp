#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>

#include "anim.h"
#include "display.h"
#include "animRes.h"

void startAnim() {
    int stop = 0;
    int frameCounter = 0;

    while(stop != 10) {
        system("cls");
        switch(frameCounter){
            case 0:
                printAnim(f1);
                break;
            case 1:
                printAnim(f2);
                break;
            case 2:
                printAnim(f3);
                break;
            case 3:
                printAnim(f1);
                frameCounter = 0;
                break;
        }
        stop++;
        frameCounter++;
        Sleep(500);
    }
}

void printEnd() { //basically the same as printAnim
    int _counter = 0;

    for(int i=0;i<80;i++) {
        for(int j=0; j<80; j++) {
            if(endSequence[_counter] != 'x') printf("%c", endSequence[_counter]);
            _counter++;
            if(endSequence[_counter] == 'x') printf("\n");
            if(endSequence[_counter] == 'x' && endSequence[_counter+1] == 'x') return;
        }
    }
}

void printAnim(char target[]) {
    int _counter = 0;

    system("cls");

    for(int i=0;i<80;i++) {
        for(int j=0; j<80; j++) {
            if(target[_counter] != 'x') printf("%c", target[_counter]);
            _counter++;
            if(target[_counter] == 'x') printf("\n");
            if(target[_counter] == 'x' && target[_counter+1] == 'x') return;
        }
    }
}

void fakeLoading(int intervalTime, int loaderTicks, char loaderText[], char addedText[], char finishText[]) {
    printf("%s", loaderText);
    Sleep(intervalTime);
    for(int i = 0; i<loaderTicks; i++) {
        printf("%s", addedText);
        Sleep(intervalTime);
    }
    printf(" %s", finishText);
}

