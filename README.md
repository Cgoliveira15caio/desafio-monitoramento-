# Desafio de Monitoramento de Temperatura

## 1. Identificação
* **Nome do aluno:** Caio Oliveira Guimarães 
* **Disciplina:** Algoritmos
* **Professora:** Profa. Karla Sartin
* **Título do projeto:** Projeto Estruturas de Repetição - Monitoramento Contínuo

## 2. Objetivo
O programa tem como objetivo monitorar a temperatura de um ambiente em tempo real. Ele avisa quando a temperatura ultrapassa um limite seguro estabelecido (38.0 ºC) e realiza o encerramento automático do sistema caso sejam registradas três temperaturas consecutivas acima do limite.

## 3. Funcionamento do programa
* **Limite de temperatura:** Definido fixo em 38.0 ºC através de uma constante.
* **Leituras:** O usuário insere os valores de temperatura manualmente de forma interativa.
* **Tratamento de entradas inválidas:** Utiliza um laço `while` para verificar se o valor digitado é um número válido, limpando o buffer do teclado caso ocorra um erro de tipo.
* **Identificação de excesso:** Se a temperatura for maior que 38.0 ºC, um alerta crítico é disparado.
* **Contagem consecutiva:** O programa incrementa uma variável de contagem a cada temperatura alta seguida. Se a temperatura normalizar, a contagem é resetada.
* **Encerramento:** Ao atingir 3 ocorrências consecutivas acima do limite, o programa encerra automaticamente por segurança.

## 4. Estruturas de repetição utilizadas
* **`do...while`:** Utilizado para manter o fluxo principal do programa rodando e permitir que o usuário faça novas leituras de temperatura de forma contínua até decidir sair ou o sistema atingir o limite crítico.
* **`while`:** Utilizado para a validação robusta de entradas de dados (garantindo que o programa não quebre caso o usuário digite letras ou caracteres inválidos).

## 5. Como executar
Para compilar e executar o programa via terminal (GCC):
```bash
gcc monitoramento.c -o monitoramento
./monitoramento
