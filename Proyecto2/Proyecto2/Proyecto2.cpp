#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class Mapa
{
	private:
		int numVertices;
		vector<vector<int>> adjacencyList;

	public:
		Mapa(int vertices) 
		{
			numVertices = vertices;
			adjacencyList.resize(vertices);
		}

		void addEdge(int origen, int destino) 
		{
			adjacencyList[origen].push_back(destino);
			adjacencyList[destino].push_back(origen);
		}

		void printGraph() {
			for (int i = 0; i < numVertices; i++) {
				cout << "Vertex " << i << ": ";
				for (int j = 0; j < adjacencyList[i].size(); j++) {
					cout << adjacencyList[i][j] << " ";
				}
				cout << endl;
			}
		}
};

struct Guardian
{
	string name;
	int powerLevel;
	string mainMaster;
	string village;
	vector<Guardian> aprendices;
};

void dados()
{
	int random = 1 + (rand() % 6);
	cout << random << endl;
}
vector<Guardian> comprobarMaestros(vector<Guardian> lista)
{
	vector<Guardian> ListaFinal = lista;

	for (int i = 0; i < lista.size() ; i++)
	{
		for (int j = 0; j < lista.size(); j++)
		{
			if (lista[i].name == lista[j].mainMaster)
			{
				ListaFinal[i].aprendices.push_back(ListaFinal[j]);
			}
		}
	}

	return ListaFinal;
}
void comprobarConexiones()
{
	ifstream archivo;
	archivo.open("Mapa.txt");
	if (archivo.is_open())
	{
		string linea;
		while (getline(archivo, linea))
		{
		}
	}
	else
	{
		cout << "Error al abrir el archivo\n";
		exit(EXIT_FAILURE);
	}
	archivo.close();
}

int main()
{
	string nombre;
	int poder;
	string maestro;
	string aldea;
	ifstream fich;
	Guardian miPersonaje;
	fich.open("Aprendices.txt");
	vector<Guardian> readGuardianVector;
	vector<string> ciudades;
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
	if (fich.is_open())
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
	else
	{
		cout << "Error al abrir el archivo\n";
		exit(EXIT_FAILURE);
	}
	fich.close();

	readGuardianVector = comprobarMaestros(readGuardianVector);

	/*for (const Guardian& data : readGuardianVector)
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

	while (ciclo = 1)
	{
		system("cls");
		cout << "/////////Bienvenido/////////" << endl;
		cout << "1. Iniciar juego" << endl;
		cout << "2. Crear un personaje" << endl;
		cout << "3. Elegir un personaje" << endl;
		cout << "4. Mi personaje" << endl;
		cout << "5. Salir" << endl;

		cin >> eleccion;

		switch (eleccion)
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
				cout << i+1 << ". " << ciudades[i] << endl;
			}
			cout << "Seleccione una aldea en donde comenzar ingresando el numero correspondiente: ";
			cin >> eleccion2;
			switch (eleccion2)
			{
			case 1:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[0];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				break;
			case 2:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[1];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				break;
			case 3:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[2];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				break;
			case 4:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[3];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				break;
			case 5:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[4];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				break;
			case 6:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[5];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				break;
			case 7:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[6];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				break;
			case 8:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[7];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				break;
			case 9:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[8];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				break;
			case 10:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[9];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				break;
			case 11:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[10];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				break;
			case 12:
				miPersonaje.name = nombre;
				miPersonaje.village = ciudades[11];
				miPersonaje.powerLevel = 50;
				miPersonaje.mainMaster = "NONE";
				readGuardianVector.push_back(miPersonaje);
				break;
			}
			system("cls");
			cout << "Su personaje es el siguiente: " << endl;
			cout << "Nombre: " << readGuardianVector[readGuardianVector.size()-1].name << endl;
			cout << "Poder: " << readGuardianVector[readGuardianVector.size()-1].powerLevel << endl;
			cout << "Maestro: " << readGuardianVector[readGuardianVector.size()-1].mainMaster << endl;
			cout << "Aldea: " << readGuardianVector[readGuardianVector.size()-1].village << endl << endl;
			cout << "Presione una tecla para continuar...";
			getchar();
			getchar();
			break;
		case 3:
			// Elegir un personaje
			system("cls");
			for (int i = 0; i < readGuardianVector.size(); i++)
			{
				if (readGuardianVector[i].aprendices.size() == 0)
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
				cout << "El numero que ingreso no existe como numero de guardian disponible, intentelo nuevamente...";
				getchar();
				getchar();
			}
			else
			{
				miPersonaje = readGuardianVector[guardSelected - 1];
				miPersonaje.powerLevel = 50;
				readGuardianVector.erase(readGuardianVector.begin() + (guardSelected - 1));
				system("cls");
				cout << "Guardian seleccionado correctamente!" << endl;
				cout << "Su guardian es:" << endl;
				cout << "Nombre: " << miPersonaje.name << endl;
				cout << "Poder: " << miPersonaje.powerLevel << endl;
				cout << "Maestro: " << miPersonaje.mainMaster << endl;
				cout << "Aldea: " << miPersonaje.village << endl << endl;
				cout << "Presione una tecla para continuar...";
				getchar();
				getchar();
				
			}
			break;
		case 4:
			// Imprimir mi personaje
			system("cls");
			cout << "Su guardian es:" << endl;
			cout << "Nombre: " << miPersonaje.name << endl;
			cout << "Poder: " << miPersonaje.powerLevel << endl;
			cout << "Maestro: " << miPersonaje.mainMaster << endl;
			cout << "Aldea: " << miPersonaje.village << endl << endl;
			cout << "Presione una tecla para continuar...";
			getchar();
			getchar();
			break;
		case 5:
			// Salir
			exit(1);
			break;
		}
	}

	return 1;
}