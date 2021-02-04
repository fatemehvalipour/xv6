#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

void printState(int childNumber, int index)
{
    printf(2, "/%d/ : /%d/\n", childNumber, index);
}

void childFunction(int childNumber)
{
    for (int j = 0; j < 250; j++)
    {
        printState(childNumber, j);
    }
    int burstTime = getRunningTime();
    int waitingTime = getReadyTime() + getSleepingTime();
    printf(4, "<%d> CBT : /%d/, WaitingTime : /%d/, TurnAroundTime : /%d/\n", getpid(), burstTime, waitingTime, burstTime + waitingTime);
    exit();
}

int main()
{
    changepolicy(2);
    for (int i = 0; i < 30; i++)
    {
        int pid = fork();
        if (pid == 0 && i < 5)
        {
            setpriority(6);
            childFunction(i);
        }
        else if (pid == 0 && i >= 5 && i < 10)
        {
            setpriority(5);
            childFunction(i);
        }
        else if (pid == 0 && i >= 10 && i < 15)
        {
            setpriority(4);
            childFunction(i);
        }
        else if (pid == 0 && i >= 15 && i < 20)
        {
            setpriority(3);
            childFunction(i);
        }
        else if (pid == 0 && i >= 20 && i < 25)
        {
            setpriority(2);
            childFunction(i);
        }
        else if (pid == 0 && i >= 25 && i < 30)
        {
            setpriority(1);
            childFunction(i);
        }
    }
}