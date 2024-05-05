/** @file Bicicletas.hh
    @brief Especificación de la clase Bicicletas
*/

#ifndef _BICICLETAS_
#define _BICICLETAS_
#include "Bicicleta.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#endif

/*
 * Clase Bicicletas
 */

 /** @class Bicicletas
     @brief Representa el conjunto de características y
     operaciones del conjunto de bicicletas.
     
 */
class Bicicletas {

private:
    /** @brief Mapa con todas las id de las bicicletas y su respectiva informacion */
    map<string, Bicicleta> id_bicicletas_bicicleta;
    /** @brief Mapa con las id de las estacione respecto a las id de las bicicletas */
    map<string, string> id_bicicletas_estacion;

public:
        //CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC Constructoras CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCc
        /** @brief Creadora por defecto
        @pre cierto
        @post El resultado es un conjunto de bicicletas vacío
         */
        Bicicletas();


        //OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO Operaciones OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
          /** @brief Consultora que añade una bicicleta nueva al conjunto
            \pre la bici no existe
            \post La bici queda añadida al conjunto de bicicletas
        */
        void alta_bici(string identificador_bici, string identificador_estacion);


          /** @brief Consultora que añade una bicicleta nueva al conjunto   
        \pre la bici no existe
        \post La bici queda añadida al conjunto de bicicletas
        */
        void baja_bici(string& identificador_bici);


        /** @brief Consultora que mueve una bicicleta de una estacion a otra
          \pre existe la bicicleta, la estacion objetivo existe y no es la misma en la cual se encuentra la bicicleta. La bicicleta cabe
          \post Se da de baja la bicicleta en su estacion actual, se da de alta en la nueva estacion y su historial de viajes queda actualizado.
        */
        void mover(string& identificador_bici, string& identificador_estacion);


        /** @brief Consultora que sube una bicicleta de una estacion a otra
          \pre existe la bicicleta, la estacion objetivo existe y se situa arriba de la estacion actual
          \post Se da de baja la bicicleta en su estacion actual, se da de alta en la nueva estacion y su historial de viajes NO queda actualizado.
        */
        void subir(string identificador_bici, string identificador_estacion);


    // CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC  Consultoras CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC


    /** @brief Consultora que indica si existe una bicicleta
        \pre cierto
        \post Retorna true si existe, false en caso contrario
    */
    bool bici_existe(string identificador_bici) const;


    /** @brief Consultora que retorna el id de la estacion a la cual pertenece cierta bici 
            \pre cierto
            \post Retorna el id de la la estacion a la cual pertenece la bici
        */
    string estacion_respecto_bicicleta(string identificador_bicicleta) const;


    /** @brief Consultora que retorna una bicicleta
           \pre la bicicleta a retornar existe
           \post Retorna la la bicicleta a la qual se refiere el id
       */
    Bicicleta bici(string identificador_bicicleta) const;
 
};
#endif

