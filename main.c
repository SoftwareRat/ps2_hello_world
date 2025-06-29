#include <tamtypes.h>
#include <kernel.h>
#include <sifrpc.h>
#include <loadfile.h>
#include <stdio.h>
#include <gsKit.h>
#include <dmaKit.h>
#include <gsToolkit.h>
#include <stdlib.h>
#include <math.h>

// Screen constants
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// Color constants
#define GS_WHITE GS_SETREG_RGBAQ(0xFF, 0xFF, 0xFF, 0x80, 0x00)
#define GS_BLACK GS_SETREG_RGBAQ(0x00, 0x00, 0x00, 0x80, 0x00)
#define GS_BLUE  GS_SETREG_RGBAQ(0x00, 0x80, 0xFF, 0x80, 0x00)
#define GS_YELLOW GS_SETREG_RGBAQ(0xFF, 0xFF, 0x00, 0x80, 0x00)
#define GS_CYAN  GS_SETREG_RGBAQ(0x00, 0xFF, 0xFF, 0x80, 0x00)
#define GS_PURPLE GS_SETREG_RGBAQ(0xFF, 0x00, 0xFF, 0x80, 0x00)

// Simple text rendering using rectangles for pixel art style
void draw_text_hello_world(GSGLOBAL *gsGlobal, float x, float y, u64 color)
{
    float char_size = 4.0f;
    float spacing = 24.0f;
    float current_x = x;
    
    // H
    gsKit_prim_quad(gsGlobal, current_x, y, current_x + char_size, y, current_x, y + 30.0f, current_x + char_size, y + 30.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 14.0f, y, current_x + 18.0f, y, current_x + 14.0f, y + 30.0f, current_x + 18.0f, y + 30.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 13.0f, current_x + 18.0f, y + 13.0f, current_x, y + 17.0f, current_x + 18.0f, y + 17.0f, 0, color);
    current_x += spacing;
    
    // E
    gsKit_prim_quad(gsGlobal, current_x, y, current_x + char_size, y, current_x, y + 30.0f, current_x + char_size, y + 30.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y, current_x + 18.0f, y, current_x, y + 4.0f, current_x + 18.0f, y + 4.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 13.0f, current_x + 14.0f, y + 13.0f, current_x, y + 17.0f, current_x + 14.0f, y + 17.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 26.0f, current_x + 18.0f, y + 26.0f, current_x, y + 30.0f, current_x + 18.0f, y + 30.0f, 0, color);
    current_x += spacing;
    
    // L
    gsKit_prim_quad(gsGlobal, current_x, y, current_x + char_size, y, current_x, y + 30.0f, current_x + char_size, y + 30.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 26.0f, current_x + 18.0f, y + 26.0f, current_x, y + 30.0f, current_x + 18.0f, y + 30.0f, 0, color);
    current_x += spacing;
    
    // L
    gsKit_prim_quad(gsGlobal, current_x, y, current_x + char_size, y, current_x, y + 30.0f, current_x + char_size, y + 30.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 26.0f, current_x + 18.0f, y + 26.0f, current_x, y + 30.0f, current_x + 18.0f, y + 30.0f, 0, color);
    current_x += spacing;
    
    // O
    gsKit_prim_quad(gsGlobal, current_x, y + 4.0f, current_x + 18.0f, y + 4.0f, current_x, y + 8.0f, current_x + 18.0f, y + 8.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 22.0f, current_x + 18.0f, y + 22.0f, current_x, y + 26.0f, current_x + 18.0f, y + 26.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 4.0f, current_x + char_size, y + 4.0f, current_x, y + 26.0f, current_x + char_size, y + 26.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 14.0f, y + 4.0f, current_x + 18.0f, y + 4.0f, current_x + 14.0f, y + 26.0f, current_x + 18.0f, y + 26.0f, 0, color);
    current_x += spacing + 10.0f;
    
    // W
    gsKit_prim_quad(gsGlobal, current_x, y, current_x + char_size, y, current_x, y + 30.0f, current_x + char_size, y + 30.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 8.0f, y + 15.0f, current_x + 12.0f, y + 15.0f, current_x + 8.0f, y + 30.0f, current_x + 12.0f, y + 30.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 16.0f, y, current_x + 20.0f, y, current_x + 16.0f, y + 30.0f, current_x + 20.0f, y + 30.0f, 0, color);
    current_x += spacing + 5.0f;
    
    // O
    gsKit_prim_quad(gsGlobal, current_x, y + 4.0f, current_x + 18.0f, y + 4.0f, current_x, y + 8.0f, current_x + 18.0f, y + 8.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 22.0f, current_x + 18.0f, y + 22.0f, current_x, y + 26.0f, current_x + 18.0f, y + 26.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 4.0f, current_x + char_size, y + 4.0f, current_x, y + 26.0f, current_x + char_size, y + 26.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 14.0f, y + 4.0f, current_x + 18.0f, y + 4.0f, current_x + 14.0f, y + 26.0f, current_x + 18.0f, y + 26.0f, 0, color);
    current_x += spacing;
    
    // R
    gsKit_prim_quad(gsGlobal, current_x, y, current_x + char_size, y, current_x, y + 30.0f, current_x + char_size, y + 30.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y, current_x + 18.0f, y, current_x, y + 4.0f, current_x + 18.0f, y + 4.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 13.0f, current_x + 18.0f, y + 13.0f, current_x, y + 17.0f, current_x + 18.0f, y + 17.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 14.0f, y, current_x + 18.0f, y, current_x + 14.0f, y + 17.0f, current_x + 18.0f, y + 17.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 10.0f, y + 17.0f, current_x + 18.0f, y + 17.0f, current_x + 14.0f, y + 30.0f, current_x + 18.0f, y + 30.0f, 0, color);
    current_x += spacing;
    
    // L
    gsKit_prim_quad(gsGlobal, current_x, y, current_x + char_size, y, current_x, y + 30.0f, current_x + char_size, y + 30.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 26.0f, current_x + 18.0f, y + 26.0f, current_x, y + 30.0f, current_x + 18.0f, y + 30.0f, 0, color);
    current_x += spacing;
    
    // D
    gsKit_prim_quad(gsGlobal, current_x, y, current_x + char_size, y, current_x, y + 30.0f, current_x + char_size, y + 30.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y, current_x + 14.0f, y, current_x, y + 4.0f, current_x + 14.0f, y + 4.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 26.0f, current_x + 14.0f, y + 26.0f, current_x, y + 30.0f, current_x + 14.0f, y + 30.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 14.0f, y + 4.0f, current_x + 18.0f, y + 4.0f, current_x + 14.0f, y + 26.0f, current_x + 18.0f, y + 26.0f, 0, color);
}

