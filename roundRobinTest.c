#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

int main()
{
    changepolicy(1);
    for (int i = 0; i < 10; i++)
    {
        if (fork() == 0)
        {
            for (int i = 0; i < 1000; i++)
            {
                printf(1, "%d\n", getpid());
            }
            exit();
        }
    }
    sleep(2500);
    printf(2, "average waiting time : %d, average turn around time : %d\n", getAvgWaitingTime(), getAvgTurnaroundTime());
    exit();
}