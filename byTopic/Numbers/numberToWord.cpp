#include<iostream>


void spellOneDigits(int I, std::string &str) {
  switch (I) {
    case 1:
      str.append("One");
      break;
    case 2:
      str.append("Two");
      break;
    case 3:
      str.append("Three");
      break;
    case 4:
      str.append("Four");
      break;
    case 5:
      str.append("Five");
      break;
    case 6:
      str.append("Six");
      break;
    case 7:
      str.append("Seven");
      break;
    case 8:
      str.append("Eight");
      break;
    case 9:
      str.append("Nine");
      break;
  }
}

void spellTwoDigits(int I, std::string &str) {
  switch (I) {
    case 11:
      str.append("Eleven");
      break;
    case 12:
      str.append("Twelve");
      break;
    case 13:
      str.append("Thirteen");
      break;
    case 14:
      str.append("Forteen");
      break;
    case 15:
      str.append("Fifteen");
      break;
    case 16:
      str.append("Sixteen");
      break;
    case 17:
      str.append("Seventeen");
      break;
    case 18:
      str.append("Eighteen");
      break;
    case 19:
      str.append("Nineteen");
      break;
    default:
      int tens = I/10;
      I = I%10;
      if(0 == tens) {
        spellOneDigits(I, str);
      } else if(1 == tens) {
        str.append(" Ten ");
      } else if(2 == tens) {
        str.append(" Twenty ");
        spellOneDigits(I, str);
      } else if(3 == tens) {
        str.append(" Thirty ");
        spellOneDigits(I, str) ;
      } else if(4 == tens) {
        str.append(" Fourty ");
        spellOneDigits(I, str) ;
      } else if(5 == tens) {
        str.append(" Fifty ");
        spellOneDigits(I, str) ;
      } else if(6 == tens) {
        str.append(" Sixty ");
        spellOneDigits(I, str) ;
      } else if(7 == tens) {
        str.append(" Seventy ");
        spellOneDigits(I, str) ;
      } else if(8 == tens) {
        str.append(" Eighty " );
        spellOneDigits(I, str) ;
      } else if(9 == tens) {
        str.append(" Ninety ");
        spellOneDigits(I, str) ;
      }
  }
}

void spellThreeDigits(int I, std::string &str) {
  I = abs(I);
  int hundrens = I/100;
  if(0!= hundrens) {
    spellOneDigits(hundrens, str);
    str.append(" Hundred ");
  }
  I = I%100;
  spellTwoDigits(I, str);
}

void 
numberToWord(int I, std::string &str){
  
  if(0 == I) {
    str.append("Zero");
    return;
  } 

  if(I < 0) {
    str.append(" - ");
  }
  //I = abs(I);

  int billions = I/1000000000;
  if(0 != billions) {
   spellThreeDigits(billions, str);
   str.append(" Billion ");
  }
  I = I%1000000000;

  int millions = I/1000000;
  if(0 != millions) {
    spellThreeDigits(millions, str);
    str.append(" Millinos ");
  }
  I = I%1000000;

  int thousands = I/1000;
  if(0 != thousands) {
    spellThreeDigits(thousands, str);
    str.append(" Thousand ");
  }
  I = I%1000;

  spellThreeDigits(I, str);
}


int main() 
{

  for(int I = -1000000;I <= 1000000 ; I++) {
    std::string str("");
    numberToWord(I, str);
    std::cout<< I << " In words : " << str << "\n";
    str.clear();
  }

  return 0;
}
