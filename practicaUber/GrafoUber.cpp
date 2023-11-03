#include <iostream>
#include <vector>
//La librería <queue> se utiliza en este código para implementar una cola (queue) de
// prioridad utilizada en el algoritmo de búsqueda de la ruta más corta
#include <queue>
//La librería <unordered_map> se utiliza en este codigo código para implementar una
// estructura de datos que mapea los nombres de lugares a sus identificadores (IDs) correspondientes.
#include <unordered_map>
//La librería <algorithm> se utiliza en este codigo para agregar el nombre del lugar actual a la componente
#include <algorithm>
// La librería <limits> se utiliza en este código para obtener el valor máximo representable por un tipo de dato entero
#include <limits>
//Clase para los lugares
class Lugar {
public:
    std::string nombre;
    int id;

    Lugar(const std::string &nombre, int id) : nombre(nombre), id(id) {}
};

class Mapa {
public:
    std::vector<Lugar> lugares;
    std::vector<std::vector<std::pair<int, int>>> relaciones;  // Relaciones con peso (distancia en km)

    Mapa(int numLugares) {
        lugares.reserve(numLugares); // Reserva espacio en el vector de lugares.
        relaciones.resize(numLugares); // Inicializa el vector de relaciones entre lugares.
    }

    void AgregarLugar(const std::string &nombre) {
        lugares.emplace_back(nombre, lugares.size()); // Agregar un lugar al vector de lugares.
    }

    void AgregarRuta(const std::string &origen, const std::string &destino, int distancia) {
        int idOrigen = ObtenerIdLugar(origen); // Obtiene el ID del lugar de origen.
        int idDestino = ObtenerIdLugar(destino); // Obtiene el ID del lugar de destino.
        relaciones[idOrigen].emplace_back(idDestino, distancia); // Agrega una ruta con distancia entre lugares.
    }

    int ObtenerIdLugar(const std::string &nombre) {
        for (size_t i = 0; i < lugares.size(); i++) {
            if (lugares[i].nombre == nombre) {
                return static_cast<int>(i); // Busca y devuelve el ID de un lugar por su nombre.
            }
        }
        return -1; // Devuelve -1 si el lugar no se encuentra.
    }

    std::vector<std::string>
    EncontrarRutaMasCorta(const std::string &origen, const std::string &destino, int &distancia_total,
                          int &duracion_total) {
        int idOrigen = ObtenerIdLugar(origen); // Obtiene el ID del lugar de origen.
        int idDestino = ObtenerIdLugar(destino); // Obtiene el ID del lugar de destino.

        std::vector<int> distancia(lugares.size(), std::numeric_limits<int>::max());
        std::vector<int> duracion(lugares.size(), std::numeric_limits<int>::max());
        std::vector<int> padre(lugares.size(), -1);
        std::priority_queue<std::pair<int, int>> pq;

        distancia[idOrigen] = 0;
        duracion[idOrigen] = 0;
        pq.push({0, idOrigen}); // Inicializa las distancias y agrega el lugar de origen a la cola de prioridad.

        while (!pq.empty()) {
            int lugar_actual = pq.top().second; // Obtiene el lugar actual de la cola de prioridad.
            pq.pop();

            for (const auto &relacion: relaciones[lugar_actual]) {
                int lugar_destino = relacion.first; // Obtiene el lugar de destino de la relación.
                int distancia_actual = relacion.second; // Obtiene la distancia entre los lugares.
                int nueva_duracion = duracion[lugar_actual] + CalcularDuracion(distancia_actual);

                if (distancia[lugar_destino] > distancia[lugar_actual] + distancia_actual) {
                    distancia[lugar_destino] = distancia[lugar_actual] + distancia_actual;
                    duracion[lugar_destino] = nueva_duracion;
                    padre[lugar_destino] = lugar_actual;
                    pq.push({-distancia[lugar_destino],
                             lugar_destino}); // Actualiza las distancias y la cola de prioridad.
                }
            }
        }

        // Reconstruir la ruta.
        std::vector<std::string> ruta;
        int lugar_actual = idDestino;
        while (lugar_actual != -1) {
            ruta.push_back(lugares[lugar_actual].nombre); // Reconstruye la ruta desde el destino hasta el origen.
            lugar_actual = padre[lugar_actual];
        }
        std::reverse(ruta.begin(), ruta.end()); // Invierte la ruta para que vaya desde el origen hasta el destino.

        distancia_total = distancia[idDestino]; // Almacenar la distancia total.
        duracion_total = duracion[idDestino]; // Almacenar la duración total.

        return ruta; // Devolver la ruta más corta.
    }

    // Este método se encarga de calcular la duración del viaje
    int CalcularDuracion(int distancia) {
        const int velocidad_promedio = 60; // Velocidad promedio en km/h.
        return (distancia * 60) /
               velocidad_promedio; // Convierte la distancia en minutos utilizando la velocidad promedio.
    }

