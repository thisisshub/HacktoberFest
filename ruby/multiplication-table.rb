class ArrayUtils
  def self.multiplos(qtd, multiplo)
    array = []
    contador = 0
    while array.length < qtd do
      contador += 1
      array.push(multiplo * contador)
    end
    array  
  end

  def self.tabuada(numero)
    tabuada = []
    for multiplicador in 1..numero 
        tabuada_do_multiplicando = []
        for multiplicando in 1..10
          tabuada_do_multiplicando << multiplicador * multiplicando
        end
        tabuada << tabuada_do_multiplicando
    end
    tabuada
  end

end
