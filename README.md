# CanvasC 文档

## 基本说明

**CanvasC** 是一个使用 **ANSI C** 编写的图形库，提供了一些基本的绘图函数，所有图形将会在一张 `.ppm` 格式的图片上生成。

## 基本概念

### 绘图设备

CanvasC 使用一个结构体来表示绘图设备，结构体定义如下：

```c
struct CANVAS {
    int width;
    int height;
    int originX;
    int originY;
};
```

其中，`width` 和 `height` 分别表示绘图设备的宽度和高度，`originX` 和 `originY` 分别表示绘图设备的原点坐标。

### 坐标系

CanvasC 使用一个二维坐标系来表示绘图设备的坐标，原点位于绘图设备的左上角，x 轴**向右**为正方向，y 轴**向下**为正方向。

### 颜色

CanvasC 使用一个结构体来表示颜色，结构体定义如下：

```c
struct COLOR {
    unsigned char R;
    unsigned char G;
    unsigned char B;
};
```

其中，`R`、`G`、`B` 分别表示红色、绿色、蓝色的强度，取值范围是 0 到 255。

##### 宏函数 `RGB(r, g, b)`

将 RGB 值转换为 `const struct COLOR` 类型。

```c
#define RGB(r, g, b) \
    ((const struct COLOR){(r), (g), (b)})
```

#### 全局颜色

CanvasC 提供了一些全局颜色，可以在绘图函数中使用：

##### 背景色

默认为**黑色**。

`struct COLOR backColor = { 0, 0, 0 };`

##### 线条色

默认为**白色**。

`struct COLOR lineColor = { 255, 255, 255 };`

##### 填充色

默认为**白色**。

`struct COLOR fillColor = { 255, 255, 255 };`

##### 字体色

默认为**白色**。

`struct COLOR textColor = { 255, 255, 255 };`

#### 默认颜色

CanvasC 提供了一些默认颜色，可以在绘图函数中使用：

| 颜色名称 | COLOR NAME | 颜色值RGB |
| :------: | :------:  | :------:  |
| 红色   |   `RED`     |  `(255,   0,   0)`  |
| 绿色   |   `GREEN`   |  `(  0, 255,   0)`  |
| 蓝色   |   `BLUE`    |  `(  0,   0, 255)`  |
| 黑色   |   `BLACK`   |  `(  0,   0,   0)`  |
| 白色   |   `WHITE`   |  `(255, 255, 255)`  |
| 黄色   |   `YELLOW`  |  `(255, 255,   0)`  |
| 紫色   |   `PURPLE`  |  `(128,   0, 128)`  |
| 青色   |   `CYAN`    |  `(  0, 255, 255)`  |
| 品红色 |   `MAGENTA` |  `(255,   0, 255)`  |
| 橘色   |   `ORANGE`  |  `(255, 165,   0)`  |
| 灰色   |   `GRAY`    |  `(128, 128, 128)`  |

注：默认颜色均为 `const struct COLOR` 类型，**不能修改**。

## 函数说明

### 绘图设备相关函数

#### 初始化绘图设备

```c
void initCanvas(
    int width, 
    int height, 
    const char* filename
);
```

#### 关闭绘图设备

注：只有调用该函数时，绘图设备上的所有图形才会被保存到文件中。

```c
void closeCanvas();
```

#### 清空绘图设备

注：清空绘图设备实际上是将绘图设备上的所有像素点设置为背景颜色。

```c
void clearCanvas();
```

#### 设置原点

```c
void setCanvasOrigin(
    int x, 
    int y
);
```

### 颜色相关函数

#### 设置背景颜色

```c
void setBackColor(struct COLOR color);
```

#### 设置线条颜色

```c
void setLineColor(struct COLOR color);
```

#### 设置填充颜色

```c
void setFillColor(struct COLOR color);
```

#### 设置文字颜色

```c
void setTextColor(struct COLOR color);
```

### 绘图函数

### 绘制基本图形

#### 绘制点

```c
void putPixel(
    int x, 
    int y, 
    struct COLOR color
);
```

#### 绘制线段

```c
void line(
    int x1, 
    int y1, 
    int x2, 
    int y2, 
    struct COLOR color);
```

#### 绘制圆

##### 空心圆

```c
void circle(
    int x, 
    int y, 
    int radius
);
```

##### 实心圆

```c
void solidCircle(
    int x, 
    int y, 
    int radius
);
```

##### 填充圆

```c
void fillCircle(
    int x, 
    int y, 
    int radius
);
```

#### 绘制椭圆

##### 空心椭圆

```c
void ellipse(
    int left, 
    int top, 
    int right, 
    int bottom
);
```

##### 实心椭圆

```c
void solidEllipse(
    int left, 
    int top, 
    int right, 
    int bottom
);
```

##### 填充椭圆

```c
void fillEllipse(
    int left, 
    int top, 
    int right, 
    int bottom
);
```

#### 绘制矩形

##### 空心矩形

```c
void rectangle(
    int left, 
    int top, 
    int right, 
    int bottom
);
```

##### 实心矩形

```c
void solidRectangle(
    int left, 
    int top, 
    int right, 
    int bottom
);
```

##### 填充矩形

```c
void fillRectangle(
    int left, 
    int top, 
    int right, 
    int bottom
);
```

### 绘制文字

#### 绘制文字

注：当前文字仅支持大写英文字母。

##### 绘制单个字符

```c
void putChar(
    int x, 
    int y, 
    char c
);
```

##### 绘制字符串

注：支持换行符 `\n`。

```c
void putText(
    int x, 
    int y, 
    const char* str
);
```

## 内置宏

### 宏定义

#### 宏 `COLOR_MAX`

RGB 的最大值。

```c
#define COLOR_MAX 255
```

### 宏函数

#### 宏函数 

##### `RGB(r, g, b)`

将 RGB 值转换为 `const struct COLOR` 类型。

```c
#define RGB(r, g, b) \
    ((const struct COLOR){(r), (g), (b)})
```

##### `Max(a, b)`

返回 `a` 和 `b` 中的较大值。

```c
#define Max(a, b) \
    ((a) > (b) ? (a) : (b))
```

##### `Min(a, b)`

返回 `a` 和 `b` 中的较小值。

```c
#define Min(a, b) \
    ((a) < (b) ? (a) : (b))
```

##### `Abs(x)`

返回 `x` 的绝对值。

```c
#define Abs(x) \
    ((x) < 0 ? -(x) : (x))
```

##### `Sq(x)`

返回 `x` 的平方。

```c
#define Sq(x) \
    ((x) * (x))
```

##### `Swap(a, b, Type)`

交换 `a` 和 `b` 的值。

```c
#define Swap(a, b, Type) \
    do { \
        Type temp = (a); \
        (a) = (b); \
        (b) = temp; \
    } while (0)
```