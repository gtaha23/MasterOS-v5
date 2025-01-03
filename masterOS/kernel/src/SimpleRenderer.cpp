#include "SimpleRenderer.h"

SimpleRenderer::SimpleRenderer(Framebuffer* targetFramebuffer, PSF1_FONT* psf1_Font) {
    TargetFramebuffer = targetFramebuffer;
    PSF1_Font = psf1_Font;
    color = 0xffffffff;
    CursorPosition = {0,0};
}

void SimpleRenderer::Print(const char* str) {
	
	char* chr = (char*)str;
	while(*chr != 0){
		putChar(*chr, CursorPosition.X, CursorPosition.Y);
		CursorPosition.X+=8;
		if (CursorPosition.X + 8 > TargetFramebuffer->Width){
			CursorPosition.X = 0;
			CursorPosition.Y = 16;
		}
		chr++;
	}
}

void SimpleRenderer::putChar(char chr, unsigned int xOff, unsigned int yOff) {
	unsigned int* pixPtr = (unsigned int*)TargetFramebuffer->BaseAddress;
	char* fontPtr = (char*)PSF1_Font->glyphBuffer + (chr * PSF1_Font->psf1_Header->charsize);
	for (unsigned long y = yOff; y < yOff + 16; y++){
		for (unsigned long x = xOff; x < xOff + 8; x++) {
			if ((*fontPtr & (0b10000000 >> (x - xOff))) > 0) {
				*(unsigned int*)(pixPtr + x + (y * TargetFramebuffer->PixelsPerScanLine)) = color;
			}
		}
		fontPtr++;
	}
}