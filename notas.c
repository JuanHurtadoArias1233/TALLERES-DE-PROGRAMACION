#include <stdio.h>

int main() {
    // Declaración de variables
    float calificaciones[5][3]; // Matriz para almacenar calificaciones: 5 estudiantes, 3 asignaturas
    int continuador = 1, opcion, registrado = 0; // Bandera para verificar si se han ingresado calificaciones
    int i, j; // Para bucles

    // Inicializar matriz con -1 para indicar no ingresado
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            calificaciones[i][j] = -1.0;
        }
    }

    while (continuador == 1) { // Bucle principal del menú
        // Despliegue del menú
        printf("\n------* Programa de Gestión de Calificaciones *------");
        printf("\n1. Registrar calificaciones.");
        printf("\n2. Mostrar promedios por estudiante.");
        printf("\n3. Mostrar promedios por asignatura.");
        printf("\n4. Mostrar calificación más alta y baja por estudiante.");
        printf("\n5. Mostrar calificación más alta y baja por asignatura.");
        printf("\n6. Mostrar aprobados y reprobados por asignatura.");
        printf("\n7. Salir.");
        printf("\nOpción: ");

        // Lectura robusta de la opción con manejo de errores
        if (scanf("%d", &opcion) != 1) {
            // Si no es un número, limpiar buffer y error
            while (getchar() != '\n'); // Limpiar el buffer de entrada
            printf("\nEntrada no válida. Debe ingresar un número.\n");
            opcion = 0; // Reiniciar para no procesar
        } else {
            // Limpiar buffer después de éxito
            while (getchar() != '\n');
        }

        // Procesamiento con switch para mayor claridad
        switch (opcion) {
            case 1: // Opción de registro de calificaciones
                registrado = 1; // Marcar como registrado
                printf("\nIngrese las calificaciones de los 5 estudiantes en las 3 asignaturas (rango: 0-10):\n");
                for (i = 0; i < 5; i++) {
                    for (j = 0; j < 3; j++) {
                        float nota;
                        do {
                            printf("Estudiante %d, Asignatura %d: ", i + 1, j + 1);
                            if (scanf("%f", &nota) != 1) {
                                // Si no es número, limpiar y pedir de nuevo
                                while (getchar() != '\n');
                                printf("Error: Debe ingresar un número. Intente nuevamente.\n");
                                nota = -1.0; // Valor inválido para loop
                            } else {
                                while (getchar() != '\n'); // Limpiar buffer
                                if (nota < 0 || nota > 10) {
                                    printf("Error: La calificación debe estar entre 0 y 10. Intente nuevamente.\n");
                                }
                            }
                        } while (nota < 0 || nota > 10);
                        calificaciones[i][j] = nota;
                    }
                }
                printf("\nCalificaciones registradas exitosamente.\n");
                printf("Presione Enter para continuar...");
                getchar(); // Pausa
                break;

            case 2: // Mostrar promedios por estudiante
                if (registrado == 0) {
                    printf("\nPrimero se deben registrar las calificaciones.");
                } else {
                    printf("\n--- PROMEDIOS POR ESTUDIANTE ---");
                    for (i = 0; i < 5; i++) {
                        float suma = 0;
                        for (j = 0; j < 3; j++) {
                            suma += calificaciones[i][j];
                        }
                        float promedio = suma / 3.0;
                        printf("\nEstudiante %d: %.2f", i + 1, promedio);
                    }
                    printf("\nPresione Enter para continuar...");
                    getchar();
                }
                break;

            case 3: // Mostrar promedios por asignatura
                if (registrado == 0) {
                    printf("\nPrimero se deben registrar las calificaciones.");
                } else {
                    printf("\n--- PROMEDIOS POR ASIGNATURA ---");
                    for (j = 0; j < 3; j++) {
                        float suma = 0;
                        for (i = 0; i < 5; i++) {
                            suma += calificaciones[i][j];
                        }
                        float promedio = suma / 5.0;
                        printf("\nAsignatura %d: %.2f", j + 1, promedio);
                    }
                    printf("\nPresione Enter para continuar...");
                    getchar();
                }
                break;

            case 4: // Mostrar calificación más alta y baja por estudiante
                if (registrado == 0) {
                    printf("\nPrimero se deben registrar las calificaciones.");
                } else {
                    printf("\n--- CALIFICACIÓN MÁS ALTA Y BAJA POR ESTUDIANTE ---");
                    for (i = 0; i < 5; i++) {
                        float min = calificaciones[i][0];
                        float max = calificaciones[i][0];
                        for (j = 1; j < 3; j++) {
                            if (calificaciones[i][j] < min) {
                                min = calificaciones[i][j];
                            }
                            if (calificaciones[i][j] > max) {
                                max = calificaciones[i][j];
                            }
                        }
                        printf("\nEstudiante %d: Baja %.2f, Alta %.2f", i + 1, min, max);
                    }
                    printf("\nPresione Enter para continuar...");
                    getchar();
                }
                break;

            case 5: // Mostrar calificación más alta y baja por asignatura
                if (registrado == 0) {
                    printf("\nPrimero se deben registrar las calificaciones.");
                } else {
                    printf("\n--- CALIFICACIÓN MÁS ALTA Y BAJA POR ASIGNATURA ---");
                    for (j = 0; j < 3; j++) {
                        float min = calificaciones[0][j];
                        float max = calificaciones[0][j];
                        for (i = 1; i < 5; i++) {
                            if (calificaciones[i][j] < min) {
                                min = calificaciones[i][j];
                            }
                            if (calificaciones[i][j] > max) {
                                max = calificaciones[i][j];
                            }
                        }
                        printf("\nAsignatura %d: Baja %.2f, Alta %.2f", j + 1, min, max);
                    }
                    printf("\nPresione Enter para continuar...");
                    getchar();
                }
                break;

            case 6: // Mostrar aprobados y reprobados por asignatura (aprobado >= 6)
                if (registrado == 0) {
                    printf("\nPrimero se deben registrar las calificaciones.");
                } else {
                    printf("\n--- ESTUDIANTES APROBADOS Y REPROBADOS POR ASIGNATURA ---");
                    for (j = 0; j < 3; j++) {
                        int aprobados = 0;
                        for (i = 0; i < 5; i++) {
                            if (calificaciones[i][j] >= 6.0) {
                                aprobados++;
                            }
                        }
                        int reprobados = 5 - aprobados;
                        printf("\nAsignatura %d: Aprobados %d, Reprobados %d", j + 1, aprobados, reprobados);
                    }
                    printf("\nPresione Enter para continuar...");
                    getchar();
                }
                break;

            case 7: // Opción de salida del programa
                printf("\nFin del programa. :)");
                continuador = 0; // Cierre del bucle principal
                break;

            default: // Para opciones inválidas (1-7 ya cubiertas, pero por si acaso)
                if (opcion != 0) { // Evitar mensaje si es el reinicio interno
                    printf("\nOpción no válida.");
                    printf("Presione Enter para continuar...");
                    getchar();
                }
                break;
        }

        if (continuador == 1) { // Solo reiniciar si no salimos
            opcion = 0; // Reinicio de la variable opcion
        }
    }

    return 0;
}
