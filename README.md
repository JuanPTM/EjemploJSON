Tutorial JSON
----

Introducción
---
En este tutorial vamos a aprender como funciona la librería “ArduinoJSON” con la que podremos trabajar con JSON con
total normalidad, ya que tiene una gestión de memoria muy buena, lo que evita problemas posteriores con el Arduino.

----
¿Qué necesitamos?
----
Librería ArduinoJSON: Descargar de [Aquí][1]. 
Algún sensor: En el caso de que queráis probarlo junto con algo.
Nuestro arduino.

----
Primer Ejemplo
---
En este primer ejemplo vamos a crear un JSON simple que constara de varios campos con texto y un array de valores, que
podrán ser obtenidos de donde se quieran,

El ejemplo puede encontrarse [aquí][2]

![](https://i.imgur.com/8qTwv5R.png)


Como podemos ver en este ejemplo creamos el JSON utilizando  ``` StaticJsonBuffer<200> jsonBuffer; ``` y con eso creamos el primer objeto en sí, que es el que contiene todos los valores.
Para añadir campos a ese objeto, se podrá de dos formas, si es un par nombre:valor se hará por sobrecarga de operadores, 
```
json["nombre"] = "SOLEPCC"; 
```
O añadiendo un vector, para esto reservamos memoria dentro del objeto con ``` json.createNestedArray("sensors") ```, en el cual añadimos el nombre que tendrá dicho vector en el json, como se ve en la salida por serial. Esta llamada nos devolverá un objeto de la clase JSONArray, que es la que usaremos para poder añadir objetos a dicho array.

----
¿Cómo accedemos a los datos?
----
Muy fácil, los pares nombre:valor serán accedidos igual que son añadidos, si hacemos referencia a  ```json[“nombre”]``` estaremos obteniendo lo que tenemos ahí guardado.
En el caso de los vectores, como son parte del valor de un campo, accederemos así: ```json[sensors][INDICEVECTOR]``` y estaremos accediendo a la posición del vector indicada.

---
Ejemplo 2
---
Basándonos en el ejemplo anterior, convertiremos los elementos del vector en objetos JSON también, dándonos una mayor complejidad a la hora de trabajar con ellos pero a su vez una mayor versatilidad.

El ejemplo puede encontrarse [aquí][3]

![](https://i.imgur.com/y9BO1Bm.png)

Como podemos ver hay una ligera diferencia con respecto al anterior, puesto dentro de cada posición del vector nos encontramos con un objeto JSON entero, lo que nos proporciona mucho juego a la hora de enviar información.

---
¿Cómo accedemos a esos datos?
----
Es tan fácil como antes, pues ahora si accedemos a una posición del vector nos encontraremos con un bloque entero de datos, que es otro json y este podrá redireccionarse como se hace con un json normal, 
Por lo que si queremos acceder al campo “name” del primero sensor lo haríamos así.
``` json[“sensors”][0][“name”] ``` y con eso habríamos accedido a dicho campo, también se puede ser más estético y sacártelo a una variable auxiliar de tipo JSonObject 
``` JsonObject& jsonAux = json[“sensors”][0] ```  y trabajar a partir de ahí.

----
Pero… ¿y Parserito?
---
Ahora llegamos al punto que nos dará mucho juego, crear JSON a través de datos recibidos vía Serial (en este ejemplo) o cualquier otro flujo de información (SD, Internet, etc.)

Con el código a continuación veremos cómo podemos crear un json con los datos recibidos, que será simulado por una cadena fija. Se generará un Json igual que el del ejemplo anterior.


El ejemplo puede encontrarse [aquí][4]

Y este es el resultado. Como podemos ver solo se nos muestra el campo nombre, valor1 y el primer objeto Json del array.

![](https://i.imgur.com/VS9tjYH.png)

----
Conclusión
----
Con esto tendréis una visión básica de cómo usar esta librería y añadir los JSON a vuestros proyectos, si tenéis alguna duda no dudéis en preguntarme y si seguís avanzando con esta librería sois libres de añadir más información a esta guía o rehacerla.




  [1]: https://github.com/bblanchon/ArduinoJson
  [2]: https://github.com/JuanPTM/EjemploJSON/blob/master/Ejemplo1/Ejemplo1.ino
  [3]: https://github.com/JuanPTM/EjemploJSON/blob/master/Ejemplo2/Ejemplo2.ino
  [4]: https://github.com/JuanPTM/EjemploJSON/blob/master/Ejemplo3/Ejemplo3.ino
