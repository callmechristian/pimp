/* imgconvert module header */
/* Author : Christian Siman */
/* Version : 12−08−2018 */

#ifndef imgconvert_H
#endif

#include <stdlib.h>

extern void convertInverted(char inputBMP[], char outputTXT[], int imgSize, int threshold);
extern void flipVertical(char inputTXT[], int imgSize, char outputTXT[]);
extern void convertToASCII(char inputTXT[], int imgSize, char outputTXT[], int threshold);
extern void fixInverted(char inputTXT[], int imgSize, char outputTXT[]);
extern void flipHorizontal(char inputTXT[], int imgSize, char outputTXT[]);
