#ifndef REDUCAO_TRANSITIVA_HPP
#define REDUCAO_TRANSITIVA_HPP

#include "grafo.hpp"

namespace paa {

// Redução transitiva de DAGs por caminhamento (DFS).
// Complexidade: O(|V| * (|V| + |E|)).
class ReducaoTransitiva {
public:
    // Pré-condição: g é acíclico (ver paa::ehAciclico).
    Grafo reduzir(const Grafo& g) const;
};

}  // namespace paa

#endif  // REDUCAO_TRANSITIVA_HPP
