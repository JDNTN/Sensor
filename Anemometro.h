//Declaracion de pinea
#define VELOCIDAD_BAJA D5
#define VELOCIDAD_MEDIA D6
#define VELOCIDAD_ALTA D7

//Path para MQTT estacion central
#define pathStation "estacion/Anemometro"

const int MAX_VEL_BAJA = 2;
const int MAX_VELMEDIA = 8;

const int VEL_BAJA = 2;
const int VEL_MEDIA = 3;
const int VEL_ALTA = 4;

//Declaracion de variables
int velBaja;
int velMedia;
int velAlta;

bool flagBaja;
bool flagMedia;
bool flagAlta;

//Limpia los contadores
void reset(){
  velBaja = 0;
  velMedia = 0;
  velAlta = 0;
}

//Procesa los datos
int procesar(){
  if(velAlta <= MAX_VEL_BAJA){
    return velBaja * VEL_BAJA;
  }else if(velAlta <= MAX_VELMEDIA){
    return velMedia * VEL_MEDIA;
  }else if(velAlta >= MAX_VELMEDIA){
    return velAlta * VEL_ALTA;
  }  
}

//regresa el valor obtenido
int obtenerValor(){
   int temp = procesar();
   reset();
   return temp;
}

void addVelBaja(){  
  //if (!flagBaja) {
    velBaja++;
    flagBaja = true;
  //}  
}
void addVelMedia(){
  //if (!flagMedia) {
    velMedia++;
    flagMedia = true;
  //}
}
void addVelAlta(){
  //if (!flagAlta) {
    velAlta++;
    flagAlta = true;
//  }
}

void iniciar(){
  //Declaracion pines entrada
  pinMode(VELOCIDAD_BAJA, INPUT_PULLUP);
  pinMode(VELOCIDAD_MEDIA, INPUT_PULLUP);
  pinMode(VELOCIDAD_ALTA, INPUT_PULLUP);

  //Declaracion interrupcion
  attachInterrupt(VELOCIDAD_BAJA, addVelBaja, RISING);
  attachInterrupt(VELOCIDAD_MEDIA,addVelMedia,RISING);
  attachInterrupt(VELOCIDAD_ALTA, addVelAlta, RISING);

  //Limpiar Contadores
  reset();  
}
