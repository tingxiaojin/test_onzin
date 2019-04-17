#include "stm32_ub_vga_screen.h"


/*
 * note : tekent een reeks pixels achtereen op het scherm
 * param:	startx= begin breedte van de reeks pixels
 * 		  	starty= begin hoogte van de reeks pixels
 * 		  	eindx = eind breedte van de reeks pixels
 * 		  	eindy = eind hoogte van de reeks pixels
 */
void drawLine (int startx, int starty, int eindx, int eindy, unsigned char kleur)
{
	unsigned int x, y; 	// pixel waardes langslopen
	float a, dx, dy;	// coëfficient berekening

	dx = eindx - startx;
	dy = eindy - starty;

	if ((dy)&&(dx))
		a = dy/dx;
	else
		a = 0;

	if (a<=1)
		for (x=startx; x<eindx; x++)
		{
		  y = (int)(a*(x-startx));
		  UB_VGA_SetPixel(x,y,kleur);
		}
	else
		for (y=starty; y<eindy; y++)
		{
		  x = (int)((1/a)*(y-starty));
		  UB_VGA_SetPixel(x,y,kleur);
		}
}


void drawFrame(int startx, int starty, int breedte, int lengte, unsigned char kleur)
{
	drawLine(startx, starty, startx, lengte+starty, kleur);
	drawLine(startx, lengte+starty, breedte+startx, lengte+starty, kleur);
	drawLine(startx, starty, breedte+startx, lengte+starty, kleur);
	drawLine(startx, starty, breedte+startx, lengte+starty, kleur);
}


//void drawRect(int startx, int starty, int breedte, int lengte, unsigned char kleur)
//{
//
//}



