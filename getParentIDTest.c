#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    fork();
    wait();
    printf(2, "This is proccess %d and the parent id is %d\n", getpid(), getparentid());
    exit();
}