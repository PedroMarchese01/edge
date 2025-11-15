# Projeto de Monitoramento de Ambientes Inteligentes para o Futuro do Trabalho

Este projeto foi desenvolvido com foco no tema Futuro do Trabalho, onde ambientes de trabalho conectados, inteligentes e seguros se tornam essenciais.  
A solução monitora condições ambientais em tempo real para garantir que o trabalhador esteja em um espaço adequado, confortável e seguro, aumentando produtividade e bem-estar.

O sistema utiliza um ESP32 integrado com sensores de temperatura, umidade, luminosidade e qualidade do ar. Todos os dados são analisados e enviados automaticamente para o ThingSpeak para visualização.

Desenvolvido por:
- Pedro Marchese – RM 563339  
- Jonas Esteves – RM 564143  
- Augusto Valerio – RM 562185  

---

## Objetivo do Projeto

Criar um ambiente de trabalho inteligente capaz de:
- Monitorar continuamente condições ambientais.
- Gerar dados em tempo real sobre conforto térmico, umidade, iluminação e qualidade do ar.
- Auxiliar empresas a promover ambientes saudáveis e adequados para o trabalhador.
- Conectar o ambiente físico ao digital, alinhado às tendências do futuro do trabalho.

---

## Funcionalidades

- Leitura e análise de temperatura, umidade, luz e qualidade do ar.
- Envio automático e contínuo para o ThingSpeak.
- Feedback instantâneo no Serial Monitor explicando cada condição detectada.
- LED sensor para alerta em caso de má qualidade do ar.
- Sistema resiliente com reconexão automática ao Wi-Fi.

---

## Tecnologias Utilizadas

- ESP32  
- DHT11  
- MQ-135  
- LDR  
- ThingSpeak  
- Wokwi  
- Bibliotecas: WiFi.h, HTTPClient.h, DHT.h  

---

## Simulação no Wokwi

Para visualizar e testar o projeto diretamente no navegador:

[**Acessar Wokwi**](https://wokwi.com/projects/447467534654824449)

---

## Dashboard no ThingSpeak

Visualize os dados sendo enviados em tempo real no painel:

[**Acessar Canal ThingSpeak**](https://thingspeak.mathworks.com/channels/3163643)

---

## Como Funciona

O sistema realiza:
1. Conexão automática ao Wi-Fi Wokwi-GUEST.  
2. Coleta contínua dos sensores:  
   - Temperatura  
   - Umidade  
   - Qualidade do ar (gases)  
   - Luminosidade  
3. Análises automáticas com mensagens interpretativas.  
4. Avisos sobre ambiente inadequado (frio, quente, úmido, seco, escuro, iluminado demais, ar ruim).  
5. Envio para o ThingSpeak a cada 20 segundos.  
6. Indicação luminosa caso a qualidade do ar esteja fora do ideal.

---

## Estrutura do Hardware

- ESP32 DevKit V1  
- DHT11 → pino 15  
- MQ-135 → pino 34  
- LDR → pino 35  
- LED → pino 2  

Toda estrutura pode ser visualizada no Wokwi.

---

## Como Executar

1. Abra o projeto no Wokwi.  
2. Clique em Run.  
3. Abra o Serial Monitor para acompanhar análises.  
4. Acesse o canal no ThingSpeak para visualizar os gráficos.  

---

## Intervalo de Envio

Os dados são enviados a cada 20 segundos, respeitando os limites do ThingSpeak.
