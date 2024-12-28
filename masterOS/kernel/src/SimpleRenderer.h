#pragma once
#include "mat.h"
#include "Framebuffer.h"
#include "simpleFonts.h"

class SimpleRenderer {
    public:
    void Print(const char* str);
    void putChar(char chr, unsigned int xOff, unsigned int yOff);
    SimpleRenderer(Framebuffer* targetFramebuffer, PSF1_FONT* psf1_Font);
    Point CursorPosition;
    Framebuffer* TargetFramebuffer;
    PSF1_FONT* PSF1_Font;
    unsigned int color;
};