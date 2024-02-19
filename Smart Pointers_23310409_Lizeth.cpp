/*Smart Pointers 
¿Que son?
Los Smart Pointers son objetos en C++ que actúan como punteros tradicionales, pero con la ventaja de realizar la gestión automática de memoria. Esto significa que se encargan de liberar automáticamente la memoria asignada cuando ya no se necesitan, evitando así posibles fugas de memoria o referencias a memoria no válida. Los Smart Pointers son una parte fundamental de la gestión de memoria segura en C++, ya que ayudan a prevenir errores comunes asociados con la manipulación manual de memoria.

dentro de este termino existen tres tipos principales de Smart Pointers en C++:

unique_ptr: Es un Smart Pointer que posee la exclusividad de la memoria a la que apunta. Solo puede haber un único unique_ptr apuntando a una dirección de memoria en un momento dado. Cuando el unique_ptr sale del ámbito o se elimina explícitamente, libera automáticamente la memoria que posee.

shared_ptr: Permite tener múltiples punteros apuntando a la misma dirección de memoria. Lleva un contador interno para realizar un seguimiento de cuántos shared_ptr están haciendo referencia a la memoria. La memoria se libera automáticamente cuando el último shared_ptr que hace referencia a ella sale del ámbito o se elimina.

weak_ptr: Similar a shared_ptr, pero no incrementa el contador de referencias. Se utiliza para evitar ciclos de referencia en estructuras de datos complejas que utilizan shared_ptr. Puede ser bloqueado para convertirse en un shared_ptr si la memoria aún no ha sido liberada.*/

//Ejemplo de Smart Pointer 
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() {
        std::cout << "Constructor de MyClass" << std::endl;
    }
    ~MyClass() {
        std::cout << "Destructor de MyClass" << std::endl;
    }
    void sayHello() {
        std::cout << "Hola desde MyClass" << std::endl;
    }
};

int main() {
    // Uso de unique_ptr
    std::unique_ptr<MyClass> ptr1(new MyClass());
    ptr1->sayHello();

    // Uso de shared_ptr
    std::shared_ptr<MyClass> ptr2(new MyClass());
    std::shared_ptr<MyClass> ptr3 = ptr2; // Se incrementa el contador de referencias
    ptr2->sayHello();
    ptr3->sayHello();

    // Uso de weak_ptr
    std::weak_ptr<MyClass> ptr4 = ptr2;
    std::shared_ptr<MyClass> ptr5 = ptr4.lock(); // Se convierte en shared_ptr antes de usarlo
    ptr5->sayHello();

    return 0;
}
