﻿#ifndef LCDWIDGET_H
#define LCDWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>

#define CHAR_RAM_SIZE        256
#define CGRAM_STORAGE_CHARS  16
#define ROM_FONT_CHARS       (CHAR_RAM_SIZE - CGRAM_STORAGE_CHARS)

#define LCD_CHAR_W 5
#define LCD_CHAR_H 8

#define LCD_BORDER_SIZE 10
#define LCD_PIXEL_SIZE_W 4
#define LCD_PIXEL_SIZE_H 4
#define LCD_PIXEL_SPACE_X 1
#define LCD_PIXEL_SPACE_Y 1

#define LCD_CHAR_PIXEL_SIZE_W (LCD_PIXEL_SIZE_W + LCD_PIXEL_SPACE_X) * LCD_CHAR_W
#define LCD_CHAR_PIXEL_SIZE_H (LCD_PIXEL_SIZE_H + LCD_PIXEL_SPACE_Y) * LCD_CHAR_H
#define LCD_CHAR_SPACE_X (LCD_PIXEL_SIZE_W + LCD_PIXEL_SPACE_X) * 1
#define LCD_CHAR_SPACE_Y (LCD_PIXEL_SIZE_H + LCD_PIXEL_SPACE_Y) * 1


class LCDWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LCDWidget(QWidget *parent = nullptr);
    ~LCDWidget();
    void paintEvent(QPaintEvent *event);
    void RefreshDisplay();

    int GetCurrentColumn();
    int GetCurrentRow();

    void SetColorBackground1(const QColor color);
    void SetColorBackground2(const QColor color);
    void SetColorPixel(const QColor color);

    QColor SetColorBackground1();
    QColor SetColorBackground2();
    QColor SetColorPixel();

    void SetCursorPosition(uint16_t x, uint16_t y);
    void SetText(QString text);

    uint8_t* GetDisplayCharBuffer();
    int GetDisplayCharBufferLength();

    void ClearLCD();
    bool SaveImage(QString filename);

private:
    void CalculateDisplaySize();
    void DrawChar(int x, int y, uint8_t c);
    void CopyCharRomToRam();

    /* font roms */
    static const uint8_t fontA00[ROM_FONT_CHARS][LCD_CHAR_W];
    static const uint8_t fontA02[ROM_FONT_CHARS][LCD_CHAR_W];

    QImage *display;
    int row, column;

    int display_size_w, display_size_h;

    uint8_t char_ram[CHAR_RAM_SIZE][LCD_CHAR_W];
    uint8_t *display_char_buffer;

    uint16_t cursor_pos_x, cursor_pos_y;

    QColor color_background_1;
    QColor color_background_2;
    QColor color_pixel;

signals:

};

#endif // LCDWIDGET_H
