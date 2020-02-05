#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int pid,p[2];
	char inbuf[10],outbuf[10];
	if(pipe(p)==-1)
	{
		printf("Pipe not created successfully");
		return 1;
	}
	else
	{
		pid=fork();
		
		if(pid)
		{
			printf("\nIn parent Process:");
			printf("\nEnter the message to be sent to child process");
			scanf("%s",outbuf);
			write(p[1],outbuf,sizeof(outbuf));
			sleep(2);
			printf("\nAfter sleep in parent!");
		}		
		else
		{
			printf("\nIn child process: ");
			read(p[0],inbuf,10);
			printf("\nThe message sent by parent is: %s",inbuf);
		
		}
		
	}

	return 0;
}
