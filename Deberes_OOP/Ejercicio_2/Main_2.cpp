//Qué hace esta función?

void misteriousFunction(const int* value) {
	*value = 0;
}

/*Respuesta:
Como la variable que inicializamos en la función es un puntero a datos constantes
si intentamos modificar los datos a los que apunta el puntero, no nos lo permitirá.*/