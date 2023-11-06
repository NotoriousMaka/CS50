#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Enter you name: ");
    printf("Hello, %s!\n", name);
}