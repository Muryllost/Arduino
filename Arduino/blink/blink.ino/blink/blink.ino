// projeto Ultrassonico ultraMais
// declaração das variaveis
// usando arrays (vetores)
byte led[] = {2, 3, 4, 5, 8, 9, 10, 11};

int trigger = 7;
int echo = 6;
float distancia = 0;

void setup() 
{
   for(int i = 0; i < sizeof(led); i++) 
   {
      pinMode(led[i], OUTPUT); 
   } 
   pinMode(trigger, OUTPUT);
   pinMode(echo, INPUT); 

   Serial.begin(9600);
}

void loop()
{
    sensor();
    piscar();
}

void sensor()
{
    digitalWrite(trigger, LOW);
    delay(10); 
    digitalWrite(trigger, HIGH);
    delay(10); 
    digitalWrite(trigger, LOW);

    long duracao = pulseIn(echo, HIGH);
    distancia = duracao / 58.0;

    Serial.print("A distancia e: ");
    Serial.print(distancia);
    Serial.println(" cm");
}

void piscar()
{
   int velocidade = 0;
   
   if(distancia >= 200)
   {
      velocidade = 500; // piscam devagar
   } 
   else if(distancia >= 100)
   {
      velocidade = 200; // piscam em um ritmo médio
   } 
   else 
   {
      velocidade = 50; // piscam rapidamente
   }
   
   for(int x = 0; x < sizeof(led); x++)
   {
      digitalWrite(led[x], HIGH);
      delay(velocidade);
      digitalWrite(led[x], LOW);
      delay(velocidade);
   }
}

void apagarTudo()
{
   for(int x = 0; x < sizeof(led); x++)
   {
      digitalWrite(led[x], LOW);
   }
}
