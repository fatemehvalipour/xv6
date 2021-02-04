#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

void printState(int index)
{
    printf(2, "/%d/ : /%d/\n", getpid(), index);
}

void childFunction()
{
    for (int i = 0; i < 1000; i++)
    {
        printState(i);
    }
    int burstTime = getRunningTime();
    int waitingTime = getReadyTime() + getSleepingTime();
    printf(4, "<%d> CBT : /%d/, WaitingTime : /%d/, TurnAroundTime : /%d/\n", getpid(), burstTime, waitingTime, burstTime + waitingTime);
    exit();
}

int main()
{
    changepolicy(1);
    for (int i = 0; i < 10; i++)
    {
        int testFork = fork();
        wait();
        if (testFork == 0)
        {
            wait();
            childFunction();
        }
    }
    exit();
}