void draw_text_ps2(GSGLOBAL *gsGlobal, float x, float y, u64 color)
{
    float char_size = 3.0f;
    float spacing = 18.0f;
    float current_x = x;
    
    // P
    gsKit_prim_quad(gsGlobal, current_x, y, current_x + char_size, y, current_x, y + 24.0f, current_x + char_size, y + 24.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y, current_x + 15.0f, y, current_x, y + 3.0f, current_x + 15.0f, y + 3.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 10.0f, current_x + 15.0f, y + 10.0f, current_x, y + 13.0f, current_x + 15.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 12.0f, y, current_x + 15.0f, y, current_x + 12.0f, y + 13.0f, current_x + 15.0f, y + 13.0f, 0, color);
    current_x += spacing;
    
    // S
    gsKit_prim_quad(gsGlobal, current_x, y, current_x + 15.0f, y, current_x, y + 3.0f, current_x + 15.0f, y + 3.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 10.0f, current_x + 15.0f, y + 10.0f, current_x, y + 13.0f, current_x + 15.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 21.0f, current_x + 15.0f, y + 21.0f, current_x, y + 24.0f, current_x + 15.0f, y + 24.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y, current_x + char_size, y, current_x, y + 13.0f, current_x + char_size, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 12.0f, y + 10.0f, current_x + 15.0f, y + 10.0f, current_x + 12.0f, y + 24.0f, current_x + 15.0f, y + 24.0f, 0, color);
    current_x += spacing;
    
    // 2
    gsKit_prim_quad(gsGlobal, current_x, y, current_x + 15.0f, y, current_x, y + 3.0f, current_x + 15.0f, y + 3.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 10.0f, current_x + 15.0f, y + 10.0f, current_x, y + 13.0f, current_x + 15.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 21.0f, current_x + 15.0f, y + 21.0f, current_x, y + 24.0f, current_x + 15.0f, y + 24.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 12.0f, y, current_x + 15.0f, y, current_x + 12.0f, y + 13.0f, current_x + 15.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 10.0f, current_x + char_size, y + 10.0f, current_x, y + 24.0f, current_x + char_size, y + 24.0f, 0, color);
}

