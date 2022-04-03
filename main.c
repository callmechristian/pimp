#include <stdio.h>
#include <stdlib.h>
#include <windows.h>         //for Sleep(ms); and system("cls");
#include <conio.h>           //for getch();

#include "display.h"
#include "draw.h"
#include "imgconvert.h"
#include "anim.h"
#include "animRes.h"
#include "editor.h"

int main() {

int userInput = 1;                      //the loop boolean
int userValue;                          //input int 1
int userValue2;                         //input int 2
char userString[256];                   //input string 1
char userString2[256];                  //input string 2

while(userInput != 0) {
    //system("cls");
    printMenu(mainMenu);
    scanf("%d", &userInput);
    printf("\n");
    switch(userInput) {
        case 0: //------------------------------------------------------------ Quit
            break;
        case 1: //------------------------------------------------------------ Display Menu
            system("cls");
            while(userInput != 0) {
                printMenu(displayMenu);
                scanf("%d", &userInput);
                switch(userInput) {
                    case 0:
                        system("cls");
                        break;
                    case 1: //------------------------------------------------ Display Shapes Menu
                        system("cls");
                        while(userInput != 0) {
                            printMenu(displayShapesMenu);
                            scanf("%d", &userInput);
                                switch(userInput) {
                                    case 0:
                                        system("cls");
                                        break;
                                    case 1: //---------------------------- Box
                                        printf("\nBox size: ");
                                        scanf("%d", &userValue);
                                        printf("\n\n");
                                        Box(userValue);
                                        printf("\n\n");
                                        getch();
                                        system("cls");
                                        break;
                                    case 2: //---------------------------- Triangle
                                        printf("\nNumber of vertical rows: ");
                                        scanf("%d", &userValue);
                                        printf("\n\n");
                                        Triangle(userValue);
                                        printf("\n\n");
                                        getch();
                                        system("cls");
                                        break;
                                    case 3: //---------------------------- Hollow Box
                                        printf("\nBox size: ");
                                        scanf("%d", &userValue);
                                        printf("\n\n");
                                        HollowBox(userValue);
                                        printf("\n\n");
                                        getch();
                                        system("cls");
                                }
                        } userInput = 1; //reset exit boolean
                        break; //----------------------------------------- end case 1.1
                    case 2://---------------------------------------------------------- display image
                        system("cls");
                        printMenu(fileInputTXT);
                        scanf("%s", userString);
                        printMenu(valueInputImageSize);
                        scanf("%d", &userValue);
                        drawImage(userString, userValue);
                        printf("\n\n                            Press any key to return\n\n");
                        printf("                                        ");
                        getch();
                        system("cls");
                        break;
                    case 3: //-------------------------------------------- ASCII art
                        while(userInput != 0) {
                            printMenu(displayASCIIart);
                            scanf("%d", &userInput);
                                switch(userInput) {
                                    case 0:
                                        system("cls");
                                        break;
                                    case 1: //---------------------------- stick man
                                        system("cls");
                                        initDraw(32, stickman, 0);
                                        Complex(7, stickman, 25);
                                        endDraw();
                                        getch();
                                        system("cls");
                                        break;
                                    case 2: //----------------------------- car
                                        system("cls");
                                        initDraw(32, car, 0);
                                        Complex(17, car, 60);
                                        endDraw();
                                        getch();
                                        system("cls");
                                        break;
                                    case 3: //----------------------------- Hollow Box
                                        system("cls");
                                        printAnim(celticKnot);
                                        getch();
                                        system("cls");
                                        break;
                                    case 4: //------------------------------ car
                                        system("cls");
                                        initDraw(30, frog, 0);
                                        Complex(32, frog, 390);
                                        endDraw();
                                        getch();
                                        system("cls");
                                        break;
                                }
                        } userInput = 1; //reset exit boolean
                        break;

                }
            } userInput = 1;
            break; //-------------------------------------------------------------------- end case 1
        case 2: //----------------------------------------------------------------------- Image Editor
            system("cls");
            printf("Enter image size: ");
            scanf("%d", &userValue);
            mainEditorLoop(userValue);
            break;
        case 3: //----------------------------------------------------------------------- Image Conversion Menu
            system("cls");
            while(userInput != 0) {
                printMenu(imageConvertMenu);
                scanf("%d", &userInput);
                switch(userInput) {
                    case 0:
                        system("cls");
                        break;
                    case 1: //---------------------------------------------- BMP to ASCII
                        system("cls");
                        printMenu(fileInputBMP);
                        scanf("%s", userString2);
                        system("cls");
                        printMenu(fileOutput);
                        scanf("%s", userString);
                        system("cls");
                        printMenu(valueInputImageSize);
                        scanf("%d", &userValue2);
                        system("cls");
                        printMenu(valueInputThreshold);
                        scanf("%d", &userValue);
                        system("cls");
                        convertToASCII(userString2, userValue2, userString, userValue);
                        printf("\n\n                            Press any key to return\n\n");
                        printf("                                        ");
                        getch();
                        system("cls");
                        break;
                    case 2: //------------------------------------------------ BMP to v flip ASCII
                        system("cls");
                        printMenu(fileInputTXT);
                        scanf("%s", userString2);
                        printMenu(fileOutput);
                        scanf("%s", userString);
                        printMenu(valueInputImageSize);
                        scanf("%d", &userValue2);
                        printMenu(valueInputThreshold);
                        scanf("%d", &userValue);
                        convertInverted(userString2, userString, userValue2, userValue);
                        printf("\n\n                            Press any key to return\n\n");
                        printf("                                        ");
                        getch();
                        system("cls");
                        break;
                    case 3: //-------------------------------------------------- BMP to h flip ASCII
                        system("cls");
                        printMenu(fileInputTXT);
                        scanf("%s", userString2);
                        printMenu(fileOutput);
                        scanf("%s", userString);
                        printMenu(valueInputImageSize);
                        scanf("%d", &userValue);
                        printMenu(valueInputThreshold);
                        scanf("%d", &userValue2);
                        convertInverted(userString2, "tmp", userValue, userValue2);
                        flipVertical("tmp", userValue, userString);
                        printf("\n\n                            Press any key to return\n\n");
                        printf("                                        ");
                        getch();
                        system("cls");
                        break;
                    case 4: //--------------------------------------------------- v flip image
                        system("cls");
                        printMenu(fileInputTXT);
                        scanf("%s", userString2);
                        printMenu(fileOutput);
                        scanf("%s", userString);
                        printMenu(valueInputImageSize);
                        scanf("%d", &userValue);
                        flipVertical(userString2, userValue, userString);
                        printf("\n\n                            Press any key to return\n\n");
                        printf("                                        ");
                        getch();
                        system("cls");
                        break;
                    case 5: //---------------------------------------------------- h flip image
                        system("cls");
                        printMenu(fileInputTXT);
                        scanf("%s", userString2);
                        printMenu(fileOutput);
                        scanf("%s", userString);
                        printMenu(valueInputImageSize);
                        scanf("%d", &userValue);
                        flipHorizontal(userString2, userValue, userString);
                        printf("\n\n                            Press any key to return\n\n");
                        printf("                                        ");
                        getch();
                        system("cls");
                        break;
                    case 6: //----------------------------------------------------- display image
                        system("cls");
                        printMenu(fileInputTXT);
                        scanf("%s", userString);
                        printMenu(valueInputImageSize);
                        scanf("%d", &userValue);
                        drawImage(userString, userValue);
                        printf("\n\n                            Press any key to return\n\n");
                        printf("                                        ");
                        getch();
                        system("cls");
                        break;
                }
            } userInput = 1;
            break; //--------------------------------------------------------- end case 3
        case 4: //---------------------------------------------------------------------------- Animation Player
            startAnim();
            system("cls");
            break; //-------------------------------------------------------- end case 4
        case 5: //---------------------------------------------------------------------------- User Manual
            printMenu(userManualSplash);
            scanf("%d", &userInput);
            switch(userInput) {
                case 0:
                    break;
                case 1:
                    printAnim(userManual);
                    printf("\n\n                            Press any key to return\n\n");
                    printf("                                        ");
                    getch();
                    break;
                case 2:
                    system("cls");
                    printAnim(jokeManual);
                    getch();
                    break;
            }
            system("cls");
            break; //-------------------------------------------------------- end case 5
    }
}

printEnd(); //credits

return 0;
}
