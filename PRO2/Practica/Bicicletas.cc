/** @file Bicicletas.cc
    @brief Código de la clase Bicicletas
*/

#include"Bicicletas.hh"

Bicicletas::Bicicletas() {
    map<string, Bicicleta> id_bicicletas_bicicleta;
    map<string, string> id_bicicletas_estacion;
}

    
string Bicicletas::estacion_respecto_bicicleta(string identificador_bicicleta) const {
    auto it = id_bicicletas_bicicleta.find(identificador_bicicleta);
    return it->second.ubicacion();
}

void Bicicletas::alta_bici(string identificador_bicicleta,string identificador_estacion)
{
    id_bicicletas_bicicleta.insert(pair<string, Bicicleta>(identificador_bicicleta, Bicicleta(identificador_bicicleta, identificador_estacion)));
    id_bicicletas_estacion.insert(pair<string, string>(identificador_bicicleta, identificador_estacion));
}

void Bicicletas::baja_bici(string& identificador_bicicleta) {
    id_bicicletas_bicicleta.erase(identificador_bicicleta);
    id_bicicletas_estacion.erase(identificador_bicicleta);
}

void Bicicletas::mover(string& identificador_bici, string& identificador_estacion)
{
    auto it = id_bicicletas_estacion.find(identificador_bici);
    it->second = identificador_estacion;
    auto iter = id_bicicletas_bicicleta.find(identificador_bici);
    iter->second.mover(identificador_estacion);
}

void Bicicletas::subir(string identificador_bici, string identificador_estacion) {
    auto it = id_bicicletas_estacion.find(identificador_bici);
    it->second = identificador_estacion;
    auto iter = id_bicicletas_bicicleta.find(identificador_bici);
    iter->second.mod_ubicacion(identificador_estacion);
}
bool Bicicletas::bici_existe(string identificador_bici) const
{
    auto it = id_bicicletas_bicicleta.find(identificador_bici);
    return (it != id_bicicletas_bicicleta.end());
}

Bicicleta Bicicletas::bici(string identificador_bicicleta) const
{
    auto it = id_bicicletas_bicicleta.find(identificador_bicicleta);
    return it->second;
}