# Teste de Estresse de Memória (em C)
## Um programa simples e eficiente desenvolvido em C para testar os limites de alocação de memória RAM e observar o comportamento do sistema operacional sob carga máxima.



Como o código funciona por debaixo dos panos:
O "Coração" do Teste: O programa utiliza um loop infinito (while(1)) que roda continuamente. A cada ciclo, ele aciona a função malloc(1024 * 1024) para solicitar ao sistema operacional exatamente 1 Megabyte (MB) de memória.

Forçando a Alocação Física: Muitos sistemas operacionais utilizam lazy allocation (alocação preguiçosa), prometendo a memória, mas só entregando de fato quando o programa tenta escrever nela. Para garantir o consumo real da RAM física, o código usa um loop for logo após o malloc para preencher todo esse novo espaço com zeros (ptr[i] = 0).

Monitoramento ao Vivo: O programa mantém uma contagem de quantos Megabytes foram alocados com sucesso (total_alocado). Utilizando o caractere \r no printf, ele atualiza a contagem na mesma linha do terminal, mostrando o consumo subindo em tempo real sem poluir a tela.

Atingindo o Limite (Out of Memory): O loop continua executando até que a memória RAM e o arquivo de paginação (swap) se esgotem. Quando isso acontece, a função malloc retorna NULL. O programa identifica isso, exibe uma mensagem informando que o limite seguro foi atingido e encerra graciosamente usando um break.
