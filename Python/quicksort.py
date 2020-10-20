def partition(dlist, inicio, fim):
    pivo = dlist[fim]
    baixo = inicio-1
    cima = fim

    done = 0
    while not done:

        while not done:
            baixo = baixo + 1

            if baixo == cima:
                done = 1
                break

            if dlist[baixo] > pivo:
                dlist[cima] = dlist[baixo]
                break

        while not done:
            cima = cima-1

            if cima == baixo:
                done = 1
                break

            if dlist[cima] < pivo:
                dlist[baixo] = dlist[cima]
                break

    dlist[cima] = pivo
    return cima

def quicksort(dlist,inicio,fim):
	if inicio < fim:

		n = partition(dlist,inicio,fim)
		quicksort(dlist,inicio,n-1)
		quicksort(dlist,n+1,fim)




if __name__ == '__main__':
	print("Insert how many itens the list will have")

	n = int(input())

	print("Now input the itens")

	dlist = []
	texto = ''

	for i in range(n):
		a = int(input())
		dlist.append(a)

	quicksort(dlist,0,n-1)

	for i in range(n):
		texto += str(dlist[i])
		texto += ' '


	print(texto)
