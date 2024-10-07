#include "canvasc.h"

const struct COLOR RED = { 255, 0, 0 };
const struct COLOR GREEN = { 0, 255, 0 };
const struct COLOR BLUE = { 0, 0, 255 };
const struct COLOR BLACK = { 0, 0, 0 };
const struct COLOR WHITE = { 255, 255, 255 };
const struct COLOR YELLOW = { 255, 255, 0 };
const struct COLOR PURPLE = { 128, 0, 128 };
const struct COLOR CYAN = {0, 255, 255};
const struct COLOR MAGENTA = {255, 0, 255};
const struct COLOR ORANGE = {255, 165, 0};
const struct COLOR GRAY = {128, 128, 128};

struct COLOR backColor = { 0, 0, 0 };
struct COLOR lineColor = { 255, 255, 255};
struct COLOR fillColor = { 255, 255, 255};
struct COLOR textColor = { 255, 255, 255};

FILE* fileCanvas = NULL;

void initArray(int newSize) {
    array.size = newSize;
    array.element = (struct COLOR*)malloc(sizeof(struct COLOR) * newSize);
}

void clearCanvas() {
    for (int row = 0; row < canvas.Height; row++) {
        for (int col = 0; col < canvas.Width; col++) {
            array.element[canvas.Width * row + col].R = backColor.R;
            array.element[canvas.Width * row + col].G = backColor.G;
            array.element[canvas.Width * row + col].B = backColor.B;
        }
    }
}

void initCanvas(int width, int height, const char* filename) {
    canvas.Width = width;
    canvas.Height = height;
    canvas.originX = 0;
    canvas.originY = 0;
    initArray(width * height);
    fileCanvas = fopen(filename, "wb");
    if (fileCanvas == NULL) {
        int errorNum = errno;
        fprintf(stderr, "[ ERROR ] %s\n", strerror(errno));
        exit(errno);
    }
    fprintf(fileCanvas, "P6\n");
    fprintf(fileCanvas, "%d %d\n", width, height);
    fprintf(fileCanvas, "%d\n", COLOR_MAX);
    clearCanvas();
}

void setCanvasOrigin(int x, int y) {
    canvas.originX = x;
    canvas.originY = y;
}

void saveCanvas() {
    int r, g, b;
    for (int row = 0; row < canvas.Height; row++) {
        for (int col = 0; col < canvas.Width; col++) {
            r = array.element[canvas.Width * row + col].R;
            g = array.element[canvas.Width * row + col].G;
            b = array.element[canvas.Width * row + col].B;
            fputc(r, fileCanvas);
            fputc(g, fileCanvas);
            fputc(b, fileCanvas);
        }
    }
}

void closeCanvas() {
    saveCanvas();
    free(array.element);
    fclose(fileCanvas);
}

void setBackColor(struct COLOR color) {
    backColor.R = color.R;
    backColor.G = color.G;
    backColor.B = color.B;
}

void setLineColor(struct COLOR color) {
    lineColor.R = color.R;
    lineColor.G = color.G;
    lineColor.B = color.B;
}

void setFillColor(struct COLOR color) {
    fillColor.R = color.R;
    fillColor.G = color.G;
    fillColor.B = color.B;
}

void setTextColor(struct COLOR color) {
    textColor.R = color.R;
    textColor.G = color.G;
    textColor.B = color.B;
}

void putPixel(int x, int y, const struct COLOR color) {
    int row = y + canvas.originY;
    int col = x + canvas.originX;
    if (row > canvas.Height || col > canvas.Width || row < 0 || col < 0) {
        return;
    }
    array.element[canvas.Width * row + col].R = color.R;
    array.element[canvas.Width * row + col].G = color.G;
    array.element[canvas.Width * row + col].B = color.B;
}

void line(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int signX = dx > 0 ? 1 : (dx < 0 ? -1 : 0);
    int signY = dy > 0 ? 1 : (dy < 0 ? -1 : 0);
    dx = abs(dx);
    dy = abs(dy);

    int change = 0;
    if (dy > dx) {
        int temp = dx;
        dx = dy;
        dy = temp;
        change = 1;
    }

    int e = -dx;
    int x = x1, y = y1;

    for (int i = 0; i <= dx; i++) {
        putPixel(x, y, lineColor);
        e += 2 * dy;
        if (e >= 0) {
            if (change == 1) 
                x += signX;
            else 
                y += signY;
            e -= 2 * dx;
        }
        if (change == 1) 
            y += signY;
        else 
            x += signX;
    }
}

