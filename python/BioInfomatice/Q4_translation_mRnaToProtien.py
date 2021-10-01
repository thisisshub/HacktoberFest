
table = {
    'AUA': 'I', 'AUC': 'I', 'AUU': 'I', 'AUG': 'M',
    'ACA': 'T', 'ACC': 'T', 'ACG': 'T', 'ACU': 'T',
    'AAC': 'N', 'AAU': 'N', 'AAA': 'K', 'AAG': 'K',
    'AGC': 'S', 'AGU': 'S', 'AGA': 'R', 'AGG': 'R',
    'CUA': 'L', 'CUC': 'L', 'CUG': 'L', 'CUU': 'L',
    'CCA': 'P', 'CCC': 'P', 'CCG': 'P', 'CCU': 'P',
    'CAC': 'H', 'CAU': 'H', 'CAA': 'Q', 'CAG': 'Q',
    'CGA': 'R', 'CGC': 'R', 'CGG': 'R', 'CGU': 'R',
    'GUA': 'V', 'GUC': 'V', 'GUG': 'V', 'GUU': 'V',
    'GCA': 'A', 'GCC': 'A', 'GCG': 'A', 'GCU': 'A',
    'GAC': 'D', 'GAU': 'D', 'GAA': 'E', 'GAG': 'E',
    'GGA': 'G', 'GGC': 'G', 'GGG': 'G', 'GGU': 'G',
    'UCA': 'S', 'UCC': 'S', 'UCG': 'S', 'UCU': 'S',
    'UUC': 'F', 'UUU': 'F', 'UUA': 'L', 'UUG': 'L',
    'UAC': 'Y', 'UAU': 'Y', 'UAA': '_', 'UAG': '_',
    'UGC': 'C', 'UGU': 'C', 'UGA': '_', 'UGG': 'W',
}


def protien_name(ami):
    if 'I' == ami:
        return "Isoleucine"

    elif 'T' == ami:
        return "Threonine"

    elif 'M' == ami:
        return "Start"

    elif 'N' == ami:
        return "Asparagine"

    elif 'S' == ami:
        return "Serine"

    elif 'R' == ami:
        return "Arginine"

    elif 'L' == ami:
        return "Leucine"

    elif 'P' == ami:
        return "Proline"

    elif 'H' == ami:
        return "Histidine"

    elif 'Q' == ami:
        return "Glutamine"

    elif 'V' == ami:
        return "Valine"

    elif 'A' == ami:
        return "Alanine"

    elif 'D' == ami:
        return "Aspartic"

    elif 'E' == ami:
        return "Glutamic"

    elif 'G' == ami:
        return "Glycine"

    elif 'F' == ami:
        return "Phenylalanine"

    elif 'Y' == ami:
        return "Tyrosine"

    elif 'C' == ami:
        return "Cysteine"

    elif 'W' == ami:
        return "Tryptophan"

    elif 'K' == ami:
        return "Lysine"

    else:
        return "Stop"


protein = ""
file1 = open("protien.txt", "w")
with open('mRna_seq.txt', 'r') as file:
    for string in file:
        print(string)
        temp_string = [string[i:i + 3] for i in range(0, len(string) - 3, 3)]
        print(temp_string)
        for i in temp_string:
            if i in table:
                nme = table[i]
                file1.write(protien_name(nme))
                file1.write(" ")
        # break
        file1.write("\n")

file1.close()
# print(protein)
