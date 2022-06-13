//Pin define
#define LEFT D5
#define RIGHT D6

//Path que va a leer la estacion central
#define pathStation "estacion/Pluviometro"

//Declaración de variables
int contador;
bool lado;

//Metodos de procesamiento
//Limpia el contador
void reset(){
  contador = 0;
}

//Cambia el estado del balancin
void stateChange(){
  lado = !lado;
}

//procesa los datos
int procesar(){
  int temp = contador * 5;
  reset();
  return temp;
}

//Llama a procesamiento, limpia las variables y regresa el dato resultante
int obtenerValor(){  
  return procesar();
}

//Metodos que sirve para la interrupcion
void left(){
  if(lado){    
    contador++;
    stateChange();
  }
}

void right(){
  if(!lado){    
    contador++;
    stateChange();
  }
}

/*Metodo inial, contiene las declaraciones de los pines
Las interrupciones y la asignacion de datos a variables*/
void iniciar(){
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);

  attachInterrupt(LEFT, left, RISING);
  attachInterrupt(RIGHT, right, RISING);

  lado = true;
  reset();
}
