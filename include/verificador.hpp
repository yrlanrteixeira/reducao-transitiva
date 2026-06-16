#ifndef VERIFICADOR_HPP
#define VERIFICADOR_HPP

#include <string>

#include "grafo.hpp"

namespace paa {

// Verificação independente da redução: atingibilidade preservada e minimalidade.
class Verificador {
public:
    struct Resultado {
        bool valido = true;
        std::string mensagem = "OK";
    };

    Resultado verificar(const Grafo& original, const Grafo& reduzido) const;

private:
    Resultado verificarAtingibilidade(const Grafo& g, const Grafo& r) const;
    Resultado verificarMinimalidade(const Grafo& r) const;
};

}  // namespace paa

#endif  // VERIFICADOR_HPP
