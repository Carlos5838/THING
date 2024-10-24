from pickle import FALSE


palabra=list("casa")
n=len(palabra)
letra=''
entrada = ['_' for _ in range(n)]
vidas=4
encontrado = False

print("Bienvenido al juego del ahocado")
print(f"Cuentas con {vidas} vidas")
print(f"Estado actual: {entrada} ")

while entrada != palabra:
    print()
    letra = input("Ingresa una letra: ")
    for i in range (n):
        if palabra[i] == letra:
            print(f"Si existe {letra} en la posicion {i+1}")
            entrada[i] = letra
            encontrado = True

    if not encontrado:
        vidas-=1
        print(f"La letra {letra} no existe")
        


    print(f"Vidas restantes: {vidas}")
    print(f"Estado actual: {entrada} ")

    if vidas == 0:
        break
    encontrado = False

    print()
if entrada == palabra:
    print("Felicidades ganaste")
else:
    print("Game Over")