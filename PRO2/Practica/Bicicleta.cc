/** @file Bicicleta.cc
    @brief Código de la clase Bicicleta
*/

#include "Bicicleta.hh"

Bicicleta::Bicicleta(string identificador_bicicleta, string identificador_estacion)
{
    identificador = identificador_bicicleta;  
    list<pair<string, string>> h;
    historial = h;
    ubi = identificador_estacion;
}

void Bicicleta::mod_ubicacion(string& identificador_estacion) 
{
    ubi = identificador_estacion;
}



void Bicicleta::mover(string& identificador_estacion)
{
    historial.push_back(pair <string, string>(ubi, identificador_estacion));
    ubi = identificador_estacion;
}

void Bicicleta::escribir_historial(){
    auto it = historial.begin();
    int s = historial.size();
    for (int i = 0 ; i < s; ++i) {
        cout << it->first << ' ' << it->second << endl;
        ++it;
    }
}
string Bicicleta::ubicacion() const{
    return ubi;
}

