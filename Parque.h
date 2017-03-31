#ifndef PARQUE
#define PARQUE
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Parque
{
public:

    Parque() {}
    ~Parque() {}

    int maxAtracciones;

    std::vector<int> busquedaExhaustiva(const int** espera, int m, int n, const int* disfrute,  const int**  traslado)
    {
        copiaEspera(espera,m,n);
        tFinal = m;
        cantAtracciones = n;
        copiaDisfrute(disfrute, n);
        copiaTraslado(traslado,n);
        maxAtracciones = fase(-1,0);
        return sigma;
    }

    std::vector<int> programacionDinamica(const int** espera, int m, int n, const int* disfrute, const int** traslado)
    {

        tFinal = m;
        cantAtracciones = n;
        maxAtracciones = 0;
        sigma.clear();
        inicializarM();
        crearOraculo(espera,disfrute, traslado);

        int cantidad = 0, cantidadMaxima = 0, tiempoOpt, atraccionOpt = 0;

        for (int j = 0; j <= cantAtracciones-1 ; j++)
        {
            if(traslado[0][j]  < tFinal)
            {
                if(traslado[0][j] + espera[traslado[0][j]][j] + disfrute[j] < tFinal)
                {
                    cantidad = oraculoD [traslado[0][j] + espera[traslado[0][j]][j] + disfrute[j]][j];

                    if(cantidad > cantidadMaxima)
                    {
                        cantidadMaxima = cantidad;
                        tiempoOpt=traslado[0][j] + espera[traslado[0][j]][j] + disfrute[j];
                        atraccionOpt = j;
                    }
                }
            }
        }

        if(cantidadMaxima != 0)
            crearSigma (atraccionOpt, tiempoOpt, cantidadMaxima,  espera, disfrute, traslado);

        maxAtracciones = cantidadMaxima;

        return sigma;
    }


    std::vector<int> algoritmoAvido(const int** espera, int m, int n, const int* disfrute, const int** traslado);

private:

    int** espera;
    int* disfrute;
    int** traslado;
    int tFinal, cantAtracciones;
    std::vector <int> sigma;

    int** oraculoD;
    int ** horaD ;
    int **atraccionesD;

    int fase(int atraccion, int tiempo)
    {
        int cantidad = 0;
        int cantidadMaxima = 0;
        std::vector <int> sigmaMax;
        if (atraccion != -1)
        {
            if((tiempo + traslado[atraccion][cantAtracciones]) == tFinal)
                return 1;
            if( (tiempo + traslado[atraccion][cantAtracciones]) >= tFinal)
                return 0;
        }

        //Entrada
        if (atraccion == -1)
        {
            for (int j = 0; j <= cantAtracciones-1 ; j++)
            {
                if( (traslado[0][j] + tiempo) < tFinal)
                {
                    cantidad = fase(j, tiempo + traslado[0][j] + espera[traslado[0][j]+ tiempo] [j] + disfrute[j]);
                    if(cantidad != 0)
                    {
                        if(cantidad >= cantidadMaxima)
                        {
                            cantidadMaxima = cantidad;
                            sigma.insert(sigma.begin(), j);
                            sigmaMax = sigma;
                            sigma.clear();
                        }
                    }
                }
            }
        }
        else
        {
            for (int j = 0; j <= cantAtracciones-1 ; j++)
            {
                if(atraccion != j && (traslado[atraccion+1][j] + tiempo) < tFinal)
                {
                    cantidad = fase(j, tiempo + traslado[atraccion+1][j] + espera[traslado[atraccion+1][j] + tiempo] [j] + disfrute[j]);
                    if( cantidad != 0)
                    {
                        if( cantidad >= cantidadMaxima )
                        {
                            cantidadMaxima = cantidad;
                            sigma.insert(sigma.begin(),j);
                            sigmaMax = sigma;
                            sigma.clear();
                        }
                    }
                }
            }
        }

        if(atraccion != -1)
            cantidadMaxima++;
        sigma = sigmaMax;
        return cantidadMaxima;
    }

    void copiaEspera(const int** M, int m, int n)
    {
        int filas = m;
        int columnas = n;
        espera =  new int*[filas];

        for (int i=0; i< filas; i++)
            espera [i] = new int [columnas];

        for ( int i = 0; i < filas; i++ )
        {
            for ( int j = 0; j < columnas; j++ )
                espera [i][j] = M [i][j];
        }
    }

    void copiaTraslado( const int** M, int n)
    {
        int filas = n + 1;
        int columnas = n + 1;
        traslado = new int*[filas];

        for (int i = 0; i < filas; i++)
            traslado [i] = new int [columnas];

        for ( int i = 0; i < filas; i++)
        {
            for ( int j = 0; j < columnas; j++ )
                traslado [i][j] = M [i][j];
        }
    }

    void copiaDisfrute(const int* vec, int n)
    {
        int columnas = n;
        disfrute = new int [columnas];

        for ( int i = 0; i < columnas; i++)
            disfrute [i] = vec [i];
    }

    //Crear oraculo
    void crearOraculo (const int** espera, const int* disfrute, const int** traslado)
    {
        int maxDis = 0;
        int maxAct = 0;

        for (int i = tFinal-1; i >= 0 ; i--)
        {
            for(int j = 0; j < cantAtracciones; j++)
            {
                if(i + traslado[j+1][cantAtracciones] == tFinal)
                    oraculoD[i][j] = 1;
                else if( i + traslado[j+1][cantAtracciones] > tFinal || i < traslado[0][j] + espera[traslado[0][j]][j] + disfrute[j])
                    oraculoD[i][j] = 0;
                else
                {
                    maxAct = 0;
                    maxDis = 0;
                    oraculoD[i][j] = 1;

                    for (int k = 0; k < cantAtracciones; k++)
                    {
                        if(traslado[j+1][k] + i < tFinal  &&  j != k)
                        {
                            if(i + traslado[j+1][k] + espera[traslado[j+1][k] + i][k] + disfrute[k] < tFinal)
                            {
                                maxDis = oraculoD [ i + traslado[j+1][k] + espera[traslado[j+1][k] + i] [k] + disfrute[k]][k];
                                if(maxDis >  maxAct)
                                {
                                    maxAct = maxDis;
                                    horaD[i][j] = i + traslado[j+1][k] + espera[traslado[j+1][k] + i][k] + disfrute[k];
                                    atraccionesD [i][j]= k;
                                }
                            }
                        }
                    }

                    oraculoD[i][j] = oraculoD[i][j] + maxAct;
                }
            }
        }
    }

    //vector sigma
    void crearSigma(int atraccion, int hora, int maxVisitados,const int** espera, const int* disfrute, const int** traslado)
    {
        int sgteHora = hora;
        int sgteAtraccion = atraccion;
        int horaTemp = 0;
        int atraccionTemp = 0;
        int visitas = maxVisitados;

        for(int i = visitas; i > 0; i--)
        {
            if(i != 1)
            {
                sigma.push_back(sgteAtraccion);
                horaTemp = horaD [sgteHora][sgteAtraccion];
                atraccionTemp = atraccionesD [sgteHora][sgteAtraccion];
                sgteHora = horaTemp;
                sgteAtraccion = atraccionTemp;
            }
            else
                sigma.push_back(sgteAtraccion);
        }
    }

    void inicializarM()
    {
        oraculoD = new int* [tFinal];
        horaD = new int* [tFinal];
        atraccionesD = new int* [tFinal];

        for (int i = 0; i < tFinal; i++)
        {
            oraculoD[i] = new int[cantAtracciones];
            horaD[i] = new int[cantAtracciones];
            atraccionesD[i] = new int[cantAtracciones];
        }

        for (int i = 0; i < tFinal; i++)
        {
            for(int j = 0; j < cantAtracciones; j++)
            {
                horaD [i][j] = -1;
                atraccionesD[i][j] = -1;
            }
        }
    }

};
#endif

