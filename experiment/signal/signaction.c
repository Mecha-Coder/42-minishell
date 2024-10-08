#include <signal.h>
#include <stdio.h>

void handler(int sig)
{
    printf("Caught signal %d\n", sig);
}

int main() 
{
    // signal(SIGINT, handler);
    
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);
    while (1) {;}
    return 0;
}