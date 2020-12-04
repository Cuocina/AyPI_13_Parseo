#include<iostream>

using namespace std;

struct Campo {
	char valor[20];
};

struct Registro {
	int cantidadCampos;
	Campo campos[5];
};

struct ArchivoCSV {
	int cantidadRegistros;
	Registro registros[7];
};

void Copiar(char* origen, char* destino) {
	while (*destino++ = *origen++);
}

// Precondiciones: @campoACargar es una instancia valida
void CargarCampo(Campo* campoACargar, char *valorCampo) {
	Copiar(valorCampo, campoACargar->valor);
}

// Precondicion: @registro es una instancia valida. @campos tiene una cantidad de filas igual a @cantidadFilas y cada fila es una cadena de caracteres

void CargarRegistro(Registro* registro, char campos[3][20], int cantidadFilas) {
	registro->cantidadCampos = cantidadFilas;
	for (int i = 0; i < cantidadFilas; i++) {
		CargarCampo(&(registro->campos[i]), campos[i]);
	}
}

void MostrarRegistro(Registro* registro) {
	for (int numeroCampo = 0; numeroCampo < registro->cantidadCampos; ++numeroCampo) {
		cout << "Campo nro " << numeroCampo << " :" << registro->campos[numeroCampo].valor << endl;
	}
}

struct ResultadoSeparacion {
	char matriz[100][100];
	int cantidadFilas;
};

// Precondicion: @texto es una cadena de caracteres. @resultado es una instanacia valida
// Postcondicion: En cada fila de @resutlado.matriz hay una cadena de caracteres que se corresponde a separa la cadena @texto por @separador
void Separar(char* texto, char separador, ResultadoSeparacion& resultado);

//Precondicion: @resultado es una instancia valida
void Mostrar(ResultadoSeparacion *resultado) {
	for (int i = 0; resultado->cantidadFilas; ++i) {
		cout << resultado->matriz[i] << endl;
	}
}

int main() {
	Registro fiat600Azul;
	char campos[3][20] = { {"FIAT"},{"Azul"},{"600"} };
	CargarRegistro(&fiat600Azul, campos, 3);
	MostrarRegistro(&fiat600Azul);
	return 0;
}
