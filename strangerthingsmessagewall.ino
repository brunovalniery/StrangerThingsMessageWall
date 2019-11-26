//Definição de Pinos
#define pin_A_I_R 2
#define pin_B_J_S 3
#define pin_C_K_T 4
#define pin_D_L_U 5
#define pin_E_M_V 6
#define pin_F_N_W 7
#define pin_G_O_X 8
#define pin_H_P_Y 9
#define pin_Q_Z   10

#define linha1 11
#define linha2 12
#define linha3 13

String text;                                                    //Variável do tipo string que receberá o texto

void setup() {
  Serial.begin(9600);                                           //Velocidade de comunicação
  pinMode(pin_A_I_R, OUTPUT);                                   //Declarando o pino como saída
  pinMode(pin_B_J_S, OUTPUT);                                   //Declarando o pino como saída
  pinMode(pin_C_K_T, OUTPUT);                                   //Declarando o pino como saída
  pinMode(pin_D_L_U, OUTPUT);                                   //Declarando o pino como saída
  pinMode(pin_E_M_V, OUTPUT);                                   //Declarando o pino como saída
  pinMode(pin_F_N_W, OUTPUT);                                   //Declarando o pino como saída
  pinMode(pin_G_O_X, OUTPUT);                                   //Declarando o pino como saída
  pinMode(pin_H_P_Y, OUTPUT);                                   //Declarando o pino como saída
  pinMode(pin_Q_Z, OUTPUT);                                     //Declarando o pino como saída
  
  pinMode(linha1, OUTPUT);                                      //Declarando o pino como saída
  pinMode(linha2, OUTPUT);                                      //Declarando o pino como saída
  pinMode(linha3, OUTPUT);                                      //Declarando o pino como saída
  
  inicializationEffect();                                       //Chamada da Função responsável pelo efeito inicial
}

void loop() {  
   receberTexto();                                               //Chamada da função responsável por receber o texto digitado
}

//Função que recebe o texto digitado
void receberTexto()(){
  while(Serial.available() > 0){                                //Verifica se existe alguma informação na Serial
    char c = Serial.read();                                     //atribui cada caractere a variável c que é do tipo char
    if(c != '\n') text.concat(c);                               //verifica se a variável do tipo char recebeu uma quebra de linha que indica o fim da palavra ou frase e concatena todos os caracteres na String text
    delay(10);                                                  //aguarda 10 milissegundos 
  }  
  if(text.length() > 0){                                        //verifica se a string text tem tamanho maior que 0
    text.toUpperCase();                                         //transforma tudo que estiver na string text para maiúsculo 
    executeEffect(text);                                        //chama a função executeEffect passando a string text como parâmetro
  }

  text = "";                                                    //limpa a string text
}

//Função responsável por ativar linha que recebe como parâmetro o número da linha
void lineActivation(int line){ 
  if(line == 1){                                                //verifica se a linha recebida como parâmetro é a linha 1 e se for:
      digitalWrite(line_2, LOW);                                //coloca a linha 2 em estado lógico baixo
      digitalWrite(line_3, LOW);                                //coloca a linha 3 em estado lógico baixo
      digitalWrite(line_1, HIGH);                               //coloca a linha 1 em estado lógico alto
  }else if (line == 2){                                         //verifica se a linha recebida como parâmetro é a linha 2 e se for:
      digitalWrite(line_1, LOW);                                //coloca a linha 1 em estado lógico baixo
      digitalWrite(line_3, LOW);                                //coloca a linha 3 em estado lógico baixo
      digitalWrite(line_2, HIGH);                               //coloca a linha 2 em estado lógico alto
  }else if(line == 3){                                          //verifica se a linha recebida como parâmetro é a linha 3 e se for:   
      digitalWrite(line_1, LOW);                                //coloca a linha 1 em estado lógico baixo
      digitalWrite(line_2, LOW);                                //coloca a linha 2 em estado lógico baixo
      digitalWrite(line_3, HIGH);                               //coloca a linha 3 em estado lógico alto
  }
}

