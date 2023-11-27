import os
def count_num_4(lst):
    count = 0
    for num in lst:
        if num == 4:
            count += 1
    
    return count

def is_vowel(letter):
    vowels = "AEIOUaeiou"
    return letter in vowels

def main():
    numbers = [1, 4, 2, 5, 4, 6, 8, 4]
    count_4 = count_num_4(numbers)
    print(f"The number 4 appears {count_4} times in the given list")
    
    letter = input("Enter a letter: ")

# Check if input is a single letter and if input is alphabetic
    if len(letter) == 1 and letter.isalpha():
        if is_vowel(letter):
            print(f"{letter} is a vowel")
        else:
            print(f"{letter} is not a vowel")
    else:
        print(f"Please enter a valid single letter")

    path_var = os.environ.get('PATH')
    os_var = os.environ.get('os')

    print(f"PATH env var: {path_var}")
    print(f"OS env vat: {os_var}")


if __name__ == "__main__":
    main()