// tema 6 

#include <stdio.h>
#include <string.h>

#define mm_med 10
#define mm_far 100

typedef struct {
    int cod;
    float prec;
} medic;

typedef struct {
    int cod;
    int cantt;
    char farmacia[100];
} asig;

int buscar_med(medic medicamentos[], int cod, int n) {
    for (int i = 0; i < n; i++) {
        if (medicamentos[i].cod == cod) {
            return i;
        }
    }
    return -1; 
}

int main() {
    medic medicamentos[mm_med];
    asig asignaciones[mm_far];
    int total_asigg[mm_med] = {0};
    float valorPercibir[mm_med] = {0};
    int num_med = 0;
    int num_asig = 0;

    int medicam[mm_med] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    float asigss[mm_med] = {10, 20, 30, 40, 55, 90, 25, 60, 80, 7.777};

    for (int i = 0; i < mm_med; i++) {
        medicamentos[i].cod = medicam[i];
        medicamentos[i].prec = asigss[i];
        num_med++;
    }

    int continuar = 1;
    while (continuar) {
        int cod, cantt;
        char farmacia[100];

        printf("por favor ingrese el codigo de su medicamento ( ingrese -1 para finalisar): ");
        scanf("%d", &cod);

        if (cod == -1) {
            continuar = 0;
            continue;
        }

        printf("ahora ingrese la cantida de medicamentos : ");
        scanf("%d", &cantt);

        printf("ingrese el nombre de su farmacia : ");
        scanf("%s", farmacia);

        int posc_medi = buscar_med(medicamentos, cod, num_med);

        if (posc_medi != -1) {
            strcpy(asignaciones[num_asig].farmacia, farmacia);
            asignaciones[num_asig].cod = cod;
            asignaciones[num_asig].cantt = cantt;
            total_asigg[posc_medi] += cantt;
            valorPercibir[posc_medi] += cantt * medicamentos[posc_medi].prec;
            num_asig++;
        } else {
            printf("medicamento inexistente \n ");
        }
    }

    printf(" \n cantidad total asignada y valor a percibir por medicamento :\n ");
    for (int i = 0; i < num_med; i++) {
        printf(" medicamento %d: cantidad: %d, Valor a percibir: %.2f \n ", medicamentos[i].cod, total_asigg[i], valorPercibir[i]);
    }

    int men_asigg = total_asigg[0];
    int pos_men_asig = 0;

    for (int i = 1; i < num_med; i++) {
        if (total_asigg[i] < men_asigg) {
            men_asigg = total_asigg[i];
            pos_men_asig = i;
        }
    }

    printf(" \n medicamiento con la menor asignacion: %d  \n", medicamentos[pos_men_asig].cod);

    printf(" \n medicamento no asignados a ninguna farmaci: \n ");
    int asignado[mm_med] = {0};

    for (int i = 0; i < num_asig; i++) {
        asignado[buscar_med(medicamentos, asignaciones[i].cod, num_med)] = 1;
    }

    for (int i = 0; i < num_med; i++) {
        if (asignado[i] == 0) {
            printf("%d \n", medicamentos[i].cod);
        }
    }

    return 0;
}

