#include <stdio.h>

int main() {
    // 1. Definição do limite de temperatura crítico
    const float LIMITE_MAXIMO = 38.0; 
    float temperaturaAtual;
    int temperaturasConsecutivas = 0;
    int opcaoMenu = 1;

    printf("=== SISTEMA DE MONITORAMENTO DE TEMPERATURA ===\n");

    // Uso do do...while para garantir que o menu/monitoramento execute pelo menos uma vez
    do {
        int entradaValida = 0;

        // Estrutura while para validação de entradas inválidas
        while (entradaValida == 0) {
            printf("\nDigite a temperatura atual (ºC): ");
            
            // Verifica se o usuário digitou um número válido
            if (scanf("%f", &temperaturaAtual) != 1) {
                printf("[ERRO] Entrada inválida! Por favor, insira um valor numérico.\n");
                // Limpa o buffer do teclado para evitar loop infinito
                while (getchar() != '\n');
            } else {
                entradaValida = 1; // Entrada correta, sai do loop de validação
            }
        }

        // 2. Verificação se a temperatura está acima do limite permitido
        if (temperaturaAtual > LIMITE_MAXIMO) {
            temperaturasConsecutivas++;
            printf("[ALERTA CRÍTICO] Temperatura acima do limite! (Atual: %.1f ºC | Limite: %.1f ºC)\n", temperaturaAtual, LIMITE_MAXIMO);
            printf("Contagem de ocorrências consecutivas acima do limite: %d/3\n", temperaturasConsecutivas);
        } else {
            // Reseta a contagem se a temperatura voltar ao normal
            if (temperaturasConsecutivas > 0) {
                printf("[INFO] A temperatura normalizou. A contagem consecutiva foi reiniciada.\n");
            }
            temperaturasConsecutivas = 0;
        }

        // 3. Condição de encerramento automático: 3 temperaturas consecutivas acima do limite
        if (temperaturasConsecutivas >= 3) {
            printf("\n[PERIGO] 3 temperaturas consecutivas acima do limite detetadas!\n");
            printf("O sistema de monitoramento foi encerrado automaticamente por segurança.\n");
            break; // Encerra o loop do...while
        }

        // Pergunta se deseja continuar a monitorização manual (caso não atinja o limite crítico)
        printf("\nDeseja realizar uma nova leitura? (1 - Sim / 0 - Não): ");
        if (scanf("%d", &opcaoMenu) != 1) {
            printf("[ERRO] Opção inválida. A encerrar o programa.\n");
            break;
        }

    } while (opcaoMenu == 1);

    printf("\n=== FIM DO MONITORAMENTO ===\n");
    return 0;
}
