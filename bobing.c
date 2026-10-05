/*Written by djw*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/select.h>

struct record
{
	int count1;
	int count2;
	int count3;
	int count4;
	int count5;
	int count6;
};

void msleep(int ms);
void compute_level(struct record result,int goal[]);

int number = 6;

int main()
{
	static int count = 0;
	int random;
	int i;
	int goal[6];
	struct record result = {0,0,0,0,0,0};
	//init
		
	printf("Bobing...\n");
	for (i =0;i < number;i++)
	{
		srand((unsigned)time(NULL));
		random = rand() % 6 + 1;//1-6
		msleep(1000);//I noticed that if it less than 1000ms,or 500ms ,the result will appear many [same number],which worth noticing
		//bobing

		goal[i] = random;
		printf("%d ",random);
		count++;
		if (count == number)
		{
			putchar('\n');
			count = 0;
		}
		//record and stop
		
	}
	
	compute_level(result,goal);
}

void msleep(int ms)
{
	struct timeval tv;
	tv.tv_sec = ms/1000;
	tv.tv_usec = (ms % 1000) * 1000;
	select(0,NULL,NULL,NULL,&tv);
}

void compute_level(struct record result,int goal[])
{
	for (int i = 0;i < number;i++)
	{
		switch (goal[i])
		{
			case 1:
			{
				result.count1 += 1;
				break;
			}
			case 2:
			{
				result.count2 += 1;
				break;
			}
			case 3:
			{
				result.count3 += 1;
				break;
			}
			case 4:
			{
				result.count4 += 1;
				break;
			}
			case 5:
			{
				result.count5 += 1;
				break;
			}
			case 6:
			{
				result.count6 += 1;
				break;
			}
		}
	}
	if (result.count4 == 4 && result.count1 == 2)
	{
		printf("This is the rarest event.I couldn't believe that it happened just now.\n");
		exit(0);
	}
	else if (result.count4 == 6)
	{
		printf("You have six fours,caught the second.\n");
		exit(0);
	}
	else if (result.count1 == 6)
	{
		printf("You have six ones,unbelieveable!\n");
		exit(0);
	}
	else if (result.count2 == 6 || result.count3 == 6 || result.count5 == 6 || result.count6 == 6)
	{
		printf("Lucky you \"all the same\".\n");
		exit(0);
	}
	else if (result.count4 == 5)
	{
		printf("You have five fours,good job!\n");
		exit(0);
	}
	else if (result.count1 == 5 || result.count2 == 5 || result.count3 == 5 || result.count5 == 5 || result.count6 == 5)
	{
		printf("Obviously,it is rare.\n");
		exit(0);
	}
	else if (result.count4 == 4)
	{
		printf("May the \"fourth\" be with you.\n");
		exit(0);
	}
	else if (result.count1 == 1 && result.count2 == 1 && result.count3 == 1 && result.count4 == 1 && result.count5 == 1 && result.count6 == 1)
	{
		printf("Wait,count them carefully...\n");
		msleep(1200);
		printf("Congratulations!\n");
		exit(0);
	}
	else if (result.count4 == 3)
	{
		printf("ABC.OneTwoThree.DoReMi.\n");
		exit(0);
	}
	else if (result.count1 == 4 || result.count2 == 4 || result.count3 == 4 || result.count5 == 4 || result.count6 == 4)
	{
		printf("Goal");
		if (result.count4 > 0)
		{
			printf(" with %d fours.\n",result.count4);
		}
		else
		{
			printf("!\n");
		}
		exit(0);
	}
	else if (result.count4 == 2)
	{
		printf("You have 2 fours.\n");
		exit(0);
	}
	else if (result.count4 == 1)
	{
		printf("You have 1 fours.\n");
		exit(0);
	}
	else
	{
		printf("Try again.\n");
		exit(0);
	}
}