void draw_text_by_softwarerat(GSGLOBAL *gsGlobal, float x, float y, u64 color)
{
    // Draw "by SoftwareRat" using proper pixel art letters
    float char_size = 2.0f;
    float spacing = 8.0f;
    float current_x = x;
    
    // b
    gsKit_prim_quad(gsGlobal, current_x, y, current_x + char_size, y, current_x, y + 12.0f, current_x + char_size, y + 12.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 5.0f, current_x + 6.0f, y + 5.0f, current_x, y + 7.0f, current_x + 6.0f, y + 7.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 10.0f, current_x + 6.0f, y + 10.0f, current_x, y + 12.0f, current_x + 6.0f, y + 12.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 4.0f, y + 5.0f, current_x + 6.0f, y + 5.0f, current_x + 4.0f, y + 12.0f, current_x + 6.0f, y + 12.0f, 0, color);
    current_x += spacing;
    
    // y
    gsKit_prim_quad(gsGlobal, current_x, y + 5.0f, current_x + char_size, y + 5.0f, current_x, y + 7.0f, current_x + char_size, y + 7.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 4.0f, y + 5.0f, current_x + 6.0f, y + 5.0f, current_x + 4.0f, y + 12.0f, current_x + 6.0f, y + 12.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 7.0f, current_x + 6.0f, y + 7.0f, current_x, y + 9.0f, current_x + 6.0f, y + 9.0f, 0, color);
    current_x += spacing + 4.0f;
    
    // S
    gsKit_prim_quad(gsGlobal, current_x, y + 5.0f, current_x + 8.0f, y + 5.0f, current_x, y + 7.0f, current_x + 8.0f, y + 7.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 8.0f, current_x + 8.0f, y + 8.0f, current_x, y + 10.0f, current_x + 8.0f, y + 10.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 11.0f, current_x + 8.0f, y + 11.0f, current_x, y + 13.0f, current_x + 8.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 5.0f, current_x + 2.0f, y + 5.0f, current_x, y + 10.0f, current_x + 2.0f, y + 10.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 6.0f, y + 8.0f, current_x + 8.0f, y + 8.0f, current_x + 6.0f, y + 13.0f, current_x + 8.0f, y + 13.0f, 0, color);
    current_x += spacing + 2.0f;
    
    // o
    gsKit_prim_quad(gsGlobal, current_x, y + 7.0f, current_x + 6.0f, y + 7.0f, current_x, y + 9.0f, current_x + 6.0f, y + 9.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 11.0f, current_x + 6.0f, y + 11.0f, current_x, y + 13.0f, current_x + 6.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 7.0f, current_x + 2.0f, y + 7.0f, current_x, y + 13.0f, current_x + 2.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 4.0f, y + 7.0f, current_x + 6.0f, y + 7.0f, current_x + 4.0f, y + 13.0f, current_x + 6.0f, y + 13.0f, 0, color);
    current_x += spacing;
    
    // f
    gsKit_prim_quad(gsGlobal, current_x, y + 3.0f, current_x + 2.0f, y + 3.0f, current_x, y + 13.0f, current_x + 2.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 3.0f, current_x + 6.0f, y + 3.0f, current_x, y + 5.0f, current_x + 6.0f, y + 5.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 7.0f, current_x + 4.0f, y + 7.0f, current_x, y + 9.0f, current_x + 4.0f, y + 9.0f, 0, color);
    current_x += spacing;
    
    // t
    gsKit_prim_quad(gsGlobal, current_x, y + 5.0f, current_x + 2.0f, y + 5.0f, current_x, y + 13.0f, current_x + 2.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 11.0f, current_x + 6.0f, y + 11.0f, current_x, y + 13.0f, current_x + 6.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x - 2.0f, y + 7.0f, current_x + 4.0f, y + 7.0f, current_x - 2.0f, y + 9.0f, current_x + 4.0f, y + 9.0f, 0, color);
    current_x += spacing;
    
    // w
    gsKit_prim_quad(gsGlobal, current_x, y + 7.0f, current_x + 2.0f, y + 7.0f, current_x, y + 13.0f, current_x + 2.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 3.0f, y + 9.0f, current_x + 5.0f, y + 9.0f, current_x + 3.0f, y + 13.0f, current_x + 5.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 6.0f, y + 7.0f, current_x + 8.0f, y + 7.0f, current_x + 6.0f, y + 13.0f, current_x + 8.0f, y + 13.0f, 0, color);
    current_x += spacing + 2.0f;
    
    // a
    gsKit_prim_quad(gsGlobal, current_x, y + 7.0f, current_x + 6.0f, y + 7.0f, current_x, y + 9.0f, current_x + 6.0f, y + 9.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 10.0f, current_x + 6.0f, y + 10.0f, current_x, y + 12.0f, current_x + 6.0f, y + 12.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 7.0f, current_x + 2.0f, y + 7.0f, current_x, y + 13.0f, current_x + 2.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 4.0f, y + 7.0f, current_x + 6.0f, y + 7.0f, current_x + 4.0f, y + 13.0f, current_x + 6.0f, y + 13.0f, 0, color);
    current_x += spacing;
    
    // r
    gsKit_prim_quad(gsGlobal, current_x, y + 7.0f, current_x + 2.0f, y + 7.0f, current_x, y + 13.0f, current_x + 2.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 7.0f, current_x + 6.0f, y + 7.0f, current_x, y + 9.0f, current_x + 6.0f, y + 9.0f, 0, color);
    current_x += spacing;
    
    // e
    gsKit_prim_quad(gsGlobal, current_x, y + 7.0f, current_x + 6.0f, y + 7.0f, current_x, y + 9.0f, current_x + 6.0f, y + 9.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 10.0f, current_x + 6.0f, y + 10.0f, current_x, y + 12.0f, current_x + 6.0f, y + 12.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 11.0f, current_x + 6.0f, y + 11.0f, current_x, y + 13.0f, current_x + 6.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 7.0f, current_x + 2.0f, y + 7.0f, current_x, y + 13.0f, current_x + 2.0f, y + 13.0f, 0, color);
    current_x += spacing + 4.0f;
    
    // R
    gsKit_prim_quad(gsGlobal, current_x, y + 5.0f, current_x + 2.0f, y + 5.0f, current_x, y + 13.0f, current_x + 2.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 5.0f, current_x + 6.0f, y + 5.0f, current_x, y + 7.0f, current_x + 6.0f, y + 7.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 9.0f, current_x + 6.0f, y + 9.0f, current_x, y + 11.0f, current_x + 6.0f, y + 11.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 4.0f, y + 5.0f, current_x + 6.0f, y + 5.0f, current_x + 4.0f, y + 11.0f, current_x + 6.0f, y + 11.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 3.0f, y + 11.0f, current_x + 6.0f, y + 11.0f, current_x + 4.0f, y + 13.0f, current_x + 6.0f, y + 13.0f, 0, color);
    current_x += spacing;
    
    // a
    gsKit_prim_quad(gsGlobal, current_x, y + 7.0f, current_x + 6.0f, y + 7.0f, current_x, y + 9.0f, current_x + 6.0f, y + 9.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 10.0f, current_x + 6.0f, y + 10.0f, current_x, y + 12.0f, current_x + 6.0f, y + 12.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 7.0f, current_x + 2.0f, y + 7.0f, current_x, y + 13.0f, current_x + 2.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x + 4.0f, y + 7.0f, current_x + 6.0f, y + 7.0f, current_x + 4.0f, y + 13.0f, current_x + 6.0f, y + 13.0f, 0, color);
    current_x += spacing;
    
    // t
    gsKit_prim_quad(gsGlobal, current_x, y + 5.0f, current_x + 2.0f, y + 5.0f, current_x, y + 13.0f, current_x + 2.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x, y + 11.0f, current_x + 6.0f, y + 11.0f, current_x, y + 13.0f, current_x + 6.0f, y + 13.0f, 0, color);
    gsKit_prim_quad(gsGlobal, current_x - 2.0f, y + 7.0f, current_x + 4.0f, y + 7.0f, current_x - 2.0f, y + 9.0f, current_x + 4.0f, y + 9.0f, 0, color);
}

