#include <stdio.h>

#include "hardware/timer.h"
#include "pico/stdlib.h"

#define LED_RED 13     // GPIO do LED vermelho
#define LED_YELLOW 12  // GPIO do LED amarelo
#define LED_GREEN 11   // GPIO do LED verde

// Estado do semáforo: 0 - Vermelho, 1 - Amarelo, 2 - Verde
volatile int estado_semaforo = 0;

// Função de callback chamada pelo temporizador repetitivo
bool temporizador_callback(struct repeating_timer *t) {
  // Desliga todos os LEDs antes de alterar o estado
  gpio_put(LED_RED, 0);
  gpio_put(LED_YELLOW, 0);
  gpio_put(LED_GREEN, 0);

  // Atualiza o estado do semáforo
  switch (estado_semaforo) {
    case 0:
      gpio_put(LED_RED, 1);  // Liga o LED vermelho
      printf("Semáforo: VERMELHO\n");
      estado_semaforo = 1;
      break;
    case 1:
      gpio_put(LED_YELLOW, 1);  // Liga o LED amarelo
      printf("Semáforo: AMARELO\n");
      estado_semaforo = 2;
      break;
    case 2:
      gpio_put(LED_GREEN, 1);  // Liga o LED verde
      printf("Semáforo: VERDE\n");
      estado_semaforo = 0;
      break;
  }

  return true;  // Mantém o temporizador repetindo
}

int main() {
  stdio_init_all();  // Inicializa a comunicação serial

  // Inicializa os pinos dos LEDs como saída
  gpio_init(LED_RED);
  gpio_set_dir(LED_RED, GPIO_OUT);

  gpio_init(LED_YELLOW);
  gpio_set_dir(LED_YELLOW, GPIO_OUT);

  gpio_init(LED_GREEN);
  gpio_set_dir(LED_GREEN, GPIO_OUT);

  // Configuração do temporizador repetitivo (3.000 ms = 3 segundos)
  struct repeating_timer timer;
  add_repeating_timer_ms(3000, temporizador_callback, NULL, &timer);

  // Loop principal para manter o programa rodando
  while (true) {
    sleep_ms(1000);  // Mensagem a cada segundo
    printf("Sistema rodando...\n");
  }

  return 0;
}
