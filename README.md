# Shi
 Welcome to my very own programming language... (Heavily inspired by BrainF**k)<br /> 
 Even if it is a joke it can do basically every task you can imagine ( given enough time/memory :] ). <br /> 
 With that said, lets get started <br /> 

## Instructions
```shi
'           = increases memory pointer, or moves the pointer to the right 1 block.
''          = decreases memory pointer, or moves the pointer to the left 1 block.
'''         = increases value stored at the block pointed to by the memory pointer.
''''        = decreases value stored at the block pointed to by the memory pointer.
'''''       = prints character to the console.
''''''      = reads character from user.
'''''''     = beginning of loop in form of -> while(cur_block_value != 0)...
''''''''    = jump back to beginning of loop.

ALL INSTRUCTIONS MUST END WITH A "SPACE" OR A "NEW LINE"

```

## Example Programm
This programm will run a loop
which subtracts 1 from the current cell
untill the cell contains a 0 
```c
''''''' '''' ''''''''
```
