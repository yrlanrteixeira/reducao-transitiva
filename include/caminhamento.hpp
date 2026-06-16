#ifndef CAMINHAMENTO_HPP
#define CAMINHAMENTO_HPP

#include <vector>

#include "grafo.hpp"

namespace paa {

// DFS iterativa (pilha explícita) para evitar estouro da pilha de execução
// em grafos grandes e profundos.

// Marca todos os vértices alcançáveis a partir de 'origem', respeitando
// marcações prévias (permite compartilhar o vetor entre chamadas).
void dfsMarcar(const Grafo& g, int origem, std::vector<char>& visitado);

// Vértices alcançáveis a partir de 'origem'.
std::vector<char> alcancaveis(const Grafo& g, int origem);

// Verifica se o grafo é acíclico.
bool ehAciclico(const Grafo& g);

}  // namespace paa

#endif  // CAMINHAMENTO_HPP
