#include <string.h>
#include <stdlib.h>

#include "animRes.h"


char f1[256] = "\
 0 x\
[|]x\
/|xx";

char f2[256] = "\
 0 x\
/|]x\
-|xx";

char f3[256] = "\
 0 x\
[|-x\
 |-xx";

char endSequence[8096] = "\
################################################################################x\
#______________________________________________________________________________#x\
#______________________________________________________________________________#x\
#_____________8b____d8____db____8888b.__888888_____88''Yb Yb__dP_______________#x\
#_____________88b__d88___dPYb____8I__Yb_88.._______88__dP__YbdP________________#x\
#_____________88YbdP88__dP__Yb___8I__dY_88^^_______88''Yb___8P_________________#x\
#_____________88_YY_88_dP''''Yb 8888Y'__888888_____88oodP__dP__________________#x\
#______________________________________________________________________________#x\
#                                                                              #x\
#        ____   ___                                                            #x\
#       6MMMMb/ `MM              68b                 68b                       #x\
#      8P    YM  MM              Y89           /     Y89                       #x\
#     6M      Y  MM  __  ___  __ ___   ____   /M     ___    ___   ___  __      #x\
#     MM         MM 6MMb `MM 6MM `MM  6MMMMb /MMMMM  `MM  6MMMMb  `MM 6MMb     #x\
#     MM         MMM9 `Mb MM69 '  MM MM'    ` MM      MM 8M'  `Mb  MMM9 `Mb    #x\
#     MM         MM'   MM MM'     MM YM.      MM      MM     ,oMM  MM'   MM    #x\
#     MM         MM    MM MM      MM  YMMMMb  MM      MM ,6MM9'MM  MM    MM    #x\
#     YM      6  MM    MM MM      MM      `Mb MM      MM MM'   MM  MM    MM    #x\
#      8b    d9  MM    MM MM      MM L    ,MM YM.  ,  MM MM.  ,MM  MM    MM    #x\
#       YMMMM9  _MM_  _MM_MM_    _MM_MYMMMM9   YMMM9 _MM_`YMMM9'Yb_MM_  _MM_   #x\
#                    ____                                                      #x\
#                   6MMMMb 68b                                                 #x\
#                  6M'    `Y89                                                 #x\
#                  MM      ___ ___  __    __      ___   ___  __                #x\
#                  YM.     `MM `MM 6MMb  6MMb   6MMMMb  `MM 6MMb               #x\
#                   YMMMMb  MM  MM69 `MM69 `Mb 8M'  `Mb  MMM9 `Mb              #x\
#                       `Mb MM  MM'   MM'   MM     ,oMM  MM'   MM              #x\
#                        MM MM  MM    MM    MM ,6MM9'MM  MM    MM              #x\
#                        MM MM  MM    MM    MM MM'   MM  MM    MM              #x\
#                  L    ,M9 MM  MM    MM    MM MM.  ,MM  MM    MM              #x\
#                  MYMMMM9 _MM__MM_  _MM_  _MM_`YMMM9'Yb_MM_  _MM_             #x\
#                                                                              #x\
#                                                                              #x\
#                                                              ver 1.02        #x\
#                                                                              #x\
################################################################################xx";

char mainMenu[4096] = "\
################################################################################x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#                  ||                                                      #|#x\
#|#     ... ...     ...     .. .. ..     ... ...                             #|#x\
#|#      ||'  ||     ||      || || ||     ||'  ||                            #|#x\
#|#      ||   ||     ||      || || ||     ||   ||                Main Menu   #|#x\
#|#      ||    |     ||      || || ||     ||    |                            #|#x\
#|#      ||...' #   .||. #  .|| || ||. #  ||...' #                           #|#x\
#|#      ||                               ||                                 #|#x\
#|#     ''''                             ''''    ver 1.02                    #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#  Select a number and press enter to move through the menu                #|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#   1. Display                                                             #|#x\
#|#                                                                          #|#x\
#|#   2. Image Editor                                                        #|#x\
#|#                                                                          #|#x\
#|#   3. Image Conversion                                                    #|#x\
#|#                                                                          #|#x\
#|#   4. Animation Player                                                    #|#x\
#|#                                                                          #|#x\
#|#   5. User Manual                                                         #|#x\
#|#                                                                          #|#x\
#|#   0. Quit                                                                #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
################################################################################xx";

