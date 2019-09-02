#ifndef TODO_H_
#define TODO_H_

typedef struct{
  char task[30];
  char due_date[10];
  bool done;  
}entry;

char* get_file_name(char* file_num);
int read_todo(FILE* file, entry* todo_list);
void write_file(FILE* file, entry* todo_list, int size);
int add_task(entry* todo_list, int size);
void run_interface(char* file_name);
void check_off(entry* todo_list);
void print_todo(entry* todo_list, int size);

#endif
