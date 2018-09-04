#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>
#include "graphics.h"

class game_setup
{
	private:
		int row, col;
		int x_blocks,y_blocks;
		int gd , gm;
	public:
		int scale;
		game_setup()
		{
			scale=10;
			gd=DETECT;

		}

		void draw_canvas()
		{
			initgraph(&gd,&gm,"c://tc//bgi");

			col=getmaxx()-(getmaxx()%scale);
			row=getmaxy()-(getmaxy()%scale);
			col=col+2;
			row=row+2;
		}

		void close_canvas()
		{
			closegraph();
		}

		int get_width()
		{
			return col;
		}
		int get_height()
		{
			return row;
		}

		~game_setup()
		{
		}
};