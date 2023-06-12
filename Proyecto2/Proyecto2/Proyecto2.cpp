#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Guardian  // Estructura que contiene las características de cada guardian
{
	string name;
	int powerLevel;
	string mainMaster;
	string village;
	vector<Guardian> aprendices;  // Si el personaje es un maestro, significa que tiene aprendices, los cuales se guardarán aquí
};

vector<Guardian> comprobarMaestros(vector<Guardian> lista)  
{
	vector<Guardian> ListaFinal = lista;

	for (int i = 0; i < lista.size() ; i++)
	{
		for (int j = 0; j < lista.size(); j++)
		{
			if (lista[i].name == lista[j].mainMaster) // Con esta función se verifica si un nombre de un guardian esta como maestro de otro, lo cual significa que es un maestro 
			{
				ListaFinal[i].aprendices.push_back(ListaFinal[j]);  // Aquí se añade el aprendiz al vector de aprendices del guardian maestro
			}
		}
	}

	return ListaFinal;  // Se retorna el vector
}

int main()
{
	Guardian arbol;
	string nombre;
	int poder;
	string maestro;
	string aldea;
	ifstream fich;
	Guardian miPersonaje;
	vector<Guardian> readGuardianVector;
	vector<string> ciudades;
	bool guardSelect = false;
	int eleccion2;
	ciudades.push_back("Capital City");
	ciudades.push_back("Tesla");
	ciudades.push_back("Forest Village");
	ciudades.push_back("Mountain Village");
	ciudades.push_back("Desert Village");
	ciudades.push_back("Coast Village");
	ciudades.push_back("River Village");
	ciudades.push_back("Valley Village");
	ciudades.push_back("Hill Village");
	ciudades.push_back("Cliff Village");
	ciudades.push_back("Island Village");
	ciudades.push_back("Storm Village");

	fich.open("Aprendices.txt");  // Se abre el archivo con este nombre y que se encuentra en la carpeta del programa
	if (fich.is_open())  // Si el archivo se abrió correctamente, entonces se realiza todo esto
	{
		Guardian data;
		while (fich >> nombre >> poder >> maestro)
		{
			data.name = nombre;
			data.powerLevel = poder;
			data.mainMaster = maestro;
			getline(fich >> ws, aldea);
			data.village = aldea;
			readGuardianVector.push_back(data);
		}
	}
	else  // Esto ocurre cuando el archivo no se pudo abrir, ya sea porque tiene otro nombre u otra ubicacion
	{
		cout << "Error al abrir el archivo\n";
		exit(EXIT_FAILURE);
	}
	fich.close();  // Una vez hecho todo, se cierra el archivo

	readGuardianVector = comprobarMaestros(readGuardianVector);  // readGuardianVector contiene a todos los guardianes con sus respectivos discipulos, si es que tiene alguno

	/*for (const Guardian& data : readGuardianVector)  // Utilicé estos for para comprobar si se guardaron correctamente los guardianes y las ciudades
	{
		cout << "Nombre: " << data.name << endl;
		cout << "Poder: " << data.powerLevel << endl;
		cout << "Maestro: " << data.mainMaster << endl;
		cout << "Aldea: " << data.village << endl;
		for (int i = 0; i < data.aprendices.size(); i++)
		{
			cout << "Aprendices: " << data.aprendices[i].name << endl;
		}
		cout << endl;
	}

	for (const string& data : ciudades)
	{
		cout << "Ciudad: " << data << endl;
	}*/

	int ciclo = 1;
	int eleccion = 0;
	int guardSelected=0;
	srand((unsigned)time(NULL));

	while (ciclo == 1)
	{
		system("cls");
		cout << "/////////Bienvenido/////////" << endl;
		cout << "1. Iniciar juego" << endl;
		cout << "2. Crear un personaje" << endl;
		cout << "3. Elegir un personaje" << endl;
		cout << "4. Mi personaje" << endl;
		cout << "5. Salir" << endl;

		cin >> eleccion;

		switch (eleccion)  // Dependiendo de la eleccion del jugador, se comienza con una funcion u otra
		{
		case 1:
			// Inicia el juego
			break;
		case 2:
			// Crear personaje
			system("cls");
			cout << "Ingrese el nombre de su personaje: " << endl;
			cin >> nombre;
			for (int i = 0; i < ciudades.size(); i++)
			{
				if (ciudades[i] != "Tesla")
				{
					cout << i + 1 << ". " << ciudades[i] << endl;  // Se imprimen las ciudades menos Tesla
				}
			}
			cout << "Seleccione una aldea en donde comenzar ingresando el numero correspondiente: ";
			cin >> eleccion2;
			switch (eleccion2)  // Se asignan el nombre y la aldea al personaje del usuario, su nivel de poder se vuelve 50 y no tiene maestro
			{
			case 1:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[0];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				guardSelect = true;
				break;
			case 2:
				cout << "El numero ingresado no corresponde con ninguna aldea..." << endl;
				system("pause");
				break;
			case 3:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[2];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				guardSelect = true;
				break;
			case 4:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[3];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				guardSelect = true;
				break;
			case 5:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[4];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				guardSelect = true;
				break;
			case 6:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[5];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				guardSelect = true;
				break;
			case 7:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[6];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				guardSelect = true;
				break;
			case 8:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[7];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				guardSelect = true;
				break;
			case 9:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[8];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				guardSelect = true;
				break;
			case 10:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[9];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				guardSelect = true;
				break;
			case 11:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[10];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				guardSelect = true;
				break;
			case 12:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[11];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				guardSelect = true;
				break;
			}
			break;
		case 3:
			// Elegir un personaje
			system("cls");
			for (int i = 0; i < readGuardianVector.size(); i++)
			{
				if (readGuardianVector[i].aprendices.size() == 0)  // Se imprimen aquellos guardianes que no sean maestros, es decir, que no tengan aprendices dentro de su respectivo vector
				{
					cout << i + 1 << ". " << endl;
					cout << "Nombre: " << readGuardianVector[i].name << endl;
					cout << "Poder: " << readGuardianVector[i].powerLevel << endl;
					cout << "Maestro: " << readGuardianVector[i].mainMaster << endl;
					cout << "Aldea: " << readGuardianVector[i].village << endl;
					cout << endl;
				}

			}
			cout << "Seleccione un guardian ingresando el numero correspondiente: ";
			cin >> guardSelected;
			if (readGuardianVector[guardSelected - 1].aprendices.size() > 0)
			{
				cout << "El numero que ingreso no existe como numero de guardian disponible..."<< endl;
				system("pause");
			}
			else
			{
				miPersonaje = readGuardianVector[guardSelected - 1];  // El personaje del usuario copia los atributos del guardian seleccionado y luego este ultimo se borra de la lista
				miPersonaje.powerLevel = 50;
				readGuardianVector.erase(readGuardianVector.begin() + (guardSelected - 1));
				system("cls");
				cout << "Guardian seleccionado correctamente!" << endl;
				cout << "Su guardian es:" << endl;
				cout << "Nombre: " << miPersonaje.name << endl;
				cout << "Poder: " << miPersonaje.powerLevel << endl;
				cout << "Maestro: " << miPersonaje.mainMaster << endl;
				cout << "Aldea: " << miPersonaje.village << endl << endl;
				guardSelect = true;
				system("pause");
			}
			break;
		case 4:
			// Imprimir mi personaje
			system("cls");
			if (guardSelect == true)
			{
				cout << "Su guardian es:" << endl;
				cout << "Nombre: " << miPersonaje.name << endl;  // Se imprime el personaje seleccionado
				cout << "Poder: " << miPersonaje.powerLevel << endl;
				cout << "Maestro: " << miPersonaje.mainMaster << endl;
				cout << "Aldea: " << miPersonaje.village << endl << endl;
			}
			else
			{
				cout << "Aun no ha elegido un personaje..." << endl;  // Si no se ha elegido o creado un personaje, aparece este mensaje
			}
			system("pause");
			break;
		case 5:
			// Salir
			exit(1);  // Se termina la ejecucion del programa
			break;
		}
	}

	return 1;
}