//Função responsável por ativar a letra e recebe como parâmetro a letra, tempo que ficará ligada e tempo que ficará desligada
void activateLetter(char letter, int on, int off){
   if(letter == 'A' or letter == 'I' or letter == 'R'){         //verifica se a letra recebida é A, I ou R
      digitalWrite(pin_A_I_R, HIGH);                            //coloca o pino responsável pelas letras A, I, R em nível lógico alto
      delay(on);                                                //mantém o pino em nível lógico alto durante o tempo que foi determinado no parâmetro da função
      digitalWrite(pin_A_I_R, LOW);                             //coloca o pino responsável pelas letras A, I, R em nível lógico baixo
      delay(off);                                               //mantém o pino em nível lógico baixo durante o tempo que foi determinado no parâmetro da função
   }else
   if(letter == 'B' or letter == 'J' or letter == 'S'){         //verifica se a letra recebida é B, J ou S
      digitalWrite(pin_B_J_S, HIGH);                            //coloca o pino responsável pelas letras B, J, S em nível lógico alto
      delay(on);                                                //mantém o pino em nível lógico alto durante o tempo que foi determinado no parâmetro da função
      digitalWrite(pin_B_J_S, LOW);                             //coloca o pino responsável pelas letras B, J, S em nível lógico baixo
      delay(off);
   }else
   if(letter == 'C' or letter == 'K' or letter == 'T'){         //verifica se a letra recebida é C, K ou T
      digitalWrite(pin_C_K_T, HIGH);                            //coloca o pino responsável pelas letras C, K, T em nível lógico alto
      delay(on);                                                //mantém o pino em nível lógico alto durante o tempo que foi determinado no parâmetro da função
      digitalWrite(pin_C_K_T, LOW);                             //coloca o pino responsável pelas letras C, K, T em nível lógico baixo
      delay(off);                                               //mantém o pino em nível lógico baixo durante o tempo que foi determinado no parâmetro da função
   }else
   if(letter == 'D' or letter =='L' or letter == 'U'){          //verifica se a letra recebida é D, L ou U
      digitalWrite(pin_D_L_U, HIGH);                            //coloca o pino responsável pelas letras D, L, U em nível lógico alto
      delay(on);                                                //mantém o pino em nível lógico alto durante o tempo que foi determinado no parâmetro da função
      digitalWrite(pin_D_L_U, LOW);                             //coloca o pino responsável pelas letras D, L, U em nível lógico baixo
      delay(off);                                               //mantém o pino em nível lógico baixo durante o tempo que foi determinado no parâmetro da função
   }else
   if(letter == 'E' or letter == 'M' or letter == 'V'){         //verifica se a letra recebida é E, M ou V
      digitalWrite(pin_E_M_V, HIGH);                            //coloca o pino responsável pelas letras E, M, V em nível lógico alto
      delay(on);                                                //mantém o pino em nível lógico alto durante o tempo que foi determinado no parâmetro da função
      digitalWrite(pin_E_M_V, LOW);                             //coloca o pino responsável pelas letras E, M,  V em nível lógico baixo
      delay(off);                                               //mantém o pino em nível lógico baixo durante o tempo que foi determinado no parâmetro da função
   }else
   if(letter == 'F' or letter == 'N' or letter == 'W'){         //verifica se a letra recebida é F, N, W
      digitalWrite(pin_F_N_W, HIGH);                            //coloca o pino responsável pelas letras F, N, W em nível lógico alto
      delay(on);                                                //mantém o pino em nível lógico alto durante o tempo que foi determinado no parâmetro da função
      digitalWrite(pin_F_N_W, LOW);                             //coloca o pino responsável pelas letras F, N,  W em nível lógico baixo
      delay(off);                                               //mantém o pino em nível lógico baixo durante o tempo que foi determinado no parâmetro da função
   }else
   if(letter == 'G' or letter == 'O' or letter == 'X'){         //verifica se a letra recebida é G, O, X
      digitalWrite(pin_G_O_X, HIGH);                            //coloca o pino responsável pelas letras G, O, X em nível lógico alto
      delay(on);                                                //mantém o pino em nível lógico alto durante o tempo que foi determinado no parâmetro da função
      digitalWrite(pin_G_O_X, LOW);                             //coloca o pino responsável pelas letras G, O, X em nível lógico baixo
      delay(off);                                               //mantém o pino em nível lógico baixo durante o tempo que foi determinado no parâmetro da função
   }else
   if(letter == 'H' or letter == 'P' or letter == 'Y'){         //verifica se a letra recebida é H, P, Y
      digitalWrite(pin_H_P_Y, HIGH);                            //coloca o pino responsável pelas letras H, P,  Y em nível lógico alto
      delay(on);                                                //mantém o pino em nível lógico alto durante o tempo que foi determinado no parâmetro da função
      digitalWrite(pin_H_P_Y, LOW);                             //coloca o pino responsável pelas letras H, P,  Y em nível lógico baixo
      delay(off);                                               //mantém o pino em nível lógico baixo durante o tempo que foi determinado no parâmetro da função
   }else
   if(letter == 'Q' or letter == 'Z'){                          //verifica se a letra recebida é Q OU Z
      digitalWrite(pin_Q_Z, HIGH);                              //coloca o pino responsável pelas letras Q, Z em nível lógico alto
      delay(on);                                                //mantém o pino em nível lógico alto durante o tempo que foi determinado no parâmetro da função
      digitalWrite(pin_Q_Z, LOW);                               //coloca o pino responsável pelas letras Q, Z em nível lógico baixo
      delay(off);                                               //mantém o pino em nível lógico baixo durante o tempo que foi determinado no parâmetro da função
   }   
}

