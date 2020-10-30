def print_formatted(number):
    #finding the bit length
    #Returns the number of bits required to represent an integer in binary, excluding the sign and leading zeros.
    length = number.bit_length()
    #taking the decimal, octal, hexadecimal and binary in a list
    formats = ['{0:d}', '{0:o}', '{0:X}', '{0:b}']
    for i in range(1, n + 1):
        #rjust a new string of given length after substituting a given character in left side of original string.
        print(' '.join(f.format(i).rjust(length) for f in formats))
if __name__ == '__main__':
    n = int(input())
    print_formatted(n)
