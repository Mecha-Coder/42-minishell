#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main() {
    printf("Hello\n");

    // Save the original terminal attributes
    struct termios old_termios;
    tcgetattr(STDIN_FILENO, &old_termios);

    write(2, "Yoyo", sizeof("Yoyo"));

    // Restore the original terminal attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);

    return 0;
}