void circle(int x, int y, int radius) {
    radius = Abs(radius);
    int dx = 0;
    int dy = radius;
    int e = 1 - radius;
    while (dx <= dy) {
        putPixel(x + dx, y + dy, lineColor);
        putPixel(x + dx, y - dy, lineColor);
        putPixel(x - dx, y + dy, lineColor);
        putPixel(x - dx, y - dy, lineColor);
        putPixel(x + dy, y + dx, lineColor);
        putPixel(x + dy, y - dx, lineColor);
        putPixel(x - dy, y + dx, lineColor);
        putPixel(x - dy, y - dx, lineColor);

        if (e < 0) {
            e += 2 * dx + 1;
        }
        else {
            e += 2 * (dx - dy) + 1;
            dy--;
        }
        dx++;
    }
}

void solidCircle(int x, int y, int radius) {
    radius = Abs(radius);
    int dx = 0;
    int dy = radius;
    int e = 1 - radius;
    struct COLOR temp = lineColor;
    setLineColor(fillColor);
    while (dx <= dy) {
        line(x + dx, y + dy, x + dx, y - dy);
        line(x + dx, y + dy, x - dx, y + dy);
        line(x - dx, y - dy, x + dx, y - dy);
        line(x - dx, y - dy, x - dx, y + dy);
        line(x + dy, y + dx, x + dy, y - dx);
        line(x + dy, y + dx, x - dy, y + dx);
        line(x - dy, y - dx, x + dy, y - dx);
        line(x - dy, y - dx, x - dy, y + dx);

        if (e < 0) {
            e += 2 * dx + 1;
        }
        else {
            e += 2 * (dx - dy) + 1;
            dy--;
        }
        dx++;
    }
    setLineColor(temp);
}

void fillCircle(int x, int y, int radius) {
    solidCircle(x, y, radius);
    circle(x, y, radius);
}

void ellipse(int left, int top, int right, int bottom) {
    if (left > right) Swap(left, right, int);
    if (top > bottom) Swap(top, bottom, int);
    double w = (double)(right - left);
    double h = (double)(bottom - top);
    double x = (double)(left + right) * (bottom - top);
    double y = (double)(top + bottom) * (right - left);
    int radius = (right - left) * (bottom - top);
    int dx = 0;
    int dy = radius;
    int e = 1 - radius;
    while (dx <= dy) {
        putPixel((x + dx) / (h * 2), (y + dy) / (w * 2), lineColor);
        putPixel((x + dx) / (h * 2), (y - dy) / (w * 2), lineColor);
        putPixel((x - dx) / (h * 2), (y + dy) / (w * 2), lineColor);
        putPixel((x - dx) / (h * 2), (y - dy) / (w * 2), lineColor);
        putPixel((x + dy) / (h * 2), (y + dx) / (w * 2), lineColor);
        putPixel((x + dy) / (h * 2), (y - dx) / (w * 2), lineColor);
        putPixel((x - dy) / (h * 2), (y + dx) / (w * 2), lineColor);
        putPixel((x - dy) / (h * 2), (y - dx) / (w * 2), lineColor);

        if (e < 0) {
            e += 2 * dx + 1;
        }
        else {
            e += 2 * (dx - dy) + 1;
            dy--;
        }
        dx++;
    }
}

