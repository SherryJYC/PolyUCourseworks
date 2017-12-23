#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>

#define LED_OFF 0
#define LED_ON  1


void led1_ctl(char* i)
{
	int  fd;
	char input;

	fd = open("/dev/pwm_buzzer", O_WRONLY);
	if(fd == -1)
	{
		printf("Fail to open device lab5_1!\n");
		goto finish;	
	}

	write(fd, i, 1);	
finish:	
	close(fd);	
}

int main(void)
{
	int  key_fd;
	int  buzzer_fd;
	char current_values[1];
	int  ret;
	
	key_fd = open("/dev/lab6", O_RDONLY);

	char beep;
	while(1)
	{
		ret = read(key_fd, current_values, sizeof(current_values) );
		if (ret != sizeof(current_values) ) 
		{
			printf("Read key error:\n");
			goto finish;
		}
		if(current_values[0] == '1')
		{
			beep = '1';
			led1_ctl(&beep);
		}
		else if(current_values[0] == '2')
		{
			beep = '2';		
			led1_ctl(&beep);
		} 
		else if(current_values[0] == '3')
		{
			beep = '3';
			led1_ctl(&beep);
		} 
		else if(current_values[0] == '4')
		{
			beep = '0';
			led1_ctl(&beep);
		}		
	}	
	
finish:		
	close(key_fd);	
	return 0;
}
