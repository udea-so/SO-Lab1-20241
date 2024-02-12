
# Práctica 1 de laboratorio - Introducción al lenguaje C

> ## Objetivos
> * Aprender a codificar programas usando el lenguaje C a nivel basico e intermedio.
> * Aprender a usar las herramientas basicas para desarrollar aplicaciones en un ambiente de desarrollo linux.

## Herramientas necesarias

Para trabajar en el laboratorio, se necesita tener una maquina con un sistema operativo Linux instalado de manera nativa o mediante maquina virtual o en su defecto una maquina con MacOS. Si su maquina usted posee una maquina con Windows o superior y no cumple el requisito anterior, la recomentación es que instale la ultima versión del [WSL](https://en.wikipedia.org/wiki/Windows_Subsystem_for_Linux). Para llevar a cabo esto último la recomendación es que consulte los siguientes enlaces:
1. **Entrenamiento: Introducción a Subsistema de Windows para Linux (WSL)** ([link](https://learn.microsoft.com/es-es/training/modules/wsl-introduction/))
2. **Configurar un entorno de desarrollo de WSL** ([link]((https://learn.microsoft.com/es-es/windows/wsl/setup/environment)))
3. **Ejecución de aplicaciones de GUI de Linux en el Subsistema de Windows para Linux**([link](https://learn.microsoft.com/es-es/windows/wsl/tutorials/gui-apps)) 

## Primeros pasos

Con el fin de incentivar el trabajo en equipo y el uso de repositorios, antes de comenzar a trabajar en esta práctica se recomienda que lleve a cabo los siguientes pasos:
* Uno de los integrantes debe realizar un fork de este repositorio.

  ![fork](fork.png)

* La persona que haga el fork se debe encargar de agregar como colaborador al compañero de trabajo con el fin de que la modificación del repositorio sea hecha grupalmente.

* Cada uno de los integrantes del equipo puede hacer una copia local del laboratorio con el fin de colaborar en su desarrollo.

No olvide ir actualizando la práctica del laboratorio a medida que vaya avanzando en esta. Para el caso, vaya llevando a cabo los test proporcionados (tal y como se explicó0 en el laboratorio). Estos test serán el indicativo de cómo va su trabajo. 

Una vez hecho lo anterior puede empezar el desarrollo de la practica.

### Conceptos importantes

Para llevar a cabo el procedimiento descrito anteriormente es importante que tenga conocimientos basicos de manego de [github](https://en.wikipedia.org/wiki/GitHub). A continuación, se comparte material de utilidad a cerca del uso de esta herramienta con el fin de que aplique lo que aqui se muestra:
1. **Introducción a Git** ([link](https://learn.microsoft.com/es-es/training/modules/intro-to-git/)): Tutorial de Microsoft Learn sobre el manejo de la utilidad ```git```
2. **Introducción a GitHub** ([link](https://learn.microsoft.com/es-es/training/modules/introduction-to-github/)): Tutorial de Microsoft Learn sobre ```github```
3. **Laboratorio git parte 1** ([link](https://github.com/dannymrock/UdeA-SO-Lab/tree/master/lab0/lab0a/git_basico)): Apuntes de clase viejos sobre el manejo del git.

Ademas del manejo de la herramienta anterior, es sumamente importante tener un conocimiento sobre el manejo de la linea de comandos de linux. En los siguientes enlaces se 

## Recursos lenguaje C

A lo largo de todo el curso (teoria y practica), se empleara el lenguaje C. Como este es un lenguaje poco usado en el ambito de la carrera de Ingenieria de Sistemas se abordará de manera introductoria este lenguaje a lo largo del laboratorio con el fin de que se familiarice.

Los conceptos básicos relacionados con este lenguaje son bastante similares a lo que se usan en otros lenguajes de programación empleados a lo largo de su carrera (como python y java); sin embargo, hay unos cuantos que le resultaran nuevos. Es en estos últimos en los que haremos enfasis. A continuación, se muestran algunos recursos que le serán de utilidad:
1. **Apuntes de clase sobre el lenguaje C** ([link](https://github.com/dannymrock/UdeA-SO-Lab/tree/master/lab0/lab0b)): Apuntes del curso sobre los principales conceptos del lenguaje C que se van a emplear. 
2. **Stanford CS Education Library** ([link](http://cslibrary.stanford.edu/)): Material de Computer Science de la universidad de Stanford.
3. **The GNU C Reference Manual** ([link](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html)): Manual de referencia del lenguaje C de la GNU.
4. **C for Java Programmers: Tutorial** ([link](https://www.cs.rochester.edu/u/ferguson/csc/c/tutorial/)): Tutorial de la Universidad de Ronchester sobre el lenguaje C para programadores de Java.
5. **The C programming Languaje** ([link](http://cslabcms.nju.edu.cn/problem_solving/images/c/cc/The_C_Programming_Language_%282nd_Edition_Ritchie_Kernighan%29.pdf)): Libro del lenguaje C de Dennis Ritchie y Brian Kernighan.
6. **C for Python Programmers** ([link](https://realpython.com/c-for-python-programmers/)): Tutorial de Lenguaje C para programadores de Python de [real Python](https://realpython.com/)
7. **C for Python Programmers** ([link](https://www.cs.toronto.edu/~patitsas/cs190/c_for_python.html)): Lenguaje C para programadores de Python de la universidad de Toronto.

A manera de resumen, se presentan varias **Reference Sheets** ([link](reference_sheets/)). De estas se resalta la **C Reference Card (ANSI)
** ([link](https://www.math.brown.edu/johsilve/ReferenceCards/CRefCard.v2.2.pdf))

## Practica

> **Nota**: Esta práctica es una traducción de la práctica **Reverse** del libro del profesor Remzi. Esta traducción puede tener algunos errores y no ser fiel con lo que el autor quiere transmitir. Si desea leerla en inglés puede hacerlo en el siguiente ([enlace](https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/initial-reverse)).

### Antes de empezar

Antes de empezar a desarrollar esta práctica, lea el [lab tutorial](http://pages.cs.wisc.edu/~remzi/OSTEP/lab-tutorial.pdf) el cual contiene algunos tips de utilidad para trabajar con en un entorno de programación. 

Adicionalmente, se presenta el siguiente material con algunos ejemplos cuya comprensión le pueden ayudar a familiarizarse con todos los conceptos teorico-practicos necesarios para desarrollar la siguiente practica. A continuación se detalla el material de apoyo.
* **Desarrollo de aplicaciones en lenguaje C usando Linux** ([link](ejemplos/lab_tutorial/))
* **Ejemplos varios del lenguaje C** ([link](ejemplos/conceptos_c/))

### Enunciado

Esta práctica no es más que un simple calentamiento (warm-up) para familiarizarlo con la forma de trabajo en varios de los proyectos que se realizarán en el laboratorio. También sirve de punto de partida para empezar los primeros pasos con el lenguaje de programación C el cual se usará a lo largo del curso.

Se pide que desarrollo un programa sencillo llamado `reverse` el cual se debe invocar siguiendo las instrucciones mostradas a continuación:

```sh
prompt> ./reverse
prompt> ./reverse input.txt
prompt> ./reverse input.txt output.txt
```

En cada una de las instrucciones anteriomente mostradas se puede ver que el usuario ha tecleado el nombre del programa de inversión `reverse` (el `./` delante simplemente se refiere al directorio de trabajo actual directorio, llamado punto, referido como `.` y la barra `/` es un separador; así, en este directorio, se buscó un programa llamado `reverse`). Nótese que cada una de las instrucciones se invocaron de tres formas distintas:
* En el caso la primera instrucción no se ingresó ningún argumento en la linea comandos.
* En lo que respecta a la segunda instrucción se pasó un argumento de línea de comandos (un archivo de entrada, `input.txt`).
* En la última instrucción se pasaron dos argumentos de línea de órdenes (un fichero de entrada y un fichero de salida `salida.txt`).

Por ejemplo, si el archivo de entrada tiene el siguiente contenido:

```
hello
this
is 
a file
```

El objetivo del programa de inversión `reverse` es leer los datos del archivo de entrada especificado e invertirlos; por lo tanto, las líneas se imprimirán en el orden del flujo de entrada. Así, para el ejemplo anterior, la salida debería ser:

```
a file
is
this
hello
```

Las diferentes formas de invocar el archivo (mostradas enteriormente) corresponden a formas ligeramente diferentes de usar esta nueva y sencilla utilidad de Unix. Por ejemplo, cuando se invoca con dos argumentos de línea de comandos, el programa debe leer el archivo de entrada que proporciona el usuario y escribir la versión invertida de dicho archivo en el archivo de salida que proporciona el usuario.

Cuando se invoca con un solo argumento de línea de comando, el usuario proporciona el archivo de entrada, pero el archivo debe imprimirse en la pantalla. En los sistemas basados en Unix, imprimir en la pantalla es lo mismo que escribir en un archivo especial conocido como **salida estándar** o "stdout" para abreviar.

Finalmente, cuando se invoca sin ningún argumento, su programa de inversión debe leer desde la **entrada estándar** (`stdin`), que es la entrada que ingresa un usuario, y escribir en la salida estándar (es decir, la pantalla).

Suena fácil, ¿verdad? Debería serlo. Pero hay algunos detalles...



## Detalles

### Suposiciones y errores

- **La entrada es la misma que la salida:** Si el archivo de entrada y el archivo de salida son el mismo archivo, debe imprimir un mensaje de error "El archivo de entrada y salida deben diferir" y salir con el código de retorno 1.

- **Longitud de la cadena:** No puedes asumir nada sobre la longitud que debe tener una línea. Por lo tanto, es posible que tengas que leer en una línea de entrada muy larga...

- **Longitud del archivo:** No puedes asumir nada sobre la longitud del archivo, es decir, puede ser **MUY** largo.

- **Archivos no válidos:** Si el usuario especifica un archivo de entrada o un archivo de salida, y por alguna razón, cuando intenta abrir dicho archivo (por ejemplo, `input.txt`) y falla, debe imprimir exactamente lo siguiente mensaje de error: `error: no se puede abrir el archivo 'input.txt'` y luego salir con el código de retorno 1 (es decir, llamar a `exit(1);`).

- **Malloc falla:** Si llama a `malloc()` para asignar algo de memoria y malloc falla, debe imprimir el mensaje de error `malloc falló` y salir con el código de retorno 1.

- **Demasiados argumentos pasados al programa:** Si el usuario ejecuta `reverse` con demasiados argumentos, imprima `usage: reverse <input> <output>` y salga con el código de retorno 1.

- **Cómo imprimir mensajes de error:** Ante cualquier error, debe imprimir el error en la pantalla usando `fprintf()` y enviar el mensaje de error a `stderr` (error estándar) y no a `stdout` (salida estándar). Esto se logra en su código C de la siguiente manera: `fprintf(stderr, "cualquiera que sea el mensaje de error\n");`


### Useful Routines

To exit, call `exit(1)`. The number you pass to `exit()`, in this case 1, is
then available to the user to see if the program returned an error (i.e.,
return a non-zero) or exited cleanly (i.e., returned 0).

For reading in the input file, the following routines will make your life
easy: `fopen()`, `getline()`, and `fclose()`.

For printing (to screen, or to a file), use `fprintf()`.  Note that it is easy
to write to standard output by passing `stdout` to `fprintf()`; it is also
easy to write to a file by passing in the `FILE *` returned by `fopen`, e.g.,
`fp=fopen(...); fprintf(fp, ...);`.

The routine `malloc()` is useful for memory allocation. Perhaps for
adding elements to a list?
  
If you don't know how to use these functions, use the man pages. For
example, typing `man malloc` at the command line will give you a lot of
information on malloc.

### Tips

**Start small, and get things working incrementally.** For example, first
get a program that simply reads in the input file, one line at a time, and
prints out what it reads in. Then, slowly add features and test them as you
go.

For example, the way we wrote this code was first to write some code that used
`fopen()`, `getline()`, and `fclose()` to read an input file and print it
out. Then, we wrote code to store each input line into a linked list and made
sure that worked. Then, we printed out the list in reverse order. Then we made
sure to handle error cases. And so forth...

**Testing is critical.** A great programmer we once knew said you have to
write five to ten lines of test code for every line of code you produce;
testing your code to make sure it works is crucial. Write tests to see if your
code handles all the cases you think it should. Be as comprehensive as you can
be. Of course, when grading your projects, we will be. Thus, it is better if
you find your bugs first, before we do.

**Keep old versions around.** Keep copies of older versions of your program
around, as you may introduce bugs and not be able to easily undo them. A
simple way to do this is to keep copies around, by explicitly making copies of
the file at various points during development. For example, let's say you get
a simple version of `reverse.c` working (say, that just reads in the file);
type `cp reverse.c reverse.v1.c` to make a copy into the file
`reverse.v1.c`. More sophisticated developers use version control systems git
(perhaps through github); such a tool is well worth learning, so do it!

