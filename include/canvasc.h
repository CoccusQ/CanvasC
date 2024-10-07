#ifndef CANVASC_H
#define CANVASC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "font.h"

#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Abs(a) ((a > 0) ? (a) : (-a))
#define Sq(a) ((a) * (a))
#define Swap(a, b, Type) do { Type temp = a; a = b; b = temp; } while(0)
#define RGB(r, g, b) ((const struct COLOR){(r), (g), (b)})
#define COLOR_MAX 255

struct CANVAS {
    int Width;
    int Height;
    int originX;
    int originY;
} canvas;

struct COLOR {
    unsigned char R;
    unsigned char G;
    unsigned char B;
};

struct ARRAY {
    struct COLOR* element;
    int size;
} array;

extern const struct COLOR RED;
extern const struct COLOR GREEN;
extern const struct COLOR BLUE;
extern const struct COLOR BLACK;
extern const struct COLOR WHITE;
extern const struct COLOR YELLOW;
extern const struct COLOR PURPLE;
extern const struct COLOR CYAN;
extern const struct COLOR MAGENTA;
extern const struct COLOR ORANGE;
extern const struct COLOR GRAY;

extern struct COLOR backColor;
extern struct COLOR lineColor;
extern struct COLOR fillColor;
extern struct COLOR textColor;

extern FILE* fileCanvas;

void initArray(int newSize);

void clearCanvas();

void initCanvas(int width, int height, const char* filename);

void setCanvasOrigin(int x, int y) ;

void saveCanvas();

void closeCanvas();

void setBackColor(struct COLOR color);

void setLineColor(struct COLOR color);

void setFillColor(struct COLOR color);

void setTextColor(struct COLOR color);

void putPixel(int x, int y, const struct COLOR color);

void line(int x1, int y1, int x2, int y2);

void circle(int x, int y, int radius);

void solidCircle(int x, int y, int radius);

void fillCircle(int x, int y, int radius);

void ellipse(int left, int top, int right, int bottom);

void solidEllipse(int left, int top, int right, int bottom);

void fillEllipse(int left, int top, int right, int bottom);

void rectangle(int left, int top, int right, int bottom);

void fillRectangle(int left, int top, int right, int bottom);

void putChar(int x, int y, char c);

void putText(int x, int y, const char* str);

#endif