char celticKnot[4096] = ""
"  .--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--.  x"
" / .. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\ x"
" \\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/ / x"
"  \\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /  x"
"  / /\\/ /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /\\/ /\\  x"
" / /\\ \\/`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'\\ \\/\\ \\ x"
" \\ \\/\\ \\                                                                /\\ \\/ / x"
"  \\/ /\\ \\                                                              / /\\/ /  x"
"  / /\\/ /                                                              \\ \\/ /\\  x"
" / /\\ \\/                                                                \\ \\/\\ \\ x"
" \\ \\/\\ \\                                                                /\\ \\/ / x"
"  \\/ /\\ \\                                                              / /\\/ /  x"
"  / /\\/ /                                                              \\ \\/ /\\  x"
" / /\\ \\/                                                                \\ \\/\\ \\ x"
" \\ \\/\\ \\.--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--./\\ \\/ / x"
"  \\/ /\\/ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ /\\/ /  x"
"  / /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\  x"
" / /\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\ x"
" \\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `' / x"
"  `--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'  xx";

char displayMenu[4096] = "\
################################################################################x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#                  ||                                                      #|#x\
#|#     ... ...     ...     .. .. ..     ... ...                             #|#x\
#|#      ||'  ||     ||      || || ||     ||'  ||                            #|#x\
#|#      ||   ||     ||      || || ||     ||   ||           Display Menu     #|#x\
#|#      ||    |     ||      || || ||     ||    |                            #|#x\
#|#      ||...' #   .||. #  .|| || ||. #  ||...' #                           #|#x\
#|#      ||                               ||                                 #|#x\
#|#     ''''                             ''''    ver 1.02                    #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#  Select a number and press enter to move through the menu                #|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#   1. Shapes                                                              #|#x\
#|#                                                                          #|#x\
#|#   2. Images                                                              #|#x\
#|#                                                                          #|#x\
#|#   3. ASCII Art                                                           #|#x\
#|#                                                                          #|#x\
#|#   0. Quit                                                                #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
################################################################################xx";

char displayShapesMenu[4096] = "\
################################################################################x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#                  ||                                                      #|#x\
#|#     ... ...     ...     .. .. ..     ... ...                             #|#x\
#|#      ||'  ||     ||      || || ||     ||'  ||                            #|#x\
#|#      ||   ||     ||      || || ||     ||   ||           Display Shapes   #|#x\
#|#      ||    |     ||      || || ||     ||    |               Menu         #|#x\
#|#      ||...' #   .||. #  .|| || ||. #  ||...' #                           #|#x\
#|#      ||                               ||                                 #|#x\
#|#     ''''                             ''''    ver 1.02                    #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#  Select a number and press enter to move through the menu                #|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#   1. Square                                                              #|#x\
#|#                                                                          #|#x\
#|#   2. Triangle                                                            #|#x\
#|#                                                                          #|#x\
#|#   3. Hollow Square                                                       #|#x\
#|#                                                                          #|#x\
#|#   0. Quit                                                                #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
################################################################################xx";

char displayASCIIart[4096] = "\
################################################################################x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#                  ||                                                      #|#x\
#|#     ... ...     ...     .. .. ..     ... ...                             #|#x\
#|#      ||'  ||     ||      || || ||     ||'  ||                            #|#x\
#|#      ||   ||     ||      || || ||     ||   ||           Display ASCII    #|#x\
#|#      ||    |     ||      || || ||     ||    |             Art Menu       #|#x\
#|#      ||...' #   .||. #  .|| || ||. #  ||...' #                           #|#x\
#|#      ||                               ||                                 #|#x\
#|#     ''''                             ''''    ver 1.02                    #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#  Select a number and press enter to move through the menu                #|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#   1. Stick figure                                                        #|#x\
#|#                                                                          #|#x\
#|#   2. Car                                                                 #|#x\
#|#                                                                          #|#x\
#|#   3. Celtic knot frame                                                   #|#x\
#|#                                                                          #|#x\
#|#   4. Frog by hjw '97                                                     #|#x\
#|#                                                                          #|#x\
#|#   0. Quit                                                                #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
################################################################################xx";

