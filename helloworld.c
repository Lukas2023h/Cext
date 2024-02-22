#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

/*ToDos:
1. Load Text File if exists an write it in the Teminal
2. Backspace Taste implemetieren sodass man im file und im Terminal

Future Things to think about:
1. Undo & Redo
2. Syntax Highliting (different mode for Syntax Highliting, normal mode & syntax mode)

*/

int write_in_file(char *filename, int ch){
    FILE* fptr = fopen(filename, "a+");

    if(fptr == NULL){
        perror("Error opening file");
        return -1;
    }

    fputc(ch, fptr);
    fclose(fptr);
}

int main(int argc, char* argv[]){
    int ch;
    char *filename = argv[1];

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    while(TRUE){
        ch = getch();
        if(ch == KEY_F(9)){
            break;
        }else{
            printw("%c", ch);
            refresh();
            write_in_file(filename,ch);
        }
    }

    endwin();

    return 0;
}