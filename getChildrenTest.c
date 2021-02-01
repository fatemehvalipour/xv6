#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    fork();
    wait();
    printf(2, "PID: %d, parentID: %d, children: \n", getpid(), getparentid());
    int *arr = getChildren(getparentid());
    for(int i = 0 ; i < 64; i++){
        // if(arr[i] == 1){
        //     printf(1, "%d   ", i);
        // }
        
        printf(2, "*(arr + %d) : %d\n", i, *(arr + i));
    }
    exit();
}