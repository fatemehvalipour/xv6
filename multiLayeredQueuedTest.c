#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

void childFunction(int childNumber)
{
    for (int j = 0; j < 200; j++)
    {
        printf(1, "%d\n", childNumber);
    }
    exit();
}

int main()
{
    changepolicy(3);
    for (int i = 0; i < 40; i++)
    {
        int pid = fork();
        if (pid == 0 && i < 10)
        {
            setGroup(1);
            childFunction(i);
        }
        else if (pid == 0 && i >= 10 && i < 20)
        {
            setGroup(2);
            setpriority((int)(((20 - i)/9)*6));
            childFunction(i);
        }
        else if (pid == 0 && i >= 20 && i < 30)
        {
            setGroup(3);
            setpriority((int)(((30 - i)/9)*6));
            childFunction(i);
        }
        else if (pid == 0 && i >= 30 && i < 40)
        {
            setGroup(4);
            childFunction(i);
        }
    }
    sleep(2500);
    printf(2, "average waiting time : %d, average turn around time : %d\n", getAvgWaitingTime(), getAvgTurnaroundTime());
    exit();
}