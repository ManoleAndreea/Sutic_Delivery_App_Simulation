#include <iostream>
#include <string.h>

using namespace std;

struct adresa
{
	char nume[1001], strada[10001], restaurant[1001], meniu[1001];
	int numar_ordine, numar;
	float pret; 
}persoana[10001];

struct nod
{
	int info;
	int numarul_clientului;
	nod *next;
} *numar[10001];
int n;
int auxiliar, numar_intreg_invers, clienti;

int introducere()
{
	char d[30], t[30];
	cout << '\n' << "         Doriti sa faceti o comanda?: ";  cin.getline(d, 30);
	if(strcmp(d, "da")==0)
		return 1;
	else 
		cout << '\n' << "         Introduceti codul: ";  cin.getline(t, 30);
	if(strcmp(t, "1234")==0)
	{
		cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
		cout << "                                   _______     _______     _         | |                                                   " <<'\n';
		cout << "                                  |  _____|   |   _   |   | |        | |                                                   " <<'\n';
		cout << "                                  | |     _   |  | |  |   | |        | |                                                   " <<'\n';
		cout << "                                  | |____| |  |  |_|  |   | |____    |_|                                                   " <<'\n';
		cout << "                                  |________|  |_______|   |______|    _                                                    " <<'\n';
		cout << "                                                                     |_|                                                   " <<'\n';
		cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
	}
	else
		cout << '\n' << "         COD INCORECT !!! ";
}
void citire(int &clienti)
{
	clienti++;
		cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
	cout << '\n' << "         Introduceti numele: "; cin.getline (persoana[clienti].nume, 1001);		 
	cout << '\n' << "         Introduceti strada: "; cin.getline (persoana[clienti].strada, 10001);
	cout << '\n' << "         Si numarul de telefon: "; cin >> auxiliar;
		cout<< '\n' << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
}
void dictionar(nod *numar[], int auxiliar)
{
	persoana[clienti].numar_ordine=auxiliar/1000000;
	persoana[clienti].numar=auxiliar;
	int auxiliar_2=auxiliar/1000000;
	if(numar[auxiliar_2]==NULL)
    {
    	nod *adaugare=new nod;
        adaugare->next=NULL;
        adaugare->info=auxiliar;
        adaugare->numarul_clientului=clienti;
        numar[auxiliar_2]->next=adaugare;
    }
    else
    { 
		nod *primul=numar[auxiliar_2];
		int stop=false;
        while(primul->next!=NULL && stop==false)
        {
			if(primul->next->info==auxiliar)
				stop=true;
            else
			 primul=primul->next;
        }
        if(stop==false)
        {
			nod *adaugare=new nod;
        	adaugare->next=NULL;
        	adaugare->info=auxiliar;
        	adaugare->numarul_clientului=clienti;
        	primul->next=adaugare;	
    	} 
		else
			primul->next->numarul_clientului=clienti;
	}
}
float alegere_restaurant_si_meniu(int clienti)
{
	cout << '\n' << "         Alegeti dintre restaurantele KFC, McDonald's, Pizza Hut, Burger King, Subway, Springtime: "; cin.getline(persoana[clienti].restaurant, 1001);
	if(strcmp(persoana[clienti].restaurant, "KFC")==0)
	{
		cout << '\n' << "         Alegeti dintre meniurile: 5 Crispy Strips(32,50 lei), Box for One(31,00 lei), American Bucket(53,50 lei), Smart Menu Extra(221,50 lei): "; cin.getline(persoana[clienti].meniu, 1001);
		if(strcmp(persoana[clienti].meniu, "5 Crispy Strips")==0)
			return 32.50;
		else
			if(strcmp(persoana[clienti].meniu, "Box for One")==0)
				return 31.00;
			else
				if(strcmp(persoana[clienti].meniu, "American Bucket")==0)
					return 53.50;
				else
					if(strcmp(persoana[clienti].meniu, "Smart Menu Extra")==0)
						return 221.50;
	}
		else
		if(strcmp(persoana[clienti].restaurant, "McDonald's")==0)			
		{
			cout << '\n' << "         Alegeti dintre meniurile: Maxi Big Mac(21,20 lei), Mare Chicken McNuggets 9 bucati(24,40 lei), Maxi Dublu Cheesburger(21,20 lei), Maxi McChicken(21,20 lei): "; cin.getline(persoana[clienti].meniu, 1001);
			if(strcmp(persoana[clienti].meniu, "Maxi Big Mac")==0)
				return 21.20;
			else
				if(strcmp(persoana[clienti].meniu, "Mare Chicken McNuggets")==0)
					return 24.40;
				else
					if(strcmp(persoana[clienti].meniu, "Maxi Dublu Cheesburger")==0)
						return 21.20;
					else
						if(strcmp(persoana[clienti].meniu, "Maxi McChicken")==0)
							return 21.20;
				
		}
		else
			if(strcmp(persoana[clienti].restaurant, "Pizza Hut")==0)
			{
				cout << '\n' << "         Alegeti dintre meniurile: Pepperoni Pan medie(39,00 lei), Super Suprema Cheesy Bites mare(59,50 lei), Pepperoni Pan mare(50,00 lei), Pepperoni Cheesy Bites mare(54,00 lei): "; cin.getline(persoana[clienti].meniu, 1001);
				if(strcmp(persoana[clienti].meniu, "Pepperoni Pan mare")==0)
					return 50.00;
				else
					if(strcmp(persoana[clienti].meniu, "Pepperoni Pan medie")==0)
						return 39.00;
					else
						if(strcmp(persoana[clienti].meniu, "Super Suprema Cheesy Bites mare")==0)
							return 59.50;
						else
							if(strcmp(persoana[clienti].meniu, "Pepperoni Cheesy Bites mare")==0)
								return 54.00;
			}
			else
				if(strcmp(persoana[clienti].restaurant, "Burger King")==0)			
				{
					//cin.get();
					cout << '\n' << "         Alegeti dintre meniurile: King Menu(29,00 lei), Crispy Chicken(19,90 lei), Big King XXL(35,90 lei), Menu Family(59,00 lei): "; cin.getline(persoana[clienti].meniu, 1001);
					if(strcmp(persoana[clienti].meniu, "King Menu")==0)
						return 29.00;
					else
						if(strcmp(persoana[clienti].meniu, "Crispy Chicken")==0)
							return 19.90;
						else
							if(strcmp(persoana[clienti].meniu, "Big King XXL")==0)
								return 35.90;
							else
								if(strcmp(persoana[clienti].meniu, "Menu Family")==0)
									return 59.00;
				}
				else
					if(strcmp(persoana[clienti].restaurant, "Subway")==0)			
					{
					//	cin.get();
						cout << '\n' << "         Alegeti dintre meniurile: Pui Teriyaki 30cm(28,60 lei), Pui Teriyaki 15cm(15,80 lei), Vita si Branza 30cm(30,90 lei), Italian BMT 30cm(28,00 lei): "; cin.getline(persoana[clienti].meniu, 1001);
						if(strcmp(persoana[clienti].meniu, "Pui Teriyaki 30cm")==0)
							return 28.60;
						else
							if(strcmp(persoana[clienti].meniu, "Pui Teriyaki 15cm")==0)
								return 15.80;
							else
								if(strcmp(persoana[clienti].meniu, "Vita si Branza 30cm")==0)
									return 30.90;
								else
									if(strcmp(persoana[clienti].meniu, "Italian BMT 30cm")==0)
										return 28.00;
					}
					else
						if(strcmp(persoana[clienti].restaurant, "Springtime")==0)			
						{
						//	cin.get();
							cout << '\n' << "         Alegeti dintre meniurile: Saorma Mare de pui sandwich(26,40 lei), Snitel Vienez pui(28,80 lei), Quesadilla Platou(29,60 lei), Snitel de pui Platou(28,00 lei): "; cin.getline(persoana[clienti].meniu, 1001);
							if(strcmp(persoana[clienti].meniu, "Saorma Mare de pui sandwich")==0)
								return 26.40;
							else
								if(strcmp(persoana[clienti].meniu, "Snitel Vienez pui")==0)
									return 28.80;
								else
									if(strcmp(persoana[clienti].meniu, "Quesadilla Platou")==0)
										return 29.60;
									else
										if(strcmp(persoana[clienti].meniu, "Snitel de pui Platou")==0)
											return 28.00;
						}
			
}
int intrebare()
 {
	cout << '\n' << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
	char c[10];
	cout << '\n' << "        Mai doriti sa comandati ceva?: "; cin.getline(c, 10);
	if(strcmp(c, "da")==0)
		return 1;
 	 else 
    	return 2;
	cout << '\n' << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
}	
float alegere_restaurant_si_meniu2(int clienti, char auxiliar_restaurant[], char auxiliar_meniu[])
{
	cout << '\n' << "         Alegeti dintre restaurantele KFC, McDonald's, Pizza Hut, Burger King, Subway, Springtime: "; cin.getline(auxiliar_restaurant, 1001);
	if(strcmp(auxiliar_restaurant, "KFC")==0)
	{
		cout << '\n' << "         Alegeti dintre meniurile: 5 Crispy Strips(32,50 lei), Box for One(31,00 lei), American Bucket(53,50 lei), Smart Menu Extra(221,50 lei): "; cin.getline(auxiliar_meniu, 1001);
		if(strcmp(auxiliar_meniu, "5 Crispy Strips")==0)
			return 32.50;
		else
			if(strcmp(auxiliar_meniu, "Box for One")==0)
				return 31.00;
			else
				if(strcmp(auxiliar_meniu, "American Bucket")==0)
					return 53.50;
				else
					if(strcmp(auxiliar_meniu, "Smart Menu Extra")==0)
						return 221.50;
	}
		else
		if(strcmp(auxiliar_restaurant, "McDonald's")==0)			
		{
			cout << '\n' << "         Alegeti dintre meniurile: Maxi Big Mac(21,20 lei), Mare Chicken McNuggets 9 bucati(24,40 lei), Maxi Dublu Cheesburger(21,20 lei), Maxi McChicken(21,20 lei): "; cin.getline(auxiliar_meniu, 1001);
			if(strcmp(auxiliar_meniu, "Maxi Big Mac")==0)
				return 21.20;
			else
				if(strcmp(auxiliar_meniu, "Mare Chicken McNuggets")==0)
					return 24.40;
				else
					if(strcmp(auxiliar_meniu, "Maxi Dublu Cheesburger")==0)
						return 21.20;
					else
						if(strcmp(auxiliar_meniu, "Maxi McChicken")==0)
							return 21.20;
				
		}
		else
			if(strcmp(auxiliar_restaurant, "Pizza Hut")==0)
			{
				cout << '\n' << "         Alegeti dintre meniurile: Pepperoni Pan medie(39,00 lei), Super Suprema Cheesy Bites mare(59,50 lei), Pepperoni Pan mare(50,00 lei), Pepperoni Cheesy Bites mare(54,00 lei): "; cin.getline(auxiliar_meniu, 1001);
				if(strcmp(auxiliar_meniu, "Pepperoni Pan mare")==0)
					return 50.00;
				else
					if(strcmp(auxiliar_meniu, "Pepperoni Pan medie")==0)
						return 39.00;
					else
						if(strcmp(auxiliar_meniu, "Super Suprema Cheesy Bites mare")==0)
							return 59.50;
						else
							if(strcmp(auxiliar_meniu, "Pepperoni Cheesy Bites mare")==0)
								return 54.00;
			}
			else
				if(strcmp(auxiliar_restaurant, "Burger King")==0)			
				{
					cout << '\n' << "         Alegeti dintre meniurile: King Menu(29,00 lei), Crispy Chicken(19,90 lei), Big King XXL(35,90 lei), Menu Family(59,00 lei): "; cin.getline(auxiliar_meniu, 1001);
					if(strcmp(auxiliar_meniu, "King Menu")==0)
						return 29.00;
					else
						if(strcmp(auxiliar_meniu, "Crispy Chicken")==0)
							return 19.90;
						else
							if(strcmp(auxiliar_meniu, "Big King XXL")==0)
								return 35.90;
							else
								if(strcmp(auxiliar_meniu, "Menu Family")==0)
									return 59.00;
				}
				else
					if(strcmp(auxiliar_restaurant, "Subway")==0)			
					{
						cout << '\n' << "         Alegeti dintre meniurile: Pui Teriyaki 30cm(28,60 lei), Pui Teriyaki 15cm(15,80 lei), Vita si Branza 30cm(30,90 lei), Italian BMT 30cm(28,00 lei): "; cin.getline(auxiliar_meniu, 1001);
						if(strcmp(auxiliar_meniu, "Pui Teriyaki 30cm")==0)
							return 28.60;
						else
							if(strcmp(auxiliar_meniu, "Pui Teriyaki 15cm")==0)
								return 15.80;
							else
								if(strcmp(auxiliar_meniu, "Vita si Branza 30cm")==0)
									return 30.90;
								else
									if(strcmp(auxiliar_meniu, "Italian BMT 30cm")==0)
										return 28.00;
					}
					else
						if(strcmp(auxiliar_restaurant, "Springtime")==0)			
						{
							cout << '\n' << "         Alegeti dintre meniurile: Saorma Mare de pui sandwich(26,40 lei), Snitel Vienez pui(28,80 lei), Quesadilla Platou(29,60 lei), Snitel de pui Platou(28,00 lei): "; cin.getline(auxiliar_meniu, 1001);
							if(strcmp(auxiliar_meniu, "Saorma Mare de pui sandwich")==0)
								return 26.40;
							else
								if(strcmp(auxiliar_meniu, "Snitel Vienez pui")==0)
									return 28.80;
								else
									if(strcmp(auxiliar_meniu, "Quesadilla Platou")==0)
										return 29.60;
									else
										if(strcmp(auxiliar_meniu, "Snitel de pui Platou")==0)
											return 28.00;
						}
	 
			
}
int confirmare()
{
		cout << '\n' << "***************************************************************************************************************************" <<'\n';
		cout << '\n' << "                  COMANDA CONFIRMATA !";
		cout << '\n' << '\n' << "		Ati comandat de la restaurantul/restaurantele: " << persoana[clienti].restaurant;
		cout << '\n' << "		Ati comandat pe numele: " << persoana[clienti].nume;
		cout << '\n' << "		La adresa: " << persoana[clienti].strada;
		cout << '\n' << "		Cu numarul de telefon: 0" << persoana[clienti].numar;
		cout << '\n' << "       		Meniul/ meniurile: " << persoana[clienti].meniu;
		cout << '\n' << '\n' << "      		 Costul total este: " << persoana[clienti].pret << " lei";
		cout << '\n' << "       	Comanda va ajunge in aproximativ 60 de minute, va multumim ca ati comandat de la noi!";
		cout << '\n' << '\n' << "***************************************************************************************************************************" <<'\n';
}
int INCEPUT(int &clienti)
{
	if(clienti==0)
	{
		int a=introducere();
		if(a==1)
		{
			citire(clienti);
			cin.get();
			dictionar(numar, auxiliar);
			persoana[clienti].pret+=alegere_restaurant_si_meniu(clienti);
			int b=intrebare();
			if(b==1)
			{
				char aux1[1001], aux2[1001];
				persoana[clienti].pret+=alegere_restaurant_si_meniu2(clienti, aux1, aux2);
				strcat(persoana[clienti].restaurant, " si ");
				strcat(persoana[clienti].meniu, " si ");
				strcat(persoana[clienti].restaurant, aux1);
				strcat(persoana[clienti].meniu, aux2);
				confirmare();
			}
			else 
				confirmare();
			char x[10], y[10], z[10];
			cout << '\n' << "        Doriti sa mai faceti o comanda?: "; cin.getline(x, 10);
			if(strcmp(x, "da")==0)
				return INCEPUT(clienti);
			else
				cout << '\n' << "        Doriti sa verificati datele?: "; cin.get(); cin.getline(y, 10);
			if(strcmp(y, "da")==0)
				cout << '\n' << "        Introduceti codul: "; cin.get(); cin.getline(z, 10);
			if(strcmp(z, "1234")==0)
			{
				cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
				cout << "       N U M E       |      S T R A D A     |      N U M A R     |    R E S T A U R A N T E      |       M E N I U R I     " <<'\n';
				cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
				for(int i=1; i<=clienti; i++)
				{
					while(numar[persoana[i].numar_ordine]->info!=persoana[i].numar)
					numar[persoana[i].numar_ordine]=numar[persoana[i].numar_ordine]->next;		
					cout <<"  " << persoana[i].nume << " | " << persoana[i].strada << " | " << numar[persoana[i].numar_ordine]->info << " | " << persoana[i].restaurant << " | " << persoana[i].meniu <<'\n';                                                                                                                        
				}
				cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
			}
			else
				cout << '\n' << "         COD INCORECT !!! ";
		}
	}
	else
	{
		citire(clienti);
		cin.get();
		dictionar(numar, auxiliar);
		persoana[clienti].pret+=alegere_restaurant_si_meniu(clienti);
		int b=intrebare();
		if(b==1)
		{
			char aux1[1001], aux2[1001];
			persoana[clienti].pret+=alegere_restaurant_si_meniu2(clienti, aux1, aux2);
			strcat(persoana[clienti].restaurant, " si ");
			strcat(persoana[clienti].meniu, " si ");
			strcat(persoana[clienti].restaurant, aux1);
			strcat(persoana[clienti].meniu, aux2);
			confirmare();
		}
		else 
			confirmare();
		char x[10], y[10], z[10];
		cout << '\n' << "        Doriti sa mai faceti o comanda?: "; cin.get(); cin.getline(x, 10);
		if(strcmp(x, "da")==0)
			return INCEPUT(clienti);
		else
			cout << '\n' << "        Doriti sa verificati datele?: "; cin.get (); cin.getline(y, 10);
		if(strcmp(y, "da")==0)
			cout << '\n' << "        Introduceti codul: "; cin.get(); cin.getline(z, 10);
		if(strcmp(z, "1234")==0)
		{
			cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
			cout << "       N U M E       |      S T R A D A     |      N U M A R     |    R E S T A U R A N T E      |       M E N I U R I     " <<'\n';
			cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
			for(int i=1; i<=clienti; i++)
			{
				while(numar[persoana[i].numar_ordine]->info!=persoana[i].numar)
				numar[persoana[i].numar_ordine]=numar[persoana[i].numar_ordine]->next;		
				cout <<"  " << persoana[i].nume << " | " << persoana[i].strada << " | " << numar[persoana[i].numar_ordine]->info << " | " << persoana[i].restaurant << " | " << persoana[i].meniu <<'\n';                                                                                                                        
			}
			cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
		}
		else
			cout << '\n' << "         COD INCORECT !!! ";;
			
	}
}
int main()
{
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
	cout << "                                     _                                                                                     " <<'\n';
	cout << "     _____                          |_|                                                                                    " <<'\n';
	cout << "    |  ___|   _     _   _________    _    ________                                                                         " <<'\n'; 
	cout << "    | |___   | |   | | |___   ___|  | |  |  ______|                                                                        " <<'\n';
	cout << "    |___  |  | |   | |     | |      | |  | |                                                                               " <<'\n';
	cout << "     ___| |  | |___| |     | |      | |  | |______                                                                         " <<'\n';
	cout << "    |_____|  |_______|     |_|      |_|  |________|       ____  ___   ___   ___                                            " <<'\n';
	cout << "                                                         |___  |   | |   | |   |                                           " <<'\n';
	cout << "                                                         |     | | | | | | | | |                                           " <<'\n';
	cout << "                                                         |     |___| |___| |__/                                            " <<'\n';
	cout << "                                                                    ___   __      *         __   __                        " <<'\n';
	cout << "                                                                   |   | |    |   | $    / |    |__|  $   /                " <<'\n';
	cout << "                                                                   | | | |--  |   |  $  /  |--  |$     $ /                 " <<'\n';
	cout << "                                                                   |__/  |__  |__ |   $/   |__  | $     /                  " <<'\n';
	cout << "                                                                                                                           " <<'\n';
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
	for(int i=0; i<10001; i++)
    {
        numar[i]=new nod;
        numar[i]->next=0;
    }
   INCEPUT(clienti);

}