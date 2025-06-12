TriagemCovid 🦠💻

Descrição

TriagemCovid é um sistema simples em C para triagem de pacientes baseado em um questionário de sintomas relacionados à COVID-19. O programa coleta informações básicas (CPF, nome, idade, sexo) e realiza perguntas sobre sintomas e exposições recentes para calcular uma pontuação de risco.

Funcionalidades 🚀

•Entrada de dados do paciente: CPF, nome, idade e sexo
•Questionário com 10 perguntas sobre sintomas e exposição
•Cálculo da pontuação de risco baseada nas respostas
•Classificação do risco em Baixo, Médio ou Alto
•Geração de relatório salvo em arquivo com o nome do paciente



Como compilar 🛠️

Para compilar o programa, você precisa do compilador gcc instalado. No terminal, dentro da pasta do projeto, execute:
gcc triagem.c -o triagem.exe



Como executar ▶️

No terminal, rode o programa compilado:
./triagem.exe
Siga as instruções no console para preencher os dados e responder ao questionário.



Requisitos 📋

•Compilador C (ex: GCC)
•Sistema operacional: Windows, Linux ou macOS



Estrutura do Código 🧩

•O código principal está em triagem.c, que contém:
•Entrada dos dados do paciente
•Perguntas do questionário armazenadas em struct
•Cálculo da pontuação e classificação do risco
•Gravação do resultado em arquivo com nome do paciente



Licença 📄

Este projeto é open source e pode ser usado livremente.