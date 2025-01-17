#include <ESP8266WiFi.h>
#include<ESP8266WebServer.h>


String ssid     = "Francisco";
String password = "12345678";
ESP8266WebServer server(80);
void handleRoot(){
  digitalWrite(2,1);
  server.send(200,"text/plano ","hello world" );
  digitalWrite(2,0);
}
  

byte cont = 0;
byte max_intentos = 50;

void setup() {
  // Inicia Serial
  Serial.begin(115200);
  Serial.println("\n");

  // Conexión WIFI
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED and cont < max_intentos) { //Cuenta hasta 50 si no se puede conectar lo cancela
    cont++;
    delay(500);
    Serial.print(".");
  }

Serial.println("");

  if (cont < max_intentos) {  //Si se conectó      
      Serial.println("********************************************");
      Serial.print("Conectado a la red WiFi: ");
      Serial.println(WiFi.SSID());
      Serial.print("IP: ");
      Serial.println(WiFi.localIP());
      Serial.print("macAdress: ");
      Serial.println(WiFi.macAddress());
      Serial.println("*********************************************");

      server.on("/",handleRoot);
      server.begin();
      Serial.println("Server HTTP started");
  }
  else { //No se conectó
      Serial.println("------------------------------------");
      Serial.println("Error de conexion");
      Serial.println("------------------------------------");
  }
}

void loop() {
 server.handleClient();
}
