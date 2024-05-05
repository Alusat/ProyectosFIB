/** @file Estaciones.hh
    @brief Especificación de la clase Estaciones
*/

#ifndef _ESTACIONES_
#define _ESTACIONES_

#include "Bicicletas.hh"
#include "Estacion.hh"
#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <map>
using namespace std;
#endif

/*
 * Clase Estaciones
 */

 /** @class Estaciones
     @brief Representa el conjunto de características y
     operaciones del conjunto de estaciones

     Ofrece una operacion de lectura.
     
 */
class Estaciones {

private:

    /** @brief Arbol de ids de estaciones */
    BinTree<string> arbol_estaciones;
    /** @brief Mapa con todas las id de las estaciones y su respectiva Estacion */
    map<string, Estacion> id_estaciones_estacion;
    /** brief Entero con las plazas libres del conunto de estaciones*/
    int plazas;
  void leer_arbol(BinTree<string>& arbol_estaciones, map<string, Estacion>& id_estaciones_estacion, int& plazas);
   /** @brief Función auxiliar. Justificación en el documento de 'Justificación de operaciones de la práctica de PRO2, Otoño 2023'*/
  void subir(const BinTree<string>& arbol, Bicicletas& bicicletas);
    /** @brief Justificación de todos los bucles en el documento de 'Justificación de operaciones de la práctica de PRO2, Otoño 2023'*/
  void asignar(const BinTree<string>& arbol, int& estaciones_actuales, int& plazas_sin_usar, double& coef_max, string& estacion_actual);

public:

    // CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC Constructora CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
    /** @brief Creadora por defecto
        @pre Cierto
        @post El resultado es un arbol de estaciones vacias (sin bicicletas)
    */
    Estaciones();

    
    // CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC  Consultoras CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC


    /** @brief Consultora que indica si existe una estacion
        \pre Cierto
        \post Retorna true si existe la estacion, false en caso contrario
    */
    bool estacion_existe(string identificador_estacion);


    /** @brief Consultora que retorna una estacion
          \pre La estacion a retornar existe
          \post Retorna la estacion a la qual se refiere la id
      */
    Estacion& estacion(string identificador_estacion);


    /** @brief Escribe el numero de plazas disponibles
    \pre Cierto
    \post Se ha escrito por pantalla el numero de plazas libres (y salto de linea)
    */ 
   int plazas_libres();


    //OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO Operaciones OOOOOOOOOOOOOOOOOOOOOOOOOOO


    /** @brief Añade una bicicleta al conjunto de estaciones en una estacion en concreto
    \pre La bicicleta no existe, la estacion existe, la bicicleta cabe en la estacion
    \post La bicicleta queda añadida a la estacion. Se reduce en 1 el numero de plazas disponibles globales
    */
    void alta_bici(string& identificador_estacion, string& identificador_bicicleta);


    /** @brief Elimina una bicicleta de su estacion actual, y por tanto del conjunto de estaciones
       \pre La bicicleta existe 
       \post La bicicleta queda eliminada de la estacion en la que ese encuentra, y por tanto del connjunto de estaicones.
       Se reduce en 1 el numero de plazas disponibles globales.
   */
    void baja_bici(string &identificador_estacion, string& identficador_bicicleta);


   /** @brief Mueve una bicicleta de una estacion existente a otra
       \pre las estaciones y la bicicleta existen. La estacion destino no es la misma en la cual esta la bicicleta
       \post La bicicleta queda eliminada de su estacion actual, y pasa a estar en la nueva estacion
   */
    void mover(string& identificador_bici, string& identificador_estacion, string& identificador_estacion_actual);


    /** @brief Modifica la capacidad de una estacion
       \pre La estacion existe. El nuemero de bicicletas actuales de la estacion es menor o igual a la nueva capacidad.
       \post La estacion tiene una nueva capacidad. Las plazas libres totales se han actualizado en consecuencia.
   */
    void modificar_capacidad(const string& identificador_estacion, const int& x);


    /** @brief Se identifica la estacion con mayor coeficiete de desocupacion general y se retorna su id. La bicicleta queda asignada a esa estacion
       \pre Hay una plaza libre como mínimo
      \post Se ha identificado la estacion con mayor coeficiente de desocupacion general y se ha retornado su id.
       La bici ha quedado asignada a la estacion con mayor coeficient de desocupacion general.
   */
   string asignar_estacion(string& identificador_bicicleta);


   /** @brief Acerca bicis a la primera estacion
    \pre Cierto
   \post Las bicicletas han quedado mas cercanas a la primera estacion
    */
     void subir_bicis(Bicicletas& bicicletas);


    //LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL Lectura LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL


    /** @brief Lee un cojunto de estaciones 
        \pre Cierto
        \post El conjunto de estaciones almacena los datos leidos.
        
    */
    void leer_bicicletas();


};
#endif

