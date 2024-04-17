#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAX_PROCESSES 15

// Estructura de un proceso
typedef struct {
    int id;
    int burst_time;
} Process;

// Cola de procesos
typedef struct {
    Process *queue[MAX_PROCESSES];
    int front, rear;
} Queue;

// Inicializar una cola
void initializeQueue(Queue *q) {
    q->front = q->rear = -1;
}

// Verificar si la cola está vacía
int isEmpty(Queue *q) {
    return (q->front == -1);
}

// Añadir un proceso a la cola
void enqueue(Queue *q, Process *process) {
    if (q->rear == MAX_PROCESSES - 1) {
        printf("La cola está llena\n");
        exit(EXIT_FAILURE);
    }

    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->queue[q->rear] = process;
}

// Eliminar un proceso de la cola
Process *dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("La cola está vacía\n");
        exit(EXIT_FAILURE);
    }

    Process *process = q->queue[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return process;
}

long long calcular_factorial(int n)
{
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    return factorial;
}

// Función principal
int main() {
    // Inicializar las colas
    struct timeval inicio, fin;    
    gettimeofday(&inicio, NULL);
    
    Queue EntryQueue, LowQueue, MediumQueue, LongQueue;
    initializeQueue(&EntryQueue);
    initializeQueue(&LowQueue);
    initializeQueue(&MediumQueue);
    initializeQueue(&LongQueue);

    // Creacion procesos
    Process *process1 = malloc(sizeof(Process));
    process1->id = 1;
    process1->burst_time = 5;
    Process *process2 = malloc(sizeof(Process));
    process2->id = 2;
    process2->burst_time = 3;
    Process *process3 = malloc(sizeof(Process));
    process3->id = 3;
    process3->burst_time = 7;
    Process *process4 = malloc(sizeof(Process));
    process4->id = 4;
    process4->burst_time = 5;
    Process *process5 = malloc(sizeof(Process));
    process5->id = 5;
    process5->burst_time = 5;
    Process *process6 = malloc(sizeof(Process));
    process6->id = 6;
    process6->burst_time = 7;
    Process *process7 = malloc(sizeof(Process));
    process7->id = 7;
    process7->burst_time = 3;
    Process *process8 = malloc(sizeof(Process));
    process8->id = 8;
    process8->burst_time = 3;
    Process *process9 = malloc(sizeof(Process));
    process9->id = 9;
    process9->burst_time = 5;
    Process *process10 = malloc(sizeof(Process));
    process10->id = 10;
    process10->burst_time = 7;
    

    // Añadir los procesos a las cola Entry
    enqueue(&EntryQueue, process1);
    enqueue(&EntryQueue, process2);
    enqueue(&EntryQueue, process3);
    enqueue(&EntryQueue, process4);
    enqueue(&EntryQueue, process5);
    enqueue(&EntryQueue, process6);
    enqueue(&EntryQueue, process7);
    enqueue(&EntryQueue, process8);
    enqueue(&EntryQueue, process8);
    enqueue(&EntryQueue, process9);
    enqueue(&EntryQueue, process10);

    // Añadir los procesos a las colas dinamicas
    while (!isEmpty(&EntryQueue)) {
        Process *current_process = dequeue(&EntryQueue);
        if(current_process->burst_time == 3){
        	enqueue(&LowQueue, current_process);
        }else{
        	if(current_process->burst_time == 5){
       			enqueue(&MediumQueue, current_process);
        	}
        	else{
        		if(current_process->burst_time == 7){
        			enqueue(&LongQueue, current_process);
        		}
        	}
        }
    }
    
    // Simular la ejecución de procesos
    
    while (!isEmpty(&LowQueue)) {
        Process *current_process = dequeue(&LowQueue);
        for(int i = 0; i < 5000; i++){
        	calcular_factorial(20);
        }
        
    }
    
    while (!isEmpty(&MediumQueue)) {
        Process *current_process = dequeue(&MediumQueue);
        
        for(int i = 0; i < 50000; i++){
        	calcular_factorial(20);
        }
        
    }
    
    while (!isEmpty(&LongQueue)) {
        Process *current_process = dequeue(&LongQueue);
        
        for(int i = 0; i < 100000; i++){
        	calcular_factorial(20);
        }
        
    }

    // Liberar memoria
    free(process1);
    free(process2);
    free(process3);
    free(process4);
    free(process5);
    free(process6);
    free(process7);
    free(process8);
    free(process9);
    free(process10);
    

// Obtener el tiempo de finalización
    gettimeofday(&fin, NULL);

    // Calcular el tiempo transcurrido en segundos y microsegundos
    double tiempo_transcurrido = (fin.tv_sec - inicio.tv_sec) + 
                                 (fin.tv_usec - inicio.tv_usec) / 1000000.0;
    printf("%.6f\n", tiempo_transcurrido);
    return 0;
}
