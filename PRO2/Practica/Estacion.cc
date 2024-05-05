/** @file Estacion.cc
    @brief Código de la clase Estacion
*/
#include"Estacion.hh"


Estacion::Estacion(int s) {
   size = s;
    set<string> b;
     bicicletas = b;
}


int Estacion::n_bicis() {
    return bicicletas.size();
}


void Estacion::meter_bicicleta(string identificador_bici) { 
    bicicletas.insert(identificador_bici);
}


void Estacion::eliminar(string identificador_bici) {
    bicicletas.erase(identificador_bici);
}


void Estacion::modifica_capacidad(const int& x) {
    size = x;
}


int Estacion::tamano() {
    return size;
}


string Estacion::bici_menor_id() 
{
    auto it = bicicletas.begin();
    string no_valor_por_referencia = *it;
    return no_valor_por_referencia;
}


void Estacion::escribe_bicis() {
    set<string>::iterator it = bicicletas.begin();
    for (int i = 0; i < bicicletas.size(); ++i) {
        cout << *it << endl;
        ++it;
    }
}
