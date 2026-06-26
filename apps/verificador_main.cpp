#include <exception>
#include <iostream>

#include "grafo_io.hpp"
#include "verificador.hpp"

// Uso: ./verificador <original.txt> <reduzido.txt>
int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " <original.txt> <reduzido.txt>\n";
        return 1;
    }
    try {
        paa::Grafo original = paa::GrafoIO::lerArquivo(argv[1]);
        paa::Grafo reduzido = paa::GrafoIO::lerArquivo(argv[2]);

        paa::Verificador verificador;
        auto resultado = verificador.verificar(original, reduzido);
        std::cout << resultado.mensagem << '\n';
        return resultado.valido ? 0 : 2;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
