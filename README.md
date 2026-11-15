# Misión Artemis
Trabajo de C del grupo "Las Ingenieras", com C 2026

## Integrantes del Grupo:
-Galarza, Karla.
-Martínez, Araceli.
-Ovelar, Eliana.
-Pedretti, Maria Teresa.

## Breve introducción al escenario 3: 
-En este escenario se simula el viaje de la nave Orion desde la órbita terrestre baja (LEO) hacia la Luna, luego de realizar la maniobra de Inyección Translunar (TLI). Durante esta etapa, la nave alcanza una velocidad inicial de 10.900 m/s gracias al impulso generado por la etapa superior ICPS. Una vez finalizado el impulso, los motores se apagan y la nave continúa su recorrido sin propulsión, siguiendo los principios de la Primera Ley de Newton y la conservación de la energía mecánica.

-El programa  presenta un menu para leer sobre la
inercia de Orion, calcular su energia cinética y consultar una explicacion
cualitativa sobre el viaje Tierra-Luna.

## ¿Cómo ejecutar nuestro proyecto? 
-Se necesita tener instalado GCC (GNU Compiler Collection, es una colección gratuita de compiladores; en nuestro caso usamos el compilador de C llamado gcc.) y poder ejecutarlo desde la terminal.

1. Abrir PowerShell en la carpeta del proyecto.
2. Ejecutar .\compilar.bat
3. Cuando termine la compilación, iniciar el programa con .\artemis.exe

El archivo compilar.bat le pide a GCC que compile juntos main.c, validaciones.c y simulador.c, y genere artemis.exe. 

### ¿Cómo instalar GCC?
Una forma recomendada es instalarlo mediante MSYS2, desde su sitio oficial: msys2.org.

1-Descargá e instalá MSYS2 siguiendo las instrucciones del sitio oficial.

2-Abrí el terminal MSYS2 UCRT64 desde el menú Inicio.

3-En esa terminal, ejecutá: pacman -S --needed base-devel mingw-w64-ucrt-x86_64-gcc

4-Para poder ejecutar gcc desde PowerShell o desde la terminal de VS Code, agregá esta carpeta al Path de Windows: C:\msys64\ucrt64\bin

5- Cerrá y volvé a abrir PowerShell o VS Code. Comprobá la instalación con: gcc --version

Si aparece es porque se instaló correctamente. 

## ¿Cómo ejecutar el simulador sin instalar GCC?

El repositorio incluye `artemis.exe`, una versión ya compilada del programa para Windows. Por eso, para ejecutar el simulador ain gcc simplemente:

1. Descargue el proyecto con el archivo artemis (por favor extraer el contenido del archivo ZIP., porque ese es el archivo artemis.exe) 
3. Abrir la carpeta extraída. Allí debería estar el archivo `artemis.exe`.
4. Abrir una terminal en esa carpeta ( debe ser powershell).
5. Por último ejecutar: .\artemis.exe
6. No es necesario usar "compilar.bat".

## Uso de inteligencia artificial

-Se utilizó inteligencia artificial como apoyo para subir los push y commits al repositorio, como equipo pensamos que al ser un trabajo que no incluía una edición sobre nuestro proyecto no habría inconvenientes en usarla para ese fin.
-También, casi al finalizar el proyecto, le pedimos ayuda a la IA (copilot) para que nos diga que pensaba de nuestro proyecto, si veía errores muy notorios o mejores evidentes. Esto también nos ayudó para lograr hacer el archivo "Compilar.bat", ya que al tener varios archivos con simulaciones, validaciones y demás, el ejecutable para el proyecto se hacía demasiado largo para escribirlo en la terminal, por lo tanto copilot nos sugierió realizar este archivo y facilitar la ejecución del proyecto, lo cual vimos muy conveniente y accesible, esto debido a que el grupo no conocía de la existencia de estos programas para facilitar la ejecución de los proyectos.

### Promp utilizado para la IA:
"Estoy trabajando en un simulador educativo en C sobre la misión Artemis (para mejor contexto ver el pdf de escenarios, nos tocó el 3), para una materia que estamos cursando llamada Algoritmos y Estructuras de Datos. Ayúdame a revisar y mejorar el código existente sin cambiar el propósito ni agregar conceptos que excedan el nivel de primer año, tampoco quiero modificaciones sobre el mismo, envíalo solo por el chat así vemos las posibles modificaciones con el grupo. Revisa especialmente las validaciones, la claridad de los mensajes y que compile correctamente. Explícame los cambios para que podamos revisarlos y probarlos como equipo."



