#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include "setup.h"
#include "snake.h"
#include "food.h"
#include "graphics.h"

int check_pos(int * s_pos, int * f_pos)
{
	int i;
	for(i=0;i<3;i++)
	{
		if(s_pos[i]!=f_pos[i])
			return 0;
	}
	return 1;
}
int main()
{


	clrscr();
	game_setup setup;
	snake s(setup.scale);
	food f;

	f.flag=1;
 //	int x=1;
// int max,may;
	int ch;
	int line_touched=0;
	setup.draw_canvas();
	int max=setup.get_width();
	int may=setup.get_height();
	f.set_max(max,may);
//	int i=1;
		f.place_food(f.flag,setup.scale);
	//	s.move(setup.scale,max,may);
	while(1)
	{
		while(!kbhit())
		{
			cleardevice();
			setcolor(15);
			rectangle(0,0,max,may);

		 //	setup.draw_canvas();
				f.place_food(f.flag,setup.scale);
			if(check_pos(s.get_pos(),f.get_pos()))
			{
				f.set_flag(1);
				s.eat(f.get_pos());
				f.place_food(f.flag,setup.scale);
			}

			if((line_touched=s.move(setup.scale,max,may))==1)
			{
				break;
			}
			delay(150);
		//	s.reset_snake();
		//	f.reset_food();
		//	if(i==15)
		 //		i=1;
		 //	else
			//	i++;

		}
		if(line_touched==1)
		{
			break;
		}
		ch=getch();
		if(ch=='0')
			exit(0);


		s.turn(ch);
	}

 //	gotoxy(11,11);
 //	cout<<"Game Over...";
 //	gotoxy(11,12);
 //	cout<<"Press any key to exit.";
 setcolor(15);
	outtextxy(max/2,may/2,"Game Over...");
	outtextxy(max/2,(may/2)+11,"Press any key to exit");

	getch();
	setup.close_canvas();
	return 0;
}