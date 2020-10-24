import re

def clear_punctuation(document):
    return re.sub('\D', '', str(document))

def calculate_first_digit(number):
    sum = 0
    weights = (5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2)

    for i in range(len(number)):
        sum = sum + int(number[i]) * weights[i]
    rest_division = sum % 11

    if rest_division < 2:
        return '0'
    return str(11 - rest_division)


def calculate_second_digit(number):
    sum = 0
    weights = (6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2)

    for i in range(len(number)):
        sum = sum + int(number[i]) * weights[i]
    rest_division = sum % 11

    if rest_division < 2:
        return '0'
    return str(11 - rest_division)

def validate(cnpj_number):
    _cnpj = clear_punctuation(cnpj_number)

    if (len(_cnpj) != 14 or len(set(_cnpj)) == 1):
        return False

    first_part = _cnpj[:12]
    second_part = _cnpj[:13]
    first_digit = _cnpj[12]
    second_digit = _cnpj[13]

    if (first_digit == calculate_first_digit(first_part) and
    second_digit == calculate_second_digit(second_part)):
        return True

    return False
