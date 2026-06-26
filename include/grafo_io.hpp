#ifndef GRAFO_IO_HPP
#define GRAFO_IO_HPP

#include <iosfwd>
#include <string>

#include "grafo.hpp"

namespace paa {

// Leitura e escrita de grafos em texto.
// Formato: linha "n m" seguida de m linhas "u v" (aresta u -> v).
class GrafoIO {
public:
    static Grafo ler(std::istream& entrada);
    static Grafo lerArquivo(const std::string& caminho);

    static void escrever(const Grafo& g, std::ostream& saida);
    static void escreverArquivo(const Grafo& g, const std::string& caminho);
};

}  // namespace paa

#endif  // GRAFO_IO_HPP
