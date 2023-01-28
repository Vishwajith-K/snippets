def add(a, b):
	return a + b

if __name__ == '__main__':
	print("Module invoked directly")
else:
	print("Some other module has imported this module; Name: ", __name__)
