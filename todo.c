#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "todo.h"

void run_interface(char* file_name){ 
  FILE* file = fopen(file_name, "a+");
  entry* todo_list = calloc(10, sizeof(entry));
  int size = read_todo(file, todo_list);
  bool running = true;
  printf("Options:\n\ta: Print todo list\n\tb: Add task\n\tc: Check off task\n\tq: quit\n");
  while(running){
    char choice;
    choice = getchar();
    switch(choice){
      case 'a':
        print_todo(todo_list, size);
        break;
      case 'b':
        size = add_task(todo_list, size);
        break;
      case 'c':
        check_off(todo_list);
        break;          
      case 'q':
        running = false;
        break;
    }
  }
  file = fopen(file_name, "w");
  write_file(file, todo_list, size);
}

char* get_file_name(char* file_num){
  static char file_name[20] = "todo";
  strcat(file_name, file_num);
  strcat(file_name, ".txt");
  return file_name;
}

void print_todo(entry* todo_list, int size){
  for(int a = 0;a<size;a++){
    if(todo_list[a].done) 
      printf("\t%d: %s --> DONE\n", a+1, todo_list[a].task);
    else
      printf("\t%d: %s --> NOT DONE\n", a+1, todo_list[a].task);
  }
}

int read_todo(FILE* file, entry* todo_list){
  char line[80];
  char delim[] = ";";
  int index = 0;  
  while(fgets(line, sizeof(line), file)!=NULL){
    char* ptr = strtok(line, delim);
    for(int a = 0; a<2; a++){
      if(a==0)
        strcpy(todo_list[index].task, ptr);
      else if(a==1)
        strcpy(todo_list[index].due_date, ptr);
      else
        todo_list[index].done = false;
        if(ptr=="DONE")
          todo_list[index].done = true;         
      ptr = strtok(NULL, delim);
    }
    index++;
  }
  fclose(file);
  return index;
} 

void write_file(FILE* file, entry* todo_list, int size){
  for(int a = 0; a<size; a++){
    char f_str[50];
    strcpy(f_str, todo_list[a].task);
    strcat(f_str, ";");
    strcat(f_str, todo_list[a].due_date);
    strcat(f_str, ";");
    if(todo_list[a].done)
      strcat(f_str, "DONE\n");
    else
      strcat(f_str, "NOT DONE\n");
    fputs(f_str, file);
  }
  fclose(file);
}

int add_task(entry* todo_list, int size){
  if(size>=10){
    printf("Max todo list size reached\n");
  }
  else{
    printf("Enter task: ");
    scanf("%s", &todo_list[size].task);
    printf("Enter due date: ");
    scanf("%s", &todo_list[size].due_date);
    todo_list[size].done = false;
    size++;
  }
  return size;
}

void check_off(entry* todo_list){
  int item_num;
  printf("Enter task #: ");
  scanf("%d", item_num);
  todo_list[item_num-1].done = true;
}
