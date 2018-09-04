#include <iostream.h>
#include "graphics.h"
class food
{
	private:
		int f_pos[4],arr[8],maxx,maxy,x_block,y_block;

	public:
		food()
		{
		}
		int flag;
void place_food(int flag1,int scale)
{
	int numx = maxx/scale;
	int numy = maxy/scale;
	if(flag1==1)
	{
		this->flag=0;
		 do
		 {
			f_pos[0]=(((rand()%numx)+1)*scale)+1;
			f_pos[1]=(((rand()%numy)+1)*scale)+1;
			f_pos[2]=f_pos[0]+scale-1;
			f_pos[3]=f_pos[1]+scale-1;
		 }while(f_pos[2]>maxx || f_pos[3]>maxy);
	}
 //	setfillstyle(LTSLASH_FILL,4);
	setcolor(4);
	//outtextxy(posx,posy,"o");
	// rectangle(f_pos[0],f_pos[1],f_pos[2],f_pos[3]);

			arr[0]=f_pos[0];
			arr[1]=f_pos[1];
			arr[2]=f_pos[0]+scale-1;
			arr[3]=f_pos[1];
			arr[4]=f_pos[2];
			arr[5]=f_pos[3];
			arr[6]=f_pos[2]-scale+1;
			arr[7]=f_pos[3];
			fillpoly(4,arr);
}
void reset_food()
{
	setcolor(0);
	fillpoly(4,arr);
}

int * get_pos()
{
	int * f_pos;
	f_pos=this->f_pos;
	return f_pos;
}

void set_flag(int a)
{
	this->flag=a;
}

void set_max(int maxx, int maxy)
{

	this->maxx=maxx-2;
	this->maxy=maxy-2;

 //	x_block=this->maxx/7;
 //	y_block=this->maxy/7;

}

		~food()
		{
		}
};