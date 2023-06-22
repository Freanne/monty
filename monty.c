#include "monty.h"


int main(int argc, char *argv[])
{
const char *filename = argv[1];
if (argc != 2)
{
printf("USAGE: monty file\n");
exit(EXIT_FAILURE);
}

executeByteCode(filename);

return 0;   

}
