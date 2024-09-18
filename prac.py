#!/usr/bin/env python3
def countInput():
    cntr = 0  # Initialize counter
    val = input("Enter something (type 'quit' to stop): ")  # Get first input
    while val != "quit":  # Continue until 'quit' is typed
        cntr += 1  # Increment counter
        val = input("Enter something (type 'quit' to stop): ")  # Get next input
    print("You entered", cntr, "values.")  # Print the result
