#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 

int main(void)
{
	pid_t pid, ppid; 
	uid_t uid, euid, suid; 
	gid_t gid, egid, sgid; 
	int ret; 

	printf("pid=%d ppid=%d\n", (int)getpid(), (int)getppid()); 
	
	ret = getresuid(&uid, &euid, &suid); 
	if(ret == -1){
		fprintf(stderr, "getresuid:%s\n", strerror(errno)); 
		exit(EXIT_FAILURE); 
	}
	printf("uid=%d euid=%d suid=%d\n", (int)uid, (int)euid, (int)suid); 

	ret = getresgid(&gid, &egid, &sgid); 
	if(ret == -1){
		fprintf(stderr, "getresgid:%s\n", strerror(errno)); 
		exit(EXIT_FAILURE); 
	}
	printf("gid=%d egid=%d sgid=%d\n", (int)gid, (int)egid, (int)sgid); 

	return(EXIT_SUCCESS); 
}