#include "Parque.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>

using namespace std;

int ** leerEspera()
{
    int ** matriz;
    int filas = 120;
    int columnas = 13;
    std::ifstream entrada;
    int i = -1;
    int hora , Bocaraca , Bumeran , Choconcitos , ChoconesAdultos , Minitorre , Pacuare , PlayParque;
    int Pulpo, RuedadeChicago , SkyMaster , Teletren , Tornado , Torre;

    matriz = new int*[filas];
    for (int i = 0; i < filas; i++)
        matriz[i] = new int[columnas];

    entrada.open("espera.csv", ios::in);
    entrada >> hora >> Bocaraca >> Bumeran >> Choconcitos >> ChoconesAdultos >> Minitorre >> Pacuare
            >> PlayParque >> Pulpo >> RuedadeChicago >> SkyMaster >> Teletren >> Tornado >> Torre;

    while(!entrada.eof())
    {
        i++;

        matriz[i][0] = Bocaraca;
        matriz[i][1] = Bumeran;
        matriz[i][2] = Choconcitos;
        matriz[i][3] = ChoconesAdultos;
        matriz[i][4] = Minitorre;
        matriz[i][5] = Pacuare;
        matriz[i][6] = PlayParque;
        matriz[i][7] = Pulpo;
        matriz[i][8] = RuedadeChicago;
        matriz[i][9] = SkyMaster;
        matriz[i][10] = Teletren;
        matriz[i][11] = Tornado;
        matriz[i][12] = Torre;

        entrada >> hora >> Bocaraca >> Bumeran >> Choconcitos >> ChoconesAdultos >> Minitorre >> Pacuare
                >> PlayParque >> Pulpo >> RuedadeChicago >> SkyMaster >> Teletren >> Tornado >> Torre;
    }

    matriz[i][0] = Bocaraca;
    matriz[i][1] = Bumeran;
    matriz[i][2] = Choconcitos;
    matriz[i][3] = ChoconesAdultos;
    matriz[i][4] = Minitorre;
    matriz[i][5] = Pacuare;
    matriz[i][6] = PlayParque;
    matriz[i][7] = Pulpo;
    matriz[i][8] = RuedadeChicago;
    matriz[i][9] = SkyMaster;
    matriz[i][10] = Teletren;
    matriz[i][11] = Tornado;
    matriz[i][12] = Torre;

    return matriz;
}

int** intervaloEspera(int** const espera, int inicio, int final)
{
    int filas = final - inicio;
    int columnas = 13;
    int** matriz = new int*[filas];

    for (int i = 0; i < filas; i++)
        matriz [i] = new int [columnas];

    int h = 0;

    for (int i = inicio; i < final; i++)
    {
        for (int j = 0; j < columnas; j++)
            matriz [h][j] = espera [i][j];

        h++;
    }
    return matriz;
}

int** leerTraslado()
{
    int ** matriz;
    int tamano = 14;
    std::ifstream entrada;
    int i = -1;
    int Bocaraca, Bumeran, Choconcitos, ChoconesAdultos, Minitorre, Pacuare, PlayParque;
    int Pulpo, RuedadeChicago, SkyMaster, Teletren, Tornado, Torre, salida;

    matriz = new int* [tamano];

    for (int i=0; i < tamano; i++)
        matriz[i] = new int [tamano] ;

    entrada.open("traslado.csv", ios::in);

    entrada >> Bocaraca >> Bumeran >> Choconcitos >> ChoconesAdultos >> Minitorre >> Pacuare
            >> PlayParque >> Pulpo >> RuedadeChicago >> SkyMaster >> Teletren >> Tornado >> Torre >> salida;

    while(!entrada.eof())
    {
        i++;

        matriz[i][0] = Bocaraca;
        matriz[i][1] = Bumeran;
        matriz[i][2] = Choconcitos;
        matriz[i][3] = ChoconesAdultos;
        matriz[i][4] = Minitorre;
        matriz[i][5] = Pacuare;
        matriz[i][6] = PlayParque;
        matriz[i][7] = Pulpo;
        matriz[i][8] = RuedadeChicago;
        matriz[i][9] = SkyMaster;
        matriz[i][10] = Teletren;
        matriz[i][11] = Tornado;
        matriz[i][12] = Torre;
        matriz[i][13] = salida;

        entrada >> Bocaraca >> Bumeran >> Choconcitos >> ChoconesAdultos >> Minitorre >> Pacuare
                >> PlayParque >> Pulpo >> RuedadeChicago >> SkyMaster >> Teletren >> Tornado >> Torre >> salida;
    }

    matriz[i][0] = Bocaraca;
    matriz[i][1] = Bumeran;
    matriz[i][2] = Choconcitos;
    matriz[i][3] = ChoconesAdultos;
    matriz[i][4] = Minitorre;
    matriz[i][5] = Pacuare;
    matriz[i][6] = PlayParque;
    matriz[i][7] = Pulpo;
    matriz[i][8] = RuedadeChicago;
    matriz[i][9] = SkyMaster;
    matriz[i][10] = Teletren;
    matriz[i][11] = Tornado;
    matriz[i][12] = Torre;
    matriz[i][13] = salida;

    return matriz;
}