char imageConvertMenu[4096] = "\
################################################################################x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#                  ||                                                      #|#x\
#|#     ... ...     ...     .. .. ..     ... ...                             #|#x\
#|#      ||'  ||     ||      || || ||     ||'  ||                            #|#x\
#|#      ||   ||     ||      || || ||     ||   ||         Image Conversion   #|#x\
#|#      ||    |     ||      || || ||     ||    |               Menu         #|#x\
#|#      ||...' #   .||. #  .|| || ||. #  ||...' #                           #|#x\
#|#      ||                               ||                                 #|#x\
#|#     ''''                             ''''    ver 1.02                    #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#  Select a number and press enter to move through the menu                #|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#   1. Convert BMP to ASCII                                                #|#x\
#|#                                                                          #|#x\
#|#   2. Convert BMP to Vertically Flipped ASCII                             #|#x\
#|#                                                                          #|#x\
#|#   3. Convert BMP to Horizontally Flipped ASCII                           #|#x\
#|#                                                                          #|#x\
#|#   4. Vertically Flip ASCII Image                                         #|#x\
#|#                                                                          #|#x\
#|#   5. Horizontally Flip ASCII Image                                       #|#x\
#|#                                                                          #|#x\
#|#   6. Display Images                                                      #|#x\
#|#                                                                          #|#x\
#|#   0. Quit                                                                #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
################################################################################xx";

char animationPlayerMenu[4096] = "\
################################################################################x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#                  ||                                                      #|#x\
#|#     ... ...     ...     .. .. ..     ... ...                             #|#x\
#|#      ||'  ||     ||      || || ||     ||'  ||                            #|#x\
#|#      ||   ||     ||      || || ||     ||   ||         Animation Player   #|#x\
#|#      ||    |     ||      || || ||     ||    |               Menu         #|#x\
#|#      ||...' #   .||. #  .|| || ||. #  ||...' #                           #|#x\
#|#      ||                               ||                                 #|#x\
#|#     ''''                             ''''    ver 1.02                    #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#  Select a number and press enter to move through the menu                #|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#   1. Play Animation                                                      #|#x\
#|#                                                                          #|#x\
#|#   2. Edit Animation                                                      #|#x\
#|#                                                                          #|#x\
#|#   0. Quit                                                                #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
################################################################################xx";

char userManualSplash[4096] = "\
################################################################################x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#                  ||                                                      #|#x\
#|#     ... ...     ...     .. .. ..     ... ...                             #|#x\
#|#      ||'  ||     ||      || || ||     ||'  ||                            #|#x\
#|#      ||   ||     ||      || || ||     ||   ||            User Manual     #|#x\
#|#      ||    |     ||      || || ||     ||    |                            #|#x\
#|#      ||...' #   .||. #  .|| || ||. #  ||...' #                           #|#x\
#|#      ||                               ||                                 #|#x\
#|#     ''''                             ''''    ver 1.02                    #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#  First time using P.I.M.P. ?                                             #|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#   1. Yes                                                                 #|#x\
#|#                                                                          #|#x\
#|#   2. No                                                                  #|#x\
#|#                                                                          #|#x\
#|#   0. Quit                                                                #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
################################################################################xx";

char userManual[4096] = "\
################################################################################x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#                  ||                                                      #|#x\
#|#     ... ...     ...     .. .. ..     ... ...                             #|#x\
#|#      ||'  ||     ||      || || ||     ||'  ||                            #|#x\
#|#      ||   ||     ||      || || ||     ||   ||            User Manual     #|#x\
#|#      ||    |     ||      || || ||     ||    |                            #|#x\
#|#      ||...' #   .||. #  .|| || ||. #  ||...' #                           #|#x\
#|#      ||                               ||                                 #|#x\
#|#     ''''                             ''''    ver 1.02                    #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#  Set your font size to 8 by 8. Now. And rerun the program.               #|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#  Some features in this version need your screen buffer size to be        #|#x\
#|#                                                                          #|#x\
#|#  set to 81 (h) by 80 (w) and your screen size to 80 by 80                #|#x\
#|#                                                                          #|#x\
#|#  It's just prettier this way.                                            #|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#  Make sure to specify the file eXtension in the converter, it won't     #|#x\
#|#                                                                          #|#x\
#|#  work otherwise. Also, the only currently supported image size is        #|#x\
#|#                                                                          #|#x\
#|#  64 by 64. More sizes are available for purchase as DLC.                 #|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#  Don't ask why it's version 1.02. And don't ask for new versions.        #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
################################################################################xx";

char fileInputBMP[2048] = "\
################################################################################x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#  Enter input file name (should be .bmp)                                  #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
################################################################################xx";

