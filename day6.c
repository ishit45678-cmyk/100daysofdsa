import sys

def print_uniques():
    # Read input
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    arr = input_data[1:]

    if n == 0:
        return

    # The first element is always unique
    last_printed = arr[0]
    unique_elements = [last_printed]

    for i in range(1, n):
        # Only act if the current number is different from the previous one
        if arr[i] != last_printed:
            unique_elements.append(arr[i])
            last_printed = arr[i]

    print(*(unique_elements))

if __name__ == "__main__":
    print_uniques()