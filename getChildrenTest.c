#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"
#include "defs.h"

int main()
{
    fork();
    wait();
    printf(2, "PID: %d, parentID: %d, children: ", getpid(), getparentid());
    int *arr = getChildren(getparentid());
    for(int i = 0 ; i < NPROC; i++){
        if (*(arr + i) != 0)
        {
            printf(1, "%d/", *(arr + i));
        }
    }
    printf(0, "\n");
    exit();
}