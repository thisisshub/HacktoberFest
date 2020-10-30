from string import ascii_lowercase

def print_rangoli(size):
    # your code goes here
    r = []
    al = ascii_lowercase
    for i in range(size):
       
       #takes alphabets from i'th position to size and joins them with '-'
       p = '-'.join(al[i:size])
       
       #taking string from last to first and then adding it with the same string from first index to last
       #center(len,  fill_char) aligns the string in center by taking the length remaining space is filled by the fill_char
       r.append((p[::-1]+p[1:]).center((4*size)-3, '-'))
    
    #display the elements in list from last to first + first index to last
    #join this with new line
    print('\n'.join(r[::-1]+r[1:]))

if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)
