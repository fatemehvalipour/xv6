#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char const *argv[]){
    getparentid();
    getparentid();
    getparentid();
    getparentid();
    getparentid();
    getparentid();
    getparentid();
    int input = atoi(argv[1]);
    printf(1, "number of SystemCalls: %d\n", getSystemCallCount(input));
    exit();
}