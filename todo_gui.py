import todo as td
class ToDoUI:
	def __init__(self,t_lst):
		self.t_lst = t_lst

	def interface(self, action): 
		if(action == 1): 
			print(self.t_lst)
		elif(action == 2):
			task = input('Task: ').strip()
			due = input('Due Date: ').strip()
			self.t_lst.add_entry(task, due)
		elif(action == 3): 
			num = int(input('Item to check-off: ').strip())
			self.t_lst.check_off(num)   		
		else:      	 	 		
			self.t_lst.update_todo() 
			self.t_lst._running = False    
    
if __name__ == '__main__': 
	file = 'todo'+input('To-do list #: ').strip()+'.txt' 
	todo = td.ToDo(file)
	t_ui = ToDoUI(todo)
	while(todo._running):  
		print("\n1: print todo list\n2: add task\n3: check off task\n4: quit\n") 
		action = int(input("Pick Action: ").strip())
		t_ui.interface(action)
	print("\nPROGRAM FINISHED")