void solidEllipse(int left, int top, int right, int bottom) {
    if (left > right) Swap(left, right, int);
    if (top > bottom) Swap(top, bottom, int);
    int startRow = Max(0, top + canvas.originY);
    int startCol = Max(0, left + canvas.originX);
    int endRow = Min(canvas.Height, bottom + canvas.originY);
    int endCol = Min(canvas.Width, right + canvas.originX);
    int x = (left + right) / 2;
    int y = (top + bottom) / 2;
    int a = (right - left) / 2;
    int b = (bottom - top) / 2;
    int sqa = a * a;
    int sqb = b * b;
    int sqab = a * a * b * b;
    for (int row = startRow; row <= endRow; row++) {
        for (int col = startCol; col <= endCol; col++) {
            if (Sq(row - y - canvas.originY) * sqa + Sq(col - x - canvas.originX) * sqb <= sqab) {
                array.element[canvas.Width * row + col].R = fillColor.R;
                array.element[canvas.Width * row + col].G = fillColor.G;
                array.element[canvas.Width * row + col].B = fillColor.B;
            }
        }
    }
}

void fillEllipse(int left, int top, int right, int bottom) {
    if (left > right) Swap(left, right, int);
    if (top > bottom) Swap(top, bottom, int);
    int startRow = Max(0, top + canvas.originY);
    int startCol = Max(0, left + canvas.originX);
    int endRow = Min(canvas.Height, bottom + canvas.originY);
    int endCol = Min(canvas.Width, right + canvas.originX);
    int x = (left + right) / 2;
    int y = (top + bottom) / 2;
    int a = (right - left) / 2;
    int b = (bottom - top) / 2;
    int sqa = a * a;
    int sqb = b * b;
    int sqab = a * a * b * b;
    for (int row = startRow; row <= endRow; row++) {
        for (int col = startCol; col <= endCol; col++) {
            if (Sq(row - y - canvas.originY) * sqa + Sq(col - x - canvas.originX) * sqb <= sqab 
            && Sq(row - y - canvas.originY) * sqa + Sq(col - x - canvas.originX) * sqb >= Sq((a - 1) * (b - 1))) {
                array.element[canvas.Width * row + col].R = lineColor.R;
                array.element[canvas.Width * row + col].G = lineColor.G;
                array.element[canvas.Width * row + col].B = lineColor.B;
            }
            else if (Sq(row - y - canvas.originY) * sqa + Sq(col - x - canvas.originX) * sqb < Sq((a - 1) * (b - 1))) {
                array.element[canvas.Width * row + col].R = fillColor.R;
                array.element[canvas.Width * row + col].G = fillColor.G;
                array.element[canvas.Width * row + col].B = fillColor.B;
            }
        }
    }
}

void rectangle(int left, int top, int right, int bottom) {
    line(left, top, right, top);
    line(left, top, left, bottom);
    line(left, bottom, right, bottom);
    line(right, top, right, bottom);
}

void solidRectangle(int left, int top, int right, int bottom) {
    if (left > right) Swap(left, right, int);
    if (top > bottom) Swap(top, bottom, int);
    int startRow = Max(0, top + canvas.originY);
    int startCol = Max(0, left + canvas.originX);
    int endRow = Min(canvas.Height, bottom + canvas.originY);
    int endCol = Min(canvas.Width, right + canvas.originX);
    for (int row = startRow; row <= endRow; row++) {
        for (int col = startCol; col <= endCol; col++) {
            array.element[canvas.Width * row + col].R = fillColor.R;
            array.element[canvas.Width * row + col].G = fillColor.G;
            array.element[canvas.Width * row + col].B = fillColor.B;
        }
    }
}

void fillRectangle(int left, int top, int right, int bottom) {
    solidRectangle(left, top, right, bottom);
    rectangle(left, top, right, bottom);
}

void putChar(int x, int y, char c) {
    int idx;
    if ( c >= 'A' && c <= 'Z') {
        idx = c - 'A';
    }
    else {
        return;
    }
    for (int i = 0; i < FONT_LENGTH; i++) {
        if (fontTable[idx][i] == '1') {
            int row = (i) / FONT_WIDTH;
            int col = (i) % FONT_WIDTH;
            putPixel(col + x, row + y, textColor);
        }
    }
}

void putText(int x, int y, const char* str) {
    int len = strlen(str);
    int curX = x, curY = y;
    for (int i = 0; i < len; i++) {
        if (str[i] == '\n') {
            curY += FONT_HEIGHT;
            curX = x;
            continue;
        }
        putChar(curX, curY, str[i]);
        curX += FONT_WIDTH;
    }
}
