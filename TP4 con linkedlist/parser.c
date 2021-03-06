#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int parser_EmployeeFromText(FILE* pointerFile , LinkedList* pointerArrayListEmployee){
	int retorno = -1;
	char buffer[4][130];

	Employee* pointerAuxEmpleado=NULL;

	if(pointerFile != NULL && pointerArrayListEmployee != NULL){
		fscanf(pointerFile, "%[^,],%[^,],%[^,],%[^\n]\n", *(buffer+0), *(buffer+1),*(buffer+2),*(buffer+3));


	while( !feof(pointerFile) ){
		fscanf(pointerFile, "%[^,],%[^,],%[^,],%[^\n]\n", *(buffer+0), *(buffer+1),*(buffer+2),*(buffer+3));
		pointerAuxEmpleado = employee_newParametros(*(buffer+0), *(buffer+1),*(buffer+2),*(buffer+3));

		if(pointerAuxEmpleado != NULL){
			ll_add(pointerArrayListEmployee,pointerAuxEmpleado); //Agrego cada empleado de la lista a la linkedlist
			retorno=0;
		}


	}

	}
  	 return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int parser_EmployeeFromBinary(FILE* pointerFile , LinkedList* pointerArrayListEmployee)
{	int retorno = -1;
	int retornoLeido;
	Employee* pointerAuxEmpleado=NULL;
	Employee auxiliarEmployee;

		if(pointerFile!=NULL && pointerArrayListEmployee!=NULL){

			while( !feof(pointerFile) ){

				retornoLeido = fread(&auxiliarEmployee,sizeof(Employee),1,pointerFile);
				pointerAuxEmpleado = employee_new();
				if (pointerAuxEmpleado != NULL ) {

					if(retornoLeido != 0){

						if(  (employee_setId(pointerAuxEmpleado, auxiliarEmployee.id)   == 0) &&
						(employee_setNombre(pointerAuxEmpleado, auxiliarEmployee.nombre)  == 0) &&
						(employee_setHorasTrabajadas(pointerAuxEmpleado, auxiliarEmployee.horasTrabajadas) == 0) &&
						(employee_setSueldo(pointerAuxEmpleado, auxiliarEmployee.sueldo) == 0) ){

							ll_add(pointerArrayListEmployee, pointerAuxEmpleado);
							retorno = 0;
						}
					}

				}
			}
		}

    return retorno;
}
