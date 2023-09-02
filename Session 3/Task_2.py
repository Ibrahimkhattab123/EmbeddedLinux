import sys

if len(sys.argv) > 1:
    arguments = sys.argv[1:]

    for arg in arguments:
        print(f"Arguments: {arg}")
else:
    print("No command line provided")