#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
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
	
    fd = open("board.txt",O_RDWR|O_APPEND);
    
	/*获取信号量*/
	
	sops.sem_num = 0;
	sops.sem_op = -1;
	
	ret = semop(semid,&sops,1);
	if(ret == -1)
	{
		perror("获取信号量失败:");
	}
	
    write(fd,"12345,",6);
    
	/*释放信号量*/
	
	sops.sem_num = 0;
	sops.sem_op = 1;
	
	ret = semop(semid,&sops,1);
	if(ret == -1)
	{
		perror("释放信号量失败:");
	}
    
    close(fd);
    
    return 0;
    

}