char fileOutput[2048] = "\
################################################################################x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#  Enter output file name                                                  #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
################################################################################xx";

char fileInputTXT[2048] = "\
################################################################################x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#  Enter input file name                                                   #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
################################################################################xx";

char valueInputImageSize[2048] = "\
################################################################################x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#  Enter image size (just kidding it's 64)                                 #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
################################################################################xx";

char valueInputThreshold[2048] = "\
################################################################################x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#  Enter threshold for processing (between 1 and 765)                      #|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#  The average value is 382 but feel free to use others                    #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
################################################################################xx";

char editorManual[4096] = "\
################################################################################x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#                  ||                                                      #|#x\
#|#     ... ...     ...     .. .. ..     ... ...                             #|#x\
#|#      ||'  ||     ||      || || ||     ||'  ||                            #|#x\
#|#      ||   ||     ||      || || ||     ||   ||           Editor Manual    #|#x\
#|#      ||    |     ||      || || ||     ||    |                            #|#x\
#|#      ||...' #   .||. #  .|| || ||. #  ||...' #                           #|#x\
#|#      ||                               ||                                 #|#x\
#|#     ''''                             ''''    ver 1.02                    #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
#|############################################################################|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#  Don't worry, you will have no genuine reason to use this.               #|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#  Large image sizes will lag it like crazy. Only go up to 32.             #|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#  You can input more than one command at a time.                          #|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#  Key bindings:                                                           #|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|#  W A S D - move the cursor                                               #|#x\
#|#                                                                          #|#x\
#|#  1 2 3 - change cursor size                                              #|#x\
#|#                                                                          #|#x\
#|#  X - erase    SPACE - draw    C - clear image                            #|#x\
#|#                                                                          #|#x\
#|#  I - open converted image file     O - open editor save file             #|#x\
#|#                                                                          #|#x\
#|#  P - save project                                                        #|#x\
#|#                                                                          #|#x\
#|#  ? - display this menu                                                   #|#x\
#|#                                                                          #|#x\
#|#  B - quit                                                                #|#x\
#|#                                                                          #|#x\
#|#                                                                          #|#x\
#|############################################################################|#x\
#||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||#x\
################################################################################xx";

char jokeManual[8096] = "\
Ok here are some cows then:x\
         (__)x\
         (oo)x\
  /-------\\/x\
 / |     ||x\
*  ||----||x\
   ~~    ~~x\
     Cowx\
 x\
 x\
         O__Ox\
         (oo)x\
  /-------\\/x\
 / |     ||x\
*  ||----||x\
   ~~    ~~x\
Cow at Disneylandx\
 x\
 x\
       \\ (__)x\
       \\\\(oo)x\
  /-----\\\\\\/x\
 / |    (##)x\
*  ||----||'x\
   ~~    ~~x\
This cow plays bagpipes.x\
 x\
         (__)                     (__)                     (__)x\
         (\\/)                     ($$)                     (**)x\
  /-------\\/               /-------\\/               /-------\\/x\
 / | 666 ||               / |=====||               / |     ||x\
*  ||----||              *  ||----||              *  ||----||x\
   ~~    ~~                 ~~    ~~                 ~~    ~~x\
Satanic cow           This cow is a Yuppie         Cow in lovex\
 x\
 x\
         ____x\
        (____)x\
 x\
         (__)x\
         (oo)x\
  /-------\\/x\
 / |     ||x\
*  ||----||x\
   ~~    ~~x\
   holy cowx\
 x\
       \\^^^^^^^^\\   (__)x\
        \\^^^^^^^^\\\\ (oo)x\
     *-----\\_______\\/\\/x\
   ^_______/   ---  \\______^x\
  ^--------\\   \\S/  /\\_____^x\
            \\______/x\
 x\
It's a bird...x\
 It's a plane...x\
 x\
 x\
                     (__)x\
                     (oo)x\
  /-------------------\\/x\
 / |                 ||x\
*  ||----------------||x\
   ^^                ^^x\
Stretch Cowx\
 x\
 x\
        __x\
     __/o \\_x\
     \\____  \\ x\
         /   \\ x\
   ___ //\\   \\ x\
__/o \\-//--\\   \\_/x\
\\____  ___  \\  |x\
     ||   \\ |\\ |x\
    _||   _||_||x\
Not cows at allxx";

