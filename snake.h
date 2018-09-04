#include <iostream.h>

class snake
{
	private:

		int posx, posy, last_dir,pre_dir;
		int maxx,maxy,scale,arr[8];
		struct snake_body
		{
			snake_body *prev_link;
			int pos[4];
			snake_body *next_link;
		}
		*start;	//first body ,always points to first body

	public:
	snake()
	{
	}
	snake(int scale)
	{
		posx=1;
		posy=1;
		this->scale=scale;

		last_dir=0;

		pre_dir=last_dir;
	 //	maxx=getmaxx();
	 //	maxy=getmaxy();

		start=new snake_body;
		start->pos[0]=posx;
		start->pos[1]=posy;
		start->pos[2]=posx+scale-1;
		start->pos[3]=posy+scale-1;
		start->prev_link=NULL;
		start->next_link=NULL;
	}
int move(int scale, int maxx, int maxy)
{
	snake_body *new_body,*temp,*traverse,*end,*prev_pos ;

		//	call_switch(last_dir,&posx,&posy);
		switch(last_dir)
			{
				case 0:
					posx=posx+scale;//+1;
					break;
				case 1:
					posy=posy-scale;//-1;
					break;
				case 2:
					posx=posx-scale;//-1;
					break;
				case 3:
					posy=posy+scale;//+1;
					break;
			}
 //	prev_pos=start;

		if(start->next_link==NULL && start->prev_link==NULL)
		{
			new_body= new snake_body;
			new_body->pos[0]=posx;
			new_body->pos[1]=posy;
			new_body->pos[2]=posx+scale-1;
			new_body->pos[3]=posy+scale-1;
			new_body->next_link=NULL;
			new_body->prev_link=NULL;
			temp=start;
			start=new_body;
			delete temp;
		}
		else
		{
			temp=start;
			new_body= new snake_body;
			new_body->pos[0]=posx;
			new_body->pos[1]=posy;
			new_body->pos[2]=posx+scale-1;
			new_body->pos[3]=posy+scale-1;
			new_body->next_link=temp;
			temp->prev_link=new_body;
			new_body->prev_link=NULL;
			start=new_body;

			while(temp->next_link !=NULL)
				temp=temp->next_link;

			end=temp;
			end=end->prev_link;
			end->next_link=NULL;
			delete temp;
		}


		setcolor(4);
	 //	setfillstyle(SOLID_FILL,4);
		for(traverse=start;traverse !=NULL; traverse=traverse->next_link)
		{
		 //	int arr[8];

			arr[0]=traverse->pos[0];
			arr[1]=traverse->pos[1];
			arr[2]=traverse->pos[0]+scale-1;
			arr[3]=traverse->pos[1];
			arr[4]=traverse->pos[2];
			arr[5]=traverse->pos[3];
			arr[6]=traverse->pos[2]-scale+1;
			arr[7]=traverse->pos[3];

			fillpoly(4,arr);

			if(traverse->prev_link !=NULL)
			{
				if(traverse->pos[0]==start->pos[0] && traverse->pos[1]==start->pos[1])
					return 1;
			}
		}

		if((start->pos[0]<0) || (start->pos[2]>maxx))
			return 1;
		else if((start->pos[1]<0) || (start->pos[3]>maxy))
			return 1;

	 //	setcolor(0);
		return 0;
}

int * get_pos()
{
	int *pos;
	pos=start->pos;
	return pos;
}

void eat(int * pos)
{
	snake_body *new_body, *temp;
	temp=start;
	new_body= new snake_body;
	new_body->pos[0]=pos[0];
	new_body->pos[1]=pos[1];
	new_body->pos[2]=pos[0]+scale-1;
	new_body->pos[3]=pos[1]+scale-1;
	new_body->next_link=temp;
	temp->prev_link=new_body;
	new_body->prev_link=NULL;
	start=new_body;
}



void turn(int ch)
{
	 switch(ch)
		{
			case 72:   //up
				if(last_dir !=3)
					last_dir=1;
				break;
			case 80:   //down
				if(last_dir !=1)
					last_dir=3;
				break;
			case 77:   //right
				if(last_dir !=2)
					last_dir=0;
				break;
			case 75:   //left
				if(last_dir !=0)
					last_dir=2;
				break;
		}
}
void reset_snake()
{
	snake_body *traverse;
	setcolor(0);
		for(traverse=start;traverse !=NULL; traverse=traverse->next_link)
		{
			fillpoly(4,arr);
		}
}

		~snake()
		{
		}

};
