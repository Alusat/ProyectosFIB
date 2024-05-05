/** @file Estaciones.cc
    @brief Código de la clase Estaciones
*/

#include "Estaciones.hh"

Estaciones::Estaciones()
{
    plazas = 0;
    map<string, Estacion> m;
    id_estaciones_estacion = m;
    BinTree<string> b;
    arbol_estaciones = b;
}




void Estaciones::alta_bici(string& identificador_estacion, string& identificador_bicicleta) {
    auto it = id_estaciones_estacion.find(identificador_estacion);
    it->second.meter_bicicleta(identificador_bicicleta);
    --plazas;
}


void Estaciones::baja_bici(string& identificador_estacion, string& identficador_bicicleta)
{
    auto it = id_estaciones_estacion.find(identificador_estacion);
    it->second.eliminar(identficador_bicicleta);
    ++plazas;
}

void Estaciones::mover(string& identificador_bici, string& identificador_estacion, string& identificador_estacion_actual) 
{
    auto it = id_estaciones_estacion.find(identificador_estacion);
    it->second.meter_bicicleta(identificador_bici);
    auto iter = id_estaciones_estacion.find(identificador_estacion_actual);
    iter->second.eliminar(identificador_bici);
}

void Estaciones::subir_bicis(Bicicletas& bicicletas)
{
    subir(arbol_estaciones, bicicletas);
}



void Estaciones::subir(const BinTree<string>& arbol, Bicicletas& bicicletas)
{
    if (arbol.left().empty()) {
        return; //no hace falta mirar el derecho, si falta el izquierdo no habra derecho
    }
    string value = arbol.value();
    string izq = arbol.left().value();
    string der = arbol.right().value();

    auto itizq = id_estaciones_estacion.find(izq);
    auto itder = id_estaciones_estacion.find(der);
    auto itvalue = id_estaciones_estacion.find(arbol.value());
    if ((itvalue->second.tamano() - itvalue->second.n_bicis()) >= (itizq->second.n_bicis() + itder->second.n_bicis())) { //caben todas las bicicletas a subir
        while ((itizq->second.n_bicis() != 0)) { //subir todas las de la izquierda
            bicicletas.subir(itizq->second.bici_menor_id(), value);
            itvalue->second.meter_bicicleta(itizq->second.bici_menor_id());
            itizq->second.eliminar(itizq->second.bici_menor_id());
        }
        while ((itder->second.n_bicis() != 0)) { //subir todas las de la derecha
            bicicletas.subir(itder->second.bici_menor_id(), value);
            itvalue->second.meter_bicicleta(itder->second.bici_menor_id());
            itder->second.eliminar(itder->second.bici_menor_id());
        }
    }
    else {
        while ((itvalue->second.n_bicis() != itvalue->second.tamano()) && (itizq->second.n_bicis() != 0) && (itder->second.n_bicis() != 0)) {
            //si no esta llena la de arriba y ninguna de las de abajo esta vacia
            if (itizq->second.n_bicis() == itder->second.n_bicis()) { //mismas bicis, mirar emenor id
                if (itizq->second.bici_menor_id() < itder->second.bici_menor_id()) {//bici con menor id a la izquierda
                    bicicletas.subir(itizq->second.bici_menor_id(), value);
                    itvalue->second.meter_bicicleta(itizq->second.bici_menor_id());
                    itizq->second.eliminar(itizq->second.bici_menor_id());
                }
                else { //bici con menor id a la derecha
                    bicicletas.subir(itder->second.bici_menor_id(), value);
                    itvalue->second.meter_bicicleta(itder->second.bici_menor_id());
                    itder->second.eliminar(itder->second.bici_menor_id());
                }
            }
           
            else if (itizq->second.n_bicis() < itder->second.n_bicis()) { //tiene mas bicis la derecha
                 bicicletas.subir(itder->second.bici_menor_id(), value);
                itvalue->second.meter_bicicleta(itder->second.bici_menor_id());
                itder->second.eliminar(itder->second.bici_menor_id());
            }
         
            else { //tiene mas bicis la izquierda
                bicicletas.subir(itizq->second.bici_menor_id(), value);
                itvalue->second.meter_bicicleta(itizq->second.bici_menor_id());
                itizq->second.eliminar(itizq->second.bici_menor_id());
            }
        }
        while ((itvalue->second.n_bicis() != itvalue->second.tamano()) && (itizq->second.n_bicis() != 0)) { //no queda en un lado, acabar de completar lo maximo posible desde el otro
            bicicletas.subir(itizq->second.bici_menor_id(), value);
            itvalue->second.meter_bicicleta(itizq->second.bici_menor_id());
            itizq->second.eliminar(itizq->second.bici_menor_id());

        }
        while ((itvalue->second.n_bicis() != itvalue->second.tamano()) && (itder->second.n_bicis() != 0)) { 
            bicicletas.subir(itder->second.bici_menor_id(), arbol.value());
            itvalue->second.meter_bicicleta(itder->second.bici_menor_id());
            itder->second.eliminar(itder->second.bici_menor_id());
        }
       
    } 
    subir(arbol.left(), bicicletas);
    subir(arbol.right(), bicicletas);
}


