#include "DeleteSmallArea.h"
#include "Regionprops.h"
#include "NewBlobLabel8.h"

// 删除小面积区域
int DeleteSmallArea(BYTE*imbw, int imWidth, int imHeight, int areaThresh)
{
	// 连通区域标记
	INT blobcount = 0;
	INT *bloblables = new INT[imWidth*imHeight];
	memset(bloblables,0,sizeof(INT)*imWidth*imHeight);
	NewBlobsLabel8(imbw,imWidth,imHeight,blobcount,bloblables);
	// 面积
	INT *Area = new INT[blobcount];
	memset(Area,0,sizeof(INT)*blobcount);
	region_area(bloblables,blobcount,imWidth,imHeight,Area);
	// 外接矩形
	box *boundingbox = new box[blobcount];
	memset(boundingbox,0,sizeof(box)*blobcount);
	region_boundingbox(bloblables,blobcount,imWidth,imHeight,boundingbox);

	int maintainArea = blobcount;

	// 循环去除小面积
	for (int k = 0; k < blobcount; ++k)
	{
		if (Area[k] < areaThresh)
		{
			maintainArea--;
			INT top = boundingbox[k].row;
			INT left = boundingbox[k].col;
			INT width = boundingbox[k].width;
			INT height =boundingbox[k].height;
			INT bottom = top + height;
			INT right = left + width;
			for (int i = top; i < bottom; ++i)
			{
				for (int j = left; j < right; ++j)
				{
					if (bloblables[i*imWidth+j] == k+1)
					{
						imbw[i*imWidth+j] = 0;
					}
				}
			}
		}
	}
	delete [] bloblables;
	delete [] Area;
	delete [] boundingbox;
	return maintainArea;
}

// 删除不符合的面积区域
int DeleteArea(BYTE*imbw, int imWidth, int imHeight, int lowThresh, int highThresh)
{
	// 连通区域标记
	INT blobcount = 0;
	INT *bloblables = new INT[imWidth*imHeight];
	memset(bloblables, 0, sizeof(INT)*imWidth*imHeight);
	NewBlobsLabel8(imbw, imWidth, imHeight, blobcount, bloblables);
	// 面积
	INT *Area = new INT[blobcount];
	memset(Area, 0, sizeof(INT)*blobcount);
	region_area(bloblables, blobcount, imWidth, imHeight, Area);
	// 外接矩形
	box *boundingbox = new box[blobcount];
	memset(boundingbox, 0, sizeof(box)*blobcount);
	region_boundingbox(bloblables, blobcount, imWidth, imHeight, boundingbox);

	int maintainArea = blobcount;

	// 循环去除小面积
	for (int k = 0; k < blobcount; ++k)
	{
		if (Area[k] < lowThresh || Area[k] > highThresh)
		{
			maintainArea--;
			INT top = boundingbox[k].row;
			INT left = boundingbox[k].col;
			INT width = boundingbox[k].width;
			INT height = boundingbox[k].height;
			INT bottom = top + height;
			INT right = left + width;
			for (int i = top; i < bottom; ++i)
			{
				for (int j = left; j < right; ++j)
				{
					if (bloblables[i*imWidth + j] == k + 1)
					{
						imbw[i*imWidth + j] = 0;
					}
				}
			}
		}
	}
	delete[] bloblables;
	delete[] Area;
	delete[] boundingbox;
	return maintainArea;
}