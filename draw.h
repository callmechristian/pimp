/* draw.h : draw module header*/
/* Author : Christian Siman */
/* Version : 12−08−2018 */

#ifndef display_H
#endif

#include <stdlib.h>

extern void stickMan();
extern char *ptr;
extern char stickman[5][5];
extern char car[4][15];
extern char frog[14][31];
extern void endDraw();
extern void initDraw(int sizeOfDisp, char target[sizeOfDisp][sizeOfDisp], int type);
