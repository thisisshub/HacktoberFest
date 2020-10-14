started = False
while True:
    command = input("> ").upper()
    if command == "START":
        if started:
            print("Car is already started")
        else:
            started = True
            print("Car started...Ready to go")
    elif command == "STOP":
        if started:
            started = False
            print("Car stopped.")
        else:
            print("Car is already stopped")
    elif command == "HELP":
        print("""
        start- To start the car
        stop- To stop the car
        quit- To quit
        """)
    elif command == "QUIT":
        break
    else:
        print("I don't understsand that...Please input a valid key")
