#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_getparentid(void)
{
  return getparentid();
}

int *
sys_getChildren(void)
{
  int pid;
  argptr(0, (void*) &pid, sizeof(pid));
  return getChildren(pid);
}

int
sys_setpriority(void)
{
  int value;
  if (argint(0, &value) < 0)
  {
    return -1;
  }
  
  if (value < 1 || value > 6)
  {
    value = 5;
  }
  
  return setpriority(value);
}

int
sys_changepolicy(void)
{
  int value;
  if (argint(0, &value) < 0)
  {
    return -1;
  }
  
  return changepolicy(value);
}

int
sys_getSystemCallCount(void)
{
  int systemCallID;
  if(argint(0, &systemCallID) < 0){
    return -1;
  }
  return myproc()->num_of_systemCall[systemCallID];

}

int
sys_getCreationTime(void)
{
  return myproc()->creationTime;
}

int
sys_getTerminationTime(void)
{
  return myproc()->terminationTime;
}

int
sys_getRunningTime(void)
{
  return myproc()->runningTime;
}

int
sys_getReadyTime(void)
{
  return myproc()->readyTime;
}

int
sys_getSleepingTime(void)
{
  return myproc()->sleepingTime;
}

int
sys_getAvgWaitingTime(void)
{
  return getAvgWaitingTime();
}

int
sys_getAvgTurnaroundTime(void)
{
  return getAvgTurnaroundTime();
}