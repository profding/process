#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int
main(void)
{
    int count = 1;
    pid_t  pid;

    printf("before create son ,parent count is %d\n",count);

    pid = vfork();// 这里是vfork
/*
vfork创建出来的子进程与父进程之间是共享内存区的。
*/
//vfork创造出来的子进程还会导致父进程挂起，除非子进程执行了exit 或者 execve才会唤起父进程。

    if(pid < 0)
    {
         printf("error in fork\n");
         exit (EXIT_FAILURE);
    }else if(0 == pid){
            printf("child process,the count is %d,my pid is %d\n",++count,getpid());
			exit(1);
    }else{
            printf("parent process,the count is %d,my pid is %d\n",count,getpid());
    }
    return EXIT_SUCCESS;
}


