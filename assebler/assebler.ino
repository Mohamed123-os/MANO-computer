#define AND  0x00
#define ADD   0x01
#define LDA   0x02
#define STA   0x03
#define BUN   0x04
#define BSA   0x05
#define ISZ   0x06
#define CLA   0x7800   
#define CLE   0x7400
#define CMA   0x7200
#define CME   0x7100
#define CIR   0x7080
#define CIL   0x7040
#define INC   0x7020
#define SPA   0x7010
#define SNA   0x7008 
#define SZA   0x7004
#define SZE   0x7002
#define HLT   0x7001
#define INP   0xF800
#define OUT   0xF400
#define SKI   0xF200
#define SKO   0xF100
#define ION   0xF080
#define IOF   0xF040
#define MAX_VALUES_ADDRESSES   50
#define NO_OF_CODE_LINES     4

unsigned int  direct=0;
unsigned short address=0;
unsigned short pc=0;
unsigned short counter=0;
unsigned short vales_addresses[MAX_VALUES_ADDRESSES];
unsigned short count=0;
uint16_t program[] = 
  {
    LDA, 0x004,
    ADD, 0x005, // Example assembly instructions
    STA, 0x006,
    HLT
  };
unsigned short values[]={1,2,0}; //WRIE VALUES OF YOUR CODE HERE
void setup() 
{
    // put your setup code here, to run once:
  DDRA=0xFF;
  DDRC=0xFF;
  DDRL=0xFF;
  DDRB=0xFF;
  DDRG=0xFF;
  while(count<NO_OF_CODE_LINES)
  {
    digitalWrite(40,HIGH);

    switch(program[pc])
    {
      case AND:
          if(direct==0)
          {
            PORTA=((AND<<4)|(program[pc+1]>>8));
          }  
          else 
          {
            PORTA=((8<<4)|(program[pc+1]>>8));
          } 
          PORTC=program[pc+1];
          vales_addresses[counter++]=program[pc+1];
          pc+=2;
          break;    

      case ADD:
          if(direct==0)
          {
            PORTA=((ADD<<4)|(program[pc+1]>>8));
          }  
          else 
          {
            PORTA=((9<<4)|(program[pc+1]>>8));
          } 
          PORTC=program[pc+1];
          vales_addresses[counter++]=program[pc+1];
          pc+=2;    
          break;

      case LDA:
          if(direct==0)
          {
            PORTA=((LDA<<4)|(program[pc+1]>>8));
         
          }  
          else 
          {
            PORTA=((0xA<<4)|(program[pc+1]>>8));
           
          } 
          PORTC=program[pc+1];
          vales_addresses[counter++]=program[pc+1];
          pc+=2; 
          break;

      case STA:
          if(direct==0)
          {
            PORTA=((STA<<4)|(program[pc+1]>>8));
          
          }  
          else 
          {
            PORTA=((0xB<<4)|(program[pc+1]>>8));
           
          } 
          PORTC=program[pc+1];
          vales_addresses[counter++]=program[pc+1];
          pc+=2;
          break; 

      case BUN:
          if(direct==0)
          {
            PORTA=((BUN<<4)|(program[pc+1]>>8));
          }  
          else 
          {
            PORTA=((0xC<<4)|(program[pc+1]>>8));
          } 
          PORTC=program[pc+1];
          vales_addresses[counter++]=program[pc+1];
          pc+=2;
          break;    
      case BSA:
          if(direct==0)
          {
            PORTA=((BSA<<4)|(program[pc+1]>>8));
        
          }  
          else 
          {
            PORTA=((0xD<<4)|(program[pc+1]>>8));
      
          } 
          PORTC=program[pc+1];
          vales_addresses[counter++]=program[pc+1];
          pc+=2;
          break;

      case ISZ:
          if(direct==0)
          {
            PORTA=((ISZ<<4)|(program[pc+1]>>8));
          
          }  
          else 
          {
            PORTA=((0xE<<4)|(program[pc+1]>>8));
            
          } 
          PORTC=program[pc+1];
          vales_addresses[counter++]=program[pc+1];
          pc+=2;
          break;

      case CLA:
          PORTA=CLA>>8;
          PORTC=CLA;   
          pc+=1;
          break;   
      case CLE:
          PORTA=CLE>>8;
          PORTC=CLE;   
          pc+=1;
          break;    
      case CMA:
          PORTA=CMA>>8;
          PORTC=CMA;   
          pc+=1;
          break;    
      case CME:
          PORTA=CME>>8;
          PORTC=CME;   
          pc+=1;
          break;    
      case CIR:
          PORTA=CIR>>8;
          PORTC=CIR;   
          pc+=1;
          break;    
     case CIL:
          PORTA=CIL>>8;
          PORTC=CIL;   
          pc+=1;
          break;
     case INC:
          PORTA=INC>>8;
          PORTC=INC;   
          pc+=1;
          break;    
     case SPA:
          PORTA=SPA>>8;
          PORTC=SPA;   
          pc+=1;
          break;    
     case SNA:
          PORTA=SNA>>8;
          PORTC=SNA;   
          pc+=1;
          break;    
     case SZA:
          PORTA=SZA>>8;
          PORTC=SZA;   
          pc+=1;
          break;    
     case SZE:
          PORTA=SZE>>8;
          PORTC=SZE;   
          pc+=1;
          break;    
     case HLT:
          PORTA=HLT>>8;
          PORTC=HLT;   
          pc+=1;
          break;    
     case (INP):
          PORTA=INP>>8;
          PORTC=INP;   
          pc+=1;
          break;
     case (OUT):
          PORTA=OUT>>8;
          PORTC=OUT;   
          pc+=1;
          break; 

     case (SKI):
          PORTA=SKI>>8;
          PORTC=SKI;   
          pc+=1;
          break; 

     case (SKO):
          PORTA=SKO>>8;
          PORTC=SKO;   
          pc+=1;
          break; 
     case (ION):
          PORTA=ION>>8;
          PORTC=ION;   
          pc+=1;
          break; 
     case (IOF):
          PORTA=IOF>>8;
          PORTC=IOF;   
          pc+=1;
          break; 
     default:
          digitalWrite(39,HIGH);
          break; 
                                                                                                                         
    }
    PORTB=address>>8;
    PORTL=address;
    digitalWrite(41,HIGH);
    _delay_ms(100);
    digitalWrite(41,LOW);
    _delay_ms(100);
    address++;
    count++;
  }
  for (int i=0; i<counter; i++)
  {
    PORTB=vales_addresses[i]>>8;
    PORTL=vales_addresses[i];
    PORTA=values[i]>>8;
    PORTC=values[i]; 
    digitalWrite(41,HIGH);
    _delay_ms(100);
    digitalWrite(41,LOW);
    _delay_ms(100);
  }
   digitalWrite(40,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
}
