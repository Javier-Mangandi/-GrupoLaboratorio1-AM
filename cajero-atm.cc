#include <iostream>

void ConsultarSaldo(float saldo)
{
    std::cout << "Saldo actual recibido: $" << saldo << std::endl;
}

void Deposito(float &saldo, float monto)
{
    // No se permiten montos negativos
    if (monto <= 0)
    {
        std::cout << "[ERROR]: El monto a depositar debe ser mayor a $0." << std::endl;
        return;
    }

    saldo += monto;
    std::cout << "[EXITO]: Deposito realizado correctamente por un monto de: $" << monto << std::endl;
}


void Retiro(float *saldo, float monto)
{
    
    if (saldo == nullptr)
    {
        std::cout << "[ERROR]: Direccion de memoria de saldo no valida." << std::endl;
        return;
    }

    //No se permiten montos negativos
    if (monto <= 0)
    {
        std::cout << "[ERROR]: El monto a retirar debe ser mayor a $0." << std::endl;
        return;
    }

    // No se puede realizar un retiro por un monto mayor al saldo disponible
    if (monto > *saldo)
    {
        std::cout << "[ERROR]: Fondos insuficientes. Intento de retiro: $" << monto
                  << " | Saldo disponible: $" << *saldo << std::endl;
        return;
    }

    *saldo -= monto;
    std::cout << "[EXITO]: Retiro realizado correctamente por un monto de: $" << monto << std::endl;
}

int main()
{
    // El saldo inicial de la cuenta debe ser de $1000 (usando tipo float)
    float saldoCuenta = 1000.0f;
    std:coout << "===== BIENVENIDO AL CAJERO AUTOMATICO =====" << std::endl;
    std::cout << "=== ESTADO INICIAL DEL ATM ===" << std::endl;
    ConsultarSaldo(saldoCuenta);


    std::cout << "\n--- OPERACION 1: DEPOSITO VALIDO ---" << std::endl;
    std::cout << "(Antes) ";
    ConsultarSaldo(saldoCuenta);
    Deposito(saldoCuenta, 500.50f);
    std::cout << "(Despues) ";
    ConsultarSaldo(saldoCuenta);

    std::cout << "\n--- OPERACION 2: RETIRO VALIDO ---" << std::endl;
    std::cout << "(Antes) ";
    ConsultarSaldo(saldoCuenta);
    // Se pasa la dirección de memoria usando el operador &
    Retiro(&saldoCuenta, 300.00f);
    std::cout << "(Despues) ";
    ConsultarSaldo(saldoCuenta);

    std::cout << "\n=== PRUEBA DE VALIDACIONES DEL SISTEMA (MENSAJES DE ERROR) ===" << std::endl;

    std::cout << "\nIntentando depositar un monto negativo:" << std::endl;
    Deposito(saldoCuenta, -50.00f);

    std::cout << "\nIntentando retirar un monto negativo:" << std::endl;
    Retiro(&saldoCuenta, -20.00f);

    std::cout << "\nIntentando retirar mas del saldo disponible:" << std::endl;
    Retiro(&saldoCuenta, 2500.00f);

    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "=== ESTADO FINAL DEL ATM ===" << std::endl;
    std::cout << "=============================================" << std::endl;
    ConsultarSaldo(saldoCuenta);

    return 0;
}
