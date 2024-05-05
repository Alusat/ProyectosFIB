/** @file Estacion.hh
    @brief Especificación de la clase Estacion
*/

#ifndef _ESTACION_
#define _ESTACION_

#include"Bicicletas.hh"
#include"Bicicleta.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include<set>
#include<string>
using namespace std;
#endif
/*
 * Clase Estacion
 */

 /** @class Estacion
     @brief Representa el conjunto de características y operaciones de una estación.

     Ofrece una operacion de escritura.
 */
class Estacion {

private:
    /** @brief Indice de tamaño*/
    int size; 
    /** @brief Set de bicicletas que contiene la estacion*/
    set<string> bicicletas;

public:

    // Constructora
    /** @brief Creadora por defecto
        @pre Cierto
        @post El resultado es una estación sin bicicletas, pero con su identifador y capacidad
    */
    Estacion(int size);


    // CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC  Consultoras  CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC


    /** @brief Consultora que indica el numero de bicis que tiene una estacion
        \pre Cierto
        \post Retorna el numero de bicis que tiene la estacion
    */
    int n_bicis();


    /** @brief Consultora que indica el tamaño de la estacion
        \pre Cierto
        \post Retorna el tamaño de la estacion
    */
    int tamano();


    /** @brief Consultora que retorna la bicicleta con menor id
        \pre Cierto
        \post Retorna el id de la bicicleta de la estacion con menor id
    */
   string bici_menor_id();


    //OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO Operaciones OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
    /** @brief Añade una bici (su id) a la estacion
        \pre hay suficiente espaio para que quepa la bicicleta
        \post Se ha añadido el id de la bicicleta a la estacion en el set que las almacena 
    */
     void meter_bicicleta(string identifiacdor_bici);


    /** @brief Modifica la capacidad maixma de la estacion
    \pre La nueva capacidad es menor o igual al numero de bicicletas que se encuentran en la estacion
    \post Se ha modificado la capacidad
    */
    void modifica_capacidad(const int& x);


    /** @brief Elimina una bicicleta de la estacion 
    \pre La bicicleta existe
    \post La bicicleta queda eliminada de la estacion
    */
    void eliminar(string identificador_bici);


    //EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE Escritura EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEee


    /** @brief Escribi las bicicletas que contiene una estacion
    \pre Cierto
    \post Quedan escrito por pantalla las bicicletas en el formato: Bicicleta, salto de línea, bicicleta, salto de línea...
    */
    void escribe_bicis();
};
#endif