int main(int argc, char *argv[])
{
    GSGLOBAL *gsGlobal;
    
    // Initialize RPC and file loading
    SifInitRpc(0);
    
    printf("PS2 Hello World - Initializing graphics and audio...\n");
    
    // Initialize DMA
    dmaKit_init(D_CTRL_RELE_OFF, D_CTRL_MFD_OFF, D_CTRL_STS_UNSPEC, 
                D_CTRL_STD_OFF, D_CTRL_RCYC_8, 1 << DMA_CHANNEL_GIF);
    dmaKit_chan_init(DMA_CHANNEL_GIF);
    
    // Initialize gsKit
    gsGlobal = gsKit_init_global();
    
    // Set video mode
    gsGlobal->Mode = GS_MODE_NTSC;
    gsGlobal->Interlace = GS_INTERLACED;
    gsGlobal->Field = GS_FIELD;
    gsGlobal->Width = SCREEN_WIDTH;
    gsGlobal->Height = SCREEN_HEIGHT;
    
    // Initialize the screen
    gsKit_init_screen(gsGlobal);
    
    // Set up drawing environment
    gsKit_mode_switch(gsGlobal, GS_ONESHOT);
    
    printf("Graphics initialized successfully!\n");
    printf("Enhanced Hello World PS2 by SoftwareRat!\n");
    
    // Main display loop
    int frame_count = 0;
    float time = 0.0f;
    
    while(1)
    {
        // Clear the screen with a dark blue background
        gsKit_clear(gsGlobal, GS_SETREG_RGBAQ(0x00, 0x10, 0x30, 0x80, 0x00));
        
        // Draw main title "HELLO WORLD" in the center
        draw_text_hello_world(gsGlobal, 80.0f, 180.0f, GS_YELLOW);
        
        // Draw "PS2" subtitle
        draw_text_ps2(gsGlobal, 280.0f, 230.0f, GS_CYAN);
        
        // Draw credits
        draw_text_by_softwarerat(gsGlobal, 220.0f, 320.0f, GS_WHITE);
        
        // Add some animated decorative elements
        time += 0.1f;
        
        // Animated corner stars
        for(int i = 0; i < 4; i++) {
            float star_x = (i % 2) * 580.0f + 30.0f;
            float star_y = (i / 2) * 400.0f + 40.0f;
            float pulse = sin(time + i) * 0.5f + 0.5f;
            u64 star_color = GS_SETREG_RGBAQ((int)(255 * pulse), (int)(255 * pulse), 255, 0x80, 0x00);
            
            // Draw star shape using quads
            gsKit_prim_quad(gsGlobal, star_x - 8.0f, star_y - 2.0f, star_x + 8.0f, star_y - 2.0f, 
                           star_x - 8.0f, star_y + 2.0f, star_x + 8.0f, star_y + 2.0f, 0, star_color);
            gsKit_prim_quad(gsGlobal, star_x - 2.0f, star_y - 8.0f, star_x + 2.0f, star_y - 8.0f, 
                           star_x - 2.0f, star_y + 8.0f, star_x + 2.0f, star_y + 8.0f, 0, star_color);
        }
        
        // Animated bottom border
        float border_y = 450.0f;
        for(int i = 0; i < 20; i++) {
            float x = i * 32.0f;
            float wave = sin(time + i * 0.5f) * 5.0f;
            u64 border_color = GS_SETREG_RGBAQ(100, 100, 255, 0x80, 0x00);
            gsKit_prim_quad(gsGlobal, x, border_y + wave, x + 20.0f, border_y + wave, 
                           x, border_y + wave + 8.0f, x + 20.0f, border_y + wave + 8.0f, 0, border_color);
        }
        
        // Sync and display the frame
        gsKit_sync_flip(gsGlobal);
        gsKit_queue_exec(gsGlobal);
        
        frame_count++;
        
        // Print status to console every 60 frames
        if(frame_count % 60 == 0) {
            printf("Hello World PS2 by SoftwareRat - Frame: %d\n", frame_count);
        }
        
        // Control frame rate
        for(volatile int i = 0; i < 50000; i++) {
            asm("nop");
        }
    }
    
    // Cleanup (never reached in this example)
    gsKit_deinit_global(gsGlobal);
    
    return 0;
}