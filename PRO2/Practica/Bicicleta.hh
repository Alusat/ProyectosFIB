/** @file Bicicleta.hh
    @brief Especificación de la clase Bicicleta
*/

#ifndef _BICICLETA_
#define _BICICLETA_

#ifndef NO_DIAGRAM
#include <iostream>
#include <list> 
using namespace std;
#endif

/*
 * Clase Bicicleta
 */

 /** @class Bicicleta
     @brief Representa el conjunto de características y
     operaciones de una bicicleta.

     Ofrece una operacion de escritura.
     
 */
class Bicicleta {

private:
    /** @brief Identificador de la bicicleta */
    string identificador; 
    /** @brief Historial de estaciones en las cuales ha estado la bicicleta */
    list<pair<string, string>> historial;
    /** @brief Estacion actual en la que se encuentra la bicicleta*/
    string ubi;

public:

    //CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC Constructora CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC


    /** @brief Creadora por defecto
        @pre cierto
        @post El resultado es una bicicleta vacía, con identificador y historia de viajes vacio
    */
    Bicicleta(string identificador_bicicleta, string identificador_estacion);


    //OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO Operaciones OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO


    /** @brief Cambia el id de la  ubicacion actual de la bicicleta
        @pre La bicicleta existe
        @post La ubicacion de la bicicleta pasa a ser el id de la estacion
    */
    void mod_ubicacion(string& identificador_estacion);


    /** @brief Mueve la bicicleta
        @pre La estacion a la cual se esta moviendo existe y tiene como mínimo 1 espacio libre
        @post La ubicacion actual de la bicicleta cambia a la nueva estacion y el cambio queda registrado en su historial de viajes
    */
    void mover(string& identificador_estacion);


    //CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC Consultoras CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC

   
       /** @brief Consultora que devuelve la ubicacion de la bicicleta
          @pre cierto
          @post Retorna el id de la estacion en la qual esta la bicicleta
      */
       string ubicacion() const;


    //EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE Escritura EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE


    /** @brief Escribe los viajes que ha hecho una bicicleta
        @pre Cierto
        @post Se ha escrito de mas antiguo a mas reciente los viajes que ha hecho la bicicleta en el formato, origen destino salto de linea
    */
     void escribir_historial();


};
#endif

