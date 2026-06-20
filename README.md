# Serviço de Alunos (Crow)

API HTTP de alunos em C++ usando o microframework Crow.

## Metadados

| Campo | Valor |
|-------|-------|
| Linguagem | C++ 17 |
| Framework | Crow |
| Serialização | crow::json |
| Armazenamento | Em memória (`AlunoRepository`) |
| Versão | 1.0.0 |
| Licença | MIT |
| Responsável | Equipe de Plataforma |

## Descrição

Serviço que expõe o CRUD de alunos, além de uma rota administrativa e uma rota de comparação.
O repositório mantém os alunos em memória.

## Endpoints

| Método | Rota | Descrição |
|--------|------|-----------|
| GET | `/alunos` | Lista de alunos |
| GET | `/alunos/<int>` | Detalhe de um aluno |
| POST | `/alunos` | Cria um aluno |
| GET | `/admin` | Rota administrativa |
| GET | `/comparar/<string>` | Comparação de nome |

## Estrutura

```
cpp-crow/
└── src/
    ├── aluno.hpp
    ├── main.cpp
    └── test_aluno.cpp
```

## Como compilar e executar

```bash
g++ -std=c++17 src/main.cpp -o servico -lpthread
./servico
# servidor em http://localhost:8080
```

## Dependências

Requer o cabeçalho do Crow disponível no include path.
