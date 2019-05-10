/*
  +---------------------------------------------------------------------------+
  |               Instituto de Tecnologias Assistivas HandsFree               |
  |                  Projeto Automação de Fazenda de Camarões                 |
  +---------------------------------------------------------------------------+

    TESTE 01 - Leitura de Sensores e Envio ao 000webhost via GET

    Autores:  Arthur L. Castro            (https://github.com/ArthurLCastro)
              Henrique Leao Martins       (https://github.com/HMLeao)

    Data: 09 de Maio de 2019
*/

// INCLUSÃO DE BIBLIOTECAS:
#include <ModulosGSM.h>
#include <KnowFlow.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,2,1,0,4,5,6,7,3, POSITIVE);

// DEFINIÇÕES:
#define RX_GSM1 50             // ligar o Pino 8 do Arduino no TX do Módulo "SIM808 EVB-V3.2"
#define TX_GSM1 51             // ligar o Pino 7 do Arduino no RX do Módulo "SIM808 EVB-V3.2"
#define intervalo 20000       // Intervalo entre os envios de dados ao servidor

// CRIAÇÃO DE OBJETOS - Para emular as comunicações Seriais nos pinos digitais definidos acima:
ModulosGSM meuGSM1;
SoftwareSerial serialGSM1(RX_GSM1, TX_GSM1);
SoftwareSerial serialDo(10,11);



SensorDo            dox;
GravityTemperature  temp(TEMPPIN);
GravityPh           ph;
GravityEc           ec(&temp);
GravityOrp          orp;


// DECLARAÇÕES DE VARIÁVEIS GLOBAIS:
  String url = "", pacote = "";
  String sensorDO, sensorEC, sensorORP, sensorPh, sensorTemp;
  bool estadoEnvio = false;
  bool conSegura = 1;         // '1' para conexões HTTPS ou '0' para conexões HTTP

void setup(){
  lcd.begin (16,2);
  delay(1);
  lcd.setBacklight(HIGH);
  Serial.begin(9600);                       // Inicia a comunicação Serial a uma taxa de transmissão de 9600
  serialGSM1.begin(9600);// Inicia a comunicação Serial Emulada a uma taxa de transmissão de 9600
  
  serialDo.begin(9600);
  dox.begin(serialDo);
  
  meuGSM1.setupGSM(serialGSM1);
  ph.begin();

  ec.begin();

  orp.begin();
}

void loop(){

  ph.update();
  temp.update();
  dox.update();
  ec.update();
  orp.begin();

  
  sensorDO = "do=" + String(dox.getValue());
  sensorEC = "ec=" + String(ec.getValue());
  sensorORP = "orp=" + String(orp.getValue());
  sensorPh = "ph=" + String(ph.getValue());
  sensorTemp = "temp=" + String(temp.getValue());

// Se a página for http (conSegura = 0), deve-se pôr a parte "http://" na URL a ser enviada
  url = "https://castroarthurelectronics.000webhostapp.com/projCamarao/add.php";
  pacote = url + "?" + sensorDO + "&" + sensorEC + "&" + sensorORP + "&" + sensorPh + "&" + sensorTemp;

  serialGSM1.listen();
  estadoEnvio = meuGSM1.httpWriteGET(pacote, conSegura);
  lcd.setCursor(0,0);
  lcd.print("Dados enviados!");
  delay(3000);
  lcd.clear();
/*
  if (estadoEnvio == true){
    Serial.println("Pacote enviado com sucesso!");
  } else {
    Serial.println("Erro no envio do pacote");
  }
*/
  delay(intervalo);
}

double lerDO(){
  // Desenvolver a função de leitura do sensor
  return 12.3;
}

double lerEC(){
  // Desenvolver a função de leitura do sensor
  return 10;
}

double lerORP(){
  // Desenvolver a função de leitura do sensor
  return 34.5;
}

double lerPh(){
  // Desenvolver a função de leitura do sensor
  return 45.6;
}

double lerTemp(){
  // Desenvolver a função de leitura do sensor
  return 56.7;
}
