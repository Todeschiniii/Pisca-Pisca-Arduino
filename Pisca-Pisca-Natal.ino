// C++ code
//
// bool executado = false;
int estado = 0;
bool ultimoBotao = LOW;

unsigned long tempoAnterior = 0;
bool ledEstado = false;

void setup()
{
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop()
{
  /*
  // ex1 ( Luz )
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  
  // ex2 ( Led )
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(10, LOW);
  delay(1000);
  
  //ex3 ( Led com intensidade )
  if( executado == false){
    for(int intensidade = 0; intensidade < 255; intensidade += 5){
      analogWrite(10, intensidade);
      delay(40);
    }
    for(int intensidade = 255; intensidade > 0; intensidade -= 5){
      analogWrite(10, intensidade);
      delay(40);
    }
  }
  */
  // ex4 ( Botão com Intensidade de Led )
  bool botao = digitalRead(2);
  
  // detectar clique ( borda de subida )
  if( botao == LOW && ultimoBotao == HIGH ){
    estado++;
    if( estado > 5 ) estado = 0;
  }
  
  ultimoBotao = botao; // garante que o code funciona apenas quando o botao for pressionado pela primeira vez
  
  // estados
  if( estado == 0 ){
    digitalWrite(10,LOW);
  }
  else{
    int tempo = 1000 / estado; // quanto maior estado mais rápido
    if(millis() - tempoAnterior >= tempo){
      tempoAnterior = millis();
      
      ledEstado = !ledEstado;
      digitalWrite(10, ledEstado);
  	}
  }
}