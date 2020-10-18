import sys

commands = None
userin = None
tape = [0] # tape of values
pointer = 0 # points at the tape
scroll = 0 # points at the stuff to interpret

try:
    commands = open(sys.argv[1], "r").read()
except IndexError:
    raise RuntimeError("Please supply an input file!")
try:
    userin = open(sys.argv[2], "r").read()
except IndexError:
    pass

if userin:
    userin = userin.split(" ")
    userin = list(map(int, userin))
    if max(userin) > 255 or min(userin) < 0:
        raise RuntimeError("Please make sure all user input is between 0 and 255 inclusive")

opens = {} # all open instances of brackets are keys
closes = {} # all closed instances of brackets are keys
stack = [] # temp
for index in range(len(commands)): # iterates through every symbol
    if commands[index] == "[":
        stack.append(index)
    elif commands[index] == "]":
        if stack: # don't pop when nothing on the stack!
            opens[stack[-1]] = index # the key in opens is the open instance - this is the last element in stack. the value is then the current index (closing bracket).
            closes[index] = stack.pop() # the key in closes is the closed instance - the current index. therefore the corresponding value is the last element in stack (can now be removed). 
        else:
            raise RuntimeError("Input has a closed bracket, index %d, before an opened one." % index)


while scroll < len(commands): # while we haven't reached the end of the commands
    
    if commands[scroll] == ">": # move along tape pointer, if we run out of tape then add some more.
        pointer += 1
        if pointer >= len(tape):
            tape += [0, 0, 0, 0, 0, 0, 0, 0]
    elif commands[scroll] == "<": # move backwards tape pointer. If we run out of tape then raise error
        pointer -= 1
        if pointer < 0:
            raise RuntimeError("Cannot move pointer below 0 on tape!")
    
    elif commands[scroll] == "+": # increment tape at pointer, if we overflow above 255 we wrap to 0.
        tape[pointer] += 1
        if tape[pointer] > 255:
            tape[pointer] = 0
    elif commands[scroll] == "-": # decrement tape at pointer, if we underflow below 0 we wrap to 255.
        tape[pointer] -= 1
        if tape[pointer] < 0:
            tape[pointer] = 255
    
    elif commands[scroll] == ".": # print the unicode char of the tape at pointer, supress newline
        print(chr(tape[pointer]), end="")
    elif commands[scroll] == ",": # take input from file, read number into tape at pointer. Pop first item.
        if userin:
            tape[pointer] = userin.pop(0)
        else:
            raise RuntimeError("Not enough input provided")
    
    elif commands[scroll] == "[": # if non zero value, ignore. Else, put the scroll to the corresponding closing bracket (minus one to be incremented below).
        if not tape[pointer]:
            scroll = opens[scroll]-1
    elif commands[scroll] == "]": # if zero value, ignore. Else, put the scroll back to the corresponding opening bracket (minus one to be incremented below).
        if tape[pointer]:
            scroll = closes[scroll]-1

    scroll += 1
