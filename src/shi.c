#include <stdio.h>

#define MEMORY_SIZE 30000
#define SOURCE_SIZE 10000

char memory[MEMORY_SIZE] = {0};
char source[SOURCE_SIZE] = {0};
char instructions[SOURCE_SIZE] = {0};
char *src = source;
char *mem = memory;
char *instr = instructions;
size_t command = 0;
size_t loop = 0;

void msg(char *msg)
{
    fprintf(stderr, "| %s", msg);
}

void shi()
{
    // Convert into numeric instructions
    while (*src)
    {
        switch (*src)
        {
            case '\'': command++; break;
            case ' ' :
            case '\n':
                if (command <= 8) *instr = command;
                else msg("Hmm... I don't understand.\n");

                instr++;                
                command = 0;
                break;
            default: msg("Nice try...\n"); break;
        }
        src++;
    }

    instr = instructions; // move back to 1 instruction
    while (*instr)
    {
        switch (*instr)
        {
            case 1: mem++; break;
            case 2: mem--; break;
            case 3: ++*mem; break;
            case 4: --*mem; break;
            case 5: fputc(*mem, stdout); break;
            case 6: scanf(" %c", mem); break;
            case 7: 
                if (*mem) break; // if not 0
                loop = 1;
                while (loop)
                {
                    instr++;
                    if (*instr == 7) loop++;
                    if (*instr == 8) loop--;
                }
                break;
            case 8: 
                loop = 1;
                while (loop)
                {
                    instr--;
                    if (*instr == 7) loop--;
                    if (*instr == 8) loop++;
                }
                instr--;
                break;
        }

        instr++;
    }
}


int main(int argc, char *argv[])
{   
    if(argc == 2)
    {
        FILE *file = fopen(argv[1], "r");
    
        if(file == NULL)
        {
            printf("Bruh don't give that NULL shit...\n");
            return 0;
        }

        fread(source, 1, SOURCE_SIZE, file);
        fclose(file);
        shi();
    }
    else
    {
        printf("Ah yes what a nice day it is...\n");
    }

    return 0;
}