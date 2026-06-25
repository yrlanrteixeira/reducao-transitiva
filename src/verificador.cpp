#include "verificador.hpp"

#include <vector>

#include "caminhamento.hpp"

namespace paa {

Verificador::Resultado Verificador::verificar(const Grafo& original,
                                              const Grafo& reduzido) const {
    if (original.numVertices() != reduzido.numVertices())
        return {false, "FALHOU: numero de vertices difere"};

    auto r1 = verificarAtingibilidade(original, reduzido);
    if (!r1.valido) return r1;

    auto r2 = verificarMinimalidade(reduzido);
    if (!r2.valido) return r2;

    return {true, "OK: G' preserva a atingibilidade de G e e minimal"};
}

// Propriedade 1: para todo u, o conjunto alcançável em G é igual ao de G'.
Verificador::Resultado Verificador::verificarAtingibilidade(const Grafo& g,
                                                            const Grafo& r) const {
    for (int u = 0; u < g.numVertices(); ++u) {
        if (alcancaveis(g, u) != alcancaveis(r, u))
            return {false, "FALHOU: atingibilidade do vertice " +
                               std::to_string(u) + " difere entre G e G'"};
    }
    return {};
}

// Propriedade 2: nenhuma aresta (u,v) de G' e alcançável por caminho
// alternativo de comprimento >= 2 (ou seja, G' não tem aresta transitiva).
Verificador::Resultado Verificador::verificarMinimalidade(const Grafo& r) const {
    const int n = r.numVertices();
    for (int u = 0; u < n; ++u) {
        std::vector<char> marca(n, 0);
        for (int w : r.vizinhos(u))
            for (int x : r.vizinhos(w)) dfsMarcar(r, x, marca);

        for (int v : r.vizinhos(u))
            if (marca[v])
                return {false, "FALHOU: aresta (" + std::to_string(u) + "," +
                                   std::to_string(v) + ") de G' ainda e transitiva"};
    }
    return {};
}

}  // namespace paa
