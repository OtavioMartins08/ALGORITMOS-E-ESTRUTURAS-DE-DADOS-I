//05. Qual a saıda do seguinte programa?

#include <stdio.h >
int main ( ) {
int i ;
for ( i =1 ; i <= 100 ; i *=100) {
if ( i ==30 ) {
break ;
}
else {
printf ("%2d\n" ,2* i ) ;
}
}
printf ("Fim do laco !\n") ;
return 0;
}

//saida: 
//2
//200 
//Fim do laco !