    // Este metodo es el encargado encontrar componentes conexas.
    std::vector<std::vector<std::string>> EncontrarComponentesConexas() {
        std::vector<bool> visitado(lugares.size(), false); // Inicializa el vector de visitados.
        std::vector<std::vector<std::string>> componentes;

        for (int i = 0; i < lugares.size(); i++) {
            if (!visitado[i]) {
                std::vector<std::string> componente;
                DFS(i, visitado, componente);
                componentes.push_back(componente);
            }
        }

        return componentes;
    }
    // Este metodo es auxiliar para el recorrido y ademas encontrar componentes conexas.
    //DFS toma tres argumentos: lugar_actual es el índice del lugar actual en el grafo, visitado es un vector de booleanos
    // que se utiliza para realizar un seguimiento de los lugares visitados, y componente
    // es un vector que se utiliza para almacenar los nombres de los lugares en la componente conexa actual.
    void DFS(int lugar_actual, std::vector<bool> &visitado, std::vector<std::string> &componente) {
        visitado[lugar_actual] = true; // Se marca el lugar actual como visitado.
        componente.push_back(lugares[lugar_actual].nombre); // Se agrega el nombre del lugar actual a la componente.

        for (const auto &relacion: relaciones[lugar_actual]) {
            int lugar_destino = relacion.first;
            if (!visitado[lugar_destino]) {
                DFS(lugar_destino, visitado,
                    componente); // Llamada recursiva a DFS para explorar los lugares adyacentes no visitados.
            }
        }
    }
};
int main() {
    Mapa mapa(17);

    // Lugares ya sean de destino o partida
    mapa.AgregarLugar("Cartago");
    mapa.AgregarLugar("Alajuela");
    mapa.AgregarLugar("SanCarlos");
    mapa.AgregarLugar("Heredia");
    mapa.AgregarLugar("Paraiso");
    mapa.AgregarLugar("ITCR");
    mapa.AgregarLugar("Casa");
    mapa.AgregarLugar("Energym");
    mapa.AgregarLugar("Moren");
    mapa.AgregarLugar("MonteVerde");
    mapa.AgregarLugar("PlayaCocoSunSetHills");

    // Rutas del punto A al B
    mapa.AgregarRuta("Heredia", "SanCarlos", 117);
    mapa.AgregarRuta("Cartago","SanCarlos",176);
    mapa.AgregarRuta("Paraiso","ITCR",15);
    mapa.AgregarRuta("Casa","Energym",5);
    mapa.AgregarRuta("Casa","Moren",16);
    mapa.AgregarRuta("Casa","PlayaCocoSunSetHills",300);
    mapa.AgregarRuta("Casa","MonteVerde",250);

    std::string origen, destino;

    // Solicitar el lugar de partida
    std::cout << "Uber" << std::endl;
    std::cout << "Ingrese el lugar de origen: ";
    // Leer el punto de partida digitado por el usuario
    std::cin >> origen;
    //Seleccionar el lugar de destino
    std::cout << "Ingrese el lugar de destino: ";
    // Leer el punto de destino digitado por el usuario
    std::cin >> destino;

    // Este if se encarga de verificar que las lugar ingresadas son válidas
    if (mapa.ObtenerIdLugar(origen) == -1 || mapa.ObtenerIdLugar(destino) == -1) {
        std::cout << "Destino no valido." << std::endl;
        return 1;
    }

    int distancia_total, duracion_total;
    // Esta linea se encarga de encortrar la ruta mas corta entre el punto A y B
    std::vector<std::string> ruta_mas_corta = mapa.EncontrarRutaMasCorta(origen, destino, distancia_total, duracion_total);

    if (ruta_mas_corta.empty()) {
        std::cout << "No se encontró una ruta desde " << origen << " a " << destino << std::endl;
    } else {
        std::cout << "Ruta más corta desde " << origen << " a " << destino << ": ";
        for (const std::string &lugar : ruta_mas_corta) {
            std::cout << lugar << " -> ";
        }
        //Esta linea muestra un mensaje indicando la distancia del recorrido y la duracion que es en minutos
        std::cout << "Distancia: " << distancia_total << " km, Duración: " << duracion_total << " minutos" << std::endl;
        std::cout << "Viaje solicitado el socio de la APP llegara en unos minutos" << std::endl;
        // Mensaje del metodo de pago
        std::cout << "Metodo de pago: Tarjeta de debito" << std::endl;
    }

    //Esta linea encuentra las componentes conexas del grafo
    std::vector<std::vector<std::string>> componentes_conexas = mapa.EncontrarComponentesConexas();

    // Imprime cada una de las componentes conexas
    std::cout << "Componentes Conexas:" << std::endl;
    for (const std::vector<std::string> &componente : componentes_conexas) {
        std::cout << "Componente: ";
        for (const std::string &lugar : componente) {
            std::cout << lugar << " -> ";
        }
        std::cout << std::endl;
    }

    return 0;
}