string Estaciones::asignar_estacion(string& identificador_bicicleta)
{
    double coef_max;
    int n_estaciones_actuales, plazas_sin_usar;
    coef_max = -1; //siempre se cambiara por otra mas pequeña ya que no puede ser mayor que 1 normalmente
    string estacion_actual;
    asignar(arbol_estaciones, n_estaciones_actuales, plazas_sin_usar, coef_max, estacion_actual);
    alta_bici(estacion_actual, identificador_bicicleta);
    return estacion_actual;
}


void Estaciones::asignar(const BinTree<string>& arbol, int& n_estaciones_actuales, int& plazas_sin_usar, double& coef_max, string& estacion_actual)
{
    double coef_act;
    if (arbol.left().empty()) //estamos en hoja
    {
        string value = arbol.value();
        n_estaciones_actuales = 1;
        auto it = id_estaciones_estacion.find(value);
        plazas_sin_usar = it->second.tamano() - it->second.n_bicis();
        coef_act = double(plazas_sin_usar) / double(n_estaciones_actuales);
        if (coef_act == coef_max) {
            if (value < estacion_actual) estacion_actual = value;
        }
        else if (coef_act > coef_max) {
            coef_max = coef_act;
            estacion_actual = value;
        }
    }
    else {
        string value = arbol.value();
        auto it = id_estaciones_estacion.find(value);
        int plazas_sin_usar_izq, n_estaciones_actuales_izquierda;
        asignar(arbol.left(), n_estaciones_actuales_izquierda, plazas_sin_usar_izq, coef_max, estacion_actual);
        int plazas_sin_usar_der, n_estaciones_actuales_derecha;
        asignar(arbol.right(), n_estaciones_actuales_derecha, plazas_sin_usar_der, coef_max, estacion_actual);
        plazas_sin_usar = plazas_sin_usar_izq + plazas_sin_usar_der + (it->second.tamano() - it->second.n_bicis());
        n_estaciones_actuales = n_estaciones_actuales_izquierda + n_estaciones_actuales_derecha + 1;
        coef_act = double(plazas_sin_usar) / double(n_estaciones_actuales);
        if (coef_act == coef_max) {
            if (value < estacion_actual) estacion_actual = value;
        }
        else if (coef_act > coef_max) {
            coef_max = coef_act;
            estacion_actual = value;
        }
    }
}


bool Estaciones::estacion_existe(string identificador_estacion) 
{
    auto it = id_estaciones_estacion.find(identificador_estacion);
    return (it != id_estaciones_estacion.end());
}

Estacion& Estaciones::estacion(string identificador_estacion)
{
    auto it = id_estaciones_estacion.find(identificador_estacion);
    return it->second;
}

int Estaciones::plazas_libres() 
{
    return plazas;
}

void Estaciones::leer_arbol(BinTree<string>& arbol_estaciones, map<string, Estacion>& id_estaciones_estacion, int& plazas)
{
    string id;
    cin >> id;
    if (id != "#") {
        int size;
        cin >> size;
        id_estaciones_estacion.insert(pair<string, Estacion>(id, Estacion(size)));
        plazas += size;
        BinTree<string> derecha, izquierda;
        leer_arbol(izquierda, id_estaciones_estacion, plazas);
        leer_arbol(derecha, id_estaciones_estacion, plazas);
        arbol_estaciones = BinTree<string>(id, izquierda, derecha);
    }
}



void Estaciones::leer_bicicletas()
{
    leer_arbol(arbol_estaciones, id_estaciones_estacion, plazas);
}

void Estaciones::modificar_capacidad(const string& identificador_estacion, const int& x)
{
    int capacidad_anterior = estacion(identificador_estacion).tamano();
    estacion(identificador_estacion).modifica_capacidad(x);
    plazas += x - capacidad_anterior;

}



