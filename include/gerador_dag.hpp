#ifndef GERADOR_DAG_HPP
#define GERADOR_DAG_HPP

#include "grafo.hpp"

namespace paa {

// Gera DAGs aleatórios no modelo G(n,p): cada par (i,j) com i < j recebe a
// aresta i -> j com probabilidade p, garantindo aciclicidade por construção.
class GeradorDag {
public:
    explicit GeradorDag(unsigned semente = 42u) : semente_(semente) {}

    Grafo gerar(int numVertices, double probabilidade) const;

private:
    unsigned semente_;
};

}  // namespace paa

#endif  // GERADOR_DAG_HPP
