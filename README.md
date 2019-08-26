# Learningcpp
T1 Computación en GPU

¿Afecta en algo el tipo de dato de su matriz?, ¿Qué pasa si realiza operaciones de multiplicación o inversa con un tipo de dato integer o double.
-si afecta, la precision del tipo int es de 32 bits, en cambio para double es de 64 bits, esto significa que para calculos de numeros grandes es más util y preciso usar datos tipo double, por eso es tan util que la clase Matriz esté diseñada con templates.

¿Qué pasa si se normaliza la matriz con un integer o con un double?
-la precicion podria cambiar algunos resultados ya que el tamaño de bit de precicion es distinto y 


Si se empezaran a usar números muy pequeños o muy grandes y principalmente números
primos, ¿Qué ocurre en términos de precisión?
-la precision cambiaria sobre todo al normalizar.

¿Pueden haber problemas de precisión si se comparan dos matrices idénticas pero con diferente
tipo? (Matrix p1 == p2)
-No se pueden comparar con los metodos programados, a pesar de estar en un template, solo se pueden comparar matrices del mismo tipo de datos.
-El método equals no dejaría compilar por ser de distinto tipo. 
