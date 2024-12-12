#ifndef __IMG_HEADER__
#define __IMG_HEADER__

#include "stdint.h"

#ifdef __WASM__
#include <emscripten.h>
#endif


typedef struct{
	uint32_t		colors[16];
}ColorPalette;

typedef struct{
	uint32_t*		pixels;
	int				h, w;
}Img;

typedef struct{
	int				x, y, h, w;
}TextWindow;


typedef struct{
	uint32_t*		pxl;
	int32_t*		data;
	int				h, w, vx, vy, zoom;
}DataImg;

DataImg			initDataImg				(int, int);
DataImg			randomizeDataImg		(DataImg);
void			drawDataImg				(Img, DataImg, int, int, int, int);
int32_t			clickDataImg			(DataImg, int, int, int, int);
int				rectCheck				(int, int, int, int, int, int);
void			printFillDataImg		(DataImg);
void			printMarkDataImg		(DataImg, int, int);


ColorPalette	defaultPalette			();

Img				makeFont				();
void			drawChar				(Img, Img, uint8_t, int, int);
void			drawColorChar			(Img, Img, uint8_t, int, int, uint32_t, uint32_t);
void			drawColorCharFlat		(Img, Img, uint8_t, int, int, uint32_t, uint32_t);
void			drawText				(Img, Img, char*  , int, int);
void			drawTextSize			(Img, Img, char*  , int, int, int);
void			drawTextColor			(Img, Img, char*  , int, int, uint32_t, uint32_t);
void			drawTextSizeColor		(Img, Img, char*  , int, int, int, uint32_t, uint32_t);
void			windowText				(Img, Img, TextWindow, char*  , int, int);
void			windowTextColor			(Img, Img, TextWindow, char*  , int, int, uint32_t, uint32_t);
int				lineCount				(char*, int);
int				lineCountSize			(char*, int, int);

void			drawSpot				(Img, int, int, uint32_t);
void			drawStar				(Img, int, int, uint32_t);


typedef struct{
	uint32_t*	fg;
	uint32_t*	bg;
	uint8_t*	text;
	int			h, w;
}TextImg;


TextImg			makeTextImg				(int, int);
void			voidTextImg				(TextImg);
void			drawTextImg				(Img, Img, TextImg);
void			drawTextImgDiff			(Img, Img, TextImg, TextImg);
void			rectTextImg				(TextImg, int, int, int, int, uint32_t, uint32_t, uint8_t);
void			textTextImg				(TextImg, int, int, char*, uint32_t, uint32_t);
void			textTextImgSize			(TextImg, int, int, char*, int, uint32_t , uint32_t );
void			textCenterTextSize		(TextImg, int, int, char*, int, int, uint32_t, uint32_t);
void			ctextTextImgSize		(TextImg, int, int, char*, int, uint32_t*, uint32_t*);
void			fTextTextImg			(TextImg, int, int, char*, int, uint32_t, uint32_t);
void			fmtTextTextImg			(TextImg, int, int, char*, int, uint32_t, uint32_t);
void			renderTextImgSize		(TextImg, int, int, char*, int, uint32_t , uint32_t );
void			borderTextImg			(TextImg, int, int, int, int, uint32_t, uint32_t);

void			renderTextPos			(char*, int, int, int*, int*);
int				closestLinePos			(char*, int, int);
void			renderLineImgWindow		(TextImg, int, int, char*, int, int, int, uint32_t, uint32_t);
int				lineWidth				(char*, int);
int				charCol					(char*, int, int);


void			hilbertRot				(int, int*, int*, int , int);
void			hilbert					(int, int , int*, int*);
int				unhilbert				(int, int, int);

#endif
