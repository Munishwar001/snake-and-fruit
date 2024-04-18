#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<unistd.h>
using namespace std;
class snakefruit
{
public:
      int height;
	  int width;
	  int snakex[100];
	  int snakey[100];
	  int score;
	  int level;
	  int fruitx,fruity;
	  int x;
	  char ip;
      int gameover;
      int fp;
	snakefruit(int,int);
    void draw();
	void food();
	void input();
	void run();
};
snakefruit::snakefruit(int h,int w)
{
    height=h;
	width=w;
	snakex[0]=height/2;
	snakey[0]=width/2;
	score=0;
	level=1;
	gameover=0;
	x=0;
	fp=0;
}
void snakefruit::draw()
{
   int i,j;
   for(i=0;i<height;i++)
   {     
	for(j=0;j<width;j++)
	{
		if(i==0||i==height-1||j==0||j==width-1)
		{
			cout<<"#";
		}
		else{
			   int flag=0;
				for(int k=0;k<=x;k++)
	          {
	          	if(i==snakex[k]&&j==snakey[k])
	          	{     
	          	     if(k==0)
	          	     {
	          	     	switch(fp)
	          	     	{
	          	     		case 1:
	          	     			cout<<"^";
	          	     			break;
	          	     		case 2:
							   	cout<<"v";
	          	     			break;
	          	     		case 3:
							   cout<<"<";
	          	     			break;
							case 4:
							cout<<">";
	          	     			break;	
						   }
					   }
					   else
	          		    printf("=");
	          		   flag=1;
				  }
			  }
			if(snakex[0]==fruitx &&snakey[0]==fruity)
			{
                food();
				switch(score)
				{
					case 20:
					level=2;
					usleep(200000);
					break;
					case 30:
					level=3;
					usleep(90000);
					 break;
					case 40:
					cout<<endl<<"CONGRATS YOU WIN"<<endl;
					gameover=1;
				}
			}
			if(j==fruity&& i==fruitx)
				 {
				 	cout<<"*";
				 }
			else if(flag==0)
				{ 
				cout<<" ";
		      }
	   }
   }
   cout<<endl;
 }
   cout<<"press w for up"<<endl<<"press a for down"<<endl<<"press s for Left"<<endl<<"press d for up"<<endl;
  cout<<"score="<<score<<endl;
  cout<<"level="<<level<<endl;
}
void snakefruit::input()
{
   if(kbhit())
    	 {
    	 	ip=getch();
			 }
}
void snakefruit::run()
{
	if(level>1)
	{
		for(int k=x-1;k>0;k--)
		 {  
		 	snakex[k]=snakex[k-1];
		 	snakey[k]=snakey[k-1];
		 	if((snakex[0]==snakex[k+1])&&(snakey[0]==snakey[k+1])&&level==3)
		 	{
		 		 cout<<"YOU LOST TRY AGAIN"<<endl;
				 gameover=1;
			 }
		 }
	}
	switch(ip)
		 	{
		 		case 'w':
		 			snakex[0]--;
		 			fp=1;
		 			if(snakex[0]==1)
		 			{ 
						if(level==1)
						{
							snakex[0]=height;
						}
						else{ 
							cout<<"YOU LOST TRY AGAIN"<<endl;
							gameover=1;
						}
					 }
		 			break;
		 		case 's':
		 				snakex[0]++;
		 				fp=2;
		 					if(snakex[0]==height-1)
		 			{
						if(level==1)
						{
							snakex[0]=1;
						}
						else{
							cout<<"YOU LOST TRY AGAIN"<<endl;
							gameover=1;
						}
					 }
		 				break;
		 		case 'a':
		 				snakey[0]--;
		 				fp=3;
		 						if(snakey[0]==1)
		 						{
		 							
									if(level==1)
						               {
							              snakey[0]=height;
						               }
						           else{
							            cout<<"YOU LOST TRY AGAIN"<<endl;
							            gameover=1;
						               }
								 }
		 					break;
		 		case 'd':
		 				snakey[0]++;
		 				fp=4;
		 					if(snakey[0]==height-1)
		 						{
									if(level==1)
						               {
							              snakey[0]=1;
						               }
						           else{
							            cout<<"YOU LOST TRY AGAIN"<<endl;
							            gameover=1;
									
								 }
			                     }
}
}
void snakefruit::food()
{   score++; 
   if(level>1)
    x++;
    fruitx=rand()%(height-2);
	fruity=rand()%(width-2);
}

int main()
{
	int h,w;
	cout<<"Enter the height and width of gameboard"<<endl;
	cin>>h>>w;
	snakefruit s(h,w);
	s.food();
	while (!s.gameover)
	{  system("cls");
		s.draw();
        s.input();
	    s.run();
	    usleep(400000);
	}
}


