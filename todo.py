class ToDo:
	def __init__(self,file_name):
		self._running = True
		self.todo_dict = {}
		try:
			self.file = open(file_name, 'r+')
			self.read_todo()
			self.file.seek(0)
			self.file.truncate(0)
		except IOError:
			self.file = open(file_name, 'w')

	def read_todo(self)->{int:{str:bool}}:
		"""returns dict form of to-do list"""
		for line in self.file:            
			todo_entry = line.rstrip('\n').split(';')
			self.todo_dict[todo_entry[0]] = [todo_entry[1],todo_entry[2],int(todo_entry[3])]
	
	def __str__(self)->None:
		"""String representation of to-do list"""
		t_str = ""
		for index in self.todo_dict:
			if(self.todo_dict[index][2]):
				t_str+="{0}. {1} Due: {2} DONE\n".format(index,self.todo_dict[index][0],self.todo_dict[index][1])
			else:
				t_str+="{0}. {1} Due: {2} NOT DONE\n".format(index,self.todo_dict[index][0],self.todo_dict[index][1])	
		return t_str
	
	def add_entry(self, task, due):
		"""adds an entry to todo list"""
		self.todo_dict[len(self.todo_dict)+1] = [task,due,0]

	def check_off(self,num):
		self.todo_dict[num][2] += 1
		
	def update_todo(self)->None:
		"""adds an entry to the to-do list"""
		for key in self.todo_dict:
			self.file.write("{0};{1};{2};{3}\n".format(key,self.todo_dict[key][0],self.todo_dict[key][1],self.todo_dict[key][2]))
		self.file.close()
