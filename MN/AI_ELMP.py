import copy
""" 
# Instituto Rosario Castellanos
# Métodos Numéricos
# Muñoz Primero Elías
# Actividad Integradora
# Programar Newton-Raphson para Ecuaciones de tercer grado
"""

def ingresa_Ecuaciones():
    print("\n********************************************************")
    print("* Instituto Rosario Castellanos")
    print("* Métodos Numéricos")
    print("* Muñoz Primero Elías")
    print("* Actividad Integradora")
    print("* Newton-Raphson para Ecuaciones de tercer grado")
    print("********************************************************")
    print("Ingresa las ecuaciones de la forma: a(x^3)+b(x^2)+c(x^1)+d\n")
    ecuacion = input("\nIngresa la ecuación > ")
    # ecuacion = "1(x^3)+9"
    # ecuacion = "1(x^3)+2(x^1)+5"
    # ecuacion = "6(x^3)+3(x^2)+7(x^1)+9"
    valores_ecuacion = leer_ecuacion(ecuacion)
    valores_derivada = calcular_derivada(valores_ecuacion)
    # print(ecuacion)
    # print(valores_ecuacion)
    # print(valores_derivada)
    return valores_ecuacion,valores_derivada

def leer_ecuacion(ecuacion):
    try:
        Coeficientes = list()
        Exponentes = list()
        size = len(ecuacion)
        valor = ""
        es_exponente = False
        for i in range(size):
            if (ecuacion[i] == "-") or (ecuacion[i] == "+"):
                es_exponente = False
                valor += ecuacion[i]
            elif (ecuacion[i] == "(") or (ecuacion[i] == ")"):
                es_exponente = True
            elif ecuacion[i] == "^":
                continue
            elif (ecuacion[i] == "x") or (ecuacion[i] == "X"):
                continue
            else:
                if(es_exponente): # Si se trata de un exponente
                    valor += ecuacion[i]
                    Exponentes.append(float(valor))
                    valor = ""
                else: # Se trata de un coeficiente
                    # Se ingresa el valor en los coeficientes
                    valor += ecuacion[i]
                    Coeficientes.append(float(valor))
                    valor = ""
        return Exponentes,Coeficientes
    except Exception as e:
        print(f"\n Formato Invalido, Ingrese correctamente la ecuacion \n {e} \n")

def calcular_derivada(ecuacion_original):
    derivada = copy.deepcopy(ecuacion_original)
    for i in range(len(derivada[0])):
        derivada[1][i] *= derivada[0][i]
        derivada[0][i] -= 1
    derivada[1][len(derivada[1])-1] = 0.0
    return derivada

def solicitar_parametros():
    # Semilla = -20.0
    # Error_max = 0.0001
    # Iteraciones = 10
    Semilla = float(input("\nIngresa un valor inicial (semilla)   >   "))
    Error_max = float(input("Ingresa el error maximo aceptado     >   "))
    Iteraciones = float(input("Ingresa el numero de iteracciones    >   "))
    return float(Semilla),float(Error_max),int(Iteraciones)

def calcular_funcion(ecuacion,puntoAevaluar):
    resultado = 0.0
    for i in range(len(ecuacion[0])):
        # resultado += coeficiente*(punto^exponente)
        resultado += (ecuacion[1][i])*pow(puntoAevaluar,ecuacion[0][i])
    # resultado += terminoIndependiente
    resultado += ecuacion[1][len(ecuacion[1])-1]
    return resultado

def Newton_Raphson(Ecuacion,Derivada,Semilla,Error_Max,Iteraciones):
    print("\n")
    si_converge = False
    error_medido = 0.0
    x_r_respuest = Semilla
    for iteracion in range(Iteraciones):
        x_r_anterior = copy.copy(x_r_respuest)
        x_r_respuest = x_r_anterior - ((calcular_funcion(Ecuacion,x_r_anterior))/(calcular_funcion(Derivada,x_r_anterior)))
        if (x_r_respuest!=0.0):
            error_medido = abs((x_r_respuest-x_r_anterior)/(x_r_respuest))
        if(error_medido<Error_Max):
            print("Iteracion: {} \t Punto Medido(xr): {:.8f}   \t Error Medido: {:.8f} \t  Converge: Si".format(iteracion+1,x_r_respuest,error_medido))
            si_converge=True
            break
        else:
            print("Iteracion: {} \t Punto Medido(xr): {:.8f}   \t Error Medido: {:.8f} \t  Converge: No".format(iteracion+1,x_r_respuest,error_medido))
            # print(f"Iteracion: {iteracion} Punto Medido(xr): {x_r_respuest} Error Medido: {error_medido} Converge: No")
    if(si_converge):
        print(f"\nSolucion Calculada (xr): {x_r_respuest}")
        print(f"Funcion evaluada  f(xr): {calcular_funcion(Ecuacion,x_r_respuest)} \n\n")
        return x_r_respuest
    else:
        print(f"\nSolucion No Encontrada (xr): 0.0 \n\n")
        return 0.0




if __name__ == '__main__':
    ecuacion, derivada = ingresa_Ecuaciones()
    Semilla,Error_max,Iteraciones = solicitar_parametros()
    Newton_Raphson(ecuacion,derivada,Semilla,Error_max,Iteraciones)