//Função responsável por executar o efeito de acender as luzes reespectivas às letras da palavra contida na string text
void executeEffect(String text){
  for(int i = 0; i < text.length(); i++){                       //laço responsável por percorrer toda os caracteres contidos na string text (text.length retorna o tamanho da string text)
    switch(text[i]){                                            //verifica se o caractere que está na posição i é:
      case 'A':                                                 //caso seja o caractere A
        lineActivation(1);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 1
        activateLetter('A', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra A, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'B':                                                 //caso seja o caractere B
        lineActivation(1);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 1
        activateLetter('B', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra B, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'C':                                                 //caso seja o caractere C
        lineActivation(1);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 1
        activateLetter('C', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra C, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'D':                                                 //caso seja o caractere D
        lineActivation(1);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 1
        activateLetter('D', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra D, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'E':                                                 //caso seja o caractere E
        lineActivation(1);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 1
        activateLetter('E', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra E, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'F':                                                 //caso seja o caractere F
        lineActivation(1);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 1
        activateLetter('F', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra F, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'G':                                                 //caso seja o caractere G
        lineActivation(1);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 1
        activateLetter('G', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra G, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'H':                                                 //caso seja o caractere H
        lineActivation(1);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 1
        activateLetter('H', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra H, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'I':                                                 //caso seja o caractere I
        lineActivation(2);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 2
        activateLetter('I', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra I, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'J':                                                 //caso seja o caractere J
        lineActivation(2);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 2
        activateLetter('J', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra J, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'K':                                                 //caso seja o caractere K
        lineActivation(2);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 2
        activateLetter('K', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra K, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'L':                                                 //caso seja o caractere L
        lineActivation(2);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 2
        activateLetter('L', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra L, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'M':                                                 //caso seja o caractere M
        lineActivation(2);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 2
        activateLetter('M', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra M, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'N':                                                 //caso seja o caractere N
        lineActivation(2);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 2
        activateLetter('N', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra N, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'O':                                                 //caso seja o caractere O
        lineActivation(2);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 2
        activateLetter('O', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra O, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'P':                                                 //caso seja o caractere P
        lineActivation(2);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 2
        activateLetter('P', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra P, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'Q':                                                 //caso seja o caractere Q
        lineActivation(2);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 2
        activateLetter('Q', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra Q, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'R':                                                 //caso seja o caractere R
        lineActivation(3);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 3
        activateLetter('R', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra R, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'S':                                                 //caso seja o caractere S
        lineActivation(3);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 3
        activateLetter('S', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra S, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'T':                                                 //caso seja o caractere T
        lineActivation(3);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 3
        activateLetter('T', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra T, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'U':                                                 //caso seja o caractere U
        lineActivation(3);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 3
        activateLetter('U', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra U, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'V':                                                 //caso seja o caractere V
        lineActivation(3);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 3
        activateLetter('V', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra V, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'W':                                                 //caso seja o caractere W 
        lineActivation(3);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 3
        activateLetter('W', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra W, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'X':                                                 //caso seja o caractere X
        lineActivation(3);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 3
        activateLetter('X', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra X, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'Y':                                                 //caso seja o caractere Y
        lineActivation(3);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 3
        activateLetter('Y', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra Y, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;

      case 'Z':                                                 //caso seja o caractere A
        lineActivation(3);                                      //chama a função responsável por ativar linha e passa como parâmetro a linha 3
        activateLetter('Z', 1000, 200);                         //chama a função responável por ativar a letra, passando como parâmetro a letra Z, tempo de 1000 milissegundos para ficar ligada e de 200 milissegundos desligada
      break;
      
      case ' ':                                                 //caso seja o caractere espaço em branco
        delay(1000);                                            //aguarda um tempo de 1000 milissegundos
      break;
    }
  }
}

//Função responsável pelo efeito de inicialização
void inicializationEffect(){
  lineActivation(1);                                            //ativa a linha 1
  activateLetter('A', 100, 10);                                 //ativa a letra A por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('B', 100, 10);                                 //ativa a letra B por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('C', 100, 10);                                 //ativa a letra C por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('D', 100, 10);                                 //ativa a letra D por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('E', 100, 10);                                 //ativa a letra E por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('F', 100, 10);                                 //ativa a letra F por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('G', 100, 10);                                 //ativa a letra G por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('H', 100, 10);                                 //ativa a letra H por 100 milissegundos e desliga por 10 milissegundos
  
  lineActivation(2);                                            //ativa a linha 2
  activateLetter('I', 100, 10);                                 //ativa a letra I por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('J', 100, 10);                                 //ativa a letra J por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('K', 100, 10);                                 //ativa a letra K por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('L', 100, 10);                                 //ativa a letra L por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('M', 100, 10);                                 //ativa a letra M por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('N', 100, 10);                                 //ativa a letra N por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('O', 100, 10);                                 //ativa a letra O por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('P', 100, 10);                                 //ativa a letra P por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('Q', 100, 10);                                 //ativa a letra Q por 100 milissegundos e desliga por 10 milissegundos

  lineActivation(3);                                            //ativa a linha 3
  activateLetter('R', 100, 10);                                 //ativa a letra R por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('S', 100, 10);                                 //ativa a letra S por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('T', 100, 10);                                 //ativa a letra T por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('U', 100, 10);                                 //ativa a letra U por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('V', 100, 10);                                 //ativa a letra V por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('W', 100, 10);                                 //ativa a letra W por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('X', 100, 10);                                 //ativa a letra X por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('Y', 100, 10);                                 //ativa a letra Y por 100 milissegundos e desliga por 10 milissegundos
  activateLetter('Z', 100, 10);                                 //ativa a letra Z por 100 milissegundos e desliga por 10 milissegundos
}
