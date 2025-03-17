#include <stdio.h>
#include <stdlib.h>

int main() {
    // Echo the current username
    printf("Current user: ");
    system("whoami");

    // Display the content of the README.md file
    printf("\nContents of ../README.md:\n");
    system("cat ../README.md");

    return 0;
}
