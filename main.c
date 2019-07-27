#include <ncurses.h>
#include <stdlib.h>
#include "todo.h"

int main(){
  initscr();
  cbreak();
  char file_num[10];
  printf("Enter todo list #: ");
  scanf("%s",file_num);
  char* file_name = get_file_name(file_num);
  run_interface(file_name);
  endwin();
  return 0;
}
