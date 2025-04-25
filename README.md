# Task #EX1: Templates  
**course:** Programaci�n III  
**unit:** 1  
**cmake project:** prog3_unit2_neuralnetwork_v2025_01
## Indicaciones Espec�ficas
El tiempo l�mite para la evaluaci�n es de 2 horas.

Cada pregunta deber� ser respondida en un archivo fuente (.cpp) y cabecera (.h) correspondiente, en caso de `templates` solo incluir el archivo cabecera:

 - `neural_network.h`  

Deber�s subir estos archivos directamente a www.gradescope.com o se puede crear un .zip que contenga todos ellos y subirlo.

## Question - templates (20 points)

Dise�ar un sistema que permita simular redes neuronales modulares y gen�ricas, compuestas por capas que pueden ser configuradas y encadenadas usando templates variadic y template-template parameters. Se debe emplear polimorfismo, memoria din�mica segura (std::unique_ptr) y pruebas automatizadas para validar el dise�o.

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
   - `Dense<T>`: capa densa con un solo peso y un solo sesgo, el n�mero de neuronas de entrada ser� igual al de los de salida y por simplificaci�n la salida del m�todo `forward` se obtendr� utilizando la f�rmula:
   - 
   - `ReLU<T>`: aplica activaci�n `max(0, x)` a cada elemento.
   - `Dropout<T>`: anula los valores en las posiciones pares.
3. Clase Template `NeuralNetwork<T, Layers...>`
Usar par�metros del tipo template-template para definir las capas.


