# Task #EX1: Templates  
**course:** Programación III  
**unit:** 1  
**cmake project:** prog3_unit2_neuralnetwork_v2025_01
## Indicaciones Específicas
El tiempo límite para la evaluación es de 2 horas.

Cada pregunta deberá ser respondida en un archivo fuente (.cpp) y cabecera (.h) correspondiente, en caso de `templates` solo incluir el archivo cabecera:

 - `neural_network.h`  

Deberás subir estos archivos directamente a www.gradescope.com o se puede crear un .zip que contenga todos ellos y subirlo.

## Question - templates (20 points)

Diseñar un sistema que permita simular redes neuronales modulares y genéricas, compuestas por capas que pueden ser configuradas y encadenadas usando templates variadic y template-template parameters. Se debe emplear polimorfismo, memoria dinámica segura (std::unique_ptr) y pruebas automatizadas para validar el diseño.

### Requisitos
1. Elaborar la clase abstracta `Layer<T>`
    ```cpp
    template<typename T>
    class Layer {
    public:
        virtual ~Layer() = default;
        virtual std::vector<T> forward(const std::vector<T>& input) = 0;
    };
    ```
2. Capas Derivadas
Debes implementar al menos tres que hereden de Layer<T>:
   - `Dense<T>`: capa densa con un solo peso y un solo sesgo, el número de neuronas de entrada será igual al de los de salida y por simplificación la salida del método `forward` se obtendrá utilizando la fórmula:
   - 
   - `ReLU<T>`: aplica activación `max(0, x)` a cada elemento.
   - `Dropout<T>`: anula los valores en las posiciones pares.
3. Clase Template `NeuralNetwork<T, Layers...>`
Usar parámetros del tipo template-template para definir las capas.


