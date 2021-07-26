#include <iostream>
#include <string>

using namespace std;
struct conta
{
    string numero;
    string cpfTitular;
    string nomeTitular;
    float saldo;

    void sacar(float valorASaca)
    {
        if (valorASaca <= 0)
        {
            cout << "Valor negativo ou nulo, não é permitido" << endl;
            return;
        }

        if (valorASaca > saldo)
        {
            cout << "Saldo insuficiente" << endl;
            return;
        }

        saldo -= valorASaca;
    }

    void depositar(float valorADepositar)
    {
        if (valorADepositar <= 0)
        {
            cout << "Valor negativo ou nulo, não é permitido" << endl;
            return;
        }

        saldo += valorADepositar;
    }
};

int main()
{
    conta umaConta;
    umaConta.numero = "5151632";
    umaConta.cpfTitular = "07160673158";
    umaConta.nomeTitular = "Vinicius";
    umaConta.saldo = 200;

    umaConta.depositar(500);
    umaConta.sacar(200);

    cout << umaConta.saldo << " Reais" << endl;

    return 0;
}