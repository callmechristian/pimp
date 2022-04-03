#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "draw.h"

char *ptr = NULL;
char stickman[5][5] = {
        "  Ox",
        "[|]x",
        " | x",
        "/ |xx"
};

char car[4][15] = {
        "   ______    x",
        " /|_||_|`._  x",
        "(   _    _ _)x",
        "=`-(_)--(_)-'xx"
};

char frog[14][31] = {
"         o  o   o  o          x",
"         |\\/ \\^/ \\/|          x",
"         |,-------.|          x",
"       ,-.(|)   (|),-.        x",
"       \\_*._ ' '_.* _/        x",
"        /`-.`--' .-'\\         x",
"   ,--./    `---'    \\,--.    x",
"   \\   |(  )     (  )|   /    x",
"hjw \\  | ||       || |  /     x",
"`97  \\ | /|\\     /|\\ | /      x",
"     /  \\-._     _,-/  \\      x",
"    //| \\\\  `---'  // |\\\\     x",
"   /,-.,-.\\       /,-.,-.\\    x",
"  o   o   o      o   o    o   x"
};

void stickMan() { //explicit of initDraw
    int k = 0;

    ptr = (char*)malloc(5*sizeof(char));

    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            *(ptr + k) = stickman[i][j];
            k++;
        }
    }
    k=0;
}

void initDraw(int sizeOfDisp, char target[sizeOfDisp][sizeOfDisp], int type) {
    int k = 0;

    if(type == 0) { //reuse memory or allocate new
        ptr = (char*)malloc(sizeOfDisp*sizeOfDisp);
    } else {
        realloc(ptr, sizeOfDisp*sizeOfDisp);
    }

    for(int i=0; i<sizeOfDisp; i++) { //add image data to memory
        for(int j=0; j<sizeOfDisp; j++) {
            *(ptr + k) = target[i][j];
            k++;
        }
    }
    k=0;
}

void endDraw() {
    free(ptr);
}
