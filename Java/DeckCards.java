  
/*program that create and mixes a deck of cards*/

import java.util.Scanner;

public class Program
{
	public static void main(String[] args) {
		int op,ver=0;
		Scanner teclado = new Scanner(System.in);
		
		//arrays for the Spanish deck
		String [] palo_esp = new String [] {"Espada","Copa","Oro","Basto"};
		String [] num_esp = new String[] {"Uno","Dos","Tres","Cuatro","Cinco","Seis","Siete","Ocho","Nueve","Diez","Once","Doce"};
		
		//arrays for the French deck
		String [] palo_fra = new String [] {"Pica","Trebol","Diamante","Corazones"};
		String [] num_fra = new String[] {"As","Dos","Tres","Cuatro","Cinco","Seis","Siete","Ocho","Nueve","Diez","J","Q","K"};
		

		//I ask the user to choose the type of deck
		System.out.println("Que baraja desea crear ? \n");
		System.out.println("1. baraja espaniola ");
		System.out.println("2. baraja francesa ");
		System.out.println("ingrese numero: ");
		op = teclado.nextInt();

		//I verify the user's choice and print
		
		if (op == 1) {
			
			//I create the deck_esp object
			Mazo baraja_esp = new Mazo(palo_esp,num_esp);
			System.out.println("Baraja lista");
			
			System.out.println("Quiere verla ? ");
			System.out.println("1.SI 2.NO ");
			System.out.println("ingrese numero: ");
			ver = teclado.nextInt();
			if(ver == 1) {
				//I ask him to show me the deck
				baraja_esp.mostrar();
			}
			else{
				System.out.print("Chau !!!");
			}
			
		}
		else if (op == 2) {
			
			
			// I create the deck_frame object, I pass the number and suit to the constructor
			Mazo baraja_fra = new Mazo(palo_fra,num_fra);
			
			
			System.out.println("Baraja lista");
			
			System.out.println("Quiere verla ? ");
			System.out.println("1.SI 2.NO ");
			System.out.print("ingrese numero: ");
			ver = teclado.nextInt();
			if(ver == 1) {
				
				//I ask him to show me the deck
				baraja_fra.mostrar();
			}
			else{
				System.out.print("Chau !!!");
			}
		}
		else {
			System.out.println("Error opcion no valida !!!");
		}
	}
}

public class Carta {
	private String num;// number of the card
	private String palo;// card suit

	//constructor
	public Carta(String num,String palo) {
		this.num = num;
		this.palo = palo;
	}
	
	public String getnum() {
		return num;
	}
	public String getpalo() {
		return palo;
	}

}

public class Mazo {
	Carta [] mazo; // array that will contain the cards
	private int cant_palo;// number of suit
	private int cant_num; // number of number
	private int total; // total cards



	
	// Constructor that receives the suits and the numbers
	public Mazo (String []palo, String [] num) {

		cant_palo = palo.length; // I save the length of the array "palo"
		cant_num = num.length; //I save the length of the array "num"
		total = cant_palo * cant_num; //I calculate the total of cards
		mazo = new Carta [total]; //I create the array of objects of type Carta

		llenar(palo,num); //I invoke the method to fill the array "mazo"
	}

	
	
	private void llenar (String []palo, String [] num) {
		int h=0;//is to move in the "mazo"
		int i;//is to move in the "palo"
		int j;//is to move in the "num"
		
		//I move in the arrays "num", "palo" and "mazo" to create the cards
		for(i=0 ; i < cant_palo ; i++) {
			
			for(j=0; j < cant_num && h< total ;j++,h++) {
				
				//voy creando cartas con sus correspondientes atributos
				// y la direcciones las guardo en el array "mazo" una x una
				this.mazo[h] = new Carta(num[j],palo[i]);
			}
		}
	}

	//method to show the cards
	public void mostrar () {
		int i;
		for(i=0 ; i < total; i++) {

			System.out.println("------------------");
			System.out.println("|Carta "+(i+1));
			System.out.println("|palo "+mazo[i].getpalo());
			System.out.println("|num "+mazo[i].getnum());
			System.out.println("------------------");
			System.out.println("\n");
		}
	}
}

