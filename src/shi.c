#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *memory; char *mem;
char *source; char *src;
char *instructions; char *instr; // same size as source
size_t loop = 0;

void msg(char *msg)
{
    fprintf(stderr, "| %s", msg);
}

void shi()
{
    // Convert into numeric instructions
    size_t command = 0;
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
        src++; // next char
    }

    instr = instructions; // move back to 1 instruction
    while (*instr) // run numeric instructions
    {
        switch (*instr)
        {
            case 1: mem++; break; // increase memory pointer
            case 2: mem--; break; // decrease memory pointer
            case 3: ++*mem; break; // increase value at memory pointer
            case 4: --*mem; break; // decrease value at memory pointer
            case 5: fputc(*mem, stdout); break; // print value at memory pointer as char
            case 6: scanf(" %c", mem); break; // read char from user
            case 7: // beginning of loop
                if (*mem) break; // if not 0
                loop = 1;
                while (loop)
                {
                    instr++; // increase instruction pointer
                    if (*instr == 7) loop++; // entered loop
                    if (*instr == 8) loop--; // left loop
                }
                break;
            case 8: // end of loop
                loop = 1;
                while (loop)
                {
                    instr--; // decrease instruction pointer
                    if (*instr == 7) loop--; // entered loop
                    if (*instr == 8) loop++; // left loop
                }
                instr--; // decrease instruction pointer because it gets increased at the end of the loop
                break;
        }

        instr++; // increase instruction pointer
    }
}


int main(int argc, char *argv[])
{
    // Read file
    if(argc == 2)
    {
        FILE *file = fopen(argv[1], "r");
    
        if(file == NULL)
        {
            printf("Bruh don't give that NULL shit...\n");
            return 0;
        }
        
        fseek(file, 0, SEEK_END); // seek to end of file
        size_t size = ftell(file); // get current file pointer
        fseek(file, 0, SEEK_SET); // seek back to beginning of file

        source = (char*)calloc(size, sizeof(char));
        src = source;
        instructions = (char*)calloc(size, sizeof(char));
        instr = instructions;
        memory = (char*)calloc(size*2, sizeof(char));
        mem = memory;

        fread(source, 1, size, file);
        fclose(file);
        shi();
    }
    else
    {
        printf("Ah yes what a nice day it is...\n");
    }

    return 0;
}
