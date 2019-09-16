#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
int main()
{
	int fd = 0;
	key_t key;
	int semid;
	int ret;
	struct sembuf sops = {0};
	/*创建键值*/
    key = ftok(".",1);
	
	/*创建并打开信号量*/
    semid = semget(key,1,IPC_CREAT);
	if(semid == -1)
	{
		printf("%m");
		//perror("创建信号量失败:");
		
	}
   
    fd = open("board.txt",O_RDWR|O_APPEND);
    
	/*获取信号量*/
	
	sops.sem_num = 0;
	sops.sem_op = -1;
	
	ret = semop(semid,&sops,1);
	if(ret == -1)
	{
		printf("%d",errno);
		perror("获取信号量失败:");
	}
	
    write(fd,"hello,",6);
    
    sleep(10);
    
    write(fd,"world",5);
    
	
	/*释放信号量*/
	
	sops.sem_num = 0;
	sops.sem_op = 1;
	
	ret = semop(semid,&sops,1);
	if(ret == -1)
	{
		printf("%d",errno);
		//perror("释放信号量失败:");
	}
    close(fd);
    
    return 0;
    

}