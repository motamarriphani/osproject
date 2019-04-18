#include<stdio.h>
#include<conio.h>
#include<string.h>

struct process
{
	int burst_time;
	int arrival_time;
	int waiting_time;
	int turn_around_time;
	char name[3];
};

int main()
{
	 int i,j,n,burst=0;
	 float average_waiting_time=0,average_turn_around_time=0;
	 printf("\nPlease enter the number of process ");
	 scanf("%d",&n);
	 struct process p[n];
	 for(i=0;i<n;i++)
	 {
	 	printf("\nPlease enter the name of process upto two characters : ");
	 	fflush(stdin);
	    gets(p[i].name);
		printf("\nPlease enter the arrival time of the process : ");
		scanf("%d",&p[i].arrival_time);	 
	    printf("\nburst time of the process : ");
	    scanf("%d",&p[i].burst_time);
	    p[i].turn_around_time = p[i].burst_time;
	    if(p[i].burst_time>burst)
	    burst=p[i].burst_time;
	 }
	 
	int bur=burst,flag=0,arr,count=0; 
	 for(i=0;i>=0;i++)
	 {
	 	int c=0;
	 	for(j=0;j<n;j++)
	 	{
	 		if(i>=p[j].arrival_time && p[j].burst_time>0)
	 		{
				if(burst>=p[j].burst_time)
				{
					burst = p[j].burst_time;
					arr=p[j].arrival_time;
				}
			}
		}
		for(j=0;j<n;j++)
		{
			if(burst==p[j].burst_time&&arr>p[j].arrival_time)
			{
				arr=p[j].arrival_time;
			}
		}
		printf("%-2d - %-2d ",i,i+1);
		for(j=0;j<n;j++)
		{
			if(p[j].arrival_time==arr && p[j].burst_time==burst)
			{
				p[j].burst_time--;
				printf("Process %s",p[j].name);
				if(p[j].burst_time==0)
				{
					burst=p[j].turn_around_time;
					p[j].turn_around_time=i+1-p[j].arrival_time;
					p[j].waiting_time = p[j].turn_around_time - burst;
					count++;
				}
				break;
			}
		}
		printf("\n");
		if(count==n)
		break;
		burst = bur;
	 }
	 for(i=0;i<n;i++)
	 {
	 	printf("name = %s waiting time = %d turn around time = %d\n",p[i].name,p[i].waiting_time,p[i].turn_around_time);
	 	average_waiting_time=average_waiting_time+p[i].waiting_time;
	 	average_turn_around_time=average_turn_around_time+p[i].turn_around_time;
	 }	
	 printf("\nThe average waiting time is : %f",average_waiting_time/n);
	 printf("\nThe average turn around time is : %f ",average_turn_around_time/n);
}

