# 🚦 **Tarefa_Clock_Temporizador_01**

**Atividade 01 - Temporizador Periódico (Semáforo)**

> **Unidade 4 | Capítulo 5 – 29/01/2025**  
> **Professor: Dr. Ricardo Menezes Prates**  
> **Plataforma: Raspberry Pi Pico W (BitDogLab)**  
> **Autor: Edcarllos Santos**

---

## 📌 **Descrição do Projeto**

Este projeto implementa um **semáforo com temporização periódica** de **3 segundos por cor**, utilizando o microcontrolador **Raspberry Pi Pico W**. A funcionalidade é implementada através da API **Pico SDK**, utilizando a função `add_repeating_timer_ms()`.

A simulação é realizada no **Wokwi** de acordo com o arquivo `diagram.json` previamente configurado.

---

## 🛠️ **Hardware Utilizado**

### 🎧 **Componentes**

- **Microcontrolador:** Raspberry Pi Pico W
- **LEDs:** 3 LEDs (Vermelho, Amarelo e Verde)
- **Resistores:** 3 resistores de 330Ω
- **Alimentação:** USB 5V via VS Code

### 🔌 **Conexões**

| **Componente**   | **GPIO (Pico W)** |
| ------------ | ------------- |
| **LED Vermelho** | **GPIO 13**       |
| **LED Amarelo**  | **GPIO 12**       |
| **LED Verde**    | **GPIO 11**       |

---

## 🏰️ **Configuração do Projeto**

### **1⃣ Instalação do SDK**

Caso não tenha o **Pico SDK** instalado, siga os passos:

```bash
git clone https://github.com/raspberrypi/pico-sdk.git
cd pico-sdk
git submodule update --init
```

No **CMakeLists.txt**, inclua a linha:

```cmake
target_link_libraries(Tarefa_Clock_Temporizador_01 pico_stdlib hardware_timer)
```

### **2⃣ Compilação e Upload**

Após configurar o ambiente, compile o projeto:

```bash
mkdir build
cd build
cmake ..
make
```

Para enviar o código ao **Pico W**, segure o botão **BOOTSEL**, conecte o USB e copie o arquivo `.uf2` gerado.

---

## 🛡️ **Objetivos do Projeto**

✅ Implementar um temporizador **periódico** de **3 segundos**  
✅ Controlar um **semáforo com LEDs RGB** usando GPIOs  
✅ Simular o projeto no **Wokwi**  
✅ Exibir logs via **porta serial**  

---

## 📲 **Demonstração**

📺 **Vídeo da simulação no Wokwi:**  
📹 **[Clique aqui](https://wokwi.com/projects/XXXXXXX)**  

---

## 📄 **Licença**

Este projeto está licenciado sob a **MIT License**.

---

## 💪 **Referências**

- [**Pico SDK**](https://github.com/raspberrypi/pico-sdk)
- [**Documentação do RP2040**](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf)
- [**Simulador Wokwi**](https://wokwi.com)
