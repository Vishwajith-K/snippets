
print("Before import")
import temp_module as module
print("After import")

print("Name: ", __name__)
print("Using imported module symbols: add:", module.add(5, 6))

if __name__ == '__main__':
	print("main.py invoked")
