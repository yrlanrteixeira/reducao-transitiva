# Transitive Reduction of Directed Graphs: PAA 2026/1

Implementação em C++ de redução transitiva de DAGs baseada em caminhamento (DFS).

## Estrutura do projeto

- `include/`: headers com as interfaces dos módulos (Grafo, Caminhamento, ReducaoTransitiva, GrafoIO, Verificador, GeradorDag).
- `src/`: implementações da biblioteca, um arquivo por módulo.
- `apps/`: implementação dos executaveis, um arquivo por executavel.
- `Makefile` e `CMakeLists.txt`: build do projeto.
- `report/`: PDF e código LaTeX do relatório do trabalho.
- `experiments/`: dados do benchmark.
- `tests/`: arquivos de input para os testes.

## Compilação

### CMake

O projeto cmake pode ser compilado tanto pelo Visual Studio no Windows quanto pela linha de comando:

```
cmake -B bin
cmake --build bin
```

### Make

Uma alternativa ao cmake é utilizar o makefile:

```
make
```

### Executáveis

O build gera os binários em `bin/`:

- `reducao_transitiva`: lê o grafo e produz a redução transitiva.
- `gerador`: gera DAGs aleatórios para experimentos.
- `verificador`: verifica corretude (atingibilidade + minimalidade).

## Formato de entrada/saída

Primeira linha: `n m` (vértices 0..n-1 e número de arestas). Em seguida, `m` linhas `u v` (aresta u->v).

## Uso

```
./bin/reducao_transitiva entrada.txt saida.txt
./bin/gerador 1000 0.05 42 > grafo.txt
./bin/verificador grafo.txt grafo_reduzido.txt
```
