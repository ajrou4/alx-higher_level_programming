#!/usr/bin/python3

def is_valid_roman_string(s):
    """
    Check if the input string contains valid Roman numeral characters.

    Args:
        s (str): The input string.

    Returns:
        bool: True if the string is a valid Roman numeral, False otherwise.
    """
    valid_characters = "IVXLCDM"
    return all(char in valid_characters for char in s)

def roman_to_int(roman_string):
    """
    Convert a Roman numeral string to an integer.

    Args:
        roman_string (str): The Roman numeral string.

    Returns:
        int: The corresponding integer value.
    """
    if not roman_string or not is_valid_roman_string(roman_string) or type(roman_string) is not str:
        raise ValueError("Invalid Roman numeral input")

    roman_numbers = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }

    total = 0
    for i in range(len(roman_string) - 1):
        if roman_numbers[roman_string[i]] < roman_numbers[roman_string[i + 1]]:
            total -= roman_numbers[roman_string[i]]
        else:
            total += roman_numbers[roman_string[i]]

    total += roman_numbers[roman_string[-1]]
    return total

