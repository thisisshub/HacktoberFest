class Matrix:

    def __init__(self, dimension):
        self.__dimension = dimension
        self.__matrix = [["empty" for self.__x in range(self.__dimension)] for self.__x in range(self.__dimension)]

    @property
    def view(self):
        #print("\n".join([str(i) for i in self.__matrix]))
        stamp = "\n".join([str(i) for i in self.__matrix])
        return stamp

    @property
    def matrix(self):
        return self.__matrix

    def delete(self, tp):
        if any(tp in self.__s for self.__i, self.__s in enumerate(self.__matrix)):
            if any(tp in self.__word for self.__k, self.__word in enumerate(self.__s)):
                self.__matrix[self.__i][self.__k] = "empty"

    def move(self, x, y, tp):
        self.delete(tp)
        self.__matrix[x][y] = tp




"""prova = Matrix(10)
# prova.view
prova.move(2, 4, "blu")
print(prova.view)
prova.delete("blu")
print("-" * 90)
print(prova.view)
prova.delete("blu")"""





