#include <stdio.h>
#include <unistd.h>     // fork(), getpid()를 위해 반드시 필요
#include <sys/types.h>  // pid_t 타입을 안전하게 쓰기 위해 권장

int main() {
    int pid = fork();
    
    if (pid < 0) {
        // 에러 처리
        return 1;
    } else if (pid == 0) {
        // 자식 프로세스 코드
        int num = getpid();
        printf("자식 PID: %d\n", num);
    } else {
        // 부모 프로세스 코드
        printf("부모가 만든 자식 PID: %d\n", pid);
    }
    
    return 0;
}

