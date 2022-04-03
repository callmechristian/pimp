/* anim.h : display module header*/
/* Author : Christian Siman */
/* Version : 12−08−2018 */

#ifndef anim_H
#endif

#include <stdlib.h>

extern void startAnim();
extern void printEnd();
extern void printAnim(char target[]);
extern void fakeLoading(int intervalTime, int loaderTicks, char loaderText[], char addedText[], char finishText[]);
