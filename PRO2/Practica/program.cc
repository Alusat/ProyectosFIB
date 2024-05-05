/**
 * @mainpage Bicing bifurcado

 */
 /** @file program.cc
     @brief Programa principal para la practica Bicing bifurcado
 */

#include "Estaciones.hh"
#include "Bicicletas.hh" 
#ifndef NO_DIAGRAM
#include "Bicicleta.hh"
#include "Estacion.hh" 
#include<iostream>
using namespace std;
#endif


/** @brief  Programa principal para la practica Bicing bifurcado. Se encarga de recibir inputs, controlar errores y escribir outputs (la mayoría),
*/
int main()
{
    Estaciones estaciones;
    Bicicletas bicicletas;
    estaciones.leer_bicicletas();
    string operacion;
    cin >> operacion;
    while (operacion != "fin") { //todas las acciones de la derecha presuponiendo que no hay ningun error
        if (operacion == "alta_bici" or operacion == "ab") // la bici pasa a estar en dicha estacion
        {
            string identificador_bici, identificador_estacion;
            cin >> identificador_bici >> identificador_estacion;
            cout << "#ab " << identificador_bici << ' ' << identificador_estacion << endl;
            if (bicicletas.bici_existe(identificador_bici)) cout << "error: la bici ya existe" << endl;
            else if (!estaciones.estacion_existe(identificador_estacion)) cout << "error: la estacion no existe" << endl;
            else if (estaciones.estacion(identificador_estacion).n_bicis() >= estaciones.estacion(identificador_estacion).tamano()) cout << "error: la bici no cabe" << endl;
            else {
                // estaciones.estacion(identificador_estacion).meter_bicicleta(identificador_bici); 
                estaciones.alta_bici(identificador_estacion, identificador_bici);
                bicicletas.alta_bici(identificador_bici, identificador_estacion);
            }
        }
        else if (operacion == "baja_bici" or operacion == "bb")  // la bici deja de estar en dicha estacion
        {
            string identificador_bici;
            cin >> identificador_bici;
            cout << "#bb " << identificador_bici << endl;
            if (!bicicletas.bici_existe(identificador_bici)) cout << "error: la bici no existe" << endl;
            else {
                string estacion;
                estacion = bicicletas.estacion_respecto_bicicleta(identificador_bici);
                estaciones.baja_bici(estacion, identificador_bici);
                bicicletas.baja_bici(identificador_bici);
            }
        }
        else if (operacion == "estacion_bici" or operacion == "eb")  // se escribe el identificador de la estacion en la cual esta la bici
        {
            string identificador_bici;
            cin >> identificador_bici;
            cout << "#eb " << identificador_bici << endl;
            if (!bicicletas.bici_existe(identificador_bici)) cout << "error: la bici no existe" << endl;
            else {
                cout << bicicletas.estacion_respecto_bicicleta(identificador_bici) << endl;
            }
        }
        else if (operacion == "viajes_bici" or operacion == "vb")  // se escriben los viajes que ha hecho la bici
        {
            string identificador_bici;
            cin >> identificador_bici;
            cout << "#vb " << identificador_bici << endl;
            if (!bicicletas.bici_existe(identificador_bici)) cout << "error: la bici no existe" << endl;
            else {
                bicicletas.bici(identificador_bici).escribir_historial();
            }
        }
        else if (operacion == "mover_bici" or operacion == "mb")  // la bici pasa de estar en su estacion actual, a la estacion destino
        {
            string identificador_bici, identificador_estacion;
            cin >> identificador_bici >> identificador_estacion;
            cout << "#mb " << identificador_bici << ' ' << identificador_estacion << endl;
            if (!bicicletas.bici_existe(identificador_bici)) cout << "error: la bici no existe" << endl;
            else if (!estaciones.estacion_existe(identificador_estacion)) cout << "error: la estacion no existe" << endl;
            else if (bicicletas.estacion_respecto_bicicleta(identificador_bici) == identificador_estacion) cout << "error: la bici ya esta en el sitio" << endl;
            else if (estaciones.estacion(identificador_estacion).n_bicis() >= estaciones.estacion(identificador_estacion).tamano()) cout << "error: la bici no cabe" << endl;
            else {
                string identificador_estacion_actual = bicicletas.estacion_respecto_bicicleta(identificador_bici);
                bicicletas.mover(identificador_bici, identificador_estacion);
                estaciones.mover(identificador_bici, identificador_estacion, identificador_estacion_actual);
            }
        }
        else if (operacion == "bicis_estacion" or operacion == "be")  //  se escribe que bicis tiene cierta estacion por orden de identificador
        {
            string identificador_estacion;
            cin >> identificador_estacion;
            cout << "#be " << identificador_estacion << endl;
            if (!estaciones.estacion_existe(identificador_estacion)) cout << "error: la estacion no existe" << endl;
            else estaciones.estacion(identificador_estacion).escribe_bicis();
        }

        else if (operacion == "modificar_capacidad" or operacion == "mc")  // cambia el numero de bicis que puede acoger una estacion
        {
            string identificador_estacion;
            int x;
            cin >> identificador_estacion >> x;
            cout << "#mc " << identificador_estacion << ' ' << x << endl;
            if (!estaciones.estacion_existe(identificador_estacion)) cout << "error: la estacion no existe" << endl;
            else if (x < estaciones.estacion(identificador_estacion).n_bicis()) cout << "error: capacidad insuficiente" << endl;
            else estaciones.modificar_capacidad(identificador_estacion, x);
        }
        else if (operacion == "plazas_libres" or operacion == "pl")  // la bici pasa de estar en su estacion actual, a la estacion destino
        {
            cout << "#pl" << endl;
            cout << estaciones.plazas_libres() << endl;
        }
        else if (operacion == "subir_bicis" or operacion == "sb")  // la bici pasa de estar en su estacion actual, a la estacion destino
        {
            cout << "#sb" << endl;
            estaciones.subir_bicis(bicicletas);
        }
        else if (operacion == "asignar_estacion" or operacion == "ae") //se añade una bici a la estacion mas vacia
        {
            string identificador_bici;
            cin >> identificador_bici;
            cout << "#ae " << identificador_bici << endl;
            if (bicicletas.bici_existe(identificador_bici)) cout << "error: la bici ya existe" << endl;
            else if (!estaciones.plazas_libres()) cout << "error: no hay plazas libres" << endl;
            else {
                string estacion_asignada = estaciones.asignar_estacion(identificador_bici);
                bicicletas.alta_bici(identificador_bici, estacion_asignada);
                cout << estacion_asignada << endl;
            }
        }
        cin >> operacion;
    }
}

