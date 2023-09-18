#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;
#define MAX_ALUNOS 10

class Aluno
{
private:
    int matricula;
    string nome;
    float nota;

public:
    Aluno(int m = 0, string n = "", float nt = -5.0)
    {
        matricula = m;
        nome = n;
        nota = nt;
    }

    string obtemNome()
    {
        return nome;
    }
    int obtemMatricula()
    {
        return matricula;
    }
    float obtemNota()
    {
        return nota;
    }

    void defineNome(string a)
    {
        nome = a;
    }
    void defineMatricula(int a)
    {
        matricula = a;
    }
    void defineNota(float a)
    {
        nota = a;
    }

    string str()
    {
        stringstream ss;
        ss << nome << " (" << setw(10) << setfill('0') << matricula << ")";
        if (nota != -1)
            ss << ": " << fixed << setprecision(4) << nota;

        return ss.str();
    }
};
class Turma
{
private:
    int numTurma;
    string nomeDisciplina;
    string nomeProfessor;
    Aluno *Alunos[MAX_ALUNOS];
    int numAlunos;

public:
    Turma(int numT = 0, string nd = "", string np = "") : numTurma(numT), nomeDisciplina(nd), nomeProfessor(np), numAlunos(0)
    {
    }

    int obtemNumero()
    {
        return numTurma;
    }

    string obtemDisciplina()
    {
        return nomeDisciplina;
    }
    string obtemProfessor()
    {
        return nomeProfessor;
    }
    Aluno *obtemAluno(int i)
    {

        if (i >= numAlunos)
        {
            return nullptr;
        }
        return Alunos[i];
    }
    int obtemNumAlunos()
    {
        return numAlunos;
    }

    void defineNumero(int n)
    {
        numTurma = n;
    }
    void defineDisciplina(string n)
    {
        nomeDisciplina = n;
    }
    void defineProfessor(string n)
    {
        nomeProfessor = n;
    }

    bool adicionaAluno(Aluno *a)
    {
        if (numAlunos < 10)
        {
            Alunos[numAlunos] = a;
            numAlunos++;
            return true;
        }
        else
            return false;
    }

    float media()
    {

        if (numAlunos == 0)
        {
            return -1;
        }
        else
        {
            float SM = 0;
            int N_notasvalidas = 0;
            for (int i = 0; i < numAlunos; i++)
            {
                if (Alunos[i]->obtemNota() != -1)
                {
                    SM += Alunos[i]->obtemNota();
                    N_notasvalidas++;
                }
            }
            return SM / N_notasvalidas;
        }
    }
    string str()
    {
        stringstream ss;
        ss << numTurma << " - " << nomeDisciplina << " - Prof. " << nomeProfessor << endl;

        for (int i = 0; i < numAlunos; i++)
        {

            ss << Alunos[i]->str() << endl;
        }
        if (numAlunos > 1)
            ss << "MEDIA = " << fixed << setprecision(4) << media()<<endl;
        return ss.str();
    }
};
int main()
{
    Aluno *discente[] = {
        new Aluno(1, "Benedito", 9.1),
        new Aluno(2, "Carlos", 8.2),
        new Aluno(3, "Daniela", 7.3),
        new Aluno(4, "Elisabeth", 6.4),
        new Aluno(5, "Fernanda", 5.5),
        new Aluno(6, "Gilson", 9.6),
        new Aluno(7, "Heitor", 8.5),
        new Aluno(8, "Irineu", 7.4),
        new Aluno(9, "Joana", 3.2),
        new Aluno(10, "Klaus", -1.0),
        new Aluno(11, "Laura", 9.8)};
    int numDiscentes = sizeof(discente) / sizeof(Aluno *);
    Turma *turma = new Turma(0, "SEM ALUNOS", "INDEFINIDO");
    int a;
    cout << turma->str() << endl;
    turma->defineNumero(123);
    turma->defineDisciplina("Linguagem C");
    turma->defineProfessor("Alberto");
    for (a = 0; a < 5; ++a)
        if (!turma->adicionaAluno(discente[a]))
        {
            cerr << "ERRO";
            exit(1);
        }
    for (a = 0; a < 5; ++a)
        if (turma->obtemAluno(a) != discente[a])
        {
            cerr << "ERRO";
            exit(1);
        }
    for (; a < numDiscentes; ++a)
        if (turma->obtemAluno(a) != nullptr)
        {
            cerr << "ERRO";
            exit(1);
        }
    cout << turma->str() << endl;
    for (a = 5; a < MAX_ALUNOS; ++a)
        if (!turma->adicionaAluno(discente[a]))
        {
            cerr << "ERRO";
            exit(1);
        }
    for (; a < numDiscentes; ++a)
        if (turma->adicionaAluno(discente[a]))
        {
            cerr << "ERRO";
            exit(1);
        }
    for (a = 0; a < MAX_ALUNOS; ++a)
        if (turma->obtemAluno(a) != discente[a])
        {
            cerr << "ERRO";
            exit(1);
        }
    cout << turma->str() << endl;
    delete turma;
    for (int i = 0; i < numDiscentes; ++i)
        delete discente[i];
    return 0;
}