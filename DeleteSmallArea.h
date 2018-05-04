#ifndef _DeleteSmallArea_
#define _DeleteSmallArea_

#include "TypeDef.h"

int DeleteSmallArea(BYTE*imbw, int imWidth, int imHeight, int areaThresh);
int DeleteArea(BYTE*imbw, int imWidth, int imHeight, int lowThresh, int highThresh);

#endif