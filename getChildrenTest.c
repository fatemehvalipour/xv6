#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

int main()
{
    wait();
    for(int i = 0; i < 20; i++)
    {
        if(fork() == 0)
        {
            exit();
        }
    }
    wait();
    printf(2, "PID: %d, parentID: %d, children: ", getpid(), getparentid());
    getChildren(getpid());
    exit();
}
