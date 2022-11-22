#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <errno.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <linux/cdrom.h> 
#include <sys/ioctl.h> 

int main (int argc, char *argv[]) 
{
	int fd, ret; 

	if (argc != 2) 
	{
		fprintf (stderr, "usage error:%s cdrom_device_file_name\n", 
			 argv[0]);
		exit (EXIT_FAILURE); 
	}

	fd = open (argv[1], O_RDONLY | O_NONBLOCK); 
	if (fd == -1) 
	{
		fprintf (stderr, "open:%s:%s\n", argv[1], strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	ret = ioctl (fd, CDROMEJECT); 
	if (ret == -1) 
	{
		fprintf (stderr, "ioctl:%s:%s\n", argv[1], strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	if (close (fd) == -1) 
	{
		fprintf (stderr, "close:%s:%s\n", argv[1], strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	exit (EXIT_SUCCESS); 
}
