import time
import math

MAX_PROCESSES = 15

# Estructura de un proceso
class Process:
    def __init__(self, id, burst_time):
        self.id = id
        self.burst_time = burst_time

# Cola de procesos


def calcular_factorial(n):
    factorial = 1
    for i in range(1, n+1):
        factorial *= i
    return factorial

# Función principal
def main():
    # Inicializar las colas
    EntryQueue = []
    LowQueue = []
    MediumQueue = []
    LongQueue = []

    # Creacion procesos
    EntryQueue = []
    EntryQueue.append(Process(1, 5))
    EntryQueue.append(Process(2, 3))
    EntryQueue.append(Process(3, 7))
    EntryQueue.append(Process(4, 5))
    EntryQueue.append(Process(5, 5))
    EntryQueue.append(Process(6, 7))
    EntryQueue.append(Process(7, 3))
    EntryQueue.append(Process(8, 3))
    EntryQueue.append(Process(9, 5))
    EntryQueue.append(Process(10, 7))

    

    # Añadir los procesos a las colas dinamicas
    while len(EntryQueue) != 0:
        current_process = EntryQueue.pop(0)
        if current_process.burst_time == 3:
            LowQueue.append(current_process)
        elif current_process.burst_time == 5:
            MediumQueue.append(current_process)
        elif current_process.burst_time == 7:
            LongQueue.append(current_process)

    # Simular la ejecución de procesos
    while len(LowQueue) != 0:
        current_process = LowQueue.pop(0)
        for i in range(5000):
            calcular_factorial(20)

    while len(MediumQueue) != 0:
        current_process = MediumQueue.pop(0)
        for i in range(50000):
            calcular_factorial(20)

    while len(LongQueue) != 0:
        current_process = LongQueue.pop(0)
        for i in range(100000):
            calcular_factorial(20)

# Obtener el tiempo de inicio
inicio = time.time()

# Llamar a la función principal
main()

# Obtener el tiempo de finalización
fin = time.time()

# Calcular el tiempo transcurrido en segundos
tiempo_transcurrido = fin - inicio
print("%.6f" % tiempo_transcurrido)
