#include <stdio.h>
#include <string.h>

int main() {
    // Declaración de variables
    float calificaciones[5][3]; // Matriz para almacenar calificaciones: 5 estudiantes, 3 asignaturas
    int continuador = 1, opcion, registrado = 0; // Bandera para verificar si se han ingresado calificaciones
    int i, j; // Para bucles
    char estudiantes[5][50]; // Nombres de los 5 estudiantes
    char asignaturas[3][20] = {"Matemáticas", "Álgebra", "Historia"}; // Nombres de las 3 asignaturas

    // Inicializar matriz con -1 para indicar no ingresado
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            calificaciones[i][j] = -1.0;
        }
    }

    // Registrar nombres de los estudiantes
    printf("Ingrese los nombres de los 5 estudiantes:\n");
    for (i = 0; i < 5; i++) {
        printf("Estudiante %d: ", i + 1);
        fgets(estudiantes[i], sizeof(estudiantes[i]), stdin);
        // Eliminar salto de línea si existe
        estudiantes[i][strcspn(estudiantes[i], "\n")] = '\0';
    }

    while (continuador == 1) { // Bucle principal del menú
        // Despliegue del menú
        printf("\n------* Programa de Gestión de Calificaciones *------");
        printf("\n1. Registrar calificaciones.");
        printf("\n2. Mostrar promedios por estudiante.");
        printf("\n3. Mostrar promedios por asignatura.");
        printf("\n4. Mostrar calificación más baja y alta por estudiante.");
        printf("\n5. Mostrar calificación más baja y alta por asignatura.");
        printf("\n6. Mostrar aprobados y reprobados por asignatura.");
        printf("\n7. Salir.");
        printf("\nOpción: ");

        // Lectura robusta de la opción con manejo de errores
        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            printf("\nEntrada no válida. Debe ingresar un número.\n");
            opcion = 0;
        } else {
            while (getchar() != '\n');
        }

        // Procesamiento con switch para mayor claridad
        switch (opcion) {
            case 1: // Registrar calificaciones
                registrado = 1;
                printf("\nIngrese las calificaciones de los 5 estudiantes en las 3 asignaturas (rango: 0-10):\n");
                for (i = 0; i < 5; i++) {
                    for (j = 0; j < 3; j++) {
                        float nota;
                        do {
                            printf("%s - %s: ", estudiantes[i], asignaturas[j]);
                            if (scanf("%f", &nota) != 1) {
                                while (getchar() != '\n');
                                printf("Error: Debe ingresar un número. Intente nuevamente.\n");
                                nota = -1.0;
                            } else {
                                while (getchar() != '\n');
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
                getchar();
                break;

            case 2: // Promedios por estudiante
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
                        printf("\n%s: %.2f", estudiantes[i], promedio);
                    }
                    printf("\nPresione Enter para continuar...");
                    getchar();
                }
                break;

            case 3: // Promedios por asignatura
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
                        printf("\n%s: %.2f", asignaturas[j], promedio);
                    }
                    printf("\nPresione Enter para continuar...");
                    getchar();
                }
                break;

            case 4: // Mínima y máxima por estudiante
                if (registrado == 0) {
                    printf("\nPrimero se deben registrar las calificaciones.");
                } else {
                    printf("\n--- CALIFICACIÓN MÁS BAJA Y ALTA POR ESTUDIANTE ---");
                    for (i = 0; i < 5; i++) {
                        float min = calificaciones[i][0];
                        float max = calificaciones[i][0];
                        for (j = 1; j < 3; j++) {
                            if (calificaciones[i][j] < min) min = calificaciones[i][j];
                            if (calificaciones[i][j] > max) max = calificaciones[i][j];
                        }
                        printf("\n%s: Baja %.2f, Alta %.2f", estudiantes[i], min, max);
                    }
                    printf("\nPresione Enter para continuar...");
                    getchar();
                }
                break;

            case 5: // Mínima y máxima por asignatura
                if (registrado == 0) {
                    printf("\nPrimero se deben registrar las calificaciones.");
                } else {
                    printf("\n--- CALIFICACIÓN MÁS BAJA Y ALTA POR ASIGNATURA ---");
                    for (j = 0; j < 3; j++) {
                        float min = calificaciones[0][j];
                        float max = calificaciones[0][j];
                        for (i = 1; i < 5; i++) {
                            if (calificaciones[i][j] < min) min = calificaciones[i][j];
                            if (calificaciones[i][j] > max) max = calificaciones[i][j];
                        }
                        printf("\n%s: Baja %.2f, Alta %.2f", asignaturas[j], min, max);
                    }
                    printf("\nPresione Enter para continuar...");
                    getchar();
                }
                break;

            case 6: // Aprobados y reprobados
                if (registrado == 0) {
                    printf("\nPrimero se deben registrar las calificaciones.");
                } else {
                    printf("\n--- ESTUDIANTES APROBADOS Y REPROBADOS POR ASIGNATURA ---");
                    for (j = 0; j < 3; j++) {
                        int aprobados = 0;
                        for (i = 0; i < 5; i++) {
                            if (calificaciones[i][j] >= 6.0) aprobados++;
                        }
                        int reprobados = 5 - aprobados;
                        printf("\n%s: Aprobados %d, Reprobados %d", asignaturas[j], aprobados, reprobados);
                    }
                    printf("\nPresione Enter para continuar...");
                    getchar();
                }
                break;

            case 7: // Salir
                printf("\nFin del programa. :)");
                continuador = 0;
                break;

            default:
                if (opcion != 0) {
                    printf("\nOpción no válida.");
                    printf("Presione Enter para continuar...");
                    getchar();
                }
                break;
        }

        if (continuador == 1) {
            opcion = 0;
        }
    }

    return 0;
}