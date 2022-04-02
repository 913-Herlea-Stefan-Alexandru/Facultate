from math import gcd

#
# Non-UI functions
#

# Rational number functions
# print or input are not allowed here
# don't call functions that print or input

'''
What's the deal implementing this?
	-each rational number is represented by one variable (list, dict)
	-i want to be able to change the representation of rational numbers later
	-acces rational numbers using functions (getters setters)

list representation:
	1 / 3 => [1, 3]
touple representation:
	1 / 3 => (1, 3) -> no changes
dict representation:
	1 / 3 => {'num': 1, 'denom': 3} 
'''

def create_rational(num, denom=1):
	#Create a rational number with the given num and denom
	
	if denom == 0:
		raise ValueError("Denominator can't be 0")

	#Simplifying
	d = gcd(num, denom)
	num = num // d
	denom = denom // d
	return {'num': num, 'denom': denom}
	#return [num, denom]

def get_num(q):
	#Return umber q's num
	return q['num']
	#return q[0]

def get_denom(q):
	#Return umber q's denom
	return q['denom']
	#return q[1]

#Make the rational number responsible for it's own representation
def to_str(q):
	#return string repr of q
	return str(get_num(q)) + '/' + str(get_denom(q))

#a/b + c/d = (a*d + c*b) / (b*d)
def add(q1, q2):
	#Add 2 rational numbers
	new_num = get_num(q1)*get_denom(q2) + get_num(q2)*get_denom(q1)
	new_denom = get_denom(q1)*get_denom(q2)
	return create_rational(new_num, new_denom)

'''
	assert <true_expression> => does nothing
	assert <false_expression> => raise AssertionError
'''

def test_create_rational():
	q = create_rational(50, 100)
	assert get_num(q) == 1 and get_denom(q) == 2
	q = create_rational(3, 4)
	assert get_num(q) == 3 and get_denom(q) == 4

	#How do i test a value error raise?
	try:
		q = create_rational(1, 0)
		#The line above is supposed to raise an exception
		#The line below should not run
		assert False
	except ValueError as ve:
		assert True

test_create_rational()

#Calculator functions are here

'''
What is the state of the calculator?
	-current value(default 0/1)
	-history of calculator values
'''

def create_calculator():
	#Create calculator instance

	return {'value': create_rational(0), 'history': []}

def add_calc_number(calc, q):
	#Adds q to the calculator

	# Record current calc value for undo
	current_value = get_calc_value(calc)
	history = get_calc_history(calc)
	history.append(current_value)
	# Update calc with new value
	new_value = add(get_calc_value(calc), q)
	set_calc_value(calc, new_value)

def set_calc_value(calculator, q):
	calculator['value'] = q

def get_calc_value(calculator):
	#Return current calc value
	
	return calculator['value']

def get_calc_history(calculator):
	'''
	Returns the history of calc values
	:param calculator: current calc
	:return: A list of calc values
	'''
	return calculator['history']

def undo_calc(calculator):
	'''
	Undo the last operation
	:param calculator: Current calculator
	:return: ---
	raises ValueError if there is no operation to undo
	'''
	history = get_calc_history(calculator)
	# Case where there are no more undos
	if len(history) == 0:
		raise ValueError("No more undos!")
	# We have at least one undo available
	new_value = history.pop()
	set_calc_value(calculator, new_value)


#
# UI functions
#


def read_rational():
	#Read rational number from console
	num = int(input('Numerator: '))
	denom = int(input('Denominator: '))
	return create_rational(num, denom)

def add_calculator_ui(calc):
	value = read_rational()
	add_calc_number(calc, value)


def undo_calculator_ui(calculator):
	undo_calc(calculator)

def add_command_ui(calculator, params):
	tokens = params.split(',')
	for token in tokens:
		# each token represents a rational number
		token = token.strip()
		num_denom_str = token.split('/')
		q = create_rational(int(num_denom_str[0]), int(num_denom_str[1]) if len(num_denom_str) == 2 else 1)
		# add number to cacl
		add_calc_number(calculator, q)

def undo_command_ui(calculator, step_count):
	try:
		step_count = int(step_count)
	except ValueError:
		print("Not an int!")
		return
	while step_count > 0:
		undo_calc(calculator)
		step_count -= 1

def print_menu():
	print('\n')
	print('\t+ add a rational numbre to the calculator')
	print('\tu undo the last operation')
	print('\tx exit')


def start():
	#in a loop
	#print a menu
	#get the user's choice
	#do what user wants
	#print result

	calc = create_calculator()
	
	done = False
	while not done:
		print_menu()
		print('total '+ to_str(get_calc_value(calc)))
		option = input("Enter operation: ")
	
		#V1. handling user input
		try:
			if option == '+':
				add_calculator_ui(calc)
			elif option == 'u':
				undo_calculator_ui(calc)
			elif option == 'x':
				print("Bye bye!")
				done = True
			else:
				print("Bad command!")
		except ValueError as ve:
			print("An error occurred " + str(ve))

def split_command(command):
	# index = command.find(' ')
	tokens = command.split(' ', 1)
	return tokens[0].strip().lower(), tokens[1].strip() if len(tokens) == 2 else ''

def start_command_ui():
	calc = create_calculator()
	done = False

	command_dict = {'add': add_command_ui, 'undo': undo_command_ui}

	while not done:
		try:
			print("total=" + to_str(get_calc_value(calc)))
			command = input('command >')
			# Which command is requested
			command_words, command_params = split_command(command)
			if 'exit' == command_words:
				done = True
			elif command_words in command_dict:
				command_dict[command_words](calc, command_params)
			else:
				print("Bad command!")
		except ValueError as ve:
			print(str(ve))


start_command_ui()

'''
My test functions go here
'''

'''
	assert <true_expression> => does nothing
	assert <false_expression> => raise AssertionError
'''

def test_create_rational():
	q = create_rational(50, 100)
	assert get_num(q) == 1 and get_denom(q) == 2
	q = create_rational(3, 4)
	assert get_num(q) == 3 and get_denom(q) == 4

	#How do i test a value error raise?
	try:
		q = create_rational(1, 0)
		#The line above is supposed to raise an exception
		#The line below should not run
		assert False
	except ValueError as ve:
		assert True

def test_undo_calc():
	c = create_calculator()

	# Try to undo with no operations available
	try:
		undo_calc(c)
		assert False
	except ValueError:
		# the function was supposed to raise an exception
		assert True

	# Undo one operation
	add_calc_number(c, create_rational(1, 3))
	undo_calc(c)
	calc_value = get_calc_value(c)
	assert get_num(calc_value) == 0 and get_denom(calc_value) == 1

	# Undo several operations
	add_calc_number(c, create_rational(1, 2))
	add_calc_number(c, create_rational(1, 3))
	add_calc_number(c, create_rational(1, 4))

	undo_calc(c)
	calc_value = get_calc_value(c)
	assert get_num(calc_value) == 5 and get_denom(calc_value) == 6
	undo_calc(c)
	calc_value = get_calc_value(c)
	assert get_num(calc_value) == 1 and get_denom(calc_value) == 2
	undo_calc(c)
	calc_value = get_calc_value(c)
	assert get_num(calc_value) == 0 and get_denom(calc_value) == 1

	# There should be no more undos
	try:
		undo_calc(c)
		assert False
	except ValueError:
		# the function was supposed to raise an exception
		assert True

#test_undo_calc()
#test_create_rational()









