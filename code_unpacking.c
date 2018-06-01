#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "textcolor.h"

/// To-Do List
// ToDo_1 - Allow user to page through multiple pages of disassembly
// ToDo_2 - Add different failure messages based on user progress
// ToDo_3 - Finish implementations of the handle functions

// Global constants
const int MAX_LINE_LENGTH = 128;
const char OPTION_A[] = "Enter breakpoint";
const char OPTION_B[] = "Continue Execution";
const char OPTION_C[] = "OllyDump";

// Global variables to track game state
int gl_Breakpoint = 0x00000000;     // Stores user-entered OllyDbg breakpoint

int gl_CurrentStep = 0;             // Tracks user's progress through module
                                    /* Values mean the following, and higher
                                        values imply previous steps completed:
                                            
                                            0 - No action has been taken
                                            1 - User has entered a breakpoint
                                            2 - User has unpacked the code
                                    */

// Functions for displaying module sections to User
int print_intro();
int print_success();
int print_failure(); // ToDo_2: Use user progress to inform failure message
int print_exit();

// ToDo_1: Implement below function
// int print_ollydbg(int page);
int print_ollydbg();

// Functions that prompt user for input
int prompt_menu();
int prompt_ollybreakpoint();
int prompt_ollydump();

// Functions to handle different actions. Return 0 on correct user action, -1 otherwise
int handle_breakpoint();
int handle_continue();
int handle_ollydump();


int main()
{
    char game_over = 0;
    char selection = 0;
    print_intro();
    
    while ( !game_over )
    {
        prompt_menu();
        selection = toupper(fgetc(stdin));
        /* A.) Enter breakpoint | B.) Continue Execution | C.) OllyDump */
        switch( selection )
        {
            case 'A':
                prompt_ollybreakpoint();
                printf("\n");
                handle_breakpoint();
                break;
                
            case 'B':
                if( handle_continue() )
                {
                    print_failure();
                    game_over = 1;
                }
                else
                {
                    printf("%s\n", "Program has paused at correct breakpoint.");
                }
                break;
                
            case 'C':
                if( handle_ollydump() )
                {
                    print_failure();
                    game_over = 1;
                }
                else
                {
                    printf("%s\n", "Program has paused at correct breakpoint.");
                }
                break;
                
            case 'X':
                game_over = 1;
                break;
                
            default:
                printf("%s\n", "Invalid option, enter valid option.");
        }
        //print_ollydbg();
    
    }
    print_exit();
    return 0;
}

// Print functions
int print_intro()
{
    printf("%s\n","---------------------------------------------------------------------------------");
    textcolor(UNDERLINE, GREEN, BLACK);
    printf("%s\n", "Welcome to the code unpacking educational module!");
    printf("%s\n", "The goal is to go through the correct steps in OllyDbg to obtain an unpacked program.");
    printf("%s\n","");
    textcolor(UNDERLINE, WHITE, BLACK);

    return 0;
}
int print_success()
{
    printf("%s\n", "Unpacked code retrieved, congratulations!");

    return 0;
}
int print_failure()
{
    printf("%s\n", "Failed to get unpacked code. Try again.");

    return 0;
}
int print_exit()
{
    printf("Goodbye.\n");
    printf("%s\n","---------------------------------------------------------------------------------");

    return 0;
}

int print_ollydbg()
{
    int c;
    FILE * ollyFile;
    ollyFile = fopen ("code_unpacking_ollydbg","r");
    if (ollyFile)
    {
        while ( (c = getc(ollyFile)) != EOF )
            printf("%c", c);
        fclose(ollyFile);
    }
    fclose (ollyFile);
    printf("\n");
    return 0;
}

// Prompt functions
int prompt_menu()
{
    printf("%s\n", "A.) Enter breakpoint | B.) Continue Execution | C.) OllyDump");
    printf("%s", "Enter choice (X to quit): ");
    return 0;
}
int prompt_ollybreakpoint()
{
    printf("%s", "Where do you want to set a breakpoint? 0x779");
    return 0;
}
int prompt_ollydump()
{
    printf("%s", "Where should the exported executable's entry point be? ");
    return 0;
}

// ToDo_3: Handle functions
int handle_breakpoint()
{
    
    return 0;
}
int handle_continue()
{
    
    return 0;
}
int handle_ollydump()
{
    
    return 0;
}