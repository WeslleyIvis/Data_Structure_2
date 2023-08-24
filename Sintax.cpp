#include <iostream>
#include <vector>

using namespace std;

// Create class
class User
{
public:
    // Constructor
    User(std::string nome, int idade)
    {
        this->nome = nome;
        this->idade = idade;
    }

    void info()
    {
        std::cout << "Nome: " << nome << std::endl;
        std::cout << "Idade: " << idade << std::endl;
    }

private:
    // Variaveis
    std::string nome;
    int idade;
};

// Toda aplicação em C++ começa dentro do main \/
int main()
{
    User pessoa("Jaum", 52);
    pessoa.info();

    int idade;
    float altura;
    char nome;

    std::cout << "Informe sua idade";
    std::cin >> idade;
    cout << "Você digitou: " << idade << std::endl;

    cout << "texto" << endl;
    cout << "texto a nais";
    return 0;
}
