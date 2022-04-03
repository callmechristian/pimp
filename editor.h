/* editor module for editing obviously */
/* Author : Christian Siman */
/* Version : 12−08−2018 */

#ifndef editor_H
#endif

#include <stdlib.h>

extern void mainEditorLoop(int boxSize);
extern void loadDrawing(char saveName[], int boxSize, int imageMatrix[boxSize][boxSize]);
extern void saveDrawing(int imageSize, int imageMatrix[imageSize][imageSize], char saveName[]);
extern void loadImageFile(char imageFile[], int imageSize, int imageMatrix[imageSize][imageSize]);