int* leerDisfrute()
{
    std::ifstream entrada;
    int Bocaraca, Bumeran, Choconcitos, ChoconesAdultos, Minitorre, Pacuare, PlayParque;
    int Pulpo, RuedadeChicago, SkyMaster, Teletren, Tornado, Torre;

    int * disfrute = new int[13];
    entrada.open("disfrute.csv", std::ios::in);

    entrada >> Bocaraca >> Bumeran >> Choconcitos >> ChoconesAdultos >> Minitorre >> Pacuare
            >> PlayParque >> Pulpo >> RuedadeChicago >> SkyMaster >> Teletren >> Tornado >> Torre ;

    disfrute[0] = Bocaraca;
    disfrute[1] = Bumeran;
    disfrute[2] = Choconcitos;
    disfrute[3] = ChoconesAdultos;
    disfrute[4] = Minitorre;
    disfrute[5] = Pacuare;
    disfrute[6] = PlayParque;
    disfrute[7] = Pulpo;
    disfrute[8] = RuedadeChicago;
    disfrute[9] = SkyMaster;
    disfrute[10] = Teletren;
    disfrute[11] = Tornado;
    disfrute[12] = Torre;

    return disfrute;
}

void imprimirResultado(std::vector<int> atracciones, Parque p)
{
    std::cout << "\n~ ~ ~ ~ ~ ~ ~ RESULTADOS OBTENIDOS ~ ~ ~ ~ ~ ~ ~ \n" << std::endl;
    std::cout << "\nRuta a seguir:  \n\n";

    int j = 1;

    for ( std::vector<int>::iterator i = atracciones.begin() ; i != atracciones.end(); i++)
    {
        std::cout << j << " ";
        switch(*i)
        {
        case 0:
            std::cout<< "~ Bocaraca"<< std::endl;
            break;
        case 1:
            std::cout<< "~ Bumeran"<< std::endl;
            break;
        case 2:
            std::cout<< "~ Choconcitos"<< std::endl;
            break;
        case 3:
            std::cout<< "~ Chocones Adultos"<< std::endl;
            break;
        case 4:
            std::cout<< "~ Minitorre"<< std::endl;
            break;
        case 5:
            std::cout<< "~ Pacuare"<< std::endl;
            break;
        case 6:
            std::cout<< "~ Play Parque"<< std::endl;
            break;
        case 7:
            std::cout<< "~ Pulpo"<< std::endl;
            break;
        case 8:
            std::cout<< "~ Rueda de Chicago"<< std::endl;
            break;
        case 9:
            std::cout<< "~ Sky Master"<< std::endl;
            break;
        case 10:
            std::cout<< "~ Teletren"<< std::endl;
            break;
        case 11:
            std::cout<< "~ Tornado"<< std::endl;
            break;
        case 12:
            std::cout<< "~ Torre"<< std::endl;
            break;
        }
        j++;
    }
    std::cout << "Cantidad maxima de atracciones a visitar: " << p.maxAtracciones << std::endl;
}

int horaLlegada(int opcion)
{
    switch(opcion)
    {
    case 9:
        return 0;
        break;
    case 10:
        return 12;
        break;
    case 1:
        return 48;
        break;
    case 2:
        return 60;
        break;
    case 3:
        return 72;
        break;
    }
}
int horaSalida(int opcion, int horaLlegada)
{
    switch(opcion)
    {
    case 1:
        return horaLlegada + (12);
        break;
    case 2:
        return horaLlegada + (24);
        break;
    case 3:
        return horaLlegada + (36);
        break;
    case 4:
        return horaLlegada + (48);
        break;
    }
}

int main()
{
    Parque parque;
    string opcion = "s";
    int entrada = 0;
    int salida = 0;
    int ** espera = leerEspera();
    int ** traslado = leerTraslado();
    int * disfrute = leerDisfrute();
    //int a = 1;
    //int b = 1;
    //int cont = 1;
    std::cout << "\n -------- VISITA DEL PROFESOR CASSASOLA AL PARQUE DE DIVERSIONES --------\n" << std::endl;
    std::cout << "Desea visitar el parque? s/n \n";

    std::cin >> opcion;

    do
    {
        std::cout << "\nPor favor indique su hora de llegada (9, 10, 1, 2 o 3\n";
        std::cin >> entrada;
        entrada = horaLlegada(entrada);
        std::cout << "\nCuantas horas desea permanecer en el parque? (1, 2, 3 o 4)\n";
        std::cin >> salida;
        salida = horaSalida(salida,entrada);
        //entrada = horaLlegada(a);
        //salida = horaSalida(b,entrada);
        int ** esperaInt = intervaloEspera(espera, entrada, salida);
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        std::vector <int> resultado = parque.programacionDinamica((const int**) esperaInt, salida - entrada, 13, disfrute, (const int**) traslado);
        end = std::chrono::system_clock::now();

        std::chrono::duration<float> elapsed_seconds = (end-start)*1000;

        imprimirResultado(resultado, parque);

        std::cout << "Tiempo de ejecucion: " << elapsed_seconds.count() << " segundos." <<std::endl;

        std::cout << "\nDesea seleccionar algun otro horario? s/n \n ";
        std::cin >> opcion;

    }
    while (opcion == "s");
}
